#include <iostream>
#include <cmath>


using namespace std;
// Solution 1: Sum of odd numbers
bool isPerfectSquare(int num) {
        int tong = 0;
        for(int i = 1; i <= 2*sqrt(num) - 1; i+= 2)
        {
            tong += i;
        }

        return tong == num;
}

// Solution 2:
bool isPerfectSquare(int num)
{
    int n =  sqrt(num);
    return n*n == num;
} 

int main()
{

}