#pragma once
#ifdef __cplusplus
	#include <cstdint>
	#include <cmath>
	#include <memory>
/*
	You might have to change the float macros
	since some implementations don't support float_t or double_t,
	you might have to change long double for FLOAT64L aswell.
	You can use the following macros:

	#define STD_FLOAT32  float
	#define STD_FLOAT64  double
	#define STD_FLOAT64L double
*/
// if platform is x64
#if defined __x86_64__ /* GCC/Clang */ || defined _M_X64 //MSVC
	#define STD_FLOAT32  std::float_t
	#define STD_FLOAT64  std::double_t
	#define STD_FLOAT64L long double
#else // platform x86
	#define STD_FLOAT32  std::float_t
	#define STD_FLOAT64  std::double_t
	#define STD_FLOAT64L long double
#endif

#define TYPES_NAMESPACE_NAME dt
namespace TYPES_NAMESPACE_NAME {
//##############################################################
// bool implementation #########################################
	/*
		WARNING:
		Since some implementations do only use 1 bit for booleans
		you have to be very carefull using it, and it should only be
		used for it's purpose of setting either 1 or 0.
	*/
	using int1      = bool;
	// WARNING: Only use of 1/0 (true / false)
	using cint1     = const bool;
	// WARNING: Only use of 1/0 (true / false)
	using int1ref   = bool&;
	// WARNING: Only use of 1/0 (true / false)
	using cint1ref  = const bool&;
	
	// WARNING: Only use of 1/0 (true / false)
	using int1ptr   = bool*;
	// WARNING: Only use of 1/0 (true / false)
	using cint1ptr  = const bool*;
	// WARNING: Only use of 1/0 (true / false)
	using cint1ptrc = const bool* const;

// end of bool impl ############################################
//##############################################################
	
	
//##############################################################
// types #######################################################
	using int8    = std::int8_t;
	using int16   = std::int16_t;
	using int32   = std::int32_t;
	using int64   = std::int64_t;
	using intmax  = std::intmax_t;
	
	using uint8   = std::uint8_t;
	using uint16  = std::uint16_t;
	using uint32  = std::uint32_t;
	using uint64  = std::uint64_t;
	using uintmax = std::uintmax_t;

	using float32 = STD_FLOAT32;
	using float64 = STD_FLOAT64;
	using float64l = STD_FLOAT64L;
	
	// ints fast
	using int8f   = std::int_fast8_t;
	using int16f  = std::int_fast16_t;
	using int32f  = std::int_fast32_t;
	using int64f  = std::int_fast64_t;
	
	using uint8f  = std::uint_fast8_t;
	using uint16f = std::uint_fast16_t;
	using uint32f = std::uint_fast32_t;
	using uint64f = std::uint_fast64_t;
	
	// ints least
	using int8s   = std::int_least8_t;
	using int16s  = std::int_least16_t;
	using int32s  = std::int_least32_t;
	using int64s  = std::int_least64_t;
	
	using uint8s  = std::uint_least8_t;
	using uint16s = std::uint_least16_t;
	using uint32s = std::uint_least32_t;
	using uint64s = std::uint_least64_t;
// end of types ################################################
//##############################################################


//##############################################################
// pointer #####################################################
	using intptr  = std::intptr_t;
	using uintptr = std::uintptr_t;
	using ptrdiff = std::ptrdiff_t;
	
	// int pointer
	using int8ptr    = std::int8_t*;
	using int16ptr   = std::int16_t*;
	using int32ptr   = std::int32_t*;
	using int64ptr   = std::int64_t*;
	using intmaxptr  = std::intmax_t*;
	
	using uint8ptr   = std::uint8_t*;
	using uint16ptr  = std::uint16_t*;
	using uint32ptr  = std::uint32_t*;
	using uint64ptr  = std::uint64_t*;
	using uintmaxptr = std::uintmax_t*;
	
	using float32ptr = STD_FLOAT32*;
	using float64ptr = STD_FLOAT64*;
	using float64lptr = STD_FLOAT64L*;

	// fast int pointer
	using int8fptr   = std::int_fast8_t*;
	using int16fptr  = std::int_fast16_t*;
	using int32fptr  = std::int_fast32_t*;
	using int64fptr  = std::int_fast64_t*;
	
	using uint8fptr  = std::uint_fast8_t*;
	using uint16fptr = std::uint_fast16_t*;
	using uint32fptr = std::uint_fast32_t*;
	using uint64fptr = std::uint_fast64_t*;
	
	// least int pointer
	using int8sptr   = std::int_least8_t*;
	using int16sptr  = std::int_least16_t*;
	using int32sptr  = std::int_least32_t*;
	using int64sptr  = std::int_least64_t*;
	
	using uint8sptr  = std::uint_least8_t*;
	using uint16sptr = std::uint_least16_t*;
	using uint32sptr = std::uint_least32_t*;
	using uint64sptr = std::uint_least64_t*;
// end of pointer ##############################################
//##############################################################
	
	
//##############################################################
// const types #################################################
	using cint8    = const std::int8_t;
	using cint16   = const std::int16_t;
	using cint32   = const std::int32_t;
	using cint64   = const std::int64_t;
	using cintmax  = const std::intmax_t;
	
	using cuint8   = const std::uint8_t;
	using cuint16  = const std::uint16_t;
	using cuint32  = const std::uint32_t;
	using cuint64  = const std::uint64_t;
	using cuintmax = const std::uintmax_t;
	
	using cfloat32 = const STD_FLOAT32;
	using cfloat64 = const STD_FLOAT64;
	using cfloat64l = const STD_FLOAT64L;
	
	// fast const
	using cint8f   = const std::int_fast8_t;
	using cint16f  = const std::int_fast16_t;
	using cint32f  = const std::int_fast32_t;
	using cint64f  = const std::int_fast64_t;
	
	using cuint8f  = const std::uint_fast8_t;
	using cuint16f = const std::uint_fast16_t;
	using cuint32f = const std::uint_fast32_t;
	using cuint64f = const std::uint_fast64_t;
	
	// least const
	using cint8s   = const std::int_least8_t;
	using cint16s  = const std::int_least16_t;
	using cint32s  = const std::int_least32_t;
	using cint64s  = const std::int_least64_t;
	
	using cuint8s  = const std::uint_least8_t;
	using cuint16s = const std::uint_least16_t;
	using cuint32s = const std::uint_least32_t;
	using cuint64s = const std::uint_least64_t;
// end of const types ##########################################
//##############################################################


//##############################################################
// pointer const value #########################################
	using cintptr  = const std::intptr_t;
	using cuintptr = const std::uintptr_t;
	using cptrdiff = const std::ptrdiff_t;
	
	// int pointer const
	using cint8ptr    = const std::int8_t*;
	using cint16ptr   = const std::int16_t*;
	using cint32ptr   = const std::int32_t*;
	using cint64ptr   = const std::int64_t*;
	using cintmaxptr  = const std::intmax_t*;
	
	using cuint8ptr   = const std::uint8_t*;
	using cuint16ptr  = const std::uint16_t*;
	using cuint32ptr  = const std::uint32_t*;
	using cuint64ptr  = const std::uint64_t*;
	using cuintmaxptr = const std::uintmax_t*;
	
	// float pointer const
	using cfloat32ptr = const STD_FLOAT32*;
	using cfloat64ptr = const STD_FLOAT64*;
	using cfloat64lptr = const STD_FLOAT64L*;
	
	// fast int pointer const
	using cint8fptr   = const std::int_fast8_t*;
	using cint16fptr  = const std::int_fast16_t*;
	using cint32fptr  = const std::int_fast32_t*;
	using cint64fptr  = const std::int_fast64_t*;
	
	using cuint8fptr  = const std::uint_fast8_t*;
	using cuint16fptr = const std::uint_fast16_t*;
	using cuint32fptr = const std::uint_fast32_t*;
	using cuint64fptr = const std::uint_fast64_t*;
	
	// least int pointer const
	using cint8sptr   = const std::int_least8_t*;
	using cint16sptr  = const std::int_least16_t*;
	using cint32sptr  = const std::int_least32_t*;
	using cint64sptr  = const std::int_least64_t*;
	
	using cuint8sptr  = const std::uint_least8_t*;
	using cuint16sptr = const std::uint_least16_t*;
	using cuint32sptr = const std::uint_least32_t*;
	using cuint64sptr = const std::uint_least64_t*;
// end of pointer const value ##################################
//##############################################################
	
	
//##############################################################
// const pointer ###############################################
	using intptrc  = std::intptr_t const;
	using uintptrc = std::uintptr_t const;
	using ptrdiffc = std::ptrdiff_t const;
	
	// int const pointer
	using int8ptrc    = std::int8_t* const;
	using int16ptrc   = std::int16_t* const;
	using int32ptrc   = std::int32_t* const;
	using int64ptrc   = std::int64_t* const;
	using intmaxptrc  = std::intmax_t* const;
	
	using uint8ptrc   = std::uint8_t* const;
	using uint16ptrc  = std::uint16_t* const;
	using uint32ptrc  = std::uint32_t* const;
	using uint64ptrc  = std::uint64_t* const;
	using uintmaxptrc = std::uintmax_t* const;
	
	// float const pointer
	using float32ptrc = STD_FLOAT32* const;
	using float64ptrc = STD_FLOAT64* const;
	using float64lptrc = STD_FLOAT64L* const;

	// fast int const pointer
	using int8fptrc   = std::int_fast8_t* const;
	using int16fptrc  = std::int_fast16_t* const;
	using int32fptrc  = std::int_fast32_t* const;
	using int64fptrc  = std::int_fast64_t* const;

	using uint8fptrc  = std::uint_fast8_t* const;
	using uint16fptrc = std::uint_fast16_t* const;
	using uint32fptrc = std::uint_fast32_t* const;
	using uint64fptrc = std::uint_fast64_t* const;

	// least int const pointer
	using int8sptrc   = std::int_least8_t* const;
	using int16sptrc  = std::int_least16_t* const;
	using int32sptrc  = std::int_least32_t* const;
	using int64sptrc  = std::int_least64_t* const;

	using uint8sptrc  = std::uint_least8_t* const;
	using uint16sptrc = std::uint_least16_t* const;
	using uint32sptrc = std::uint_least32_t* const;
	using uint64sptrc = std::uint_least64_t* const;
// end of const pointer ########################################
//##############################################################
	
	
//##############################################################
// const pointer and const value ###############################
	using cintptrc  = const std::intptr_t;
	using cuintptrc = const std::uintptr_t;
	using cptrdiffc = const std::ptrdiff_t;
	
	// const int pointer const
	using cint8ptrc    = const std::int8_t* const;
	using cint16ptrc   = const std::int16_t* const;
	using cint32ptrc   = const std::int32_t* const;
	using cint64ptrc   = const std::int64_t* const;
	using cintmaxptrc  = const std::intmax_t* const;
	
	using cuint8ptrc   = const std::uint8_t* const;
	using cuint16ptrc  = const std::uint16_t* const;
	using cuint32ptrc  = const std::uint32_t* const;
	using cuint64ptrc  = const std::uint64_t* const;
	using cuintmaxptrc = const std::uintmax_t* const;
	
	using cfloat32ptrc = const STD_FLOAT32* const;
	using cfloat64ptrc = const STD_FLOAT64* const;
	using cfloat64lptrc = const STD_FLOAT64L* const;
	
	// const fast int pointer const
	using cint8fptrc   = const std::int_fast8_t* const;
	using cint16fptrc  = const std::int_fast16_t* const;
	using cint32fptrc  = const std::int_fast32_t* const;
	using cint64fptrc  = const std::int_fast64_t* const;
	
	using cuint8fptrc  = const std::uint_fast8_t* const;
	using cuint16fptrc = const std::uint_fast16_t* const;
	using cuint32fptrc = const std::uint_fast32_t* const;
	using cuint64fptrc = const std::uint_fast64_t* const;
	
	// const least int pointer const
	using cint8sptrc   = const std::int_least8_t* const;
	using cint16sptrc  = const std::int_least16_t* const;
	using cint32sptrc  = const std::int_least32_t* const;
	using cint64sptrc  = const std::int_least64_t* const;
	
	using cuint8sptrc  = const std::uint_least8_t* const;
	using cuint16sptrc = const std::uint_least16_t* const;
	using cuint32sptrc = const std::uint_least32_t* const;
	using cuint64sptrc = const std::uint_least64_t* const;
// end of const pointer and const value ########################
//##############################################################
	
	
//##############################################################
// type reference ##############################################
	using int8ref    = std::int8_t&;
	using int16ref   = std::int16_t&;
	using int32ref   = std::int32_t&;
	using int64ref   = std::int64_t&;
	using intmaxref  = std::intmax_t&;
	
	using uint8ref   = std::uint8_t&;
	using uint16ref  = std::uint16_t&;
	using uint32ref  = std::uint32_t&;
	using uint64ref  = std::uint64_t&;
	using uintmaxref = std::uintmax_t&;
	
	// float reference
	using float32ref = STD_FLOAT32&;
	using float64ref = STD_FLOAT64&;
	using float64lref = STD_FLOAT64L&;

	// fast int reference
	using int8fref   = std::int_fast8_t&;
	using int16fref  = std::int_fast16_t&;
	using int32fref  = std::int_fast32_t&;
	using int64fref  = std::int_fast64_t&;

	using uint8fref  = std::uint_fast8_t&;
	using uint16fref = std::uint_fast16_t&;
	using uint32fref = std::uint_fast32_t&;
	using uint64fref = std::uint_fast64_t&;

	// least int reference
	using int8sref   = std::int_least8_t&;
	using int16sref  = std::int_least16_t&;
	using int32sref  = std::int_least32_t&;
	using int64sref  = std::int_least64_t&;

	using uint8sref  = std::uint_least8_t&;
	using uint16sref = std::uint_least16_t&;
	using uint32sref = std::uint_least32_t&;
	using uint64sref = std::uint_least64_t&;
// end of type reference #######################################
//##############################################################
	
	
//##############################################################
// const type reference ########################################
	using cint8ref    = const std::int8_t&;
	using cint16ref   = const std::int16_t&;
	using cint32ref   = const std::int32_t&;
	using cint64ref   = const std::int64_t&;
	using cintmaxref  = const std::intmax_t&;

	using cuint8ref   = const std::uint8_t&;
	using cuint16ref  = const std::uint16_t&;
	using cuint32ref  = const std::uint32_t&;
	using cuint64ref  = const std::uint64_t&;
	using cuintmaxref = const std::uintmax_t&;

	// float reference
	using cfloat32ref = const STD_FLOAT32&;
	using cfloat64ref = const STD_FLOAT64&;
	using cfloat64lref = const STD_FLOAT64L&;

	// fast int reference
	using cint8fref   = const std::int_fast8_t&;
	using cint16fref  = const std::int_fast16_t&;
	using cint32fref  = const std::int_fast32_t&;
	using cint64fref  = const std::int_fast64_t&;

	using cuint8fref  = const std::uint_fast8_t&;
	using cuint16fref = const std::uint_fast16_t&;
	using cuint32fref = const std::uint_fast32_t&;
	using cuint64fref = const std::uint_fast64_t&;

	// least int reference
	using cint8sref   = const std::int_least8_t&;
	using cint16sref  = const std::int_least16_t&;
	using cint32sref  = const std::int_least32_t&;
	using cint64sref  = const std::int_least64_t&;

	using cuint8sref  = const std::uint_least8_t&;
	using cuint16sref = const std::uint_least16_t&;
	using cuint32sref = const std::uint_least32_t&;
	using cuint64sref = const std::uint_least64_t&;
// end of const type reference #################################
//##############################################################
} // namespace end
using namespace TYPES_NAMESPACE_NAME;
#else // if not c++
	#include <stdint.h>
	#include <math.h>
/*
	You might have to change the float macros
	since some implementations don't support float_t or double_t,
	you might have to change long double for FLOAT64L aswell.
	You can use the following macros:
	
	#define FLOAT32  float
	#define FLOAT64  double
	#define FLOAT64L double
*/
// if platform is x64
#if defined __x86_64__ /* GCC/Clang */ || defined _M_X64 //MSVC
	#define FLOAT32  float_t
	#define FLOAT64  double_t
	#define FLOAT64L long double
#else // platform x86
	#define FLOAT32  float_t
	#define FLOAT64  double_t
	#define FLOAT64L long double
#endif
//##############################################################
// bool implementation #########################################
	/*
		WARNING:
		Since some implementations do only use 1 bit for booleans
		you have to be very carefull using it, and it should only be
		used for it's purpose of setting either 1 or 0.
	*/
	typedef bool		int1;
	// WARNING: Only use of 1/0 (true / false)
	typedef const bool  cint1;
	// WARNING: Only use of 1/0 (true / false)
	typedef bool&		int1ref;
	// WARNING: Only use of 1/0 (true / false)
	typedef const bool& cint1ref;

	// WARNING: Only use of 1/0 (true / false)
	typedef bool*		int1ptr;
	// WARNING: Only use of 1/0 (true / false)
	typedef const bool* cint1ptr;
	// WARNING: Only use of 1/0 (true / false)
	typedef const bool* const cint1ptrc;
// end of bool impl ############################################
//##############################################################
 

//##############################################################
// types #######################################################
	typedef int8_t    int8;
	typedef int16_t   int16;
	typedef int32_t   int32;
	typedef int64_t   int64;
	typedef intmax_t  intmax;
	
	typedef uint8_t   uint8;
	typedef uint16_t  uint16;
	typedef uint32_t  uint32;
	typedef uint64_t  uint64;
	typedef uintmax_t uintmax;

// if platform is x64
	typedef FLOAT32   float32;
	typedef FLOAT64   float64;
	typedef FLOAT64L  float64l;
	
	// ints fast
	typedef int_fast8_t     int8f;
	typedef int_fast16_t    int16f;
	typedef int_fast32_t    int32f;
	typedef int_fast64_t    int64f;

	typedef uint_fast8_t    uint8f;
	typedef uint_fast16_t   uint16f;
	typedef uint_fast32_t   uint32f;
	typedef uint_fast64_t   uint64f;

	// ints least
	typedef int_least8_t    int8s;
	typedef int_least16_t   int16s;
	typedef int_least32_t   int32s;
	typedef int_least64_t   int64s;

	typedef uint_least8_t   uint8s;
	typedef uint_least16_t  uint16s;
	typedef uint_least32_t  uint32s;
	typedef uint_least64_t  uint64s;
// end of types ################################################
//##############################################################

	
//##############################################################
// pointer #####################################################
	typedef intptr_t   intptr;
	typedef uintptr_t  uintptr;
	typedef ptrdiff_t  ptrdiff;

	// int pointer
	typedef int8_t*    int8ptr;
	typedef int16_t*   int16ptr;
	typedef int32_t*   int32ptr;
	typedef int64_t*   int64ptr;
	typedef intmax_t*  intmaxptr;

	typedef uint8_t*   uint8ptr ;
	typedef uint16_t*  uint16ptr;
	typedef uint32_t*  uint32ptr;
	typedef uint64_t*  uint64ptr;
	typedef uintmax_t* uintmaxptr;
	
	// float pointer
	typedef FLOAT32*   float32ptr;
	typedef FLOAT64*   float64ptr;
	typedef FLOAT64L*  float64lptr;

	// fast int pointer
	typedef int_fast8_t*     int8fptr ;
	typedef int_fast16_t*    int16fptr;
	typedef int_fast32_t*    int32fptr;
	typedef int_fast64_t*    int64fptr;

	typedef uint_fast8_t*    uint8fptr;
	typedef uint_fast16_t*   uint16fptr;
	typedef uint_fast32_t*   uint32fptr;
	typedef uint_fast64_t*   uint64fptr;
	
	// least int pointer
	typedef int_least8_t*	 int8sptr;
	typedef int_least16_t*   int16sptr;
	typedef int_least32_t*   int32sptr;
	typedef int_least64_t*   int64sptr;

	typedef uint_least8_t*   uint8sptr;
	typedef uint_least16_t*  uint16sptr;
	typedef uint_least32_t*  uint32sptr;
	typedef uint_least64_t*  uint64sptr;
// end of pointer ##############################################
//##############################################################
	
	
//##############################################################
// const types #################################################
	typedef const int8_t    cint8;
	typedef const int16_t   cint16;
	typedef const int32_t   cint32;
	typedef const int64_t   cint64;
	typedef const intmax_t  cintmax;
	
	typedef const uint8_t   cuint8;
	typedef const uint16_t  cuint16;
	typedef const uint32_t  cuint32;
	typedef const uint64_t  cuint64;
	typedef const uintmax_t cuintmax;
	
	typedef const FLOAT32   cfloat32;
	typedef const FLOAT64   cfloat64;
	typedef const FLOAT64L  cfloat64l;
	
	// ints fast
	typedef const int_fast8_t     cint8f;
	typedef const int_fast16_t    cint16f;
	typedef const int_fast32_t    cint32f;
	typedef const int_fast64_t    cint64f;
	
	typedef const uint_fast8_t    cuint8f;
	typedef const uint_fast16_t   cuint16f;
	typedef const uint_fast32_t   cuint32f;
	typedef const uint_fast64_t   cuint64f;
		
	// ints least
	typedef const int_least8_t    cint8s;
	typedef const int_least16_t   cint16s;
	typedef const int_least32_t   cint32s;
	typedef const int_least64_t   cint64s;
	
	typedef const uint_least8_t   cuint8s;
	typedef const uint_least16_t  cuint16s;
	typedef const uint_least32_t  cuint32s;
	typedef const uint_least64_t  cuint64s;
// end of const types ##########################################
//##############################################################
	
	
//##############################################################
// pointer const value #########################################
	typedef const intptr_t   cintptr;
	typedef const uintptr_t  cuintptr;
	typedef const ptrdiff_t  cptrdiff;
	
	// int pointer
	typedef const int8_t*    cint8ptr;
	typedef const int16_t*   cint16ptr;
	typedef const int32_t*   cint32ptr;
	typedef const int64_t*   cint64ptr;
	typedef const intmax_t*  cintmaxptr;
	
	typedef const uint8_t*   cuint8ptr;
	typedef const uint16_t*  cuint16ptr;
	typedef const uint32_t*  cuint32ptr;
	typedef const uint64_t*  cuint64ptr;
	typedef const uintmax_t* cuintmaxptr;
	
	// float pointer
	typedef const FLOAT32*   cfloat32ptr;
	typedef const FLOAT64*   cfloat64ptr;
	typedef const FLOAT64L*  cfloat64lptr;

	// fast int pointer
	typedef const int_fast8_t*    cint8fptr;
	typedef const int_fast16_t*   cint16fptr;
	typedef const int_fast32_t*   cint32fptr;
	typedef const int_fast64_t*   cint64fptr;

	typedef const uint_fast8_t*   cuint8fptr;
	typedef const uint_fast16_t*  cuint16fptr;
	typedef const uint_fast32_t*  cuint32fptr;
	typedef const uint_fast64_t*  cuint64fptr;

	// least int pointer
	typedef const int_least8_t*   cint8sptr;
	typedef const int_least16_t*  cint16sptr;
	typedef const int_least32_t*  cint32sptr;
	typedef const int_least64_t*  cint64sptr;

	typedef const uint_least8_t*  cuint8sptr;
	typedef const uint_least16_t* cuint16sptr;
	typedef const uint_least32_t* cuint32sptr;
	typedef const uint_least64_t* cuint64sptr;
// end of pointer const value ##################################
//##############################################################
	
	
//##############################################################
// const pointer ###############################################
	typedef intptr_t*  const intptrc;
	typedef uintptr_t* const uintptrc;
	typedef ptrdiff_t* const ptrdiffc;
	
	// int pointer
	typedef int8_t*    const int8ptrc;
	typedef int16_t*   const int16ptrc;
	typedef int32_t*   const int32ptrc;
	typedef int64_t*   const int64ptrc;
	typedef intmax_t*  const intmaxptrc;
	
	typedef uint8_t*   const uint8ptrc;
	typedef uint16_t*  const uint16ptrc;
	typedef uint32_t*  const uint32ptrc;
	typedef uint64_t*  const uint64ptrc;
	typedef uintmax_t* const uintmaxptrc;
	
	// float pointer
	typedef FLOAT32*   const float32ptrc;
	typedef FLOAT64*   const float64ptrc;
	typedef FLOAT64L*  const float64lptrc;

	// fast int pointer
	typedef int_fast8_t*    const int8fptrc;
	typedef int_fast16_t*   const int16fptrc;
	typedef int_fast32_t*   const int32fptrc;
	typedef int_fast64_t*   const int64fptrc;

	typedef uint_fast8_t*   const uint8fptrc;
	typedef uint_fast16_t*  const uint16fptrc;
	typedef uint_fast32_t*  const uint32fptrc;
	typedef uint_fast64_t*  const uint64fptrc;

	// least int pointer
	typedef int_least8_t*   const int8sptrc;
	typedef int_least16_t*  const int16sptrc;
	typedef int_least32_t*  const int32sptrc;
	typedef int_least64_t*  const int64sptrc;

	typedef uint_least8_t*  const uint8sptrc;
	typedef uint_least16_t* const uint16sptrc;
	typedef uint_least32_t* const uint32sptrc;
	typedef uint_least64_t* const uint64sptrc;
// end of const pointer ########################################
//##############################################################
	
	
//##############################################################
// const pointer and const value ###############################
	typedef const intptr_t*  const cintptrc;
	typedef const uintptr_t* const cuintptrc;
	typedef const ptrdiff_t* const cptrdiffc;
	
	// int pointer
	typedef const int8_t*    const cint8ptrc;
	typedef const int16_t*   const cint16ptrc;
	typedef const int32_t*   const cint32ptrc;
	typedef const int64_t*   const cint64ptrc;
	typedef const intmax_t*  const cintmaxptrc;
	
	typedef const uint8_t*   const cuint8ptrc;
	typedef const uint16_t*  const cuint16ptrc;
	typedef const uint32_t*  const cuint32ptrc;
	typedef const uint64_t*  const cuint64ptrc;
	typedef const uintmax_t* const cuintmaxptrc;
	
	// float pointer
	typedef const FLOAT32*   const cfloat32ptrc;
	typedef const FLOAT64*   const cfloat64ptrc;
	typedef const FLOAT64L*  const cfloat64lptrc;

	// fast int pointer
	typedef const int_fast8_t*    const cint8fptrc;
	typedef const int_fast16_t*   const cint16fptrc;
	typedef const int_fast32_t*   const cint32fptrc;
	typedef const int_fast64_t*   const cint64fptrc;

	typedef const uint_fast8_t*   const cuint8fptrc;
	typedef const uint_fast16_t*  const cuint16fptrc;
	typedef const uint_fast32_t*  const cuint32fptrc;
	typedef const uint_fast64_t*  const cuint64fptrc;

	// least int pointer
	typedef const int_least8_t*   const cint8sptrc;
	typedef const int_least16_t*  const cint16sptrc;
	typedef const int_least32_t*  const cint32sptrc;
	typedef const int_least64_t*  const cint64sptrc;

	typedef const uint_least8_t*  const cuint8sptrc;
	typedef const uint_least16_t* const cuint16sptrc;
	typedef const uint_least32_t* const cuint32sptrc;
	typedef const uint_least64_t* const cuint64sptrc;
// end of const pointer and const value ########################
//##############################################################
#endif