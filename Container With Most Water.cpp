#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& v) {
    int maxn = 0;
    int n = v.size();
    int i = 0, j = n - 1;
    
    while(i < j)
    {   
        maxn = max(maxn, (j - i)*(min(v[i], v[j])));
        if(v[i] < v[j])
        {
            i++;
        }
        else{
            j--;
        }
    }

    return maxn;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxArea(v);
    return 0;
}