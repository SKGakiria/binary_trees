#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void binary_tree_level(const binary_tree_t *tree, size_t i, void (*func)(int));

/**
 * binary_tree_levelorder - level-order traversal through a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, i;

	if (!tree || !func)
	{
		return;
	}

	level = binary_tree_height(tree);

	for (i = 1; i <= level; i++)
	{
		binary_tree_level(tree, i, func);
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: tree height, else 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_node, r_node;

	if (!tree)
	{
		return (0);
	}

	l_node = binary_tree_height(tree->left);
	r_node = binary_tree_height(tree->right);

	if (l_node >= r_node)
	{
		return (1 + l_node);
	}
	return (1 + r_node);
}

/**
 * binary_tree_level - function that finds level of a node in a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @i: size of the binary tree
 * @func:  a pointer to a function to call for each node
 */

void binary_tree_level(const binary_tree_t *tree, size_t i, void (*func)(int))
{
	if (!tree)
	{
		return;
	}

	if (i == 1)
	{
		func(tree->n);
	}
	else if (i > 1)
	{
		binary_tree_level(tree->left, i - 1, func);
		binary_tree_level(tree->right, i - 1, func);
	}
}
