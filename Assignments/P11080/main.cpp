/**
* Joshua Beaty
* 4883
* 09/16/2021
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool debugMode = false;

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    int name;
    int side;
    bool placed;
    vector<Node*> neighbors;

    Node(){
        totalNeighbors = 0;
        name = 0;
        side = 0;
        placed = false;
    }
};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ofstream fOut;
    ofstream debug;
    fOut.open("testOutput.txt");
    debug.open("debug.out");
    //Create a variable to hold the total number of test cases.
    int totalCases = 0;
    
    cin >> totalCases;
    if(debugMode)
        debug << "totalCases: " << totalCases << "\n\n";

    int countT = totalCases;
    while(countT--){
        //read/store current case total junctions and total streets
        int minGuards = 0;
        int totalJunctions = 0;                                      //1<=V<=200
        int totalStreets = 0;                                        //0<=E<=10000                   
        if(debugMode)
            debug << "==Case " << (totalCases-countT) << " initialized==\n";

        cin >> totalJunctions;
        cin >> totalStreets;
        if(debugMode){                                                                     
            debug << "totalJunctions: " << totalJunctions << '\n';
            debug << "totalStreets: " << totalStreets << '\n';
        }

        //if no streets, minimum number of guards would be equal to the number of junctions.
        if(totalStreets == 0){
            minGuards = totalJunctions;
            if(debugMode)
                debug << "No streets, minGuards = totalJunctions\n";
        }
        else{
            //Set a vector of nodes "junctions" to hold the junctions
            vector<Node*> junctions;
            int countJ = totalJunctions;
            while(countJ--){
                if(debugMode)
                    debug << (totalJunctions-countJ)-1 << '\n';
                //create basic node and push it on the vector 'junctions'
                Node* temp = new Node();
                temp->name = (totalJunctions-countJ)-1;
                junctions.push_back(temp);
            }
            if(debugMode)   
                debug << "Number of nodes in junctions: " << junctions.size() << '\n';

            int countS = totalStreets;

            if(debugMode)
                debug << "\n==List of Streets==\n";
            //loop through to read in street endpoints and set the Node's neighbors
            while(countS--){
                //f and t correspond to the left and right numbers of the street endpoints.
                int f = 0;
                int t = 0;
                cin >> f;
                cin >> t;
                
                //skip if f=t;
                if(f!=t){
                    //push t onto the list of f's neighbors and f onto the list of t's neighbors
                    junctions[f]->neighbors.push_back(junctions[t]);
                    junctions[t]->neighbors.push_back(junctions[f]);
                    //increment total neighbors of the node, any node with totalNeighbors = 0 is disjointed and adds to minGuards
                    junctions[f]->totalNeighbors++;
                    junctions[t]->totalNeighbors++;

                    if(debugMode)
                        debug << "Street " << (totalStreets-countS)-1 << " connects junction " << f << " to junction " << t << "\n";
                }  
            }

            vector<Node*> left;
            vector<Node*> right;
            int smallSide = 0;
            if(debugMode)
                debug << "\n==Sorting Junctions==\n";
            //look at every node in junctions
            for(auto n : junctions){
                //if no neighbors, it doesn't get placed, and minGuards gets incremented
                if(n->totalNeighbors == 0){
                    minGuards++;
                    if(debugMode)
                        debug << n->name << " has no neighbors, gets no side, minGuards incremented\n";
                }
                //if n hasn't been given a side and sides are even or left is smaller
                else if(!n->placed && smallSide<=1){
                    //place n on the smaller side
                    left.push_back(n);
                    n->side = 1;
                    n->placed = true;
                    if(debugMode)
                        debug << n->name << " goes on the left side.\n";
                    //for every neighbor n has, put them on the right side if they haven't already been placed
                    for(auto a : n->neighbors){
                        if(!a->placed){
                            right.push_back(a);
                            a->side = 2;
                            a->placed = true;
                            if(debugMode)
                                debug << a->name << " goes on the right side.\n";
                            //for every neighbor a has, put them on the left side if they haven't already been placed
                            for(auto b : a->neighbors){
                                if(!b->placed){
                                    left.push_back(b);
                                    b->side = 1;
                                    b->placed = true;
                                    if(debugMode)
                                        debug << b->name << " goes on the left side.\n";
                                }
                            }
                        }
                    }
                }
                //if n hasn't been given a side and right is smaller
                else if(!n->placed && smallSide>1){
                    //place n on the smaller side
                    right.push_back(n);
                    n->side = 2;
                    n->placed = true;
                    if(debugMode)
                        debug << n->name << " goes on the right side.\n";
                    //for every neighbor n has, put them on the left side if they haven't already been placed
                    for(auto a : n->neighbors){
                        if(!a->placed){
                            left.push_back(a);
                            a->side = 1;
                            a->placed = true;
                            if(debugMode)
                                debug << a->name << " goes on the left side.\n";
                            //for every neighbor a has, put them on the right side if they haven't already been placed
                            for(auto b : a->neighbors){
                                if(!b->placed){
                                    right.push_back(b);
                                    b->side = 2;
                                    b->placed = true;
                                    if(debugMode)
                                        debug << b->name << " goes on the right side.\n";
                                }
                            }
                        }
                    }
                }
                //set small side
                if(left.size()<=right.size())
                    smallSide = 1;
                else
                    smallSide = 2;
            }


            if(debugMode)
                debug << "\n==Checking for connected nodes on left side==\n";
            bool sameSideFound = false;
            //for every node in left, check if its neighbors are also on the left.
            for(auto l : left){
                if(sameSideFound)
                    break;
                for(auto ln : l->neighbors){
                    if(l->side == ln->side){
                        sameSideFound = true;
                        if(debugMode){
                            debug << l->name << " is connected to " << ln->name << " on side " << l->side << '\n';
                            debug << "Connected nodes on same side, breaks\n\n";
                        }
                        break;
                    }   
                }
            }

            if(debugMode)
                debug << "\n==Checking for connected nodes on right side==\n";
            //then check right side
            //for every node in left, check if its neighbors are also on the left.
            for(auto r : right){
                if(sameSideFound)
                    break;
                for(auto rn : r->neighbors){
                    if(r->side == rn->side){
                        sameSideFound = true;
                        if(debugMode){
                            debug << r->name << " is connected to " << rn->name << " on side " << r->side << '\n';
                            debug << "Connected nodes on same side, breaks\n\n";
                        }
                        break;
                    }   
                }
            }

            if(debugMode)
                debug << "\n==Determining Output==\n";

            //after checking both sides, sameSideFound should be false or minGuards = -1
            //otherwise minGuards should += the smaller side's size
            if(sameSideFound){
                minGuards = -1;
                if(debugMode)
                    debug << "Same side found, minGuards becomes -1\n";
            }
            else{
                if(left.size()<=right.size()){
                    minGuards += left.size();
                    if(debugMode)
                        debug << "left size is either equal to or less than right size, minGuards += left size\n";
                }
                else{
                    minGuards += right.size();
                    if(debugMode)
                        debug << "right size is less than left size, minGuards += right size\n";
                }
            }
        }

        if(debugMode)
                debug << "+++Answer is: " << minGuards << "\n\n";
        else{
            cout << minGuards << '\n';
            fOut << minGuards << '\n';
        }
    }
    fOut.close();
    debug.close();
    return 0;
}