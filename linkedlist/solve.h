struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dum = new ListNode(0, head);
        ListNode* p1 = dum;
        ListNode* p2 = dum;

        for (int i = 0; i <= n; ++i) {
            p2 = p2->next;
        }

        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* temp = p1->next;

        p1->next = temp->next;

        delete temp;

        return dum->next;
    }
};