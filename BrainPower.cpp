#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    return 0;
}

long long f(int index, vector<vector<int>> &questions, map<int, long long> &memo) {
    if (index >= questions.size()) {
        return 0;
    }
    if (memo.count(index)) {
        return memo[index];
    }
    long long take = questions[index][0] + f(index + questions[index][1] + 1, questions, memo);
    long long skip = f(index + 1, questions, memo);
    return memo[index] = max(take, skip);
}