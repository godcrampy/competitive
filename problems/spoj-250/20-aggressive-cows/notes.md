# 20 Agressive Cows

The naive approach to this problem is to store the positions in an array of size N. Then make another array of size N-1 of differences between these positions. Then one by one, remove the elements which lead to the smallest distance. We do this removal process N - C times. In every removal, we find the smallest distance pair costing us N order time and then we remove the apropriate element. Thus we get a N^2 time complexity.

An approach to this problem is by binary search. We are finding the maximum disance in the optimal array. This answer can be between and including 1 and the difference between the largest and smallest position. Thus we do binary search over this range. For every possible solution, we will check if it is feasable to fit the cows costing us N time. The search will cost us log(largest position - smallest position) time. This seems to be more efficient algorithm
