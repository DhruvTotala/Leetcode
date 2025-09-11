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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set <ListNode*> st;

        ListNode* curr = headA;
        while(curr != NULL) {
            st.insert(curr);
            curr = curr -> next;
        }

        curr = headB;
        while(curr != NULL) {
            if(st.count(curr)) return curr;
        curr = curr -> next;
        }
        
    return NULL;
    }
};