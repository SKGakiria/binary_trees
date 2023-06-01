#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: the lowest common ancestor node, else
 *         NULL if no common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *l_child, *r_child;

	if (!first || !second)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	l_child = first->parent;
	r_child = second->parent;

	if (first == r_child || !l_child || (!l_child->parent && r_child))
	{
		return (binary_trees_ancestor(first, r_child));
	}
	else if (second == l_child || !r_child || (!r_child->parent && l_child))
	{
		return (binary_trees_ancestor(l_child, second));
	}
	return (binary_trees_ancestor(l_child, r_child));
}
