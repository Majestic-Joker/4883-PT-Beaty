/**
* Joshua Beaty
* 4883
* 09/28/2021
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;


bool debugMode = false;
vector<int> A;
vector<int> B;
vector<int> C;
int currentStep, finalStep;

void printState(){
    //print a
    if(A.size()>0){
        cout << "A=>  ";
        for(int a : A)
            cout << ' ' << a;
        cout << "\n";
    }
    else{
        cout << "A=>";

        cout << "\n";
    }
    //print b
    if(B.size()>0){
        cout << "B=>  "; 
        for(int b : B)
            cout << ' ' << b;
        cout << "\n";
    }
    else{
        cout << "B=>";

        cout << "\n";
    }
    //print c
    if(C.size()>0){
        cout << "C=>  ";
        for(int c : C)
            cout << ' ' << c;
        cout << "\n"; 
    }
    else{
        cout << "C=>";

        cout << "\n";
    }
    //blank line after all the printings
    cout << "\n";

    //increment current step
    currentStep++;
}

void adjustState(char from, char to){
    if(currentStep>=finalStep)
        return;

    int popped = 0;
    
    //remove from whatever vector
    if(from == 'A'){
        popped = A.back();
        A.pop_back();
    }
    else if(from == 'B'){
        popped = B.back();
        B.pop_back();
    }
    else if(from == 'C'){
        popped = C.back();
        C.pop_back();
    }

    //push onto whatever vector
    if(to == 'A')
        A.push_back(popped);
    else if(to == 'B')
        B.push_back(popped);
    else if(to == 'C')
        C.push_back(popped);

    //print the step
    printState();
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    //Hopefully breaks out of the recursion upon printing the final step. 
    if(currentStep >= finalStep)
        return;

    if (n == 1)
    {
        adjustState(from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    adjustState(from_rod, to_rod);
    if(currentStep >= finalStep)
        return;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main(){
    //initialize some stuff
    ofstream fout, debug;
    fout.open("test.out");
    int n = 0; // Number of disks
    int problem = 1;
    while(cin >> n){
        if(!n)
            break;

        cout << "Problem #" << problem << "\n\n";

        //fill vector A
        for(int i = n; 0 < i; i--)
            A.push_back(i);

        printState();
        
        //initialize steps
        currentStep = 0; 
        finalStep = 0;

        cin >> finalStep;
        towerOfHanoi(n, 'A', 'C', 'B');
        
        if(debugMode){
            debug << "Number of Disks: " << n << '\n';
            debug << "Number of Steps: " << finalStep << '\n';
        }

        //clear the vectors
        A.clear();
        B.clear();
        C.clear();

        //increment header
        problem++;
    }
    fout.close();
    return 0;
} 