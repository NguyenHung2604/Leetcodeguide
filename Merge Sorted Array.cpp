#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// two pointer
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(j >= 0)
    {
        if(i >= 0 && nums1[i] > nums2[j]) // neu nhu trong 1 cac gia tri khong bang 0
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i < m + n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x); 
    }

    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        v2.push_back(y);
    }

    merge(v1, m, v2, n);
    for(int i : v1)
    {
        cout << i << ' ';
    }

    return 0;
}