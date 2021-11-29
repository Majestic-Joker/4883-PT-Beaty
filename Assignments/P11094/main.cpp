#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct Team{
    string name;
    //points, games, wins, ties, losses, goalsMade, goalsGiven, goalsDiff
    map<string,int> info;
    Team(){
        name = "default";
    }
    Team(string n){
        name = n;
        info["points"] = 0;
        info["games"] = 0;
        info["wins"] = 0;
        info["ties"] = 0;
        info["losses"] = 0;
        info["goalsMade"] = 0;
        info["goalsGiven"] = 0;
        info["goalsDiff"] = 0;
    }
    
    //function updates the info map, winCode 0=loss, 1 = tie, 2 = win.
    void AddGame(int goalM, int goalG, int winCode){
        info["goalsMade"] += goalM;
        info["goalsGiven"] += goalG;
        info["goalsDiff"] = info["goalsMade"]-info["goalsGiven"];
        info["games"]++;

        switch(winCode){
            case 0:
                info["losses"]++;
            break;
            case 1:
                info["ties"]++;
                info["points"]++;
            break;
            case 2:
                info["wins"]++;
                info["points"] += 3;
            break;
        }
    }
};

ofstream fout, debug;
bool debugMode = true;

void outputLine(string, bool);

int main(){
    //open files
    fout.open("test.out");
    debug.open("debug.out");

    //read in cases
    int cases;
    cin >> cases;
    if(debugMode)
        debug << "Cases: " << cases << '\n';
    while(cases--){
        //read in tournament name
        string tournamentName;
        cin.ignore();
        getline(cin, tournamentName);

        if(debugMode)
            debug << "Tournament: " << tournamentName << '\n';

        //create a map of teams
        map<string, Team*> tournament;
        
        //get number of teams
        int t;
        cin >> t;
        cin.ignore();
        if(debugMode)
            debug << "Number of Teams: " << t << '\n';
        
        //loop through and intialize each team
        while(t--){
            string team;
            getline(cin, team);
            Team* temp = new Team(team);
            tournament[team] = temp;
            
            if(debugMode)
                debug << "Team Name: " << tournament[team]->name << '\n';
        }

        //get number of games
        int g;
        cin >> g;
        cin.ignore();

        //loop through games and extract data
        while(g--){
            vector<string> gameInfo;
            string info;
            while(getline(cin, info, '#')){
                gameInfo.push_back(info);
            }

            vector<int> gameScores;
            string score;
            for(char c : gameInfo[1]){
                if(c != '@');
                    gameScores.push_back(c-48);
            }

            //if left side wins
            if(gameScores[0] > gameScores[1]){
                tournament[gameInfo[0]]->AddGame(gameScores[0], gameScores[1], 2);
                tournament[gameInfo[2]]->AddGame(gameScores[1], gameScores[0], 0);
            }
            //if right side wins
            else if(gameScores[0] < gameScores[1]){
                tournament[gameInfo[0]]->AddGame(gameScores[0], gameScores[1], 0);
                tournament[gameInfo[2]]->AddGame(gameScores[1], gameScores[0], 2);
            }
            //tie
            else if(gameScores[0] == gameScores[1]){
                tournament[gameInfo[0]]->AddGame(gameScores[0], gameScores[1], 1);
                tournament[gameInfo[2]]->AddGame(gameScores[1], gameScores[0], 1);
            }
        }

        //sort the teams based on criteria

        //print out results

    }


    fout.close();
    debug.close();
}

//Sends output to both the console and the file and prints a new line after each
void outputLine(string output, bool newLine = false)
{
    cout << output;
    fout << output;
    if (debugMode)
        debug << output;

    if (newLine)
    {
        cout << '\n';
        fout << '\n';
        if (debugMode)
            debug << '\n';
    }
}