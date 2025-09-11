class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* headA = new ListNode();  // dummy for odd
        ListNode* headB = new ListNode();  // dummy for even
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        int count = 1;
        while (curr != NULL) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = NULL; // disconnect node from original chain
            
            if (count % 2 == 1) {  // odd
                p1->next = temp;
                p1 = p1->next;
            } else {               // even
                p2->next = temp;
                p2 = p2->next;
            }
            count++;
        }
        
        // connect odd list with even list
        p1->next = headB->next;
        p2->next = NULL; // terminate even list
        
        return headA->next; // skip dummy
    }
};
