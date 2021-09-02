## P161 - Traffic Lights
### Joshua Beaty
### Description:

On a given street there are 2 to 100 traffic lights with green light cycles between 10 and 90 seconds in length. The last five seconds of a cycle is orange. 

Write a program that determines how long it will be before all the lights are green again. The timer begins as soon as all the lights show green. Output will be in the **hh:mm:ss** format unless the time takes longer than 5 hours in which case the output will be *"Signals fail to synchronise in 5 hours"*.

#### Example

- Input: 
    - 19 20   0
    - 30
    -   25    35 0
    - 0 0 0
- Output: 
    - 00:00:40
    - 00:05:00

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file.                                             |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Test input file from uDebug user UVA Judge                 |
|   4   | [input3](./input3)         | Two initially incorrect cases from input2, solved by editing start time           |


### Instructions

- This solution was accepted by UVA Judge using C++ 11

### Sources

- No sources used so far.