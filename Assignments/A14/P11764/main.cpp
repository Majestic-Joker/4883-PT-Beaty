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
    int cases;
    int test = 1;
    vector<int> j;
    cin >> cases;
    while(cases--){
        int jumps;
        int high = 0;
        int low = 0;
        cin >> jumps;

        if (jumps > 1)
        {
            while (jumps--)
            {
                int temp;
                cin >> temp;
                j.push_back(temp);
            }
            for (int i = 0; i < (j.size() - 1); i++)
            {
                if (j[i] > j[i + 1])
                    low++;
                else if (j[i] < j[i + 1])
                    high++;
            }
        }
        else
            cin >> jumps;

        cout << "Case " << test << ": " << high << " "  << low << "\n";
        fout << "Case " << test << ": " << high << " "  << low << "\n";

        j.clear();
        test++;
    }

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
}