#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    int max_cnt = 0;
    int ans = 0;
    for (auto p : mp)
    {
        int a, b;
        tie(a, b) = p;
        if (b > max_cnt)
        {
            max_cnt = b;
            ans = a;
        }
    }
    cout << ans << " " << max_cnt << endl;
}