#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
        sum += vec.at(i);
    }
    int mean = sum / N;

    for (int i = 0; i < N; i++) {
        cout << max(mean - vec.at(i), vec.at(i) - mean) << endl;
    }

    return 0;
}