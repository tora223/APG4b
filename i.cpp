#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, price;
    cin >> p;

    if (p == 1) {
        cin >> price;
    } else if (p == 2) {
        string text;
        cin >> text >> price;
        cout << text << "!" << endl;
    }

    int N;
    cin >> N;
    cout << N * price << endl;

    return 0;
}