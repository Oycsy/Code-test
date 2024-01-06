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
using namespace std;

///����ʱ����ҵ���Сֵ
class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if(min_st.empty()) min_st.push(val);
        else if (val <= min_st.top()) {
            min_st.push(val);
        }
        return;
    }

    void pop() {
        int val = st.top();
        st.pop();
        if (val == min_st.top()) min_st.pop();
        return;
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

//��ջʵ�ֶ��� 
class MyQueue {
public:
    MyQueue() {}
    void push(int x) {
        inst.push(x);
    }
    int pop() {
        int res = 0;
        while (!inst.empty()) {
            outst.push(inst.top());
            inst.pop();
        }
        res = outst.top();
        outst.pop();
        while (!outst.empty()) {
            inst.push(outst.top());
            outst.pop();
        }
        return res;
    }
    int peek() {
        int res = 0;
        while (!inst.empty()) {
            outst.push(inst.top());
            inst.pop();
        }
        res = outst.top();
        while (!outst.empty()) {
            inst.push(outst.top());
            outst.pop();
        }
        return res;
    }
    bool empty() {
        return inst.empty() && outst.empty();
    }

private:
    stack<int> inst;
    stack<int> outst;
};

//�ö���ʵ��ջ
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // ��que1 ����que2����Ҫ�������һ��Ԫ��
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // ���µ����һ��Ԫ�ؾ���Ҫ���ص�ֵ
        que1.pop();
        que1 = que2;            // �ٽ�que2��ֵ��que1
        while (!que2.empty()) { // ���que2
            que2.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top() {
        return que1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty() && que2.empty();
    }
private:
    queue<int> que1;
    queue<int> que2; 
};

//ѭ��˫�˶���
class MyCircularDeque {
private:
    int _maxsize;
    queue<int> qu;
    queue<int> tmpqu;
public:
    MyCircularDeque(int k) {
        _maxsize = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        tmpqu.push(value);
        while (!qu.empty()) {
            tmpqu.push(qu.front());
            qu.pop();
        }
        while (!tmpqu.empty()) {
            qu.push(tmpqu.front());
            tmpqu.pop();
        }
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        qu.push(value);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        qu.pop();
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        int count = 0;
        while (!qu.empty()) {
            tmpqu.push(qu.front());
            qu.pop();
            count++;
        }
        while (count > 1) {
            qu.push(tmpqu.front());
            tmpqu.pop();
            count--;
        }
        tmpqu.pop();
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        else return qu.front();
    }

    int getRear() {
        if (isEmpty()) return -1;
        else return qu.back();
    }

    bool isEmpty() {
        if (qu.size() == 0) return true;
        else return false;
    }

    bool isFull() {
        if (qu.size() == _maxsize) return true;
        else return false;
    }

};


class SackAndQueueSolution {
public:
    char couple(char c) {
        if (c == '(') return ')';
        if (c == '{') return '}';
        if (c == '[') return ']';
        else return NULL;
    }
    /**
     * ��Ч����.
     * 
     * \param s
     * \return 
     */
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && s[i] == couple(st.top())) st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
    /**
     * ��֤ջ����.
     * 
     * \param pushed
     * \param popped
     * \return 
     */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int index1 = 0;
        int index2 = 0;
        while (index1 < pushed.size()) {
            st.push(pushed[index1]);
            while (!st.empty() && popped[index2] == st.top()) {
                st.pop();
                index2++;
            }
            index1++;
        }
        return st.empty();
    }
    /**
     * ɾ���ַ����е����������ظ���.
     * 
     * \param s
     * \return 
     */
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && s[i] == st.top()) st.pop();
            else st.push(s[i]);
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    /**
     * ����������.
     * 
     * \param s
     * \return 
     */
    void replace(string& s) {
        int pos = s.find(" ");
        while (pos != -1) {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }
    }
    int calculate(string s) {
        // ������е�����
        stack<int> nums;
        // Ϊ�˷�ֹ��һ����Ϊ���������� nums �Ӹ� 0
        nums.push(0);
        // �����еĿո�ȥ��
        replace(s);
        // ������еĲ��������� +/-
        stack<char> ops;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')
                ops.push(c);
            else if (c == ')') {
                // ���㵽���һ��������Ϊֹ
                while (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(')
                        calc(nums, ops);
                    else {
                        ops.pop();
                        break;
                    }
                }
            }
            else {
                if (isdigit(c)) {
                    int cur_num = 0;
                    int j = i;
                    // ���� i λ�ÿ�ʼ�����������������ȡ�������� nums
                    while (j < n && isdigit(s[j]))
                        cur_num = cur_num * 10 + (s[j++] - '0');
                    // ע������ļ���һ��Ҫ�����ţ������п��ܻ����
                    nums.push(cur_num);
                    i = j - 1;
                }
                else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }
                    // ��һ���²���Ҫ��ջʱ���Ȱ�ջ�ڿ�����Ķ�����
                    while (!ops.empty() && ops.top() != '(')
                        calc(nums, ops);
                    ops.push(c);
                }
            }
        }
        while (!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
    void calc(stack<int>& nums, stack<char>& ops) {
        if (nums.size() < 2 || ops.empty())
            return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(op == '+' ? a + b : a - b);
    }
    //����
    int calculate2(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            }
            else if (s[i] == '+') {
                sign = ops.top();
                i++;
            }
            else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            }
            else if (s[i] == '(') {
                ops.push(sign);
                i++;
            }
            else if (s[i] == ')') {
                ops.pop();
                i++;
            }
            else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
    /**
     * �Ƶ� K λ����.
     * 
     * \param num
     * \param k
     * \return 
     */
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            if (st.empty() && num[i] == '0') continue;
            st.push(num[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        if (st.empty()) return "0";

        string s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
    /**
     * ���Ч����.
     * 
     * \param s
     * \return 
     */
    int longestValidParentheses(string s) {
        int len = 0;
        int start = 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) {
                    start = i + 1;
                }
                else {
                    st.pop();
                    if (st.empty()) len = max(len, i - start + 1);
                    else len = max(len, i - (st.top() + 1) + 1);
                }
            }            
        }
        return len;
    }
    /**
     * �ַ�������.
     * 
     * \param s
     * \return 
     */
    string decodeString(string s) {
        stack<int> num;
        stack<string> letter;
        string res = "";
        int k = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                k = 10 * k + (s[i] - '0');
            }
            else if (!isdigit(s[i]) && s[i] != '[' && s[i] != ']') {
                res += s[i];
            }
            else if (s[i] == '[') {
                num.push(k);
                k = 0;
                letter.push(res);
                res = "";
            }
            else {
                int times = num.top();
                num.pop();
                for (int j = 0; j < times; j++) {
                    letter.top() += res;                    
                }
                res = letter.top();
                letter.pop();
            }
        }
        return res;
    }
    /**
     * ÿ���¶�.
     *
     * \param temperatures
     * \return
     */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }      
            st.push(i);
        }
        return res;
    }
    
    /**
     * ǰK����ƵԪ��.
     * 
     * \param nums
     * \param k
     * \return 
     */
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pr;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (pr.size() == k && it->second <= pr.top().second) continue;
            pr.push(*it);
            if (pr.size() > k) {
                pr.pop();
            }
        }
        while (!pr.empty()) {
            res.push_back(pr.top().first);
            pr.pop();
        }
        return res;
    }
    /**
     * �����еĵ�K�����Ԫ��.
     * 
     * \param nums
     * \param k
     * \return 
     */
    int findKthLargest(vector<int>& nums, int k) {
        //��ʹ�� std::greater<int> ��Ϊ������ģ�����ʱ��
        //������ʽָ����������Ϊ std::vector<int> �������������͡�
        //�����ָ���������ͣ����������
        priority_queue<int, vector<int>, greater<int>> pr;//Ĭ�ϴ󶥶�
        for (int i = 0; i < nums.size(); i++) {
            if (pr.size() == k && nums[i] <= pr.top()) continue;
            pr.push(nums[i]);
            if (pr.size() > k) {
                pr.pop();
            }
        }
        return pr.top();
    }
    //������
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargestStack(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }

    /**
     * �沨�����ʽ.
     * 
     * \param tokens
     * \return 
     */
    int res(int a, int b, string s) {
        if (s == "+") return a + b;
        if (s == "-") return b - a;
        if (s == "*") return a * b;
        else return b / a;
    }
    bool isCol(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        else return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (int i = 0; i < tokens.size(); i++) {
            if (!isCol(tokens[i])) num.push(stoi(tokens[i]));
            else {
                int a = num.top(); num.pop();
                int b = num.top(); num.pop();
                num.push(res(a, b, tokens[i]));
            }
        }
        return num.top();
    }
    /**
     * ��һ�������Ԫ��.
     * 
     * \param nums1
     * \param nums2
     * \return 
     */
    int bigNum(vector<int>& nums2, int index,int val) {
        int res = -1;
        for (int i = index; i < nums2.size(); i++) {
            if (nums2[i] > val) {
                res = nums2[i];
                break;
            }
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> mp2;
        for (int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(bigNum(nums2, mp2[nums1[i]], nums1[i]));
        }
        return res;
    }
    /**
     * ѭ���������һ�������Ԫ��.
     * 
     * \param nums
     * \return 
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> st;
        for (int i = 0; i < len * 2; i++) {
            while (!st.empty() && nums[i % len] > nums[st.top()]) {
                res[st.top()] = nums[i % len];
                st.pop();
            }
            st.push(i % len);
        }
        return res;
    }
    /**
     * ����ˮ.
     *
     * \param height
     * \return
     */

    int trap(vector<int>& height) {
        int res = 0;
        vector<int> leftMax(height.size(), -1);
        vector<int> rightMax(height.size(), -1);
        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        // ��¼ÿ�������ұ��������߶�
        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        for (int i = 0; i < height.size(); i++) {
            res += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
    //����
    int trapStack(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }

    /**
     * ���ε�������.
     * 
     * \param heights
     * \return 
     */
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> leftMin(len);
        vector<int> rightMin(len);

        leftMin[0] = -1;
        for (int i = 1; i < len; i++) {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) t = leftMin[t];
            leftMin[i] = t;
        }

        rightMin[len - 1] = len;
        for (int i = len - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < len && heights[t] >= heights[i]) t = rightMin[t];
            rightMin[i] = t;
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            int sum = heights[i] * (rightMin[i] - leftMin[i] - 1);
            res = max(sum, res);
        }
        return res;
    }
    //����
    int largestRectangleAreaStack(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // ����ͷ������Ԫ��0
        heights.push_back(0); // ����β������Ԫ��0
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
    /**
     * �����������ֵ.
     * 
     * \param nums
     * \param k
     * \return 
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> qu;
        int count = 1;
        for (int i = 0; i < k; i++) {
            while (!qu.empty() && nums[i] >= nums[qu.back()]) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        res.push_back(nums[qu.front()]);
        cout << "nums[qu.front()] = " << nums[qu.front()] << endl;
        for (int i = k; i < nums.size(); i++) {            
            while (!qu.empty() && qu.front() < count) qu.pop_front();
            while (!qu.empty() && nums[i] > nums[qu.back()]) {
                cout << "i = " << i << endl;
                cout << "nums[qu.back()] = " << nums[qu.back()] << endl;
                qu.pop_back();
            }
            qu.push_back(i);
            cout << "nums[qu.front()] = " << nums[qu.front()] << endl;
            res.push_back(nums[qu.front()]);
            count++;
        }
        return res;
    }
    
};
