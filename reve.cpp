#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    char *a = new char[11];
    cin.getline(a, 11);
    cout << strlen(a);
    return 0;
}