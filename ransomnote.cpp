#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;
    for(char s : magazine)
    {
        mp[s]++;
    }

    for(char s : ransomNote)
    {
        if(mp.find(s) != mp.end())
        {
            mp[s]--;
        }
        else{
            return false;
        }
    }

    return true;
}

bool isIsomorphic(string s, string t) {
    unordered_map<char, int> mps;
    unordered_map<char, int> mpt;
    if(s.size() != t.size()) return false;

    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(mps.find(s[i]) == mps.end())
        {
            mps[s[i]] = i;
        }

        if(mpt.find(t[i]) == mpt.end())
        {
            mpt[t[i]] = i;
        }

        if(mps[s[i]] != mpt[t[i]])
        {
            return false;
        }
    }
    return true;
}

bool wordPattern(string pattern, string s) {
    unordered_map<char, int> mpp;
    unordered_map<string, int> mps;
    int n = pattern.size();   
    stringstream ss(s);
    string word;
    int i = 0;
    while(ss >> word)
    {
        if(mpp.find(pattern[i]) == mpp.end())
        {
            mpp[pattern[i]] = i;
        }

        if(mps.find(word) == mps.end())
        {
            mps[word] = i;
        }

        if(mps[word] != mpp[pattern[i]])
        {
            return false;
        }
        i++;
        
    }

    return i == n ? true : false;
    
}

int main() {
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    cout << wordPattern(s, t);
    return 0;
}