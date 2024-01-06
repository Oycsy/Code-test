#pragma once
#include <iostream>
#include <istream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class SlideWindowSolution{
public:
	/**
	 * 寻找数组中心点下标.
	 * 
	 * \param nums
	 * \return 
	 */
	int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num; // 求和
        int leftSum = 0;    // 中心索引左半和
        int rightSum = 0;   // 中心索引右半和
        for (int i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            rightSum = sum - leftSum + nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
	}

    /**
     * 和为K的子数组.
     * 
     * \param nums
     * \param k
     * \return 
     */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int pre = 0;
        int count = 0;
        map[0]++;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (map[pre - k] > 0) count += map[pre - k];
            map[pre]++;
        }
        return count;
    }
    /**
     * 长度最小的子数组.
     * 
     * \param target
     * \param nums
     * \return 
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int res = INT_MAX;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < len; right++) {
            sum += nums[right];
            while (sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }

        }
        return res == INT_MAX ? 0 : res;
    }
    /**
     * 子数组最大平均数 I.
     * 
     * \param nums
     * \param k
     * \return 
     */
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int right = 0;
        int res = INT_MAX;
        for (; right < k; right++) {
            sum += nums[right];
        }
        res = sum;
        for (; right < nums.size(); right++) {
            sum -= nums[left];
            sum += nums[right];
            res = max(res, sum);
            left++;
        }
        return (double)res / k;
    }
    /**
     * 移除元素.
     * 
     * \param nums
     * \param val
     * \return 
     */
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }            
        }
        return slow;
    }
    /**
     * 反转字符串.
     * 
     * \param s
     */
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            right--;
            left++;
        }
        return;
    }
    /**
     * 翻转固定字符串.
     * 
     * \param s
     * \param k
     * \return 
     */
    string reverseStr(string s, int k) {
        int index = 0;
        while (index < s.length()) {
            if(s.length() - index < k) reverse(s.begin() + index, s.end());
            else reverse(s.begin() + index, s.begin() + index + k);
            index += 2 * k;
        }
        return s;
    }
    /**
     * 反转字符串中的单词.
     * 
     * \param s
     * \return 
     */
    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        int end = s.length() - 1;
        int start = s.length() - 1;
        string res = "";
        while (end >= 0 && start >= 0) {
            if (s[end] == ' ') {
                start--;
                end--;
                if (end < 0) break;
            }
            while (s[start] != ' ') {
                start--;
                if (start < 0) break;
            }
            if (start < 0) {
                res += s.substr(0, end + 1);
                break;
            }
            res += s.substr(start + 1, end - start);
            res += " ";
            start--;
            end = start;
        }
        return res;
    }
    /**
     * 无重复字符的最长子串.
     * 
     * \param s
     * \return 
     */
    int lengthOfLongestSubstring(string s) { 
        int res = 0;
        set<char> set;
        set.clear();
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            while (set.count(s[end])) {
                set.erase(s[start]);
                start++;
            }
            set.insert(s[end]);
            res = max(res, end - start + 1);
        }
        return res;
    }
    /**
     * 删除子数组中最大的得分.
     * 
     * \param nums
     * \return 
     */
    int maximumUniqueSubarray(vector<int>& nums) {

    }

    /**
     * 找到字符串中所有字母异位词.
     * 
     * \param s
     * \param p
     * \return 
     */
    bool isTrue(unordered_map<char, int>& mapp, unordered_map<char, int> &maps) {
        for (auto it : mapp) {
            auto sit = maps.find(it.first);
            if (sit == maps.end()) return false;
            if (sit != maps.end() && sit->second != it.second) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int start = 0;
        int end = 0;
        vector<int> res;
        unordered_map<char, int> mapp;
        for (char c : p) mapp[c]++;
        unordered_map<char, int> maps;
        for (; end < p.length(); end++) {
            maps[s[end]]++;
        }
        if (maps == mapp) res.push_back(start);
        for (; end < s.length(); end++) {
            maps[s[start]]--;
            start++;
            maps[s[end]]++;
            if (isTrue(mapp,maps)) res.push_back(start);
        }
        return res;
    }

    /**
     *  字符串的排列.
     * 
     * \param s1
     * \param s2
     * \return 
     */
    bool isTrue(unordered_map<char, int>& mapp, unordered_map<char, int>& maps) {
        for (auto it : mapp) {
            auto sit = maps.find(it.first);
            if (sit == maps.end()) return false;
            if (sit != maps.end() && sit->second != it.second) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int start = 0;
        int end = 0;
        unordered_map<char, int> mapp;
        for (char c : s1) mapp[c]++;
        unordered_map<char, int> maps;
        for (; end < s1.length(); end++) {
            maps[s2[end]]++;
        }
        if (isTrue(mapp, maps)) return true;
        for (; end < s2.length(); end++) {
            maps[s2[start]]--;
            start++;
            maps[s2[end]]++;
            if (isTrue(mapp, maps)) return true;
        }
        return false;
    }
    /**
     * 找出字符串中第一个匹配项的下标.
     * 
     * \param haystack
     * \param needle
     * \return 
     */
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        int len = needle.length();
        for (int i = 0; i < haystack.length() - len; i++) {
            if (haystack[i] != needle[0]) continue;
            if (haystack.substr(i, len) == needle) return i;
        }
        return -1;
    }

    /**
     * 重复的子字符串.
     * 
     * \param s
     * \return 
     */
    bool repeatedSubstringPattern(string s) {
        string str = s;
        str += s;
        int len = s.length();
        for (int i = 1; i < str.length() - len; i++) {
            if (str[i] != s[0]) continue;
            if (str.substr(i, len) == s) return true;
        }
        return false;
    }
    /**
     * 删除子数组.
     * 
     * \param nums
     * \return 
     */
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> set;
        int start = 0;
        int res = 0;
        int sum = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (set.count(nums[end])) {
                sum -= nums[start];
                set.erase(nums[start]);
                start++;
            }
            set.insert(nums[end]);
            sum += nums[end];
            res = max(sum, res);
        }
        return res;
    }
    /**
     * 最小覆盖子串.
     * 
     * \param s
     * \param t
     * \return 
     */
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto& p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto& c : t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
    /**
     * 移动零.
     * 
     * \param nums
     */
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int count = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) nums[slow++] = nums[fast];
            else count++;
        }
        for (int i = nums.size() - 1; i >= nums.size() - 1 - count; i--) nums[i] = 0;
    }
    /**
     * 验证回文串.
     * 
     * \param s
     * \return 
     */
    bool isPalindrome(string s) {
        int slow = 0;
        for (int fast = 0; fast < s.length(); fast++) {
            if (isalnum(s[fast])) s[slow++] = s[fast];
        }
        s.resize(slow);
        for (char& ch : s) {
            ch = std::tolower(ch);
        }
        if (s.length() == 1) return true;
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    /**
     * x的平方根--二分法.
     * 
     * \param x
     * \return 
     */
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1;
        int right = x / 2 + 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid > x / mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
    /**
     * 寻找重复的数.
     * 
     * \param nums
     * \return 
     */
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (set.count(nums[i])) {
                res = nums[i];
                break;
            }
            set.insert(nums[i]);
        }
        return res;
    }
    //或者
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
};
