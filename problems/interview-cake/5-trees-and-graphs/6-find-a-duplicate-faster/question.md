Find a duplicate, Space Edition™ BEAST MODE

In [Find a duplicate, Space Edition™](https://www.interviewcake.com/question/cpp/find-duplicate-optimize-for-space), we were given a vector of integers where:

1.  the integers are in the range 1..n
2.  the vector has a length of n+1

These properties mean the vector *must have at least 1 duplicate*. Our challenge was to find a duplicate number, while optimizing for *space*. We used a divide and conquer approach, iteratively cutting the vector in half to find a duplicate integer in `O(nlgn)`time and `O(1)` space (sort of a modified binary search).

But we can actually do *better*. We can find a duplicate integer in O(n)O(n) time while keeping our space cost at `O(1)`.
