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

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class RecursionSolution{
	/**
	 * ��Ч����ĸ��λ��.
	 * 
	 * \param s
	 * \param t
	 * \return 
	 */
	bool isAnagram(string s, string t) {
		unordered_map<char, int> maps;
		unordered_map<char, int> mapt;
		for (char c : s) maps[c]++;
		for (char c : t) mapt[c]++;

		if (maps == mapt) return true;
		else return false;
	}
	/**
	 * ��������Ľ���.
	 * 
	 * \param nums1
	 * \param nums2
	 * \return 
	 */
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set1;
		set<int> set2;
		for (int n : nums1) set1.insert(n);
		for (int n : nums2) set2.insert(n);

		vector<int> res;
		for (auto it : set1) {
			if (set2.count(it)) res.push_back(it);
		}
		return res;
	}
	/**
	 * �����.
	 * 
	 * \param nums
	 * \return 
	 */
	string largestNumber(vector<int>& nums) {
		string res = "";
		sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
			return to_string(x) + to_string(y) > to_string(y) + to_string(x);
			});
		if (nums[0] == 0) {
			return "0";
		}
		for (int& x : nums) {
			res += to_string(x);
		}
		return res;
	}
	/**
	 * �������.
	 * 
	 * \param l1
	 * \param l2
	 * \return 
	 */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = nullptr, * tail = nullptr;
		int count = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int num = n1 + n2 + count;
			
			if (!head) {
				head = tail = new ListNode(num % 10);
			}
			else {
				tail->next = new ListNode(num % 10);
				tail = tail->next;
			}
			count = num / 10;
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}
		if (count > 0) {
			tail->next = new ListNode(count);
		}
		return head;
	}
	//�ڶ���
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur) {
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head1 = reverseList(l1);
		ListNode* head2 = reverseList(l2);
		ListNode* head = nullptr, * tail = nullptr;
		int count = 0;
		while (head1 || head2) {
			int n1 = head1 ? head1->val : 0;
			int n2 = head2 ? head2->val : 0;
			int num = n1 + n2 + count;

			if (!head) {
				head = tail = new ListNode(num % 10);
			}
			else {
				tail->next = new ListNode(num % 10);
				tail = tail->next;
			}
			count = num / 10;
			if (head1) {
				head1 = head1->next;
			}
			if (head2) {
				head2 = head2->next;
			}
		}
		if (count > 0) {
			tail->next = new ListNode(count);
		}
		return reverseList(head);
	}

	//�ڶ��ֿ���ʹ��ջ�ķ���
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		while (l1) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			s2.push(l2->val);
			l2 = l2->next;
		}
		int carry = 0;
		ListNode* ans = nullptr;
		while (!s1.empty() or !s2.empty() or carry != 0) {
			int a = s1.empty() ? 0 : s1.top();
			int b = s2.empty() ? 0 : s2.top();
			if (!s1.empty()) s1.pop();
			if (!s2.empty()) s2.pop();
			int cur = a + b + carry;
			carry = cur / 10;
			cur %= 10;
			auto curnode = new ListNode(cur);
			curnode->next = ans;
			ans = curnode;
		}
		return ans;
	}
	/**
	 * ��ɫ����.
	 * 
	 * \param nums
	 */
	void sortColors(vector<int>& nums) {
		int temp;
		for (int step = nums.size() / 2; step > 0; step /= 2) {
			for (int i = step; i < nums.size(); i++) {
				int j = i;
				temp = nums[j];
				if (nums[j] < nums[j - step]) {
					while (j - step >= 0 && temp < nums[j - step]) {
						nums[j] = nums[j - step];
						j -= step;
					}
					nums[j] = temp;
				}
			}
		}
	}
	/**
	 * ��������--�鲢����.
	 * 
	 * \param head
	 * \return 
	 */
	/*ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode* slow = head, * fast = head;
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}

	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* dummyHead = new ListNode(0);
		ListNode* temp = dummyHead, * temp1 = head1, * temp2 = head2;
		while (temp1 != nullptr && temp2 != nullptr) {
			if (temp1->val <= temp2->val) {
				temp->next = temp1;
				temp1 = temp1->next;
			}
			else {
				temp->next = temp2;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		if (temp1 != nullptr) {
			temp->next = temp1;
		}
		else if (temp2 != nullptr) {
			temp->next = temp2;
		}
		return dummyHead->next;
	}*/

	//����--����
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dp = new ListNode(-1);
		ListNode* pre = dp;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				pre->next = l1;
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		pre->next = (l1 ? l1 : l2);
		return dp->next;
	}

	ListNode* sortList(ListNode* head) {
		int len = 0;
		ListNode* node = head;
		while (node) {
			len++;
			node = node->next;
		}
		ListNode* dp = new ListNode(-1, head);
		for (int subLength = 1; subLength < len; subLength += 2) {
			ListNode* prev = dp;
			ListNode* cur = dp->next;
			while (cur) {
				ListNode* head1 = cur;
				for (int i = 1; i < subLength && cur->next; i++) {
					cur = cur->next;
				}
				ListNode* head2 = cur->next;
				cur->next = nullptr;
				cur = head2;
				for (int i = 1; i < subLength && cur && cur->next; i++) {
					cur = cur->next;
				}
				ListNode* next0 = nullptr;
				if (cur) {
					next0 = cur->next;
					cur->next = nullptr;
				}
				ListNode* merged = mergeTwoLists(head1, head2);

				prev->next = merged;
				while (prev->next) prev = prev->next;
				cur = next0;
			}
		}
		return dp->next;
	}

	/**
	 * �ϲ� K ����������.
	 * 
	 * \param lists
	 * \return 
	 */
	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		if ((!a) || (!b)) return a ? a : b;
		ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
		while (aPtr && bPtr) {
			if (aPtr->val < bPtr->val) {
				tail->next = aPtr; aPtr = aPtr->next;
			}
			else {
				tail->next = bPtr; bPtr = bPtr->next;
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr);
		return head.next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ans = nullptr;
		for (size_t i = 0; i < lists.size(); ++i) {
			ans = mergeTwoLists(ans, lists[i]);
		}
		return ans;
	}
	/**
	 * ð������.
	 * 
	 * \param nums
	 */
	void bollsort(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = 0; j < nums.size() - i - 1; j++) {
				if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
			}
		}
	}

	/**
	 * ��������.
	 *
	 * \param nums
	 */
	void insertsort(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			int j = i - 1;
			int val = nums[i];
			for (; j >= 0 && nums[j] > val; j--) {
				nums[j + 1] = nums[j];
			}
			nums[j + 1] = val;
		}
	}

	/**
	 * ѡ������.
	 *
	 * \param nums
	 */
	void choosesort(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			int index = i;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] < nums[index]) {
					index = j;
				}
			}
			swap(nums[index], nums[i]);
		}
	}

	/**
	 * �鲢����.
	 * 
	 * \param nums
	 */
	 // �ϲ�����������Ϊһ����������
	void merge(std::vector<int>& arr, int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		// ������ʱ�������洢����������
		std::vector<int> leftArr(n1);
		std::vector<int> rightArr(n2);

		for (int i = 0; i < n1; i++) {
			leftArr[i] = arr[left + i];
		}
		for (int i = 0; i < n2; i++) {
			rightArr[i] = arr[mid + i + 1];
		}

		int i = 0, j = 0, k = left;

		// �ϲ�����������Ϊһ����������
		while (i < n1 && j < n2) {
			if (leftArr[i] <= rightArr[j]) {
				arr[k] = leftArr[i];
				i++;
			}
			else {
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = leftArr[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = rightArr[j];
			j++;
			k++;
		}
	} 
	void mergeSort(std::vector<int>& arr, int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}
	
	/**
	 * ��������.
	 * 
	 * \param nums
	 */
	 // ������ֳ������֣����Ԫ��С�ڻ�׼ֵ���ұ�Ԫ�ش��ڻ�׼ֵ
	int partition(vector<int>& nums, int left, int right) {
		int pivot = nums[left]; // ѡȡ���ұߵ�Ԫ����Ϊ��׼ֵ
		while (left < right) {
			while (left < right && nums[right] > pivot) {
				right--;
			}
			nums[left] = nums[right];

			while (left < right && nums[left] < pivot) {
				left++;
			}
			nums[right] = nums[left];
		}
		nums[left] = pivot;
		return left;
	}

	// ���������㷨
	void quickSort(vector<int>& nums, int left, int right) {
		if (left >= right) return;
		int mid = partition(nums, left, right); // ������ֳ������֣������ػ�׼ֵ������
		quickSort(nums, left, mid - 1); // �Ի�׼ֵ��ߵ���������п�������
		quickSort(nums, mid + 1, right); // �Ի�׼ֵ�ұߵ���������п�������
	}

	/**
	 * ������.
	 */
	// ����rootIndexΪ���ڵ���������жѵ���
	void heapify(vector<int>& nums, int rootIndex, int heapSize) {
		int largest = rootIndex; // ��ʼ�����ڵ�Ϊ���ֵ
		int left = 2 * rootIndex + 1; // ���ӽڵ������
		int right = 2 * rootIndex + 2; // �Һ��ӽڵ������

		// ������ӽڵ�����Ҵ��ڸ��ڵ㣬��������ֵ������
		if (left < heapSize && nums[left] > nums[largest]) {
			largest = left;
		}

		// ����Һ��ӽڵ�����Ҵ��ڸ��ڵ�����ӽڵ㣬��������ֵ������
		if (right < heapSize && nums[right] > nums[largest]) {
			largest = right;
		}

		// ������ֵ���Ǹ��ڵ㣬�򽻻����ڵ�����ֵ��λ�ã����ݹ��������
		if (largest != rootIndex) {
			swap(nums[rootIndex], nums[largest]);
			heapify(nums, largest, heapSize);
		}
	}

	// �������㷨
	void heapSort(vector<int>& nums) {
		int n = nums.size();

		// �������ѣ������һ����Ҷ�ӽڵ㿪ʼ���жѵ���
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(nums, i, n);
		}

		// ��������ֵ�Ƶ�����ĩβ�������µ�����
		for (int i = n - 1; i > 0; i--) {
			swap(nums[0], nums[i]);
			heapify(nums, 0, i);
		}
	}
	/**
	 * ��������.
	 * 
	 * \param nums
	 * \return 
	 */
	vector<int> subSort(vector<int>& array) {
		if (array.size() <= 0) return { -1,-1 };
		int m = -1;		
		int minRight = array[array.size() - 1];		
		for (int right = array.size() - 2; right >= 0; right--) {
			int cur = array[right];
			if (cur <= minRight) minRight = cur;
			else m = right;
		}

		int n = -1;
		int minLeft = array[0];
		for (int left = 1; left < array.size(); left++) {
			int cur = array[left];
			if (cur >= minLeft) minLeft = cur;
			else n = left;
		}
		return { m,n };
	}
};
