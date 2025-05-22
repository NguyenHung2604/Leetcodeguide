#include <iostream>
#include <vector>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0) , next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x){}
};  
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = new ListNode();
    ListNode *p = ans;
    int carry = 0;
    while(l1 || l2 || carry != 0)
    {
        int digit1 = l1 ? l1->val : 0;
        int digit2 = l2 ? l2->val : 0;
        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode(digit);
        p->next = newNode;
        p = p->next;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return ans->next;

}
int main() {
    // Nhập dữ liệu cho danh sách l1
    int n1;
    cout << "Nhap so luong phan tu cua l1: ";
    cin >> n1;
    ListNode *l1_head = new ListNode(), *l1 = l1_head;
    cout << "Nhap cac phan tu cua l1: ";
    for (int i = 0; i < n1; ++i) {
        int x;
        cin >> x;
        l1->next = new ListNode(x);
        l1 = l1->next;
    }
    l1 = l1_head->next; // Bỏ node giả phía trước

    // Nhập dữ liệu cho danh sách l2
    int n2;
    cout << "Nhap so luong phan tu cua l2: ";
    cin >> n2;
    ListNode *l2_head = new ListNode(), *l2 = l2_head;
    cout << "Nhap cac phan tu cua l2: ";
    for (int i = 0; i < n2; ++i) {
        int x;
        cin >> x;
        l2->next = new ListNode(x);
        l2 = l2->next;
    }
    l2 = l2_head->next; // Bỏ node giả phía trước
    
    ListNode *ans = addTwoNumbers(l1, l2);
    
    for(ListNode *p = ans; p != nullptr; p = p->next)
    {
        cout << p->val << ' '; 
    }
    return 0;
}