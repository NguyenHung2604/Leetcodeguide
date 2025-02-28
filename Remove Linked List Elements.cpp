#include <iostream>


using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x) ,  next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *newhead = nullptr;
    ListNode *newtail = nullptr;
    ListNode *cur = head;
    while(cur != nullptr)  
    {
        if(cur -> val != val)
        {
            ListNode *newnode = new ListNode(cur -> val);
            if(newhead == nullptr)
            {
                newhead = newnode;
                newtail = newnode;
            }
            else{
                newtail ->next = newnode;
                newtail = newnode;
            }
        }
        cur = cur -> next;
    }
    return newhead;
}   

int main()
{
    //implement a listnode from keyboard input
    int n;
    cin >> n;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *p = new ListNode(x);
        if(head == nullptr)
        {
            head = p;
            tail = p;
        }
        else{
            tail->next = p;
            tail = p;
        }
    }

    head = removeElements(head, 7);

    for(ListNode *x = head; x != nullptr; x = x->next)
    {
        cout << x -> val << ' ';
    }
    cout << endl;
}