/**
* Joshua Beaty
* 4883
* 08/26/2021
*/

#include <iostream>

using namespace std;

int main() {
    //create int 'n' to hold size of line
    int n;
    //create array of ints 'jumpers'
    int jumpers[3001];
    //create array of ints 'absolutes'
    int absolutes[3001];
    //initialize all memory to 0
    for(int i = 0; i< 3001; i++){
        jumpers[i] = 0;
        absolutes[i] = 0;
    }
    //keep looping as long as there is incoming input
    while(cin >> n){
        if(n > 1){
            //if dirty memory, set back to 0
            if(jumpers[0] != 0)
                for(int b = 0; b<n; b++){
                    jumpers[b] = 0;
                    absolutes[b] = 0;
                }
            // create int 'k' to hold count of absolute values
            int k = 0;
            //loop through 0 to n read data into jumpers
            for(int i = 0; i<n; i++){
                cin >> jumpers[i];
            }
            //loop through 0 to n-1 to get abs of jumpers values
            for(int j = 0; j<n-1; j++)
            absolutes[(abs(jumpers[j]-jumpers[j+1])-1)]++;

            //check the absolutes, if any of the values are anything other than 1, break
            for(int l = 0; l<n-1; l++){
                if(absolutes[l]!=1)
                    break;

                k++; 
            }

            //if k is equal to n-1, then there was 1 of every absolute value 1 through n-1
            if(k == n-1)
                cout << "Jolly\n";  
            else
                cout << "Not jolly\n";
        }
        else{
            //if n was originally 1, it's automatically jolly
            cin >> n;
            cout << "Jolly\n";
        }
    }
}