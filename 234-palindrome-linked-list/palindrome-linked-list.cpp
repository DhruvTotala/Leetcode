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
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL) {
            count++;
            curr = curr -> next;
        }
        return count;
    }

    bool isPalindrome(ListNode* head) {
        int n = ll_len(head);
        vector <int> arr(n);
        ListNode* curr = head;
        int i = 0;
        while(curr != NULL) {
            arr[i] = curr -> val;
            i++;
            curr = curr -> next;
        }
        for(int j = 0; j < (n / 2); j++) {
            if(arr[j] != arr[n - j - 1]) return false;
        }
        return true;
    }
};