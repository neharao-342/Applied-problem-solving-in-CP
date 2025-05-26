#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        int x;
        cin >> x;
        actual_sum += x;
    }

    cout << expected_sum - actual_sum << endl;
    return 0;
}