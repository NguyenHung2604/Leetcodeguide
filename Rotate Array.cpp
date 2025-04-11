#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // de phong truong hop k > n;
    vector<int> v;
    for(int i = n - k; i < n; i++)
    {
        v.push_back(nums[i]); 
    }
    for(int i = 0; i < n - k; i++)
    {
        v.push_back(nums[i]);
    }

    for(int i = 0; i < n; i++)
    {
        nums[i] = v[i];
    }
}
// cach 2, su dung sorting
void lotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}
// cach 3, su dung 

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    rotate(v, k);

    for(int i : v)
    {
        cout << i << ' ';
    }
    return 0;

}