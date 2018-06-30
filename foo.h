#pragma once

#if defined (_WIN32)
  #if defined (foo_EXPORTS)
    #define  MYLIB_EXPORT __declspec(dllexport)
  #else /* defined (foo_EXPORTS) */
    #define  MYLIB_EXPORT __declspec(dllimport)
  #endif /* defined (foo_EXPORTS) */
#else /* defined (_WIN32) */
  #define MYLIB_EXPORT
#endif /* defined (_WIN32) */

namespace my {
void MYLIB_EXPORT Foo();
inline void Bar();
}
