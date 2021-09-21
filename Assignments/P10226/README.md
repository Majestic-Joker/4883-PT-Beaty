## 10226 - Hardwood Species
### Joshua Beaty
### Description:

Forests are big and have many tree species. A satellite flies over head and provides an input for each tree species in a given forest one species per line. Write a program that reads in the data and determines the percentage of every species listed in a test case.

While it's possible to get the correct answer using vectors and nodes, it's too slow for UVA to accept it so a map will be required to get an accepted solution from UVA online judge.

#### Example

- Input: 
    - 1
    - Red Alder
    - Ash
    - Aspen
    - Basswood
    - Ash
    - Beech
    - Yellow Birch
    - Ash
    - Cherry
    - Cottonwood
    - Ash
    - Cypress
    - Red Elm
    - Gum
    - Hackberry
    - White Oak
    - Hickory
    - Pecan
    - Hard Maple
    - White Oak
    - Soft Maple
    - Red Oak
    - Red Oak
    - White Oak
    - Poplan
    - Sassafras
    - Sycamore
    - Black Walnut
    - Willow

- Output: 
    - Ash 13.7931
    - Aspen 3.4483
    - Basswood 3.4483
    - Beech 3.4483
    - Black Walnut 3.4483
    - Cherry 3.4483
    - Cottonwood 3.4483
    - Cypress 3.4483
    - Gum 3.4483
    - Hackberry 3.4483
    - Hard Maple 3.4483
    - Hickory 3.4483
    - Pecan 3.4483
    - Poplan 3.4483
    - Red Alder 3.4483
    - Red Elm 3.4483
    - Red Oak 6.8966
    - Sassafras 3.4483
    - Soft Maple 3.4483
    - Sycamore 3.4483
    - White Oak 10.3448
    - Willow 3.4483
    - Yellow Birch 3.4483

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | First solution file, correct answer, but too slow for UVA  |
|   2   | [main2.cpp](./main2.cpp)   | Second solution file using map                             |
|   3   | [input](./input)           | Test input file from problem statement                     |
|   4   | [input2](./input2)         | Larger test input from udebug user shimul_cseustc          |
|   5   | [input3](./input3)         | Alternative test input from udebug user brianfry713        |

### Instructions

- This project was accepted by UVA Judge using C++ 11

### Sources

- Geeks for Geeks
    -[Maps in C++](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/) explains how maps associate a key with data. Since the key can be a string it was pretty useful for this problem.