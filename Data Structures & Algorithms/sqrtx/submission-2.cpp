class Solution {
public:
    int mySqrt(int x) {
        long long lo = 1, hi = x;
        if(x <= 0) return 0;
        while(lo < hi){
            long long mid = lo + (hi - lo + 1)/2 ;
            long long ans = mid * mid;
            cout << "this is the square of mid element " << mid << " - " <<  ans << endl;
            if(ans > x){
                // move lo to right
                hi = mid - 1;
            } else{
                // move hi to left
                lo = mid;
            }
        }   
        cout << lo << endl;
        return int(lo);
    }
};