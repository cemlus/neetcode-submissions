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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // there are 3 parts to this problem:
        // the leftPart, the reversed part and the rightPart
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;

        for(int i = 1 ; i < left ; i++){
            temp = temp->next;
        }
        // we now have one node before reversed part
        ListNode* beforeLeft = temp;
        for(int i = 0 ; i <= right - left + 1 ; i++){
            temp = temp->next;   
                     
        }
        ListNode* rightNode = temp;
        ListNode* curr = beforeLeft->next;
        ListNode* prev = nullptr;
        for(int i = 0 ; i <= right - left ; i++){
            ListNode* next = curr->next;
            if(i == 0) curr->next = rightNode;
            else curr->next = prev;
            prev = curr;
            curr = next;
        }
        beforeLeft->next = prev;
        return dummy.next;

    }
};