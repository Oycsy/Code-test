//#pragma once
//#include <iostream>
//#include <istream>
//#include <algorithm>
//#include <vector>
//#include <set>
//#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <string>
//#include <unordered_set>
//using namespace std;
//
//class GreadyAlogrithmSolution {
//public:
//    /**
//     * 分发饼干.
//     * 
//     * \param g
//     * \param s
//     * \return 
//     */
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        int res = 0;
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//        int s_index = 0;
//        int g_index = 0;
//        while (s_index < s.size() && g_index < g.size()) {
//            if (s[s_index] >= g[g_index]) {
//                res++;
//                s_index++;
//                g_index++;
//            }
//            else {
//                s_index++;
//            }
//        }
//        return res;
//    }
//    /**
//     * 柠檬水找零.
//     * 
//     * \param bills
//     * \return 
//     */
//    bool lemonadeChange(vector<int>& bills) {
//        unordered_map<int, int> map;
//        if (bills[0] == 10 || bills[0] == 20) return false;
//        for (int i = 0; i < bills.size(); i++) {
//            if (bills[i] == 5) {
//                map[5]++;
//            }
//            else if (bills[i] == 10) {
//                if (map[5] == 0) return false;
//                map[5]--;
//                map[10]++;
//            }
//            else {
//                if (map[10] > 0 && map[5] > 0) {
//                    map[20]++;
//                    map[10]--;
//                    map[5]--;
//                }
//                else if (map[10] == 0 && map[5] >= 3) {
//                    map[20]++;
//                    map[5] -= 3;
//                }
//                else return false;
//            }
//        }
//        return true;
//    }
//    /**
//     * 有序数组的平方.
//     * 
//     * \param nums
//     * \return 
//     */
//    vector<int> sortedSquares(vector<int>& nums) {
//        vector<int> res;
//        int index = 0;
//        for (; index < nums.size(); index++) {
//            if (nums[index] >= 0)break;
//        }
//        int left = index - 1;
//        int right = index;
//        while (left >= 0 && right < nums.size()) {
//            if (nums[left] * nums[left] < nums[right] * nums[right]) {
//                res.push_back(nums[left] * nums[left]);
//                left--;
//            }
//            else {
//                res.push_back(nums[right] * nums[right]);
//                right++;
//            }
//
//        }
//        while (left >= 0) {
//            res.push_back(nums[left] * nums[left]);
//            left--;
//        }
//        while (right < nums.size()) {
//            res.push_back(nums[right] * nums[right]);
//            right++;
//        }
//        return res;
//    }
//    /**
//     * 种花问题.
//     * 
//     * \param flowerbed
//     * \param n
//     * \return 
//     */
//    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//        int count = 0;
//        int len = flowerbed.size();
//        if (len == 1) {
//            if (flowerbed[0] == 1 && n > 0) return false;
//            else if (flowerbed[0] == 0 && n > 1) return false;
//            else return true;
//        }
//        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
//            flowerbed[0] = 1;
//            count++;
//        }
//        if (count >= n) return true;
//        for (int i = 1; i < flowerbed.size() - 1; i++) {
//            if (count >= n) return true;
//            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
//                flowerbed[i] = 1;
//                count++;
//            }
//        }
//        if (flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0) {
//            flowerbed[flowerbed.size() - 1] = 1;
//            count++;
//        }
//        if (count >= n) return true;
//        return false;
//    }
//    /**
//     * k次取反后最大化数组和.
//     * 
//     * \param nums
//     * \param k
//     * \return 
//     */
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        int res = 0;
//        sort(nums.begin(), nums.end());
//        int index = 0;
//        for (; index < nums.size(); index++) {
//            if (nums[index] >= 0) break;
//        }
//        if (k < index) {
//            for (int i = 0; i < k; i++)  res -= nums[i];
//            for (int i = k; i < nums.size(); i++)  res += nums[i];
//        }
//        else {
//            for (int i = 0; i < index; i++)  nums[i] = -1 * nums[i];
//            sort(nums.begin(), nums.end());
//            int dif = k - index;
//            if (dif % 2 == 1) nums[0] = 0 - nums[0];
//            for (int i = 0; i < nums.size(); i++)  res += nums[i];
//        }
//        return res;
//    }
//    /**
//     * 加油站.
//     * 
//     * \param gas
//     * \param cost
//     * \return 
//     */
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int curSum = 0;
//        int totalSum = 0;
//        int start = 0;
//        for (int i = 0; i < gas.size(); i++) {
//            curSum += gas[i] - cost[i];
//            totalSum += gas[i] - cost[i];
//            if (curSum < 0) {
//                start = i + 1;
//                curSum = 0;
//            }
//        }
//        if (totalSum < 0) return -1;
//        return start;
//    }
//    /**
//     * 摇摆序列.
//     * 
//     * \param nums
//     * \return 
//     */
//    int wiggleMaxLength(vector<int>& nums) {
//        if (nums.size() <= 1) return nums.size();
//        int curDiff = 0;
//        int preDiff = 0;
//        int res = 1;
//        for (int i = 0; i < nums.size() - 1; i++) {
//            curDiff = nums[i + 1] - nums[i];
//            if ((preDiff <= 0 && curDiff > 0)
//                || (preDiff >= 0 && curDiff < 0)) {
//                res++;
//                preDiff = curDiff;
//            }
//        }
//        return res;
//    }
//    /**
//     * 最大和的连续子数组.
//     * 
//     * \param nums
//     * \return 
//     */
//    int maxSubArray(vector<int>& nums) {
//        if (nums.size() == 1) return nums[0];
//        int res = INT_MIN;
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            sum += nums[i];
//            if (sum > res) {
//                res = sum;
//            }
//            if (sum <= 0) sum = 0;
//        }
//        return res;
//    }
//    /**
//     * 单调递增的数字.
//     * 
//     * \param N
//     * \return 
//     */
//    int monotoneIncreasingDigits(int N) {
//        string num = to_string(N);
//        int flag = num.size();
//        for (int i = num.size() - 1; i > 0; i--) {
//            if (num[i] < num[i - 1]) {
//                flag = i;
//                num[i - 1]--;
//            }
//        }
//        for (int i = flag; i < num.size(); i++) {
//            num[i] = '9';
//        }
//        return stoi(num);
//    }
//    /**
//     * 身高队列重建.
//     * 
//     * \param people
//     * \return 
//     */
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        sort(people.begin(), people.end(), 
//            [](const vector<int>& a, const vector<int>& b) {
//            if (a[0] == b[0]) { // 当第一个元素相同的时候，按第二个元素从小到大排序
//                return a[1] < b[1];
//            }
//            else { // 第一个元素不相同，按第一个元素从小到大排序
//                return a[0] > b[0];
//            }
//            });
//        vector<vector<int>> res;
//        for (int i = 0; i < people.size(); i++) {
//            int position = people[i][1];
//            res.insert(res.begin() + position, people[i]);
//        }
//        return res;
//    }
//    /**
//     * 分发糖果.
//     * 
//     * \param ratings
//     * \return 
//     */
//    int candy(vector<int>& ratings) {
//        if (ratings.size() == 1) return 1;
//        vector<int> res(ratings.size(), 1);
//        // 从前向后
//        for (int i = 1; i < ratings.size(); i++) {
//            if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
//        }
//        // 从后向前
//        for (int i = ratings.size() - 2; i >= 0; i--) {
//            if (ratings[i] > ratings[i + 1]) {
//                res[i] = max(res[i], res[i + 1] + 1);
//            }
//        }
//        int sum = 0;
//        for (int i : res) sum += i;
//        return sum;
//    }
//
//    /**
//     * 盛水最多的容器.
//     * 
//     * \param height
//     * \return 
//     */
//    int maxArea(vector<int>& height) {
//        vector<int> leftMax(height.size(), 0);
//        vector<int> rightMax(height.size(), 0);
//        leftMax[0] = 0;
//        for (int i = 1; i < height.size(); i++) {
//            leftMax[i] = i;
//            for (int j = 0; j <= i; j++) {
//                if (height[j] >= height[i]) {
//                    leftMax[i] = j;
//                    break;
//                }
//            }
//        }
//        // 记录每个柱子右边柱子最大高度
//        rightMax[height.size() - 1] = height.size() - 1;
//        for (int i = height.size() - 2; i >= 0; i--) {
//            rightMax[i] = i;
//            for (int j = height.size() - 1; j >= i; j--) {
//                if (height[j] >= height[i]) {
//                    rightMax[i] = j;
//                    break;
//                }
//            }
//        }
//
//        int res = 0;
//        for (int i = 0; i < height.size(); i++) {
//            int countleft = min(height[leftMax[i]], height[i]) * (i - leftMax[i]);
//            int countright = min(height[rightMax[i]], height[i]) * (rightMax[i] - i);
//            res = max(max(countleft, countright), res);
//        }
//        return res;
//    }
//    //或者
//    int maxArea(vector<int>& height) {
//        int left = 0;
//        int right = height.size() - 1;
//        int res = 0;
//        while (left < right) {
//            int width = right - left;
//            int h = min(height[left], height[right]);
//            int area = width * h;
//            res = max(res, area);
//            if (height[left] < height[right]) {
//                left++;
//            }
//            else {
//                right--;
//            }
//        }
//        return res;
//    }
//    /**
//     * 两数之和.
//     * 
//     * \param nums
//     * \param target
//     * \return 
//     */
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> res(2);
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            auto it = map.find(target - nums[i]);
//            if (it != map.end()) {
//                res[0] = map[target - nums[i]];
//                res[1] = i;
//                break;
//            }
//            else {
//                map[nums[i]] = i;
//            }
//        }
//        return res;
//    }
//    //或者
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i) {
//            auto it = map.find(target - nums[i]);
//            if (it != map.end()) {
//                return { it->second,i };
//            }
//            map[nums[i]] = i;
//        }
//        return {};
//    }
//    /**
//     * 三数之和.
//     * 
//     * \param nums
//     * \return 
//     */
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> res;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > 0) break;
//            if (i > 0 && nums[i] == nums[i - 1]) continue;
//            int target = 0 - nums[i];
//            unordered_set<int> set;
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (j > i + 2
//                    && nums[j] == nums[j - 1]
//                    && nums[j - 1] == nums[j - 2]) continue;
//                if (set.count(target - nums[j]) > 0) {
//                    res.push_back({ nums[i],nums[j],target - nums[j] });
//                    set.erase(target - nums[j]);
//                }
//                else {
//                    set.insert(nums[j]);
//                }
//
//            }
//        }
//        return res;
//    }
//    //或者用双指针方法
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > 0) {
//                return result;
//            }
//            // 正确去重a方法
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            int left = i + 1;
//            int right = nums.size() - 1;
//            while (right > left) {
//                if (nums[i] + nums[left] + nums[right] > 0) right--;
//                else if (nums[i] + nums[left] + nums[right] < 0) left++;
//                else {
//                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
//                    while (right > left && nums[right] == nums[right - 1]) right--;
//                    while (right > left && nums[left] == nums[left + 1]) left++;
//                    // 找到答案时，双指针同时收缩
//                    right--;
//                    left++;
//                }
//            }
//
//        }
//        return result;
//    }
//    /**
//     * 最接近的三数之和.
//     * 
//     * \param nums
//     * \param target
//     * \return 
//     */
//    int threeSumClosest(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end());
//        int res = 0;
//        int dif = INT_MAX;
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            int left = i + 1;
//            int right = nums.size() - 1;
//            while (right > left) {
//                if (nums[i] + nums[left] + nums[right] == target) return target;
//
//                if (abs(nums[i] + nums[left] + nums[right] - target) < dif) {
//                    dif = abs(nums[i] + nums[left] + nums[right] - target);
//                    res = nums[i] + nums[left] + nums[right];
//                }
//
//                else if (nums[i] + nums[left] + nums[right] > target) {
//                    right--;
//                }
//                else if (nums[i] + nums[left] + nums[right] < target) {
//                    left++;
//                }
//                else {
//                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
//                    while (right > left && nums[right] == nums[right - 1]) right--;
//                    while (right > left && nums[left] == nums[left + 1]) left++;
//                    // 找到答案时，双指针同时收缩
//                    right--;
//                    left++;
//                }
//            }
//        }
//        return res;
//    }
//    /**
//     * 四数之和.
//     * 
//     * \param nums
//     * \param target
//     * \return 
//     */
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>> res;
//        sort(nums.begin(), nums.end());
//
//        for (int i = 0; i < nums.size(); i++) {
//            // 剪枝处理
//            if (nums[i] > target && nums[i] >= 0) {
//                break; // 这里使用break，统一通过最后的return返回
//            }
//            // 对nums[k]去重
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = i + 1; j < nums.size(); j++) {
//                // 2级剪枝处理
//                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
//                    break;
//                }
//
//                // 对nums[i]去重
//                if (j > i + 1 && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//
//                int left = j + 1;
//                int right = nums.size() - 1;
//
//                while (right > left) {
//                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
//                        right--;
//                    }
//                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
//                        left++;
//                    }
//                    else {
//                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
//                        // 对nums[left]和nums[right]去重
//                        while (right > left && nums[right] == nums[right - 1]) right--;
//                        while (right > left && nums[left] == nums[left + 1]) left++;
//
//                        // 找到答案时，双指针同时收缩
//                        right--;
//                        left++;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//    /**
//     * 四个集合的四个数之和.
//     * 
//     * \param A
//     * \param B
//     * \param C
//     * \param D
//     * \return 
//     */
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
//        for (int a : A) {
//            for (int b : B) {
//                umap[a + b]++;
//            }
//        }
//        int count = 0; // 统计a+b+c+d = 0 出现的次数
//        for (int c : C) {
//            for (int d : D) {
//                if (umap.find(0 - (c + d)) != umap.end()) {
//                    count += umap[0 - (c + d)];
//                }
//            }
//        }
//        return count;
//    }
//
//    //区间问题汇总
//    /**
//     * 跳跃游戏.
//     * 
//     * \param nums
//     * \return 
//     */
//    bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        int maxIndex = 0;
//        for (int i = 0; i < n - 1; i++) {
//            maxIndex = max(maxIndex, nums[i] + i);
//            if (maxIndex < i + 1) return false;
//        }
//        return true;
//    }
//    /**
//     * 最小跳跃次数.
//     * 
//     * \param nums
//     * \return 
//     */
//    int jump(vector<int>& nums) {
//        int curDistance = 0;    // 当前覆盖的最远距离下标
//        int ans = 0;            // 记录走的最大步数
//        int nextDistance = 0;   // 下一步覆盖的最远距离下标
//        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
//            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
//            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
//                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
//                ans++;
//            }
//        }
//        return ans;
//    }
//    /**
//     * 合并区间.
//     * 
//     * \param intervals
//     * \return 
//     */
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> res;
//        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
//        for (int i = 0; i < intervals.size() - 1; i++) {
//            if (intervals[i][1] < intervals[i + 1][0])
//                res.push_back(intervals[i]);
//            else {
//                intervals[i + 1][0] = intervals[i][0];
//                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
//            }
//        }
//        res.push_back(intervals[intervals.size() - 1]);
//        return res;
//    }
//    //或者
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> result;
//        if (intervals.size() == 0) return result; // 区间集合为空直接返回
//        // 排序的参数使用了lambda表达式
//        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
//
//        // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
//        result.push_back(intervals[0]);
//
//        for (int i = 1; i < intervals.size(); i++) {
//            if (result.back()[1] >= intervals[i][0]) { // 发现重叠区间
//                // 合并区间，只更新右边界就好，因为result.back()的左边界一定是最小值，因为我们按照左边界排序的
//                result.back()[1] = max(result.back()[1], intervals[i][1]);
//            }
//            else {
//                result.push_back(intervals[i]); // 区间不重叠 
//            }
//        }
//        return result;
//    }
//    /**
//     * 用最少数量的箭引爆气球.
//     * 
//     * \param points
//     * \return 
//     */
//    int findMinArrowShots(vector<vector<int>>& points) {
//        vector<vector<int>> res;
//        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
//        for (int i = 0; i < points.size() - 1; i++) {
//            if (points[i][1] < points[i + 1][0])
//                res.push_back(points[i]);
//            else {
//                points[i + 1][0] = points[i][0];
//                points[i + 1][1] = min(points[i][1], points[i + 1][1]);
//            }
//        }
//        res.push_back(points[points.size() - 1]);
//        return res.size();
//    }
//    //或者
//    static bool cmp(const vector<int>& a, const vector<int>& b) {
//        return a[0] < b[0];
//    }
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.size() == 0) return 0;
//        sort(points.begin(), points.end(), cmp);
//
//        int result = 1; // points 不为空至少需要一支箭
//        for (int i = 1; i < points.size(); i++) {
//            if (points[i][0] > points[i - 1][1]) {  // 气球i和气球i-1不挨着，注意这里不是>=
//                result++; // 需要一支箭
//            }
//            else {  // 气球i和气球i-1挨着
//                points[i][1] = min(points[i - 1][1], points[i][1]); // 更新重叠气球最小右边界
//            }
//        }
//        return result;
//    }
//    /**
//     * 无重叠区间.
//     * 
//     * \param intervals
//     * \return 
//     */
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        int res = 0;
//        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
//            if(a[0] == b[0]) return a[1] < b[1];
//            else return a[0] < b[0];
//            });
//
//        for (int i = 1; i < intervals.size(); i++) {
//            if (intervals[i][0] < intervals[i - 1][1]) { //重叠情况
//                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
//                res++;
//            }
//        }
//        return res;
//    }
//    /**
//     * 划分字母区间.
//     * 
//     * \param s
//     * \return 
//     */
//    int far(string s, int index, char c) {
//        for (int i = s.length() - 1; i > index; i--) {
//            if (s[i] == c) return i;
//        }
//        return index;
//    }
//
//    vector<int> partitionLabels(string s) {
//        vector<int> res;
//        int nextIndex = 0;
//        int cur = 0;
//        for (int i = 0; i < s.length(); i++) {
//            nextIndex = far(s, i, s[i]);
//            for (int j = i + 1; j < nextIndex; j++) {
//                cur = far(s, j, s[j]);
//                nextIndex = max(nextIndex, cur);
//            }
//            res.push_back(nextIndex - i + 1);
//            i = nextIndex;
//        }
//        return res;
//    }
//    //或者
//    vector<int> partitionLabels(string S) {
//        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
//        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
//            hash[S[i] - 'a'] = i;
//        }
//        vector<int> result;
//        int left = 0;
//        int right = 0;
//        for (int i = 0; i < S.size(); i++) {
//            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
//            if (i == right) {
//                result.push_back(right - left + 1);
//                left = i + 1;
//            }
//        }
//        return result;
//    }
//};
