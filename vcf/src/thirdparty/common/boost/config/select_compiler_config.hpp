//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Martin Wille 2003.
//  (C) Copyright Guillaume Melquiond 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

// locate which compiler we are using and define
// BOOST_COMPILER_CONFIG as needed: 

# if defined __COMO__
//  Comeau C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/comeau.hpp"

#elif defined __DMC__
//  Digital Mars C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/digitalmars.hpp"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
//  Intel
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/intel.hpp"

# elif defined __GNUC__
//  GNU C++:
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/gcc.hpp"

#elif defined __KCC
//  Kai C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/kai.hpp"

#elif defined __sgi
//  SGI MIPSpro C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/sgi_mipspro.hpp"

#elif defined __DECCXX
//  Compaq Tru64 Unix cxx
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/compaq_cxx.hpp"

#elif defined __ghs
//  Greenhills C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/greenhills.hpp"

#elif defined __BORLANDC__
//  Borland
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/borland.hpp"

#elif defined  __MWERKS__
//  Metrowerks CodeWarrior
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/metrowerks.hpp"

#elif defined  __SUNPRO_CC
//  Sun Workshop Compiler C++
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/sunpro_cc.hpp"

#elif defined __HP_aCC
//  HP aCC
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/hp_acc.hpp"

#elif defined(__MRC__) || defined(__SC__)
//  MPW MrCpp or SCpp
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/mpw.hpp"

#elif defined(__IBMCPP__)
//  IBM Visual Age
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/vacpp.hpp"

#elif defined _MSC_VER
//  Microsoft Visual C++
//
//  Must remain the last #elif since some other vendors (Metrowerks, for
//  example) also #define _MSC_VER
#   define BOOST_COMPILER_CONFIG "thirdparty/common/boost/config/compiler/visualc.hpp"

#elif defined (BOOST_ASSERT_CONFIG)
// this must come last - generate an error if we don't
// recognise the compiler:
#  error "Unknown compiler - please configure (http://www.boost.org/libs/config/config.htm#configuring) and report the results to the main boost mailing list (http://www.boost.org/more/mailing_lists.htm#main)"

#endif
