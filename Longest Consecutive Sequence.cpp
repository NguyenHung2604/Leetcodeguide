#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    unordered_map<int, int> table;
    int longest = 0;
    
    for(int i : st)
    {
        if(table.count(i)) continue;

        int left = table.count(i - 1) ? table[i - 1] : 0;
        int right = table.count(i + 1) ? table[i + 1] : 0;

        int length = left + right + 1;

        table[i] = length;
        table[i - left] = length;
        table[i + right] = length;
        longest = max(longest, length);
    }

    return longest;
        
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << longestConsecutive(v);
    return 0;
}