/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.95%)
 * Likes:    2040
 * Dislikes: 0
 * Total Accepted:    754.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> result;

    // 快速选择：寻找前 k 大的频率元素
    void qsort(vector<pair<int, int> >& arr, int left, int right, int k) {
        pair<int, int> pivot = arr[left]; // 选取左侧作为基准
        int i = left;
        int j = right;

        // 分区过程：大于 pivot 的放左边，小于 pivot 的放右边
        while (i < j) {
            while (i < j && arr[j].second <= pivot.second) {
                j--;
            }
            while (i < j && arr[i].second >= pivot.second) {
                i++;
            }
            swap(arr[i], arr[j]);
        }
        swap(arr[left], arr[i]); // 将基准放到最终位置

        if (i == k - 1) { // 找到前 k 大频率位置
            for (int idx = 0; idx < k; idx++) {
                result.push_back(arr[idx].first);
            }
        }
        else if (i < k - 1) { // 继续在右半部分找
            qsort(arr, i + 1, right, k);
        }
        else { // 继续在左半部分找
            qsort(arr, left, i - 1, k);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // 将哈希表转换为 (num, freq) 对
        vector<pair<int, int> > arr;
        for (auto& [num, freq] : freq_map) {
            arr.emplace_back(num, freq);
        }

        // 快速选择前 k 大频率
        qsort(arr, 0, arr.size() - 1, k);

        return result;
    }
};

// @lc code=end

