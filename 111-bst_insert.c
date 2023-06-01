#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value:  the value to store in the node to be inserted
 *
 * Return: NULL on failure or a pointer to the created node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr = NULL;
	bst_t *new = NULL;

	if (tree != NULL)
	{
		curr = *tree;

		if (!curr)
		{
			new = binary_tree_node(curr, value);
			if (!new)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new = binary_tree_node(curr, value);
			if (!new)
				return (NULL);
			return (curr->left = new);
		}

		if (value > curr->n)
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new = binary_tree_node(curr, value);
			if (!new)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
