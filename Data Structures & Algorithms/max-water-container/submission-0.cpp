class Solution {
public:
    int maxArea(vector<int>& heights) {
        // pick the indices with the largest area possible
        // this means that the area will be calulcated using 
        // maxArea = max(min(nums[indx1], nums[indx2]) * abs(idx1 - indx2), maxArea)
        // --------------------------------------------------------------
        // brute force
        // int maxArea = 0;
        // int n = heights.size();
        // for(int l = 0 ; l < n ; l++){
        //     for(int r = l + 1; r < n ; r++){
        //         int area = min(heights[l], heights[r]) * (r - l);
        //         if(maxArea < area){
        //             maxArea = area;
        //         }
        //     }
        // }
        // return maxArea;
        // --------------------------------------------------------------

        // try and pin the maximum numbered pillar, then from it's right and calculate the biggest
        // area with respect to that pillar and do the same on the left side
        // after doing so i want you to merge the both maxArea indices and find the final area 
        // by using the minimum index out of both and distance between both

        int n = heights.size();
        int start = 0, end = n - 1;
        int maxArea = -1;
        while(start < end){
            int area = min(heights[start], heights[end]) * (end - start);
            maxArea = max(maxArea, area);

            if(heights[start] < heights[end]){
                // move the smller index cuz there's a better chance to get a higher valued index 
                // further
                start++;
            } else {
                end--;
            }
        }
        return maxArea;


    }
};
