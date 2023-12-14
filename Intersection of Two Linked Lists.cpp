// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode* head) {
        int i = 0;

        while(head) {
            i++;
            head = head->next;
        }

        return i;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = length(headA);
        int m = length(headB);
        
        if(n > m) {
            int k = n - m;
            while(k--)
                headA = headA->next;
        } else {
            int k = m - n;
            while(k--)
                headB = headB->next;
        }

        while(headA && headB) {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};
