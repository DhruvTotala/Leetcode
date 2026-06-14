class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> half;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            half.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int res = 0;
        int i = half.size() - 1;

        while (slow) {
            res = max(res, half[i--] + slow->val);
            slow = slow->next;
        }

        return res;
    }
};