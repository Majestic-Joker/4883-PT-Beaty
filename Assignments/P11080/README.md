## 11080 - Place the Guards
### Joshua Beaty
### Description:

A king has terrible guards that fight each other when they guard the same street. He can place them at street junctions and the guards will guard that junction as well as adjacent streets and junctions. The problem is to determine if he can place guards to guard the entire city without them fighting and the minimum number of guards it will take.

#### Example

- Input: 
    - 2
    - 4 2
    - 0 1
    - 2 3
    - 5 5
    - 0 1
    - 1 2
    - 2 3
    - 0 4
    - 3 4
- Output: 
    - 2
    - "-1"

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file.                                             |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Larger test input from udebug user brianfry713             |


### Instructions

- This project was accepted by UVA Judge using C++ 11

### Sources

- Geeks for Geeks
    - [Bipartite Graph](https://www.geeksforgeeks.org/bipartite-graph/) explains what a bipartite graph is and basic steps
    to figure out if a graph is bipartite. While is does provide code, I am attempting to not use it and just implement 
    the basic steps using what I know.
    - [For Each](https://www.geeksforgeeks.org/g-fact-40-foreach-in-c-and-java/) looked up the syntax to use a foreach
    loop in C++