# A program to find the height of a binary tree

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def get_height(root):
    if root is None:
        return 0
    left_height = get_height(root.left)
    right_height = get_height(root.right)
    return 1 + max(left_height, right_height)

# Create the binary tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

height = get_height(root)
print("Height of the binary tree:", height)
