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

using namespace std;

struct SlopedLine{
    pair<double,double> c1;
    pair<double,double> c2;
    double slope;
    double yIntercept;
    double length;

    SlopedLine(){
        c1 = {0.0,0.0};
        c2 = {0.0,0.0};
        slope = 0.0;
        yIntercept = 0.0;
        length = 0.0;
    }
    
    SlopedLine(pair<double, double> coord1, pair<double,double> coord2){
        c1 = coord1;
        c2 = coord2;
        slope = (coord2.second-coord1.second)/(coord2.first-coord1.first);  // m = (y2-y1)/(x2-x1)
        yIntercept = coord1.second-(slope*coord1.first);                    // b = y1-(m*x1)
        length = sqrt(((coord2.second-coord1.second)*(coord2.second-coord1.second))+((coord2.first-coord1.first)*(coord2.first-coord1.first)));                                                       // length = rise + run; where a^2 + b^2 = c^2, 
    }
}

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
        map<double, double> pointMap;

        while(points--){
            //create temporary x and y values
            int tempX, tempY;
            //read into the temporary values
            cin >> tempX >> tempY;
            //slap the values into the map of points, auto sorted by X
            pointMap[tempX] = tempY;
        }

        // now we create a vector of sloped lines based on the X sorted map of points
        vector<SlopedLine*> lines;
        for(pair<double, double> it = pointMap.begin(); it != pointMap.end(); it++){
            pair<double, double> trash = it;
            pair<double, double> current = trash;
            trash++;
            pair<double, double> next = trash;

            //create a temporary SlopedLine pointer and put it on the vector of lines
            SlopedLine* temp = new SlopedLine(current, next);
            lines.push_back(temp);
        }
        
        vector<int> eraseables;
        //go through the vector of lines and remove the ones that have a positive slope
        for(int a = 0; a < lines.size(); a++){
            if(lines[a].slope >= 0)
                eraseables.push_back(a);
        }
        for(int b = 0; b < eraseables.size(); b++){
            lines.erase(lines.begin()+eraseables[b]-b);
        }
    }

    //close files
    fout.close();
    debug.close();

    //end program
    return 0;
} 