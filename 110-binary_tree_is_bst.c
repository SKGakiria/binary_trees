#include "binary_trees.h"

int bts_helper(const binary_tree_t *tree, int min, int max);

/**
 * bts_helper - helps to check if binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: minimum element in BST
 * @max: maximum element in BST
 *
 * Return: 1 if tree is a valid BST, otherwise 0 if not or tree is NULL
 */

int bts_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}
	return (bts_helper(tree->left, min, tree->n - 1) &&
			bts_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, otherwise 0 if not or tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return (bts_helper(tree, INT_MIN, INT_MAX));
	}
}
