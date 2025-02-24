#include <iostream>
#include <cmath>


using namespace std;

void printArrow(int n, bool left)
{
    if(!left)
    {
        for(int i = n - 1; i >= (1 - n); i--)
        {
            // in dau ' ' 
            for(int c = 1; c <= (n - 1 - abs(i))*2; c++)
            {
                cout << ' ';
            }
            for(int s = 1; s <= abs(i) + 1; s++)
            {
                cout << '*';
            }

            cout << endl;
        }
    }
    else{
        for(int i = n - 1; i >= 1 - n; i--)
        {
            // in dau *
            for(int c = 1; c <= abs(i); c++)
            {
                cout << ' ';
            }
            for(int s = 1; s <= abs(i) + 1; s++)
            {
                cout << '*';
            }

            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    printArrow(n, left);

}