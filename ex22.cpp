#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.at(i) = make_pair(b, a);
    }
    sort(vec.begin(), vec.end());
    for (auto p : vec) {
        cout << p.second << " " << p.first << endl;
    }
}