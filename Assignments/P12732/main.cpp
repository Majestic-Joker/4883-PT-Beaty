/**
* Joshua Beaty
* 4883
* 09/30/2021
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

//when set to true, queries user for test cases instead of server
bool testing = false;

//Sends output to both the console and the file and prints a new line after each
void outputLine(string output, ofstream& file, ofstream& dbg){
    cout << output << '\n';
    file << output << '\n';
    if(debugMode)
        dbg << output << '\n';
}

int main(){
    //initialize file stuff
    ofstream fout, debug;
    fout.open("test.out");
    debug.open("debug.out");

    if(debugMode)
        debug << "==Program Initialized==\n\n";

    int cases = 0;
    //when testing is true, we need to prompt the user to provide server output.
    if(testing)
        outputLine("How many cases do you want to run? (1-100)", fout, debug);

    //read in the number of cases
    cin >> cases;
    if(testing)
        fout << cases << '\n';

    if(debugMode)
        debug << "Total number of cases is: " << cases << "\n";

    int caseCount = cases;
    //loop for the number of cases
    while(caseCount--){
        //initialize the case
        int numCoins = 0;
        int heavyCoin = -99;
        vector<int> coins;

        if(debugMode)
            debug << "Starting Case: " << cases-caseCount << "\n";

        //if testing prompt for coins
        if(testing)
            outputLine("How many coins are in this case?", fout, debug);

        cin >> numCoins;
        if(testing)
            fout << numCoins << '\n';
        
        //if testing, prompt user to decide on a heavy coin and 
        //store the result for later comparison
        //repeat prompts 
        if(testing){
            while(heavyCoin < 0 || heavyCoin > numCoins){
                outputLine("Which coin is heaviest? (1-number of coins)", fout, debug);
                cin >> heavyCoin;
            }
        }

        
    }

    
    fout.close();
    debug.close();
    return 0;
} 