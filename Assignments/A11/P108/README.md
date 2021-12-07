## 108 - Maximum Sum/Kadane's Algorithm
### Joshua Beaty
### Description:

A problem that is simple to solve in one dimension is often much more difficult to solve in more than
one dimension. Consider satisfying a boolean expression in conjunctive normal form in which each
conjunct consists of exactly 3 disjuncts. This problem (3-SAT) is NP-complete. The problem 2-SAT
is solved quite efficiently, however. In contrast, some problems belong to the same complexity class
regardless of the dimensionality of the problem.
Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest
sum. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the subrectangle with the largest sum is referred to as the maximal sub-rectangle.

#### Example

- Input: 
    - 4
    - 0 -2 -7 0 9 2 -6 2
    - -4 1 -4 1 -1
    - 8 0 -2


- Output: 
    - 15

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file                                              |
|   2   | [input](./input)           | Test input file from problem statement                     |

### Instructions

- Solution accepted by UVA Online Judge using C++11.

### Sources

- None