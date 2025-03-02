#include <iostream>
#include <string> 
// liet ke tat ca cac hoan vi tu mot xau tu ban phim  
using namespace std;
string ans = "";
int check[100] = {};

void sinhhoanvi(string &s)
{
    for(int i = 0; i < (int) s.size(); i++)
    {
        if(check[i] == 1) continue;
        ans += s[i];
        check[i] = 1;
        if(ans.size() == s.size())
        {
            cout << ans << endl;
        }
        else{
            sinhhoanvi(s);
        }
        check[i] = 0;
        ans.pop_back();
    }
}

int main()
{
    string s;
    cin >> s;
    sinhhoanvi(s);

}