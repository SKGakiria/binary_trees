#include "binary_trees.h"

int remove_children(bst_t *root);
int children(bst_t *root);
int successor(bst_t *node);

/**
 * remove_children - function that removes node depending on its children
 * @root: a pointer to the root node of the tree where you will remove a node
 * Return: 0, otherwise value
 */

int remove_children(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (children(root));
}

/**
 * children - function that gets the next successor
 * @root: node that has two children
 *
 * Return: the value found
 */

int children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * successor - function that gets the next successor
 * @node: the tree to check
 *
 * Return: the min value of tree
 */

int successor(bst_t *node)
{
	int left = 0;

	if (!node)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
			return (node->n);

		return (left);
	}
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: pointer to new root node of tree after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
	{
		return (NULL);
	}

	if (value < root->n)
		bst_remove(root->left, value);

	else if (value > root->n)
		bst_remove(root->right, value);

	else if (value == root->n)
	{
		type = remove_children(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
	{
		return (NULL);
	}
	return (root);
}
