/**
* Joshua Beaty
* 4883
* 08/26/2021
*/
#include <iostream>

using namespace std;

int main() {
    long long int B = 0, A = 0;         //long long ints used to accomodate the possible 2^32 int size

    while (cin >> A >> B) {
        if(A>B)
            cout << A - B << '\n';
        else
            cout << B - A << '\n';
    }
    return 0;
}