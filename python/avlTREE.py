class AVLNode:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
    self.height = 1

def get_height(node):
  if node is None:
    return 0
  return node.height

def get_balance_factor(node):
  if node is None:
    return 0
  return get_height(node.left) - get_height(node.right)

def rotate_left(node):
  right_child = node.right
  left_grandchild = right_child.left
  right_child.left = node
  node.right = left_grandchild
  node.height = 1 + max(get_height(node.left), get_height(node.right))
  right_child.height = 1 + max(get_height(right_child.left), get_height(right_child.right))
  return right_child

def rotate_right(node):
  left_child = node.left
  right_grandchild = left_child.right
  left_child.right = node
  node.left = right_grandchild
  node.height = 1 + max(get_height(node.left), get_height(node.right))
  left_child.height = 1 + max(get_height(left_child.left), get_height(left_child.right))
  return left_child

def insert(node, data):
  if node is None:
    return AVLNode(data)
  if data < node.data:
    node.left = insert(node.left, data)
  else:
    node.right = insert(node.right, data)
  node.height = 1 + max(get_height(node.left), get_height(node.right))
  balance_factor = get_balance_factor(node)
  if balance_factor > 1 and get_balance_factor(node.left) >= 0:
    return rotate_right(node)
  if balance_factor > 1 and get_balance_factor(node.left) < 0:
    node.left = rotate_left(node.left)
    return rotate_right(node)
  if balance_factor < -1 and get_balance_factor(node.right) <= 0:
    return rotate_left(node)
  if balance_factor < -1 and get_balance_factor(node.right) > 0:
    node.right = rotate_right(node.right)
    return rotate_left(node)
  return node

# Insert elements in the AVL tree
root = None
for data in [10, 15, 28, 9, 39, 31, 30, 14, 7, 8]:
  root = insert(root, data)

# Print the AVL tree in pre-order traversal
def in_order(node):
  if node is not None:
    in_order(node.left)
    print(node.data, end=" ")
    in_order(node.right)

in_order(root)