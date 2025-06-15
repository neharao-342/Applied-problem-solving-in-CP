#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int missingCount = 0;
    int current = 1;
    int i = 0;

    while (missingCount < k) {
        if (i < arr.size() && arr[i] == current) {
            i++;
        } else {
            missingCount++;
            if (missingCount == k)
                return current;
        }
        current++;
    }
    return -1; // Should not reach here
}
int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k) << endl;  // Output: 9
    return 0;
}
