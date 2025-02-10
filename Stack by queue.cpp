#include <iostream>
#include <queue>

using namespace std;
// Way 1: Using one queue
class MyStack {
    private:
    queue <int> q;


    public:
        MyStack() {
            
        }
        
        void push(int x) {
            q.push(x);
            for(int i = 0; i < q.size() - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int top = q.front();
            q.pop();
            return top;
        }
        
        int top() {
            
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
    
    class MyStack {
        private:
        queue <int> q1;
        queue <int> q2;
    
    
        public:
            MyStack() {
                
            }
            
            void push(int x) {
                q1.push(x);
            }
            
            int pop() {
                while(q1.size() > 1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                int top = q1.front();
                q1.pop();
                swap(q1, q2);
                return top;

            }
            
            int top() {
                while(q1.size() > 1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                int top = q1.front();
                q2.push(q1.front());
                q1.pop();
                swap(q1, q2);
                return top;
            }
            
            bool empty() {
                return q1.empty() && q2.empty();
            }
        };

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */
// Way 2: using 2 queues

int main()
{

}