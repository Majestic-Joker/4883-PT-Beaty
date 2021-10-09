#include <iostream>
#include <fstream>

using namespace std;

int fakeGen()
{
    srand(time(NULL));
    ofstream fout;
    fout.open("random.in");

    //pick number 1-100
    int count = (rand() % 100) + 1;
    cout << count << '\n';
    fout << count << '\n';
    while (count--)
    {   
        //for every 1-100 number, pick a coin 3-120
        int coins = (rand() % 117) + 3;
        //pick a heavy coin 1 - number of coins
        int heavyCoin = (rand() % coins) + 1;
        cout << coins << ' ' << heavyCoin << '\n';
        fout << coins << ' ' << heavyCoin << '\n';
    }
    fout.close();
    return 0;
}