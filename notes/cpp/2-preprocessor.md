# Preprocessor

The Preprocessor is a program that processes the cpp file before it is compiled. It does _not_ understand c++. It removes all the comments and replaces them with a space. Then it looks for preprocessor directives and executes them. These are the line begining with #. For example it replaces all `#include` statements with the real code.

```c++
#include <>
#if 1
#elif 1
#else
#endif
#define DIRECTIVE 1
#undef DIRECTIVE
#line
#error
#pragma
```
