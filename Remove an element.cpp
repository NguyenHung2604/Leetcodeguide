#include <iostream>
#include <vector> 
using namespace std;

class ListNode
{   
public:    
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Tạo danh sách liên kết từ vector
ListNode *createLinkedList(vector<int> &v)
{
    if (v.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(v[0]);
    ListNode *cur = head;

    for (int i = 1; i < v.size(); i++)
    {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }
    return head;
}

// Hàm xóa node tại vị trí x
ListNode* deleteNode(ListNode* head, int x) {
    if (head == nullptr) return head;

    // Nếu cần xóa node đầu tiên
    if (x == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* p = head;
    for (int i = 0; i < x - 2 && p->next != nullptr; i++) {
        p = p->next;
    }

    if (p->next != nullptr) {
        ListNode* temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
    
    return head;
}
// Ham xoa nodeo vi tri duoi
ListNode *deleteEndNode()

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    ListNode *head = createLinkedList(v);

    int x;
    cin >> x;

    head = deleteNode(head, x); // Xóa node tại vị trí x

    // In danh sách sau khi xóa
    for (ListNode *p = head; p != nullptr; p = p->next)
    {
        cout << p->val << ' ';
    }
    cout << endl;

    // Giải phóng bộ nhớ
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
