#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int *a, int n);


int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i : a)
    {
        cin >> i;
    }
    insertionSort(a, n);
    
    for(int i : a)
    {
        cout << i << ' '; 
    }

}

void insertionSort(int *a, int n)
{
    for(int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
        cout << endl;
    }
}