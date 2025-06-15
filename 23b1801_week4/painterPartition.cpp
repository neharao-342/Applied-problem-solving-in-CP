#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return true if all boards can be painted within 'maxTime'
    // using at most k painters
    bool canPaint(const vector<int>& boards, int k, long long maxTime) {
        int painters = 1;
        long long currentLoad = 0;
        for (int length : boards) {
            // If a single board exceeds maxTime, impossible
            if (length > maxTime) return false;
            
            if (currentLoad + length > maxTime) {
                // Assign next painter
                painters++;
                currentLoad = length;
                if (painters > k) return false;
            } else {
                currentLoad += length;
            }
        }
        return true;
    }

    long long minTime(vector<int>& boards, int k) {
        long long low = 0, high = 0;
        for (int b : boards) {
            low = max(low, (long long)b);
            high += b;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canPaint(boards, k, mid)) {
                high = mid;      // mid works, try smaller
            } else {
                low = mid + 1;   // mid too small, increase
            }
        }
        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    // n = number of boards, k = number of painters
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    Solution sol;
    cout << sol.minTime(boards, k) << "\n";
    return 0;
}
