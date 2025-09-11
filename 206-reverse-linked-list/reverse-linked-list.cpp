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

    int ll_len(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            count++;
            curr = curr -> next;
        }
        return count;
    }

    ListNode* reverseList(ListNode* head) {
        int n = ll_len(head);
        vector <int> arr(n);
        ListNode* curr = head;
        int i = 0;
        while(curr != NULL) {
            arr[i] = curr -> val;
            curr = curr -> next;
            i++;
        }
        reverse(arr.begin(), arr.end());
        curr = head;
        i = 0;
        while(curr != NULL) {
            curr -> val = arr[i];
            i++;
            curr = curr -> next;
        }
        return head;
    }
};