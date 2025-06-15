#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return true if using 'div' as divisor makes the total sum <= threshold
    bool check(const vector<int>& nums, int div, int threshold) {
        long long sum = 0;
        for (int x : nums) {
            // ceil division: (x + div - 1) / div
            sum += (x + div - 1) / div;
            if (sum > threshold) 
                return false;  // early exit
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        // binary search for the smallest good divisor
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(nums, mid, threshold)) {
                hi = mid;  // mid works, try smaller
            } else {
                lo = mid + 1;  // mid too small, increase
            }
        }
        return lo;
    }
};

int main() {
    Solution sol;
    // Example 1
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << sol.smallestDivisor(nums1, threshold1) << "\n";  // 5

    // Example 2
    vector<int> nums2 = {2, 3, 5, 7, 11};
    int threshold2 = 11;
    // Answer is 3.
    cout << sol.smallestDivisor(nums2, threshold2) << "\n";  // 3

    return 0;
}
