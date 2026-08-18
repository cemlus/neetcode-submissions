class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we use the fast and slow pointer technqiue here (idk why but apparently there's a cycle here)    
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int slow2 = 0;
        while(true){
            slow2 = nums[slow2];
            fast = nums[fast];
            if(slow2 == fast){
                return slow2;
            }
        }
        return 0;
    }
};
