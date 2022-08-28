#include "binary_trees.h"
/**
 * find_height - find height for a node
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0 if tree is NULL
 */
int find_height(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);
	l = find_height(tree->left);
	r = find_height(tree->right);
	if (l >= r)
		return (1 + l);
	else
		return (1 + r);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the number of balance, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	return (find_height(tree->left) - find_height(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is perfect, otherwise 0
 * 0 is tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (binary_tree_balance(tree) != 0)
		return (0);
	if ((tree->left) && (tree->right))
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
