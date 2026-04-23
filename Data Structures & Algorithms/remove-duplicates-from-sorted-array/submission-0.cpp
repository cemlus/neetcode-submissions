class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // first k elements of nums contain the unique elements.
        // remove duplicates from nums in-place so that each element appears only once.
        
        int l = 0;
        for(int r = 1 ; r < nums.size() ; r++){
            if(nums[r] != nums[l]){
                nums[l + 1] = nums[r];
                l++;
            }
        }
        return l+1;
    }
};