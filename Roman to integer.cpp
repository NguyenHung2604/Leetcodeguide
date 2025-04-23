#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    int tong = 0;
    unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    for(int i = s.size() - 1; i >= 0; i--)
    {   
        if(mp[s[i]] < mp[s[i + 1]])
        {
            tong -= mp[s[i]];
        }
        else{
            tong += mp[s[i]];
        }
    }

    return tong;
}

int main() {
    string s;
    cin >> s;
    cout << romanToInt(s);
    return 0;
}