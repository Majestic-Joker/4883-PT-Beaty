/**
* Joshua Beaty
* 4883
* 09/14/2021
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool debugMode = true;

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    int bp;
    vector<int> neighbors;
    vector<int> connections;
    bool hasGuard;
    bool guarded;

    Node(){
        totalNeighbors = 0;
        bp = 0;
        hasGuard = false;
        guarded = false;
    }
};

int main() {
    ofstream fOut;
    fOut.open("testOutput.txt");
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
            //Set a vector of nodes "junctions" to hold the junctions
            vector<Node*> junctions;
            int countJ = totalJunctions;
            while(countJ > 0){
                //create basic node and push it on the vector 'junctions'
                Node* temp = new Node();
                junctions.push_back(temp);
                countJ--;
            }
            //and set a vector of nodes "streets" to hold the streets
            vector<Node*> streets;
            int countS = totalStreets;
            while(countS > 0){
                //create basic node and push it on the vector 'junctions'
                Node* temp = new Node();
                streets.push_back(temp);
                countS--;
            }
            if(debugMode){   
                cout << "Number of nodes in junctions: " << junctions.size() << '\n';
                cout << "Number of nodes in streets: " << streets.size() << '\n';                                                                   
            }
            //f and t correspond to the left and right numbers of the street endpoints.
            int f = 0;
            int t = 0;

            //loop through to read in street endpoints and set the Node's neighbors
            for(int j = 0; j < totalStreets; j++){
                if(debugMode && j == 0)
                    cout << "\nList of Streets\n";
                
                cin >> f;
                cin >> t;

                //push t onto the list of f's neighbors and f onto the list of t's neighbors
                junctions[f]->neighbors.push_back(t);
                junctions[t]->neighbors.push_back(f);
                //push j onto the list of f and t's connections
                junctions[f]->connections.push_back(j);
                junctions[t]->connections.push_back(j);
                //increment total neighbors of the node, any node with totalNeighbors = 0 is disjointed and adds to minGuards
                junctions[f]->totalNeighbors++;
                junctions[t]->totalNeighbors++;
                
                if(debugMode)
                    cout << "Street " << j << " connects junction " << f << " to junction " << t << "\n";
            }
            bool isBipartite = true;
            //for every node in junctions, if
            for(Node* bpCheck : junctions){
                //before checking bipart, make sure node isn't disconnected
                if(bpCheck->totalNeighbors != 0){
                    //if node hasn't been swapped around set itself and neighbors and neighborsNeighbors
                    if(bpCheck->bp == 0){
                        bpCheck->bp = 1;
                        for(int neighbor : bpCheck->neighbors){
                            if(junctions[neighbor]->bp == 0){
                                junctions[neighbor]->bp = 2;
                                for(int neighborNeighbor : junctions[neighbor]->neighbors){
                                    if(junctions[neighborNeighbor]->bp == 0)
                                        junctions[neighborNeighbor]->bp = 1;
                                } 
                            }  
                        }
                    }
                    //if node has been swapped around
                    else{
                        //check neighbors to see if they equal current node
                        for(int neighbor : bpCheck->neighbors){
                            if(bpCheck->bp == junctions[neighbor]->bp){
                                isBipartite = false;
                                break;
                            }
                        }
                    }
                }
                if(!isBipartite)
                    break;
            }

            if(isBipartite){
                if(debugMode)
                    cout << "\nThis graph is bipartite";
                //for every node in junctions count how many 1s and 2s there are
                int count1 = 0;
                int count2 = 0;
                int smallest1 = 999;
                int smallest2 = 999;
                for(int colors = 0; colors < junctions.size(); colors++){
                    if(junctions[colors]->bp > 0)
                        if(junctions[colors]->bp == 1){
                            if(smallest1 > colors)
                                smallest1 = colors;
                            count1++;
                        }
                        else{
                            if(smallest2 > colors)
                                smallest2 = colors;
                            count2++;
                        }
                }

                int starter = 0;
                if(count1 < count2){
                    //start with smallest 1
                    starter = smallest1;
                }
                else{
                    //start with smallest 2
                    starter = smallest2;
                }

                if(debugMode)
                    cout << "starting node is " << starter << '\n';

                //for every connected node in junctions, if not guarded, place guard and set neighboring junctions and streets to guarded.
                for(int z = starter; z < junctions.size(); z++){
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
                            for(int connection : junctions[z]->connections){
                                streets[connection]->guarded = true;
                                if(debugMode)
                                    cout << "Connecting street " << connection << " becomes guarded.\n";
                            }
                        }
                        else{
                            if(debugMode)
                                cout << "Node " << z << " is guarded\n";
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

                //check if any junctions are unguarded
                for(Node* x : junctions){
                    if(!x->guarded)
                        minGuards = -1;
                }
                //check if any streets are unguarded
                for(Node* y : streets){
                    if(!y->guarded)
                        minGuards = -1;
                }
            }
            else{
                if(debugMode)
                    cout << "\nThis graph is not bipartite\n";
                minGuards = -1;
            }

            if(debugMode)
                cout << "Answer is: " << minGuards << "\n\n";
            else{
                cout << minGuards << '\n';
                fOut << minGuards << '\n';
            }
        }
    }

    fOut.close();
    return 0;
}