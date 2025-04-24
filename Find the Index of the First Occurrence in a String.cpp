#include <iostream>
#include <vector>


using namespace std;

int strStr(string haystack, string needle) {
    int h = haystack.size();
    int n = needle.size();
    
    if(h < n) return -1;
    
    for(int i = 0; i <= h - n; i++)
    {
        if(haystack[i] == needle[0])
        {
            bool found = true;
            for(int j = 1; j < n; j++)
            {
                if(haystack[i+j] == needle[j])
                {
                    found = false;
                    break;
                }
            }
            if(found) return i;
        } 
    }
    return -1;
}

int main() {
    string a;
    string b;
    cin >> a >> b;
    cout << strStr(a, b);
    
    return 0;
}