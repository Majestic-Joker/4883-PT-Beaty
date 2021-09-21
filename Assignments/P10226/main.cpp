#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>

using namespace std;

struct treeNode{
    string species;
    int count;

    treeNode(){
        species = "";
        count = 0;
    }

    bool operator<(const treeNode& other) const
    {
        return species < other.species; // order by name
    }
};

struct SortTreeNodePointers
{
    // overload the function call operator
    bool operator()(const treeNode* lhs, const treeNode* rhs) const
    {
        // dereference the pointers to compare their targets
        // using the Product class's operator<(...) function
        return *lhs < *rhs;
    }
};

bool debugMode = false;

int main(){
    //initialize some stuff
    ofstream fout, debug;
    fout.open("test.out");
    int cases = 0;
    string dump;

    cin >> cases;
    int countCase = cases;
    if(debugMode)
        cout << "Cases: " << cases << '\n';

    //dump first empty line
    getline(cin, dump);
    if(debugMode)
        cout << "dump is : " << dump << '\n';
    //loop while there are active cases
    while(countCase--){
        if(debugMode)
            cout << "Case " << cases-countCase << " started.\n";

        int totalTrees = 0;
        int count = 0;
        string lineIn;
        vector<treeNode*> vTrees;
        while(getline(cin, lineIn)){
            if(totalTrees == 0 && lineIn.size() == 0)
                continue;
            else if(lineIn.size() == 0)
                break;
            
            //if vector is empty no need to check
            /*if(vTrees.empty()){
                treeNode* temp = new treeNode();
                temp->species = lineIn;
                temp->count++; 
                vTrees.push_back(temp);    
                totalTrees++;
            }*/

            //if vector isn't empty compare line in to the currently stored species
            bool isFound = false;
            for(treeNode* tn : vTrees){
                if(tn->species.compare(lineIn) == 0){
                    //if lineIn is found in vector, set isFound to true;
                    isFound = true;
                    tn->count++;
                    totalTrees++;
                }
            }

            //if vector doesn't have the species yet.
            if(!isFound){
                treeNode* temp = new treeNode();
                temp->species = lineIn;
                temp->count++;
                vTrees.push_back(temp);    
                totalTrees++;
            }

            count++;
        }
        //figure out the percentage of each tree
        //first sort the tree vector
        sort(vTrees.begin(), vTrees.end(), SortTreeNodePointers());

        if(debugMode){
            cout << "Total Trees: " << totalTrees << '\n';
            cout << "Run times: " << count << '\n';
        }

        for(treeNode* t : vTrees){
            cout << t->species << ' ' << setprecision(4) << fixed << ((double)t->count/totalTrees)*100 << '\n';
            fout << t->species << ' ' << setprecision(4) << fixed << ((double)t->count/totalTrees)*100 << '\n';
        }

        cout << '\n';
        fout << '\n';
    }

    fout.close();
}