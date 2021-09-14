/**
* Joshua Beaty
* 4883
* 09/14/2021
*/
#include <iostream>
#include <vector>

//created a struct to keep track of some basic information.
struct Node{
    int totalNeighbors;
    vector<int> neighbors;
    bool hasGuard;

    Node(){
        totalNeighbors = 0;
        hasGuard = false;
    }
};

using namespace std;

int main() {
    //Create a variable to hold the total number of test cases.
    int totalCases = 0;
    cin >> totalCases;

    for(int i = totalCases; i > 0; i--){
        //read/store current case total junctions and total streets
        int minGuards = 0;
        int totalJunctions = 0;                                                                 //1<=V<=200
        int totalStreets = 0;                                                                   //0<=E<=10000
        cin >> totalJunctions;
        cin >> totalStreets;
        //if no streets, minimum number of guards would be equal to the number of junctions.
        if(totalStreets = 0){
            minGuards = totalJunctions;
        }
        else{
            //set an array to easily keep track of disjointed junctions, as they add 1 to the total number of needed guards
            int disJunctions[200]; //probably replacing this with a general vector of nodes
            //f and t correspond to the left and right numbers of the street endpoints.
            int f = 0;
            int t = 0;

            //loop through to read in street endpoints
            for(int j = totalStreets; j > 0; j--){
                cin >> f;
                cin >> t;
                //increment disJunctions based on connections
                disJunctions[f]++;
                disJunctions[t]++;
                //figure out how to track junctions and streets beyond disjunctions
            }

            //check if there are any disjointed junctions
            for(int k = totalJunctions-1; k >= 0; k-- ){
                if(disJunctions[k] == 0)
                    minGuards++;
            }
        }


        cout << minGuards << '\n';
    }

    return 0;
}