#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

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

    //function prints out the line for team stats
    //Team Name #p, #g (#-#-#), #gd (#-#)
    //need to add the '0' to convert the integers to character numbers
    string PrintStats(){
        string rtn = "";
        rtn += name;
        rtn += " ";
        rtn += to_string(info["points"]);
        rtn += "p, ";
        rtn += to_string(info["games"]);
        rtn += "g (";
        rtn += to_string(info["wins"]);
        rtn += "-"; 
        rtn += to_string(info["ties"]);
        rtn += "-";
        rtn += to_string(info["losses"]);
        rtn += "), ";
        rtn += to_string(info["goalsDiff"]);
        rtn += "gd (";
        rtn += to_string(info["goalsMade"]);
        rtn += "-";
        rtn += to_string(info["goalsGiven"]);
        rtn += ")";
        return rtn;
    }
};

ofstream fout, debug;
bool debugMode = false;

void outputLine(string output, bool newLine = false);
vector<string> splitToStrings(string, char);
vector<int> splitToInts(string, char);
bool CompareTeams(Team* leftTeam, Team* rightTeam);

int main(){
    //open files
    fout.open("test.out");
    debug.open("debug.out");

    //read in cases
    int cases;
    cin >> cases;
    if(debugMode){
        outputLine("Cases: ");
        outputLine(to_string(cases), true);
    }
    cin.ignore();

    while(cases--){
        //read in tournament name
        string tournamentName;
        //cin.ignore();
        getline(cin, tournamentName);

        if(debugMode){
            outputLine("Tournament: ");
            outputLine(tournamentName, true);
        }

        //create a map of teams
        map<string, Team*> tournament;
        
        //get number of teams
        int t;
        cin >> t;
        cin.ignore();
        if(debugMode){
            outputLine("Number of Teams: " );
            outputLine(to_string(t), true);
        }
        
        //loop through and intialize each team
        if(debugMode){
            outputLine("==Reading Team Names==", true);
        }
        while(t--){
            string team;
            getline(cin, team);

            Team* temp = new Team(team);
            tournament[team] = temp;
            
            if(debugMode){
                outputLine("Team Name: ");
                outputLine(tournament[team]->name, true);
            }
        }

        if(debugMode){
            outputLine("==Testing Tournament Map==", true);
            for(pair<string, Team*> teamTest : tournament){
                outputLine(teamTest.second->PrintStats(), true);
            }
        }

        //get number of games
        int g;
        cin >> g;
        cin.ignore();
        if(debugMode){
            outputLine("Number of Games: ");
            outputLine(to_string(g), true);
            outputLine("==Reading Game Data==",true);
        }

        //loop through games and extract data
        while(g--){
            vector<string> gameInfo;
            string info = "";

            getline(cin, info);
            gameInfo = splitToStrings(info, '#');
            
            if(debugMode)
                for(string s : gameInfo){
                    outputLine("gameInfo: ");
                    outputLine(s, true);
                }

            //extract each side's score
            vector<int> gameScores;
            gameScores = splitToInts(gameInfo[1], '@');

            if(debugMode)
                for(int score : gameScores){
                    outputLine("gameScores: ");
                    outputLine(to_string(score), true);
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

        /*
        sort the teams based on the following criteria
        1 Most points earned
        2 Most wins
        3 Most goal difference (i.e. goals scored - goals against)
        4 Most goals scored
        5 Less games played
        6 Lexicographic order
        */
        vector<Team*> teams;
        for(pair<string, Team*> tm : tournament){
            teams.push_back(tm.second);
        }
        sort(teams.begin(), teams.end(), CompareTeams);

        //print out results
        outputLine(tournamentName,true);
        int num = 1;
        for(Team* team : teams){
            outputLine(to_string(num));
            outputLine(") ");
            outputLine(team->PrintStats(), true);
            num++;
        }

        if(cases>0)
            outputLine("",true);
    }


    fout.close();
    debug.close();
}

//Sends output to both the console and the file and prints a new line after each if newLine is true
void outputLine(string output, bool newLine)
{
    if (debugMode){
        debug << output;
    }
    cout << output;
    fout << output;

    if (newLine)
    {
        cout << '\n';
        fout << '\n';
        if (debugMode)
            debug << '\n';
    }
}

//Function splits a string based on a delimiting character
//returns a vector of strings
vector<string> splitToStrings(string str, char del){
    vector<string> rtn;
    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            rtn.push_back(temp);
            temp = "";
        }
    }
    rtn.push_back(temp);
    return rtn;
}

//Function splits a string based on a delimiting character
//returns a vector of ints
vector<int> splitToInts(string str, char del){
    vector<int> rtn;
    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != del){
            temp += str[i];
        }
        else{
            rtn.push_back(stoi(temp));
            temp = "";
        }
    }
    rtn.push_back(stoi(temp));
    return rtn;
}

/*
    Function compares team pointers to be used with the sort method.
    1 Most points earned
    2 Most wins
    3 Most goal difference (i.e. goals scored - goals against)
    4 Most goals scored
    5 Less games played
    6 Lexicographic order
*/
bool CompareTeams(Team* leftTeam, Team* rightTeam)
{
    int i;
    if(leftTeam->info["points"] > rightTeam->info["points"] ) return true;
    if(leftTeam->info["points"]  < rightTeam->info["points"] ) return false;
    if(leftTeam->info["wins"] > rightTeam->info["wins"]) return true;
    if(leftTeam->info["wins"] < rightTeam->info["wins"]) return false;
    if(leftTeam->info["goalsDiff"] > rightTeam->info["goalsDiff"]) return true;
    if(leftTeam->info["goalsDiff"] < rightTeam->info["goalsDiff"]) return false;
    if(leftTeam->info["goalsMade"] > rightTeam->info["goalsMade"]) return true;
    if(leftTeam->info["goalsMade"] < rightTeam->info["goalsMade"]) return false;
    if(leftTeam->info["games"] < rightTeam->info["games"]) return true;
    if(leftTeam->info["games"] > rightTeam->info["games"]) return false;

    for(i = 0; i < 35; i++)
    {
        char c1 = leftTeam->name[i];
        char c2 = rightTeam->name[i];

        if(c1 >= 'A' && c1 <= 'Z')
                c1 = c1 + 32;
        if(c2 >= 'A' && c2 <= 'Z')
            c2 = c2 + 32;

        if(c1 < c2) return true;
        if(c1 > c2) return false;
    }
    return false;
}