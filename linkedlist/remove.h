struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* id = head;

        while (id != nullptr) {
            while (id->next != nullptr && id->next->val == id->val) {
                id->next = id->next->next;
            }
            id = id->next;
        }
        return dummy->next;
    }
};