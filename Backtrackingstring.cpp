#include <iostream>
#include <string>


using namespace std;

int n,k;
char x[100] = {};

void kq()
{
    for(int i = 1; i <= k; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void dequy(int i)
{
    for(char j = 'a'; j <= 'a' + n - 1; j++)
    {
        x[i] = j;
        if(i == k)
        {
            kq();
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