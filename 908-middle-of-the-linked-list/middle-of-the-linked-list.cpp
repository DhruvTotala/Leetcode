/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len_ll(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            count++;
            curr = curr -> next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int len = len_ll(head);
        int mid = (len / 2) + 1;
        ListNode* curr = head;
        while(mid > 1) {
            mid--;
            curr = curr -> next;
        }
        return curr;
    }
};