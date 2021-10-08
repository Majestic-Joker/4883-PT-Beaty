/**
* Joshua Beaty
* 4883
* 09/30/2021
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

//when set to true, queries user for test cases instead of server
bool testing = false;

//ofstreams
ofstream fout, debug;

//Sends output to both the console and the file and prints a new line after each
void outputLine(string output, bool newLine = false)
{
    cout << output;
    fout << output;
    if (debugMode)
        debug << output;

    if (newLine)
    {
        cout << '\n';
        fout << '\n';
        if (debugMode)
            debug << '\n';
    }
}

//This function checks two sections of equal size based on a starting index.
void testSection(int sectionSize, int startingIndex)
{
    if (debugMode)
        debug << "Section Size: " << sectionSize << "\nStarting Index: " << startingIndex << "\n";

    //print out command 'Test'
    if (testing)
        outputLine("Test ");
    else
        cout << "Test ";

    //print out every number for 2 consecutive sections
    for (int i = startingIndex; i <= ((sectionSize * 2 + startingIndex) - 1); i++)
    {
        if (testing)
        {
            outputLine(to_string(i));
            outputLine(" ");
        }
        else
        {
            cout << i << " ";
        }
    }
    //flush to send the command to the server
    cout.flush();

    if (testing)
    {
        outputLine("\nIf the heavy coin is less than ");
        outputLine(to_string((sectionSize + startingIndex) - 1));
        outputLine(" please enter 1", true);
        outputLine("If the heavy coin is greater than ");
        outputLine(to_string((sectionSize + startingIndex) - 1));
        outputLine(" please enter -1", true);
        outputLine("If the heavy coin is greater than ");
        outputLine(to_string((sectionSize * 2 + startingIndex) - 1));
        outputLine(" please enter 0", true);
    }
}

int main()
{
    //Open files
    fout.open("test.out");
    debug.open("debug.out");

    if (debugMode)
        debug << "==Program Initialized==\n\n";

    int cases = 0;
    //when testing is true, we need to prompt the user to provide server output.
    if (testing)
        outputLine("How many cases do you want to run? (1-100)");

    //read in the number of cases
    cin >> cases;
    if (testing)
        fout << cases << '\n';

    if (debugMode)
        debug << "Total number of cases is: " << cases << "\n";

    int caseCount = cases;
    //loop for the number of cases
    while (caseCount--)
    {
        //initialize the case
        int numCoins = 0;
        int heavyCoin = -99;
        vector<int> coins;

        if (debugMode)
            debug << "Starting Case: " << cases - caseCount << "\n";

        //if testing prompt for coins
        if (testing)
            while (numCoins < 3 || 120 < numCoins)
            {
                outputLine("How many coins are in this case? (3-120)");
                cin >> numCoins;
            }
        else
            cin >> numCoins;

        if (testing)
            fout << numCoins << '\n';

        //if testing, prompt user to decide on a heavy coin and
        //store the result for later comparison
        //repeat prompts
        if (testing)
        {
            while (heavyCoin < 0 || heavyCoin > numCoins)
            {
                outputLine("Which coin is heaviest? (1-number of coins)");
                cin >> heavyCoin;
            }
        }

        //fill vector "coins" with numbers 1 to numCoins
        for (int i = 1; i < numCoins; i++)
        {
            coins.push_back(i);
        }

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
            if (debugMode)
                debug << "==Testing section: " << numTests << "==\n";
            //To determine which coin is heaviest, the program needs to split the numCoins
            //into 3 chunks, and query the server for a result
            int response = -99;

            if (chunkSize > 1)
            {
                if (debugMode)
                    debug << "\n==chunkSize greater than 1==\n";
                //send a test command to the server or output and get a response
                testSection(chunkSize, startingIndex);
                cin >> response;
                //change startingIndex and chunkSize based on response
                switch (response)
                {
                case 0:
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
                    if (debugMode)
                        debug << "Starting index is now: " << startingIndex << "\nChunk size is now: " << chunkSize << "\nRemainder is now: " << addToThirdSet << "\n";
                    break;
                case 1:
                    //left side is heavier, starting index should stay the same
                    //get new remainder
                    addToThirdSet = chunkSize % 3;
                    //get new chunkSize
                    chunkSize = chunkSize / 3;
                    if (debugMode)
                        debug << "Starting index is now: " << startingIndex << "\nChunk size is now: " << chunkSize << "\nRemainder is now: " << addToThirdSet << "\n";
                    break;
                case -1:
                    //right side is heavier, starting index becomes the first index of the second set
                    startingIndex += chunkSize;
                    //get new remainder
                    addToThirdSet = chunkSize % 3;
                    //get new chunkSize
                    chunkSize = chunkSize / 3;
                    if (debugMode)
                        debug << "Starting index is now: " << startingIndex << "\nChunk size is now: " << chunkSize << "\nRemainder is now: " << addToThirdSet << "\n";
                    break;
                }
            }
            else
            {
                if (debugMode)
                    debug << "\n==chunkSize less than or equal to 1==\n==Testing Potential Last Section==\n";
                //send a test command to the server or output and get a response
                testSection(chunkSize, startingIndex);
                cin >> response;
                //if chunkSize is 0 then it's either the first second or third set.
                switch (response)
                {
                case 0:
                    if (addToThirdSet != 0)
                    {
                        addToThirdSet = 0;
                        chunkSize = 1;
                        startingIndex += 2;
                    }
                    else
                        fakeCoin = startingIndex + 2;
                    break;
                case 1:
                    //first set
                    fakeCoin = startingIndex;
                    break;
                case -1:
                    //second set
                    fakeCoin = startingIndex + 1;
                    break;
                }
            }
            numTests++;
        }

        if (testing)
        {
            outputLine("Answer ");
            outputLine(to_string(fakeCoin), true);
        }
        else
        {
            cout << "Answer " << fakeCoin << '\n';
            cout.flush();
        }

        if (testing)
        {
            outputLine("Heavy Coin was chosen to be: ");
            outputLine(to_string(heavyCoin), true);
        }
    }

    fout.close();
    debug.close();
    return 0;
}