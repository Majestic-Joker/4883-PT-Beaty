/**
* Joshua Beaty
* 4883
* 09/28/2021
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool debugMode = false;
int minGuards;
bool bp = true;

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    int name;
    int color;
    vector<Node*> neighbors;
    bool visited;

    Node(){
        totalNeighbors = 0;
        name = 0;
        color = -1;
        visited = false;
    }
};

//A butchered Geeks for Geeks method to check bipartiteness.
//takes in the vector of Node pointers

//+++Not implemented yet+++
bool isBipartite(vector<Node*> adj)
{
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int>> q;

    //loop incase graph is not connected
    for (int i = 0; i < adj.size(); i++) {
    
        //if not connected
        if(adj[i]->totalNeighbors >0)
            //if not coloured
            if (adj[i]->color<0) {
            
                //colouring with 0 i.e. red
                q.push({ i, 0 });
                adj[i]->color = 0;
            
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                
                    //current vertex
                    int v = p.first;
                    //colour of current vertex
                    int c = p.second;
                
                    //traversing vertexes connected to current vertex
                    for (Node* n : adj[i]->neighbors) {
                
                        //if already coloured with parent vertex color
                        //then bipartite graph is not possible
                        if (n->color == c)
                            return 0;
                    
                        //if uncolored
                        if (n->color == -1) {
                            //colouring with opposite color to that of parent
                            n->color = (c) ? 0 : 1;
                            q.push({ n->name, n->color });
                    }
                }
            }
        }
    }
    //if all vertexes are coloured such that
      //no two connected vertex have same colours
    return 1;
}

void BFSbip(Node*& s, vector<Node*>& jS, ofstream& d){
    if(debugMode)
        d << "\n==Beginning Breadth First Search==\n";

    // Create a queue for BFS
    queue<Node*> bfs;
            
    // Mark the current node as visited, color and enqueue it
    s->visited = true;
    s->color = 0;
    bfs.push(s);

    while(!bfs.empty())
    {
        // Dequeue a vertex from queue
        Node* currentNode = bfs.front();
        bfs.pop();

        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent has not been visited, then mark it visited, color and enqueue it
        for (Node* nN : currentNode->neighbors)
        {
            //if already visited and colored with parent vertex color
            //then bipartite graph is not possible
            if (nN->visited)
                if(nN->color == currentNode->color){
                    bp = false;
                    return;
                }
            else{
                //not yet visited, set visited to true
                nN->visited = true;
                //colouring with opposite color to that of parent
                if(currentNode->color == 0)
                    nN->color = 1;
                else if(currentNode->color == 1)
                    nN->color = 0;
                bfs.push(nN);
            }
        }
    }
    if(bp){
        //count the minimum number of guards needed to patrol this section
        int count0 = 0;
        int count1 = 0;
        for(Node* v : jS){
            if(v->visited)
                if(v->color==0)
                    count0++;
                else if(v->color==1)
                    count1++;
        }
        if(count0<=count1)
            minGuards += count0;
        else
            minGuards += count1;
    }
}

int main() {
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
        bp = true;
        minGuards = 0;
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

            if(debugMode)
                debug << "\n==Sorting Junctions==\n";
            //look at every node in junctions
            for(Node* n : junctions){
                //hopefully goes through the entire graph in a good way.
                if(!n->visited)
                    BFSbip(n, junctions, debug); 
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