class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        // long long num = long long(x);
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == -1){
            if(n % 2 == 0){
                cout << n % 2 << endl;
                return 1;
            } else {
                cout << n % 2 << endl;
                return -1;
            }
        }
        if(n > 0){
            while(n > 0){
                ans *= x;
                n--;
            }
        } else {
            while(n < 0){
                ans *= (1/x);
                n++;
            }
        }
        return double(ans);
    }
};