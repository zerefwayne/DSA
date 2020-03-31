## Approach 1 Recursion O(n) space O(n) - callstack

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *Solution::invertTree(TreeNode *A)
{
    if (A == NULL)
    {
        return NULL;
    }

    TreeNode *right = A->right;
    A->right = invertTree(A->left);
    A->left = invertTree(right);

    return A;
}
```
