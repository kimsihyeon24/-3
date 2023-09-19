//2+3+4*4-6/7+9
#include <stdio.h>
#include <stdlib.h>
			 			  
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

struct TreeNode* createNode(int data) {
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//				-
//	  	  +	           +
//	  +       *		9	  /		
//  2   3   4   5      6     7


TreeNode n1 = { 2.0, NULL, NULL };
TreeNode n2 = { 3.0, NULL, NULL };
TreeNode n3 = { '+', &n1, &n2 };
TreeNode n4 = { 4.0, NULL, NULL };
TreeNode n5 = { 5.0, NULL, NULL };
TreeNode n6 = { '*', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode n8 = { 9.0, NULL, NULL };
TreeNode n9 = { 6.0, NULL, NULL };
TreeNode n10 = { 7.0, NULL, NULL };
TreeNode n11 = { '/', &n9, &n10};
TreeNode n12 = { '+', &n8, &n11};
TreeNode n13 = { '-', &n7, &n12 };
TreeNode* exp = &n13;

float evaluate(TreeNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data; 5
	else {
		float op1 = evaluate(root->left);
		float op2 = evaluate(root->right);
		printf("%.2f %c %.2f을 계산합니다. \n", op1, root->data, op2);
		switch (root->data) {
		case'+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;


		}
	}
	return 0;
}

int countNodes(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int leftCount = countNodes(root->left);
		int rightCount = countNodes(root->right);
		return leftCount + rightCount + 1;
	}
}


int main(void) {
	
	printf("수식의 값은 %f입니다. \n", evaluate(exp));
	

	struct TreeNode* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->left->left->left = createNode(8);
	root->left->left->right = createNode(9);
	root->left->right->left = createNode(10);
	root->left->right->right = createNode(11);
	root->right->left->left = createNode(12);
	root->right->left->right = createNode(13);

	int nodeCount = countNodes(root);
	printf("이진 트리의 노드 수: %d\n", nodeCount);
	return 0;
}
