# A program to check if a binary tree is a binary search tree

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_bst_util(root, min_val, max_val):
    if root is None:
        return True
    if root.data < min_val or root.data > max_val:
        return False
    return is_bst_util(root.left, min_val, root.data - 1) and \
           is_bst_util(root.right, root.data + 1, max_val)

def is_bst(root):
    return is_bst_util(root, float('-inf'), float('inf'))

# Create the binary tree
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(6)

is_bst_tree = is_bst(root)
print("Is the binary tree a BST?", "Yes" if is_bst_tree else "No")
