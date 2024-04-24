#include <bits/stdc++.h>
using namespace std;

int ctoi(char c);
int calc_int(map<string, int> &mpi);
void define_int(map<string, int> &mpi);
void print_int(map<string, int> &mpi);
vector<int> add(vector<int> left, vector<int> right);
vector<int> subtract(vector<int> left, vector<int> right);
vector<int> calc_vec(map<string, vector<int>> &mpv, map<string, int> &mpi);
void define_vec(map<string, vector<int>> &mpv, map<string, int> &mpi);
void print_vec(map<string, vector<int>> &mpv, map<string, int> &mpi);

int main()
{
    map<string, int> mpi;
    map<string, vector<int>> mpv;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string type;
        cin >> type;
        if (type == "int")
        {
            define_int(mpi);
        }
        else if (type == "print_int")
        {
            print_int(mpi);
        }
        else if (type == "vec")
        {
            define_vec(mpv, mpi);
        }
        else if (type == "print_vec")
        {
            print_vec(mpv, mpi);
        }
        else
        {
            cout << "type error" << endl;
            cout << "error:" << type << endl;
        }
    }
}

int ctoi(char c)
{
    return c - '0';
}

int calc_int(map<string, int> &mpi)
{
    char tmp;
    int value = 0;
    bool flag_add = true;
    while (true)
    {
        cin >> tmp;
        if (isdigit(tmp))
        {
            if (flag_add)
                value += ctoi(tmp);
            else
                value -= ctoi(tmp);
        }
        else if (isalpha(tmp))
        {
            string a = {tmp};
            if (flag_add)
                value += mpi[a];
            else
                value -= mpi[a];
        }
        else if (tmp == '+')
        {
            flag_add = true;
        }
        else if (tmp == '-')
        {
            flag_add = false;
        }
        else if (tmp == ';')
        {
            break;
        }
    }
    return value;
}

void define_int(map<string, int> &mpi)
{
    string name;
    cin >> name;

    mpi[name] = calc_int(mpi);
}

void print_int(map<string, int> &mpi)
{
    cout << calc_int(mpi) << endl;
    ;
}

vector<int> add(vector<int> left, vector<int> right)
{
    if (left.size() != right.size())
    {
        if (left.size() == 0)
        {
            return right;
        }
        else
        {
            cout << "error" << endl;
            return {};
        }
    }
    vector<int> vec;
    for (int i = 0, n = left.size(); i < n; i++)
    {
        vec.push_back(left.at(i) + right.at(i));
    }
    return vec;
}

vector<int> subtract(vector<int> left, vector<int> right)
{
    if (left.size() != right.size())
    {
        if (left.size() == 0)
        {
            return right;
        }
        else
        {
            cout << "error" << endl;
            return {};
        }
    }
    vector<int> vec;
    for (int i = 0, n = left.size(); i < n; i++)
    {
        vec.push_back(left.at(i) - right.at(i));
    }
    return vec;
}

vector<int> calc_vec(map<string, vector<int>> &mpv, map<string, int> &mpi)
{
    string tmp;
    vector<int> vec;
    bool flag = false;
    bool flag_add = true;

    vector<int> tmp_vec;
    while (true)
    {
        cin >> tmp;
        if (flag)
        {
            if (tmp == "]")
            {
                if (flag_add)
                {
                    vec = add(vec, tmp_vec);
                }
                else
                {
                    vec = subtract(vec, tmp_vec);
                }
                flag = false;
                continue;
            }
            else if (isdigit(tmp[0]))
            {
                tmp_vec.push_back(stoi(tmp));
            }
            else if (isalpha(tmp[0]))
            {
                tmp_vec.push_back(mpi[tmp]);
            }
        }
        else
        {
            if (tmp == ";")
            {
                break;
            }
            else if (isalpha(tmp[0]))
            {
                if (flag_add)
                {
                    vec = add(vec, mpv[tmp]);
                }
                else
                {
                    vec = subtract(vec, mpv[tmp]);
                }
            }
            else if (tmp == "+")
            {
                flag_add = true;
            }
            else if (tmp == "-")
            {
                flag_add = false;
            }
            else if (tmp == "[")
            {
                flag = true;
                tmp_vec.clear();
            }
        }
    }

    return vec;
}

void define_vec(map<string, vector<int>> &mpv, map<string, int> &mpi)
{
    string name;
    cin >> name;

    mpv[name] = calc_vec(mpv, mpi);
}

void print_vec(map<string, vector<int>> &mpv, map<string, int> &mpi)
{
    vector<int> vec = calc_vec(mpv, mpi);
    cout << "[ ";
    for (int i = 0, n = vec.size(); i < n; i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}