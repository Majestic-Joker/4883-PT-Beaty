/**
* Joshua Beaty
* 4883
* 09/30/2021
*/

#include<iostream>
#include<fstream>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

//when set to true, queries user for test cases instead of server
bool testing = false;

int main(){
    //initialize file stuff
    ofstream fout, debug;
    fout.open("test.out");
    debug.open("debug.out");

    int cases = 0;

    
    fout.close();
    debug.close();
    return 0;
} 