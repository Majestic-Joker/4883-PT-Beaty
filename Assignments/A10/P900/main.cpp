/**
* Joshua Beaty
* 4883
* 11/30/2021
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//when set to true, prints debug messages to debug.out file
bool debugMode = false;

int main(){
    //initialize some stuff
    ofstream fout;
    fout.open("test.out");

    vector<long long int> patterns = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074};
    vector<int> input;

    //read data in
    int dump;
    while(cin>>dump)
        input.push_back(dump);

    for(int i = 0; i < input.size()-1; i++){
        cout << patterns[input[i]-1] << '\n'; 
        fout << patterns[input[i]-1] << '\n';
    }
    
    fout.close();
    return 0;
} 