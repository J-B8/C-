#include <iostream>
#include <iomanip>

#define MAX 5
using namespace std;

string name[MAX];
int qz1[MAX], qz2[MAX], qz3[MAX];
float ave[MAX];
int last;

void init();
int isfull();
int isempty();
int locate(string n);
void del(string n);
void add(string n, int q1, int q2, int q3);
void display();
void update(string n, int q1, int q2, int q3);
float computeAve(int q1, int q2, int q3);
void sortAve();
int menu();

int main()
{
    string n;
    int q1, q2, q3;

    init();
    while(1)
    {
        switch(menu())
        {
        case 1:
                system("cls");
                cout<<"Input name: ";
                cin.ignore();
                getline(cin, n);

                if (locate(n)!=-1)
                {
                    cout<<"Name already exist!";
                    system("pause");
                    break;
                }
                cout<<"Quiz 1: ";
                cin >>q1;
                cout<<"Quiz 2: ";
                cin >>q2;
                cout<<"Quiz 3: ";
                cin >>q3;
                add(n, q1, q2, q3);
                break;

        case 2:
                system("cls");
                cout<<"Input name to update: ";
                cin.ignore();
                getline(cin, n);
                if (locate(n)==-1)
                {
                    cout<<"Name does not exist!";
                    system("pause");
                    break;
                }
                cout<<"Quiz 1: ";
                cin >>q1;
                cout<<"Quiz 2: ";
                cin >>q2;
                cout<<"Quiz 3: ";
                cin >>q3;
                update(n, q1, q2, q3);
                break;

        case 3:
                system("cls");
                cout<<"Input name to delete: ";
                cin.ignore();
                getline(cin, n);
                del(n);
                break;

        case 4:
                display();
                break;
        case 5:
                exit(0);
                break;

        default:
                cout<<"Choose 1 to 5 only.\n";
                system("pause");

    }
    }
}
void init()
{
    last = -1;
}
int isfull()
{
    return (last == MAX - 1);
}
int isempty()
{
    return (last == -1);
}
int locate(string n)
{
    for(int i=0;i<=last;i++)
    {
        if (name[i]== n)
            return i;
    }
    return -1;
}
void add(string n, int q1, int q2, int q3)
{
    if (isfull())
    {
        cout << "The record is full!";
        system("pause");
        return;
    }
    else
    {
        last++;
        name[last]=n;
        qz1[last] = q1;
        qz2[last] = q2;
        qz3[last] = q3;
        ave[last] = computeAve(q1, q2, q3);
        sortAve();
        cout << "Student added successfully!\n";
        system("pause");
    }

}
void update(string n, int q1, int q2, int q3)
{
    int p = locate(n);
    if (p==-1)
    {
        cout<<"\nName does not exist!";
        system("pause");
    }
    else
    {
        qz1[p] = q1;
        qz2[p] = q2;
        qz3[p] = q3;
        ave[p] = computeAve(q1, q2, q3);
        sortAve();
        cout << "Student updated successfully!\n";
        system("pause");
    }

}
void del(string n)
{
    int p,i;
    if(isempty())
    {
        cout << "The record is empty!";
        system("pause");
    }
    else
    p = locate(n);
    if(p < 0)
    {
        cout<<"Name does not exist!";
        system("pause");
    }
    else
    {
        for(i = p;i<last;i++)
        {
            name[i] = name[i + 1];
            qz1[i] = qz1[i + 1];
            qz2[i] = qz2[i + 1];
            qz3[i] = qz3[i + 1];
            ave[i] = ave[i + 1];

        }
        last--;
        cout << "Student deleted successfully!\n";
        system("pause");

}
}
float computeAve(int q1, int q2, int q3)
{
    return (q1 + q2 + q3) / 3.0;
}
void sortAve()
{
     for (int i = 0; i <= last - 1; i++)
    {
        for (int j = i + 1; j <= last; j++)
        {
            if (ave[i] < ave[j])
            {
                swap(name[i], name[j]);
                swap(qz1[i], qz1[j]);
                swap(qz2[i], qz2[j]);
                swap(qz3[i], qz3[j]);
                swap(ave[i], ave[j]);
            }
        }
    }
}
void display()
{

    system("cls");
    cout<<setw(10)<<right<<"NAME"<<setw(10)<<right<<"QUIZ 1"<<setw(10)<<right<<"QUIZ 2"<<setw(10)<<right<<"QUIZ 3"<<setw(10)<<right<<"AVERAGE"<<setw(10)<<right<<"REMARKS"<<endl;
    for (int i=0;i<=last;i++){
    cout<<i+1<<".) "<<setw(10)<<left<<name[i]<<setw(10)<<left<<qz1[i]<<setw(10)<<left<<qz2[i]<<setw(10)<<left<<qz3[i]<<setw(10) << left << fixed << setprecision(2)<<ave[i]<<setw(10)<<left<<(ave[i] >= 75 ? "PASSED" : "FAILED")<<endl;
}
    system("pause");
}
int menu()
{
    system("cls");
    int op;
    cout <<"\n--- Student Record Program ---\n";
    cout <<"1. Add Student\n";
    cout <<"2. Update Student\n";
    cout <<"3. Delete Student\n";
    cout <<"4. Display Students\n";
    cout <<"5. Exit\n";
    cout <<"\nSelect (1-5): ";
    cin >> op;
    return op;
}
