#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool isSubsequence(string s, string t) {
    if(s.size() > t.size()) return false;

    int i = 0, j = 0;
    while(i < s.size() && j < t.size())
    {
        if(s[i] == t[j])
        {
            i++;
        }

        j++;
    }

    return i == s.size() ? 1 : 0;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << isSubsequence(a, b);
    return 0;
}