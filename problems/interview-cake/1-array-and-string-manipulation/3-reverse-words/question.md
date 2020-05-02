You're working on a secret team solving coded transmissions.

Your team is scrambling to decipher a recent message, worried it's a plot to break into a major European National Cake Vault. The message has been *mostly* deciphered, but all the words are backward! Your colleagues have handed off the last step to you.

Write a function reverseWords() that takes a message as a string and reverses the order of the words in place.

For example:

```c++
string message = "cake pound steal";

reverseWords(message);

cout << message << endl;
// prints: "steal pound cake"
```

When writing your function, assume the message contains only letters and spaces, and all words are separated by one space.

### Gotchas

We can do this in `O(1)` space. Remember, in place.
