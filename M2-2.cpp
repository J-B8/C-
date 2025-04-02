#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX 5
using namespace std;
//GLOBAL VARIABLES
struct Record{
string name;
int qz1,qz2, qz3;
float ave;
};
class Person{
private:
    Record student[MAX];//ARRAY OF STRUCTURES
    int last;
    bool isfull();//true or false
    bool isempty();
    int locate(string n);
    float computeAve(int q1, int q2, int q3);
    void sortAve();
public:
    void init();
    bool exist(string n);
    void add(Record rec);
    void del(string n);
    void display();
    void save();
    void load();

};

int menu();

int main()
{
    Record data;
    Person cs;
    cs.init();
    cs.load();
    while(true)
    {
        switch(menu())
        {
            case 1: system("cls"); cout<<"Input name: ";
            cin.ignore();
            getline(cin, data.name);
                    if (cs.exist(data.name))
                        {
                            cout<<"Name already exist!";
                            system("pause");
                            break;
                        }
                    cout<<"Input Quiz 1: ";cin>>data.qz1; cout<<"Input Quiz 2: ";cin>>data.qz2;cout<<"Input Quiz 3: ";cin>>data.qz3;cs.add(data);break;

            case 2: system("cls"); cout<<"Input name to delete: ";
                    cin.ignore();
                    getline(cin,data.name);
                    cs.del(data.name);
                    break;

            case 3: cs.display();system("pause");break;

            case 4: exit(0);

            default: cout<<"Choose 1 to 4 only.\n"; system("pause");


        }
    }
}

void Person::init()
{
    last = -1;
}
void Person::add(Record rec)
{
    if (isfull())
    {
        cout<<"Array is full.\n";system("pause");
    }
    else
    {
        last++;
        rec.ave = computeAve(rec.qz1, rec.qz2, rec.qz3);
        student[last] = rec;
        save();
    }

}
void Person::del(string n)
{
int i,p;
    if (isempty())
    {
        cout<<"There's nothing to delete.\n";
        system("pause");
    }
    else
    {
    p=locate(n);
    if (p<0){
       cout<<"Record not found.\n";
       system("pause");
    }
    else
    {
        for (i=p;i<last;i++)
        {
            student[i] = student[i+1];
        }
        last--;
        cout << "Student deleted successfully!\n";
        system("pause");
        save();
    }

}
}
float Person::computeAve(int q1, int q2, int q3)
{
    return (q1 + q2 + q3) / 3.0;
}
void Person::sortAve()
{
     for (int i = 0; i <= last - 1; i++)
    {
        for (int j = i + 1; j <= last; j++)
        {
            if (student[i].ave< student[j].ave)
            {
                swap(student[i], student[j]);

            }
        }
    }
}
void Person::display()
{
    system("cls");
    sortAve();
    cout<<setw(10)<<right<<"NAME"<<setw(10)<<right<<"QUIZ 1"<<setw(10)<<right<<"QUIZ 2"<<setw(10)<<right<<"QUIZ 3"<<setw(10)<<right<<"AVERAGE"<<setw(10)<<right<<"REMARKS"<<endl;
    for (int i=0;i<=last;i++){
    cout<<i+1<<".) "<<setw(10)<<left<<student[i].name<<setw(10)<<left<<student[i].qz1<<setw(10)<<left<<student[i].qz2<<setw(10)<<left<<student[i].qz3<<setw(10) << left << fixed << setprecision(2)<<student[i].ave<<setw(10)<<left<<(student[i].ave >= 75 ? "PASSED" : "FAILED")<<endl;
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
bool Person::exist(string n)
{
    return locate(n) != -1;
}

int menu()
{
    system("cls");
    int op;
    cout <<"--- Student Record Program ---\n";
    cout <<"\n1. Add Record\n";
    cout <<"2. Delete Record\n";
    cout <<"3. Display Record\n";
    cout <<"4. Exit\n";
    cout <<"\nSelect (1-4): ";
    cin >> op;
    return op;
}

void Person::save()
{
    ofstream outFile("Student.txt");
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
        outFile << student[i].qz1 << " " << student[i].qz2 << " " << student[i].qz3 <<  endl;

    }

    outFile.close();
    cout << "Data saved successfully!\n";
}

void Person::load()
{
    ifstream inFile("Student.txt");
    if (!inFile) {
        cout << "File Error!\n";
        system("pause");
        return;
    }

    inFile >> last;
    inFile.ignore();

    string n;
    int q1, q2, q3;
    last--;

    for(int i = 0; i <=last; i++)
    {

        getline(inFile >> ws, student[i].name);
        inFile >> student[i].qz1 >> student[i].qz2 >> student[i].qz3;
        inFile.ignore();

        student[i].ave = computeAve(student[i].qz1, student[i].qz2, student[i].qz3);

    }
    inFile.close();
    cout << "Data loaded successfully!\n";

}
