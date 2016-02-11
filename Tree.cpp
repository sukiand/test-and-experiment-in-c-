#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

TreeNode *constructTree(int *A, int n,int size){
	if (n>=size) return nullptr;
	if (A[n] == -1) return nullptr;
	TreeNode *root = new TreeNode(A[n]);
	root->left = constructTree(A, n * 2 + 1,size);
	root->right = constructTree(A, n * 2 + 2,size);
	return root;
}

void preOrderTraversal_recursive(TreeNode *node){
	if (node == nullptr) return;
	cout << node->val;
	preOrderTraversal_recursive(node->left);
	preOrderTraversal_recursive(node->right);
}

void inOrderTraversal_recursive(TreeNode *node){
	if (node == nullptr) return;
	inOrderTraversal_recursive(node->left);
	cout << node->val;
	inOrderTraversal_recursive(node->right);
}

void postOrderTraversal_recursive(TreeNode *node){
	if (node == nullptr) return;
	postOrderTraversal_recursive(node->left);
	postOrderTraversal_recursive(node->right);
	cout << node->val;
}

void levelOrderTraversal_queue(TreeNode *node){
	if (node == nullptr) return;
	TreeNode *p = node;
	queue<TreeNode *> TreeQueue;
	TreeQueue.push(node);
	while (!TreeQueue.empty()){
		p = TreeQueue.front();
		TreeQueue.pop();
		if (p == nullptr){
			continue;
		}
		cout << p->val;
		TreeQueue.push(p->left);
		TreeQueue.push(p->right);
	}
}

void preorderTraversal_stack(TreeNode *node){
	TreeNode *p = node;
	stack<TreeNode *> TreeStack;
	if (p == nullptr) return;
	TreeStack.push(p);
	while (!TreeStack.empty()){
		p = TreeStack.top();
		TreeStack.pop();
		if (p == nullptr){
			continue;
		}
		cout << p->val;
		TreeStack.push(p->right);
		TreeStack.push(p->left);
	}
}



int main(int argc, char ** argv){
	int tree[] = { 1, 2, -1, 3, 4, -1, -1, 6, 7, -1, 8 };
	TreeNode *root = constructTree(tree, 0,11);

	cout << "preorder, recursive:" << endl;
	preOrderTraversal_recursive(root);
	cout << endl;

	cout << "inorder, recursive:" << endl;
	inOrderTraversal_recursive(root);
	cout << endl;

	cout << "postorder, recursive" << endl;
	postOrderTraversal_recursive(root);
	cout << endl;

	cout << "preorder, stack" << endl;
	preorderTraversal_stack(root);
	cout << endl;

	cout << "levelorder, stack" << endl;
	levelOrderTraversal_queue(root);
	cout << endl;

	getchar();
}