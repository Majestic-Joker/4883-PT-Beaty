## 12732 - Guess the Fake Coin
### Joshua Beaty
### Description:

There are n coins, 1 coin is a fake coin. The real coins weigh the same as each other, 
the fake coin is heavier than the others.

Implement a series of functions to determine which coin is the fake one.

This is listed as an interactive problem on UVA Judge, which means every test sent to the server
will return some response until you have the information needed to provide an answer to the server. 
It's a back and forth communication for every test case, unlike other problems that just read in 
data and spit out output.

Server reponses to the test command are 1, 0, -1.
- 1 means that the left side is heavier than the right side
- 0 means that left side and right side are equal
- -1 means that left side is lighter than the right side

There are 1-100 test cases with 3-120 coins in each test case.

Using the input below, the server says there's one test case and that case has 9 coins.

The program should determine that 9 coins split into 3 sections 123, 456, and 789.
The program tests the first 2 sets 123 and 456 with the command: Test 1 2 3 4 5 6

The server responds with a -1, indicating that the set 456 is heavier than 123

The program should split 456 into 3 sections 4, 5, and 6.
The program tests the first 2 sets 4 and 5 with command: Test 4 5

The server responds with a 0, indicating that the sets are equal.

The program should determine that a 0 means, 6 is the heavy coin.
The program answers the test case with the command: Answer 6



#### Example

- Input: 
    - 1
    - 9
    - -1
    - 0


- Output: 
    - Test 1 2 3 4 5 6
    - Test 4 5
    - Answer 6

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file                                              |
|   2   | [Interactive Problems](./InteractiveProblems) | Instructions for how interactive problems work |

### Instructions

- This project was accepted by UVA Judge using C++ 11

### Sources

- UVA Online Judge
    - [Instructions to Interactive Problems](https://onlinejudge.org/contests/328-9976a2e2/interactive.html) explains how I/O should work for interactive problems.