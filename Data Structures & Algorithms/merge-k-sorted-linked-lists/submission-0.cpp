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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        
        for(ListNode* it: lists){
            minHeap.push(it);
        }

        if(minHeap.size() == 0) return nullptr;

        ListNode dummy(0);
        // we need this dummy node in order to use ->next on it and chain the subsequent nodes
        ListNode* tail = &dummy;

        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            minHeap.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next) minHeap.push(curr->next);
        }

        return dummy.next;
    }
};
