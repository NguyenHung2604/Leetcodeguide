#include <iostream>
#include <vector>

using namespace std;
int jump(vector<int>& nums) {
    int jumps = 0;
    int curEnd = 0;
    int furthest = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        furthest = max(furthest, i + nums[i]);
        if(i == curEnd)
        {
            jumps++;
            curEnd = furthest;
        }
    }
    return jumps;
}
    
}
int main() {
    return 0;
}