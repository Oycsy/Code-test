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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class BinaryTreeSolution {
	/**
	 * 二叉树的前序遍历.
	 * 
	 * \param root
	 * \return 
	 */
	vector<int> path;
	void preOrder(TreeNode* root, vector<int> &path) {
		if (root != nullptr) {
			path.push_back(root->val);
			preOrder(root->left, path);
			preOrder(root->right, path);
		}
	}
	vector<int> preorderTraversal(TreeNode* root) {
		path.clear();
		preOrder(root, path);
		return path;
	}
	//迭代器
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top(); 
			st.pop();
			result.push_back(node->val);
			if (node->right) st.push(node->right);   
			if (node->left) st.push(node->left);   
		}
		return result;
	}
	/**
	 * 中序遍历.
	 * 
	 * \param root
	 * \return 
	 */
	void inorder(TreeNode* root, vector<int>& path) {
		if (root != nullptr) {
			inorder(root->left, path);
			path.push_back(root->val);
			inorder(root->right, path);
		}
	}
	vector<int> inorderTraversal(TreeNode* root) {
		path.clear();
		inorder(root, path);
		return path;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) { 
				st.push(cur); 
				cur = cur->left; 
			}
			else {
				cur = st.top(); 
				st.pop();
				result.push_back(cur->val); 
				cur = cur->right;            
			}
		}
		return result;
	}

	/**
	 * 后序遍历.
	 * 
	 * \param root
	 * \return 
	 */
	void postorder(TreeNode* root, vector<int>& path) {
		if (root != nullptr) {
			postorder(root->left, path);
			postorder(root->right,path);
			path.push_back(root->val);
		}
	}
	vector<int> postorderTraversal(TreeNode* root) {
		path.clear();
		postorder(root, path);
		return path;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);			
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}

	/**
	 * 前中后统一迭代.
	 * 
	 * \param root
	 * \return 
	 */
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				if (node->right) st.push(node->right);  // 右
				if (node->left) st.push(node->left);    // 左
				st.push(node);                          // 中
				st.push(NULL);
			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				result.push_back(node->val);
			}
		}
		return result;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
				if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

				st.push(node);                          // 添加中节点
				st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

				if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
			}
			else { // 只有遇到空节点的时候，才将下一个节点放进结果集
				st.pop();           // 将空节点弹出
				node = st.top();    // 重新取出栈中元素
				st.pop();
				result.push_back(node->val); // 加入到结果集
			}
		}
		return result;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != NULL) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				st.push(node);                          // 中
				st.push(NULL);

				if (node->right) st.push(node->right);  // 右
				if (node->left) st.push(node->left);    // 左

			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				result.push_back(node->val);
			}
		}
		return result;
	}


	
	/**
	 * 层序遍历.
	 * 
	 * \param root
	 * \return 
	 */
	void order(TreeNode* cur, vector<vector<int>>& result, int depth)
	{
		if (cur == nullptr) return;
		if (result.size() == depth) result.push_back(vector<int>());
		result[depth].push_back(cur->val);
		order(cur->left, result, depth + 1);
		order(cur->right, result, depth + 1);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		int depth = 0;
		order(root, result, depth);
		return result;
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
	}
	/**
	 * 锯齿层序遍历.
	 * 
	 * \param root
	 * \return 
	 */
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;			
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		bool isOrderLeft = true;
		while (!nodeQueue.empty()) {
			deque<int> levelList;
			int size = nodeQueue.size();
			for (int i = 0; i < size; ++i) {
				auto node = nodeQueue.front();
				nodeQueue.pop();
				if (isOrderLeft) levelList.push_back(node->val);
				else levelList.push_front(node->val);

				if (node->left) nodeQueue.push(node->left);
				if (node->right) nodeQueue.push(node->right);
			}
			ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
			isOrderLeft = !isOrderLeft;
		}
		return ans;
	}
	/**
	 * 路径总和.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	bool hasPathSum(TreeNode* root, int targetSum) {

	}
	/**
	 * 翻转二叉树.
	 * 
	 * \param root
	 * \return 
	 */
	//递归
	TreeNode* invertTree(TreeNode* root) {
		transal(root);
		return root;
	}
	void transal(TreeNode* cur) {
		if (cur == nullptr) return;
		TreeNode* tmp = cur->left;
		cur->left = cur->right;
		cur->right = tmp;
		transal(cur->left);
		transal(cur->right);
	}
	//前序遍历
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*> st;
		if (root != nullptr) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				if (node->right) st.push(node->right);  // 右
				if (node->left) st.push(node->left);    // 左
				st.push(node);                          // 中
				st.push(NULL);
			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				swap(node->left, node->right);          // 节点处理逻辑
			}
		}
		return root;
	}
	
	/**
	 * 对称二叉树.
	 * 
	 * \param root
	 * \return 
	 */
	//迭代法
	bool compare(TreeNode* left, TreeNode* right) {
		if (left == NULL && right != NULL) return false;
		else if (left != NULL && right == NULL) return false;
		else if (left == NULL && right == NULL) return true;
		else if (left->val != right->val) return false;
		else return compare(left->left, right->right) && compare(left->right, right->left);

	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return compare(root->left, root->right);
	}
	//使用队列迭代
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> que;
		que.push(root->left);   // 将左子树头结点加入队列
		que.push(root->right);  // 将右子树头结点加入队列

		while (!que.empty()) {  // 接下来就要判断这两个树是否相互翻转
			TreeNode* leftNode = que.front(); que.pop();
			TreeNode* rightNode = que.front(); que.pop();
			if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
				continue;
			}

			// 左右一个节点不为空，或者都不为空但数值不相同，返回false
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			que.push(leftNode->left);   // 加入左节点左孩子
			que.push(rightNode->right); // 加入右节点右孩子
			que.push(leftNode->right);  // 加入左节点右孩子
			que.push(rightNode->left);  // 加入右节点左孩子
		}
		return true;
	}
	//使用栈迭代
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> st; // 这里改成了栈
		st.push(root->left);
		st.push(root->right);
		while (!st.empty()) {
			TreeNode* leftNode = st.top(); st.pop();
			TreeNode* rightNode = st.top(); st.pop();
			if (!leftNode && !rightNode) {
				continue;
			}
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			st.push(leftNode->left);
			st.push(rightNode->right);
			st.push(leftNode->right);
			st.push(rightNode->left);
		}
		return true;
	}
	/**
	 * 相同的树.
	 * 
	 * \param p
	 * \param q
	 * \return 
	 */
	//递归法
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}
		else if (p == nullptr || q == nullptr) {
			return false;
		}
		else if (p->val != q->val) {
			return false;
		}
		else {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
	//迭代法
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p != NULL && q == NULL) return false;
		if (p == NULL && q != NULL) return false;

		stack<TreeNode*> st; // 这里改成了栈
		st.push(p);
		st.push(q);
		while (!st.empty()) {
			TreeNode* leftNode = st.top(); st.pop();
			TreeNode* rightNode = st.top(); st.pop();
			if (!leftNode && !rightNode) {
				continue;
			}
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			st.push(leftNode->left);
			st.push(rightNode->left);
			st.push(leftNode->right);
			st.push(rightNode->right);	
		}
		return true;
	}
	/**
	 * 另一棵子树.
	 * 
	 * \param root
	 * \param subRoot
	 * \return 
	 */
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if (isSameTree(node, subRoot)) return true;
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
		return false;
	}
	/**
	 * 路径总和.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	//递归法
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root) return false;
		if (!root->left && !root->right && targetSum == root->val) {
			return true;
		}
		return hasPathSum(root->left, targetSum - root->val) 
			|| hasPathSum(root->right, targetSum - root->val);
	}

	//迭代法
	bool haspathsum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		// 此时栈里要放的是pair<节点指针，路径数值>
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode*, int>(root, root->val));
		while (!st.empty()) {
			pair<TreeNode*, int> node = st.top();
			st.pop();
			// 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
			if (!node.first->left && !node.first->right && sum == node.second) return true;

			// 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
			if (node.first->right) {
				st.push(pair<TreeNode*, int>(node.first->right, 
					node.second + node.first->right->val));
			}

			// 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
			if (node.first->left) {
				st.push(pair<TreeNode*, int>(node.first->left, 
					node.second + node.first->left->val));
			}
		}
		return false;
	}
	//回溯算法
	void traversal7(TreeNode* cur, vector<int>& path, vector<int>& result) {
		path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
		// 这才到了叶子节点
		if (cur->left == NULL && cur->right == NULL) {
			int sum = 0;
			for (int i = 0; i < path.size(); i++) {
				sum += path[i];
			}
			result.push_back(sum);
			return;
		}
		if (cur->left) { // 左 
			traversal7(cur->left, path, result);
			path.pop_back(); // 回溯
		}
		if (cur->right) { // 右
			traversal7(cur->right, path, result);
			path.pop_back(); // 回溯
		}
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		vector<int> result;
		vector<int> path;
		if (root == NULL) return false;
		traversal7(root, path, result);
		for (int n : result) {
			if (n == targetSum)
				return true;
		}
		return false;
	}
	/**
	 * 所有的路径之和.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	void traversal8(TreeNode* cur, vector<int>& path, vector<vector<int>>& result,int target) {
		path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
		// 这才到了叶子节点
		if (cur->left == NULL && cur->right == NULL) {
			int sum = 0;
			for (int i = 0; i < path.size(); i++) {
				sum += path[i];
			}
			if (sum == target) result.push_back(path);
			return;
		}
		if (cur->left) { // 左 
			traversal8(cur->left, path, result,target);
			path.pop_back(); // 回溯
		}
		if (cur->right) { // 右
			traversal8(cur->right, path, result, target);
			path.pop_back(); // 回溯
		}
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> result;
		vector<int> path;
		if (root == NULL) return result;
		traversal8(root, path, result,targetSum);
		return result;
	}	

	/**
	 * 所有路径.
	 * 
	 * \param root
	 * \return 
	 */
	void traversal0(TreeNode* cur, vector<int>& path, vector<string>& result) {
		path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
		// 这才到了叶子节点
		if (cur->left == NULL && cur->right == NULL) {
			string res = "";
			for (int p : path) {
				res += to_string(p) + "->";
			}
			result.push_back(res.substr(0, res.length() - 1));
			return;
		}
		if (cur->left) { // 左 
			traversal0(cur->left, path, result);
			path.pop_back(); // 回溯
		}
		if (cur->right) { // 右
			traversal0(cur->right, path, result);
			path.pop_back(); // 回溯
		}
	}
	//或者
	void traversal1(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中
		if (cur->left == NULL && cur->right == NULL) {
			result.push_back(path);
			return;
		}
		if (cur->left) {
			path += "->";
			traversal1(cur->left, path, result); // 左
			path.pop_back(); // 回溯 '>'
			path.pop_back(); // 回溯 '-'
		}
		if (cur->right) {
			path += "->";
			traversal1(cur->right, path, result); // 右
			path.pop_back(); // 回溯'>'
			path.pop_back(); // 回溯 '-'
		}
	}
	void traversal2(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val); // 中
		if (cur->left == NULL && cur->right == NULL) {
			result.push_back(path);
			return;
		}
		if (cur->left) traversal2(cur->left, path + "->", result); // 左
		if (cur->right) traversal2(cur->right, path + "->", result); // 右
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<int> path;
		if (root == nullptr) return result;
		traversal0(root, path, result);
		return result;
	}
	//迭代法
	vector<string> binaryTreePaths(TreeNode* root) {
		stack<TreeNode*> treeSt;// 保存树的遍历节点
		stack<string> pathSt;   // 保存遍历路径的节点
		vector<string> result;  // 保存最终路径集合
		if (root == NULL) return result;
		treeSt.push(root);
		pathSt.push(to_string(root->val));
		while (!treeSt.empty()) {
			TreeNode* node = treeSt.top(); treeSt.pop(); // 取出节点 中
			string path = pathSt.top(); pathSt.pop();    // 取出该节点对应的路径
			if (node->left == NULL && node->right == NULL) { // 遇到叶子节点
				result.push_back(path);
			}
			if (node->right) { // 右
				treeSt.push(node->right);
				pathSt.push(path + "->" + to_string(node->right->val));
			}
			if (node->left) { // 左
				treeSt.push(node->left);
				pathSt.push(path + "->" + to_string(node->left->val));
			}
		}
		return result;
	}

	/**
	 * 最大深度.
	 * 
	 * \param root
	 * \return 
	 */
	//递归法
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	//前序递归法
	int result;
	void getdepth(TreeNode* node, int depth) {
		result = depth > result ? depth : result; // 中
		if (node->left == NULL && node->right == NULL) return;
		if (node->left) { // 左
			getdepth(node->left, depth + 1);
		}
		if (node->right) { // 右
			getdepth(node->right, depth + 1);
		}
		return;
	}
	int maxDepth(TreeNode* root) {
		result = 0;
		if (root == 0) return result;
		getdepth(root, 1);
		return result;
	}
	//层序遍历迭代法
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // 记录深度
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return depth;
	}
	/**
	 * 最小层数.
	 * 
	 * \param root
	 * \return 
	 */
	//迭代法
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;

		int min_depth = INT_MAX;
		if (root->left != nullptr) min_depth = min(minDepth(root->left), min_depth);
		if (root->right != nullptr) min_depth = min(minDepth(root->right), min_depth);
		return min_depth + 1;
	}
	//层序迭代
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		queue<pair<TreeNode*, int> > que;
		que.emplace(root, 1);
		while (!que.empty()) {
			TreeNode* node = que.front().first;
			int depth = que.front().second;
			que.pop();
			if (node->left == nullptr && node->right == nullptr) {
				return depth;
			}
			if (node->left != nullptr) {
				que.emplace(node->left, depth + 1);
			}
			if (node->right != nullptr) {
				que.emplace(node->right, depth + 1);
			}
		}
		return 0;
	}
	//或者
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // 记录最小深度
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
					return depth;
				}
			}
		}
		return depth;
	}
	/**
	 * N叉数的最大深度.
	 * 
	 * \param root
	 * \return 
	 */
	int maxDepth(Node* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // 记录深度
			for (int i = 0; i < size; i++) {
				Node* node = que.front();
				que.pop();
				for (Node* n : node->children) {
					if (n) que.push(n);
				}
			}
		}
		return depth;
	}
	
	/**
	 * 合并二叉树.
	 * 
	 * \param t1
	 * \param t2
	 * \return 
	 */
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return t2;
		if (t2 == nullptr) return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
	/**
	 * 左子叶之和.
	 * 
	 * \param root
	 * \return 
	 */
	//递归法
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		int leftValue = 0;
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
			leftValue = root->left->val;
		}
		return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
	//迭代法
	int sumOfLeftLeaves(TreeNode* root) {
		stack<TreeNode*> st;
		if (root == NULL) return 0;
		st.push(root);
		int result = 0;
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
				result += node->left->val;
			}
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
		return result;
	}
	/**
	 * 是否是平衡树.
	 * 
	 * \param root
	 * \return 
	 */
	bool isBalanced(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				int leftDeph = maxDepth(node->left);
				int rightDeph = maxDepth(node->right);
				if (abs(leftDeph - rightDeph) > 1) return false;
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}			
		}
		return true;
	}
	/**
	 * 左下角的值.
	 * 
	 * \param root
	 * \return 
	 */
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result[result.size() - 1][0];
	}
	//回溯方法
	int maxNum = INT_MIN;
	int result;
	void traversal(TreeNode* root, int depth) {
		if (root->left == NULL && root->right == NULL) {
			if (depth > maxNum) {
				maxNum = depth;
				result = root->val;
			}
			return;
		}
		if (root->left) {
			traversal(root->left, depth + 1); // 隐藏着回溯
		}
		if (root->right) {
			traversal(root->right, depth + 1); // 隐藏着回溯
		}
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 0);
		return result;
	}

	/**
	 * 最大二叉树.
	 * 
	 * \param nums
	 * \return 
	 */
	TreeNode* traversal6(vector<int>& nums, int left, int right) {
		if (left >= right) return nullptr;

		// 分割点下标：maxValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; ++i) {
			if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		// 左闭右开：[left, maxValueIndex)
		root->left = traversal6(nums, left, maxValueIndex);

		// 左闭右开：[maxValueIndex + 1, right)
		root->right = traversal6(nums, maxValueIndex + 1, right);

		return root;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return traversal6(nums, 0, nums.size());
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (!nums.size()) {
			return NULL;
		}
		int maxNum = -INT_MAX, maxIdx = -1, n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[i] > maxNum) {
				maxNum = nums[i];
				maxIdx = i;
			}
		}
		vector<int> vecL, vecR;
		if (maxIdx) {
			vecL.assign(nums.begin(), nums.begin() + maxIdx);
		}
		if (maxIdx != n) {
			vecR.assign(nums.begin() + maxIdx + 1, nums.end());
		}
		TreeNode* thisNode = new TreeNode(maxNum);

		thisNode->left = constructMaximumBinaryTree(vecL);
		thisNode->right = constructMaximumBinaryTree(vecR);
		return thisNode;
	}

	/**
	 * 二叉树右视图.
	 * 
	 * \param root
	 * \return 
	 */
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if(i == size - 1) result.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}			
		}
		return result;
	}

	/**
	 * 二叉树展开为链表.
	 * 
	 * \param root
	 */
	//迭代法
	void preorderTraversal(TreeNode* root, vector<TreeNode*>& l) {
		if (root != NULL) {
			l.push_back(root);
			preorderTraversal(root->left, l);
			preorderTraversal(root->right, l);
		}
	}

	void flatten(TreeNode* root) {
		vector<TreeNode*> res;
		preorderTraversal(root, res);
		int n = res.size();
		for (int i = 1; i < n; i++) {
			TreeNode* cur = res[i - 1];
			TreeNode* tmp = res[i];
			cur->left = nullptr;
			cur->right = tmp;
		}
	}

	//迭代法
	void flatten(TreeNode* root) {
		auto v = vector<TreeNode*>();
		auto stk = stack<TreeNode*>();
		TreeNode* node = root;
		while (node != nullptr || !stk.empty()) {
			while (node != nullptr) {
				v.push_back(node);
				stk.push(node);
				node = node->left;
			}
			node = stk.top(); stk.pop();
			node = node->right;
		}
		int size = v.size();
		for (int i = 1; i < size; i++) {
			auto prev = v.at(i - 1), curr = v.at(i);
			prev->left = nullptr;
			prev->right = curr;
		}
	}

	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		auto stk = stack<TreeNode*>();
		stk.push(root);
		TreeNode* prev = nullptr;
		while (!stk.empty()) {
			TreeNode* curr = stk.top(); stk.pop();
			if (prev != nullptr) {
				prev->left = nullptr;
				prev->right = curr;
			}
			TreeNode* left = curr->left, * right = curr->right;
			if (right != nullptr) {
				stk.push(right);
			}
			if (left != nullptr) {
				stk.push(left);
			}
			prev = curr;
		}
	}

	/****************************搜索树****************************/
	/**
	 * 验证二叉搜索树.
	 *
	 * \param root
	 * \return
	 */
	void inorder(TreeNode* root, vector<int>& path) {
		if (root != nullptr) {
			inorder(root->left, path);
			path.push_back(root->val);
			inorder(root->right, path);
		}
	}
	bool isValidBST(TreeNode* root) {
		vector<int> path;
		inorder(root, path);
		for (int i = 1; i < path.size(); i++) {
			if (path[i] < path[i - 1]) return false;
		}
		return true;
	}

	/**
	 * 有序数组转平衡二叉搜索树.
	 * 
	 * \param nums
	 * \return 
	 */
	TreeNode* traversal3(vector<int>& nums, int left, int right) {
		if (left > right) return nullptr;
		int mid = left + ((right - left) / 2);
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = traversal3(nums, left, mid - 1);
		root->right = traversal3(nums, mid + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = traversal3(nums, 0, nums.size() - 1);
		return root;
	}
	/**
	 * 把二叉搜索树转换为累加树.
	 * 
	 * \param root
	 * \return 
	 */
	void traversal4(TreeNode* root, vector<int>& res) {
		if (root != nullptr) {
			traversal4(root->left, res);
			res.push_back(root->val);
			traversal4(root->right, res);
		}		
	}
	void totalSum(vector<int>& res) {
		int n = res.size();
		for (int i = n - 2; i >= 0; i--) {
			res[i] += res[i + 1];
		}
	}
	TreeNode* convertBST(TreeNode* root) {
		vector<int> res;
		traversal4(root, res);
		totalSum(res);

		stack<TreeNode*> st;
		TreeNode* cur = root;
		int count = 0;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top();
				st.pop();
				cur->val = res[count];
				count++;
				cur = cur->right;
			}
		}
		return root;
	}

	//或者
	int sum = 0;
	int thisSum = 0;
	void traversalSum(TreeNode* cur) {
		if (cur == NULL) return;
		traversalSum(cur->left);  // 左
		sum += cur->val;    // 中
		traversalSum(cur->right); // 右
	}
	void traversal5(TreeNode* cur) {
		if (cur == NULL) return;
		traversal5(cur->left);  // 左    
		int tmp = cur->val;
		cur->val = sum - thisSum;   // 中
		thisSum += tmp;
		traversal5(cur->right); // 右
	}
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL) return NULL;
		traversalSum(root);
		traversal5(root);
		return root;
	}

	/**
	 * 二叉搜索树中的搜索.
	 * 
	 * \param root
	 * \param val
	 * \return 
	 */
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val > val) return searchBST(root->left, val);
		else if (root->val < val) return searchBST(root->right, val);
		else return root;
	}
	
	/**
	 *  二叉搜索树中的插入操作.
	 * 
	 * \param root
	 * \param val
	 * \return 
	 */
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr) {
			TreeNode* node = new TreeNode(val);
			return node;
		}
		if (root->val > val) root->left = insertIntoBST(root->left, val);
		if (root->val < val) root->right = insertIntoBST(root->right, val);
		return root;
	}

	//或者
	TreeNode* parent;
	void traversal(TreeNode* cur, int val) {
		if (cur == NULL) {
			TreeNode* node = new TreeNode(val);
			if (val > parent->val) parent->right = node;
			else parent->left = node;
			return;
		}
		parent = cur;
		if (cur->val > val) traversal(cur->left, val);
		if (cur->val < val) traversal(cur->right, val);
		return;
	}
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		parent = new TreeNode(0);
		if (root == NULL) {
			root = new TreeNode(val);
		}
		traversal(root, val);
		return root;
	}

	//迭代法
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL) {
			TreeNode* node = new TreeNode(val);
			return node;
		}
		TreeNode* cur = root;
		TreeNode* parent = root; // 这个很重要，需要记录上一个节点，否则无法赋值新节点
		while (cur != NULL) {
			parent = cur;
			if (cur->val > val) cur = cur->left;
			else cur = cur->right;
		}
		TreeNode* node = new TreeNode(val);
		if (val < parent->val) parent->left = node;// 此时是用parent节点的进行赋值
		else parent->right = node;
		return root;
	}

	/**
	 * 删除二叉搜索树中的节点.
	 * 第一种情况：没找到删除的节点，遍历到空节点直接返回了
	 * 找到删除的节点
	 * 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
	 * 第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
	 * 第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
	 * 第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
	 * \param root
	 * \param key
	 * \return 
	 */
	//递归方法
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
		if (root->val == key) {
			// 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
			if (root->left == nullptr && root->right == nullptr) {
				///! 内存释放
				delete root;
				return nullptr;
			}
			// 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
			else if (root->left == nullptr) {
				auto retNode = root->right;
				///! 内存释放
				delete root;
				return retNode;
			}
			// 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
			else if (root->right == nullptr) {
				auto retNode = root->left;
				///! 内存释放
				delete root;
				return retNode;
			}
			// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
			// 并返回删除节点右孩子为新的根节点。
			else {
				TreeNode* cur = root->right; // 找右子树最左面的节点
				while (cur->left != nullptr) {
					cur = cur->left;
				}
				cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
				TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
				root = root->right;     // 返回旧root的右孩子作为新root
				delete tmp;             // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
				return root;
			}
		}
		if (root->val > key) root->left = deleteNode(root->left, key);
		if (root->val < key) root->right = deleteNode(root->right, key);
		return root;
	}

	//普通二叉树的删除
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root;
		if (root->val == key) {
			if (root->right == nullptr) { // 这里第二次操作目标值：最终删除的作用
				return root->left;
			}
			TreeNode* cur = root->right;
			while (cur->left) {
				cur = cur->left;
			}
			swap(root->val, cur->val); // 这里第一次操作目标值：交换目标值其右子树最左面节点。
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}

	//迭代法
	TreeNode* deleteOneNode(TreeNode* target) {
		if (target == nullptr) return target;
		if (target->right == nullptr) return target->left;
		TreeNode* cur = target->right;
		while (cur->left) {
			cur = cur->left;
		}
		cur->left = target->left;
		return target->right;
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root;
		TreeNode* cur = root;
		TreeNode* pre = nullptr; // 记录cur的父节点，用来删除cur
		while (cur) {
			if (cur->val == key) break;
			pre = cur;
			if (cur->val > key) cur = cur->left;
			else cur = cur->right;
		}
		if (pre == nullptr) { // 如果搜索树只有头结点
			return deleteOneNode(cur);
		}
		// pre 要知道是删左孩子还是右孩子
		if (pre->left && pre->left->val == key) {
			pre->left = deleteOneNode(cur);
		}
		if (pre->right && pre->right->val == key) {
			pre->right = deleteOneNode(cur);
		}
		return root;
	}

	/**
	 * 修剪二叉搜索树.
	 * 
	 * \param root
	 * \param low
	 * \param high
	 * \return 
	 */
	//递归
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) return nullptr;
		if (root->val < low) return trimBST(root->right, low, high);
		if (root->val > high) return trimBST(root->left, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}

	//迭代法
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return nullptr;

		// 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
		while (root != nullptr && (root->val < L || root->val > R)) {
			if (root->val < L) root = root->right; // 小于L往右走
			else root = root->left; // 大于R往左走
		}
		TreeNode* cur = root;
		// 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
		while (cur != nullptr) {
			while (cur->left && cur->left->val < L) {
				cur->left = cur->left->right;
			}
			cur = cur->left;
		}
		cur = root;

		// 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
		while (cur != nullptr) {
			while (cur->right && cur->right->val > R) {
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
};




