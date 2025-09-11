/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int ll(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            count++;
            curr = curr -> next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = ll(headA);
        int m = ll(headB);

        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int diff = abs(m - n);
        if(m > n) {
            swap(p1, p2);
        }
        // n is always bigger 
        while(diff > 0) {
            p1 = p1 -> next;
            diff--;
        }
        while(p1 != NULL && p2 != NULL) {
            if(p1 == p2) return p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    return NULL;
    }
};