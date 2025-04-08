#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int removeDuplicates(vector<int>& nums) {
   int j = 1;
   // phan tu dau tien luon duy nhat, khong phai xet
   for(int i = 1; i < nums.size(); i++)
   {
        if(nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
   }
   return j;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << removeDuplicates(v) << endl;
    for(int i : v)
    {
        cout << i << ' ';
    }
    return 0;
}