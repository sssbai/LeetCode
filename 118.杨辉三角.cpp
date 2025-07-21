/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode.cn/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (77.62%)
 * Likes:    1264
 * Dislikes: 0
 * Total Accepted:    686.6K
 * Total Submissions: 883.8K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        int idx = 1;
        while(idx<=numRows){
            for(int i = 0; i < idx; i++){
                if(i==0||i==idx-1){
                    result[idx-1].push_back(1);
                }
                else{
                    result[idx-1].push_back(result[idx-2][i]+result[idx-2][i-1]);
                }
            }
            idx++;
        }
        return result;
    }
};
// @lc code=end

