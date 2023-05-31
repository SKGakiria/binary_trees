#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Description: If parent already has a left-child,
 *              the new node must take its place,
 *              and the old left-child must be set as
 *              the left-child of the new node
 *
 * Return: a pointer to the created node, or NULL on failure
 *         or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_Node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_Node = binary_tree_node(parent, value);
	if (new_Node == NULL)
	{
		return (NULL);
	}

	new_Node->n = value;

	if (parent->left != NULL)
	{
		new_Node->left = parent->left;
		parent->left->parent = new_Node;
	}
	parent->left = new_Node;

	return (new_Node);
}
