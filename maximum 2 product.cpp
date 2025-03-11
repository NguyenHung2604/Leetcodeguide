#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

// cach 1: su dung pair
int maxProduct(vector<int>& nums) {
    vector<pair<int,int>> v;
    for(int i = 0; i < nums.size(); i++)
    {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());

    return (v[nums.size() - 1].first - 1)*(v[nums.size() - 2].first - 1);
}

// cach 2: su dung priortity queue / heap

int maxProduct(vector<int>& nums)
{
    priority_queue <int> maxheap;
    for(int i : nums)
    {
        maxheap.push(i);
    }

    int x1 = maxheap.top();
    maxheap.pop();
    int x2 = maxheap.top();
    maxheap.pop();
    return (x1 - 1)*(x2 - 1);
}
// cach 3; trau bo nhung thong minh
int maxProduct(vector <int> &nums)
{   int max1 = 0;
    int max2 = 0;
    for(int i : nums)
    {
        if(i >= max1)
        {
            max2 = max1;
            max1 = i; // max2 phai duoc gan bang max 1 truoc de khong bi mat gia tri
        }
        else if(i > max2)
        {
            max2 = i;
        }
    }
    return (max1 - 1)*(max2 - 1);
}

int main()
{

}