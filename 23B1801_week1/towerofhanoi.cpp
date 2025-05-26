#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;

    // Move n-1 disks from 'from' to 'aux' using 'to'
    hanoi(n - 1, from, aux, to);

    // Move the nth disk from 'from' to 'to'
    cout << from << " " << to << "\n";

    // Move n-1 disks from 'aux' to 'to' using 'from'
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;

    cout << (1LL << n) - 1 << "\n";  // Minimum moves = 2^n - 1

    hanoi(n, 1, 3, 2);  // Move n disks from stack 1 to 3 using 2

    return 0;
}
