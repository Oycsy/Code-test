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
//     * �ַ�����.
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
//     * ����ˮ����.
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
//     * ���������ƽ��.
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
//     * �ֻ�����.
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
//     * k��ȡ������������.
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
//     * ����վ.
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
//     * ҡ������.
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
//     * ���͵�����������.
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
//     * ��������������.
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
//     * ��߶����ؽ�.
//     * 
//     * \param people
//     * \return 
//     */
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        sort(people.begin(), people.end(), 
//            [](const vector<int>& a, const vector<int>& b) {
//            if (a[0] == b[0]) { // ����һ��Ԫ����ͬ��ʱ�򣬰��ڶ���Ԫ�ش�С��������
//                return a[1] < b[1];
//            }
//            else { // ��һ��Ԫ�ز���ͬ������һ��Ԫ�ش�С��������
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
//     * �ַ��ǹ�.
//     * 
//     * \param ratings
//     * \return 
//     */
//    int candy(vector<int>& ratings) {
//        if (ratings.size() == 1) return 1;
//        vector<int> res(ratings.size(), 1);
//        // ��ǰ���
//        for (int i = 1; i < ratings.size(); i++) {
//            if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
//        }
//        // �Ӻ���ǰ
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
//     * ʢˮ��������.
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
//        // ��¼ÿ�������ұ��������߶�
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
//    //����
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
//     * ����֮��.
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
//    //����
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
//     * ����֮��.
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
//    //������˫ָ�뷽��
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > 0) {
//                return result;
//            }
//            // ��ȷȥ��a����
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
//                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b �� cȥ��
//                    while (right > left && nums[right] == nums[right - 1]) right--;
//                    while (right > left && nums[left] == nums[left + 1]) left++;
//                    // �ҵ���ʱ��˫ָ��ͬʱ����
//                    right--;
//                    left++;
//                }
//            }
//
//        }
//        return result;
//    }
//    /**
//     * ��ӽ�������֮��.
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
//                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b �� cȥ��
//                    while (right > left && nums[right] == nums[right - 1]) right--;
//                    while (right > left && nums[left] == nums[left + 1]) left++;
//                    // �ҵ���ʱ��˫ָ��ͬʱ����
//                    right--;
//                    left++;
//                }
//            }
//        }
//        return res;
//    }
//    /**
//     * ����֮��.
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
//            // ��֦����
//            if (nums[i] > target && nums[i] >= 0) {
//                break; // ����ʹ��break��ͳһͨ������return����
//            }
//            // ��nums[k]ȥ��
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = i + 1; j < nums.size(); j++) {
//                // 2����֦����
//                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
//                    break;
//                }
//
//                // ��nums[i]ȥ��
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
//                        // ��nums[left]��nums[right]ȥ��
//                        while (right > left && nums[right] == nums[right - 1]) right--;
//                        while (right > left && nums[left] == nums[left + 1]) left++;
//
//                        // �ҵ���ʱ��˫ָ��ͬʱ����
//                        right--;
//                        left++;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//    /**
//     * �ĸ����ϵ��ĸ���֮��.
//     * 
//     * \param A
//     * \param B
//     * \param C
//     * \param D
//     * \return 
//     */
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        unordered_map<int, int> umap; //key:a+b����ֵ��value:a+b��ֵ���ֵĴ���
//        for (int a : A) {
//            for (int b : B) {
//                umap[a + b]++;
//            }
//        }
//        int count = 0; // ͳ��a+b+c+d = 0 ���ֵĴ���
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
//    //�����������
//    /**
//     * ��Ծ��Ϸ.
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
//     * ��С��Ծ����.
//     * 
//     * \param nums
//     * \return 
//     */
//    int jump(vector<int>& nums) {
//        int curDistance = 0;    // ��ǰ���ǵ���Զ�����±�
//        int ans = 0;            // ��¼�ߵ������
//        int nextDistance = 0;   // ��һ�����ǵ���Զ�����±�
//        for (int i = 0; i < nums.size() - 1; i++) { // ע��������С��nums.size() - 1�����ǹؼ�����
//            nextDistance = max(nums[i] + i, nextDistance); // ������һ�����ǵ���Զ�����±�
//            if (i == curDistance) {                 // ������ǰ���ǵ���Զ�����±�
//                curDistance = nextDistance;         // ���µ�ǰ���ǵ���Զ�����±�
//                ans++;
//            }
//        }
//        return ans;
//    }
//    /**
//     * �ϲ�����.
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
//    //����
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> result;
//        if (intervals.size() == 0) return result; // ���伯��Ϊ��ֱ�ӷ���
//        // ����Ĳ���ʹ����lambda���ʽ
//        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
//
//        // ��һ������Ϳ��ԷŽ���������������ص�����result��ֱ�Ӻϲ�
//        result.push_back(intervals[0]);
//
//        for (int i = 1; i < intervals.size(); i++) {
//            if (result.back()[1] >= intervals[i][0]) { // �����ص�����
//                // �ϲ����䣬ֻ�����ұ߽�ͺã���Ϊresult.back()����߽�һ������Сֵ����Ϊ���ǰ�����߽������
//                result.back()[1] = max(result.back()[1], intervals[i][1]);
//            }
//            else {
//                result.push_back(intervals[i]); // ���䲻�ص� 
//            }
//        }
//        return result;
//    }
//    /**
//     * �����������ļ���������.
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
//    //����
//    static bool cmp(const vector<int>& a, const vector<int>& b) {
//        return a[0] < b[0];
//    }
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.size() == 0) return 0;
//        sort(points.begin(), points.end(), cmp);
//
//        int result = 1; // points ��Ϊ��������Ҫһ֧��
//        for (int i = 1; i < points.size(); i++) {
//            if (points[i][0] > points[i - 1][1]) {  // ����i������i-1�����ţ�ע�����ﲻ��>=
//                result++; // ��Ҫһ֧��
//            }
//            else {  // ����i������i-1����
//                points[i][1] = min(points[i - 1][1], points[i][1]); // �����ص�������С�ұ߽�
//            }
//        }
//        return result;
//    }
//    /**
//     * ���ص�����.
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
//            if (intervals[i][0] < intervals[i - 1][1]) { //�ص����
//                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
//                res++;
//            }
//        }
//        return res;
//    }
//    /**
//     * ������ĸ����.
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
//    //����
//    vector<int> partitionLabels(string S) {
//        int hash[27] = { 0 }; // iΪ�ַ���hash[i]Ϊ�ַ����ֵ����λ��
//        for (int i = 0; i < S.size(); i++) { // ͳ��ÿһ���ַ������ֵ�λ��
//            hash[S[i] - 'a'] = i;
//        }
//        vector<int> result;
//        int left = 0;
//        int right = 0;
//        for (int i = 0; i < S.size(); i++) {
//            right = max(right, hash[S[i] - 'a']); // �ҵ��ַ����ֵ���Զ�߽�
//            if (i == right) {
//                result.push_back(right - left + 1);
//                left = i + 1;
//            }
//        }
//        return result;
//    }
//};
