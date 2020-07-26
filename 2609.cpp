#include <iostream>
using namespace std;
int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}
int LCN(int a, int b) {
    int c = GCD(a, b);
    return a * b / c;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    cout << GCD(n, m) << "\n" << LCN(n, m);
}