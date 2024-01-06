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
	 * ��������ǰ�����.
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
	//������
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
	 * �������.
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
	 * �������.
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
	 * ǰ�к�ͳһ����.
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
				if (node->right) st.push(node->right);  // ��
				if (node->left) st.push(node->left);    // ��
				st.push(node);                          // ��
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
				st.pop(); // ���ýڵ㵯���������ظ������������ٽ�������ڵ���ӵ�ջ��
				if (node->right) st.push(node->right);  // ����ҽڵ㣨�սڵ㲻��ջ��

				st.push(node);                          // ����нڵ�
				st.push(NULL); // �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�

				if (node->left) st.push(node->left);    // �����ڵ㣨�սڵ㲻��ջ��
			}
			else { // ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
				st.pop();           // ���սڵ㵯��
				node = st.top();    // ����ȡ��ջ��Ԫ��
				st.pop();
				result.push_back(node->val); // ���뵽�����
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
				st.push(node);                          // ��
				st.push(NULL);

				if (node->right) st.push(node->right);  // ��
				if (node->left) st.push(node->left);    // ��

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
	 * �������.
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
	 * ��ݲ������.
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
	 * ·���ܺ�.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	bool hasPathSum(TreeNode* root, int targetSum) {

	}
	/**
	 * ��ת������.
	 * 
	 * \param root
	 * \return 
	 */
	//�ݹ�
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
	//ǰ�����
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*> st;
		if (root != nullptr) st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			if (node != NULL) {
				st.pop();
				if (node->right) st.push(node->right);  // ��
				if (node->left) st.push(node->left);    // ��
				st.push(node);                          // ��
				st.push(NULL);
			}
			else {
				st.pop();
				node = st.top();
				st.pop();
				swap(node->left, node->right);          // �ڵ㴦���߼�
			}
		}
		return root;
	}
	
	/**
	 * �Գƶ�����.
	 * 
	 * \param root
	 * \return 
	 */
	//������
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
	//ʹ�ö��е���
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> que;
		que.push(root->left);   // ��������ͷ���������
		que.push(root->right);  // ��������ͷ���������

		while (!que.empty()) {  // ��������Ҫ�ж����������Ƿ��໥��ת
			TreeNode* leftNode = que.front(); que.pop();
			TreeNode* rightNode = que.front(); que.pop();
			if (!leftNode && !rightNode) {  // ��ڵ�Ϊ�ա��ҽڵ�Ϊ�գ���ʱ˵���ǶԳƵ�
				continue;
			}

			// ����һ���ڵ㲻Ϊ�գ����߶���Ϊ�յ���ֵ����ͬ������false
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			que.push(leftNode->left);   // ������ڵ�����
			que.push(rightNode->right); // �����ҽڵ��Һ���
			que.push(leftNode->right);  // ������ڵ��Һ���
			que.push(rightNode->left);  // �����ҽڵ�����
		}
		return true;
	}
	//ʹ��ջ����
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> st; // ����ĳ���ջ
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
	 * ��ͬ����.
	 * 
	 * \param p
	 * \param q
	 * \return 
	 */
	//�ݹ鷨
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
	//������
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p != NULL && q == NULL) return false;
		if (p == NULL && q != NULL) return false;

		stack<TreeNode*> st; // ����ĳ���ջ
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
	 * ��һ������.
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
	 * ·���ܺ�.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	//�ݹ鷨
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root) return false;
		if (!root->left && !root->right && targetSum == root->val) {
			return true;
		}
		return hasPathSum(root->left, targetSum - root->val) 
			|| hasPathSum(root->right, targetSum - root->val);
	}

	//������
	bool haspathsum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		// ��ʱջ��Ҫ�ŵ���pair<�ڵ�ָ�룬·����ֵ>
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode*, int>(root, root->val));
		while (!st.empty()) {
			pair<TreeNode*, int> node = st.top();
			st.pop();
			// ����ýڵ���Ҷ�ӽڵ��ˣ�ͬʱ�ýڵ��·����ֵ����sum����ô�ͷ���true
			if (!node.first->left && !node.first->right && sum == node.second) return true;

			// �ҽڵ㣬ѹ��ȥһ���ڵ��ʱ�򣬽��ýڵ��·����ֵҲ��¼����
			if (node.first->right) {
				st.push(pair<TreeNode*, int>(node.first->right, 
					node.second + node.first->right->val));
			}

			// ��ڵ㣬ѹ��ȥһ���ڵ��ʱ�򣬽��ýڵ��·����ֵҲ��¼����
			if (node.first->left) {
				st.push(pair<TreeNode*, int>(node.first->left, 
					node.second + node.first->left->val));
			}
		}
		return false;
	}
	//�����㷨
	void traversal7(TreeNode* cur, vector<int>& path, vector<int>& result) {
		path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path�� 
		// ��ŵ���Ҷ�ӽڵ�
		if (cur->left == NULL && cur->right == NULL) {
			int sum = 0;
			for (int i = 0; i < path.size(); i++) {
				sum += path[i];
			}
			result.push_back(sum);
			return;
		}
		if (cur->left) { // �� 
			traversal7(cur->left, path, result);
			path.pop_back(); // ����
		}
		if (cur->right) { // ��
			traversal7(cur->right, path, result);
			path.pop_back(); // ����
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
	 * ���е�·��֮��.
	 * 
	 * \param root
	 * \param targetSum
	 * \return 
	 */
	void traversal8(TreeNode* cur, vector<int>& path, vector<vector<int>>& result,int target) {
		path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path�� 
		// ��ŵ���Ҷ�ӽڵ�
		if (cur->left == NULL && cur->right == NULL) {
			int sum = 0;
			for (int i = 0; i < path.size(); i++) {
				sum += path[i];
			}
			if (sum == target) result.push_back(path);
			return;
		}
		if (cur->left) { // �� 
			traversal8(cur->left, path, result,target);
			path.pop_back(); // ����
		}
		if (cur->right) { // ��
			traversal8(cur->right, path, result, target);
			path.pop_back(); // ����
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
	 * ����·��.
	 * 
	 * \param root
	 * \return 
	 */
	void traversal0(TreeNode* cur, vector<int>& path, vector<string>& result) {
		path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path�� 
		// ��ŵ���Ҷ�ӽڵ�
		if (cur->left == NULL && cur->right == NULL) {
			string res = "";
			for (int p : path) {
				res += to_string(p) + "->";
			}
			result.push_back(res.substr(0, res.length() - 1));
			return;
		}
		if (cur->left) { // �� 
			traversal0(cur->left, path, result);
			path.pop_back(); // ����
		}
		if (cur->right) { // ��
			traversal0(cur->right, path, result);
			path.pop_back(); // ����
		}
	}
	//����
	void traversal1(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path��
		if (cur->left == NULL && cur->right == NULL) {
			result.push_back(path);
			return;
		}
		if (cur->left) {
			path += "->";
			traversal1(cur->left, path, result); // ��
			path.pop_back(); // ���� '>'
			path.pop_back(); // ���� '-'
		}
		if (cur->right) {
			path += "->";
			traversal1(cur->right, path, result); // ��
			path.pop_back(); // ����'>'
			path.pop_back(); // ���� '-'
		}
	}
	void traversal2(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val); // ��
		if (cur->left == NULL && cur->right == NULL) {
			result.push_back(path);
			return;
		}
		if (cur->left) traversal2(cur->left, path + "->", result); // ��
		if (cur->right) traversal2(cur->right, path + "->", result); // ��
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		vector<int> path;
		if (root == nullptr) return result;
		traversal0(root, path, result);
		return result;
	}
	//������
	vector<string> binaryTreePaths(TreeNode* root) {
		stack<TreeNode*> treeSt;// �������ı����ڵ�
		stack<string> pathSt;   // �������·���Ľڵ�
		vector<string> result;  // ��������·������
		if (root == NULL) return result;
		treeSt.push(root);
		pathSt.push(to_string(root->val));
		while (!treeSt.empty()) {
			TreeNode* node = treeSt.top(); treeSt.pop(); // ȡ���ڵ� ��
			string path = pathSt.top(); pathSt.pop();    // ȡ���ýڵ��Ӧ��·��
			if (node->left == NULL && node->right == NULL) { // ����Ҷ�ӽڵ�
				result.push_back(path);
			}
			if (node->right) { // ��
				treeSt.push(node->right);
				pathSt.push(path + "->" + to_string(node->right->val));
			}
			if (node->left) { // ��
				treeSt.push(node->left);
				pathSt.push(path + "->" + to_string(node->left->val));
			}
		}
		return result;
	}

	/**
	 * ������.
	 * 
	 * \param root
	 * \return 
	 */
	//�ݹ鷨
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	//ǰ��ݹ鷨
	int result;
	void getdepth(TreeNode* node, int depth) {
		result = depth > result ? depth : result; // ��
		if (node->left == NULL && node->right == NULL) return;
		if (node->left) { // ��
			getdepth(node->left, depth + 1);
		}
		if (node->right) { // ��
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
	//�������������
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // ��¼���
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
	 * ��С����.
	 * 
	 * \param root
	 * \return 
	 */
	//������
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;

		int min_depth = INT_MAX;
		if (root->left != nullptr) min_depth = min(minDepth(root->left), min_depth);
		if (root->right != nullptr) min_depth = min(minDepth(root->right), min_depth);
		return min_depth + 1;
	}
	//�������
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
	//����
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int depth = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++; // ��¼��С���
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) { // �����Һ��Ӷ�Ϊ�յ�ʱ��˵������͵��һ���ˣ��˳�
					return depth;
				}
			}
		}
		return depth;
	}
	/**
	 * N������������.
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
			depth++; // ��¼���
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
	 * �ϲ�������.
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
	 * ����Ҷ֮��.
	 * 
	 * \param root
	 * \return 
	 */
	//�ݹ鷨
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		int leftValue = 0;
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
			leftValue = root->left->val;
		}
		return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
	//������
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
	 * �Ƿ���ƽ����.
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
	 * ���½ǵ�ֵ.
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
	//���ݷ���
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
			traversal(root->left, depth + 1); // �����Ż���
		}
		if (root->right) {
			traversal(root->right, depth + 1); // �����Ż���
		}
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 0);
		return result;
	}

	/**
	 * ��������.
	 * 
	 * \param nums
	 * \return 
	 */
	TreeNode* traversal6(vector<int>& nums, int left, int right) {
		if (left >= right) return nullptr;

		// �ָ���±꣺maxValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; ++i) {
			if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		// ����ҿ���[left, maxValueIndex)
		root->left = traversal6(nums, left, maxValueIndex);

		// ����ҿ���[maxValueIndex + 1, right)
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
	 * ����������ͼ.
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
	 * ������չ��Ϊ����.
	 * 
	 * \param root
	 */
	//������
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

	//������
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

	/****************************������****************************/
	/**
	 * ��֤����������.
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
	 * ��������תƽ�����������.
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
	 * �Ѷ���������ת��Ϊ�ۼ���.
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

	//����
	int sum = 0;
	int thisSum = 0;
	void traversalSum(TreeNode* cur) {
		if (cur == NULL) return;
		traversalSum(cur->left);  // ��
		sum += cur->val;    // ��
		traversalSum(cur->right); // ��
	}
	void traversal5(TreeNode* cur) {
		if (cur == NULL) return;
		traversal5(cur->left);  // ��    
		int tmp = cur->val;
		cur->val = sum - thisSum;   // ��
		thisSum += tmp;
		traversal5(cur->right); // ��
	}
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL) return NULL;
		traversalSum(root);
		traversal5(root);
		return root;
	}

	/**
	 * �����������е�����.
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
	 *  �����������еĲ������.
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

	//����
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

	//������
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL) {
			TreeNode* node = new TreeNode(val);
			return node;
		}
		TreeNode* cur = root;
		TreeNode* parent = root; // �������Ҫ����Ҫ��¼��һ���ڵ㣬�����޷���ֵ�½ڵ�
		while (cur != NULL) {
			parent = cur;
			if (cur->val > val) cur = cur->left;
			else cur = cur->right;
		}
		TreeNode* node = new TreeNode(val);
		if (val < parent->val) parent->left = node;// ��ʱ����parent�ڵ�Ľ��и�ֵ
		else parent->right = node;
		return root;
	}

	/**
	 * ɾ�������������еĽڵ�.
	 * ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
	 * �ҵ�ɾ���Ľڵ�
	 * �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
	 * �����������ɾ���ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ�������Һ���Ϊ���ڵ�
	 * �����������ɾ���ڵ���Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
	 * ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ��������ͷ��㣨���ӣ��ŵ�ɾ���ڵ����������������ڵ�������ϣ�����ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
	 * \param root
	 * \param key
	 * \return 
	 */
	//�ݹ鷽��
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root; // ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
		if (root->val == key) {
			// �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
			if (root->left == nullptr && root->right == nullptr) {
				///! �ڴ��ͷ�
				delete root;
				return nullptr;
			}
			// �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
			else if (root->left == nullptr) {
				auto retNode = root->right;
				///! �ڴ��ͷ�
				delete root;
				return retNode;
			}
			// ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
			else if (root->right == nullptr) {
				auto retNode = root->left;
				///! �ڴ��ͷ�
				delete root;
				return retNode;
			}
			// ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
			// ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
			else {
				TreeNode* cur = root->right; // ��������������Ľڵ�
				while (cur->left != nullptr) {
					cur = cur->left;
				}
				cur->left = root->left; // ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
				TreeNode* tmp = root;   // ��root�ڵ㱣��һ�£�������ɾ��
				root = root->right;     // ���ؾ�root���Һ�����Ϊ��root
				delete tmp;             // �ͷŽڵ��ڴ棨���ﲻдҲ���ԣ���C++����ֶ��ͷ�һ�°ɣ�
				return root;
			}
		}
		if (root->val > key) root->left = deleteNode(root->left, key);
		if (root->val < key) root->right = deleteNode(root->right, key);
		return root;
	}

	//��ͨ��������ɾ��
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return root;
		if (root->val == key) {
			if (root->right == nullptr) { // ����ڶ��β���Ŀ��ֵ������ɾ��������
				return root->left;
			}
			TreeNode* cur = root->right;
			while (cur->left) {
				cur = cur->left;
			}
			swap(root->val, cur->val); // �����һ�β���Ŀ��ֵ������Ŀ��ֵ��������������ڵ㡣
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}

	//������
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
		TreeNode* pre = nullptr; // ��¼cur�ĸ��ڵ㣬����ɾ��cur
		while (cur) {
			if (cur->val == key) break;
			pre = cur;
			if (cur->val > key) cur = cur->left;
			else cur = cur->right;
		}
		if (pre == nullptr) { // ���������ֻ��ͷ���
			return deleteOneNode(cur);
		}
		// pre Ҫ֪����ɾ���ӻ����Һ���
		if (pre->left && pre->left->val == key) {
			pre->left = deleteOneNode(cur);
		}
		if (pre->right && pre->right->val == key) {
			pre->right = deleteOneNode(cur);
		}
		return root;
	}

	/**
	 * �޼�����������.
	 * 
	 * \param root
	 * \param low
	 * \param high
	 * \return 
	 */
	//�ݹ�
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) return nullptr;
		if (root->val < low) return trimBST(root->right, low, high);
		if (root->val > high) return trimBST(root->left, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}

	//������
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return nullptr;

		// ����ͷ��㣬��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�
		while (root != nullptr && (root->val < L || root->val > R)) {
			if (root->val < L) root = root->right; // С��L������
			else root = root->left; // ����R������
		}
		TreeNode* cur = root;
		// ��ʱroot�Ѿ���[L, R] ��Χ�ڣ���������Ԫ��С��L�����
		while (cur != nullptr) {
			while (cur->left && cur->left->val < L) {
				cur->left = cur->left->right;
			}
			cur = cur->left;
		}
		cur = root;

		// ��ʱroot�Ѿ���[L, R] ��Χ�ڣ������Һ��Ӵ���R�����
		while (cur != nullptr) {
			while (cur->right && cur->right->val > R) {
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
};




