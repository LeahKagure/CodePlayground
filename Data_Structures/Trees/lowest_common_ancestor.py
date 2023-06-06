# A program to find the lowest common ancestor (LCA) of two nodes in a binary tree

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def find_lca(root, val1, val2):
    if root is None:
        return None
    if root.data == val1 or root.data == val2:
        return root

    left_lca = find_lca(root.left, val1, val2)
    right_lca = find_lca(root.right, val1, val2)

    if left_lca is not None and right_lca is not None:
        return root
    if left_lca is not None:
        return left_lca
    return right_lca

# Create the binary tree
root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)

lca = find_lca(root, 5, 1)
print("Lowest Common Ancestor:", lca.data)
