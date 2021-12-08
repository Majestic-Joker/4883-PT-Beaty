/**
* Joshua Beaty
* 4883
* 12/07/2021
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;
vector<int> vI;
vector<char> vC;

string getCase();
void charsToInts();
bool solve(int);

int main()
{
    ofstream fout, debug;
    //open files
    fout.open("test.out");
    debug.open("debug.out");
    //initialize variables
    int sum = 0;
    string line = "";

    while (cin >> sum)
    {
        bool solved = false;
        line = getCase();
        for(char c : line)
            vC.push_back(c);
        charsToInts();

        solved = solve(sum);

        if(vI.size() == 0 || !solved)
            cout << "no\n";
        else
            cout << "yes\n";

        vC.clear();
        vI.clear();
    }

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
}

string getCase(){
    bool done = false;
    string info = "";
    string temp = "";
    int brackets = 0;
    cin >> info;

    temp = info;
    while (!done)
    {
        for (char c : temp)
        {
            if (c == '(')
                brackets++;
            else if (c == ')')
                brackets--;
        }


        if(brackets > 0){
            temp = "";
            cin >> temp;
            info += temp;
        }
        else
            done = true;
    }

    return info;
}

void charsToInts(){
    for(int a = 0; a < vC.size(); a++){
        if(vC[a] - '0' >= 0){
            int temp = vC[a]-'0';
            int i = 1;
            while(vC[a+i]-'0' >= 0){
                temp *= 10;
                temp += vC[a+i]-'0';
                i++;
            }
            a += i;
            vI.push_back(temp);
        }
    }
}

bool solve(int target){
    bool rtn = false;

    for(int z = 0; z < vI.size(); z++){
        target -= vI[z];
        if(target == 0){
            rtn = true;
            break;
        }
    }

    return rtn;
}