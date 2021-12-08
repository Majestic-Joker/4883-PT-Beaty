/**
* Joshua Beaty
* 4883
* 12/07/2021
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

int main()
{
    ofstream fout, debug;
    //open files
    fout.open("test.out");
    debug.open("debug.out");
    //initialize variables

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
}