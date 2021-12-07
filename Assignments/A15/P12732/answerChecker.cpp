#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int answerChecker()
{
    ifstream data;
    data.open("OnlyAnswers");

    vector<int> algorithmGuesses;
    vector<int> heavyCoins;

    //while there's data to be read
    //put left side on algorithmGuesses
    //put right side on heavyCoins
    while (!data.eof())
    {
        int a, b;
        data >> a >> b;
        algorithmGuesses.push_back(a);
        heavyCoins.push_back(b);
    }

    cout << "Number of guesses: " << algorithmGuesses.size() << '\n';
    cout << "Number of heavyCoins: " << heavyCoins.size() << '\n';

    vector<int> indexes;

    //keep track of every index where the guess failed
    for (int c = 0; c < algorithmGuesses.size(); c++)
    {
        if (algorithmGuesses[c] != heavyCoins[c])
            indexes.push_back(c);
    }

    //found indexes, dump them to file.
    if (!indexes.empty())
    {
        ofstream dump;
        dump.open("indexDump.out");
        for (int d : indexes)
            dump << d << '\n';

        cout << indexes.size() << " failures found.\n\n";
    }
    else
        cout << "No failures found.\n\n";

    data.close();
}