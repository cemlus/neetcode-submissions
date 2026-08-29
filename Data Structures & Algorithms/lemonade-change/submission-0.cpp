class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int b: bills){
            if(b == 5) fives++;
            else if(b == 10){
                tens++;
                if(fives) fives--;
                else return false;
            } else {
                // case 1
                if(fives && tens){
                    fives--;
                    tens--;
                } else if(fives >= 3){
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};