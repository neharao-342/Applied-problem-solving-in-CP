#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns how many days are needed if ship capacity = cap
    int daysNeeded(const vector<int>& weights, int cap) {
        int days = 1;
        int currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > cap) {
                days++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // Lower bound = heaviest package
        int low = *max_element(weights.begin(), weights.end());
        // Upper bound = sum of all weights
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        // Binary search for minimum capacity
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (daysNeeded(weights, mid) <= days) {
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

    int n, days;
    // Read number of packages and allowed days
    cin >> n >> days;
    
    vector<int> weights(n);
    // Read weights
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    Solution sol;
    int answer = sol.shipWithinDays(weights, days);
    
    cout << answer << "\n";
    return 0;
}
