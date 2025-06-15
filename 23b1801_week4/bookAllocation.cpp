#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if it's possible to allocate books so that no student
    // reads more than 'maxPages' pages, using at most k students.
    bool canAllocate(const vector<int>& arr, int k, long long maxPages) {
        int students = 1;
        long long currentSum = 0;
        for (long long pages : arr) {
            if (pages > maxPages) 
                return false;  // single book exceeds maxPages
            if (currentSum + pages > maxPages) {
                // assign to next student
                students++;
                currentSum = pages;
                if (students > k) 
                    return false;
            } else {
                currentSum += pages;
            }
        }
        return true;
    }

    // Binary-search the minimal maximum-pages
    long long findMinimumPages(const vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) 
            return -1;  // fewer books than students

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long answer = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canAllocate(arr, k, mid)) {
                answer = mid;
                high = mid - 1;  // try for a smaller maximum
            } else {
                low = mid + 1;   // need to allow a larger maximum
            }
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    // Read number of books and number of students
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    long long result = sol.findMinimumPages(arr, k);
    cout << result << "\n";

    return 0;
}
