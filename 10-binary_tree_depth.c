#include "binary_trees.h"

/**
 * binary_tree_depth -  function measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: 0 if tree is NULL, otherwise return depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
	}
}
