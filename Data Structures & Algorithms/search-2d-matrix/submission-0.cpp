class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(target >= matrix[mid][0]){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        int row = lo;
        cout << row << endl;
        lo = 0;
        hi = matrix[row].size() - 1;


        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(target > matrix[row][mid]){
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int col = lo;
        cout << col << endl;

        if(matrix[row][col] == target){
            return true;
        } else {
            return false;
        }
    }
};
