#include <bits/stdc++.h>
using namespace std;

void sinhchuoic2(string &s, string cur, int length) {   
    if (cur.size() == length) {
        cout << cur << endl;
        return;
    }

    for (char c : s) { // Duyệt từng ký tự trong chuỗi input
        cur.push_back(c);
        sinhchuoic2(s, cur, length); // Gọi đệ quy tiếp tục sinh chuỗi
        cur.pop_back(); // Quay lui
    }
}

void generateWords(string &s) {
    sinhchuoic2(s, "", 2);
    sinhchuoic2(s, "", 3);
}

int main() {
    string s;
    cin >> s;

    generateWords(s);

    return 0;
}