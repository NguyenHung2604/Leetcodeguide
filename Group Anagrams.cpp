#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    for(string s : strs)
    {
        string x = s;
        sort(x.begin(), x.end());
        mp[x].push_back(s);
    }

    for(auto it: mp)
    {
        ans.push_back(it.second);
    }
    return ans;
    
}   

int main() {
    return 0;
}
