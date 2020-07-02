# Variables

When we declare a variable in any programming language, it stands as an abstraction for a memory location. The next time we access the variable, we are accessing the data in that memory location behind the scenes.

Example:

```c++
int age; // Associate age with $1001
age = 5; // $1001 = 00000101
a++; // $1001 = 00000110
```

### Defining Variables in C++

1. Uninitialized:

```c++
int age;
// Uninitalized: Value may be 0 or garbage depending on the compiler
```

2. C Style:

```c++
int age = 6;
```

3. Constructor Style Syntax:

```c++
int age (6);
```

4. C++11 List Initialization Syntax:

```c++
int age {6};
```

### int size in C++

- `int` and `unsigned`: atleast 16 bits (65,536)
- `long` and `unsigned long`: atleast 32 bits (4,294,967,296)
- `long long` and `unsigned long long`: atleast 64 bit (>10^19)

### Constants

- Literal Constants

```c++
2.5;
4;
4.0f; // float
```

- `const`

```c++
const float a {2.5};
a = 5; //error
```

- preprocessor define

```c++
#define a 2.5;
// DO NOT USE: The preprocessor doesn't know c++.
// So even if you use a reserved keyword by mistake, you won't get error
```
