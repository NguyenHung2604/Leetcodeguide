#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// su dung sorting
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    // su dung truc giac, vi cai phan tu do se luon xuat hien o giua
    sort(nums.begin(), nums.end());
    return nums[n/2];
}
// su dung Boyer-Moore Algorithm
int major(vector<int> &nums)
{
    int cnt = 0;
    int n = nums.size();
    int candidate = 0;
    for(int i : nums)
    {
        if(cnt == 0)
        {
            candidate = i;
        }
        
        cnt += (candidate == i ? 1 : -1);
        
    }
    return candidate;
}
// Divide and conquer
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

    cout << majorityElement(v);
    return 0;
}