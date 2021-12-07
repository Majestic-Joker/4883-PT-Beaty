#include<iostream>
#include<fstream>
#include<map>
#include<iomanip>
#include<string>

using namespace std;

bool debugMode = false;

int main(){
    //initialize some stuff
    ofstream fout, debug;
    fout.open("test.out");
    int cases = 0;
    string lineIn;

    cin >> cases;
    int countCase = cases;
    if(debugMode)
        cout << "Cases: " << cases << '\n';
    //loop while there are active cases
    while(countCase--){
        if(debugMode)
            cout << "Case " << cases-countCase << " started.\n";

        //initlialize case variables
        int totalTrees = 0;
        string lineIn;
        map<string,int> treeSpecies;
        while(getline(cin, lineIn)){
            //this solves an issue with getline being weird with blank lines
            if(totalTrees == 0 && lineIn.size() == 0)
                continue;
            else if(lineIn.size() == 0)
                break;
            //locates the species that was just read in and increments the associated value
            treeSpecies[lineIn]++;
            //totalTrees just keeps track of how many trees have been counted
            totalTrees++;


        }
        if(debugMode){
            cout << "Total Trees: " << totalTrees << '\n';
        }

        for(auto t : treeSpecies){
            cout << t.first << ' ' << setprecision(4) << fixed << ((double)t.second/totalTrees)*100 << '\n';
            fout << t.first << ' ' << setprecision(4) << fixed << ((double)t.second/totalTrees)*100 << '\n';
        }

        if(cases!=(cases-countCase)){
            cout << '\n';
            fout << '\n';
        }
    }

    fout.close();
}