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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        // ListNode* temp = &dummy;
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }

        while(fast->next != nullptr){
            // allows us to land just before the nth node from the last
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
