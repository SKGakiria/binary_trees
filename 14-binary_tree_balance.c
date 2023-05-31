#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL, otherwise return height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t l_height = 0, r_height = 0;

        if (!tree)
        {
                return (0);
        }
        else
        {
                l_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
                r_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
                return ((l_height > r_height) ? l_height : r_height);
        }
}

/**
 * binary_tree_balance - function that measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, otherwise return the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	else
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
}
