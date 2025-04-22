#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    

    int start = 0;
    int total_fuel = 0;
    int tank = 0;
    int n = gas.size();
    for(int i = 0; i < n; i++)
    {
        total_fuel+= gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if(tank < 0)
        {
            tank = 0;
            start = i + 1;
        }
    }

    return (total_fuel < 0) ? -1 : start;
}

int main() {
    return 0;
}