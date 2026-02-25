// Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.empty() || nums2.empty()) return;
        
        int* p1 = nums1.data() + m - 1;      // nums1 유효 마지막
        int* p2 = nums2.data() + n - 1;      // nums2 마지막
        int* cur = nums1.data() + m + n - 1; // nums1 맨 뒤

        // nums2가 남아있는 동안만 처리하면 됨
        while (p2 >= nums2.data()) {
            if (p1 >= nums1.data() && *p1 > *p2) {
                *cur-- = *p1--;
            } else {
                *cur-- = *p2--;
            }
        }
    }
};
