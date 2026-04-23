class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, hi = nums.size() - 1;
        while(low < hi){
            int mid = low + (hi - low)/2;               // taking the lower middle
            if(target > nums[mid]){
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        if(nums[low] == target){
            return low;
        } else if(nums[low] < target){
            return low + 1;
        } else {
            return low;
        }
    }
};