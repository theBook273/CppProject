struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        for (int i = 0; i < k; i++) {
            ListNode* p = dummy->next;
            while (p->next != nullptr) p = p->next;
            p->next = dummy->next;
            dummy->next = p;
        }

        return dummy->next;
    }
};