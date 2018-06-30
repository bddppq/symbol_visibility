#pragma once

#if defined (_WIN32)
  #define  MYLIB_EXPORT __declspec(dllexport)
#else /* defined (_WIN32) */
 #define MYLIB_EXPORT
#endif

namespace my {
void MYLIB_EXPORT Foo();
void MYLIB_EXPORT Bar();
}
