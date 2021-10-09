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
bool debugMode = true;

//when set to true, queries user for test cases instead of server
bool testing = true;

//when set to true, use randData from file
bool randData = true;

//ofstreams
ofstream fout, debug;

//global stuff
vector<vector<int>> coins;
int numCoins, heavyCoin, rem;

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
int Test(vector<vector<int>> vvi)
{
    if(randData){
        if (debugMode)
            debug << "Section Size: " << vvi[0].size() << "\nStarting Index: " << vvi[0][0] << "\n";

        string output = "Test ";

        //print out every number for 2 consecutive sections
        for (int i = 0; i < 2; i++)
        {
            for (int j : vvi[i])
            {
                output += to_string(j) + " ";
            }
        }
        //print out command 'Test'
        //flush to send the command to the server
        outputLine(output, true);
        int randResponse = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j : vvi[i])
            {
                if(j == heavyCoin){
                    if(i == 0)
                        randResponse = 1;
                    else if(i == 1)
                        randResponse = -1;
                }
            }
        }

        outputLine("Random Response: ");
        outputLine(to_string(randResponse), true);
        return randResponse;
    }
    else{
        if (debugMode)
            debug << "Section Size: " << vvi[0].size() << "\nStarting Index: " << vvi[0][0] << "\n";

        string output = "Test ";

        //print out every number for 2 consecutive sections
        for (int i = 0; i < 2; i++)
        {
            for (int j : vvi[i])
            {
                output += to_string(j) + " ";
            }
        }
        //print out command 'Test'
        //flush to send the command to the server
        if (testing)
            outputLine(output, true);
        else
            cout << output << flush;


        if (testing)
        {
            int first = vvi[0].back();
            int second = vvi[1].back();
            outputLine("\nIf the heavy coin is less than or equal to ");
            outputLine(to_string(first));
            outputLine(" please enter 1", true);
            outputLine("If the heavy coin is less than or equal to ");
            outputLine(to_string(second));
            outputLine(" please enter -1", true);
            outputLine("If the heavy coin is greater than ");
            outputLine(to_string(second));
            outputLine(" please enter 0", true);
        }
      int res = 90;
      cin >> res;
      return res;
    }
}

//takes a vector of ints and splits it into 3 subsets
void splitVector(vector<int> toSplit)
{
    if (debugMode)
    {
        debug << "\n==Spliting the following into 3 sections==\n";

        for (int d : toSplit)
            debug << to_string(d) << " ";
        
        debug << "\n\n";
    }

    if (toSplit.size() >= 3)
    {
        //get remainder
        rem = toSplit.size() % 3;
        //clear coins vector
        coins.clear();

        for (int i = 0; i < 3; i++)
        {
            vector<int> temp;
            for (int j = 0; j < toSplit.size() / 3; j++)
            {
                temp.push_back(toSplit[j] + ((toSplit.size() / 3) * i));
            }
            coins.push_back(temp);
        }
        //overwrite final section to include trailing remainder numberss
        if (rem != 0)
        {
            vector<int> temp;
            for (int i = 0; i < toSplit.size() / 3 + rem; i++)
                temp.push_back(toSplit[i] + ((toSplit.size() / 3) * 2));
            coins[2] = temp;
        }
    }
    else{
        //toSplit is 2 or less
        //clear coins vector
        coins.clear();
        vector<int> temp = {toSplit[0]};
        coins.push_back(temp);
        temp.clear();
        temp = {toSplit[1]};
        coins.push_back(temp);
    }
}

int main()
{
    //Open files
    fout.open("test.out");
    debug.open("debug.out");
    ofstream ans;
    //prints out data in the format:
    //guesses heavyCoins
    ans.open("OnlyAnswers");
    ifstream randIn;
    randIn.open("random.in");


    if (debugMode)
        debug << "==Program Initialized==\n\n";

    int cases = 0;
    //when testing is true, we need to prompt the user to provide server output.
    if (testing)
    {
        outputLine("How many cases(1-100) do you want to run? ");
    }

    //read in the number of cases
    if(randData)
        randIn >> cases;
    else
        cin >> cases;

    if (testing || debugMode)
        outputLine(to_string(cases), true);

    int caseCount = cases;
    //loop for the number of cases
    while (caseCount--)
    {
        //initialize the case
        numCoins = 0;
        heavyCoin = -99;

        if (debugMode)
            debug << "Starting Case: " << cases - caseCount << "\n";

        //if testing prompt for coins
        if (testing)
            while (numCoins < 3 || 120 < numCoins)
            {
                outputLine("How many coins(3-120) are in this case? ");
                if(randData)
                    randIn >> numCoins;
                else
                    cin >> numCoins;
            }
        else
            cin >> numCoins;

        if (testing || debugMode)
            outputLine(to_string(numCoins), true);

        //if testing, prompt user to decide on a heavy coin and
        //store the result for later comparison
        //repeat prompts
        if (testing)
        {
            while (heavyCoin < 0 || heavyCoin > numCoins)
            {
                outputLine("Which coin(1-number of coins) is heaviest? ");

                if(randData)
                    randIn >> heavyCoin;
                else
                    cin >> heavyCoin;
            }
        }

        if (testing || debugMode)
            outputLine(to_string(heavyCoin), true);

        int fakeCoin = 0;
        //keep track of the remainder to append to the third set
        int rem = numCoins % 3;
        //fill vector "coins" with numbers 1 to numCoins
        for (int i = 0; i < 3; i++)
        {
            vector<int> temp;
            for (int j = 1; j <= numCoins / 3; j++)
            {
                temp.push_back(j + ((numCoins / 3) * i));
            }
            coins.push_back(temp);
        }

        //add trailing remainders to the last section
        if (rem != 0)
        {
            vector<int> temp;
            for (int i = 1; i <= numCoins / 3 + rem; i++)
                temp.push_back(i + ((numCoins / 3) * 2));
            coins[2] = temp;
        }

        //create temporary vector to hold the winning section
        vector<int> tempV;
        int numTests = 1;
        //Keep searching while fakeCoin isn't found
        while (fakeCoin < 1 && numTests <= 5)
        {
            if (debugMode)
                debug << "==Testing section: " << numTests << "==\n";
            //To determine which coin is heaviest, the program needs to split the numCoins
            //into 3 chunks, and query the server for a result
            int response = -99;

            response = Test(coins);

            outputLine(to_string(response), true);

            //1 left is heavy,
            //-1 right is heavy,
            //0 left and right are the same
            switch (response)
            {
            case -1:
                //right is heavy
                tempV = coins[1];

                if (debugMode)
                {
                    debug << "\n==contents of tempV==\n";

                    for (int d : tempV)
                        debug << to_string(d) << " ";
                    
                    debug << "\n\n";
                }

                if (tempV.size() > 1)
                {
                    //Split section into 3 sets and recheck
                    splitVector(tempV);
                }
                else
                {
                    //size should be one and just return it
                    fakeCoin = tempV[0];
                }

                break;
            case 0:
                //sides are even
                tempV = coins[2];

                if (debugMode)
                {
                    debug << "\n==contents of tempV==\n";

                    for (int d : tempV)
                        debug << to_string(d) << " ";
                    
                    debug << "\n\n";
                }

                if (tempV.size() > 1)
                {
                    //Split section into 3 sets and recheck
                    splitVector(tempV);
                }
                else
                {
                    //size should be one and just return it
                    fakeCoin = tempV[0];
                }
                break;
            case 1:
                //left is heavy
                tempV = coins[0];

                if (debugMode)
                {
                    debug << "\n==contents of tempV==\n";

                    for (int d : tempV)
                        debug << to_string(d) << " ";
                    
                    debug << "\n\n";
                }

                if (tempV.size() > 1)
                {
                    //Split section into 3 sets and recheck
                    splitVector(tempV);
                }
                else
                {
                    //size should be one and just return it
                    fakeCoin = tempV[0];
                }
                break;
            }
            cout << "\n\n";

            tempV.clear();
            numTests++;
        }

        if (testing)
        {
            outputLine("Answer ");
            outputLine(to_string(fakeCoin), true);
            ans << fakeCoin << " ";
        }
        else
        {
            cout << "Answer " << fakeCoin << flush;
        }

        if (testing)
        {
            outputLine("Heavy Coin was chosen to be: ");
            outputLine(to_string(heavyCoin), true);
            ans << heavyCoin << '\n';
        }
        coins.clear();
    }

    fout.close();
    debug.close();
    ans.close();
    randIn.close();
    return 0;
}