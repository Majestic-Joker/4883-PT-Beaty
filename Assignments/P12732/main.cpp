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
void outputLine(string output)
{
    cout << output << '\n';
    fout << output << '\n';
    if (debugMode)
        debug << output << '\n';
}

//This function checks two sections of equal size based on a starting index.
void testSection(int sectionSize, int startingIndex){
    if(debugMode)
        debug << "Section Size: " << sectionSize << "\nStarting Index: " << startingIndex << "\n";

    //print out command 'Test'
    if(testing)
        outputLine("Test ");
    else
        cout << "Test ";

    //print out every number for 2 consecutive sections
    for(int i = startingIndex; i < (sectionSize*2); i++){
        if(testing)
            outputLine(to_string(i));
        else
            cout << i;
        
        cout << " ";
    }
    //flush to send the command to the server
    cout.flush();
    
    if(testing)
        outputLine("\nIf the heavy coin");
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
        for(int i = 1; i < numCoins; i++){
            coins.push_back(i);
        }

        int fakeCoin = 0;
        //Keep searching while fakeCoin isn't found
        while(fakeCoin < 1){
            //To determine which coin is heaviest, the program needs to split the numCoins
            //into 3 chunks, and query the server for a result
            int chunkSize = numCoins/3;
            int startingIndex = 1;
            testSection(chunkSize, startingIndex);
        }
        



    }

    fout.close();
    debug.close();
    return 0;
}