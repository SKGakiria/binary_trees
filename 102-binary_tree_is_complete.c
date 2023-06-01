#include "binary_trees.h"

int bt_is_Complete(const binary_tree_t *tree, size_t i, size_t size);

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: 0 if tree is NULL, otherwise return size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return (binary_tree_size(tree->left) +
				binary_tree_size(tree->right) + 1);
	}
}

/**
 * bt_is_Complete - checks if a binary tree is complete recursively
 * @tree: a pointer to the root node of the tree to check
 * @i: node index to check
 * @size: number of nodes in tree
 *
 * Return: 0 if tree is NULL, otherwise 1 if tree is complete
 */

int bt_is_Complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
	{
		return (1);
	}

	if (i >= size)
	{
		return (0);
	}
	else
	{
		return (bt_is_Complete(tree->left, 2 * i + 1, size) &&
				bt_is_Complete(tree->right, 2 * i + 2, size));
	}
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL, otherwise 1 if tree is complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
	{
		return (0);
	}
	size = binary_tree_size(tree);

	return (bt_is_Complete(tree, 0, size));
}
