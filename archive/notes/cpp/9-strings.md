# C++ Strings

### Getting strings from the user

> Make sure that the buffer is empty by using `while(getchar() != '\n');`

- **Charecter Array**: Use `std::cin.getline(str, length);`
- **std::string**: Use `std::getline(cin, str)`

### Initializing Strings

```c++
using namespace std;

string s1;               // Empty, No garbage Value
string s2 {"Sahil"};     // String Literal
string s3 {s2};          // Whole string will be copied unlike in c style
string s4 {"Sahil", 4};  // "l"
string s5 {s2, 1, 4};    // "ahil"
string s6 (5, 'a');      // "aaaaa" NOTICE the constructor syntax
```

### Concatenation

```c++
std::string name = "Sahil";

name = name + " Bondre";    // Allowed
name = "Sahil" + " Bondre"  // Not allowd as concatination of c style string not allowed
```

### For range

```c++
std::string name = "Sahil"
for(char a:name)
  std::cout << a;

```

### Comparision

`==, !=, >=, >, <, <=` all work. Greater than and less than work by comparing the ASCII values of charecters.
