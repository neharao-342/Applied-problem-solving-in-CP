#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Helper function to check if we can make 'm' bouquets by 'day'
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if ((long long)bloomDay.size() < totalNeeded) {
            return -1;  // Not enough flowers
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;
                high = mid - 1; // Try to find earlier possible day
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};
int main() {
    Solution sol;
    // Example 1:
    vector<int> bloom = {1,10,3,10,2};
    cout << sol.minDays(bloom, 3, 1) << "\n";  // expected 3

    // Example 2:
    bloom = {1,10,3,10,2};
    cout << sol.minDays(bloom, 3, 2) << "\n";  // expected -1


    return 0;
}
