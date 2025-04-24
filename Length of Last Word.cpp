#include <iostream>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();
    int dem = 0;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == ' ')
        {
            if(dem == 0)
            {
                continue;
            }
            else 
            {
                break;
            }
        }
        dem++;    
    }

    return dem;
}

int main() {
    string s;
    getline(cin, s);
    cout << lengthOfLastWord(s);
    return 0;
}