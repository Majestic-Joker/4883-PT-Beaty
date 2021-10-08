/**
* Joshua Beaty
* 4883
* 09/30/2021
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//This function checks two sections of equal size based on a starting index.
void testSection(int sectionSize, int startingIndex)
{
    //print out command 'Test'
    string output = "Test ";

    //print out every number for 2 consecutive sections
    for (int i = startingIndex; i <= ((sectionSize * 2 + startingIndex) - 1); i++)
    {
        output += to_string(i) + " ";
    }
    //flush to send the command to the server
    cout << output << flush;
}

int main()
{
    int cases = 0;
    //read in the number of cases
    cin >> cases;
    int caseCount = cases;
    //loop for the number of cases
    while (caseCount > 0)
    {
        //initialize the case
        int numCoins = 0;
        cin >> numCoins;

        int fakeCoin = 0;
        int chunkSize = numCoins / 3;
        int addToThirdSet = 0;
        //keep track of the remainder to append to the third set
        addToThirdSet = numCoins % 3;
        int startingIndex = 1;
        int numTests = 1;
        //Keep searching while fakeCoin isn't found
        while (fakeCoin < 1 || numTests < 5)
        {
            //To determine which coin is heaviest, the program needs to split the numCoins
            //into 3 chunks, and query the server for a result
            int response = -99;
            if (chunkSize > 1)
            {
                //send a test command to the server or output and get a response
                testSection(chunkSize, startingIndex);
                cin >> response;
                //change startingIndex and chunkSize based on response
                if (response == 0)
                {
                    //sides are even, starting index should become the start of third set
                    startingIndex += chunkSize * 2;
                    //chunkSize*3 gets last index, subtracting startingIndex gets total size of set, divide by 3 to get new chunkSize
                    chunkSize = chunkSize * 3;
                    //append remainder to third set
                    chunkSize += addToThirdSet;
                    //subtract startingIndex to get size of set
                    chunkSize -= startingIndex;
                    //track remainder
                    addToThirdSet = chunkSize % 3;
                    //divide by 3 to get chunkSize;
                    chunkSize = chunkSize / 3;
                }
                else if (response == 1)
                {
                    //left side is heavier, starting index should stay the same
                    //get new remainder
                    addToThirdSet = chunkSize % 3;
                    //get new chunkSize
                    chunkSize = chunkSize / 3;
                }
                else if (response == -1)
                {
                    //right side is heavier, starting index becomes the first index of the second set
                    startingIndex += chunkSize;
                    //get new remainder
                    addToThirdSet = chunkSize % 3;
                    //get new chunkSize
                    chunkSize = chunkSize / 3;
                }
            }
            else
            {
                //send a test command to the server or output and get a response
                testSection(chunkSize, startingIndex);
                cin >> response;
                //if chunkSize is 0 then it's either the first second or third set.
                if (response == 0)
                {
                    if (addToThirdSet != 0)
                    {
                        addToThirdSet = 0;
                        chunkSize = 1;
                        startingIndex += 2;
                    }
                    else
                        fakeCoin = startingIndex + 2;
                }
                else if (response == 1)
                {
                    //first set
                    fakeCoin = startingIndex;
                }
                else if (response == -1)
                {
                    //second set
                    fakeCoin = startingIndex + 1;
                }
            }
            numTests++;
        }
        

        cout << "Answer " << fakeCoin << flush;
        caseCount--;
    }
    return 0;
}