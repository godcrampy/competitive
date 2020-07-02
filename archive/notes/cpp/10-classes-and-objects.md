# Classes and Objects in C++

Procedural languages like C give methods or functions all the power and control of data. On the contrary in Object Oriented languages, like C++, the data has contol over itself.

This file will be like a tutorial. We will create a complete class adding new features one by one.
We will create a complex numbers class.

### Creating Class

Classes can be created in the main file as well. But it is conventional to declare the class members(functions and variables) in an .h ore .hpp file and define the methods in another .cpp file. The .hpp file will thus hide all the implementation of the method provideing data abstraction.

Let's create our comple number class:

```c++
// ComplexNumber.hpp
class Complex_Number
{
public:
  int real;
  int complex;
}
```

Let's use this class in our main file:

```c++
Complex_Number a;
a.real = 5;
a.complex = 4;
// a = 5 + 4i
```

public members are the members which can be accessed by the world outside the class. private members can be accessed only inside the class by other members. It's conventional to make all the variables of a class as private and expose functions to access and modify them as we wish.
Let's make some getters and setters.

> Methods inside the class have access to the this poiter which has the memory address of the instance of the class.

```c++
// ComplexNumber.hpp
class ComplexNumber
{
private:
  int real;
  int complex;

public:
  int get_real_part();
  void set_real_part(int real);

  int get_complex_part();
  void set_complex_part(int complex);
};

```

```c++
// ComplexNumber.cpp
int ComplexNumber::get_real_part()
{
  return this->real;
}

void ComplexNumber::set_real_part(int real)
{
  this->real = real;
}

int ComplexNumber::get_complex_part()
{
  return this->complex;
}

void ComplexNumber::set_complex_part(int complex)
{
  this->complex = complex;
}
```

Let's add a print_number method

```c++
// ComplexNumber.hpp
class ComplexNumber
{
  //rest of the code
public:
  void print_number();
}
```

```c++
// ComplexNumber.cpp
// Rest of the code
void ComplexNumber::print_number()
{
  std::cout << this->real << " + " << this->complex << "i" << std::endl;
}
```

To make a class method inline, just add the inline keyword before the function definition and move the definition to the .hpp file

Constructors and Destructors are invoked during the creation and destruction of data. Both of them do not return anything. Destructors don't have arguments as well. Just like normal functions, we can overload these too.

```c++
// ComplexNumber.hpp
class ComplexNumber
{
public:
  ComplexNumber();
  ComplexNumber(int, int);
}
```

```c++
// ComplexNumber.cpp
ComplexNumber::ComplexNumber()
{
  this->real = 0;
  this->complex = 0;
}

ComplexNumber::ComplexNumber(int real, int complex)
{
  this->real = real;
  this->complex = complex;
}
```

```c++
// main.cpp
ComplexNumber a;
// 0 + 0i
ComplexNumber b(1, 4);
// 1 + 4i
```

The problem with the above constructors is that we do not assign the values while the object is being created but after it is created. We don't feel the difference implementation wise but theres a better way: Initilization Lists

```c++
// ComplexNumber.cpp
ComplexNumber::ComplexNumber() : real{0}, complex{0}
{
}

ComplexNumber::ComplexNumber(int real, int complex) : real{real}, complex{complex}
{
}
```

We can even _Delegate_ overloaded constructors

```c++
// ComplexNumber.cpp
ComplexNumber::ComplexNumber(int real, int complex) : real{real}, complex{complex}
{
}

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0)
{
}
```

And so can we define _Default_ values too. This can sometimes reduce the number of constructor definitions too. Be sure to write the default values only in the .hpp file and not in the .cpp files

```c++
// ComplexNumber.hpp
class ComplexNumber
{
public:
  ComplexNumber(int real = 0, int complex = 0);
}
```

```c++
// ComplexNumber.cpp
ComplexNumber::ComplexNumber(int real, int complex) : real{real}, complex{complex}
{
}
```

### Copy and Move

> The below concept of copying and moving is valid only if the class has a pointer variable

_Copy_

C++ provides a default copy constructor which copies an object.

```c++
ComplexNumber b(1, 4);
ComplexNumber a(b);
```

The default constructor copies the properties of the object one by one.
When we pass the object to a function by value, the same copy constructor is called. This is copying values one by one is known as _shallow copying_. Now suppose we had a class variable as a pointer to an integer. In such case, is we create a _shallow copy_ of an object a and store it in b, both a and b point to the same data thru the pointer. Moreover if b is deleted off stack, say if b was actually a copy made by pass by value, and if we have a delete operation in the destructor for the pointer(which we should), then a will loose the data too. Thus trying to access or modify the value of the pointer will cause an error.

Thus we need to redefine the copy constructor and make a _deep copy_.

```c++
class Node
{
private:
  int* data;
public:
  // normal constructor
  Node(int a)
  {
    this->data = new int(data)
  }
  // copy constructor
  Node(Node &source):Node(*source.data)
}
```

This will ensure that whenever we copy the object or pass it by value, the newly created object will have its own address for the data.

_Move_

Consider the following expressions:

```c++
int x = 0;
int y;
y = x;
200 = x;
x = 100 + 200;
```

l-values are the values which are assignable. r-values are temporary values which are not assignable.
In the above code in the first line, x is l-value and 0 is the r-value.
On the 3rd line x acts as an r-value ans y acts as l-value.
4th line will produce an error as we cannot assign the l-values.

In the 5th line, 100 + 200 is evaluated first to 300 and stored in temporary memory which we are not allowed to accessed and then this data is transferred to x;

Consider the following:

```c++
int x = 100;
auto aplha(int);
auto beta(int&);
auto gamma(int&&);

aplha(x); // Allowed: pass by value
aplha(200); // Allowed: pass by value

beta(x); // Allowed: pass by reference
beta(200); // ERROR: r-values not allowed

gamma(x); // ERROR: l-values not allowed
gamma(200); // Allowed: r-values are allowed
```

Consider the following code:

```c++
std::vector<Node> list_of_nodes;

Node a(5);

list_of_nodes.push_back(a);
list_of_nodes.push_back(Node{6});
```

Both the push*back are valid. Both of them are pass by value. In the first one, we created a \_deep copy* of a, which is the correct way. But in the secod one, we costruct the node object on the fly, and them make the _deep copy_ again which was not required and inefficient. To solve this we define the move constructor, which instead of _deep copying_, _shallow copies_ the object and then deletes the previous object.

```c++
class Node
{
private:
  int* data;
public:
  // normal constructor
  Node(int a)
  {
    this->data = new int(data)
  }
  // copy constructor
  Node(Node &source):Node(*source.data)
  // move constructor
  Node(Node &&source) : data{source.data}
  {
    source.data = nullptr;
  }
}
```

Notice how the source object is stripped off of its data pointer. This is really effective when we are passing values to function on the fly. Vectors in C++ constantly move in the memory to accomodate more data. When moving to another place, all the data is copied by value internally. Thus having the efficient move constructor will make copying the pointers more efficient.

### static members

Use static keyword

```c++
// ComplexNumber.hpp
class ComplexNumber
{
private:
  static int number_of_complex_numbers;
}
```

```c++
// ComplexNumber.cpp
int ComplexNumber::number_of_complex_numbers = 0;
// initial value
```

### const instance

If some instance of a class is const, then by default every method on invocation will result in error. But we want some methods like the getters to be still invocable. To do this just add the const keyword in the function declaration and definition

```c++
  int get_complex_part() const;
  int get_complex_part() const
  {
    return this->complex;
  }
```

### friend functions

Friend functions can access private members of objects if they are declared as friend in the class definition.

```c++
// ComplexNumber
class ComplexNumber
{
public:
  friend ComplexNumber addNumber(ComplexNumber, ComplexNumber);
};

// main.cpp
ComplexNumber addNumber(ComplexNumber a, ComplexNumber b){
  return ComplexNumber(a.real + b.real, a.complex + b.complex);
}
```
