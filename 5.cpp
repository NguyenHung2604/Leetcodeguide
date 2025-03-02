#include <iostream>
#include <algorithm>
using namespace std;
bool check[200] = {0}; 
string ans = "";
void sinhchuoic1(string s, string cur, int length)
{   
    if(cur.size() == length)
    {
        cout << cur << ' ';
        return;
    }

    for(char i : s)
    {
        sinhchuoic1(s, cur + i, length);
    }
}


void sinhchuoic2(string s, string cur)
{   
    if(cur.size() == 2 || cur.size() == 3)
    {
        cout << cur << endl;
        if(cur.size() == 3) return;
    }
    

    for(int i = 0; i < s.size(); i++)
    {
        if(!check[s[i]])
        {
            cur.push_back(s[i]);
            check[s[i]] = true;

            // goi de quy ngay lap tuc
                sinhchuoic2(s, cur);
                check[s[i]] = false;
                cur.pop_back();
        }

    }
}

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    sinhchuoic2(s, "");
    return 0;
}