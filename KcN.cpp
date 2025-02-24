#include <iostream>

using namespace std;
int n, x[100], k;

void inkq()
{
    for(int i = 1; i <= k; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void dequy(int i)
{   // x[i] <= n - k + i and x[i] >= X[i - 1] + 1
    for(int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if(i == k)
        {
            inkq();
        }
        else{
            dequy(i + 1);
        }
    }
}

int main()
{
    cin >> n >> k;

    dequy(1);
}