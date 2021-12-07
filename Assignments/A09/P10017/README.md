## 10017 - The Neverending Towers of Hanoi
### Joshua Beaty
### Description:

Classic recursive problem, there are 3 pegs(A, B, C), n disks, every disk is unique, disks are initially stacked on the A peg, goal is to move a disk at a time so all disks are on peg C with the smallest disk on top and the largest disk on the bottom.

The main goal of the program is to print out the puzzle state after each move.

#### Example

- Input: 
    - 64 2
    - 8 45
    - 0 0


- Output: 
    - A=> 8 7 6 5 4 3 2 1
    - B=>
    - C=>
    - 
    - A=> 8 7 6 5 4 3 2
    - B=> 1
    - C=>
    - etc...

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file                                              |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Larger test input from udebug user UVa Judge Online        |

### Instructions

- This project was accepted by UVA Judge using C++ 11

### Sources

- Geeks for Geeks
    -[Towers of Hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/) provides the recursive solution for this problem. Had to edit it a little to get the right output.