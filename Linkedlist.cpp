#include <iostream>
#include <vector>
using namespace std;


class listNode
{  
public:   
    int val;
    listNode *next;
    listNode(int x) : val(x), next(NULL) {}
};


listNode *create_a_linkedlist(vector <int> &v)
{
    if(v.empty())
    {
        return nullptr;
    }

    listNode *head = new listNode(v[0]);
    listNode *cur = head;
    
    for(int i = 1; i < v.size() ; i++)
    {
        cur -> next = new listNode(v[i]);
        cur = cur -> next;
    }

    return head;
}



int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    listNode *head = create_a_linkedlist(v);


    int y;
    cin >> y;
    
    listNode* p = head;    
    for(int i = 0; i < n/2; i++)
    {
        p = p->next;
    }

    listNode *newnode = new listNode(y);
    newnode -> next = p -> next;
    p->next = newnode;

    for(listNode *p = head; p != nullptr; p = p ->next)
    {
        cout << p->val << ' ';
    }
    cout << endl;

        // Giải phóng bộ nho
    while(head != nullptr)
    {
        listNode *p = head;
        head = head -> next;
        delete p;
    }
    return 0;
}