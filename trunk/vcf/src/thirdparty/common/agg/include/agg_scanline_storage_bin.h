//----------------------------------------------------------------------------
// Anti-Grain Geometry - Version 2.1
// Copyright (C) 2002-2004 Maxim Shemanarev (http://www.antigrain.com)
//
// Permission to copy, use, modify, sell and distribute this software 
// is granted provided this copyright notice appears in all copies. 
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//
//----------------------------------------------------------------------------
// Contact: mcseem@antigrain.com
//          mcseemagg@yahoo.com
//          http://www.antigrain.com
//----------------------------------------------------------------------------

#ifndef AGG_SCANLINE_STORAGE_BIN_INCLUDED
#define AGG_SCANLINE_STORAGE_BIN_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "agg_array.h"


namespace agg
{

    //-----------------------------------------------scanline_storage_bin
    class scanline_storage_bin
    {
    public:
        //---------------------------------------------------------------
        struct span_data
        {
            int16 x;
            int16 len;
        };

        //---------------------------------------------------------------
        struct scanline_data
        {
            int      y;
            unsigned num_spans;
            unsigned start_span;
        };


        //---------------------------------------------------------------
        class embedded_scanline
        {
        public:

            //-----------------------------------------------------------
            class const_iterator
            {
            public:
                const_iterator(const embedded_scanline& sl) :
                    m_storage(sl.m_storage),
                    m_span_idx(sl.m_scanline.start_span)
                {
                    m_span = m_storage->span_by_index(m_span_idx);
                }

                const span_data& operator*()  const { return m_span;  }
                const span_data* operator->() const { return &m_span; }

                void operator ++ ()
                {
                    ++m_span_idx;
                    m_span = m_storage->span_by_index(m_span_idx);
                }

            private:
                const scanline_storage_bin* m_storage;
                unsigned                    m_span_idx;
                span_data                   m_span;
            };

            friend class const_iterator;


            //-----------------------------------------------------------
            embedded_scanline(const scanline_storage_bin& storage) :
                m_storage(&storage)
            {
                setup(0);
            }

            //-----------------------------------------------------------
            void     reset(int, int)     {}
            unsigned num_spans()   const { return m_scanline.num_spans;  }
            int      y()           const { return m_scanline.y;          }
            const_iterator begin() const { return const_iterator(*this); }

            //-----------------------------------------------------------
            void setup(unsigned scanline_idx)
            {
                m_scanline_idx = scanline_idx;
                m_scanline = m_storage->scanline_by_index(m_scanline_idx);
            }

        private:
            const scanline_storage_bin* m_storage;
            scanline_data               m_scanline;
            unsigned                    m_scanline_idx;
        };


        //---------------------------------------------------------------
        scanline_storage_bin() :
            m_spans(256-2),         // Block increment size
            m_scanlines(),
            m_min_x( 0x7FFFFFFF),
            m_min_y( 0x7FFFFFFF),
            m_max_x(-0x7FFFFFFF),
            m_max_y(-0x7FFFFFFF),
            m_cur_scanline(0)
        {
            m_fake_scanline.y = 0;
            m_fake_scanline.num_spans = 0;
            m_fake_scanline.start_span = 0;
            m_fake_span.x = 0;
            m_fake_span.len = 0;
        }

        // Renderer Interface
        //---------------------------------------------------------------
        void prepare(unsigned)
        {
            m_scanlines.remove_all();
            m_spans.remove_all();
            m_min_x =  0x7FFFFFFF;
            m_min_y =  0x7FFFFFFF;
            m_max_x = -0x7FFFFFFF;
            m_max_y = -0x7FFFFFFF;
            m_cur_scanline = 0;
        }

        //---------------------------------------------------------------
        template<class Scanline> void render(const Scanline& sl)
        {
            scanline_data sl_this;

            int y = sl.y();
            if(y < m_min_y) m_min_y = y;
            if(y > m_max_y) m_max_y = y;

            sl_this.y = y;
            sl_this.num_spans = sl.num_spans();
            sl_this.start_span = m_spans.size();
            typename Scanline::const_iterator span_iterator = sl.begin();

            unsigned num_spans = sl_this.num_spans;
            do
            {
                span_data sp;
                sp.x   = span_iterator->x;
                sp.len = (int16)abs((int)(span_iterator->len));
                m_spans.add(sp);
                int x1 = sp.x;
                int x2 = sp.x + sp.len - 1;
                if(x1 < m_min_x) m_min_x = x1;
                if(x2 > m_max_x) m_max_x = x2;
                ++span_iterator;
            }
            while(--num_spans);
            m_scanlines.add(sl_this);
        }


        //---------------------------------------------------------------
        // Iterate scanlines interface
        int min_x() const { return m_min_x; }
        int min_y() const { return m_min_y; }
        int max_x() const { return m_max_x; }
        int max_y() const { return m_max_y; }

        //---------------------------------------------------------------
        bool rewind_scanlines()
        {
            m_cur_scanline = 0;
            return m_scanlines.size() > 0;
        }


        //---------------------------------------------------------------
        template<class Scanline> bool sweep_scanline(Scanline& sl)
        {
            sl.reset_spans();
            for(;;)
            {
                if(m_cur_scanline >= m_scanlines.size()) return false;
                const scanline_data& sl_this = m_scanlines[m_cur_scanline];

                unsigned num_spans = sl_this.num_spans;
                unsigned span_idx  = sl_this.start_span;
                do
                {
                    const span_data& sp = m_spans[span_idx++];
                    sl.add_span(sp.x, sp.len, cover_full);
                }
                while(--num_spans);

                ++m_cur_scanline;
                if(sl.num_spans())
                {
                    sl.finalize(sl_this.y);
                    break;
                }
            }
            return true;
        }


        //---------------------------------------------------------------
        // Specialization for embedded_scanline
        bool sweep_scanline(embedded_scanline& sl)
        {
            do
            {
                if(m_cur_scanline >= m_scanlines.size()) return false;
                sl.setup(m_cur_scanline);
                ++m_cur_scanline;
            }
            while(sl.num_spans() == 0);
            return true;
        }


        //---------------------------------------------------------------
        unsigned byte_size() const
        {
            unsigned i;
            unsigned size = sizeof(int16) * 4; // min_x, min_y, max_x, max_y

            for(i = 0; i < m_scanlines.size(); ++i)
            {
                size += sizeof(int16) * 2; // Y, num_spans

                const scanline_data& sl_this = m_scanlines[i];

                unsigned num_spans = sl_this.num_spans;
                unsigned span_idx  = sl_this.start_span;
                do
                {
                    const span_data& sp = m_spans[span_idx++];
                    size += sizeof(int16) * 2;                // X, span_len
                }
                while(--num_spans);
            }
            return size;
        }


        //---------------------------------------------------------------
        static void write_int16(int8u* dst, int16 val)
        {
            dst[0] = ((const int8u*)&val)[0];
            dst[1] = ((const int8u*)&val)[1];
        }


        //---------------------------------------------------------------
        void serialize(int8u* data) const
        {
            unsigned i;

            write_int16(data, int16u(min_x())); // min_x
            data += sizeof(int16u);
            write_int16(data, int16u(min_y())); // min_y
            data += sizeof(int16u);
            write_int16(data, int16u(max_x())); // max_x
            data += sizeof(int16u);
            write_int16(data, int16u(max_y())); // max_y
            data += sizeof(int16u);

            for(i = 0; i < m_scanlines.size(); ++i)
            {
                const scanline_data& sl_this = m_scanlines[i];

                write_int16(data, int16(sl_this.y));            // Y
                data += sizeof(int16);

                write_int16(data, int16(sl_this.num_spans));    // num_spans
                data += sizeof(int16);

                unsigned num_spans = sl_this.num_spans;
                unsigned span_idx  = sl_this.start_span;
                do
                {
                    const span_data& sp = m_spans[span_idx++];

                    write_int16(data, int16(sp.x));             // X
                    data += sizeof(int16);

                    write_int16(data, int16(sp.len));           // len
                    data += sizeof(int16);
                }
                while(--num_spans);
            }
        }


        //---------------------------------------------------------------
        const scanline_data& scanline_by_index(unsigned i) const
        {
            return (i < m_scanlines.size()) ? m_scanlines[i] : m_fake_scanline;
        }

        //---------------------------------------------------------------
        const span_data& span_by_index(unsigned i) const
        {
            return (i < m_spans.size()) ? m_spans[i] : m_fake_span;
        }


    private:
        pod_deque<span_data, 10>    m_spans;
        pod_deque<scanline_data, 8> m_scanlines;
        span_data     m_fake_span;
        scanline_data m_fake_scanline;
        int           m_min_x;
        int           m_min_y;
        int           m_max_x;
        int           m_max_y;
        unsigned      m_cur_scanline;
    };













    //---------------------------------------serialized_scanlines_adaptor_bin
    class serialized_scanlines_adaptor_bin
    {
    public:
        typedef bool cover_type;

        //--------------------------------------------------------------------
        class embedded_scanline
        {
        public:

            //----------------------------------------------------------------
            class const_iterator
            {
            public:
                struct span
                {
                    int16 x;
                    int16 len;
                };

                const_iterator(const embedded_scanline& sl) :
                    m_ptr(sl.m_ptr),
                    m_dx(sl.m_dx)
                {
                    m_span.x   = read_int16() + m_dx;
                    m_span.len = read_int16();
                }

                const span& operator*()  const { return m_span;  }
                const span* operator->() const { return &m_span; }

                void operator ++ ()
                {
                    m_span.x   = read_int16() + m_dx;
                    m_span.len = read_int16();
                }

            private:
                int read_int16()
                {
                    int16 val;
                    ((int8u*)&val)[0] = *m_ptr++;
                    ((int8u*)&val)[1] = *m_ptr++;
                    return val;
                }

                const int8u* m_ptr;
                span         m_span;
                int          m_dx;
            };

            friend class const_iterator;


            //----------------------------------------------------------------
            embedded_scanline() : m_ptr(0), m_y(0), m_num_spans(0) {}

            //----------------------------------------------------------------
            void     reset(int, int)     {}
            unsigned num_spans()   const { return m_num_spans;  }
            int      y()           const { return m_y;          }
            const_iterator begin() const { return const_iterator(*this); }


        private:
            //----------------------------------------------------------------
            int read_int16()
            {
                int16 val;
                ((int8u*)&val)[0] = *m_ptr++;
                ((int8u*)&val)[1] = *m_ptr++;
                return val;
            }

        public:
            //----------------------------------------------------------------
            void init(const int8u* ptr, int dx, int dy)
            {
                m_ptr       = ptr;
                m_y         = read_int16() + dy;
                m_num_spans = unsigned(read_int16());
                m_dx        = dx;
            }

        private:
            const int8u* m_ptr;
            int          m_y;
            unsigned     m_num_spans;
            int          m_dx;
        };



    public:
        //--------------------------------------------------------------------
        serialized_scanlines_adaptor_bin() :
            m_data(0),
            m_end(0),
            m_ptr(0),
            m_dx(0),
            m_dy(0),
            m_min_x(0x7FFFFFFF),
            m_min_y(0x7FFFFFFF),
            m_max_x(-0x7FFFFFFF),
            m_max_y(-0x7FFFFFFF)
        {}

        //--------------------------------------------------------------------
        serialized_scanlines_adaptor_bin(const int8u* data, unsigned size,
                                         double dx, double dy) :
            m_data(data),
            m_end(data + size),
            m_ptr(data),
            m_dx(int(floor(dx + 0.5))),
            m_dy(int(floor(dy + 0.5))),
            m_min_x(0x7FFFFFFF),
            m_min_y(0x7FFFFFFF),
            m_max_x(-0x7FFFFFFF),
            m_max_y(-0x7FFFFFFF)
        {}

        //--------------------------------------------------------------------
        void init(const int8u* data, unsigned size, double dx, double dy)
        {
            m_data  = data;
            m_end   = data + size;
            m_ptr   = data;
            m_dx    = int(floor(dx + 0.5));
            m_dy    = int(floor(dy + 0.5));
            m_min_x = 0x7FFFFFFF;
            m_min_y = 0x7FFFFFFF;
            m_max_x = -0x7FFFFFFF;
            m_max_y = -0x7FFFFFFF;
        }

    private:
        //--------------------------------------------------------------------
        int read_int16()
        {
            int16 val;
            ((int8u*)&val)[0] = *m_ptr++;
            ((int8u*)&val)[1] = *m_ptr++;
            return val;
        }
       
    public:
        // Iterate scanlines interface
        //--------------------------------------------------------------------
        bool rewind_scanlines()
        {
            m_ptr = m_data;
            if(m_ptr < m_end)
            {
                m_min_x = read_int16() + m_dx; 
                m_min_y = read_int16() + m_dy;
                m_max_x = read_int16() + m_dx;
                m_max_y = read_int16() + m_dy;
                return true;
            }
            return false;
        }

        //--------------------------------------------------------------------
        int min_x() const { return m_min_x; }
        int min_y() const { return m_min_y; }
        int max_x() const { return m_max_x; }
        int max_y() const { return m_max_y; }

        //--------------------------------------------------------------------
        template<class Scanline> bool sweep_scanline(Scanline& sl)
        {
            sl.reset_spans();
            for(;;)
            {
                if(m_ptr >= m_end) return false;

                int y = read_int16() + m_dy;
                unsigned num_spans = read_int16();

                do
                {
                    int x = read_int16() + m_dx;
                    int len = read_int16();

                    if(len < 0) len = -len;
                    sl.add_span(x, unsigned(len), cover_full);
                }
                while(--num_spans);

                if(sl.num_spans())
                {
                    sl.finalize(y);
                    break;
                }
            }
            return true;
        }


        //--------------------------------------------------------------------
        // Specialization for embedded_scanline
        bool sweep_scanline(embedded_scanline& sl)
        {
            do
            {
                if(m_ptr >= m_end) return false;

                sl.init(m_ptr, m_dx, m_dy);

                // Jump to the next scanline
                //--------------------------
                read_int16();                    // Y
                int num_spans = read_int16();    // num_spans
                m_ptr += num_spans * sizeof(int16) * 2;
            }
            while(sl.num_spans() == 0);
            return true;
        }

        //--------------------------------------------------------------------
        template<class Scanline, class Renderer> 
        void render(Scanline& sl, Renderer& r)
        {
            if(rewind_scanlines())
            {
                sl.reset(min_x(), max_x());
                r.prepare(unsigned(max_x() - min_x() + 2));

                while(sweep_scanline(sl))
                {
                    r.render(sl);
                }
            }
        }

    private:
        const int8u* m_data;
        const int8u* m_end;
        const int8u* m_ptr;
        int          m_dx;
        int          m_dy;
        int          m_min_x;
        int          m_min_y;
        int          m_max_x;
        int          m_max_y;
    };



}

#endif
