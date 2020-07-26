//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。 
//
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。 
//
// 
//
// 例如，给定三角形： 
//
// [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
// 
//
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。 
//
// 
//
// 说明： 
//
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。 
// Related Topics 数组 动态规划

#include "stdlib.h"
//leetcode submit region begin(Prohibit modification and deletion)


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if (triangleSize == 0)
        return 0;
    if (triangleSize == 1)
        return triangle[0][0];

    int *min_dis = (int *)calloc(triangleSize, sizeof(int));
    int *last_layer_dis = (int *)calloc(triangleSize, sizeof(int));
    min_dis[0] = triangle[0][0];
    last_layer_dis[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            if (j == 0) {
                min_dis[j] = last_layer_dis[0] + triangle[i][0];
            } else if (j == triangleColSize[i] - 1) {
                min_dis[j] = last_layer_dis[j-1] + triangle[i][j];
            } else {
                int left_dis = last_layer_dis[j-1] + triangle[i][j];
                int right_dis = last_layer_dis[j] + triangle[i][j];
                min_dis[j] = (left_dis < right_dis)? left_dis: right_dis;
            }
        }
        for (int k = 0; k <= i; k++) {
            last_layer_dis[k] = min_dis[k];
        }
    }

    int min_distance = 2147483647;
    for (int i = 0; i < triangleColSize[triangleSize-1]; i++) {
        min_distance = (min_dis[i] < min_distance)? min_dis[i]: min_distance;
    }
    return min_distance;
}


//leetcode submit region end(Prohibit modification and deletion)
