# Namespaces
Namespaces are used to avoid naming conflicts which might occur when we are using a large number of libraries. To use any _identifiers_ in a namespace, we need the scope resolution operator ie. ```::```.

Syntax:
```c++
namespace::identifier
```

To expose all the identifiers in a namespace:
```c++
using namespace name:
```

To expose only certain identifiers:
```c++
using std::cin
using std::cout
```