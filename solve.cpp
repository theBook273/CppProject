struct ListNode {
    long long val;
    ListNode *next;
    ListNode(long long x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next;

            if(slow == fast) 
                return 1;
        }
        return 0;
    }
};
