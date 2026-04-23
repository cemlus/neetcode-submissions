class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can only be 2 elements that have a count of more than > n/3
        vector<int> ans;
        int cnt1 = 0;
        int cnt2 = 0;
        unordered_map<int, int> freq;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }
        for(const auto& it : freq){
            if(it.second > nums.size() / 3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};