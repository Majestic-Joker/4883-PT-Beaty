/**
* Joshua Beaty
* 4883
* 09/14/2021
*/
#include <iostream>
#include <vector>

using namespace std;

bool debugMode = false;

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    vector<int> neighbors;
    bool hasGuard;
    bool guarded;

    Node(){
        totalNeighbors = 0;
        hasGuard = false;
        guarded = false;
    }
};

int main() {
    //Create a variable to hold the total number of test cases.
    int totalCases = 0;
    if(debugMode)
        cout << "totalCases: " << totalCases << '\n';

    cin >> totalCases;
    if(debugMode)
        cout << "totalCases: " << totalCases << '\n';

    for(int i = totalCases; i > 0; i--){
        //read/store current case total junctions and total streets
        int minGuards = 0;
        int totalJunctions = 0;                                      //1<=V<=200
        int totalStreets = 0;                                        //0<=E<=10000                   
        if(debugMode){
        cout << "totalCases: " << totalCases << '\n';    
        cout << "minGuards: " << minGuards << '\n';                                                                   
        cout << "totalJunctions: " << totalJunctions << '\n';
        cout << "totalStreets: " << totalJunctions << '\n';
        }
        cin >> totalJunctions;
        cin >> totalStreets;
        if(debugMode)
            cout << totalCases << '\n';
        if(debugMode)
            cout << totalCases << '\n';
        //if no streets, minimum number of guards would be equal to the number of junctions.
        if(totalStreets == 0){
            minGuards = totalJunctions;
        }
        else{
            //Set a vector "junctions" to hold the nodes
            vector<Node*> junctions;
            int count = totalJunctions;
            while(count > 0){
                //create basic node and push it on the vector 'junctions'
                Node* temp = new Node();
                junctions.push_back(temp);
                count--;
            }
            //f and t correspond to the left and right numbers of the street endpoints.
            int f = 0;
            int t = 0;

            //loop through to read in street endpoints and set the Node's neighbors
            for(int j = totalStreets; j > 0; j--){
                cin >> f;
                cin >> t;

                //push t onto the list of f's neighbors and f onto the list of t's neighbors
                junctions[f]->neighbors.push_back(t);
                junctions[t]->neighbors.push_back(f);
                //increment total neighbors of the node, any node with totalNeighbors = 0 is disjointed and adds to minGuards
                junctions[f]->totalNeighbors++;
                junctions[t]->totalNeighbors++;
                //figure out how to track junctions and streets beyond disjunctions
            }

            //for every connected node in junctions, if not guarded, place guard and set neighbors to guarded.
            for(Node* n : junctions){
                if(n->totalNeighbors > 0){
                    if(!n->hasGuard && !n->guarded){
                        n->hasGuard = true;
                        n->guarded = true;
                        for(int node : n->neighbors)
                            junctions[node]->guarded = true;
                    }
                }
            }

            //check if there are any disjointed junctions or junctions with guards
            for(int k = totalJunctions-1; k >= 0; k--){
                if(junctions[k]->totalNeighbors == 0){
                    minGuards++;
                }
                else if(junctions[k]->hasGuard){
                    minGuards++;
                }
            }

            //check if any nodes are unguarded
            for(Node* g : junctions){
                if(!g->guarded)
                    minGuards = -1;
            }
        }

        if(debugMode)
            cout << "Answer is: " << minGuards << "\n\n";
        else
            cout << minGuards << '\n';
    }

    return 0;
}