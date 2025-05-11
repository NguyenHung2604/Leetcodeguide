#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// su dung set de luu gia tri trung
int lengthOfLongestSubstring(string s) {
    unordered_set<int> st;
    int l = 0;
    int maxlen = 0;

    for(int r = 0; r < s.size(); r++)
    {
        while(st.find(s[r]) != st.end())
        {
            st.erase(s[l]);
            l++;
        }

        st.insert(s[r]);
        maxlen = max(maxlen, r - l + 1);
    }

    return maxlen;
}
// su dung map de luu vi tri trung
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int l = 0;
    int maxlen = 0;
    for(int r = 0; r < s.size(); r++)
    {
        if(m.count(s[r]) && m[s[r]] >= l)
        {   
            l = m[s[r]] + 1;
        }
        m[s[r]] = r;
        maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}