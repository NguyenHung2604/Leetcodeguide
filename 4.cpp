#include <iostream>
#include <string>
using namespace std;

void sinhxauki(string s, string cur, int length)
{  
    if(cur.size() == length)
    {
        cout << cur << endl;
        return;
    }

    for(char i : s)
    {
        cur.push_back(i);
        sinhxauki(s, cur, length);
        cur.pop_back(); // quay lui
    }
}

int main()
{
    string s;
    cin >> s;
    for(int i = 1; i <= s.size(); i++)
    {
        sinhxauki(s, "", i);
    }
}

