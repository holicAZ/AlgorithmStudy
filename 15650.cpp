#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    vector<bool> v(n);
    fill(v.begin(), v.begin() + m, 1);

    do {
        for (int i = 0; i < v.size(); i++) {
            if (v[i])
                cout << i + 1 << " ";
        }
        cout << "\n";
    } while (prev_permutation(v.begin(), v.end()));
    
    return 0;
}