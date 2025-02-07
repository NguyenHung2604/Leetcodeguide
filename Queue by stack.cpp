#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class MyQueue {
    private:

    stack <int> t1, t2;
    
    // chuyen doi tu stack 1 sang stack 2
    void transfer(){
        while(!t1.empty())
        {
            t2.push(t1.top());
            t1.pop();
        }
    }

    public:

    void push(int x)
    {
        t1.push(x);
    }


    int pop()
    {
        if(t2.empty())
        {
            transfer();
        }

        int top_element = t2.top();
        t2.pop();

        return top_element;
    }

    int peek()
    {
        if(t2.empty())
        {
            transfer();
        }
        return t2.top();
    }


    bool empty()
    {
        return t1.empty() && t2.empty();
    }
};

int main()
{

}