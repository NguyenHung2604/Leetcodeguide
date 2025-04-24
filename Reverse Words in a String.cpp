#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    vector<string> v;
    stringstream ss(s);
    string word;
    while(ss >> word)
    {
        v.push_back(word);
    }

    string ans = "";
    for(int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i];
        if(i > 0)
        {
            ans += " ";
        }
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s);
    return 0;
}