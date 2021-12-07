## 920 - Sunny Mountains
### Joshua Beaty
### Description:

Figure out how much horizontal right to left sun is hitting the exposed mountain peaks. 
My approach is to read the data as lines with a first coordinate and second coordinate as pairs of x,y. 
Creating a line will also calculate its slope intercept stuff. Then, I mask my list of lines to only include 
negatively sloped lines. Then I find the line with the largest first coordinate and 
mask to include only those following it.

From there, I use the slope intercept formula x=(y-b)/m to find the missing x coordinate.
m is the slope of the line.
y is the next peak's y value.
b is already calculated in the line creation step.

Then the length of the sloped line is the square root of rise squared plus run squared. AKA pythagorean theorem.
rise = high peak y - lower peak y
run = high peak x - lower peak x

Once the lengths of each slope have been established, adding them together is a simple matter.

#### Example

- Input: 
    - 2
    - 11
    - 1100 1200
    - 0 500
    - 1400 100
    - 600 600
    - 2800 0
    - 400 1100
    - 1700 600
    - 1500 800
    - 2100 300
    - 1800 700
    - 2400 500
    - 2
    - 0 1000
    - 1000 0


- Output: 
    - 1446.34
    - 1414.21

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file                                              |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Larger input file from uDebug user alberto.verdejo         |


### Instructions

- Program works using the ./main<"inputFilename" terminal syntax

### Sources

- None so far