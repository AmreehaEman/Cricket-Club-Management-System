#include <iostream>
#include <string>
#include <windows.h> //this libraray is uesd for SetConsoleOutputCP(CP_UTF8),gotoxy...
#include <iomanip>
#include <limits> // Provides information about primitive data types.numeric_limits<streamsize>::max() (used in handlePause())
#include <cctype> // Character Type. Provides functions to check the type of a character.isdigit() (used in validation functions)
using namespace std;

void displayTitle();
void printMenuHeader(string mainMenu, string subMenu);
void mazeLogin();
int menu1();
bool SignUp(int &userCount, string userN, string userP, string userR, string allNames[], string allPasswords[], string allRoles[]);
string SignIn(int userCount, string userN, string userP, string allNames[], string allPasswords[], string allRoles[]);
void gotoxy(int x, int y);

void adminInterface(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int team1[], int team2[], int team3[], int team4[], string teamNames[], int &teamCount1, int &teamCount2, int &teamCount3, int &teamCount4, int userCount, string userNames[], string userRoles[], string userPasswords[], int matchCounter, string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[]);

void userInterface(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long netSalary[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int teamCount1, int teamCount2, int teamCount3, int teamCount4, int team1[], int team2[], int team3[], int team4[], string teamNames[], int matchCounter, string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[]);

bool registration(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[]);
const int userSize = 50;

void viewData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[]);

string numValidation(string userInput);
int handlePause();
int adminMenu();
int userMenu();
void viewAdmins(int userCount, string userNames[], string userRoles[], string userPasswords[]);

void viewUsers(int userCount, string userNames[], string userRoles[], string userPasswords[]);

void viewPlayerStats(int idx, string playerName[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], float average[], float strikeRate[]);
void printNameIndex(int idx, string playerName[]);

void viewDataWithoutGetch(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long int netSalary[]);

bool deleteData(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int team1[], int team2[], int team3[], int team4[], int &teamCount1, int &teamCount2, int &teamCount3, int &teamCount4);

bool updateData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[]);

void searchData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[]);

long long int calculateSalary(int idx, long long int baseSalary[]);

void teamMake(int idx, string playerName[], string teamNames[], int team1[], int team2[], int team3[], int team4[], int teamCount1, int teamCount2, int teamCount3, int teamCount4);

void viewTeamMembers(int countTeam, string teamName, int team[], string playerName[], long long int id[], string cnic[], long long int baseSalary[]);

bool isAlreadyPlayer(int size, int player, int team[]);

void teamSelection(int &count, int twoCount, int threeCount, int fourCount, int team[], int twoTeam[], int threeTeam[], int fourTeam[], int idx, string playerName[]);

int checkIndexForTeam(string temIndex, int idx);

bool isIdValid(long long temporaryId, long long id[], int idx);

int statsValidation(string str);

bool playerStats(int idx, string playerName[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int runs[], int dismissles[], float average[], float strikeRate[]);

bool organizeMatch(int &matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string matchDate[], string resultOfMatch[]);

bool isValidTeamName(string str, string teamNames[]);

void viewMatchHistory(int matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[]);

int searchTopPlayer(int idx, float average[]);

void playerInAsynding(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[]);

void playerInDesynding(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[]);

int find_mini(int start, int idx, float average[]);

int find_max(int start, int idx, float average[]);

void printDataAOrDRuns(int idx, string playerName[], int runs[], int playerMatch[], float average[], int sixes[], int fours[], float strikeRate[]);

bool updateMatch(int matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[]);

string validationForCnic(string userInputCnic);

void printTeamNames(string teamNames[]);

void deleteIfPlayer(int delPlayer, int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long int netSalary[], float strikeRate[], int runs[], int ballFaced[], float average[], int fifties[], int fours[], int centuries[], int sixes[], int playerMatch[], int dismissles[]);

void fixTeamIndices(int team[], int &count, int delPlayer);

void deleteFromTeam(int &count, int team[], int indexToDelete);
//***************************************/ starts main********************************************

int main()
{
    int option = 0;
    int userCount = 0;
    string userNames[userSize];
    string userPasswords[userSize];
    string userRoles[userSize];
    long long int id[50] = {201, 202, 203, 204, 205,
                            206, 207, 208, 209, 210,
                            211, 212, 213, 214, 215,
                            216, 217, 218, 219, 220,
                            221, 222};
    long long int baseSalary[50] = {4500, 5200, 3900, 6100, 4700,
                                    5000, 4300, 4800, 5500, 4950,
                                    5100, 4400, 5800, 4900, 6300,
                                    4200, 5400, 6000, 4750, 5300,
                                    3425, 3422};

    long long netSalary[50] = {4050, 4680, 3510, 5490, 4230,
                               4500, 3870, 4320, 4950, 4455,
                               4590, 3960, 5220, 4410, 5670,
                               3780, 4860, 5400, 4275, 4770,
                               3082, 3080};

    string playerName[50] = {
        "Nabeel", "Shahzad", "Talha", "Rehan", "Sufyan",
        "Ahmed", "Usman", "Bilal", "Ahsan", "Farhan",
        "Omar", "Yasir", "Taha", "Daniyal", "Waqas",
        "Ali", "Hamza", "Zain", "Kamran", "Hasan",
        "Ahsan", "Quraish"};

    string fatherName[50] = {
        "Yaseen", "Hameed", "Rafiq", "Abid", "Noman",
        "Sami", "Imran", "Javed", "Aslam", "Tariq",
        "Iqbal", "Qasim", "Latif", "Sajjad", "Rashid",
        "Zafar", "Faisal", "Nasir", "Sarwar", "Anwar",
        "Zahid", "Qasim"};

    string cnic[50] = {
        "3520187654321", "3520199998888", "3120176543210", "4210188887777", "3450112345678",
        "4210198765432", "3310112345678", "4220187654321", "3450123456789", "3120165432109", "3740156789012", "4520123456789", "3110198765432", "3520111112222", "4230133334444",
        "3340155556666", "3120177778888", "3510199990000", "4240112121212", "3410134343434", "4123454657456", "2304542678901"};

    int playerMatch[50] = {10, 5, 12, 8, 15,
                           3, 7, 10, 4, 6,
                           18, 6, 14, 9, 20,
                           5, 11, 13, 7, 16,
                           45, 54},
        fifties[50] = {2, 0, 3, 0, 4,
                       0, 1, 1, 0, 0,
                       5, 0, 3, 0, 8,
                       5, 0, 2, 2, 0,
                       45, 23},
        centuries[50] = {0, 1, 0, 0, 2,
                         0, 0, 1, 0, 0,
                         1, 0, 0, 0, 3,
                         0, 0, 1, 0, 0,
                         3, 2},
        ballFaced[50] = {180, 150, 240, 60, 300,
                         50, 120, 190, 10, 95,
                         350, 50, 325, 114, 568,
                         40, 280, 320, 84, 464,
                         500, 344},
        sixes[50] = {5, 8, 10, 2, 15,
                     1, 4, 7, 0, 3,
                     12, 1, 15, 4, 25,
                     0, 8, 10, 3, 11,
                     30, 23},
        fours[50] = {18, 15, 25, 5, 35,
                     4, 12, 20, 1, 8,
                     30, 6, 40, 10, 50,
                     3, 20, 28, 7, 35,
                     43, 21},
        dismissles[50] = {8, 3, 11, 5, 12,
                          2, 6, 9, 1, 4,
                          16, 4, 10, 8, 18,
                          3, 7, 12, 6, 15,
                          345, 678},
        runs[50] = {250, 320, 410, 70, 600,
                    55, 160, 300, 15, 100,
                    750, 45, 520, 120, 1050,
                    30, 350, 480, 80, 650,
                    342, 456};
    float strikeRate[50] = {138.89, 213.33, 170.83, 116.67, 200.00,
                            110.00, 133.33, 157.89, 150.00, 105.26,
                            214.29, 90.00, 160.00, 105.26, 184.86,
                            75.00, 125.00, 150.00, 95.24, 140.00,
                            109.90, 134.00};
    float average[50] = {31.25, 106.67, 37.27, 14.00, 50.00,
                         27.50, 26.67, 33.33, 15.00, 25.00,
                         46.88, 11.25, 52.00, 15.00, 58.33,
                         10.00, 50.00, 40.00, 13.33, 43.33,
                         55.11, 34.00};
    int idx = 22;
    int team1[50] = {1, 2, 3, 4, 5,
                     6, 7, 8, 9, 10,
                     11};
    int team2[50] = {12, 13, 14, 15, 16,
                     17, 18, 19, 20, 21,
                     22};
    int team3[50], team4[50], teamCount1 = 10, teamCount2 = 10, teamCount3 = 0, teamCount4 = 0;

    string teamNames[4] = {"Golden", "Silver"};

    int matchIndex[50], matchCounter = 0;
    string opponentTeam[50], opposingTeam[50], resultOfMatch[50], matchDate[50];

    while (true)
    {

        printMenuHeader("Login Menu", "");
        mazeLogin();
        option = menu1();
        if (option == 1)
        {
            printMenuHeader("Login Menu", "SignIn");
            string userN, userP, userR;
            cout << "Enter UserName: ";
            cin >> userN;
            cout << "Enter UserPassword: ";
            cin >> userP;
            userR = SignIn(userCount, userN, userP, userNames, userPasswords, userRoles);
            if (userR != "undefined")
            {
                if (userR == "Admin" || userR == "admin")
                {
                    displayTitle();
                    printMenuHeader("SignIn", "AdminMenu");
                    adminInterface(idx, playerName, fatherName, id, cnic, baseSalary, netSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average, team1, team2, team3, team4, teamNames, teamCount1, teamCount2, teamCount3, teamCount4, userCount, userNames, userRoles, userPasswords, matchCounter, opponentTeam, opposingTeam, resultOfMatch, matchDate);
                }
                else if (userR == "User" || userR == "user")
                {
                    displayTitle();
                    printMenuHeader("SignIn", "UserMenu");
                    userInterface(idx, playerName, fatherName, id, cnic, netSalary, baseSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average, teamCount1, teamCount2, teamCount3, teamCount4, team1, team2, team3, team4, teamNames, matchCounter, opponentTeam, opposingTeam, resultOfMatch, matchDate);
                }
            }
            else
            {
                cout << "User Not Found" << endl;
                handlePause();
            }
        }
        else if (option == 2)
        {
            string temporaryPassword;
            printMenuHeader("Login Menu", "SignUp");
            string userN, userP, userR;
            cout << "Enter USerName: ";
            cin >> userN;
            cout << "Must be 8 digits long or use 2 special symboles." << endl;
            cout << "Enter USerPassword: ";
            cin >> temporaryPassword;
            bool passwordValid = true;
            while (passwordValid)
            {

                int specialSymbolCount = 0;
                int isNotEight = 0;
                isNotEight = (temporaryPassword.length());
                for (int i = 0; i < temporaryPassword.length(); i++)
                {
                    if (ispunct(temporaryPassword[i]))
                    {
                        specialSymbolCount++;
                    }
                }
                if (specialSymbolCount != 2 || isNotEight != 8)
                {
                    cout << "Invalid Password" << endl;
                    cout << "Password must be 8 digits long or could contain 2 special symbols." << endl;
                    cout << "Enter Again: ";
                    cin >> temporaryPassword;
                }
                else
                {
                    passwordValid = false;
                }
            }
            userP = temporaryPassword;
            cout << "Enter USerRole (Admin/User): ";
            cin >> userR;
            while ((userR != "Admin" && userR != "admin") && (userR != "User" && userR != "user"))
            {
                cout << "Invalid role! Use Admin or User only.\n";
                cout << "Enter USerRole (Admin/User): ";
                cin >> userR;
                continue;
            }

            bool check = SignUp(userCount, userN, userP, userR, userNames, userPasswords, userRoles);
            if (check)
            {
                cout << "SignUp Successfully" << endl;
                handlePause();
            }
            else
            {
                cout << "SignUp UnSuccessfully" << endl;
                handlePause();
            }
        }
        else if (option == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid Input" << endl;
            handlePause();
        }
    }

    return 0;
}

void displayTitle()
{
    SetConsoleOutputCP(CP_UTF8); // allow UTF-8 output
    system("cls");

    // Top border
    cout
        << "@@========================================================================================================@@" << endl;

    // Empty padding
    cout << "||                                                                                                        ||" << endl;

    // Banner lines with vertical sides
    cout << "|| █▀▀ █▀▄ ▀█▀ █▀▀ █ █ █▀▀ ▀█▀   █▀▀ █   █ █ █▀▄   █▀▄ █▀▀ █▀▀ █▀█ █▀▄ █▀▄   █▄█ █▀█ █▀█ █▀█ █▀▀ █▀▀ █▀▄  ||" << endl;
    cout << "|| █   █▀▄  █  █   █▀▄ █▀▀  █    █   █   █ █ █▀▄   █▀▄ █▀▀ █   █ █ █▀▄ █ █   █ █ █▀█ █ █ █▀█ █ █ █▀▀ █▀▄  ||" << endl;
    cout << "|| ▀▀▀ ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀▀▀   ▀▀▀ ▀▀▀ ▀▀▀ ▀▀    ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀    ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀||" << endl;

    // Empty padding
    cout << "||                                                                                                        ||" << endl;

    // Bottom border
    cout << "@@========================================================================================================@@" << endl
         << endl;
}

void mazeLogin()
{
    SetConsoleOutputCP(437);
    char solid = 219, dotted = 176;
    int hight = 8, width = 20;
    for (int i = 0; i < hight; i++)
    {
        if (i == 0 || i == hight - 1)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << solid << dotted;
            }
            cout << endl;
        }
        else
        {
            cout << solid << "                                      " << solid << endl;
            cout << dotted << "                                      " << dotted << endl;
        }
    }
}

void printMenuHeader(string mainMenu, string subMenu)
{
    displayTitle();
    string msg = mainMenu + " > " + subMenu;
    cout << msg << endl;
    cout << "------------------------------" << endl;
}
int menu1()
{
    int option;
    gotoxy(1, 12);
    cout << "Enter 1 for sign in";
    gotoxy(1, 14);
    cout << "Enter 2 for sign up";
    gotoxy(1, 16);
    cout << "Enter 3 for exit" << endl;
    gotoxy(1, 18);
    cout << "Enter your choice: ";
    cin >> option;
    return option;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

string SignIn(int userCount, string userN, string userP, string allNames[], string allPasswords[], string allRoles[])
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (allNames[idx] == userN && allPasswords[idx] == userP)
        {
            return allRoles[idx];
        }
    }
    return "undefined";
}
bool SignUp(int &userCount, string userN, string userP, string userR, string allNames[], string allPasswords[], string allRoles[])
{
    if (userCount < userSize)
    {
        for (int idx = 0; idx < userCount; idx++)
        {
            if (allNames[idx] == userN && allPasswords[idx] == userP)
            {
                return false;
            }
        }
        allNames[userCount] = userN;
        allPasswords[userCount] = userP;
        allRoles[userCount] = userR;
        userCount++;
        return true;
    }
    return false;
}

void adminInterface(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int team1[], int team2[], int team3[], int team4[], string teamNames[], int &teamCount1, int &teamCount2, int &teamCount3, int &teamCount4, int userCount, string userNames[], string userRoles[], string userPasswords[], int matchCounter, string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[])
{
    while (true)
    {
        int option = 0;
        option = adminMenu();
        if (option == 1)
        {
            if (registration(idx, playerName, fatherName, id, cnic, baseSalary, netSalary))
            {
                cout << "\nRegistration successful!\n";
                handlePause();
            }
            else
            {
                cout << "\nRegistration unsuccessfully";
            }
        }
        else if (option == 2)
        {
            displayTitle();
            viewData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary);
        }
        else if (option == 3)
        {
            displayTitle();
            if (
                deleteData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average, team1, team2, team3, team4, teamCount1, teamCount2, teamCount3, teamCount4))
            {
                cout << "Data is deleted successfully!" << endl;
                handlePause();
            }
        }
        else if (option == 4)
        {
            displayTitle();
            if (updateData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary))
            {
                cout << "Record is updated successfully";
                handlePause();
            }
        }
        else if (option == 5)
        {
            displayTitle();
            searchData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 6)
        {
            displayTitle();
            cout << "Total Salary is : " << calculateSalary(idx, baseSalary);
            handlePause();
        }
        else if (option == 7)
        {
            displayTitle();
            teamMake(idx, playerName, teamNames, team1, team2, team3, team4, teamCount1, teamCount2, teamCount3, teamCount4);
        }
        else if (option == 8)
        {
            displayTitle();
            int choice = 0;
            while (choice != 5)
            {
                string tempChoice;
                cout << "Enter 1 to view team memebrs of first" << endl;
                cout << "Enter 2 to view team memebrs of second" << endl;
                cout << "Enter 3 to view team memebrs of third" << endl;
                cout << "Enter 4 to view team memebrs of fourth" << endl;
                cout << "Enter 5 to exit" << endl;
                cin >> tempChoice;
                choice = stoi(numValidation(tempChoice));
                if (choice == 1)
                {
                    viewTeamMembers(teamCount1, teamNames[0], team1, playerName, id, cnic, baseSalary);
                }
                else if (choice == 2)
                {
                    viewTeamMembers(teamCount2, teamNames[1], team2, playerName, id, cnic, baseSalary);
                }
                else if (choice == 3)
                {
                    viewTeamMembers(teamCount3, teamNames[2], team3, playerName, id, cnic, baseSalary);
                }
                else if (choice == 4)
                {
                    viewTeamMembers(teamCount4, teamNames[3], team4, playerName, id, cnic, baseSalary);
                }
                else
                {
                    cout << "Invalid Input";
                }
            }
        }
        else if (option == 9)
        {
            displayTitle();
            if (playerStats(idx, playerName, playerMatch, ballFaced, fifties, centuries, sixes, fours, runs, dismissles, average, strikeRate))
            {
                cout << "Player stats are entered successfully";
            }
        }
        else if (option == 10)
        {
            displayTitle();
            viewPlayerStats(idx, playerName, playerMatch, ballFaced, fifties, centuries, average, strikeRate);
        }
        else if (option == 11)
        {
            displayTitle();
            if (organizeMatch(matchCounter, teamNames, opponentTeam, opposingTeam, matchDate, resultOfMatch))

            {
                cout << "Organized successfully.";
            }
            else
            {
                cout << "Organized unsuccessfully.";
            }
        }
        else if (option == 12)
        {
            displayTitle();
            viewMatchHistory(matchCounter, teamNames, opponentTeam, opposingTeam, resultOfMatch, matchDate);
            handlePause();
        }
        else if (option == 13)
        {
            displayTitle();
            int topIndex = searchTopPlayer(idx, average);
            cout << "\n==================Top Player==================\n";
            cout << "Player: " << playerName[topIndex] << endl;
            cout << "Average: " << average[topIndex] << endl;
            cout << "Strike Rate: " << strikeRate[topIndex] << endl;
            cout << "Centuries: " << centuries[topIndex] << endl;
            cout << "Fifties: " << fifties[topIndex] << endl;
            cout << "Sixes: " << sixes[topIndex] << endl;
            cout << "Four: " << fours[topIndex] << endl;
            cout << "Ball Faced: " << ballFaced[topIndex] << endl;
            cout << "Dissmissles: " << dismissles[topIndex] << endl;
            handlePause();
        }
        else if (option == 14)
        {
            displayTitle();
            playerInAsynding(idx, playerName, fatherName, id, cnic, baseSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 15)
        {
            displayTitle();
            playerInDesynding(idx, playerName, fatherName, id, cnic, baseSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 16)
        {
            displayTitle();
            viewAdmins(userCount, userNames, userRoles, userPasswords);
        }
        else if (option == 17)
        {
            displayTitle();
            viewUsers(userCount, userNames, userRoles, userPasswords);
        }
        else if (option == 18)
        {
            displayTitle();
            if (updateMatch(matchCounter, teamNames, opponentTeam, opposingTeam, resultOfMatch, matchDate))
            {
                cout << "Match updated successfully.\n";
            }
            else
            {
                cout << "Match updated unsuccessfully.\n";
            }
        }
        else if (option == 19)
        {
            displayTitle();
            cout << "Exiting Admin Interface.\n";
            handlePause();
            break;
        }

        else
        {
            cout << "Invalid input" << endl;
            handlePause();
        }
    }
}

void userInterface(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long netSalary[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int teamCount1, int teamCount2, int teamCount3, int teamCount4, int team1[], int team2[], int team3[], int team4[], string teamNames[], int matchCounter, string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[])

{
    int option = 0;
    displayTitle();
    printMenuHeader("SignIN", "UserMenu");

    while (true)
    {
        option = userMenu();
        if (option == 1)
        {
            displayTitle();
            viewData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary);
        }
        else if (option == 2)
        {
            displayTitle();
            searchData(idx, playerName, fatherName, id, cnic, baseSalary, netSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 3)
        {
            displayTitle();
            int choice = 0;
            while (choice != 5)
            {
                string tempChoice;
                cout << "Enter 1 to view team memebrs of first" << endl;
                cout << "Enter 2 to view team memebrs of second" << endl;
                cout << "Enter 3 to view team memebrs of third" << endl;
                cout << "Enter 4 to view team memebrs of fourth" << endl;
                cout << "Enter 5 to exit" << endl;
                cin >> tempChoice;
                choice = stoi(numValidation(tempChoice));
                if (choice == 1)
                {
                    viewTeamMembers(teamCount1, teamNames[0], team1, playerName, id, cnic, baseSalary);
                }
                else if (choice == 2)
                {
                    viewTeamMembers(teamCount2, teamNames[1], team2, playerName, id, cnic, baseSalary);
                }
                else if (choice == 3)
                {
                    viewTeamMembers(teamCount3, teamNames[2], team3, playerName, id, cnic, baseSalary);
                }
                else if (choice == 4)
                {
                    viewTeamMembers(teamCount4, teamNames[3], team4, playerName, id, cnic, baseSalary);
                }
                else
                {
                    cout << "Invalid Input";
                }
            }
        }
        else if (option == 4)
        {
            displayTitle();
            viewPlayerStats(idx, playerName, playerMatch, ballFaced, fifties, centuries, average, strikeRate);
        }
        else if (option == 5)
        {
            displayTitle();
            viewMatchHistory(matchCounter, teamNames, opponentTeam, opposingTeam, resultOfMatch, matchDate);
            handlePause();
        }
        else if (option == 6)
        {
            displayTitle();
            playerInAsynding(idx, playerName, fatherName, id, cnic, baseSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 7)
        {
            displayTitle();
            playerInDesynding(idx, playerName, fatherName, id, cnic, baseSalary, playerMatch, ballFaced, fifties, centuries, sixes, fours, dismissles, runs, strikeRate, average);
        }
        else if (option == 8)
        {
            displayTitle();
            cout << "Exiting User Interface.\n";
            handlePause();
            break;
        }

        else
        {
            cout << "Invalid Input";
        }
    }
}

bool registration(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[])
{
    // that function is for taking data from user as a input about player
    displayTitle();
    int numberOfPlayer, loopControl = 0, length;

    // ------------------------------------
    string tempNumber;
    cout << "Enter number of players: ";
    cin >> tempNumber;
    numberOfPlayer = stoi(numValidation(tempNumber));
    if (numberOfPlayer + idx > 50)
    {
        cout << "You can only register " << (50 - idx) << " more players.\n";
        return false;
    }
    cout << "\n--------- Registration for Player----------\n"
         << endl;
    while (loopControl < numberOfPlayer)
    {
        cout << "Enter name: ";
        cin >> playerName[idx];

        cout << "Enter father name: ";
        cin >> fatherName[idx];

        // ===================== ID VALIDATION ADDED HERE =====================
        string tempId;
        cout << "Enter id: ";
        cin >> tempId;
        long long temp = stoll(numValidation(tempId));
        while (isIdValid(temp, id, idx))
        {
            cout << "This ID is already exist, you can not enter this player." << endl;
            cout << "Enter id: ";
            cin >> tempId;
            temp = stoll(numValidation(tempId));
        }
        id[idx] = temp;
        // ====================================================================

        string tempCnic;
        cout << "Enter CNIC (must be exactly 13 digits): ";
        cin >> tempCnic;
        //   to initialize invalidCnic with that condition, here is pupose ,if digit is 13 invalidCnic will be false or in for loop it checks whether all are integers if not then invalid is becaome true and while loop will run untill user enter correct cnic .
        cnic[idx] = validationForCnic(tempCnic);
        // ----------fee Validation--------------
        string tempSalary;
        cout << "Enter Salary: ";
        cin >> tempSalary;
        baseSalary[idx] = stoll(numValidation(tempSalary));
        netSalary[idx] = baseSalary[idx];
        loopControl++;
        idx++;
    }
    return true;
}

void viewData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[])
{
    displayTitle();
    cout << std::left;
    cout << "\n=============================== PLAYER RECORDS =========================================\n";
    cout << std::setw(6) << "Index"
         << std::setw(8) << "ID"
         << std::setw(15) << "Name"
         << std::setw(15) << "Father"
         << std::setw(18) << "CNIC"
         << setw(15) << "BaseSalary"
         << setw(15) << "NetSalary" << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    for (int i = 0; i < idx; i++)
    {
        cout << std::setw(6) << i + 1
             << std::setw(8) << id[i]
             << std::setw(15) << playerName[i]
             << std::setw(15) << fatherName[i]
             << std::setw(18) << cnic[i]
             << setw(15) << baseSalary[i]
             << setw(15) << netSalary[i] << endl;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    handlePause();
}
string numValidation(string userInput)
{
    bool invalid = false;
    for (int i = 0; i < userInput.length(); i++)
    {
        if (!isdigit(userInput[i]))
        {
            invalid = true;
            break;
        }
    }
    while (invalid)
    {
        cout << "Invalid Input , input must be a integer" << endl;
        cout << "Enter again: ";
        cin >> userInput;
        invalid = false;
        for (int i = 0; i < userInput.length(); i++)
        {
            if (!isdigit(userInput[i]))
            {
                invalid = true;
                break;
            }
        }
    }
    return userInput;
}

int handlePause()
{
    string pause;

    cout << "\nType 'next' to continue: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, pause);

    while (pause != "next")
    {
        cout << "Please type 'next' to continue: ";
        getline(cin, pause);
    }

    cout << "Continuing..." << endl;
    return 0;
}

void viewAdmins(int userCount, string userNames[], string userRoles[], string userPasswords[])
{
    displayTitle();
    cout << endl
         << endl;
    cout << "*************************************************" << endl;
    cout << "*                 ADMINS                        *" << endl;
    cout << "*************************************************" << endl;

    cout << std::left;
    cout << setw(6) << "Index"
         << setw(16) << "Name"
         << setw(10) << "Role"
         << setw(10) << "Password";
    cout << endl;
    for (int i = 0; i < userCount; i++)
    {
        if (userRoles[i] == "Admin")
        {
            cout << setw(6) << (i + 1)
                 << setw(16) << userNames[i]
                 << setw(10) << userRoles[i]
                 << setw(10) << userPasswords[i];
            cout << endl;
        }
        cout << endl;
    }
    handlePause();
}
void viewUsers(int userCount, string userNames[], string userRoles[], string userPasswords[])
{
    displayTitle();
    cout << endl
         << endl;
    cout << "*************************************************" << endl;
    cout << "*                 USERS                         *" << endl;
    cout << "*************************************************" << endl;

    cout << std::left;
    cout << setw(6) << "Index"
         << setw(16) << "Name"
         << setw(10) << "Role"
         << setw(10) << "Password";
    cout << endl;
    for (int i = 0; i < userCount; i++)
    {
        if (userRoles[i] == "User")
        {
            cout << setw(6) << (i + 1)
                 << setw(16) << userNames[i]
                 << setw(10) << userRoles[i]
                 << setw(10) << userPasswords[i];
            cout << endl;
        }
        cout << endl;
    }
    handlePause();
}
int adminMenu()
{
    int choice;
    string tempChoice;
    printMenuHeader("SignIn", "AdminInterface");
    cout << "\n================= A D M I N   M E N U =================\n";
    cout << "Enter 1  for registration (Add Player)\n";
    cout << "Enter 2  for data view\n";
    cout << "Enter 3  for data delete\n";
    cout << "Enter 4  for update player data\n";
    cout << "Enter 5  for search player profile\n";
    cout << "Enter 6  for total salary\n";
    cout << "Enter 7  for team selection\n";
    cout << "Enter 8  for view team members\n";
    cout << "Enter 9  to update player's stats\n";
    cout << "Enter 10 to view player stats\n";
    cout << "Enter 11 to organize match\n";
    cout << "Enter 12 to see match history\n";
    cout << "Enter 13 to search top player\n";
    cout << "Enter 14 to see player runs in ascending order\n";
    cout << "Enter 15 to see player runs in descending order\n";
    cout << "Enter 16 to view all admins\n";
    cout << "Enter 17 to see all users\n";
    cout << "Enter 18 to update match result\n";
    cout << "Enter 19 to exit\n";
    cout << "\n=======================================================\n";
    cout << "Enter your choice: ";
    cin >> tempChoice;
    choice = stoi(numValidation(tempChoice));
    cout << "-----------------------------------------------------------" << endl;
    system("cls");
    return choice;
}
int userMenu()
{
    int choice;
    string tempChoice;
    printMenuHeader("SignIn", "UserInterface");
    cout << "\n================= U S E R   M E N U =================\n";
    cout << "Enter 1  for data view\n";
    cout << "Enter 2  for search player profile\n";
    cout << "Enter 3  for view team members\n";
    cout << "Enter 4  to view player stats\n";
    cout << "Enter 5  to see match history\n";
    cout << "Enter 6  to see player's in ascending order( according to runs)\n";
    cout << "Enter 7 to see player's in desending order( according to runs)\n";
    cout << "Enter 8  to exit\n";
    cout << "\n=====================================================\n";
    cout << "Enter your choice: ";
    cin >> tempChoice;
    choice = stoi(numValidation(tempChoice));
    cout << "-----------------------------------------------------------" << endl;
    return choice;
}
// --------------------------------------
void printNameIndex(int idx, string playerName[])
{
    cout << std::left;
    cout << "-------------------------------------------" << endl;
    cout << std::setw(10) << "I N D E \t" << "N A M E" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < idx; i++)
    {
        cout << "  " << setw(8) << (i + 1) << "\t " << playerName[i] << endl;
    }
}
void viewPlayerStats(int idx, string playerName[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], float average[], float strikeRate[])
{
    displayTitle();

    cout << fixed << setprecision(2);
    cout << std::left;

    cout << "=================================== Player Stats ======================================\n";

    // Set Header Column Widths
    cout << setw(6) << "Index"
         << setw(16) << "Name"
         << setw(10) << "Matches"
         << setw(10) << "Balls"
         << setw(6) << "50s"
         << setw(7) << "100s"
         << setw(10) << "Average"
         << setw(12) << "StrikeRate"
         << endl;

    cout << "---------------------------------------------------------------------------------------\n";

    for (int i = 0; i < idx; i++)
    {
        cout << setw(6) << (i + 1)
             << setw(16) << playerName[i]
             << setw(10) << playerMatch[i]
             << setw(10) << ballFaced[i]
             << setw(6) << fifties[i]
             << setw(7) << centuries[i]
             << setw(10) << average[i]
             << setw(12) << strikeRate[i]
             << endl;
    }
    handlePause();
}
void viewDataWithoutGetch(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long int netSalary[])
{
    displayTitle();

    cout << std::left;

    cout << "\n=============================== PLAYER RECORDS =========================================\n";

    cout << std::setw(6) << "Index"
         << std::setw(8) << "ID"
         << std::setw(15) << "Name"
         << std::setw(15) << "FatherName"
         << std::setw(15) << "CNIC"
         << "BaseSalary"
         << "NetSalary" << "\n";
    cout << "----------------------------------------------------------------------------------------\n";

    for (int i = 0; i < idx; i++)
    {
        cout << std::setw(6) << i + 1
             << std::setw(8) << id[i]
             << std::setw(15) << playerName[i]
             << std::setw(15) << fatherName[i]
             << std::setw(15) << cnic[i]
             << baseSalary[i]
             << netSalary[i] << endl;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
}

bool deleteData(int &idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[], int team1[], int team2[], int team3[], int team4[], int &teamCount1, int &teamCount2, int &teamCount3, int &teamCount4)
{
    displayTitle();
    viewDataWithoutGetch(idx, playerName, fatherName, id, cnic, baseSalary, netSalary);
    int del;
    string tempDel;
    cout << "Enter Index (Who's recored you want to delete): ";
    cin >> tempDel;
    del = stoi(numValidation(tempDel));
    int indexToDelete = del - 1;

    // ... validation check ...
    if (indexToDelete < 0 || indexToDelete >= idx)
    {
        cout << "Invalid index! Cannot delete." << endl;
        return false;
    }
    char choice = '0';
    while (true)
    {

        for (int i = 0; i < idx; i++)
        {
            if (indexToDelete == team1[i] || indexToDelete == team2[i] || indexToDelete == team3[i] || indexToDelete == team4[i])
            {

                cout << "This player is a part of a team ,are you sure you want to delete?(y/n):" << endl;
                cin >> choice;
                break;
            }
        }
        if (choice == '0')
        {
            break;
        }

        if (choice == 'y' || choice == 'Y')
        {

            deleteFromTeam(teamCount1, team1, indexToDelete);
            deleteFromTeam(teamCount2, team2, indexToDelete);
            deleteFromTeam(teamCount3, team3, indexToDelete);
            deleteFromTeam(teamCount4, team4, indexToDelete);

            deleteIfPlayer(indexToDelete, idx, playerName, fatherName, id, cnic, baseSalary, netSalary, strikeRate, runs, ballFaced, average, fifties, fours, centuries, sixes, playerMatch, dismissles);
            fixTeamIndices(team1, teamCount1, indexToDelete);
            fixTeamIndices(team2, teamCount2, indexToDelete);
            fixTeamIndices(team3, teamCount3, indexToDelete);
            fixTeamIndices(team4, teamCount4, indexToDelete);
            idx--;

            cout << "\nRecord deleted successfully!" << endl;
            return true;
        }

        else if (choice == 'N' || choice == 'n')
        {
            return false;
        }
        else
        {
            cout << "Invalid Input";
        }
    }
    deleteIfPlayer(indexToDelete, idx, playerName, fatherName, id, cnic, baseSalary, netSalary, strikeRate, runs, ballFaced, average, fifties, fours, centuries, sixes, playerMatch, dismissles);
    // -----------------------------------------------------------
    idx--;
    return true;
}

void deleteIfPlayer(int delPlayer, int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long int netSalary[], float strikeRate[], int runs[], int ballFaced[], float average[], int fifties[], int fours[], int centuries[], int sixes[], int playerMatch[], int dismissles[])
{
    for (int j = delPlayer; j < idx - 1; j++)
    {
        playerName[j] = playerName[j + 1];
        fatherName[j] = fatherName[j + 1];
        id[j] = id[j + 1];
        cnic[j] = cnic[j + 1];
        baseSalary[j] = baseSalary[j + 1];
        netSalary[j] = netSalary[j + 1];
        strikeRate[j] = strikeRate[j + 1];
        runs[j] = runs[j + 1];
        ballFaced[j] = ballFaced[j + 1];
        average[j] = average[j + 1];
        fifties[j] = fifties[j + 1];
        fours[j] = fours[j + 1];
        centuries[j] = centuries[j + 1];
        sixes[j] = sixes[j + 1];
        playerMatch[j] = playerMatch[j + 1];
        dismissles[j] = dismissles[j + 1];
    }
}

bool updateData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[])
{
    displayTitle();
    viewDataWithoutGetch(idx, playerName, fatherName, id, cnic, baseSalary, netSalary);

    int update;
    string tempUpdate;
    cout << "Enter index (Whose record you want to update): ";
    cin >> tempUpdate;
    update = stoi(numValidation(tempUpdate));
    int indexToUpdate = update - 1;

    if (indexToUpdate < 0 || indexToUpdate >= idx)
    {
        cout << "Invalid index!" << endl;
        handlePause();
        return false;
    }

    // Update Name
    cout << "Enter new name: ";
    cin >> playerName[indexToUpdate];

    // Update Father Name
    cout << "Enter father name: ";
    cin >> fatherName[indexToUpdate];

    // Update ID
    string tempId;
    cout << "Enter new ID (digits only): ";
    cin >> tempId;
    id[indexToUpdate] = stoll(numValidation(tempId));

    // Update CNIC
    string tempCnic;
    cout << "Enter CNIC (exactly 13 digits): ";
    cin >> tempCnic;
    cnic[indexToUpdate] = validationForCnic(tempCnic);

    // Update Salary/Fee
    string tempfee;
    cout << "Enter new Salary: ";
    cin >> tempfee;
    baseSalary[indexToUpdate] = stoll(numValidation(tempfee));

    // Keep netSalary updated as well
    netSalary[indexToUpdate] = baseSalary[indexToUpdate];

    return true;
}

void searchData(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], long long netSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[])
{
    displayTitle();
    // Assuming printNameIndex also needs parameters to show the list
    printNameIndex(idx, playerName);

    int searchIndex;
    string tempSearchIndex;
    cout << "======================== Search By Index ========================" << endl;
    cout << "Enter player index to search: ";
    cin >> tempSearchIndex;
    searchIndex = stoi(numValidation(tempSearchIndex));

    if (searchIndex > idx || searchIndex <= 0)
    {
        cout << "Error: Invalid index! Must be between 1 and " << idx << ".\n";
        handlePause();
        return;
    }

    int i = searchIndex - 1;

    cout << std::left << fixed << setprecision(2);
    const int labelWidthBio = 20;
    const int labelWidthStats = 20;

    cout << "\n=============== PLAYER'S BIODATA =====================" << endl;
    cout << setw(labelWidthBio) << "Player's Name:" << playerName[i] << endl;
    cout << setw(labelWidthBio) << "Father Name:" << fatherName[i] << endl;
    cout << setw(labelWidthBio) << "ID:" << id[i] << endl;
    cout << setw(labelWidthBio) << "CNIC:" << cnic[i] << endl;
    cout << setw(labelWidthBio) << "Base Salary:" << baseSalary[i] << endl;
    cout << setw(labelWidthBio) << "Net Salary:" << netSalary[i] << endl;

    cout << "\n=============== PLAYER'S STATS =====================" << endl;
    cout << setw(labelWidthStats) << "Player Matches:" << playerMatch[i] << endl;
    cout << setw(labelWidthStats) << "Ball Faced:" << ballFaced[i] << endl;
    cout << setw(labelWidthStats) << "Total Runs:" << runs[i] << endl;
    cout << setw(labelWidthStats) << "Average:" << average[i] << endl;
    cout << setw(labelWidthStats) << "Strike Rate:" << strikeRate[i] << endl;
    cout << setw(labelWidthStats) << "Dismissals:" << dismissles[i] << endl;
    cout << setw(labelWidthStats) << "Centuries:" << centuries[i] << endl;
    cout << setw(labelWidthStats) << "Fifties:" << fifties[i] << endl;
    cout << setw(labelWidthStats) << "Total Sixes:" << sixes[i] << endl;
    cout << setw(labelWidthStats) << "Total Fours:" << fours[i] << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    handlePause();
}
string validationForCnic(string userInputCnic)
{
    bool invalidCnic = (userInputCnic.length() != 13);
    for (int i = 0; i < userInputCnic.length(); i++)
    {
        if (!isdigit(userInputCnic[i]))
        {
            invalidCnic = true;
            break;
        }
    }

    while (invalidCnic)
    {
        cout << "Invalid CNIC! Must be exactly 13 digits and digits only.\nEnter CNIC again: ";
        cin >> userInputCnic;

        invalidCnic = (userInputCnic.length() != 13);
        for (int i = 0; i < userInputCnic.length() && !invalidCnic; i++)
        {
            if (!isdigit(userInputCnic[i]))
            {
                invalidCnic = true;
                break;
            }
        }
    }
    return userInputCnic;
}

long long int calculateSalary(int idx, long long int baseSalary[])
{
    long long int sum = 0;
    for (int i = 0; i < idx; i++)
    {
        sum += baseSalary[i];
    }
    return sum;
}

void viewTeamMembers(int countTeam, string teamName, int team[], string playerName[], long long int id[], string cnic[], long long int baseSalary[])
{
    displayTitle();
    if (countTeam == 0)
    {
        cout << "*******************************************************\n";
        cout << "Error: No players added to " << teamName << " yet!\n";
        cout << "*******************************************************\n";
        handlePause();
        return;
    }

    if (countTeam < 10)
    {
        cout << "*******************************************************\n";
        cout << "Error: Not Sufficient players to built a team \n"
             << teamName;
        cout << "*******************************************************\n";
        handlePause();
        return;
    }
    cout << "================ TEAM: " << teamName << " ================\n";
    cout << std::left;
    cout << setw(6) << "No." << setw(15) << "Name" << setw(10) << "ID" << setw(15) << "CNIC" << "Salary" << endl;
    cout << "----------------------------------------------------------------------\n";

    for (int i = 0; i <= countTeam; i++)
    {
        int playerIndex = team[i];
        cout << setw(6) << to_string(i + 1) + "."
             << setw(15) << playerName[playerIndex]
             << setw(10) << id[playerIndex]
             << setw(15) << cnic[playerIndex]
             << baseSalary[playerIndex] << endl;
    }
    cout << "----------------------------------------------------------------------\n";
    handlePause();
}
void teamMake(int idx, string playerName[], string teamNames[], int team1[], int team2[], int team3[], int team4[], int teamCount1, int teamCount2, int teamCount3, int teamCount4)
{
    displayTitle();
    string choiceTeamName;
    int temp = -1;
    cout << "============== Player's Selection ==============" << endl;

    if (idx < 11)
    {
        cout << "Not enough players to form a team!\n";
        handlePause();
        return;
    }

    cout << "We have four teams." << endl;
    cout << "Team 1: " << teamNames[0] << endl;
    cout << "Team 2: " << teamNames[1] << endl;

    char tempvar;
    for (int i = 2; i < 4; i++)
    {
        cout << "Want to make more teams? (y/n): ";
        cin >> tempvar;
        if (tempvar == 'y' || tempvar == 'Y')
        {
            cout << "Enter name of team " << i + 1 << ": ";
            cin >> teamNames[i];
        }
        else if (tempvar == 'n' || tempvar == 'N')
        {
            cout << "No problem." << endl;
            break;
        }
        else
        {
            cout << "Invalid Input." << endl;
            return;
        }
    }

    cout << " ---------------------------------------------------" << endl;
    cout << "|                   T E A M S                       |" << endl;
    cout << " ---------------------------------------------------" << endl;
    cout << std::left;
    cout << "***********************************" << endl;
    cout << "|" << setw(10) << "INDEX" << "NAME" << setw(10) << " |" << endl;
    cout << "***********************************" << endl;

    for (int j = 0; j < 4; j++)
    {
        if (teamNames[j] == "")
            cout << " " << setw(8) << (j + 1) << "Not Created" << endl;
        else
            cout << " " << setw(8) << (j + 1) << teamNames[j] << endl;
    }

    while (true)
    {
        bool teamFound = false;
        cout << "\nWhich team you want to select (Enter 'Q' to quit)?" << endl;
        cout << "Enter team Name: ";
        cin >> choiceTeamName;

        if (choiceTeamName == "Q" || choiceTeamName == "q")
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            if (choiceTeamName == teamNames[i] && teamNames[i] != "")
            {
                temp = i;
                teamFound = true;
                break;
            }
        }

        if (teamFound)
        {
            if (temp == 0)
                teamSelection(teamCount1, teamCount2, teamCount3, teamCount4, team1, team2, team3, team4, idx, playerName);
            else if (temp == 1)
                teamSelection(teamCount2, teamCount1, teamCount3, teamCount4, team2, team1, team3, team4, idx, playerName);
            else if (temp == 2)
                teamSelection(teamCount3, teamCount1, teamCount2, teamCount4, team3, team1, team2, team4, idx, playerName);
            else if (temp == 3)
                teamSelection(teamCount4, teamCount1, teamCount2, teamCount3, team4, team1, team2, team3, idx, playerName);
        }
        else
        {
            cout << "Invalid input or team not created yet!" << endl;
        }
    }
}

void teamSelection(int &count, int twoCount, int threeCount, int fourCount, int team[], int twoTeam[], int threeTeam[], int fourTeam[], int idx, string playerName[])
{
    if (count == 11)
    {
        char option;
        cout << "Team is full ,want to reset(y/n): ";
        cin >> option;
        if (option != 'y')
        {
            return;
        }
        count = 0;
        for (int i = 0; i < 11; i++)
            team[i] = -1;
    }

    bool isDuplicate = false;
    if (count < 11)
    {
        printNameIndex(idx, playerName);
        for (int i = 0; i < 11;)
        {
            string tempPlayerIndex;
            int tempPlayer;
            cout << "Enter index of player whom you want to add in team.";
            cin >> tempPlayerIndex;
            tempPlayer = checkIndexForTeam(tempPlayerIndex, idx);
            for (int j = 0; j < twoCount; j++)
            {
                if (tempPlayer - 1 == twoTeam[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < threeCount; j++)
            {
                if (tempPlayer - 1 == threeTeam[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < fourCount; j++)
            {
                if (tempPlayer - 1 == fourTeam[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team**************" << endl;
                    isDuplicate = true;
                }
            }

            if (isAlreadyPlayer(count, tempPlayer, team))
            {
                cout << "You cannot enter one player more than once!" << endl;
                isDuplicate = false;
                continue;
            }
            else
            {
                team[i] = tempPlayer - 1;
                count++;
                i++;
            }
        }
    }
}

bool isAlreadyPlayer(int size, int player, int team[])
{
    for (int j = 0; j < size; j++)
    {

        if (player - 1 == team[j])
        {
            return true;
        }
    }
    return false;
}
int checkIndexForTeam(string temIndex, int idx)
{

    int tempPlayer = stoi(numValidation(temIndex));
    while (tempPlayer < 1 || tempPlayer > idx)
    {
        cout << "Invalid index, Inut again: ";
        cin >> temIndex;
        tempPlayer = stoi(numValidation(temIndex));
    }
    return tempPlayer;
}
bool isIdValid(long long temporaryId, long long id[], int idx)
{
    for (int s = 0; s < idx; s++)
    {
        if (id[s] == temporaryId)
            return true;
    }
    return false;
}
int statsValidation(string str)
{
    return stoi(numValidation(str));
}

bool playerStats(int idx, string playerName[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int runs[], int dismissles[], float average[], float strikeRate[])
{
    // match,50,100,ballfaced,sixex,fours,strikerate,average
    int matchIndex;
    string tempMatchIndex;
    cout << "--------------------------Player States----------------------";
    printNameIndex(idx, playerName);
    cout << "Enter index whose profile you want to edit: ";
    cin >> tempMatchIndex;
    // The above variable is for check player index
    matchIndex = stoi(numValidation(tempMatchIndex));
    while (matchIndex > idx || matchIndex <= 0)
    {
        cout << "Error: Invalid index entered. Index must be between 1 and " << idx << ".\n";
        cin >> tempMatchIndex;
        matchIndex = stoi(numValidation(tempMatchIndex));
    }
    // this is temporary variable to check input validations
    string tempVariable;
    cout << "Enter matches played by player: ";
    cin >> tempVariable;
    playerMatch[matchIndex - 1] = statsValidation(tempVariable);
    // ----------------------------------
    cout << "Enter balls faced player: ";
    cin >> tempVariable;
    ballFaced[matchIndex - 1] = statsValidation(tempVariable);
    // --------------------------------------
    cout << "Enter fifties of player: ";
    cin >> tempVariable;
    fifties[matchIndex - 1] = statsValidation(tempVariable);
    //----------------------------------------
    cout << "Enter centuries of player: ";
    cin >> tempVariable;
    centuries[matchIndex - 1] = statsValidation(tempVariable);
    // --------------------------------------
    cout << "Enter sixes of player: ";
    cin >> tempVariable;
    sixes[matchIndex - 1] = statsValidation(tempVariable);
    // ---------------------------------------
    cout << "Enter fours of player: ";
    cin >> tempVariable;
    fours[matchIndex - 1] = statsValidation(tempVariable);
    // --------------------------------------
    cout << "Enter total runs of player: ";
    cin >> tempVariable;
    runs[matchIndex - 1] = statsValidation(tempVariable);
    // --------------------------------------
    cout << "Enter number of times player is dismissle: ";
    cin >> tempVariable;
    dismissles[matchIndex - 1] = statsValidation(tempVariable);
    // ----------------------------------------
    if (dismissles[matchIndex - 1] == 0)
    {
        cout << "As the player is NOT OUT (0 dismissals), Average is set to Total Runs." << endl;
        average[matchIndex - 1] = runs[matchIndex - 1];
    }
    else
    {
        average[matchIndex - 1] = runs[matchIndex - 1] / dismissles[matchIndex - 1];
    }
    // ---------------------------------------------------------------
    if (ballFaced[matchIndex - 1] == 0.0)
    {
        cout << "As balls faced is 0, Strike Rate is 0.0" << endl;
        strikeRate[matchIndex - 1] = 0.0;
    }
    else
    {
        strikeRate[matchIndex - 1] = (runs[matchIndex - 1] / ballFaced[matchIndex - 1]) * 100.0;
    }
    handlePause();
    return true;
}

bool organizeMatch(int &matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string matchDate[], string resultOfMatch[])
{
    displayTitle();
    if (matchCounter >= 50)
    {
        cout << "Error: Match history capacity is full (Max 50 matches).\n";
        handlePause();
        return false;
    }
    if (teamNames[0].empty())
    {
        cout << "Error: Teams must be named (Option 7) before scheduling a match.\n";
        handlePause();
        return false;
    }
    cout << "================== SCHEDUAL  A  NEW  MATCH ===================\n";
    cout << "--------------------Available Teams-------------------\n";
    printTeamNames(teamNames);
    string tempTeamInput;
    cout << "Enter which team is opponent: ";
    cin >> tempTeamInput;
    while (!isValidTeamName(tempTeamInput, teamNames))
    {
        cout << "Invalid Input, try again: ";
        cin >> tempTeamInput;
    }
    opponentTeam[matchCounter] = tempTeamInput;
    cout << "Enter which team is opposing: ";
    cin >> tempTeamInput;
    while (!isValidTeamName(tempTeamInput, teamNames))
    {
        cout << "Invalid Input, try again: ";
        cin >> tempTeamInput;
    }
    opposingTeam[matchCounter] = tempTeamInput;
    cout << "Enter date of match: ";
    cin >> matchDate[matchCounter];
    cout << "Enter result of match: ";
    cin >> resultOfMatch[matchCounter];
    matchCounter++;
    return true;
}

void printTeamNames(string teamNames[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << " " << i + 1 << ". " << teamNames[i] << endl;
    }
}

bool isValidTeamName(string str, string teamNames[])
{
    for (int i = 0; i < 4; i++)
    {
        if (str == teamNames[i])
        {
            return true;
        }
    }
    return false;
}

void viewMatchHistory(int matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[])
{
    displayTitle();

    if (matchCounter == 0)
    {
        cout << "No matches have been played yet.\n";
        handlePause();
        return;
    }

    if (teamNames[0].empty())
    {
        cout << "Error: Teams must be named (Option 7) before viewing history.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << std::left;

    cout << "=================================== MATCH HISTORY ======================================\n";
    cout << setw(10) << "matchIdx"
         << setw(16) << "OpponentTeam"
         << setw(16) << "OpposingTeam"
         << setw(16) << "Result"
         << setw(16) << "MatchDate" << endl;
    cout << "---------------------------------------------------------------------------------------\n";

    for (int i = 0; i < matchCounter; i++)
    {
        cout << setw(10) << (i + 1)
             << setw(16) << opponentTeam[i]
             << setw(16) << opposingTeam[i]
             << setw(16) << resultOfMatch[i]
             << setw(16) << matchDate[i] << endl;
    }
    cout << "---------------------------------------------------------------------------------------\n";
}

int searchTopPlayer(int idx, float average[])
{
    int index = 0;
    float maximum = average[0];

    for (int i = 1; i < idx; i++)
    {
        if (average[i] > maximum)
        {
            maximum = average[i];
            index = i;
        }
    }
    return index;
}

void playerInAsynding(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[])
{
    int maximumIndex;
    string temporary;
    for (int i = 0; i < idx; i++)
    {
        maximumIndex = find_mini(i, idx, average);
        if (maximumIndex == i)
        {
            continue;
        }
        else
        {
            // ----------------swapping of all integers---------------
            long long int temp;
            temp = id[i];
            id[i] = id[maximumIndex];
            id[maximumIndex] = temp;

            temp = baseSalary[i];
            baseSalary[i] = baseSalary[maximumIndex];
            baseSalary[maximumIndex] = temp;

            temp = playerMatch[i];
            playerMatch[i] = playerMatch[maximumIndex];
            playerMatch[maximumIndex] = temp;

            temp = fifties[i];
            fifties[i] = fifties[maximumIndex];
            fifties[maximumIndex] = temp;

            temp = centuries[i];
            centuries[i] = centuries[maximumIndex];
            centuries[maximumIndex] = temp;

            temp = ballFaced[i];
            ballFaced[i] = ballFaced[maximumIndex];
            ballFaced[maximumIndex] = temp;

            temp = sixes[i];
            sixes[i] = sixes[maximumIndex];
            sixes[maximumIndex] = temp;

            temp = fours[i];
            fours[i] = fours[maximumIndex];
            fours[maximumIndex] = temp;

            temp = dismissles[i];
            dismissles[i] = dismissles[maximumIndex];
            dismissles[maximumIndex] = temp;

            temp = runs[i];
            runs[i] = runs[maximumIndex];
            runs[maximumIndex] = temp;

            // -------------------swaping of strings-----------------------
            temporary = playerName[i];
            playerName[i] = playerName[maximumIndex];
            playerName[maximumIndex] = temporary;

            temporary = fatherName[i];
            fatherName[i] = fatherName[maximumIndex];
            fatherName[maximumIndex] = temporary;

            temporary = cnic[i];
            cnic[i] = cnic[maximumIndex];
            cnic[maximumIndex] = temporary;
            // -------------------swaping of float-----------------
            float temporaryFloat;
            temporaryFloat = average[i];
            average[i] = average[maximumIndex];
            average[maximumIndex] = temporaryFloat;

            temporaryFloat = strikeRate[i];
            strikeRate[i] = strikeRate[maximumIndex];
            strikeRate[maximumIndex] = temporaryFloat;
        }
    }

    printDataAOrDRuns(idx, playerName, runs, playerMatch, average, sixes, fours, strikeRate);
    handlePause();
}

int find_mini(int start, int idx, float average[])
{
    int minIndex = start;
    for (int i = start + 1; i < idx; i++)
    {
        if (average[i] < average[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int find_max(int start, int idx, float average[])
{
    int maxIdx = start;
    for (int i = start + 1; i < idx; i++)
    {
        if (average[i] > average[maxIdx])
        {
            maxIdx = i;
        }
    }
    return maxIdx;
}

void playerInDesynding(int idx, string playerName[], string fatherName[], long long int id[], string cnic[], long long int baseSalary[], int playerMatch[], int ballFaced[], int fifties[], int centuries[], int sixes[], int fours[], int dismissles[], int runs[], float strikeRate[], float average[])
{
    int maximumIndex;
    string temporary;
    for (int i = 0; i < idx; i++)
    {
        maximumIndex = find_max(i, idx, average);
        if (maximumIndex == i)
        {
            continue;
        }
        else
        {
            // ----------------swapping of all integers---------------
            long long int temp;
            temp = id[i];
            id[i] = id[maximumIndex];
            id[maximumIndex] = temp;

            temp = baseSalary[i];
            baseSalary[i] = baseSalary[maximumIndex];
            baseSalary[maximumIndex] = temp;

            temp = playerMatch[i];
            playerMatch[i] = playerMatch[maximumIndex];
            playerMatch[maximumIndex] = temp;

            temp = fifties[i];
            fifties[i] = fifties[maximumIndex];
            fifties[maximumIndex] = temp;

            temp = centuries[i];
            centuries[i] = centuries[maximumIndex];
            centuries[maximumIndex] = temp;

            temp = ballFaced[i];
            ballFaced[i] = ballFaced[maximumIndex];
            ballFaced[maximumIndex] = temp;

            temp = sixes[i];
            sixes[i] = sixes[maximumIndex];
            sixes[maximumIndex] = temp;

            temp = fours[i];
            fours[i] = fours[maximumIndex];
            fours[maximumIndex] = temp;

            temp = dismissles[i];
            dismissles[i] = dismissles[maximumIndex];
            dismissles[maximumIndex] = temp;

            temp = runs[i];
            runs[i] = runs[maximumIndex];
            runs[maximumIndex] = temp;

            // -------------------swaping of strings-----------------------
            temporary = playerName[i];
            playerName[i] = playerName[maximumIndex];
            playerName[maximumIndex] = temporary;

            temporary = fatherName[i];
            fatherName[i] = fatherName[maximumIndex];
            fatherName[maximumIndex] = temporary;

            temporary = cnic[i];
            cnic[i] = cnic[maximumIndex];
            cnic[maximumIndex] = temporary;
            // -------------------swaping of float-----------------
            float temporaryFloat;
            temporaryFloat = average[i];
            average[i] = average[maximumIndex];
            average[maximumIndex] = temporaryFloat;

            temporaryFloat = strikeRate[i];
            strikeRate[i] = strikeRate[maximumIndex];
            strikeRate[maximumIndex] = temporaryFloat;
        }
    }
    printDataAOrDRuns(idx, playerName, runs, playerMatch, average, sixes, fours, strikeRate);
    handlePause();
}

void printDataAOrDRuns(int idx, string playerName[], int runs[], int playerMatch[], float average[], int sixes[], int fours[], float strikeRate[])
{
    displayTitle();

    cout << fixed << setprecision(2);
    cout << std::left;

    cout << "=================================== Player Stats ======================================\n";

    // Set Header Column Widths
    cout << setw(8) << "Index"
         << setw(12) << "Name"
         << setw(12) << "Runs"
         << setw(10) << "Matches"
         << setw(10) << "Average"
         << setw(10) << "Sixes"
         << setw(10) << "Fours"
         << setw(12) << "StrikeRate" << endl;

    cout << "***************************************************************************************" << endl;
    for (int j = 0; j < idx; j++)
    {
        cout << setw(8) << (j + 1)
             << setw(12) << playerName[j]
             << setw(12) << runs[j]
             << setw(10) << playerMatch[j]
             << setw(10) << average[j]
             << setw(10) << sixes[j]
             << setw(10) << fours[j]
             << setw(12) << strikeRate[j]
             << endl;
    }
    cout << "***************************************************************************************" << endl;
}

bool updateMatch(int matchCounter, string teamNames[], string opponentTeam[], string opposingTeam[], string resultOfMatch[], string matchDate[])
{
    string tempEditMatch;
    int editMatch;

    viewMatchHistory(matchCounter, teamNames, opponentTeam, opposingTeam, resultOfMatch, matchDate);

    if (matchCounter == 0)
        return false;

    cout << "Enter which match you want to edit (1-" << matchCounter << "): ";
    cin >> tempEditMatch;

    editMatch = stoi(numValidation(tempEditMatch)) - 1;

    if (editMatch >= 0 && editMatch < matchCounter)
    {
        cout << "Enter new result of match: ";
        cin >> resultOfMatch[editMatch];
        cout << "Match updated successfully!" << endl;
        handlePause();
        return true;
    }

    cout << "Invalid match index!" << endl;
    handlePause();
    return false;
}

// function to remove the specific person from a team
void deleteFromTeam(int &count, int team[], int indexToDelete)
{
    for (int i = 0; i < count; i++)
    {
        if (team[i] == indexToDelete)
        {
            for (int j = i; j < count - 1; j++)
            {
                team[j] = team[j + 1];
            }
            count--;
            break;
        }
    }
}

// function to update indices of everyone else in that team
void fixTeamIndices(int team[], int &count, int delPlayer)
{
    for (int i = 0; i < count; i++)
    {
        if (team[i] > delPlayer)
        {
            team[i]--; // Adjust the index to match the new position in Bio Data
        }
    }
}