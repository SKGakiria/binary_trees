#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int bt_avl(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: the tree to measure the height of
 *
 * Return: height of tree, 0 otherwise
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h = 0, r_h = 0;

	if (!tree)
	{
		return (0);
	}

	l_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l_h > r_h ? l_h : r_h);
}

/**
 * bt_avl - function that finds if a binary tree is an avl
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value
 * @max: the maximum value
 *
 * Return: 1 if tree is avl, 0 otherwise
 */

int bt_avl(const binary_tree_t *tree, int min, int max)
{
	int l_child, r_child;

	if (!tree)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
		return (0);

	l_child = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_child = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(l_child - r_child) > 1)
		return (0);

	return (bt_avl(tree->left, min, tree->n - 1) &&
			bt_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - function checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (bt_avl(tree, INT_MIN, INT_MAX));
}
