#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    
    int g = nums.size() - 1;
    for(int i = g - 1; i >= 0; i--)
    {
        if(i + nums[i] >= g)
        {
            g = i;
        }
    }
    return g == 0;
    // tra ve true neu nhu g trung voi 0;
    // y tuong: chay nguoc ve 0
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << canJump(v);
    return 0;
}