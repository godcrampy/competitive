# Statement and Operators

### Type Conversion

Methods:

- C style casting: (type)value [Gives Runtime Errors]
- function style casting: type(value) [Gives Runtime Errors]
- static_cast: Prefer this over above two [Gives Complile-time Errors]
- dynamic_cast: Used for polymorphism
- const_cast: To toggle const
- reinterpret_cast: To cast between any types of pointers

syntax: `static_cast<type>(variable)`

> Note: static_cast, dynamic_cast, const_cast, reinterpret_cast are not functions but operators and thus are part of the c++ keywords

> Note: Do not cast const variable to non const and then change it. The behavior is undefined in this case.

```c++
// Do NOT do this
const int a = 5;
int* b = const_cast<*int>(&a);
*b = 6;
```

A good use case for const_cast is when some function requires const argument and you have a non const argument and vice-versa.
