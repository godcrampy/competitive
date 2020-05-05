You created a game that is more popular than Angry Birds.

Each round, players receive a score between 0 and 100, which you use to rank them from highest to lowest. So far you're using an algorithm that sorts in `O(nlogn)` time, but players are complaining that their rankings aren't updated fast enough. You need a faster sorting algorithm.

Write a function that takes:

1.  a vector of unsortedScores
2.  the highestPossibleScore in the game

and returns a sorted vector of scores in less than `O(nlogn)` time.

For example:

```c++
const vector<int> unsortedScores {37, 89, 41, 65, 91, 53};
const int HIGHEST_POSSIBLE_SCORE = 100;

vector<int> sortedScores = sortScores(unsortedScores, HIGHEST_POSSIBLE_SCORE);
// sortedScores: [91, 89, 65, 53, 41, 37]
```

We're defining nn as the number of unsortedScores because we're expecting the number of players to keep climbing.

And, we'll treat highestPossibleScore as a constant instead of factoring it into our big O time and space costs because the highest possible score isn't going to change. Even if we *do* redesign the game a little, the scores will stay around the same order of magnitude.
