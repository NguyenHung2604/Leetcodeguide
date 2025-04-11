#include <iostream>
#include <vector>
using namespace std;

vector <int> insertionbi(vector <int> &s)
{
    for(int j = 1; j <= s.size() - 1; j++)
    {   int pos;
        int x = s[j];
        int l = 1;
        int r = j - 1;
        while (l <= r)
        {
            int mid = (l + r)/2;
            if(s[mid] > x) l = mid + 1;
            else if(s[mid] > x) r = mid;

            if(x <= s[l])
            {
                pos = l + 1;
            }
            else{
                pos = l;
            }
        }

        for(int k = j; k > pos; k--)
        {
            s[k + 1] = s[k];
        }
        s[pos] = x;

    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {   int x;
        cin >> x;
        v.push_back(x);
    }

    v = insertionbi(v);
    for(int i : v)
    {
        cout << i << ' ';
    }

}