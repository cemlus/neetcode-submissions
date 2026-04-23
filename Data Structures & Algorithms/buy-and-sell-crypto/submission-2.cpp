class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // need to find the minimum element first
        // then i need to find the greatest element from that minimum element
        int r = 1, l = 0;
        while(r < prices.size()){
            if(prices[r] < prices[l]){
                l++;
                // r++;
            } else {
                int dif = prices[r] - prices[l];
                profit = max(profit, dif);
                cout << profit << endl;
                r++;
            }
        }    
        return profit;    
        
    }
};
