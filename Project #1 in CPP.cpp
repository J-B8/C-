#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <string>
# define MAX 5
using namespace std;

struct Record{

string name;
string pass;
int addscore;
int subscore;
int multiscore;
int divscore;
float ave;

};

class Person{
private:
    Record student[MAX];
    int last;
    int currentuser;
    bool isfull();
    bool isempty();
    int locate(string n);
    float computeAve(int pos);

    void sortscores();
    void sortAddscores();
    void sortSubscores();
    void sortMultiscores();
    void sortDivscores();

public:
    void init();
    void signup(Record Rec);
    void password(string& p);
    string getPassword(int userind);
    int findUserindex(string n);
    void login(string n);
    bool exist(string n);
    void add(Record Rec);
    void del(string n);
    void display();
    void save();
    void retrieve();
    void savescore();
    void retrievescores();




};

int menu();
int menu2();
int quizdisplay();
void credits();
 int addition(int items);
    int subtraction(int items);
    int multiplication(int items);
    int division(int items);

int main()
{
    string confirm, enterpass;
    Record data;
    Person cs;
    cs.init();
    int pos = -1;
   // cs.retrieve();
   // cs.retrievescores();

    while(true)
    {
        switch(menu())
        {
            case 1: system("cls"); cout<<"Input name: ";
                    cin.ignore();
                    getline(cin, data.name);
                    if (cs.exist(data.name))
                    {
                        cout<<"The name already exists!\nPlease proceed to log in.\n";
                        system("pause");
                        break;
                    }
                    while(1)
                    {
                        cout<< "Enter your password (maximum 8 characters): ";
                        cs.password(data.pass);

                        cout<< "\nConfirm password: ";
                        cs.password(confirm);


                        if (data.pass == confirm)
                        {
                            cs.signup(data);
                            break;
                        }
                        else
                        {
                            cout <<"\nPasswords do not match! Please try again!\n";
                            system("pause");
                        }

                    }
                    break;

            case 2:
                    system("cls");
                    cout << "Enter your username: ";
                    cin.ignore();  // Clear the input buffer
                    getline(cin, data.name);

    // Declare pos before use
                    pos = cs.findUserindex(data.name);

                    if (pos == -1)
                        {
                            cout << "The username doesn't exist! Please proceed to sign up.\n";
                            system("pause");
                            break;  // Exit this case and go back to the menu
                        }

    // Ask for password
                        cout << "Enter your password (maximum 8 characters): ";
                        cs.password(enterpass); // Read the password input

    // Check password validity
                    if (enterpass == cs.getPassword(pos))
                        {
                            cs.login(data.name);  // Login the user
                            break;  // Exit this case and go back to the menu
                        }
                    else
                        {
                            cout << "\nPasswords do not match! Please try again!\n";
                            system("pause");  // Pause for user to see the error
                        }
                    break;  // Exit this case and go back to the menu


            case 3: credits();
                    break;

            case 4: exit(0);

            default: cout<<"Select 1 to 4 only.\n"; system("pause");

        }
    }

}

void Person::init()
{
    last = -1;
    currentuser = -1;

    for(int i = 0; i < MAX; i++)
    {
        student[i].name = "";
        student[i].pass = "";
        student[i].addscore=0;
        student[i].subscore = 0;
        student[i].multiscore = 0;
        student[i].divscore = 0;
        student[i].ave = 0;

    }
}
bool Person::isfull()
{
    return (last==MAX-1);
}
bool Person::isempty()
{
    return (last==-1);
}
int Person::locate(string n)
{
    int i;
    for (i=0;i<=last;i++)
        {
            if (student[i].name == n)
            return i;
        }
    return -1;
}
int Person::findUserindex(string n)
{
    return locate(n);
}
bool Person::exist(string n)
{
    return locate(n) != -1;
}
void Person::add(Record rec)
{
    if (isfull()) {
        cout << "The record is full.\n";
        return ;
    }
    last++;
    student[last] = rec;  // Increment and then assign the record

}

void Person::signup(Record rec)
{
        add(rec);  // Add the record
        currentuser = last;
        student[currentuser].pass = rec.pass;  // Set the current user
        system("cls");
        cout << "\nSign up Successful!\n";
        cout << "Username: " << student[currentuser].name << endl;
        // quizdisplay(); // Uncomment when quiz functionality is implemented
        system("pause");

}
void Person::login(string n)
{
    system("cls");
    currentuser = locate(n);
    cout << "\nLogin Successful!" << endl;
    cout << "Welcome back, " << student[currentuser].name << endl;
    system("pause");
}
void Person::password(string& p)
{
      char ch;
      p = "";
        while (true)
        {
        ch = _getch();  // _getch is used in Windows to handle char input
        if (ch == 13) // Enter key
            break;
        if (ch == 8 && p.length() > 0) // Backspace
        {
            cout << "\b \b";
            p.pop_back();  // Remove last character
        }
        else if (ch >= 32 && ch <= 126) // Allow printable characters
        {
            p.push_back(ch);
            cout << "*";  // Display asterisks for password characters
        }
        }
        cout << endl;
}
string Person::getPassword(int userind)
{
    return student[userind].pass;
}
void Person::save()
{
    ofstream outFile("Studentcpp.txt");
    if (!outFile)
    {
        cout << "File Error!\n" << endl;
        system("pause");
        return;
    }

    outFile << last + 1 << endl;

    for(int i = 0; i <=last; i++)
    {
        if(student[i].name.empty()) continue;

        outFile << student[i].name << endl;
        outFile << student[i].pass << endl;
        outFile << student[i].addscore << " " << student[i].subscore << " " << student[i].multiscore<< " " << student[i].divscore << endl;

    }

    outFile.close();
    cout << "Data saved successfully!\n";
}
void Person::retrieve()
{
    ifstream inFile("Studentcpp.txt");
    if (!inFile) {
        cout << "File Error!\n";
        system("pause");
        return;
    }
    inFile >> last;
    inFile.ignore();
    last--;

    for(int i = 0; i <=last; i++)
    {
        getline(inFile >> ws, student[i].name);
        getline(inFile >> ws, student[i].pass);
        inFile >> student[i].addscore >> student[i].subscore >> student[i].multiscore >> student[i].divscore;
        inFile.ignore();
       // student[i].ave = computeAve(student[i].qz1, student[i].qz2, student[i].qz3);
    }
    inFile.close();
    cout << "Data loaded successfully!\n";

}





int menu() {
    int choice;
    cout << "1. Sign up\n2. Log in\n3. Credits\n4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void credits() {
    system("cls");
    cout << "Arithmetic Quiz Game\n";
    cout << "Created by [Your Name]\n";
    system("pause");
}
