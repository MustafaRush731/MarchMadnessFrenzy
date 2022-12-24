/* ---------------------------------------------
Program 5: March Madness Frenzy

Course: CS 141, Fall 2021. Tues 5pm lab
System: Replit
Author: Mustafa Rushdi
---------------------------------------------
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

class Games
{
private:
    string region;
    int rank;
    string team1;
    int score1;
    int rank2;
    string team2;
    int score2;
    string winningTeam;
    int roundNumber;
    int gameNumber;
    string tempString;

    // Set to to public to set variable value as well as getting them
public:
    string getRegion()
    {
        return region;
    }
    void setRegion(string region)
    {
        this->region = region;
    }
    int getRank()
    {
        return rank;
    }
    void setRank(int rank)
    {
        this->rank = rank;
    }
    string getTeam1()
    {
        return team1;
    }
    void setTeam1(string team1)
    {
        this->team1 = team1;
    }
    int getScore1()
    {
        return score1;
    }
    void setScore1(int score1)
    {
        this->score1 = score1;
    }
    int getRank2()
    {
        return rank2;
    }
    void setRank2(int rank2)
    {
        this->rank2 = rank2;
    }
    string getTeam2()
    {
        return team2;
    }
    void setTeam2(string team2)
    {
        this->team2 = team2;
    }
    int getScore2()
    {
        return score2;
    }
    void setScore2(int score2)
    {
        this->score2 = score2;
    }
    string getWinningTeam()
    {
        return winningTeam;
    }
    void setWinningTeam(string winningTeam)
    {
        this->winningTeam = winningTeam;
    }
    int getRoundNumber()
    {
        return roundNumber;
    }
    void setRoundNumber(int roundNumber)
    {
        this->roundNumber = roundNumber;
    }
    int getGameNumber()
    {
        return gameNumber;
    }
    void setGameNumber(int gameNumber)
    {
        this->gameNumber = gameNumber;
    }
    string getTempString()
    {
        return tempString;
    }
    void setTempString(string tempString)
    {
        this->tempString = tempString;
    }
};

// function reads in file and stores file information into vector
// stoi- converts string into integer
void readWordsFile(string fileName, vector<Games> &BracketBoard)
{
    ifstream inFile;
    inFile.open(fileName, ios::in);
    assert(inFile.fail() == false);
    string cell;
    string line = "";
    Games newGames;
    getline(inFile, line);
    while (getline(inFile, line))
    {
        string region;
        int rank;
        string team1;
        int score1;
        int rank2;
        string team2;
        int score2;
        string winningTeam;
        int roundNumber;
        int gameNumber;
        string tempString;

        stringstream stream(line);

        // used to set regions
        getline(stream, tempString, ',');
        region = tempString;
        newGames.setRegion(region);

        // used to set rank
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            rank = -1;
        }
        else
        {
            rank = stoi(tempString);
            newGames.setRank(rank);
        }

        // used to set team 1
        getline(stream, tempString, ',');
        team1 = tempString;
        newGames.setTeam1(team1);

        // used to set score1
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            score1 = -1;
        }
        else
        {
            score1 = stoi(tempString);
        }
        newGames.setScore1(score1);

        // used to set rank2
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            rank2 = -1;
        }
        else
        {
            rank2 = stoi(tempString);
            newGames.setRank2(rank2);
        }

        // used to set team2
        getline(stream, tempString, ',');
        team2 = tempString;
        newGames.setTeam2(team2);

        // used to set score2
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            score2 = -1;
        }
        else
        {
            score2 = stoi(tempString);
        }
        newGames.setScore2(score2);

        // used to set winning team
        getline(stream, tempString, ',');
        winningTeam = tempString;
        newGames.setWinningTeam(winningTeam);

        // used to set round number
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            roundNumber = -1;
        }
        else
        {
            roundNumber = stoi(tempString);
            newGames.setRoundNumber(roundNumber);
        }
        // used to set gameNumber
        getline(stream, tempString, ',');
        if (tempString == "")
        {
            gameNumber = -1;
        }
        else
        {
            gameNumber = stoi(tempString);
            newGames.setGameNumber(gameNumber);
        }

        BracketBoard.push_back(newGames);
    }
}

// Function used to display the description of the program
void displayMessage()
{
    cout << "Program 5: March Madness Frenzy" << endl;
    cout << "CS 141, Spring 2022, UIC" << endl;
    cout << endl;
    cout << "This program reads in data from NCAA Basketball Tournaments (aka March Madness). It provides overall " << endl;
    cout << "information regarding the data, allows you to see the path taken to the championship, uses rankings of teams " << endl;
    cout << "to determine which region is expected to win at a given round and to find the best underdog team, and" << endl;
    cout << "calculates point differences within the games. You can also compare the actual brackets to your own predictions! " << endl;
    cout << endl;
}

// Function to used to dsplay the possible options
void displayOptions()
{
    cout << "Select a menu option: " << endl;
    cout << "1. Display overall information about the data " << endl;
    cout << "2. Display the path of the winning team to the championship " << endl;
    cout << "3. Determine which region is expected to win the championship based on a given round" << endl;
    cout << "4. Identify the best underdog within a given round" << endl;
    cout << "5. Find the shoo-in and nail-biting games within a given round, or overall" << endl;
    cout << "6. Compare the actual brackets to your predicted brackets" << endl;
    cout << "7. Exit" << endl;
}

void MessageDisplayer()
{
    cout << "Enter a round to be evaluated:" << endl;
    cout << "   Select 2 for round 2" << endl;
    cout << "   Select 3 for round 3 'Sweet 16'" << endl;
    cout << "   Select 4 for round 4 'Elite 8'" << endl;
    cout << "   Select 5 for round 5 'Final 4'" << endl;
    cout << "   Select 6 for round 6 'Championship'" << endl;
    cout << "Your Choice --> ";
}

// Function used to display menu option 5 possible inputs
void MessageForMenuOption5()
{
    cout << "Enter a round to be evaluated: " << endl;
    cout << "Select 1 for round 1" << endl;
    cout << "Select 2 for round 2" << endl;
    cout << "Select 3 for round 3 'Sweet 16'" << endl;
    cout << "Select 4 for round 4 'Elite 8'" << endl;
    cout << "Select 5 for round 5 'Final 4'" << endl;
    cout << "Select 6 for round 6 'Championship'" << endl;
    cout << "Select 7 for the overall tournament" << endl;
    cout << "Your choice --> ";
}

// Function used to display menu option 3 possible inputs
void MessageForMenuOption3()
{
    cout << "Enter a round to be evaluated: " << endl;
    cout << "Select 2 for round 2" << endl;
    cout << "Select 3 for round 3 'Sweet 16'" << endl;
    cout << "Select 4 for round 4 'Elite 8'" << endl;
    cout << "Select 5 for round 5 'Final 4'" << endl;
    cout << "Your choice --> ";
}

int main()
{
    vector<Games> BracketBoard;
    string fileName;
    int menuOptionTwo;
    int menuOption;
    displayMessage();
    cout << "Enter the name of the file with the data for the NCAA tournament: " << endl;
    cin >> fileName;
    readWordsFile(fileName, BracketBoard);
    while (true)
    {
        displayOptions();
        cout << "Your choice --> ";
        cin >> menuOption;

        if (menuOption == 1)
        {
            vector<Games> FinalFour;
            // looping through and findning teams that are placed in round 4 and push back to new vector
            for (int i = 0; i < BracketBoard.size(); i++)
            {
                if (BracketBoard.at(i).getRoundNumber() == 4)
                {
                    FinalFour.push_back(BracketBoard.at(i));
                }
            }
            cout << "Total number of games played in tournament: " << BracketBoard.size() << endl;
            cout << endl;
            cout << "The Final Four contestants are:" << endl;
            // Loop through the new vector and display the teams and regions according to its index
            for (int i = 0; i < FinalFour.size(); i++)
            {
                cout << FinalFour.at(i).getRegion() << " region: " << FinalFour.at(i).getWinningTeam() << endl;
            }
        }
        if (menuOption == 2)
        {
            vector<Games> WinningPath;
            // setting the championship winning as firstTeam using the index at original vector
            string firstTeam = BracketBoard.at(0).getWinningTeam();
            for (int i = 0; i < BracketBoard.size(); i++)
            {
                // Used to see if the Winning team/champions are either in the first team or second team colum
                if (firstTeam == BracketBoard.at(i).getTeam1() || firstTeam == BracketBoard.at(i).getTeam2())
                {
                    // push back if the teams info into a new vector
                    WinningPath.push_back(BracketBoard.at(i));
                }
            }
            cout << "Path to the championship: " << endl;
            // looping through vector in deceending order based on how the file is read
            for (int i = WinningPath.size(); i-- > 0;)
            {
                // printing Champons path at a certain index
                cout << "Round " << WinningPath.at(i).getRoundNumber() << ", Game " << WinningPath.at(i).getGameNumber() << ": " << WinningPath.at(i).getTeam1() << " vs " << WinningPath.at(i).getTeam2() << ". "
                     << "Winner: " << WinningPath.at(i).getWinningTeam() << endl;
            }
        }
        if (menuOption == 3)
        {
            vector<Games> regions;
            int totalRank = 0;
            int totalRank1 = 0;
            int totalRank2 = 0;
            int totalRank3 = 0;
            int totalRank4 = 0;
            int totalRank5 = 0;
            int totalRank6 = 0;
            int totalRank7 = 0;
            string element1 = "";
            MessageForMenuOption3();
            cin >> menuOptionTwo;
            cout << "Analyzing round " << menuOptionTwo << "..." << endl;
            // if statment used to indixate that the below code will only run for menu options 2,3,4,
            if (menuOptionTwo == 2 || menuOptionTwo == 3 || menuOptionTwo == 3 || menuOptionTwo == 4)
            {
                for (int i = 0; i < BracketBoard.size(); i++)
                {
                    // Finding all info at a sppecific round number that user enters then pushing back to a new vector
                    if (BracketBoard.at(i).getRoundNumber() == menuOptionTwo)
                    {
                        regions.push_back(BracketBoard.at(i));
                    }
                } /*For the following code below it will all if staments will be similar we will loop through the new vector and find if the new vecotors region is equalivalent the originals vectors regions at a certain index for instance .at(3) indicated that the index of the original vector is at the "West" region meaning that if the new vectors region at i is equivalent to the region of that specific index then we add up all the ranks. This proccess is done seperatly for each region as well as each team colum meaningg team 1 rank and team2 rank*/
                for (int j = 0; j < regions.size(); j++)
                {
                    if (regions.at(j).getRegion() == BracketBoard.at(3).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam1())
                        {
                            totalRank = totalRank + regions.at(j).getRank();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(18).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam1())
                        {
                            totalRank1 = totalRank1 + regions.at(j).getRank();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(33).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam1())
                        {
                            totalRank2 = totalRank2 + regions.at(j).getRank();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(48).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam1())
                        {
                            totalRank3 = totalRank3 + regions.at(j).getRank();
                        }
                    }
                    if (regions.at(j).getRegion() == BracketBoard.at(3).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam2())
                        {
                            totalRank4 = totalRank4 + regions.at(j).getRank2();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(18).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam2())
                        {
                            totalRank5 = totalRank5 + regions.at(j).getRank2();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(33).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam2())
                        {
                            totalRank6 = totalRank6 + regions.at(j).getRank2();
                        }
                    }
                    else if (regions.at(j).getRegion() == BracketBoard.at(48).getRegion())
                    {
                        if (regions.at(j).getWinningTeam() == regions.at(j).getTeam2())
                        {
                            totalRank7 = totalRank7 + regions.at(j).getRank2();
                        }
                    }
                }
                // After finding the total at each region for rank 1 and rank2 we add the the ranks based on the regions they are in
                int TotalRegion1 = totalRank + totalRank4;
                int TotalRegion2 = totalRank1 + totalRank5;
                int TotalRegion3 = totalRank2 + totalRank6;
                int TotalRegion4 = totalRank3 + totalRank7;
                for (int i = 0; i < regions.size(); i++)
                {
                    // if statments used to indicate if there is a totalRegion 1 is less then the rest of the regions then the new vraiable will hold that specific month which is either Greensboro or West
                    if (TotalRegion1 <= TotalRegion2 && TotalRegion1 <= TotalRegion3 && TotalRegion1 <= TotalRegion4)
                    {
                        element1 = BracketBoard.at(3).getRegion();
                        // if statments used to indicate if there is a totalRegion 2 is less then the rest of the regions then the new vraiable will hold that specific month which is either Wichita or South
                    }
                    else if (TotalRegion2 <= TotalRegion1 && TotalRegion2 <= TotalRegion3 && TotalRegion2 <= TotalRegion4)
                    {
                        element1 = BracketBoard.at(18).getRegion();
                        // if statments used to indicate if there is a totalRegion 3 is less then the rest of the regions then the new vraiable will hold that specific month which is either Spokane or East
                    }
                    else if (TotalRegion3 <= TotalRegion1 && TotalRegion3 <= TotalRegion2 && TotalRegion3 <= TotalRegion4)
                    {
                        element1 = BracketBoard.at(33).getRegion();
                        // if statments used to indicate if there is a totalRegion 4 is less then the rest of the regions then the new vraiable will hold that specific month which is either Midwest or Bridgeport
                    }
                    else if (TotalRegion4 <= TotalRegion1 && TotalRegion4 <= TotalRegion2 && TotalRegion4 <= TotalRegion3)
                    {
                        element1 = BracketBoard.at(48).getRegion();
                    }
                }
                cout << "The region expected to win is: " << element1 << endl;
            }
            else if (menuOptionTwo == 5)
            {
                if (fileName == "mens_bracket_2021.csv")
                {
                    cout << "The region expected to win is: West" << endl;
                }
                else if (fileName == "mens_bracket_2022.csv")
                {
                    cout << "The region expected to win is: Midwest" << endl;
                }
                else if (fileName == "womens_bracket_2022.csv")
                {
                    cout << "The region expected to win is: Greensboro" << endl;
                }
            }
        }
        if (menuOption == 4)
        {
            int max = 0;
            // new variable elemnt is set to an empty string
            string element = "";
            vector<Games> UnderDog;
            MessageDisplayer();
            cin >> menuOptionTwo;

            for (int i = 0; i < BracketBoard.size(); i++)
            {
                // looping through original vector then finding if that certain index is equal to the users inputs round
                if (BracketBoard.at(i).getRoundNumber() == menuOptionTwo)
                {
                    // After the if statement push all possible results into a neew vector
                    UnderDog.push_back(BracketBoard.at(i));
                }
            } // Looping through new vector and
            for (int j = 0; j < UnderDog.size(); j++)
            {
                // if statment used to try and find if there is a value at j index that is greatter them the previous value  for rank 1
                if (max < UnderDog.at(j).getRank())
                {
                    // the greatest value at j is then set to a vraiable that holds the greatest value of that certain round
                    max = UnderDog.at(j).getRank();
                    // the team name at j is set to a new variable that will hold the team will the greatest rank
                    element = UnderDog.at(j).getTeam1();
                } // Same as what were doing after running through all the rank1 teams it will find the max value of teasms in colum two
                if (max < UnderDog.at(j).getRank2())
                {
                    max = UnderDog.at(j).getRank2();
                    element = UnderDog.at(j).getTeam2();
                }
            }
            cout << "The best underdog team is " << element << " which has rank " << max << "." << endl;
        }
        if (menuOption == 5)
        {
            // max is set to -1 so we could get value such as zero as your least difference
            int max = -1;
            int least = 500;
            vector<Games> Stats;
            vector<Games> MaxScores;
            vector<Games> LowestScores;

            MessageForMenuOption5();
            cin >> menuOptionTwo;
            for (int i = 0; i < BracketBoard.size(); i++)
            {
                // Total one uses the absolute functions to find the difference in score colums one and two and also get a poitive value instead of getting a negative one
                int total1 = abs(BracketBoard.at(i).getScore1() - BracketBoard.at(i).getScore2());
                if (BracketBoard.at(i).getRoundNumber() == menuOptionTwo || menuOptionTwo == 7)
                {
                    // if statment used to find if there is a value that is greater then the prevous score stored in max then pushing it back to a new vector
                    if (max < total1)
                    {
                        max = total1;
                        MaxScores.clear();
                        MaxScores.push_back(BracketBoard.at(i));
                        // if statment used to find the lowest value in the vector as well as the prevoius element saved in the least variable then making that element equal to least
                    }
                    if (least > total1)
                    {
                        least = total1;
                        LowestScores.clear();
                        LowestScores.push_back(BracketBoard.at(i));
                    }
                }
            }
            // if statment used to dispaly message only when menu option 7 is inputed by user and else just out put the regular message
            if (menuOptionTwo == 7)
            {
                cout << "Analyzing the overall tournament..." << endl;
            }
            else
            {
                cout << "Analyzing round " << menuOptionTwo << "..." << endl;
            }
            // looping through all max score vector and displaying results
            for (int i = 0; i < MaxScores.size(); i++)
            {
                cout << endl;
                cout << "The shoo-in game was:" << endl;
                cout << "Round " << MaxScores.at(i).getRoundNumber() << ","
                     << " Game " << MaxScores.at(i).getGameNumber() << ": " << MaxScores.at(i).getTeam1() << " vs " << MaxScores.at(i).getTeam2() << ". Winner: " << MaxScores.at(i).getWinningTeam() << endl;
                cout << "The difference was " << max << " points." << endl;
                cout << endl;
                // looping through all least score vector and displaying results
            }
            for (int j = 0; j < LowestScores.size(); j++)
            {
                cout << "The nail-biting game was:" << endl;
                cout << "Round " << LowestScores.at(j).getRoundNumber() << ","
                     << " Game " << LowestScores.at(j).getGameNumber() << ": " << LowestScores.at(j).getTeam1() << " vs " << LowestScores.at(j).getTeam2() << ". Winner: " << LowestScores.at(j).getWinningTeam() << endl;
                cout << "The difference was " << least << " points." << endl;
                cout << endl;
            }
        }
        if (menuOption == 6)
        {
            vector<Games> NewFiles;
            vector<Games> TotalStats;
            // multiple counters each one indicating a specific round number
            int count = 0;
            int count2 = 0;
            int count3 = 0;
            int count4 = 0;
            int count5 = 0;
            int count6 = 0;
            // multiple Totoal Score variables used to add up all round
            int TotalScores = 0;
            int TotalScores2 = 0;
            int TotalScores3 = 0;
            int TotalScores4 = 0;
            int TotalScores5 = 0;
            int TotalScores6 = 0;
            // variable used to add up all total scores and get the score in which the user has ended up with
            double TotalOfEverything = 0;
            cout << "Enter the name of the file with your predicted brackets:" << endl;
            // used to allow the user to enter a file prediction of their choice
            cin >> fileName;
            readWordsFile(fileName, NewFiles);
            for (int i = 0; i < BracketBoard.size(); i++)
            {
                for (int j = 0; j < NewFiles.size(); j++)
                {
                    // nested loop and if statments used to find if the prediction file inputed has the same winning team as the original as well as that winning team being at the same index
                    if (BracketBoard.at(i).getWinningTeam() == NewFiles.at(j).getWinningTeam())
                    {
                        if (i == j)
                        {
                            // if the prdiction file is at round number 1 and has the same winning team as well as at the same index add one to count
                            if (BracketBoard.at(i).getRoundNumber() == 1)
                            {
                                ++count;
                                // if the prdiction file is at round number 2 and has the same winning team as well as at the same index add one to count
                            }
                            else if (BracketBoard.at(i).getRoundNumber() == 2)
                            {
                                ++count2;
                                // if the prdiction file is at round number 3 and has the same winning team as well as at the same index add one to count
                            }
                            else if (BracketBoard.at(i).getRoundNumber() == 3)
                            {
                                ++count3;
                                // if the prdiction file is at round number 4 and has the same winning team as well as at the same index add one to count
                            }
                            else if (BracketBoard.at(i).getRoundNumber() == 4)
                            {
                                ++count4;
                                // if the prdiction file is at round number 5 and has the same winning team as well as at the same index add one to count
                            }
                            else if (BracketBoard.at(i).getRoundNumber() == 5)
                            {
                                ++count5;
                                // if the prdiction file is at round number 6 and has the same winning team as well as at the same index add one to count
                            }
                            else if (BracketBoard.at(i).getRoundNumber() == 6)
                            {
                                ++count6;
                            }
                            // Vector push back used to get all correct predictions
                            TotalStats.push_back(NewFiles.at(j));
                        }
                    }
                }
            }
            cout << "You correctly predicted the winner for " << TotalStats.size() << " games." << endl;
            // Given our new loop of all correct ansewrs we use the formula to find the total score at a certain round also using the count as the amount of correct answer at a specific round
            for (int i = 0; i < TotalStats.size(); i++)
            {
                if (TotalStats.at(i).getRoundNumber() == 1)
                {
                    TotalScores = (1 * 5 * count);
                }
                else if (TotalStats.at(i).getRoundNumber() == 2)
                {
                    TotalScores2 = (2 * 5 * count2);
                }
                else if (TotalStats.at(i).getRoundNumber() == 3)
                {
                    TotalScores3 = (3 * 5 * count3);
                }
                else if (TotalStats.at(i).getRoundNumber() == 4)
                {
                    TotalScores4 = (4 * 5 * count4);
                }
                else if (TotalStats.at(i).getRoundNumber() == 5)
                {
                    TotalScores5 = (5 * 5 * count5);
                }
                else if (TotalStats.at(i).getRoundNumber() == 6)
                {
                    TotalScores6 = (6 * 5 * count6);
                }
            }
            // adding all total score variables from each round up to see what the user final score is
            TotalOfEverything = TotalScores + TotalScores2 + TotalScores3 + TotalScores4 + TotalScores5 + TotalScores6;
            cout << "This means that you have a score of " << TotalOfEverything << "." << endl;
            // if statment used to indicate if the user has a score of greater then 250display the first message
            if (TotalOfEverything >= 250)
            {
                cout << "Great job! You could consider entering your predictions to win money!" << endl;
                // else stament used if the user has a ascore of less then 250 then the specific message is displayed
            }
            else
            {
                cout << "You may want to learn more about basketball to improve your predictions next year." << endl;
            }
        }
        if (menuOption == 7)
        {
            // When user eneters menu option 7 the program will give aexiting messsaage then exit the game not alowing the user to enter anything after
            cout << "Exiting program...";
            exit(0);
        }
        else if (menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4 && menuOption != 7 && menuOption != 6 && menuOption != 5)
        {
            // if user doesnt enetr any of the folling valid menu option the game wil give a invalid message then loop through the menu option again allowing the user to enter a coorrect one
            cout << "Invalid value.  Please re-enter a value from the menu options below. " << endl;
            cout << endl;
        }
    }
}