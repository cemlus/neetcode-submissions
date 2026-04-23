class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        vector<int> suff(n, 1);

        for(int i = 1 ; i < n; i++){
            pref[i] = pref[i - 1] * nums[i - 1];
        }

        for(int j = n - 2; j >= 0; j--){
            suff[j] = suff[j + 1] * nums[j + 1];
        }
        vector<int> ans;
        for(int k = 0; k < n; k++){
            ans.push_back(pref[k] * suff[k]);
        }
        return ans;

    }
};