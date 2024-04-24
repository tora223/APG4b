#include <bits/stdc++.h>
using namespace std;

int count_report_num(vector<vector<int>> &children, int x);

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);
    p.at(0) = -1;
    for (int i = 1; i < N; i++) {
        cin >> p.at(i);
    }

    vector<vector<int>> children(N);
    for (int i = 1; i < N; i++) {
        int parent = p.at(i);
        children.at(parent).push_back(i);
    }

    for (int i = 0; i < N; i++) {
        cout << count_report_num(children, i) << endl;
    }
}

int count_report_num(vector<vector<int>> &children, int x)
{
    int report_num = 1;
    if (children.at(x).size() == 0) {
        return report_num;
    }

    for (int i = 0, n = children.at(x).size(); i < n; i++) {
        report_num += count_report_num(children, children.at(x).at(i));
    }
    return report_num;
}