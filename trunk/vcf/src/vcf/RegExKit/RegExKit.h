#ifndef _VCF_REGEXKIT_H__
#define _VCF_REGEXKIT_H__


/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif






/**
Handle the extension based on the compiler
*/
# if defined(__INTEL_COMPILER)
#   define _LIB_CPLVERNUM "icl7"
# elif defined(__ICL)
#   define _LIB_CPLVERNUM "icl6"
# else
#   if (_MSC_VER >= 1400)
#     define _LIB_CPLVERNUM "vc80"
#   elif (_MSC_VER >= 1310)
#     define _LIB_CPLVERNUM "vc71"
#   elif (_MSC_VER >= 1300)
#     define _LIB_CPLVERNUM "vc70"
#   elif (_MSC_VER >= 1200)
#		ifdef VCF_GTK
#			define _LIB_CPLVERNUM "gtk"
#		else
#			define _LIB_CPLVERNUM "vc6"
#		endif
#   elif (_MSC_VER >= 1100)
#     define _LIB_CPLVERNUM "vc5"
#		endif
#  ifdef __BORLANDC__
#     define _LIB_CPLVERNUM "bcc"
#  endif
# endif


#ifdef _DEBUG
	#define REGEX_LIBDLL	"RegExKit_"_LIB_CPLVERNUM"_d.lib"
	#define REGEX_LIBS	"RegExKit_"_LIB_CPLVERNUM"_sd.lib"
#else
	#define REGEX_LIBDLL	"RegExKit_"_LIB_CPLVERNUM".lib"
	#define REGEX_LIBS	"RegExKit_"_LIB_CPLVERNUM"_s.lib"
#endif


//auto link stuff
#if defined(_MSC_VER) || defined(__BORLANDC__)
	#ifdef USE_REGEXKIT_DLL
		#pragma message( "linking to " REGEX_LIBDLL )
		#define REGEXKIT_DLL
		// using dynamic link library
		#ifdef _DEBUG
			#pragma comment(lib, "RegExKit_"_LIB_CPLVERNUM"_d.lib")
		#else
			#pragma comment(lib, "RegExKit_"_LIB_CPLVERNUM".lib")
		#endif
	#elif defined USE_REGEXKIT_LIB
		#pragma message( "linking to " REGEX_LIBS )
		// using statically linked library
		#ifdef _DEBUG
			#pragma comment(lib, "RegExKit_"_LIB_CPLVERNUM"_sd.lib")
		#else
			#pragma comment(lib, "RegExKit_"_LIB_CPLVERNUM"_s.lib")
		#endif
	#endif

#endif //VCF_MSC


//this sets up a "dependencies" set of defines
//if you are using the regex kit, then it only makes 
//sense that you are ALSO using the FoundationKit.
//the following takes care of defining these for you.

#ifdef USE_REGEXKIT_DLL
#pragma message( "REGEXKIT_DLL" )
//#		define ONIG_EXTERN extern __declspec(dllimport)
# 	ifndef REGEXKIT_DLL
#		define REGEXKIT_DLL
# 	endif
# 	ifndef USE_FOUNDATIONKIT_DLL
#		define USE_FOUNDATIONKIT_DLL
# 	endif
#elif defined (USE_REGEXKIT_LIB)
//#		define ONIG_EXTERN extern
# 	ifndef USE_FOUNDATIONKIT_LIB
#		define USE_FOUNDATIONKIT_LIB
# 	endif
#endif


//export crap
#ifdef REGEXKIT_DLL
	#if defined(REGEXKIT_EXPORTS)
		#define REGEXKIT_API __declspec(dllexport)
	#else
		#define REGEXKIT_API __declspec(dllimport)
	#endif
#else
	#define REGEXKIT_API
#endif //REGEXKIT_DLL




#include "thirdparty/common/oniguruma/oniguruma.h"
#include "vcf/FoundationKit/FoundationKit.h"
#include <set>






#ifdef VCF_VC60
#define VCF_REGEX_ITERATOR_SUBTRACTION_OPERATOR
#endif


namespace VCF {

	class REGEXKIT_API RegExKit {
	public:
		static void init( int argc, char** argv );

		static void terminate();
	};





namespace Regex{

    class Host;
	class Iterator;

	/**
	\class Match
	Contains details of matches found during regex searches, namely the
	regex object that performed the search, the position in which the match
	was made and the exact text that triggered the match.  This class is for
	reporting purposes only and as such it is not intended that objects of
	this type are created by the user.
	*/
    class REGEXKIT_API Match {
		friend class Host;
		friend class Iterator;
        public:
            Match(unsigned char* pos=NULL, String text="", Host* const env=NULL): pos_(pos),
				matchText_(text), env_(env), linkedNext_(false), linkedPrev_(false){}
            Match(const Match& rhs): pos_(rhs.pos_), matchText_(rhs.matchText_), env_(rhs.env_),
				linkedNext_(rhs.linkedNext_), linkedPrev_(rhs.linkedPrev_){}

            Match& operator=(const Match& rhs){
                pos_=rhs.pos_;
                matchText_=rhs.matchText_;
                env_=rhs.env_;
				linkedNext_=rhs.linkedNext_;
				linkedPrev_=rhs.linkedPrev_;
                return *this;
            }

            bool operator==(const Match& rhs) const {
                return (pos_==rhs.pos_ && matchText_==rhs.matchText_ && env_==rhs.env_);
            }

			bool operator<(const Match& rhs) const {
				if (env_==rhs.env_) {
					if (pos_<rhs.pos_) {
						return true;
					}
					else if (pos_==rhs.pos_) {
						if (matchText_<rhs.matchText_) {
							return true;
						}
					}
				}
				return false;
			}

			/**
			Returns the offset position of the first character of the match.
			@return ptrdiff_t Offset position relative to the
			beginning of the search range.
			*/
            unsigned char* getPos() const {
                return pos_;
            }			

			/**
			Returns the offset position of the first character of the match.
			@return ptrdiff_t Offset position relative to the
			beginning of the search range.
			*/
            ptrdiff_t getPosAsOffset() const;

			/**
			Returns the text that matched the search expression.
			@return String Matching text.
			*/
            const String& getText() const {
                return matchText_;
            }

        private:
            unsigned char* pos_;
            String matchText_;
            Host* env_;
			mutable bool linkedNext_;
			mutable bool linkedPrev_;
    };

    typedef std::set<Match> MatchList;

	/**
	\class Iterator
	A bi-directional iterator to simplify the regex interface.
	ReverseIterator is also available.
	*/
    class REGEXKIT_API Iterator: public std::iterator<std::bidirectional_iterator_tag, const Match> {
        public:
            // trivial
            Iterator(const Match* data=NULL): data_(data){}

			Iterator(const Iterator& rhs): data_(rhs.data_){}

            Iterator& operator=(const Iterator& rhs){
                data_=rhs.data_;
                return (*this);
            }

            bool operator==(const Iterator& rhs) const {
                return data_==rhs.data_;
            }

            bool operator!=(const Iterator& rhs) const {
                return !(data_==rhs.data_);
            }

            const Match& operator*() const {
                return *data_;
            }

            const Match* operator->() const {
                return data_;
            }
            // input/forward
            const Iterator& operator++();
            Iterator operator++(int);
            // bidirectional
            const Iterator& operator--();
            Iterator operator--(int);

#ifdef VCF_REGEX_ITERATOR_SUBTRACTION_OPERATOR
			// this is used by VC6 to dereference reverse_iterators, strangely...
			Iterator operator-(const int& count) const {
				Iterator res(*this);

				for (int i=0; i < count; i++) {
					res --;
				}

				return res;
			}

#endif
        private:
            const Match* data_;
    };

#ifdef VCF_VC60
	typedef std::reverse_iterator<Iterator,const Match> ReverseIterator;
#else
    typedef std::reverse_iterator<Iterator> ReverseIterator;
#endif

	/**
	\class Host
	Base class for performing regex searches. Regex classes are
	derived from this to process a particular encoding method.
	Match results are stored within the Host object to facilitate
	iteration.
	<p>
	A Host object contains two unsigned char pointers which
	denote a search range beyond which the regex object	will
	not search.  Adjusting these pointers or any data within
	the search range after matches have	been found may
	invalidate iterators (see changeRangeBeginning and
	changeRangeEnd for more details).

	@see Ascii
	@see UTF_16LE
	*/
	class REGEXKIT_API Host: public Enumerator<Match> {
		friend class Match;
		friend class Iterator;
        public:
			virtual ~Host();

			// Enumerator-related functions
			virtual bool hasMoreElements(const bool &backward = false);
			virtual Match nextElement();
			virtual Match prevElement();
			virtual void reset(const bool &backward = false);
			Enumerator<Match>* getEnumerator() {
				reset();
				return this;
			}

			/**
			Parses the regex search string. This should always be
			called immediately after object creation.
			*/
			void compile();

			/**
			Finds the first match result at or after the specified position.
			@param unsigned char* Pointer to location to start matching.
			If this position points outside the search range, then
			the search will start at the beginning of the range.
			@return Iterator An iterator pointing to the match result.
			*/
			Iterator find(unsigned char* pos);
			
			/**
			Finds the first match result at or before the specified position.
			@param unsigned char* Pointer to location to start matching.
			If this position points outside the search range, then
			the search will start at the end of the range.
			@return Iterator An iterator pointing to the match result.
			*/
			Iterator rfind(unsigned char* pos);

			/**
			Finds the first match result at or after the specified position.
			@param ptrdiff_t Offset position from beginning of the search
			range.  If this position points outside the search range, then
			the search will start at the beginning of the range.
			@return Iterator An iterator pointing to the match result.
			*/
			Iterator find(ptrdiff_t pos) {
				return find(first_+pos);
			}
			
			/**
			Finds the first match result at or before the specified position.
			@param ptrdiff_t Offset position from beginning of the search
			range.  If this position points outside the search range, then
			the search will start at the end of the range.
			@return Iterator An iterator pointing to the match result.
			*/
			Iterator rfind(ptrdiff_t pos) {
				return rfind(first_+pos);
			}

			/**
			Finds all matches throughout the entire search range.
			@return MatchList A std::set<Match> containing all the matches found
			in order of position in the search range.
			*/
            MatchList findAll();

			/**
			Searches from the beginning for the first match.
			@return Iterator Either the first match or a past-the-end iterator
			if there are no matches.
			*/
			Iterator begin();

			/**
			Returns a past-the-end iterator.
			*/
            Iterator end(){
                return Iterator(&pastTheEnd_);
            }

			/**
			Returns a ReverseIterator to the result of end()
			*/
            ReverseIterator rbegin(){
                return ReverseIterator(end());
            }

			/**
			Returns a ReverseIterator to the result of begin()
			*/
            ReverseIterator rend(){
                return ReverseIterator(begin());
            }
			
			/**
			Moves the pointer that marks the beginning of the search range.
			This will invalidate any iterators that point to matches lying
			outside the new search range. Also, any offset values (such as
			from Match::getPosAsOffset()) previously calculated will now be
			incorrect.
			@param unsigned char* Pointer to the new range limit.
			@return unsigned char* Pointer to the previous range limit.
			*/
			unsigned char* changeRangeBeginning(unsigned char* newBeginning);
			
			/**
			Moves the pointer that marks the end of the search range.
			This will invalidate any iterators that point to matches lying
			outside the new search range.
			@param unsigned char* Pointer to the new range limit.
			@return unsigned char* Pointer to the previous range limit.
			*/
			unsigned char* changeRangeEnd(unsigned char* newEnd);

			/**
			Changes the regular expression for the search.  Note that this
			function calls clearCache().  If you want to retain previous
			search results, create a new Host object instead.
			@param String New regular expression
			@return String Old regular expression
			*/
			String changeSearchExpression(const String& newExpression);

			/**
			Deletes information about previously found matches.  Use this
			if the contents of the search range have changed since the
			last search or the last time the cache was cleared.  Note
			that this invalidates all iterators for	these matches.
			*/
			void clearCache() {
				cache_.clear();
				reset();
			}

        protected:

			typedef std::set<Match> MatchContainerT;

            Host(const String& expression, unsigned char* first, unsigned char* last, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);
			Host(const String& expression, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);
			virtual int init()=0;
			Iterator next(Iterator current) const;
			Iterator prev(Iterator current) const;
			virtual unsigned int characterWidth(const ptrdiff_t& pos) const=0;

			MatchContainerT cache_;
			typedef MatchContainerT::iterator InternalIterator;
			typedef MatchContainerT::const_iterator InternalConstIterator;
			Match pastTheEnd_;

            String expression_;
            unsigned char* first_;
            unsigned char* last_;
			regex_t* reg_;
			OnigSyntaxType* syntax_;
            OnigErrorInfo error_;
			Iterator enumerator;
    };

	/**
	\class Ascii
	Regex engine for Ascii text.  After creating this object, always
	call compile() immediately.
	@see Host
	*/
	class REGEXKIT_API Ascii: public Host {
		public:
			/**
			Standard constructor.  It is the user's responsibility to ensure
			that the data in the search range remains valid for the lifetime
			of the Ascii object.
			@param String Regular expression.
			@param unsigned char* Beginning of search range.
			@param unsigned char* End of search range.
			@param OnigSyntaxType The regex syntax used to interpret the
			expression.
			*/
            Ascii(const String& expression, unsigned char* first, unsigned char* last, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);

			/**
			Alternate constructor using a String to denote the search range.
			It is the user's responsibility to ensure that the String object
			remains valid for the lifetime of the Ascii object.
			@param String Regular expression.
			@param String Text to be searched.
			@param OnigSyntaxType The regex syntax used to interpret the
			expression.
			*/
            Ascii(const String& expression, const String& source, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);
		protected:
			virtual int init();
			virtual unsigned int characterWidth(const ptrdiff_t& pos) const {
				return 1;
			}
	};

	/**
	\class UTF_16LE
	Regex engine for UTF-16LE text.  After creating this object, always
	call compile() immediately.
	@see Host
	*/
	class REGEXKIT_API UTF_16LE: public Host {
		public:
			/**
			Standard constructor.  It is the user's responsibility to ensure
			that the data in the search range remains valid for the lifetime
			of the UTF_16LE object.
			@param String Regular expression.
			@param unsigned char* Beginning of search range.
			@param unsigned char* End of search range.
			@param OnigSyntaxType The regex syntax used to interpret the
			expression.
			*/
            UTF_16LE(const String& expression, unsigned char* first, unsigned char* last, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);
			
			/**
			Alternate constructor using a String to denote the search range.
			It is the user's responsibility to ensure that the String object
			remains valid for the lifetime of the UTF_16LE object.
			@param String Regular expression.
			@param String Text to be searched.
			@param OnigSyntaxType The regex syntax used to interpret the
			expression.
			*/
			UTF_16LE(const String& expression, const String& source, OnigSyntaxType* syntax=ONIG_SYNTAX_DEFAULT);
		protected:
			virtual int init();
			virtual unsigned int characterWidth(const ptrdiff_t& pos) const;
			bool Regex::UTF_16LE::isSurrogate(VCFChar octet) const;
	};
}; //end of namespace Regex


}; //end of namespace VCF




#endif //_VCF_REGEXKIT_H__
