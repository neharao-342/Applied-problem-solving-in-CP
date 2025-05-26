#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int max_count = 1, count = 1;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count > max_count)
                max_count = count;
        } else {
            count = 1;
        }
    }

    cout << max_count << endl;
    return 0;
}
