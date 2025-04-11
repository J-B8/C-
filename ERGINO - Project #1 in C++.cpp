#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <string>
# define MAX 5
using namespace std;


class User{
protected:
    string name;
    string pass;
public:
    void setName(string n){name = n;}
    string getName(){return name;}
    void setPassword(string p) {pass = p;}
    string getPassword(){return pass;}
    bool checkPassword(string p){return pass == p;}
};

class Student : public User{
private:
    int addscore;
    int subscore;
    int multiscore;
    int divscore;
public:
    Student(){
        addscore = 0;
        subscore = 0;
        multiscore = 0;
        divscore = 0;
    }
    void setAddscore(int score){addscore = score;}
    int getAddscore() {return addscore;}
    void setSubscore(int score){subscore = score;}
    int getSubscore() {return subscore;}
    void setMultiscore(int score) {multiscore = score;}
    int getMultiscore(){return multiscore;}
    void setDivscore(int score){divscore=score;}
    int getDivscore(){return divscore;}
    float getAverage()
    {
        return (addscore + subscore + multiscore + divscore) / 4.0f;
    }

};

class Person{
private:
    Student students[MAX];
    int last;
    int currentuser;

public:
    Person()
    {
        last = -1;
        currentuser = -1;
    }
bool isfull()
{
        return (last==MAX-1);
}
bool isempty()
{
        return (last==-1);
}
int locate(string n)
{
    for (int i=0;i<=last;i++)
        {
            if (students[i].getName() == n)
            return i;
        }
    return -1;
}
bool signup(string name, string pass)
{
    if (isfull())
    {
        return false;
    }

    if (locate(name)!= -1)
    {
        return false;
    }
    last++;
    students[last].setName(name);
    students[last].setPassword(pass);
    return true;
}
bool login(string name, string pass)
{
    int pos = locate(name);
    if (pos == -1)
    {
        return false;
    }
    if (students[pos].checkPassword(pass))
    {
        currentuser = pos;

        return true;
    }
    return false;
}
void logout() {
    currentuser = -1;
}
string getCurrentusername()
{
    if (currentuser != -1)
    {

        return students[currentuser].getName();

    }
    return "";
}
void setAddscore(int score)
{
    if (currentuser != -1)
        {
            students[currentuser].setAddscore(score);
        }
}

void setSubscore(int score)
 {
    if (currentuser != -1)
        {
            students[currentuser].setSubscore(score);
        }
}

void setMultiscore(int score)
{
    if (currentuser != -1)
        {
            students[currentuser].setMultiscore(score);
        }
    }

void setDivscore(int score)
{
        if (currentuser != -1)
        {
            students[currentuser].setDivscore(score);
        }
    }


int getAddscore()
{
        if (currentuser != -1)
        {
            return students[currentuser].getAddscore();
        }
        return 0;
    }

int getSubscore()
{
        if (currentuser != -1)
        {
            return students[currentuser].getSubscore();
        }
        return 0;
    }

int getMultiscore()
 {
        if (currentuser != -1)
        {
            return students[currentuser].getMultiscore();
        }
        return 0;
    }

int getDivscore()
{
        if (currentuser != -1)
        {
            return students[currentuser].getDivscore();
        }
        return 0;
    }

float getAverage()
{
        if (currentuser != -1)
        {
            return students[currentuser].getAverage();
        }
        return 0.0f;
    }
void swapStudents(int i, int j)
{
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
}

void sortAddscores()
{
    string currentUserName = "";
    if (currentuser != -1) {
        currentUserName = students[currentuser].getName();
    }

    for (int i = 0; i <= last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (students[i].getAddscore() < students[j].getAddscore()) {
                swapStudents(i, j);
            }
        }
    }

    if (!currentUserName.empty()) {
        currentuser = locate(currentUserName);
    }
}

void sortSubscores()
{
    string currentUserName = "";
    if (currentuser != -1) {
        currentUserName = students[currentuser].getName();
    }

    for (int i = 0; i <= last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (students[i].getSubscore() < students[j].getSubscore()) {
                swapStudents(i, j);
            }
        }
    }
    if (!currentUserName.empty()) {
        currentuser = locate(currentUserName);
    }
}

void sortMultiscores()
{
       string currentUserName = "";
    if (currentuser != -1) {
        currentUserName = students[currentuser].getName();
    }
    for (int i = 0; i <= last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (students[i].getMultiscore() < students[j].getMultiscore()) {
                swapStudents(i, j);
            }
        }
    }
    if (!currentUserName.empty()) {
        currentuser = locate(currentUserName);
    }
}

void sortDivscores()
{
        string currentUserName = "";
    if (currentuser != -1) {
        currentUserName = students[currentuser].getName();
    }
    for (int i = 0; i <= last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (students[i].getDivscore() < students[j].getDivscore()) {
                swapStudents(i, j);
            }
        }
    }

    if (!currentUserName.empty()) {
        currentuser = locate(currentUserName);
    }
}
void displayAdditionLeaderboard() {
    sortAddscores();
    cout << "\n=====> Addition Scores Leaderboard <=====\n";
    cout << "\nRANK\tNAME\t\tSCORE\n";
    for (int i = 0; i <= last; i++) {
        cout << i + 1 << ".)\t" << students[i].getName() << "\t\t"
             << students[i].getAddscore() << endl;
    }
    cout << endl;
}

void displaySubtractionLeaderboard() {
    sortSubscores();
    cout << "\n=====> Subtraction Scores Leaderboard <=====\n";
    cout << "\nRANK\tNAME\t\tSCORE\n";
    for (int i = 0; i <= last; i++) {
        cout << i + 1 << ".)\t" << students[i].getName() << "\t\t"
             << students[i].getSubscore() << endl;
    }
    cout << endl;
}

void displayMultiplicationLeaderboard() {
    sortMultiscores();
    cout << "\n=====> Multiplication Scores Leaderboard <=====\n";
    cout << "\nRANK\tNAME\t\tSCORE\n";
    for (int i = 0; i <= last; i++) {
        cout << i + 1 << ".)\t" << students[i].getName() << "\t\t"
             << students[i].getMultiscore() << endl;
    }
    cout << endl;
}

void displayDivisionLeaderboard() {
    sortDivscores();
    cout << "\n=====> Division Scores Leaderboard <=====\n";
    cout << "\nRANK\tNAME\t\tSCORE\n";
    for (int i = 0; i <= last; i++) {
        cout << i + 1 << ".)\t" << students[i].getName() << "\t\t"
             << students[i].getDivscore() << endl;
    }
    cout << endl;
}
bool save()
{
    ofstream outfile("Students.txt");
    if(!outfile)
    {
        return false;
    }
    outfile << last + 1 << endl;

    for(int i = 0; i<=last;i++)
    {
        outfile << students[i].getName() << endl;
        outfile << students[i].getPassword() << endl;
        outfile << students[i].getAddscore() << " " << students[i].getSubscore() << " " << students[i].getMultiscore() << " " << students[i].getDivscore() << endl;
    }
    outfile.close();
    return true;
}
bool load()
{
    ifstream inFile("Students.txt");
        if (!inFile)
        {
            return false;
        }

        int count;
        inFile >> count;
        inFile.ignore();

        last = -1;

        for (int i = 0; i < count; i++)
        {
            string name, pass;
            int add, sub, mult, div;

            getline(inFile, name);
            getline(inFile, pass);
            inFile >> add >> sub >> mult >> div;
            inFile.ignore();

            last++;
            students[last].setName(name);
            students[last].setPassword(pass);
            students[last].setAddscore(add);
            students[last].setSubscore(sub);
            students[last].setMultiscore(mult);
            students[last].setDivscore(div);
        }

        inFile.close();
        return true;
}
int getLast()
{
    return last;
}

Student getStudent(int index)
{
    if (index >= 0 && index <= last)
    {
        return students[index];
    }
    return Student();
}

void password(string& p);

void sort()
{
    string currentUserName = "";
    if (currentuser != -1) {
        currentUserName = students[currentuser].getName();
    }

    for (int i = 0; i <= last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (students[i].getAverage() < students[j].getAverage()) {
                swapStudents(i, j);
            }
        }
    }
    if (!currentUserName.empty()) {
        currentuser = locate(currentUserName);
    }
}

};
class ArithmeticQuiz{
protected:
    int items;
    string quiztype;
    Person* personRef;

public:
    ArithmeticQuiz(int i = 5, string type = "Generic",Person* person = nullptr)
    {
        items = i;
        quiztype = type;
        personRef = person;
    }
    virtual int performQuiz()=0;

    string getType()
    {
        return quiztype;
    }

    int getItems()
    {
        return items;
    }
    void setPerson(Person* person) {
        personRef = person;
    }
};
class AdditionQuiz : public ArithmeticQuiz{
public:
    AdditionQuiz(int i = 5,Person* person = nullptr) : ArithmeticQuiz(i, "Addition") {

        personRef = person;
    }
    int performQuiz()override{
    system("cls");

    if (personRef)
        {
            personRef ->displayAdditionLeaderboard();
        }
    cout << " === " << quiztype << " Quiz ===\n";
    cout << "\nName: " << personRef->getCurrentusername() << "\n\n";

    int c = 0;
        for(int i = 1; i <= items; i++) {
            int a = rand() % 15 + 1;
            int b = rand() % 10 + 1;
            int ans;

            cout << i << ". What is " << a << " + " << b << "? ";
            cin >> ans;

            if(ans == a + b) {
                cout << "Correct!\n";
                c++;
            } else {
                cout << "Incorrect. The answer is " << (a + b) << endl;
            }
        }
        return c;
    }
};
class SubtractionQuiz : public ArithmeticQuiz{
public:
    SubtractionQuiz(int i = 5, Person* person = nullptr) : ArithmeticQuiz(i, "Subtraction") {

            personRef = person;
    }
    int performQuiz()override{
    system("cls");
    if (personRef)
        {
            personRef ->displaySubtractionLeaderboard();
        }
    cout << " === " << quiztype << " Quiz ===\n";
    cout << "\nName: " << personRef->getCurrentusername() << "\n\n";

    int a,b, c = 0;
        for(int i = 1; i <= items; i++) {
            do{
                a = rand() % 15 + 1;
                b = rand() % 10 + 1;
            } while(a<b);

            int ans;

            cout << i << ". What is " << a << " - " << b << "? ";
            cin >> ans;

            if(ans == a - b) {
                cout << "Correct!\n";
                c++;
            } else {
                cout << "Incorrect. The answer is " << (a - b) << endl;
            }
        }
        return c;
    }
};
class MultiplicationQuiz : public ArithmeticQuiz{
public:
    MultiplicationQuiz(int i = 5, Person* person = nullptr) : ArithmeticQuiz(i, "Multiplication") {

        personRef = person;
    }
    int performQuiz()override{
    system("cls");
    if (personRef)
        {
            personRef ->displayMultiplicationLeaderboard();
        }

    cout << " === " << quiztype << " Quiz ===\n";
    cout << "\nName: " << personRef->getCurrentusername() << "\n\n";

    int c = 0;
        for(int i = 1; i <= items; i++) {
            int a = rand() % 15 + 1;
            int b = rand() % 10 + 1;
            int ans;

            cout << i << ". What is " << a << " * " << b << "? ";
            cin >> ans;

            if(ans == a * b) {
                cout << "Correct!\n";
                c++;
            } else {
                cout << "Incorrect. The answer is " << (a * b) << endl;
            }
        }
        return c;
    }
};
class DivisionQuiz : public ArithmeticQuiz{
public:
    DivisionQuiz(int i = 5,Person* person = nullptr) : ArithmeticQuiz(i, "Division") {

        personRef = person;

    }
    int performQuiz()override{
    system("cls");
   if (personRef)
        {
            personRef ->displayDivisionLeaderboard();
        }
    cout << " === " << quiztype << " Quiz ===\n";
    cout << "\nName: " << personRef->getCurrentusername() << "\n\n";
    int a,b,c = 0;
        for(int i = 1; i <= items; i++) {
            do{
                a = rand() % 15 + 1;
                b = rand() % 10 + 1;
            }while(a % b !=0);

            int ans;

            cout << i << ". What is " << a << " / " << b << "? ";
            cin >> ans;

            if(ans == a / b) {
                cout << "Correct!\n";
                c++;
            } else {
                cout << "Incorrect. The answer is " << (a / b) << endl;
            }
        }
        return c;
    }
};
void Person::password(string& p) {
    char ch;
    p = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!p.empty()) {
                cout << "\b \b";
                p.pop_back();
            }
        } else {
            p += ch;
            cout << '*';
        }
    }
    cout << endl;
}


void quizDisplay(Person& person);
void displayLeaderboard(Person& person);
void Credits();

int mainMenu() {
    system("cls");
    cout << "=== ARITHMETIC QUIZ PROGRAM ===\n\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Credits\n";
    cout << "4. Exit\n\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;
    return choice;
}


int quizMenu(Person& person) {
    system("cls");
    displayLeaderboard(person);

    cout << "\n=== QUIZ MENU ===\n";
    cout << "Participant: " << person.getCurrentusername() << endl;

    cout << "\n\n1. Addition Quiz\n";
    cout << "2. Subtraction Quiz\n";
    cout << "3. Multiplication Quiz\n";
    cout << "4. Division Quiz\n";
    cout << "5. Logout\n\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;
    return choice;
}
void quizDisplay(Person& person)
{
    int score;
    srand(time(NULL));
    cout << "ARITHMETHIC QUIZ\n";

    while (true)
    {
        int choice = quizMenu(person);

        ArithmeticQuiz* quiz = nullptr;
        switch(choice){
        case 1:
            quiz = new AdditionQuiz(5,&person);
            break;
        case 2:
            quiz = new SubtractionQuiz(5,&person);
            break;
        case 3:
            quiz = new MultiplicationQuiz(5,&person);
            break;
        case 4:
            quiz = new DivisionQuiz(5,&person);
            break;
        case 5:
                cout << "\nLogging out...\n";
                person.logout();
                system("pause");
                cin.ignore();
                cin.get();
                return;
        default:
            cout << "Please select options 1-6 only.\n";
            system("pause");
            continue;
        }

        if (quiz) {

            score = quiz->performQuiz();

            if (choice == 1) person.setAddscore(score);
            else if (choice == 2) person.setSubscore(score);
            else if (choice == 3) person.setMultiscore(score);
            else if (choice == 4) person.setDivscore(score);
            person.save();

            cout << "\nGreat job, " << person.getCurrentusername()
                 << "! You answered " << score << " questions correctly out of 5.\n";

            delete quiz;
            system("pause");
        }

    }
}
void displayLeaderboard(Person& person)
{
    system("cls");
    person.sort();

    cout << "=======>>> OVERALL LEADERBOARD <<<=======\n\n";
    cout << setw(5) << left << "RANK"
         << setw(18) << "NAME"
         << setw(15) << "ADDITION"
         << setw(15) << "SUBTRACTION"
         << setw(15) << "MULTIPLICATION"
         << setw(15) << "DIVISION"

         << setw(20) << "AVERAGE"
         << endl;

    for (int i = 0; i <= person.getLast(); i++) {
        Student s = person.getStudent(i);
        int totalScore = s.getAddscore() + s.getSubscore() + s.getMultiscore() + s.getDivscore();
        float average = s.getAverage() * 20;

        cout << left << i + 1 << ".)  "
             << setw(22) << s.getName()
             << setw(15) << s.getAddscore()
             << setw(15) << s.getSubscore()
             << setw(15) << s.getMultiscore()
             << setw(15) << s.getDivscore()

             << setw(10) << fixed << setprecision(2) << average
             << endl;
    }
}

int main()
{
    Person personManager;
    personManager.load();

    while(true)
    {
        int choice = mainMenu();

        switch(choice){

    case 1:
            {
                system("cls");
                cout << "=== LOGIN ===\n\n";
                string username, password;
                cin.ignore();
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";

                personManager.password(password);

                if (personManager.login(username,password))
                {
                    cout << "\nLogin Successful!\n";
                    system("pause");
                    quizDisplay(personManager);
                }
                else
                {
                    cout << "\nInvalid username or password. Please try again.\n";
                    system("pause");
                }
            }
            break;
    case 2:
            {
                system("cls");
                cout << "=== REGISTER ===\n\n";
                string username, password;
                cin.ignore();
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";

                personManager.password(password);

                if (personManager.signup(username, password)) {
                    cout << "\nRegistration successful! Logging in...\n";
                    personManager.save();
                    personManager.login(username, password);
                    system("pause");
                    quizDisplay(personManager);
                }
                else {
                    cout << "\nRegistration failed. Username may already exist or maximum users reached.\n";
                    system("pause");
                }
                }
                break;
        case 3:
                Credits();
                break;
        case 4:
            return 0;

        default:
            cout << "\nPlease select options 1-4 only.\n";
            system("pause");

    }

    }
}
void Credits()
{
    system("cls");
    cout << "=== CREDITS ===\n";
    cout << "\nProject #1:  Simple Arithmetic Practice Program in C++\n";
    cout << "Student: Jakob Berzelius A. Ergino\n";
    cout << "Course/Year/Section: BSCS - 1A\n";
    cout << "Professor: Mr. Fernando Renegado\n\n";

    system("pause");

}
