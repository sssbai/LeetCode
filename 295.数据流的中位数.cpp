/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode.cn/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (57.03%)
 * Likes:    1136
 * Dislikes: 0
 * Total Accepted:    228.1K
 * Total Submissions: 398.6K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 * 
 * 
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 * 
 * 
 * 实现 MedianFinder 类:
 * 
 * 
 * 
 * MedianFinder() 初始化 MedianFinder 对象。
 * 
 * 
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 * 
 * 
 * double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10^-5 以内的答案将被接受。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 * 
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 * 
 * 提示:
 * 
 * 
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int, vector<int>, less<int> > arr1;
    priority_queue<int, vector<int>, greater<int> > arr2;
    void addNum(int num) {
        if(arr1.size()==arr2.size()){
            if(!arr1.empty()){
                if(num>=arr2.top()){
                    arr1.push(arr2.top());
                    arr2.pop();
                    arr2.push(num);
                }
                else{
                    arr1.push(num);
                } 
            }
            else{
                arr1.push(num);
            }
        }
        else{
            if(num<arr1.top()){
                arr2.push(arr1.top());
                arr1.pop();
                arr1.push(num);
            }
            else{
                arr2.push(num);
            }
        }
    }
    
    double findMedian() {
        if(arr1.size()==arr2.size()){
            return (arr1.top()+arr2.top())*1.0/2;
        }
        else{
            return arr1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

