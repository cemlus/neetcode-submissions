/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, hi = n;
        while(low < hi){
            int num = low + (hi - low)/2;
            // if target > nums[mid]
            if(guess(num) == 1){
                low = num + 1;
            } else if (guess(num) == -1){
                hi = num - 1;
            } else {
                return num;
            }
        }
        return low;
    }
};