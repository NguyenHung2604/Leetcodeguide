#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>


using namespace std;
// cach 1: su dung queue, stack
int countStudents1(vector<int>& students, vector<int>& sandwiches) {
        queue <int> q;
        stack <int> st;
        int len = students.size();

        for(int i = 0; i < len; i++)
        {
            q.push(students[i]);
            st.push(sandwiches[len - i - 1]);
        }
        int lastserve = 0; // so nguoi da dc phuc vu nhung khong thanh cong 
        // khi co nguoi bi di chuyen xuong cuoi hang, thi tang lastserve len 1, neu nhu lastserve = len thi co nghia la khong 
        // ai an banh mi do het, end process
        while(!q.empty() && lastserve < q.size())
        {
            if(q.front() == st.top())
            {
                q.pop();
                st.pop();
                lastserve = 0;
            }
            else{
                int front = q.front();
                q.pop();
                q.push(front);
                lastserve++;
            }
        }

        return q.size();
    }

// cach 2: su dung phuong phap dem
int countStudents2(vector<int>& students, vector<int>& sandwiches) 
    {
        int len = students.size();
        int circlestd = 0;
        int squarestd = 0;

        for(int i : students)
        {
            if(i == 0)
            {
                circlestd++;
            }
            else{
                squarestd++;
            }
        }
    // serve sandwiches for std
        for(int i : sandwiches)
        {
            if(i == 0 && circlestd == 0)
            {
                return squarestd;
            }

            if(i == 1 && squarestd == 0)
            {
                return circlestd;
            }

            if(i == 0)
            {
                circlestd--;
            }
            else
            {
                squarestd--;
            }
        }

        return 0;
    }

int main()
{
    int n;
    cin >> n;
    int x, y;
    vector <int> a(n);
    vector <int> b(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);

    }

    for(int i = 0; i < n; i++)
    {
        cin >> y;
        b.push_back(y);
    }



    cout << countStudents1(a, b);
}