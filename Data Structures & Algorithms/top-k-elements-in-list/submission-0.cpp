class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //  make the frequency map
        unordered_map<int, int> freq;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }

        //  make the bucket array where the index -> frequency
        vector<vector<int>> buckets(nums.size() + 1);
        for(const auto& it: freq){
            buckets[it.second].push_back(it.first);
        }

        // return the k digits from the end
        int idx = nums.size();
        vector<int> ans;
        while(idx > 0 && k > 0){
            for(int i = 0 ; i < buckets[idx].size() && k > 0 ; i++){
                ans.push_back(buckets[idx][i]);
                k--;
            }
            idx--;
        }
        return ans;
    }
};
