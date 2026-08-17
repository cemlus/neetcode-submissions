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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // 1. find middle element
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        // split the 2 halves
        slow->next = nullptr;
        
        // 2. reverse the 2nd half
        ListNode* prev = nullptr;
        while(secondHalf != nullptr){
            ListNode* next = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = next;
        }


        // 3. join the linked list together alternatively
        ListNode* head1 = head;
        ListNode* head2 = prev;

        while(head2 != nullptr){
            ListNode* next = head1->next;
            head1->next = head2;
            head1 = next;

            next = head2->next;
            head2->next = head1;
            head2 = next;
        }

        return;

    }
};