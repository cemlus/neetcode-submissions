class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int pos = 0;

    KthLargest(int k, vector<int>& nums) {
        pos = k;
        for(int num: nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > pos){
            pq.pop();
        }
        return pq.top();
    }
};
