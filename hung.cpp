#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

//Bo sung code o day. Phan ham main() co san o cho khac va khong sua doi duoc
void sort(float array[], int size, bool isAscending)
{
    if(isAscending)
    {
        sort(array, array + size);
    }
    else
    {
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(array[i] <= array[j])
                {
                    swap(array[i], array[j]);
                }
            }
        }
    }
}

int main()
{
    
}