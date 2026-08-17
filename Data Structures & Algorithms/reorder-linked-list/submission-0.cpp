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
        if (!head || !head->next) return;

        vector<ListNode*> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp);
            temp = temp->next;
        }

        temp = head;
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            arr[left]->next = arr[right];
            left++;

            if (left == right) break;

            arr[right]->next = arr[left];
            right--;
        }
        // removing the 1 remaining edge from the old linked list
        arr[left]->next = nullptr;
    }
};
