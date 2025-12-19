#include <iostream>
// String support. Essential for working with text data like names and passwords.
#include <string>
// Provides information about primitive data types.numeric_limits<streamsize>::max() (used in handlePause())
#include <limits>
// nput/Output MANIPulators. Essential for controlling the formatting of your output.std::left, std::setw(), std::fixed, std::setprecision()
#include <iomanip>
// Provides access to the Windows API for console control. (Crucial for display features).SetConsoleOutputCP(), gotoxy(), SetConsoleCursorPosition(), GetStdHandle(STD_OUTPUT_HANDLE) or SetConsoleOutputCP(437);
#include <windows.h>
// Character Type. Provides functions to check the type of a character.isdigit() (used in validation functions)
#include <cctype>
using namespace std;

// --------------------------------------------
// globall arrays or variable
long long int id[50] = {
    201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222};
long long int baseSalary[50] = {4500, 5200, 3900, 6100, 4700, 5000, 4300, 4800, 5500, 4950, 5100, 4400, 5800, 4900, 6300, 4200, 5400, 6000, 4750, 5300, 3425, 3422};

long long netSalary[50] = {4050, 4680, 3510, 5490, 4230, 4500, 3870, 4320, 4950, 4455, 4590, 3960, 5220, 4410, 5670, 3780, 4860, 5400, 4275, 4770, 3082, 3080};

string playerName[50] = {
    "Nabeel", "Shahzad", "Talha", "Rehan", "Sufyan",
    "Ahmed", "Usman", "Bilal", "Ahsan", "Farhan", "Omar", "Yasir", "Taha", "Daniyal", "Waqas",
    "Ali", "Hamza", "Zain", "Kamran", "Hasan", "Ahsan", "Quraish"};

string fatherName[50] = {
    "Yaseen", "Hameed", "Rafiq", "Abid", "Noman",
    "Sami", "Imran", "Javed", "Aslam", "Tariq", "Iqbal", "Qasim", "Latif", "Sajjad", "Rashid",
    "Zafar", "Faisal", "Nasir", "Sarwar", "Anwar", "Zahid", "Qasim"};

string cnic[50] = {
    "3520187654321", "3520199998888", "3120176543210", "4210188887777", "3450112345678",
    "4210198765432", "3310112345678", "4220187654321", "3450123456789", "3120165432109", "3740156789012", "4520123456789", "3110198765432", "3520111112222", "4230133334444",
    "3340155556666", "3120177778888", "3510199990000", "4240112121212", "3410134343434", "4123454657456", "2304542678901"};

int playerMatch[50] = {10, 5, 12, 8, 15, 3, 7, 10, 4, 6, 18, 6, 14, 9, 20, 5, 11, 13, 7, 16, 3, 45},
    fifties[50] = {2, 0, 3, 0, 4, 0, 1, 1, 0, 0, 5, 0, 3, 0, 8, 0, 2, 2, 0, 45, 23},
    centuries[50] = {0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 3, 0, 0, 1, 0, 0, 3, 2},
    ballFaced[50] = {180, 150, 240, 60, 300, 50, 120, 190, 10, 95, 350, 50, 325, 114, 568, 40, 280, 320, 84, 464, 500, 344},
    sixes[50] = {5, 8, 10, 2, 15, 1, 4, 7, 0, 3, 12, 1, 15, 4, 25, 0, 8, 10, 3, 11, 30, 23},
    fours[50] = {18, 15, 25, 5, 35, 4, 12, 20, 1, 8, 30, 6, 40, 10, 50, 3, 20, 28, 7, 35, 43, 21},
    dismissles[50] = {8, 3, 11, 5, 12, 2, 6, 9, 1, 4, 16, 4, 10, 8, 18, 3, 7, 12, 6, 15, 345, 678},
    runs[50] = {250, 320, 410, 70, 600, 55, 160, 300, 15, 100, 750, 45, 520, 120, 1050, 30, 350, 480, 80, 650, 342, 456};
float strikeRate[50] = {138.89, 213.33, 170.83, 116.67, 200.00, 110.00, 133.33, 157.89, 150.00, 105.26, 214.29, 90.00, 160.00, 105.26, 184.86, 75.00, 125.00, 150.00, 95.24, 140.00, 109.90, 134.00}, average[50] = {31.25, 106.67, 37.27, 14.00, 50.00, 27.50, 26.67, 33.33, 15.00, 25.00, 46.88, 11.25, 52.00, 15.00, 58.33, 10.00, 50.00, 40.00, 13.33, 43.33, 55.11, 34.00};

int idx = 22, team1[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, team2[50] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22}, team3[50], team4[50], teamCount1 = 11, teamCount2 = 11, teamCount3 = 0, teamCount4 = 0;

// Team Name variable
string teamNames[4] = {"Golden", "Silver"};

// arrays to organize matches in cricket clubs
int matchIndex[50], matchCounter = 0;
string opponentTeam[50], opposingTeam[50], resultOfMatch[50], matchDate[50];

// --------------------------------------------
void printMenuHeader(string mainMenu, string subMenu);
// ---------------------------------------------------
// int menu();
void printNameIndex();
void displayTitle();
bool registration();
bool deleteData();
void viewData();
void viewDataWithoutGetch();
bool updateData();
void searchData();
long long calculateSalary();
void teamMake();
int handlePause();
string numValidation(string userInput);
string validationForCnic(string userInputCnic);
int checkIndexForTeam(string temIndex);
void teamSelection1();
void teamSelection2();
void teamSelection3();
void teamSelection4();
void viewTeam1Members();
void viewTeam2Members();
void viewTeam3Members();
void viewTeam4Members();
bool playerStats();
void viewPlayerStats();
int statsValidation(string str);
bool organizeMatch();
void viewMatchHistory();
void printTeamNames();
bool isValidTeamName(string str);
int searchTopPlayer();
void playerInAsynding();
void playerInDesynding();
int find_max(int index);
int find_mini(int index);
void printDataAOrDRuns();
void viewAdmins();
void viewUsers();
void gotoxy(int x, int y);
bool updateMatch();
bool isIdValid(long long temporaryId);
void deleteIfPlayer(int index, int delPlayer);
// --------------------------------------------------
bool SignUp(string uN, string uP, string uR);
string SignIn(string uN, string uP);
const int userSize = 50;
string userNames[userSize] = {"Amreeha", "Eman"};
string userPasswords[userSize] = {"1", "2"};
string userRoles[userSize] = {"Admin", "User"};
int userCount = 2;
void adminInterface();
void userInterface();
int menu1();
int adminMenu();
int userMenu();
void mazeLogin();
// ----------------------------------------------------

int main()
{
    int option = 0;
    system("cls");
    displayTitle();
    while (true)
    {
        system("cls");
        printMenuHeader("Login Menu", "");
        // Purpose: This function sets the Windows Console Output Code Page to 437 (OEM/DOS).
        // This is necessary to correctly display extended ASCII characters like the block elements (char 219 and 176)
        // used for the maze/border art, preventing them from appearing as question marks ('?').
        SetConsoleOutputCP(437);
        mazeLogin();
        option = menu1();
        if (option == 1)
        {
            printMenuHeader("Login Menu", "SignIn");
            string uN, uP, uR;
            cout << "Enter UserName: ";
            cin >> uN;
            cout << "Enter UserPassword: ";
            cin >> uP;
            uR = SignIn(uN, uP);
            if (uR != "undefined")
            {
                if (uR == "Admin")
                {
                    displayTitle();
                    printMenuHeader("SignIn", "AdminMenu");
                    adminInterface();
                }
                if (uR == "User")
                {
                    displayTitle();
                    printMenuHeader("SignIn", "UserMenu");
                    userInterface();
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
            printMenuHeader("Login Menu", "SignUp");
            string uN, uP, uR;
            cout << "Enter USerName: ";
            cin >> uN;
            cout << "Enter USerPassword: ";
            cin >> uP;
            cout << "Enter USerRole (Admin/User): ";
            cin >> uR;
            if (uR != "Admin" && uR != "User")
            {
                cout << "Invalid role! Use Admin or User only.\n";
                handlePause();
                continue;
            }

            bool check = SignUp(uN, uP, uR);
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

// heaader message(location)
void printMenuHeader(string mainMenu, string subMenu)
{
    displayTitle();
    string msg = mainMenu + " > " + subMenu;
    cout << msg << endl;
    cout << "------------------------------" << endl;
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
int menu1()
{
    int option;
    gotoxy(1, 12);
    cout << "Enter 1 for sign in";
    gotoxy(1, 13);
    cout << "Enter 2 for sign up";
    gotoxy(1, 14);
    cout << "Enter 3 for exit" << endl;
    gotoxy(1, 15);
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
void mazeLogin()
{

    char solid = 219, dotted = 176;
    for (int i = 0; i < 20; i++)
    {
        cout << solid << dotted;
    }
    cout << endl;
    for (int j = 0; j < 4; j++)
    {
        cout << solid << "                                      " << solid << endl;
        cout << dotted << "                                      " << dotted << endl;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << solid << dotted;
    }
    cout << endl;
}

void adminInterface()
{
    while (true)
    {

        int option = 0;
        // printMenuHeader("Admin Menu", "");
        option = adminMenu();
        if (option == 1)
        {
            if (registration())
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
            viewData();
        }
        else if (option == 3)
        {
            displayTitle();
            if (deleteData())
            {
                cout << "Data is deleted successfully!" << endl;
                handlePause();
            }
        }
        else if (option == 4)
        {
            displayTitle();
            if (updateData())
            {
                cout << "Record is updated successfully";
                handlePause();
            }
        }
        else if (option == 5)
        {
            displayTitle();
            searchData();
        }
        else if (option == 6)
        {
            displayTitle();
            cout << "Total Salary is : " << calculateSalary();
            handlePause();
        }
        else if (option == 7)
        {
            displayTitle();
            teamMake();
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
                    viewTeam1Members();
                }
                else if (choice == 2)
                {
                    viewTeam2Members();
                }
                else if (choice == 3)
                {
                    viewTeam3Members();
                }
                else if (choice == 4)
                {
                    viewTeam4Members();
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
            if (playerStats())
            {
                cout << "Player stats are entered successfully";
            }
        }
        else if (option == 10)
        {
            displayTitle();
            viewPlayerStats();
        }
        else if (option == 11)
        {
            displayTitle();
            if (organizeMatch())
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
            viewMatchHistory();
            handlePause();
        }
        else if (option == 13)
        {
            displayTitle();
            int topIndex = searchTopPlayer();
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
            playerInAsynding();
        }
        else if (option == 15)
        {
            displayTitle();
            playerInDesynding();
        }
        else if (option == 16)
        {
            displayTitle();
            viewAdmins();
        }
        else if (option == 17)
        {
            displayTitle();
            viewUsers();
        }
        else if (option == 18)
        {
            displayTitle();
            if (updateMatch())
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
    // menu1();
}
void userInterface()
{
    int option = 0;
    // system("cls");
    displayTitle();
    // printMenuHeader("SignIN", "UserMenu");

    while (true)
    {
        option = userMenu();
        if (option == 1)
        {
            displayTitle();
            viewData();
        }
        else if (option == 2)
        {
            displayTitle();
            searchData();
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
                    viewTeam1Members();
                }
                else if (choice == 2)
                {
                    viewTeam2Members();
                }
                else if (choice == 3)
                {
                    viewTeam3Members();
                }
                else if (choice == 4)
                {
                    viewTeam4Members();
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
            viewPlayerStats();
        }
        else if (option == 5)
        {
            displayTitle();
            viewMatchHistory();
            handlePause();
        }
        else if (option == 6)
        {
            displayTitle();
            playerInAsynding();
        }
        else if (option == 7)
        {
            displayTitle();
            playerInDesynding();
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
    // menu1();
}
string SignIn(string uN, string uP)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == uN && userPasswords[idx] == uP)
        {
            return userRoles[idx];
        }
    }
    return "undefined";
}
bool SignUp(string uN, string uP, string uR)
{
    if (userCount < userSize)
    {
        for (int idx = 0; idx < userCount; idx++)
        {
            if (userNames[idx] == uN && userPasswords[idx] == uP)
            {
                return false;
            }
        }
        userNames[userCount] = uN;
        userPasswords[userCount] = uP;
        userRoles[userCount] = uR;
        userCount++;
        return true;
    }
    return false;
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
bool registration()
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
        while (isIdValid(temp))
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
        string tempfee;
        cout << "Enter fee: ";
        cin >> tempfee;
        baseSalary[idx] = stoll(numValidation(tempfee));
        netSalary[idx] = baseSalary[idx];
        idx++;
        loopControl++;
    }
    return true;
}
bool isIdValid(long long temporaryId)
{
    for (int s = 0; s < idx; s++)
    {
        if (id[s] == temporaryId)
            return true;
    }
    return false;
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

void viewData()
{

    displayTitle();
    int screenIndex = 1;

    // Use std::left to make sure all text is left-justified in its column
    cout << std::left;

    cout << "\n=============================== PLAYER RECORDS =========================================\n";

    // Use std::setw() for the header to define column widths
    cout << std::setw(6) << "Index"
         << std::setw(8) << "ID"
         << std::setw(15) << "Name"
         << std::setw(15) << "Father"
         << std::setw(15) << "CNIC"
         << setw(15) << "BaseSalary"
         << setw(15) << "NetSalary" << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    for (int i = 0; i < idx; i++)
    {
        // Use std::setw() before every single item in the loop to maintain alignment
        cout << std::setw(6) << screenIndex
             << std::setw(8) << id[i]
             << std::setw(15) << playerName[i]
             << std::setw(15) << fatherName[i]
             << std::setw(15) << cnic[i]
             << setw(15) << baseSalary[i]
             << setw(15) << netSalary[i] << endl;
        screenIndex++;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    handlePause();
}

void viewDataWithoutGetch()
{
    displayTitle();
    int screenIndex = 1;

    // Use std::left to make sure all text is left-justified in its column
    cout << std::left;

    cout << "\n=============================== PLAYER RECORDS =========================================\n";

    // Use std::setw() for the header to define column widths
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
        // Use std::setw() before every single item in the loop to maintain alignment
        cout << std::setw(6) << screenIndex
             << std::setw(8) << id[i]
             << std::setw(15) << playerName[i]
             << std::setw(15) << fatherName[i]
             << std::setw(15) << cnic[i]
             << baseSalary[i]
             << netSalary[i] << endl;
        screenIndex++;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
}
bool deleteData()
{
    displayTitle();
    viewDataWithoutGetch();
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
    char choice='0';
    while (true)
    {

        for (int i = 0; i < idx; i++)
        {
            if (indexToDelete == team1[i] || indexToDelete == team2[i]|| indexToDelete == team3[i] || indexToDelete == team4[i])
            {

                cout << "This player is a part of a team ,are you sure you want to delete?(y/n):" << endl;
                cin >> choice;
                break;
            }
        }
        if (choice=='0')
        {
            break;
        }
        
        if (choice == 'y' || choice == 'Y')
        {

            // Shifting elements to fill the gap left by the deleted record
            deleteIfPlayer(indexToDelete);
            // -----------------------------------------------------------
            idx--;
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
    deleteIfPlayer(indexToDelete);
            // -----------------------------------------------------------
            idx--;
            return true;
}
void deleteIfPlayer( int delPlayer)
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
bool updateData()

{
    displayTitle();
    viewDataWithoutGetch();
    int update;
    string tempUpdate;
    cout << "Enter index (Whose record you want to update): ";
    cin >> tempUpdate;
    update = stoi(numValidation(tempUpdate));
    int indexToUpdate = update - 1;

    if (indexToUpdate < 0 || indexToUpdate >= idx)
    {
        cout << "Invalid index!" << endl;
        return false;
    }

    // Update Name
    cout << "Enter new name: ";
    cin >> playerName[indexToUpdate];

    // Update Father Name
    cout << "Enter father name: ";
    cin >> fatherName[indexToUpdate];

    // Update ID with validation
    string tempId;
    cout << "Enter new ID (digits only): ";
    cin >> tempId;
    id[indexToUpdate] = stoll(numValidation(tempId));

    // Update CNIC with validation
    string tempCnic;
    cout << "Enter CNIC (must be exactly 13 digits): ";
    cin >> tempCnic;
    cnic[indexToUpdate] = validationForCnic(tempCnic);

    // Update Fee
    // ----------fee Validation--------------
    string tempfee;
    cout << "Enter new fee: ";
    cin >> tempfee;
    baseSalary[indexToUpdate] = stoll(numValidation(tempfee));
    // ----------------------------------------------------------------------

    return true;
}

void searchData()
{
    displayTitle();
    printNameIndex();
    int searchIndex;
    string tempSearchIndex;
    cout << "========================Search By Index========================" << endl;
    cout << "Enter player index to search: ";
    cin >> tempSearchIndex;
    searchIndex = stoi(numValidation(tempSearchIndex));
    if (searchIndex > idx || searchIndex <= 0)
    {
        cout << "Error: Invalid index entered. Index must be between 1 and " << idx << ".\n";
        return;
    }
    // set precision is used to decide values after decimal
    cout << std::left << fixed << setprecision(2);
    const int lableWidthBio = 15;
    const int lableWidthStats = 18;
    cout << "=============== PLAYER'S BIODATA =====================" << endl;
    cout << setw(lableWidthBio) << "Player's Name: " << playerName[searchIndex - 1] << endl;
    cout << setw(lableWidthBio) << "Father Name: " << fatherName[searchIndex - 1] << endl;
    cout << setw(lableWidthBio) << "ID: " << id[searchIndex - 1] << endl;
    cout << setw(lableWidthBio) << "CNIC: " << cnic[searchIndex - 1] << endl;
    cout << setw(lableWidthBio) << "BaseSlary: " << baseSalary[searchIndex - 1] << endl;
    cout << setw(lableWidthBio) << "NetSalary: " << netSalary[searchIndex - 1] << endl;
    cout << endl;
    cout << "=============== PLAYER'S STATS =====================" << endl;
    cout << setw(lableWidthStats) << "Player Matches: " << playerMatch[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Ball Faced: " << ballFaced[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Total Runs: " << runs[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Average: " << average[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "StrikeRate: " << strikeRate[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Dismissles: " << dismissles[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Centuries: " << centuries[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Fifties: " << fifties[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Total Sixes" << sixes[searchIndex - 1] << endl;
    cout << setw(lableWidthStats) << "Total Fours: " << fours[searchIndex - 1] << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    handlePause();
}

long long calculateSalary()
{
    long long sum = 0;
    for (int i = 0; i < idx; i++)
    {
        sum += baseSalary[i];
    }
    return sum;
}
void teamMake()
{
    displayTitle();
    string choiceTeamName;
    int temp = -1;
    cout << "==============Player's Selection==============" << endl;

    if (idx < 11)
    {
        cout << "Not enough players to form a team!\n";
        handlePause();
        return;
    }
    cout << "We have four teams." << endl;
    cout << "Team 1 team is: " << teamNames[0] << endl;
    cout << "Team 2 team is: " << teamNames[1] << endl;

    char tempvar;
    int a = 2;
    for (int i = 2; i < 4; i++)
    {
        cout << "Want to make more team?(y/n)" << endl;
        cin >> tempvar;
        if (tempvar == 'y')
        {
            cout << "Enter name of team " << a + 1 << ": ";
            cin >> teamNames[i];
        }
        else if (tempvar == 'n')
        {
            cout << "No problem" << endl;
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return;
        }
    }
    cout << " ---------------------------------------------------" << endl;
    cout << "|                  T E A M S                        |" << endl;
    cout << " ---------------------------------------------------" << endl;
    cout << std::left;
    cout << "***********************************" << endl;
    cout << "|" << setw(10) << "I N D E \t" << "N A M E         |" << endl;
    cout << "***********************************" << endl;
    for (int j = 0; j < 4; j++)
    {
        if (teamNames[j] == "")
            cout << " " << setw(8) << (j + 1) << "NotCreated" << endl;
        else
            cout << " " << setw(8) << (j + 1) << teamNames[j] << endl;
    }
    while (true)
    {
        bool teamFound = false;
        cout << "Which team you want to select(If you want to quit enter Q)?" << endl;
        cout << "Enter team Name: ";
        cin >> choiceTeamName;

        if (choiceTeamName == "Q")
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
            {
                teamSelection1();
            }
            else if (temp == 1)
            {
                teamSelection2();
            }
            else if (temp == 2)
            {
                teamSelection3();
            }
            else if (temp == 3)
            {
                teamSelection4();
            }
        }
        else
        {
            cout << "Invalid input or team not created yet!" << endl;
        }
    }
}
// to stop a program for a while
int handlePause()
{
    string pause;

    cout << "Type 'next' to continue: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, pause); // read input

    while (pause != "next")
    {
        cout << "Please type 'next' to continue: ";
        getline(cin, pause);
    }

    cout << "Continuing..." << endl;
    return 0;
}
int checkIndexForTeam(string temIndex)
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

void printNameIndex()
{
    cout << std::left; // Set alignment
                       // Used setw to ensure perfect alignment between index and name
    cout << "-------------------------------------------" << endl;
    cout << std::setw(10) << "I N D E \t" << "N A M E" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < idx; i++)
    {
        // Use setw(10) to ensure the player name always starts in the same column
        cout << "  " << setw(8) << (i + 1) << "\t " << playerName[i] << endl;
    }
}
void teamSelection1()
{
    if (teamCount1 == 11)
    {
        char option;
        cout << "Team is full ,want to reset(y/n): ";
        cin >> option;
        if (option != 'y')
        {
            return;
        }
        teamCount1 = 0;
        for (int i = 0; i < 11; i++)
            team1[i] = -1;
    }

    bool isDuplicate = false;
    if (teamCount1 < 11)
    {
        // function which prints player's indexs or names
        printNameIndex();
        for (int i = 0; i < 11;)
        {
            string tempPlayerIndex;
            int tempPlayer;
            cout << "Enter index of player whom you want to add in team.";
            cin >> tempPlayerIndex;
            tempPlayer = checkIndexForTeam(tempPlayerIndex);
            for (int j = 0; j < teamCount2; j++)
            {
                if (tempPlayer - 1 == team2[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team2**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount3; j++)
            {
                if (tempPlayer - 1 == team3[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team3**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount4; j++)
            {
                if (tempPlayer - 1 == team4[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team4**************" << endl;
                    isDuplicate = true;
                }
            }

            for (int j = 0; j < teamCount1; j++)
            {

                if (tempPlayer - 1 == team1[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate)
            {
                cout << "You cannot enter one player more than once!" << endl;
                isDuplicate = false;
                continue;
            }
            else
            {
                team1[i] = tempPlayer - 1;
                teamCount1++;
                i++;
            }
        }
    }
}
void teamSelection2()
{
    if (teamCount2 == 11)
    {
        char option;
        cout << "Team is full ,want to reset(y/n): ";
        cin >> option;
        if (option != 'y')
        {
            return;
        }
        teamCount2 = 0;
        for (int i = 0; i < 11; i++)
            team2[i] = -1;
    }

    bool isDuplicate = false;
    if (teamCount2 < 11)
    {
        // function which prints player's indexs or names
        printNameIndex();
        for (int i = 0; i < 11;)
        {
            string tempPlayerIndex;
            int tempPlayer;
            cout << "Enter index of player whom you want to add in team.";
            cin >> tempPlayerIndex;
            tempPlayer = checkIndexForTeam(tempPlayerIndex);
            for (int j = 0; j < teamCount1; j++)
            {
                if (tempPlayer - 1 == team1[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team1**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount3; j++)
            {
                if (tempPlayer - 1 == team3[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team3**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount4; j++)
            {
                if (tempPlayer - 1 == team4[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team4**************" << endl;
                    isDuplicate = true;
                }
            }

            for (int j = 0; j < teamCount2; j++)
            {

                if (tempPlayer - 1 == team2[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate)
            {
                cout << "You cannot enter one player more than once!" << endl;
                isDuplicate = false;
                continue;
            }
            else
            {
                team2[i] = tempPlayer - 1;
                teamCount2++;
                i++;
            }
        }
    }
}
void teamSelection3()
{

    if (teamCount3 == 11)
    {
        char option;
        cout << "Team is full ,want to reset(y/n): ";
        cin >> option;
        if (option != 'y')
        {
            return;
        }
        teamCount3 = 0;
        for (int i = 0; i < 11; i++)
            team3[i] = -1;
    }

    bool isDuplicate = false;
    if (teamCount3 < 11)
    {
        // function which prints player's indexs or names
        printNameIndex();
        for (int i = 0; i < 11;)
        {
            string tempPlayerIndex;
            int tempPlayer;
            cout << "Enter index of player whom you want to add in team.";
            cin >> tempPlayerIndex;
            tempPlayer = checkIndexForTeam(tempPlayerIndex);
            for (int j = 0; j < teamCount1; j++)
            {
                if (tempPlayer - 1 == team1[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team1**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount2; j++)
            {
                if (tempPlayer - 1 == team2[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team2**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount4; j++)
            {
                if (tempPlayer - 1 == team4[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team4**************" << endl;
                    isDuplicate = true;
                }
            }

            for (int j = 0; j < teamCount3; j++)
            {

                if (tempPlayer - 1 == team3[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate)
            {
                cout << "You cannot enter one player more than once!" << endl;
                isDuplicate = false;
                continue;
            }
            else
            {
                team3[i] = tempPlayer - 1;
                teamCount3++;
                i++;
            }
        }
    }
}

void teamSelection4()
{

    if (teamCount4 == 11)
    {
        char option;
        cout << "Team is full ,want to reset(y/n): ";
        cin >> option;
        if (option != 'y')
        {
            return;
        }
        teamCount4 = 0;
        for (int i = 0; i < 11; i++)
            team4[i] = -1;
    }

    bool isDuplicate = false;
    if (teamCount4 < 11)
    {
        // function which prints player's indexs or names
        printNameIndex();
        for (int i = 0; i < 11;)
        {
            string tempPlayerIndex;
            int tempPlayer;
            cout << "Enter index of player whom you want to add in team.";
            cin >> tempPlayerIndex;
            tempPlayer = checkIndexForTeam(tempPlayerIndex);
            for (int j = 0; j < teamCount1; j++)
            {
                if (tempPlayer - 1 == team1[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team1**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount2; j++)
            {
                if (tempPlayer - 1 == team2[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team2**************" << endl;
                    isDuplicate = true;
                }
            }
            for (int j = 0; j < teamCount3; j++)
            {
                if (tempPlayer - 1 == team3[j])
                {
                    cout << "We can not enter this player" << endl;
                    cout << "**************This player is already a part of team3**************" << endl;
                    isDuplicate = true;
                }
            }

            for (int j = 0; j < teamCount4; j++)
            {

                if (tempPlayer - 1 == team4[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate)
            {
                cout << "You cannot enter one player more than once!" << endl;
                isDuplicate = false;
                continue;
            }
            else
            {
                team4[i] = tempPlayer - 1;
                teamCount4++;
                i++;
            }
        }
    }
}
void viewTeam1Members()
{
    displayTitle();
    if (teamCount1 == 0)
    {
        cout << "*******************************************************\n";
        cout << "Error: The team has not been selected yet! (Option 7).\n";
        cout << "*******************************************************\n";
        handlePause();
        return; // Stop the function if no team is selected
    }
    cout << "================ TEAM: " << teamNames[0] << " ================\n";
    cout << "Index\tPlayerNames:\n";
    cout << "------------------------------------------------\n";

    cout << std::left; // Set alignment

    for (int i = 0; i < teamCount1; i++)
    {
        int playerIndex = team1[i]; // Get the index from the team array

        // Fix the alignment for the number (1. to 11.)
        // Use setw(4) to give a fixed space of 4 characters for the number and dot (e.g., "1.  " or "10. ")
        cout << setw(4) << to_string(i + 1) + ".";

        cout << playerName[playerIndex]
             << " (ID: " << id[playerIndex]
             << ", CNIC: " << cnic[playerIndex]
             << ", Salary: " << baseSalary[playerIndex] << ")\n";
    }

    cout << "------------------------------------------------\n";
    handlePause();
}
void viewTeam2Members()
{
    displayTitle();
    if (teamCount2 == 0)
    {
        cout << "*******************************************************\n";
        cout << "Error: The team has not been selected yet! (Option 7).\n";
        cout << "*******************************************************\n";
        handlePause();
        return; // Stop the function if no team is selected
    }
    cout << "================ TEAM: " << teamNames[1] << " ================\n";
    cout << "Index\tPlayerNames:\n";
    cout << "------------------------------------------------\n";

    cout << std::left; // Set alignment

    for (int i = 0; i < teamCount2; i++)
    {
        int playerIndex = team2[i]; // Get the index from the team array

        // Fix the alignment for the number (1. to 11.)
        // Use setw(4) to give a fixed space of 4 characters for the number and dot (e.g., "1.  " or "10. ")
        cout << std::setw(4) << to_string(i + 1) + ".";

        cout << playerName[playerIndex]
             << " (ID: " << id[playerIndex]
             << ", CNIC: " << cnic[playerIndex]
             << ", Salary: " << baseSalary[playerIndex] << ")\n";
    }

    cout << "------------------------------------------------\n";
    handlePause();
}
void viewTeam3Members()
{
    displayTitle();
    if (teamCount3 == 0)
    {
        cout << "*******************************************************\n";
        cout << "Error: The team has not been selected yet! (Option 7).\n";
        cout << "*******************************************************\n";
        handlePause();
        return; // Stop the function if no team is selected
    }
    cout << "================ TEAM: " << teamNames[2] << " ================\n";
    cout << "Index\tPlayerNames:\n";
    cout << "------------------------------------------------\n";

    cout << std::left; // Set alignment

    for (int i = 0; i < teamCount3; i++)
    {
        int playerIndex = team3[i]; // Get the index from the team array

        // Fix the alignment for the number (1. to 11.)
        // Use setw(4) to give a fixed space of 4 characters for the number and dot (e.g., "1.  " or "10. ")
        cout << std::setw(4) << to_string(i + 1) + ".";

        cout << playerName[playerIndex]
             << " (ID: " << id[playerIndex]
             << ", CNIC: " << cnic[playerIndex]
             << ", Salary: " << baseSalary[playerIndex] << ")\n";
    }

    cout << "------------------------------------------------\n";
    handlePause();
}
void viewTeam4Members()
{
    displayTitle();
    if (teamCount4 == 0)
    {
        cout << "*******************************************************\n";
        cout << "Error: The team has not been selected yet! (Option 7).\n";
        cout << "*******************************************************\n";
        handlePause();
        return; // Stop the function if no team is selected
    }
    cout << "================ TEAM: " << teamNames[3] << " ================\n";
    cout << "Index\tPlayerNames:\n";
    cout << "------------------------------------------------\n";

    cout << std::left; // Set alignment

    for (int i = 0; i < teamCount4; i++)
    {
        int playerIndex = team4[i]; // Get the index from the team array

        // Fix the alignment for the number (1. to 11.)
        // Use setw(4) to give a fixed space of 4 characters for the number and dot (e.g., "1.  " or "10. ")
        cout << std::setw(4) << to_string(i + 1) + ".";

        cout << playerName[playerIndex]
             << " (ID: " << id[playerIndex]
             << ", CNIC: " << cnic[playerIndex]
             << ", Salary: " << baseSalary[playerIndex] << ")\n";
    }

    cout << "------------------------------------------------\n";
    handlePause();
}

bool playerStats()
{

    // match,50,100,ballfaced,sixex,fours,strikerate,average
    int matchIndex;
    string tempMatchIndex;
    cout << "--------------------------Player States----------------------";
    printNameIndex();
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
        strikeRate[matchIndex - 1] = (runs[matchIndex - 1] / ballFaced[matchIndex - 1]) * 100;
    }
    handlePause();
    return true;
}
void viewPlayerStats()
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

int statsValidation(string str)
{
    return stoi(numValidation(str));
}

bool organizeMatch()
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
    printTeamNames();
    string tempTeamInput;
    cout << "Enter which team is opponent: ";
    cin >> tempTeamInput;
    while (!isValidTeamName(tempTeamInput))
    {
        cout << "Invalid Input, try again: ";
        cin >> tempTeamInput;
    }
    opponentTeam[matchCounter] = tempTeamInput;
    cout << "Enter which team is opposing: ";
    cin >> tempTeamInput;
    while (!isValidTeamName(tempTeamInput))
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
bool updateMatch()
{
    string tempEditMatch;
    int editMatch;
    viewMatchHistory();
    cout << "Enter which match you want to edit?  " << endl;
    cin >> tempEditMatch;
    editMatch = stoi(numValidation(tempEditMatch));
    editMatch = editMatch - 1;
    for (int i = 0; i < matchCounter; i++)
    {
        if (i == editMatch)
        {
            cout << "Enter result of match: ";
            cin >> resultOfMatch[editMatch];
            return true;
        }
    }
    return false;
}
void viewMatchHistory()
{
    displayTitle();
    if (matchCounter >= 50)
    {
        cout << "Error: Match history capacity is full (Max 50 matches).\n";
        handlePause();
        return;
    }
    if (teamNames[0].empty())
    {
        cout << "Error: Teams must be named (Option 7) before scheduling a match.\n";
        handlePause();
        return;
    }

    cout << fixed << setprecision(2);
    cout << std::left;

    cout << "=================================== MATCH HISTORY ======================================\n";
    cout << setw(10) << "matchIndex"
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

void printTeamNames()
{
    for (int i = 0; i < 4; i++)
    {
        cout << " " << i + 1 << ". " << teamNames[i] << endl;
    }
}

bool isValidTeamName(string str)
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

int searchTopPlayer()
{
    int index;
    float maximum = average[0];
    for (int i = 0; i < idx; i++)
    {
        if (average[i] > maximum)
        {
            maximum = average[i];
            index = i;
        }
    }
    return index;
}
void playerInAsynding()
{
    int maximumIndex;
    string temporary;
    for (int i = 0; i < idx; i++)
    {
        maximumIndex = find_mini(i);
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

    printDataAOrDRuns();
    handlePause();
}
void playerInDesynding()
{

    int maximumIndex;
    string temporary;
    for (int i = 0; i < idx; i++)
    {
        maximumIndex = find_max(i);
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
    printDataAOrDRuns();
    handlePause();
}

int find_max(int index)
{
    int maximum = runs[index];
    int returnIndex = index;

    for (int j = index; j < idx; j++)
    {

        if (runs[j] > maximum)
        {
            maximum = runs[j];
            returnIndex = j;
        }
    }
    return returnIndex;
}
int find_mini(int index)
{
    int minimum = runs[index];
    int returnIndex = index;

    for (int j = index; j < idx; j++)
    {

        if (runs[j] < minimum)
        {
            minimum = runs[j];
            returnIndex = j;
        }
    }
    return returnIndex;
}
void printDataAOrDRuns()
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
void viewAdmins()
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
void viewUsers()
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
void manageSalaryBonus()
{
    char op;
    float bonusPercent;
    for (int i = 0; i < idx; i++)
    {
        cout << "Player: " << playerName[i] << " (Base Salary: " << baseSalary[i] << ")" << endl;
        cout << "Want to give bonus?(y/n): ";
        cin >> op;
        if (op == 'y' || op == 'Y')
        {
            cout << "How many percent you want to gave bonus:  " << endl;
            cin >> bonusPercent;
            netSalary[i] = baseSalary[i] + baseSalary[i] * (bonusPercent / 100.0);
            cout << "Discount is given." << endl;
        }
        else if (op == 'n' || op == 'N')
        {
            netSalary[i] = baseSalary[i];
            cout << "No Bonus is given" << endl;
        }
        else
        {
            cout << "Invalid input.Enter again: " << endl;
            i--;
        }
    }
    cout << "------------------------------------------" << endl;
    cout << "All salaries updated successfully!" << endl;
    cout << "------------------------------------------" << endl;
}
