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
ofstream fout, debug;

int getTens(int);

int main()
{
    //open files
    fout.open("test.out");
    debug.open("debug.out");
    //initialize variables
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        debug << n << '\n';
        n *= 567;
        debug << n << '\n';
        n = n/9;
        debug << n << '\n';
        n += 7492;
        debug << n << '\n';
        n *= 235;
        debug << n << '\n';
        n = n/47;
        debug << n << '\n';
        n -= 498;
        debug << n << '\n';
        n = getTens(n);

        cout << n << '\n';
        fout << n << '\n';
    }

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
}

int getTens(int n){
    int rtn = 0;
    string s = "";
    s += to_string(n);
    debug << s << '\n';
    rtn = s[s.size()-2] - '0';
    debug << s[s.size()-2] << '\n';
    return rtn;
}