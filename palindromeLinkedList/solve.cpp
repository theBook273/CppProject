struct ListNode {
    long long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long long x) : val(x), next(nullptr) {}
    ListNode(long long x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return 0;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next->next && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow->next;

        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            if (first->val != second->val) return 0;
            first = first->next;
            second = second->next;
        }

        return 1;
    };
};
