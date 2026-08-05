class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int st : stones) {
            pq.push(st);
        }
        while (!pq.empty()) {
            if (pq.size() == 1) break;
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x > y) pq.push(abs(x - y));
        }
        return (pq.size() == 1) ? pq.top() : 0;
    }
};
