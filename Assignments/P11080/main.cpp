/**
* Joshua Beaty
* 4883
* 09/14/2021
*/
#include <iostream>
#include <vector>

using namespace std;

bool debugMode = true;

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    vector<int> neighbors;
    vector<int> streets;
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
            cout << "Current Case: " << totalCases-i << '\n';     
            cout << "minGuards: " << minGuards << '\n';                                                                   
            cout << "totalJunctions: " << totalJunctions << '\n';
            cout << "totalStreets: " << totalStreets << '\n';
        }
        cin >> totalJunctions;
        cin >> totalStreets;

        if(debugMode){                                                                     
            cout << "totalJunctions: " << totalJunctions << '\n';
            cout << "totalStreets: " << totalStreets << '\n';
        }

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
            if(debugMode){   
                cout << "Number of Nodes: " << junctions.size() << '\n';                                                                   
            }
            //f and t correspond to the left and right numbers of the street endpoints.
            int f = 0;
            int t = 0;

            //loop through to read in street endpoints and set the Node's neighbors
            for(int j = totalStreets; j > 0; j--){
                if(debugMode && j == totalStreets)
                    cout << "\nList of Streets\n";
                
                cin >> f;
                cin >> t;

                //push t onto the list of f's neighbors and f onto the list of t's neighbors
                junctions[f]->neighbors.push_back(t);
                junctions[t]->neighbors.push_back(f);
                //increment total neighbors of the node, any node with totalNeighbors = 0 is disjointed and adds to minGuards
                junctions[f]->totalNeighbors++;
                junctions[t]->totalNeighbors++;
                
                if(debugMode)
                    cout << "Junction " << f << " is connected to " << t << "\n";
            }

            //for every connected node in junctions, if not guarded, place guard and set neighbors to guarded.
            for(int z = 0; z < junctions.size(); z++){
                if(debugMode)   
                    cout << "\nCurrent Node Position: " << z << '\n';                                                                   
            

                if(junctions[z]->totalNeighbors > 0){
                    if(debugMode)
                        cout << "Node " << z << " has " << junctions[z]->totalNeighbors << " neighbors\n";
                    
                    if(!junctions[z]->hasGuard && !junctions[z]->guarded){
                        if(debugMode)
                            cout << "Node " << z << " has no guards and isn't guarded" << '\n';
                        junctions[z]->hasGuard = true;
                        junctions[z]->guarded = true;
                        if(debugMode)
                            cout << "Node " << z << " gets a guard and becomes guarded" << '\n';
                        for(int node : junctions[z]->neighbors){
                            junctions[node]->guarded = true;
                            if(debugMode)
                                cout << "Neighbor Node " << node << " becomes guarded.\n";
                        }
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