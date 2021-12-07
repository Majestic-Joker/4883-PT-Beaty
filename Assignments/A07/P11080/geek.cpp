#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
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
vi colors2;
int pos;
//setup for disjointed nodes
int hasConnections[201];

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
    cout << "colors2: ";
    REP(i, V) {
        cout << colors2[i] << " ";
    }
    cout << endl;
}

// colors[1,-1,-1,-1];
// c = 1
// ans = true

// This function returns true if
// graph G[V][V] is Bipartite, else false
bool isBipartiteUtil(int src, int run) {
    if(run){
        //this run counts the colors and start with the smallest one
        int count0 = 0;
        int count1 = 0;
        for(int c: colors)
            if(c==0)
                count0++;
            else if(c==1)
                count1++;
        
        if(count0>=count1)
            colors[src] = 1;
        else
            colors[src] = 0;

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

            /*// Return false if there is a self-loop
            if (G[u][u] == 1)
                return false;
            */

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
                else if (G[u][v] && colors[v] == colors[u] && u!=v)
                    return false;
            }
        }

        // If we reach here, then all adjacent vertices can
        // be colored with alternate color
        return true;
    }
    else{
        //this run always starts at 1
        colors2[src] = 1;

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

            /*// Return false if there is a self-loop
            if (G[u][u] == 1)
                return false;
            */
            // Find all non-colored adjacent vertices
            for (int v = 0; v < V; ++v) {
                // An edge from u to v exists and
                // destination v is not colored
                if (G[u][v] && colors2[v] == -1) {
                    // Assign alternate color to this
                    // adjacent v of u
                    colors2[v] = 1 - colors2[u];
                    q.push(v);
                }

                // An edge from u to v exists and destination
                // v is colored with same color as u
                else if (G[u][v] && colors2[v] == colors2[u] && u!=v)
                    return false;
            }
        }

        // If we reach here, then all adjacent vertices can
        // be colored with alternate color
        return true;
    }
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(int r) {
    if(r){
        for (int i = 0; i < V; i++){
            if(hasConnections[i])
                if (colors[i] == -1)
                    if (isBipartiteUtil(i,r) == false)
                        return false;
        }

        return true;
    }
    else{
        for (int i = 0; i < V; i++){
            if(hasConnections[i])
                if (colors2[i] == -1)
                    if (isBipartiteUtil(i,r) == false)
                        return false;
        }

        return true;
    }
}

int main(int argc, char **argv) {
    bool isitreallybipartite;
    ofstream fout;
    fout.open("geekOutput");
    cin >> T;

    while (T--) {
        REP(a,201){
            hasConnections[a] = 0;
        }
        
        // get node and edge counts
        cin >> V >> E;

        G.resize(V);
        colors.resize(V, -1);
        colors2.resize(V, -1);

        REP(i, V) {
            G[i].resize(V, 0);
        }

        REP(i, E) {
            cin >> u >> v;
            //cout << s <<","<< t << endl;
            G[u][v] = 1;
            G[v][u] = 1;

            //helps determine if a node has connections
            hasConnections[u]++;
            hasConnections[v]++;
        }
        // gives me two versions of colorings
        isitreallybipartite = isBipartite(0);
        
        int smallestColor = 0;
        //no reason to run it again if the first one wasn't bipartite
        if(isitreallybipartite){
            isBipartite(1);
            //count the colors in each coloring method.
            int a0 = 0;
            int a1 = 0;
            int b0 = 0;
            int b1 = 0;
            for(int color = 0; color<colors.size(); color++){
                if(colors[color]==0)
                    a0++;
                else if(colors[color]==1)
                    a1++;
                
                if(colors2[color]==0)
                    b0++;
                else if(colors2[color]==1)
                    b1++;
            }
            int smallA = 0;
            int smallB = 0;
            if(a0<=a1)
                smallA = a0;
            else
                smallA = a1;

            if(b0<=b1)
                smallB = b0;
            else
                smallB = b1;

            if(smallA<=smallB)
                smallestColor = smallA;
            else
                smallestColor = smallB;
        }

        int output = 0;
        output = smallestColor;

        if(!isitreallybipartite){
            output = -1;
        }
        else{
            //printColors();
            //if a disconnected node is found
            for(int c : colors){
                if(c<0)
                    output++;
            }
        }
        G.clear();
        colors.clear();
        colors2.clear();

        if(V==1)
            output = 1;

        cout << output << endl;
        fout << output << endl;
    }

    return 0;
}