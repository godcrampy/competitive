# Arrays and Vectors

## Arrays

Syntax:

```c++
Data_Type name[number_of_elemetnts] {init_list};
int a[5] {1, 2, 3, 4, 5};
int b[4] {1, 2}; // [1, 2, 0, 0, 0]
int c[] {1, 2, 3}; // [1, 2, 3]
int d[4] {1}; // [1, 0, 0, 0]
int e[3]{}; // [0, 0, 0]
```

## Multidimensional Arrays

Syntax:

```c++
int a[2][3];
// [row][column]
```

## Vectors

Dynamic Size.

```c++
vector <int> a(5); //[0, 0, 0, 0, 0]
vector <int> b {1, 2, 3}; [1, 2, 3]
b.size() // 3;
b[1] // 2
```

Vector Functions:

- size: returns the current size of vector
- begin: returns a random access iterator to the first element
- end: end iterator
- rend: reverse iterator to the last element(++ makes it go back)
- rbegin: reverse iterator to the first element(-- makes it go forward)
- push_back: push to the vector
- pop_back: pop to the vector (Does Not return the popped value)

## Multidimensional Vectors

```c++
vector <<vector<int>> a
{
  {1, 3, 4},
  {1, 3, 4},
  {1, 3, 4}
};
```
