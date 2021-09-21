#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;

struct treeNode{
    string species;
    int count;
    double percentage;

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
    vector<treeNode*> vTrees;
    int totalTrees = 0;
    int cases = 0;
    int dump;

    cin >> cases;
    cin >> dump;
    while(cases--){
        string lineIn;
        while(getline(cin, lineIn)){
            //if vector is empty no need to check
            if(vTrees.empty()){
                treeNode* temp = new treeNode();
                temp->species = lineIn;
                temp->count++;
                vTrees.push_back(temp);    
                totalTrees++;
            }

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
                
        }
        //figure out the percentage of each tree
        //first sort the tree vector
        sort(vTrees.begin(), vTrees.end(), SortTreeNodePointers());

        for(treeNode* t : vTrees){
            cout << t->species << ' ' << ((double)t->count/totalTrees) << '\n';
            fout << t->species << ' ' << ((double)t->count/totalTrees) << '\n';
        }

        cout << '\n';
        cout << '\n';
        cin >> dump;
    }

}