#ifndef FORTRAN_FROM_CPLUSPLUS
#define FORTRAN_FROM_CPLUSPLUS

/*
   Definitions for calling FORTRAN 77 from C++
   ===========================================
   Author: Carsten Arnholm, 25-AUG-1995  (first Windows NT impl.)
   Rev1  : Carsten Arnholm, 21-DEC-1995  (Unix updates)
   Rev2  : Carsten Arnholm, 03-MAR-1996  (f77cmplx.h, f77matrx.h)
 */

typedef int INTEGER;          // INTEGER              4 bytes
typedef float REAL;             // REAL                 4 bytes
typedef double DOUBLE_PRECISION; // DOUBLE PRECISION     8 bytes
typedef int LOGICAL;          // LOGICAL              4 bytes

#include  <f77char.hh>           // character            n bytes
#include  <f77cmplx.hh>          // complex
#include  <f77matrx.hh>          // fmatrix class

// values for LOGICAL
#define FALSE 0
#define TRUE  1

// Macros for portable handling of linkage & calling conventions
// #ifdef F77_STUB_REQUIRED
// Typically, this branch is for Unix computers

// C++ stub functions:
#define SUBROUTINE                    inline void
#define INTEGER_FUNCTION              inline INTEGER
#define REAL_FUNCTION                 inline REAL
#define LOGICAL_FUNCTION              inline LOGICAL
#define DOUBLE_PRECISION_FUNCTION     inline DOUBLE_PRECISION

// FORTRAN functions
#define SUBROUTINE_F77                extern "C" void
#define INTEGER_FUNCTION_F77          extern "C" int
#define REAL_FUNCTION_F77             extern "C" float
#define LOGICAL_FUNCTION_F77          extern "C" int
#define DOUBLE_PRECISION_FUNCTION_F77 extern "C" double

// #else
//   // MS Windows using Microsoft compilers

//   // FORTRAN functions
//   #define SUBROUTINE            extern "C" void           __stdcall
//   #define INTEGER_FUNCTION      extern "C" INTEGER        __stdcall
//   #define REAL_FUNCTION         extern "C" REAL           __stdcall
//   #define LOGICAL_FUNCTION      extern "C" LOGICAL        __stdcall
//   #define DOUBLE_PRECISION_FUNCTION extern "C" DOUBLE_PRECISION  __stdcall
//
// #endif
#endif /* ifndef FORTRAN_FROM_CPLUSPLUS */
