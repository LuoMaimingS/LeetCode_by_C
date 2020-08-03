//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
// 你可以假设 nums1 和 nums2 不会同时为空。
//
//
//
// 示例 1:
//
// nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
//
//
// 示例 2:
//
// nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
//
// Related Topics 数组 二分查找 分治算法

#include "stdio.h"
//leetcode submit region begin(Prohibit modification and deletion)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum_index = (nums1Size + nums2Size + 1) / 2;
    int * num_short = (nums2Size < nums1Size)? nums2: nums1;
    int * num_long = (num_short == nums1)? nums2: nums1;
    int shortSize = (nums2Size < nums1Size)? nums2Size: nums1Size;

    // 二分查找较短列表的分割线
    int left = 0, right = shortSize - 1;
    int p1, p2;
    while (left <= right) {
        p1 = left + (right - left + 1) / 2;
        p2 = sum_index - p1;
        if ((p1 > 0) && (num_short[p1 - 1] > num_long[p2])) {
            right = p1 - 1;
        } else if ((p2 > 0) && (num_long[p2 - 1] > num_short[p1])) {
            left = p1 + 1;
        } else {
            break;
        }
    }
    p1 = left, p2 = sum_index - p1;
    int left_v1 = (p1 == 0)? -2147483647: num_short[p1-1];
    int left_larger = (left_v1 > num_long[p2-1])? left_v1: num_long[p2-1];
    int right_v1 = (left > p1)? 2147483647: num_short[p1];
    int right_smaller = (right_v1 < num_long[p2])? right_v1: num_long[p2];
    float median;
    if ((nums1Size + nums2Size) % 2 == 0) {
        median = (float)(left_larger + right_smaller) / 2;
    } else {
        median = (float)(left_larger);
    }
    return median;
}


//leetcode submit region end(Prohibit modification and deletion)