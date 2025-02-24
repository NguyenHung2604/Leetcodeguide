#include<iostream>
#include <cmath>
using namespace std;

void printMaxSUM(int a[], int n, int k)
{
    int l = 0, r = k - 1;
    int maxsum = 0;
    int sum = 0;
    
    for(int i = l; i <= r; i++)
        {
            sum += a[i];
        }
        

    while (r < n - 1)
    {
        sum = sum - a[l];
        l++;
        r++;
        sum = sum + a[r];
        maxsum = max(sum, maxsum);
    }
    cout << maxsum << ' ';
}


int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printMaxSUM(a, n, k);
}