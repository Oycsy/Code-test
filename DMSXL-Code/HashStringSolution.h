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

class HashStringSolution {
	/**
	 * ���ظ�����.
	 * 
	 * \param nums
	 * \return 
	 */
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		set<int> res;
		for (int i : nums) {
			if (res.count(i) > 0) return true;
			res.insert(i);
		}
		return false;
	}
	/**
	 * �����.
	 * 
	 * \param ransomNote
	 * \param magazine
	 * \return 
	 */
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map <char, int> umap;
		for (auto a : magazine) {
			umap[a]++;
		}
		for (auto b : ransomNote) {
			if (umap[b] > 0) {
				umap[b]--;
			}
			else return false;
		}
		return true;
	}
	/**
	 * ����Ĵ�.
	 * 
	 * \param s
	 * \return 
	 */
	int longestPalindrome(string s) {
		unordered_map<char, int> map;
		int res = 0;
		for (char c : s) map[c]++;

		for (auto it : map) {
			int num = 2 * (it.second / 2);
			res += num;
			if (res % 2 == 0 && it.second % 2 == 1) res++;
		}
		return res;
	}
};
