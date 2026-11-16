class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {
            ListNode* kth = prevGroup;

            // Check whether k nodes are available
            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if (kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect the reversed group
            ListNode* oldStart = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = oldStart;
        }

        return dummy.next;
    }
};
