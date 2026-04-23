class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, hi = nums.size() - 1;
        while(low < hi){
            int mid = low + (hi - low)/2;           // left/lower mid
            if(target > nums[mid]){
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[low] == target ? low : -1;
    }
};
