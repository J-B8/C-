#include <iostream>
#include <time.h>
using namespace std;

class Practice2{
public:
    void sort(int Arr[],int size)
    {
        for (int i = 0; i < size - 1;i++)
        for(int j = i + 1;j < size;j++){
            if(Arr[i] < Arr[j])
            {
                /*int temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;*/
                swap(Arr[j], Arr[i]);
            }
        }
    }
    void printArray(int Arr[],int size)
    {
        for(int i = 0; i < size; i++){
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    void Lucky(int Ar[])
    {
        int num, i,ctr = 0;
        bool exists;
            while(ctr<6)
            {
                num = rand()% 46 + 1;
                exists = false;
                for(i = 0; i < ctr; i++){
                    if(Ar[i]== num)
                    {
                        exists = true;
                        break;
                    }
                }
                if (!exists)
                {
                    Ar[ctr] = num;
                    ctr++;
                }
            }
    }

};


int main()
{
    int Arr[] = {5,3,2,1,6,4};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    Practice2 obj;



    cout << "Original Array: ";
    obj.printArray(Arr, size);

    obj.sort(Arr, size);

    cout << "Sorted Array: ";
    obj.printArray(Arr, size);

    srand(time(NULL));
    cout << "The numbers are: ";
    int Ar[6] = {};
    obj.Lucky(Ar);
    for(int i = 0; i < 6; i++){
        cout << Ar[i] << " ";
    }
    cout << endl;
    return 0;


}
