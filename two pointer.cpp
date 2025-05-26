#include <iostream>

using namespace std;

class Myclass{
public:
    void findPairsWithSum(int arr[], int target, int arrSize)
     {
        for (int i = 0; i < arrSize; i++) {
            for (int j = i + 1; j < arrSize; j++) {
                    if (arr[i] + arr[j] == target) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
                }
            }
        }
    }
    void rtwosuminner(int first, int arr[], int target, int arrSize)
    {
        if (arrSize == 0)
            return;
        if (first + arr[0] == target)
            cout << "(" << first << ", " << arr[0] << ")\n";
            rtwosuminner(first, arr + 1, target, arrSize - 1);

    }
    void rtwosum(int arr[], int target, int arrSize)
    {
        if (arrSize <= 1)
            return;
        rtwosuminner(arr[0],arr + 1,target,arrSize-1);
        rtwosum(arr + 1, target, arrSize - 1);
    }
};


int main() {
    int arr[] = {2, 7, 4, 5, 9, 1, 3};
    int target = 10;
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    Myclass obj;

    cout << "Pairs that sum to " << target << ":\n";
    obj.findPairsWithSum(arr,target,arrSize);

     cout << "Pairs that sum to " << target << ":\n";
    obj.rtwosum(arr,target,arrSize);

    return 0;
}
