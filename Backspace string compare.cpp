#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
// su dung vong lap for
class Solution1  {
    public:
        bool backspaceCompare(string s, string t) {
            s = completestring(s);
            t = completestring(t);
            return s == t;
        }

    private:
        string completestring(string s)
        {   string a;
            int count = 0;
            for(int i = s.size() - 1; i >= 0; i--)
            {
                if(s[i] == '#')
                {
                    count++;
                }
                else if(count > 0)
                {
                    count--;
                }
                else{
                    a = s[i] + a;
                }
            }

            return a;
        }
    };

// su dung stack
class Solution2 {
    public:
        bool backspaceCompare(string s, string t) {
            stack <char> s1;
            stack <char> s2;

            for(int i : s)
            {
                if(i != '#')
                {
                    s1.push(i);
                }
                else if(!s1.empty())
                {
                    s1.pop();
                }
            }


            for(int i : t)
            {
                if(i != '#')
                {
                    s2.push(i);
                }
                else if(!s2.empty())
                {
                    s2.pop();
                }
            }

            return s1 == s2;
        }

    
};

//cach 3: Optimize
class Solution {
    public:    
    bool backspaceCompare(string s, string t)
        {
            s = process(s);
            t = process(t);
            int i = s.size() - 1, j = t.size() - 1;
            if(i != j) return false;
            while(i >= 0 && j >= 0)
            {
               if(s[i] != t[j])
               {
                    return false;
               }
               else{
                    j--;
                    i--;
               }
            }
            return true;
        }

    private:
    string process(string s)
    {
        string a;
        int i = s.size() - 1;
        int skip = 0;
        while(i >= 0)
        {
            if(s[i] == '#')
            {
                skip++;
            }
            else if(skip > 0)
            {
                skip--;
            }
            else
            {
                a = s[i] + a;
            }
            i--;
        }

        return a;
    }
};




int main()
{
    string s, t;
    cin >> s >> t;

    
}