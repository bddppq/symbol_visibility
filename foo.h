#pragma once

#if defined (_WIN32)
  #if defined(MyLibrary_EXPORTS)
    #define  MYLIB_EXPORT __declspec(dllexport)
  #else
    #define  MYLIB_EXPORT __declspec(dllimport)
  #endif /* MyLibrary_EXPORTS */
#else /* defined (_WIN32) */
 #define MYLIB_EXPORT
#endif

namespace my {
void MYLIB_EXPORT Foo();
void MYLIB_EXPORT Bar();
}
