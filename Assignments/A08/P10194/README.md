## 10194 - Football/Soccer
### Joshua Beaty
### Description:

Football the most popular sport in the world.  It's a very hard task to keep track of standings with so many teams participating and games being played. The .pdf says the task is quite simple: write a program that receives the tournament name, team names and games played. Then output the tournament standings so far.

My initial plan is to build a struct to hold team information and use a probably way overdone comparative function.

#### Example

- Input: 
    - 2
    - World Cup 1998 - Group A
    - 4
    - Brazil
    - Norway
    - Morocco
    - Scotland
    - 6
    - Brazil#2@1#Scotland
    - Norway#2@2#Morocco
    - Scotland#1@1#Norway
    - Brazil#3@0#Morocco
    - Morocco#3@0#Scotland
    - Brazil#1@2#Norway
    - Some strange tournament
    - 5
    - Team A
    - Team B
    - Team C
    - Team D
    - Team E
    - 5
    - Team A#1@1#Team B
    - Team A#2@2#Team C
    - Team A#0@0#Team D
    - Team E#2@1#Team C
    - Team E#1@2#Team D

- Output: 
    - World Cup 1998 - Group A
    - 1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
    - 2) Norway 5p, 3g (1-2-0), 1gd (5-4)
    - 3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
    - 4) Scotland 1p, 3g (0-1-2), -4gd (2-6)
    - 
    - Some strange tournament
    - 1) Team D 4p, 2g (1-1-0), 1gd (2-1)
    - 2) Team E 3p, 2g (1-0-1), 0gd (3-3)
    - 3) Team A 3p, 3g (0-3-0), 0gd (3-3)
    - 4) Team B 1p, 1g (0-1-0), 0gd (1-1)
    - 5) Team C 1p, 2g (0-1-1), -1gd (3-4)

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file                                              |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Larger test input from udebug user S6068                   |
|   4   | [input3](./input3)         | Larger test input from udebug user Morass                  |

### Instructions

- Solution accepted by UVA Online Judge using C++11

### Sources

- [Maps](./https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/) for setting up and accessing maps.