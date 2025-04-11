#include <iostream>
#include <vector>

using namespace std;
vector<int> pre, suf;
int maxSubArray(vector<int>& nums) {
    pre = suf = nums;
    for(int i = 1; i < size(nums); i++)
    {
        pre[i] += max(0, pre[i - 1]);
    }  
    for(int i = nums.size() - 2; i >= 0; i--)
    {
        suf[i] += max(0, suf[i + 1]);
    }
    return maxSubArray(nums, 0, size(nums) - 1);
}

int maxSubArray(vector<int>& A, int left, int right)
{
    if(left == right) return A[left];
    int mid = (left + right)/2;
    return max({maxSubArray(A, left, mid), maxSubArray(A, mid+1, right), pre[mid] + suf[mid + 1]});
}



int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << maxSubArray(v);
}