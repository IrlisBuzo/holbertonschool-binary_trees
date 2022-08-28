#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: if node is NULL or if node has no uncle return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left != node->parent &&
			node->parent->parent->left != NULL)
		return (node->parent->parent->left);
	if (node->parent->parent->right != node->parent &&
			node->parent->parent->right != NULL)
		return (node->parent->parent->right);
	return (NULL);
}
