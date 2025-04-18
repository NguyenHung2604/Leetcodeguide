#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& c) {
    sort(c.begin(), c.end(), greater<int> ());
    int res = 0;
    for(int i = 0; i < c.size(); i++)
    {
        if(c[i] >= i + 1)
        {
            res = i + 1;
        }
        else{
            break;
        }
    }
    return res;
}

int main() {
    return 0;
}