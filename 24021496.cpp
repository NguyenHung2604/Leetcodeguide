#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int kiemtra(int k, int n)
{
    return (0 <= k && k <= n && n >= 1 && n <= 20);
}

void nhapdulieu(vector<int> &k, vector<int> &n, int soluong)
{
    for (int i = 0; i < soluong; i++)
    {
        cin >> k[i] >> n[i];
    }
}

int C(int k, int n)
{
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return C(k, n - 1) + C(k - 1, n - 1);
}

int main()
{
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);

    int sophantu;
    cin >> sophantu;

    vector<int> k(sophantu), n(sophantu);
    nhapdulieu(k, n, sophantu);

    for (int i = 0; i < sophantu; i++)
    {
        if (!kiemtra(k[i], n[i]))
        {
            continue;
        }
        cout << C(k[i], n[i]) << endl;
    }
    cout << endl;

    return 0;
}
