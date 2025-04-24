#include <iostream>
#include <vector>

using namespace std;


string convert(string s, int numRows) {
    if(numRows == 1 || numRows >= s.size())
    {
        return s;
    }   
    int idx = 0;
    int d = 1; // cong them
    vector<vector<int>> rows(numRows);

    for(char i : s)
    {   
        rows[idx].push_back(i);
        if(idx == 0)
        {
            d = 1;
        }
        else if(idx == numRows - 1)
        {
            d = -1;
        }
        idx += d;
    }
    string ans;

    for(const auto &it : rows)
    {
        for(char i : it)
        {
            ans = ans + i;
        }
    }
    return ans;
}

string convert(string s, int numRows) {
    if(numRows == 1 || numRows >= s.size())
    {
        return s;
    }
    string res;
    const int step = numRows + numRows - 2;
    for(int i = 0; i < numRows; i++)
    {  
         int idx = i;
        while(idx < s.size())
        {   
            res += s[idx];
            idx += step;
            if(i > 0 && i < numRows - 1)
            {   if(idx - i*2 < s.size()){
                res += s[idx - i*2];
            }
            }
        }
    }
    return res;
}
int main() {
    return 0;
}