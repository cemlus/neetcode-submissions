class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        int res = 1;
        while(n != 0){
            ans += res & n;
            n = n >> 1;
        }
        return ans;

    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0 ; i <= n ; i++){
            ans.push_back(hammingWeight(i));
        }
        return ans;
    }
};
