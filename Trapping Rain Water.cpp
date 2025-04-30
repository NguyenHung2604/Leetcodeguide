#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;


// cach 1: two pointers
int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int max_left = 0, max_right = 0;
    int water = 0;
    while(l < r)
    {
       if(height[l] < height[r])
       {
            if(height[l] >= max_left)
            {
                max_left = height[l];
            }
            else{
                water += max_left - height[l];
            }
            l++;
       }
       else{
            if(height[r] >= max_right)
            {
                max_right = height[r];
            }
            else{
                water += max_right - height[r];
            }
            r--;
       }

    }
    return water;
}

// cach 2: dynamic programing
int trap2(vector<int>& h) {
    int n = h.size();
    vector<int> maxleft(n);
    vector<int> maxright(n);
    int water = 0;
    maxleft[0] = 0;
    int max_left = 0;
    maxright[n - 1] = 0;
    int max_right = 0;
    for(int i = 1; i < n; i++)
    {
        max_left = max(max_left, h[i - 1]);
        maxleft[i] = max_left;
    }

    for(int i = n - 2; i >= 0; i--)
    {
        max_right = max(max_right, h[i + 1]);
        maxright[i] = max_right;
    }

    for(int i = 0; i < n; i++)
    {
        if(h[i] < min(maxright[i], maxleft[i]))
        {
            water += min(maxright[i], maxleft[i]) - h[i];
        }
        else{
            continue;
        }
    }
    return water;
}

// cach 3: Monotonic stack
int trap3(vector<int>& height) {
    stack<int> st;
    int water = 0;
    for(int i = 0; i < height.size(); i++)
    {
        while(!st.empty() && height[i] > height[st.top()])
        {
            int bottom = st.top();
            st.pop();

            if(st.empty()) break;

            int left = st.top();
            int width = i - left - 1;
            
            int bounded_height = min(height[left], height[i]) - height[bottom];
            water += width*bounded_height;

        }
        st.push(i);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++)
    {
        cin >> v[i];
    }

    cout << trap2(v);
    return 0;
}