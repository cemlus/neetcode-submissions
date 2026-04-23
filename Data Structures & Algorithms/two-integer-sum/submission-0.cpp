class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;        // value -> index
        
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            // if the difference exists in the hash-map then immediately return the current index
            if(mpp.find(diff) != mpp.end()){
                return {mpp[diff], i};
            }

            mpp[nums[i]] = i; 
        }
        return {};
    }
};
