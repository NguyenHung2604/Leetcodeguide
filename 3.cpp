#include <iostream>
#include <string>

using namespace std;


void sinhchuoi(int x, int y, int n, int m)
{
    static string s("");
    
    if(x == n && y == m)
        {   
            cout << s << endl;
            return;
        }
    if(x > n || y > m) return;
    for(char i = '0'; i <= '1'; i++)
    {
        s += i;
        if(i == '0') // nho cai cho sai nay
        {
            sinhchuoi(x + 1, y, n, m);
        }
        else{
            sinhchuoi(x, y + 1, n, m);
        }
        s.pop_back();
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    sinhchuoi(0, 0, n, m);
}