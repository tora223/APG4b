#include <bits/stdc++.h>
using namespace std;

struct Clock
{
    int hour, minute, second;

    void set(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    string to_str()
    {
        string h = to_string(hour);
        string m = to_string(minute);
        string s = to_string(second);

        if (h.size() == 1)
            h = "0" + h;
        if (m.size() == 1)
            m = "0" + m;
        if (s.size() == 1)
            s = "0" + s;

        return h + ":" + m + ":" + s;
    }

    void shift(int diff_second)
    {
        if ((second + diff_second) >= 0)
        {
            second += diff_second;
            minute += second / 60;
            second %= 60;
            hour += minute / 60;
            minute %= 60;
            hour %= 24;
        }
        else
        {
            second += diff_second;
            minute += second / 60;
            second %= 60;
            if (second < 0)
            {
                minute--;
                second += 60;
            }
            hour += minute / 60;
            minute %= 60;
            if (minute < 0)
            {
                hour--;
                minute += 60;
            }
            hour %= 24;
            if (hour < 0)
                hour += 24;
        }
    }
};

int main()
{
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;

    Clock clock;

    clock.set(hour, minute, second);
    cout << clock.to_str() << endl;
    clock.shift(diff_second);
    cout << clock.to_str() << endl;
}