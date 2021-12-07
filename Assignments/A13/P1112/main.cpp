/**
* Joshua Beaty
* 4883
* 12/07/2021
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;
vector<pair<int,int>> g[101];

int dijkstra(int x, int N, int T){
    priority_queue<pair<int,int>> priQ;
    int distance[101];
    for(int i = 1; i <= N; i++){
        distance[i] = 100000000;
    }
    priQ.push(pair<int,int>(x, 0));
    distance[x] = 0;
    int from, to, t, cost;
    while(!priQ.empty()){
        from = priQ.top().first;
        cost = priQ.top().second;
        priQ.pop();

        if( distance[from] == cost && distance[from] <= T)
            for( int i = 0; i < (int)g[from].size(); i++){
                to = g[from][i].first;
                t = g[from][i].second;
                if(distance[from] + t < distance[to]){
                    distance[to] = distance[from] + t;
                    priQ.push(pair<int,int>(to,distance[to]));
                }
            }
    }

    int mice = 0;
    for(int i = 1; i <= N; i++)
        if(distance[i] <= T)
            mice++;
    return mice;
}

int main ()
{  
    ofstream fout, debug;
    //open files
    fout.open("test.out");
    debug.open("debug.out");
    //initialize variables
    int test, from, to, t, E, M, T, N;

    //read cases
    cin >> test;
    while(test--){
        cin >> N >> E >> T >> M;
        for(int i = 0; i < M; i++){
            cin >> from >> to >> t;
            g[to].push_back(pair<int,int>(from,t));
        }
        cout << dijkstra(E, N, T) << '\n';
        fout << dijkstra(E, N, T) << '\n';
        
        if(test){
            cout << '\n';
            fout << '\n';
        }
        
        for(int i = 1; i <= N; i++)
            g[i].clear();
    }

    //close files
    fout.close();
    debug.close();
    //terminate program
    return 0;
} 