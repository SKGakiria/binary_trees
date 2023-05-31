#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Description: If parent already has a right-child,
 *              the new node must take its place,
 *              and the old right-child must be set as
 *              the right-child of the new node
 *
 * Return: a pointer to the created node, or NULL on failure
 *         or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right != NULL)
	{
		new_Node->right = parent->right;
		parent->right->parent = new_Node;
	}
	parent->right = new_Node;

	return (new_Node);
}
