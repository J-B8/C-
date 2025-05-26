#include <iostream>
#include <string>
using namespace std;

class Practice{
public:
     bool isorteddescending(int Arr[], int size)
     {
         for(int i=0; i < size - 1; i++)
         {
             if(Arr[i] < Arr[i + 1])
             {
                 return false;
             }
         }
          return true;
     }

     int roccurrence(int Arr[], int size, int x, int index = 0)
     {
         if(index >= size)
            return 0;
         int count = (Arr[index]==x) ? 1 : 0;
         return count + roccurrence(Arr,size,x,index + 1);
     }

     int ifindsmallest(int Arr[],int size)
     {
         if (size <= 0)
            cout << "The given array is empty.";
         int small = Arr[0];

         for(int i = 1;i < size;i++)
         {
             if(Arr[i] < small)
                small = Arr[i];
         }
         return small;
     }

     int rfindsmallest(int Arr[],int size)
     {
         if (size == 1)
            return Arr[0];

         int minnum = rfindsmallest(Arr, size - 1);
         return(Arr[size - 1] < minnum )? Arr[size - 1]: minnum;
     }

     bool ipalindrome(int Arr[],int size)
     {
         int left = 0;
         int right = size -1;
         while(left < right)
         {
             if (Arr[left] != Arr[right])
                return false;
             left++;
             right--;
         }
            return true;
     }

     bool rpalindrome(int Arr[],int left, int right)
     {
         if (left >= right)
            return true;
         if(Arr[right] != Arr[left])
            return false;
         return rpalindrome(Arr,left + 1, right - 1);

     }

};

int get_int(const string &prompt)
{
int val;
cout << prompt;
while (!(cin >> val))
{
    cout << "Please enter a number. Try again. ";
    cin.clear();
    while (cin.get()!= '\n');

}
    return val;
}

int main()
{
    int size = 5;
    int Arr[size];
    cout << "Enter " << size << " numbers: \n";
    for (int i=0;i< size; i++)
    {
        Arr[i] = get_int("Enter number " + to_string(i + 1) + ": ");
    }

    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;

    Practice obj;

    cout << "\n1.) Iterative method to determine if the given array is sorted in descending order.\n";
    if(obj.isorteddescending(Arr,size))
    {
        cout << "The given array is sorted in descending order." << endl;
    }
    else
    {
        cout << "The given array is NOT sorted in descending order." << endl;
    }
    system("pause");

    cout << "\n2.) Recursive method to count the occurrence of a number in an array\n";
    int num = get_int("Enter number to check for occurrences: ");
    cout << "\nThe number " << num << " occurs " << obj.roccurrence(Arr,size,num) << " times in the given array.\n";

    system("pause");
    cout << "\n3.) Iterative method to find the smallest element in an array.\n";
    int ismallnum = obj.ifindsmallest(Arr,size);
    cout << "The smallest number in the given array is: " << ismallnum << endl;

    system("pause");
    cout << "\n4.) Recursive method to find the smallest element in an array.\n";
    int rsmallnum = obj.rfindsmallest(Arr,size);
    cout << "The smallest number in the given array is: " << rsmallnum << endl;


    system("pause");
    cout << "\n5.) Iterative method to check if the array is PALINDROME\n";
    if (obj.ipalindrome(Arr,size))
    {
        cout << "The given array is a PALINDROME." << endl;
    }
    else
    {
        cout << "The given array is NOT a PALINDROME." << endl;
    }

    system("pause");
    cout << "\n6.) Recursive method to check if the array is PALINDROME\n";
    if (obj.rpalindrome(Arr,0,size - 1))
    {
        cout << "The given array is a PALINDROME." << endl;
    }
    else
    {
        cout << "The given array is NOT a PALINDROME." << endl;
    }
}
