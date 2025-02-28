#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return NULL;
    
    ListNode *cur = head;
    ListNode *tmp = NULL;   
    while(cur != NULL && cur -> next != nullptr)
    {
        if(cur -> val == cur -> next -> val)
        {
            tmp = cur ->next ->next;
            cur -> next = tmp; 
        }
        else{
            cur = cur -> next;
        }
    }
    return head;
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

    head = deleteDuplicates(head);

    for(ListNode *x = head; x != nullptr; x = x->next)
    {
        cout << x -> val << ' ';
    }
    cout << endl;
    
}