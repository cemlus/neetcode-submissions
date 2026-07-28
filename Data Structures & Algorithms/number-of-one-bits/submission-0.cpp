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
};