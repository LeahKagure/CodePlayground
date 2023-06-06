# A program to find the diameter of a binary tree (the longest path between any two nodes)

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def max(a, b):
    return a if a > b else b

def get_height(root):
    if root is None:
        return 0
    left_height = get_height(root.left)
    right_height = get_height(root.right)
    return 1 + max(left_height, right_height)

def get_diameter(root):
    if root is None:
        return 0
    left_height = get_height(root.left)
    right_height = get_height(root.right)
    left_diameter = get_diameter(root.left)
    right_diameter = get_diameter(root.right)
    return max(left_height + right_height + 1, max(left_diameter, right_diameter))

# Create the binary tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

diameter = get_diameter(root)
print("Diameter of the binary tree:", diameter)
