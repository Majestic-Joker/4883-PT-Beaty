#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
//#include <fstream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file ".inp", "r", stdin)
#define FileOut(file) freopen(file ".out", "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1 << (n))
#define Last(i) (i & -i)
#define INF 500000000
#define EPS 1e-7
#define maxN 10000
#define endl "\n"

using namespace std;


typedef vector<int> vi;    // vector if ints
typedef pair<int, int> ii; // pair of ints
typedef vector<ii> vii;    // vector of pairs
typedef vector<vi> vvi;    // vector of vector of ints

int T, E, V;
int u, v;

vvi G;
vi colors;
int pos;

void printVVI(vvi graph) {
    REP(i, graph.size()) {
        REP(j, graph[i].size()) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void printColors(){
    cout << "colors: ";
    REP(i, V) {
        cout << colors[i] << " ";
    }
    cout << endl;
}

// colors[1,-1,-1,-1];
// c = 1
// ans = true

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int src) {
    colors[src] = 1;

    // Create a queue (FIFO) of vertex numbers a
    // nd enqueue source vertex for BFS traversal
    queue<int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to
    // BFS)
    while (!q.empty()) {
        // Dequeue a vertex from queue ( Refer
        // http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

        // Return false if there is a self-loop
        if (G[u][u] == 1)
            return false;

        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v) {
            // An edge from u to v exists and
            // destination v is not colored
            if (G[u][v] && colors[v] == -1) {
                // Assign alternate color to this
                // adjacent v of u
                colors[v] = 1 - colors[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (G[u][v] && colors[v] == colors[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite() {

    // This code is to handle disconnected graoh
    for (int i = 0; i < V; i++)
        if (colors[i] == -1)
            if (isBipartiteUtil(i) == false)
                return false;

    return true;
}

int main(int argc, char **argv) {
    bool isitreallybipartite;
    //ofstream fout;
    //fout.open("geekOutput");
    cin >> T;

    while (T--) {
        //setup for disjointed nodes
        int hasConnections[201];
        REP(a,201){
            hasConnections[a] = 0;
        }
        
        // get node and edge counts
        cin >> V >> E;

        G.resize(V);
        colors.resize(V, -1);

        REP(i, V) {
            G[i].resize(V, 0);
        }

        REP(i, E) {
            cin >> u >> v;
            //cout << s <<","<< t << endl;
            G[u][v] = 1;
            G[v][u] = 1;

            //helps determine if a node has connections
            if(hasConnections[u] == 0)
                hasConnections[u]++;
            
            if(hasConnections[v] == 0)
                hasConnections[v]++;
        }

        // printVVI(G);

        // 0 = pos
        // 1 = color count
        isitreallybipartite = isBipartite();

        int output = 0;


        if(!isitreallybipartite){
            output = -1;
        }
        else{
            if(E == 0){                             //if no edges
                output = V;
            }
            else{
                int count1 = 0;
                int count0 = 0;

                for(int c : colors){                //counting to find smallest set
                    //cout << c;
                    if(c > 0)
                        count1++;
                    else if(c==0)
                        count0++;
                }
                if(count1 > 0 && count0 > 0)
                    if(count0 == count1){
                        output = count0;
                    }
                    else if(count1 < count0){
                        output = count1;
                    }    
                    else if(count0 < count1){
                        output = count0;
                    }    
                else if(count1 > 0){
                    output = count1;
                }
                else if(count0 > 0){
                    output = count0;
                }

                if(count0!=count1)                  //finds disjointed nodes
                    REP(b, V){
                        if(hasConnections[b] == 0)
                        output++;
                    }
            }
        }
        G.clear();
        colors.clear();

        cout << output << endl;
        //fout << output << endl;
    }

    return 0;
}