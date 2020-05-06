You have a vector of integers, and for each index you want to find the product of *every integer except the integer at that index.*

Write a function getProductsOfAllIntsExceptAtIndex() that takes a vector of integers and returns a vector of the products.

For example, given:

`[1, 7, 3, 4]`

your function would return:

`[84, 12, 28, 21]`

by calculating:

`[7 * 3 * 4, 1 * 3 * 4, 1 * 7 * 4, 1 * 7 * 3]`

Here's the catch: You can't use division in your solution!
