/**
* Joshua Beaty
* 4883
* 12/07/2021
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

int addStrings(string, string);

int main()
{
    ofstream fout, debug;
    //open files
    fout.open("test.out");
    debug.open("debug.out");
    //initialize variables

    string left, right;

    while (cin >> left >> right && (left != "0" || right != "0"))
    {

        int c = addStrings(left, right);
        switch (c)
        {
        case 0:
            cout << "No carry operation.\n";
            fout << "No carry operation.\n";
            break;
        case 1:
            cout << "1 carry operation.\n";
            fout << "1 carry operation.\n";
            break;
        default:
            cout << c << " carry operations.\n";
            fout << c << " carry operations.\n";
            break;
        }
    }

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
}

int addStrings(string left, string right)
{
    int rtn = 0;
    int n = 0;
    int result = 0;
    int carry = 0;

    if (left.size() > right.size())
        n = left.size();
    else
        n = right.size();

    for (int i = 0; i <= n; i++)
    {
        int temp = 0;

        if (left.size() >= i)
            temp = left[left.size() - i] - '0';

        if (right.size() >= i)
            temp += right[right.size() - i] - '0';

        temp += carry;

        if (temp - 10 >= 0)
        {
            carry = 1;
            rtn++;
        }
        else
            carry = 0;
    }
    return rtn;
}