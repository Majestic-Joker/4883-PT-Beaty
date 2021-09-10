/**
* Joshua Beaty
* 4883
* 08/31/2021
*/
#include <iostream>

using namespace std;

int main() {
    //read first number from the input put in integer n
    int n = 0;
    cin >> n;
    //create bool to run the while loop
    bool done = false;
    //create while loop to keep checking input until two 0s are read
    while(!done){
        if(n > 0){
            //create array, 'outgoing' and 'incoming of size n;
            int* outgoing = new int[n];
            int* incoming = new int[n];
            //create array, 'station' of size n+1;
            int* station = new int[n+1];
            for(int i = 0; i < n; i++){
                //put n number of ints from input into array 'outgoing' of size n

                //create array 'incoming' of size n and fill with ascending number sequence 1-n
            }
            
            //create array 'station' of size n+1
            //create int 'stationTop'
            //loop through 'outgoing' checking each node against 'stationTop' and 'incoming'
            //loop through 'incoming' if 'outgoing' node doesn't equal 'incoming' node, put 
            //it on top of 'station', update 'stationTop'.
            //if sequence works, output yes and new line
            //if sequence fails, output no and new line
        }
        else{
            //get next n
            cin >> n;
            //if n is greater than 0, print blank line, otherwise end the while loop
            if(n > 0){
                cout << '\n';
            }
            else{
                done = true;
            }
        }
    }
}