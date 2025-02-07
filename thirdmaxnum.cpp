#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;


int thirdMax1(vector<int>& nums) {
       long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

       for(int i : nums)
       {
            if(i == first || i == second || i == third) continue;

            if( i > first)
            {
                third = second;
                second = first;
                first = i;
            }

            else if( i > second)
            {
                third = second;
                second = i;
            }

            else if(i > third)
            {
                third = i;
            }
            
       }
        return third == LONG_MIN ? first : third;
    }


 int thirdMax2(vector<int>& nums) {
    set <int> st;

    for(int &i : nums)
    {
        if(st.count(i))
        {
            continue;
        } 


        if(st.size() == 3)
        {
            if(i > *st.begin())
            {
                st.erase(*st.begin());
                st.insert(i);
            }
        }
        else{
            st.insert(i);
        }
    }
    
    return st.size() != 3 ? *st.end() : *st.begin();
}

int main()
{

}