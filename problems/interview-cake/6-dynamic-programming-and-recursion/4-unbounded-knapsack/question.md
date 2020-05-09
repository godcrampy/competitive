You are a renowned thief who has recently switched from stealing precious metals to stealing cakes because of the insane profit margins. You end up hitting the jackpot, breaking into the world's largest privately owned stock of cakes---the vault of the Queen of England.

While Queen Elizabeth has a *limited number of types of cake*, she has an *unlimited supply of each type*.

You brought a duffel bag that can hold limited weight, and you want to make off with the most valuable haul possible.

Write a function `maxDuffelBagValue()` that takes a vector of cake type objects and a weight capacity, and returns the *maximum monetary value* the duffel bag can hold.

For example:

```cpp
const vector<CakeType> cakeTypes {
  CakeType(7, 160),
  CakeType(3, 90),
  CakeType(2, 15),
};

unsigned int capacity = 20;

maxDuffelBagValue(cakeTypes, capacity);
// returns 555 (6 of the middle type of cake and 1 of the last type of cake)`
```

Weights and values may be any non-negative integer. Yes, it's weird to think about cakes that weigh nothing or duffel bags that can't hold anything. But we're not just super mastermind criminals---we're also meticulous about keeping our algorithms flexible and comprehensive.
