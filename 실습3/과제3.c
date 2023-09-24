#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


TreeNode n1 = { 2.0, NULL, NULL };
TreeNode n2 = { 3.0, NULL, NULL };
TreeNode n3 = { 4.0, NULL, NULL };
TreeNode n4 = { 5.0, NULL, NULL };
TreeNode n5 = { '+', &n1, &n2 };
TreeNode n6 = { '*', &n3, &n4 };
TreeNode n7 = { '+', &n5, &n6 };
TreeNode n8 = { 6.0, NULL, NULL };
TreeNode n9 = { 7.0, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { 9.0, NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };
TreeNode* exp = &n13;

float evaluate(TreeNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else {
		float op1 = evaluate(root->left);
		float op2 = evaluate(root->right);
		printf("%.2f %c %.2f을 계산합니다. \n", op1, root->data, op2);
		switch (root->data) {
		case '+':
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

int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}


int main(void)
{
	printf("수식의 값은 %.2f입니다. \n", evaluate(exp));
	printf("\n총 노드의 개수는 %d개입니다.\n", get_node_count(exp));
	return 0;
}