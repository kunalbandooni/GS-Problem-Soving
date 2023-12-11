// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            ans->next = new ListNode(l1->val + l2->val + carry);
            
            ans = ans->next;
            carry = ans->val/10;
            ans->val = ans->val%10;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            ans->next = new ListNode(l1->val + carry);
            ans = ans->next;
            carry = ans->val/10;
            ans->val = ans->val%10;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            ans->next = new ListNode(l2->val + carry);
            ans = ans->next;
            carry = ans->val/10;
            ans->val = ans->val%10;
            l2 = l2->next;
        }

        if(carry > 0)
            ans->next = new ListNode(carry);

        return head->next;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* ans = add(l1, l2);
        ans = reverse(ans);

        return ans;
    }
};
