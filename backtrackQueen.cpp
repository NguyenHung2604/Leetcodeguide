#include <iostream>


using namespace std;

int n, cot[100], d1[100], d2[100], x[100];
int dem = 0;


void print()
{
    for(int i = 1; i <= n; i++) 
    {
        for(int y = 1; y <= n; y++)
        {
            if(x[i] == y)
            {
                cout << "Q" << ' ';
            }
            else{
                cout << "*" << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= n; j++)
    {
        if(cot[j] == 0 && d1[i - j + n] == 0 && d2[j + i - 1] == 0)
        {
            cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
            x[i] = j;
            if(i == n)
            {
                print();
                dem++;
            }
            else{
                Try(i + 1);
                // Neu muon chi tim ra 1 cau tra loi thi viet o cho nay cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            }

            cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
        
        }
    }
}

int main()
{
    cin >> n;
    d1[0] = d2[0] = cot[0] = 0; 
    Try(1);
    cout << dem;
}