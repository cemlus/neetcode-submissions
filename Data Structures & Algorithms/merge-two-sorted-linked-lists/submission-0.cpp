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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode temp(-1);
        ListNode* dummy = new ListNode(0);
        temp.next = dummy; 

        while(head1 != nullptr && head2 != nullptr){
            if(head1->val <= head2->val){
                dummy->next = head1;
                head1 = head1->next;
                dummy = dummy->next;
            } else {
                dummy->next = head2;
                head2 = head2->next;
                dummy = dummy->next;
            }
        }

        while(head1 != nullptr){
            dummy->next = head1;
            head1 = head1->next;
            dummy = dummy->next;
        }
        while(head2 != nullptr){
            dummy->next = head2;
            head2 = head2->next;
            dummy = dummy->next;
        }

        return temp.next->next;
    }
};
