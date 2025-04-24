#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    // chia doi ra thanh hai phan, trai va phai cua i, roi nhan lai voi nhau
    vector<int> right(n);
    vector<int> left(n);
    left[0] = 1;
    right[n - 1] = 1;
    for(int i = 1; i < n; i++)
    {
        left[i] = left[i - 1]*nums[i - 1];
    }

    for(int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1]*nums[i + 1]; 
    }

    for(int i = 0; i < n ; i++)
    {
        ans[i] = left[i]*right[i];
    }

    return ans;
}

// follow up
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int cur = 1;
    for(int i = 0; i < n; i++)
    {
        ans[i] *= cur;
        cur*= nums[i];
    }

    cur = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        ans[i] *= cur;
        cur*= nums[i];
    }

    return ans;
}

int main() {
    return 0;
}