# A program to find the maximum depth of a binary tree

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def max(a, b):
    return a if a > b else b

def get_max_depth(root):
    if root is None:
        return 0
    left_depth = get_max_depth(root.left)
    right_depth = get_max_depth(root.right)
    return 1 + max(left_depth, right_depth)

# Create the binary tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

max_depth = get_max_depth(root)
print("Maximum depth of the binary tree:", max_depth)
