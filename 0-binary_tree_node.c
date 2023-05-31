#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_Node;

	new_Node = malloc(sizeof(binary_tree_t));
	if (new_Node == NULL)
	{
		return (NULL);
	}

	new_Node->n = value;
	new_Node->parent = parent;
	new_Node->left = NULL;
	new_Node->right = NULL;

	return (new_Node);
}
