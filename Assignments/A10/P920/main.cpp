/*
* P920 - Sunny Mountains
* Joshua Beaty
* 4883
* 11/30/2021
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;

double lineLength(pair<double,double>, pair<double,double>);

//when set to true, prints debug messages to debug.out file
bool debugMode = false;
ofstream fout, debug;

int main(){
    //open files
    fout.open("test.out");
    debug.open("debug.out");

    //read cases
    int cases;
    cin >> cases;

    //iterate through each case
    while(cases--){
        //read number of points
        int points;
        cin >> points;
        map<double,double> pointMap;

        while(points--){
            //create temporary x and y values
            double tempX, tempY;
            //read into the temporary values
            cin >> tempX >> tempY;
            //slap the values into the map of points, auto sorted by X
            pointMap[tempX] = tempY;
        }

        // now we create a vector of sloped lines based on the X sorted map of points
        vector<pair<double,double>> coordinates;
        for(auto it = pointMap.begin(); it != pointMap.end(); it++){
            pair<double, double> temp;
            temp.first = it->first;
            temp.second = it->second;

            coordinates.push_back(temp);
        }

        int i = coordinates.size()-2;
        double answer = 0;
        double last = 0;
        while(i >= 0){
            if(coordinates[i].second > last){
                pair<double, double> temp;
                temp.first = coordinates[i].first+(coordinates[i+1].first - coordinates[i].first)*(last - coordinates[i].second)/(coordinates[i+1].second-coordinates[i].second);
                temp.second = last;
                
                answer += lineLength(temp, coordinates[i]);

                last = coordinates[i].second;
            }
            i--;
        }
        
        cout << fixed << setprecision(2) << answer << "\n";
        //fout << fixed << setprecision(2) << answer << "\n";
    }

    //close files
    fout.close();
    debug.close();

    //end program
    return 0;
}

double lineLength(pair<double,double> a, pair<double,double> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}