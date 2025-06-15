#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns true if we can split into ≤ k subarrays
    // so that no subarray sum exceeds 'maxSum'
    bool canSplit(const vector<int>& nums, int k, long long maxSum) {
        int count = 1;
        long long currentSum = 0;
        for (int x : nums) {
            if (currentSum + x > maxSum) {
                // cut here, start new subarray
                count++;
                currentSum = 0;
            }
            currentSum += x;
        }
        return count <= k;
    }

    long long splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int x : nums) {
            lo = max(lo, (long long)x);
            hi += x;
        }

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) {
                hi = mid;      // mid works, try smaller
            } else {
                lo = mid + 1;  // mid too small, increase
            }
        }

        return lo;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    // Read n = nums.size(), k = number of subarrays
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.splitArray(nums, k) << "\n";
    return 0;
}
