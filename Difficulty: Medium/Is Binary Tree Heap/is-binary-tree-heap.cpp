/*
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};
*/

class Solution {
	bool isHeapProperty(Node* root) {
		if (root == NULL)
			return true;
		
		if (root->left && root->data < root->left->data)
			return false;
		
		if (root->right && root->data < root->right->data)
			return false;
		
		return isHeapProperty(root->left) &&
		isHeapProperty(root->right);
	}
	int countNodes(Node* root) {
		if (root == NULL)
			return 0;
		
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	
	bool isCBT(Node* root, int index, int total) {
		if (root == NULL)
			return true;
		
		if (index >= total)
			return false;
		
		return isCBT(root->left, 2 * index + 1, total) &&
		isCBT(root->right, 2 * index + 2, total);
	}
	public:
	bool isHeap(Node* tree) {
		int total = countNodes(tree);
		return isCBT(tree, 0, total) && isHeapProperty(tree);
	}
};
