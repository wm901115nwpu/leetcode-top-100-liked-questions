#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2){
    int ca = 0;
    int n1 = 0;
    int n2 = 0;
    int n = 0;
    ListNode* c1 = head1;
    ListNode* c2 = head2;
    ListNode* node = NULL;
    ListNode* pre = NULL;
    while (c1 != NULL || c2 != NULL) {
        n1 = c1 != NULL ? c1->val : 0;
        n2 = c2 != NULL ? c2->val : 0;
        n = n1 + n2 + ca;
        pre = node;
        node = new ListNode(n % 10);
        node->next = pre;
        ca = n / 10;
        c1 = c1 != NULL ? c1->next : NULL;
        c2 = c2 != NULL ? c2->next : NULL;
    }
    if (ca == 1) {
        pre = node;
        node = new ListNode(1);
        node->next = pre;
    }
    return reverseList(node);
}

void printList(ListNode* head)
{
    ListNode* phead=head;
    while(phead->next!=NULL)
    {
        std::cout << phead->val << "->";
        phead = phead->next;
    }
    std::cout << phead->val << std::endl;
}

int main(){
    ListNode* head1 = new ListNode(9);
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(9);
    head1->next->next->next = new ListNode(9);
    head1->next->next->next->next = new ListNode(9);
    head1->next->next->next->next->next = new ListNode(9);
    head1->next->next->next->next->next->next = new ListNode(9);
    ListNode* head2 = new ListNode(9);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);
    head2->next->next->next = new ListNode(9);
    ListNode* ans = addTwoNumbers(head1, head2);
    printList(ans);
}
