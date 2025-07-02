
struct ListNode {
    long long val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long long x) : val(x), next(nullptr) {}
    ListNode(long long x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, long long val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = dummy;

        while (p1 != nullptr) {
            if (p1->next != nullptr && p1->next->val == val) {
                ListNode* temp = p1->next;
                p1->next = temp->next;
                delete temp;
            } else
                p1 = p1->next;
        }
        return dummy;
    }
};
