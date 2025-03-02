// Sinh chuoi nhi phan co do dai la n
#include <iostream>     
#include <string>
#include <vector>   

using namespace std;
string s = "";
void sinhchuoi(int n)
{   
    
    for(char i = '0'; i <= '1'; i++)
    {
        s += i;
        if((int) s.size() == n)
        {
            cout << s << endl;
        }
        else{
            sinhchuoi(n);
        }
        s.pop_back();
    }
    
}

int main()
{
    int n;
    cin >> n;
    sinhchuoi(n);
}