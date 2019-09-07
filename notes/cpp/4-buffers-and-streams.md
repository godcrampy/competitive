# Buffers and Streams

A **Stream** is a sequence of data. Think of it as a conveyer belt. The input stream is a stream of charecters from the keyboard.

A **Buffer** is temporary space of storage. The input buffer is where the data coming from the _Input Stream_ is stored. It is like a queue from which cin, scanf etc. function read incoming data.

### ```cin``` and ```scanf``` design
```cin``` and ```scanf``` work so that they only take the required data from the buffer. For example, if the input buffer has _[1, 2, '\n']_ and we are scanning an integer, these function will take _1_ and _2_ leaving the new line charecter in the buffer.

```c++
int a; // Input Buffer: []
cout << "Enter a Number: "; // []
// I type 12 and press enter
cin >> a; // [1, 2, '\n']
// cin takes the first two relevant charecters only
// a = 12
// ['\n']
```

Even if I send a few spaces before entering the number _12_ and then send a few spaces and then press enter, these functions will take only the required _12_ ignoring the _whitespace_ in the buffer. Note that on sending [space, space, space, 1, 2, space, space, '\n'], will result in the buffer to be modified to [space, space, '\n']. As the input function consume the initial whitespace till it get the relevant data ie. integers. Once it consumes 1 and 2 and then sees that next data in buffer is a whitespace, it stops and leaves the buffer as is with the remaining whitespace intact.

### Taking String input from ```cin``` and ```scanf```
This is where things start to break down. Suppose ```cin``` or ```scanf``` is expecting a string input and I send [a, b, c, space, d, e, f, '\n'], the functions will take _"abc"_ and then see space and stop there leaving the buffer with the _"def"_ data.

To overcome the whitespace problem, we use ```gets```, ```fgets```, ```cin.getline()``` etc. These functions keep on taking data from the buffer until they see a newline charecter. They consume the newline as well but don't store it in the data. The problem arises when ```cin``` or ```scanf``` are used with these functions.

```cpp
int a;
char name[50];

cout << "Enter a number "; // []
cin >> a; // [1, 2, '\n']
// 12 consumed. buffer: ['\n']
cout << "Enter your name"; // ['\n']
cin.getline(name, 50); // Reads the '\n' and stores nothing
// name = ""
```

Thus it is important to _flush_ the buffer before doing string input. A common way is to use ```getchar``` after every ```cin``` or ```scanf``` to consume the trailing '\n'. But it won't consume more than one charecter. Thus this won't work if someone passes [1, 2, space, '\n'], as a integer input as the '\n' will still remain in the buffer with ```getchar``` consuming the space.
One solution is to use ```while (getchar() != '\n')``` to consume the spaces till the nextline charecter. There is no possible way to get two '\n' for a single input. Hence this would work fine.

Similarly ```cin.ignore(numeric_limits<streamsize>::max(), '\n');``` would work as well. ```cin.ignore(int size, char delimiter)```, takes in two arguments. It keeps on clearing the buffer until it has cleared ```size``` number of charecters or it encountered the ```delimiter``` clearing it as well, whichever comes first. Instead of passing a random value as the first argument, we pass ```numeric_limits<streamsize>::max()``` which is available under the ```<limits>``` header.