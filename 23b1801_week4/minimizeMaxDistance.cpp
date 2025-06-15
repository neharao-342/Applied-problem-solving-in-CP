#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        string cur = x;
        for (int op = 0; op <= 7; ++op) {
            if (cur.find(s) != string::npos) {
                cout << op << endl;
                goto next_testcase;
            }
            cur += cur;  // Apply operation
        }
        cout << -1 << endl;
    next_testcase:;
    }
    return 0;
}
