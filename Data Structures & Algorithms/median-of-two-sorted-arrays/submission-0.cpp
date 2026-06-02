class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = (m + n);

        int idx2 = len / 2;
        int idx1 = idx2 - 1;
        int ele1 = -1, ele2 = -1;
        int count = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (count == idx1) ele1 = nums1[i];
                if (count == idx2) ele2 = nums1[i];
                i++;
                count++;
            } else {
                if (count == idx1) ele1 = nums2[j];
                if (count == idx2) ele2 = nums2[j];
                j++;
                count++;
            }
        }

        while (i < m) {
            if (count == idx1) ele1 = nums1[i];
            if (count == idx2) ele2 = nums1[i];
            i++;
            count++;
        }

        while (j < n) {
            if (count == idx1) ele1 = nums2[j];
            if (count == idx2) ele2 = nums2[j];
            j++;
            count++;
        }

        if(len % 2 == 1){
            return double(ele2);
        } else {
            return (double(ele1) + double(ele2)) / 2.0;
        }
    }
};
