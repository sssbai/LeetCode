/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.98%)
 * Likes:    2857
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 * 
 * 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j]
 * 处:
 * 
 * 
 * 0 <= j <= nums[i] 
 * i + j < n
 * 
 * 
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 题目保证可以到达 nums[n-1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_cover = 0;     // 当前跳跃次数能覆盖的最远位置（当前跳跃范围的右边界）
        int next_cover = 0;    // 在当前跳跃范围内，下一步跳跃时能到达的最远位置
        int ans = 0;           // 当前跳跃次数

        // 从位置 0 开始遍历，直到当前跳跃范围的右边界
        for(int i = 0; i <= cur_cover; i++) {
            // 更新在当前位置 i 能跳到的最远位置，记录在下一次跳跃的覆盖范围中
            next_cover = max(nums[i] + i, next_cover);

            // 如果当前跳跃范围已经覆盖或超过最后一个位置，立即返回当前跳跃次数
            if(cur_cover >= nums.size() - 1) return ans;

            // 当遍历到当前跳跃范围的右边界时，进行一次跳跃
            if(i == cur_cover) {
                cur_cover = next_cover; // 扩展跳跃范围到 next_cover
                ans++;                  // 跳跃次数 +1
            }
        }

        // 理论上不会执行到这里，仅保证语法完整
        return 0;
    }
};
// @lc code=end

