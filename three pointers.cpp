#include <iostream>
using namespace std;

class Myclass {
public:

    void findTripletsWithSum(int arr[], int target, int arrSize) {
        for (int i = 0; i < arrSize - 2; i++) {
            for (int j = i + 1; j < arrSize - 1; j++) {
                for (int k = j + 1; k < arrSize; k++) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")\n";
                    }
                }
            }
        }
    }


    void rfindTripletInner(int arr[], int first, int target, int arrSize, bool visited[]) {
        if (arrSize < 2) return;

        for (int i = 1; i < arrSize; i++) {
            for (int j = i + 1; j < arrSize; j++) {
                if (arr[first] + arr[i] + arr[j] == target) {
                    if (!visited[first] && !visited[i] && !visited[j]) {
                        cout << "(" << arr[first] << ", " << arr[i] << ", " << arr[j] << ")\n";
                        visited[first] = true;
                        visited[i] = true;
                        visited[j] = true;
                    }
                }
            }
        }
    }

    // Main recursive function to find all triplets
    void rfindTriplets(int arr[], int target, int arrSize) {
        if (arrSize < 3) return;

        bool visited[arrSize] = {false};  // Array to track visited elements

        for (int i = 0; i < arrSize - 2; i++) {
            rfindTripletInner(arr, i, target, arrSize, visited);
            rfindTriplets(arr + 1, target, arrSize - 1);  // Recursive call with reduced array
        }
    }
};

int main() {
    int arr[] = {2, 7, 4, 5, 9, 1, 3};
    int target = 10;
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    Myclass obj;
    cout << "Triplets that sum to " << target << ":\n";
    obj.findTripletsWithSum(arr, target, arrSize);

    cout << "Triplets that sum to " << target << ":\n";
    obj.rfindTriplets(arr, target, arrSize);

    return 0;
}
