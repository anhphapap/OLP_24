#include <bits/stdc++.h>

using namespace std;

string start = "XVXVXVTXT";
string goal = "TTTTTTTTT";
string robot[9] = {
    "159",
    "123",
    "357",
    "147",
    "5",
    "369",
    "456",
    "789",
    "258",
};

vector<int> state(9, 0), bestState;
int bestAns = INT_MAX, ans = 0;

void fillColor(string &s, int id)
{
    for (int i = 0; i < robot[id].length(); i++)
    {
        int j = (robot[id][i] - '0') - 1;
        switch (s[j])
        {
        case 'T':
            s[j] = 'X';
            break;
        case 'X':
            s[j] = 'V';
            break;
        case 'V':
            s[j] = 'T';
            break;
        }
    }
}

int chooseRobot()
{
    int maxT = -1, j = -1;
    for (int i = 0; i < 9; i++)
    {
        if (state[i] < 2)
        {
            string s1 = start;
            fillColor(s1, i);
            int counter = (int)count_if(s1.begin(), s1.end(), [](char x)
                                        { return x == 'T'; });
            if (counter > maxT)
            {
                maxT = counter;
                j = i;
            }
        }
    }
    return j;
}

void process()
{
    int j = chooseRobot();
    if (j >= 0)
    {
        fillColor(start, j);
        state[j]++;
        ans++;
        if (start == goal && ans < bestAns)
        {
            bestAns = ans;
            bestState = state;
        }
        else
            process();
        ans--;
        state[j]--;
    }
}

void output()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < bestState[i]; j++)
            cout << i + 1;
}

int main()
{
    process();
    output();
    return 0;
}