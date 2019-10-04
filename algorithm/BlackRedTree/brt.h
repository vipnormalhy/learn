#include <list>
#include <memory>
#include <iostream>
#include <tuple>

enum BRTreeColor
{
  RED,
  BLACK
};

enum UncleLocation
{
  NOT_EXISTS,
  LEFT_NODE,
  RIGHT_NODE,
};

template<typename T>
class BRTreeNode
{
public:
  T m_value;
  BRTreeColor m_color;
  std::shared_ptr<BRTreeNode<T>> m_left_ptr;
  std::shared_ptr<BRTreeNode<T>> m_right_ptr;
  std::shared_ptr<BRTreeNode<T>> m_parent_ptr;
};

template<typename T>
class BRTree
{
public:
  BRTree();
  ~BRTree();

  bool insert(const T &value);
  void travel_tree();

private:
  std::shared_ptr<BRTreeNode<T>> m_brtree_ptr;

  void travel_subtree(std::shared_ptr<BRTreeNode<T>> node_ptr);
  bool insert_head(const T &value);

  // adjust Red-Black Tree
  bool is_root_node(std::shared_ptr<BRTreeNode<T>> node);
  bool is_parent_red(std::shared_ptr<BRTreeNode<T>> node);
  bool is_uncle_red(std::shared_ptr<BRTreeNode<T>> node);
  std::tuple<std::shared_ptr<BRTreeNode<T>>, UncleLocation> find_uncle_node(std::shared_ptr<BRTreeNode<T>> node);
  bool adjust_tree(std::shared_ptr<BRTreeNode<T>> start_node);
  bool adjust_head(std::shared_ptr<BRTreeNode<T>> start_node);
  bool rotate_right(std::shared_ptr<BRTreeNode<T>> adjust_node);
  bool rotate_left(std::shared_ptr<BRTreeNode<T>> adjust_node);

  std::tuple<std::shared_ptr<BRTreeNode<T>>, std::shared_ptr<BRTreeNode<T>>> create_insert_node(const T &value);
};

template<typename T>
BRTree<T>::BRTree()
{
  // create head node
  m_brtree_ptr = nullptr;
}

template<typename T>
BRTree<T>::~BRTree()
{
  m_brtree_ptr = nullptr;
}

template<typename T>
bool BRTree<T>::insert(const T &value) 
{
  if (!m_brtree_ptr)
  {
    return insert_head(value);
  }

  // Insert a node to BRTree
  std::shared_ptr<BRTreeNode<T>> parent, node;
  tie(parent, node) = create_insert_node(value);
  if (!node)
  {
    std::cerr << "Cannot find a node for " << value << std::endl;
    std::terminate();
  }
  node->m_value = value;
  node->m_color = RED;
  node->m_parent_ptr = parent;
  node->m_left_ptr = nullptr;
  node->m_right_ptr = nullptr;

  // adjust red-black
  adjust_tree(node);
  return true;
}

template<typename T>
bool BRTree<T>::insert_head(const T &value)
{
  m_brtree_ptr = std::make_shared<BRTreeNode<T>>();
  m_brtree_ptr->m_value = value;
  m_brtree_ptr->m_color = BLACK;
  m_brtree_ptr->m_left_ptr = nullptr;
  m_brtree_ptr->m_right_ptr = nullptr;
  m_brtree_ptr->m_parent_ptr = nullptr;
  return true;
}

template<typename T>
void BRTree<T>::travel_tree()
{
  std::shared_ptr<BRTreeNode<T>> head = m_brtree_ptr;
  if (!head)
  {
    return;
  }

  travel_subtree(head);
}

template<typename T>
void BRTree<T>::travel_subtree(std::shared_ptr<BRTreeNode<T>> node_ptr)
{
  if (node_ptr->m_left_ptr)
  {
    travel_subtree(node_ptr->m_left_ptr);
  }

  std::cout << "value is " << node_ptr->m_value << " color is " << node_ptr->m_color << std::endl;

  if (node_ptr->m_right_ptr)
  {
    travel_subtree(node_ptr->m_right_ptr);
  }
}

template<typename T>
std::tuple<std::shared_ptr<BRTreeNode<T> >, std::shared_ptr<BRTreeNode<T>> > BRTree<T>::create_insert_node(const T &value)
{
  auto node = m_brtree_ptr;
  if (node == nullptr)
  {
    return std::make_tuple(nullptr, node);
  }

  while(true)
  {
    if (node->m_value < value)
    {
      if (node->m_right_ptr)
      {
        node = node->m_right_ptr;
      }
      else
      {
        node->m_right_ptr = std::make_shared<BRTreeNode<T>>();
        return std::make_tuple(node, node->m_right_ptr);
      }
    }
    else
    {
      if (node->m_left_ptr)
      {
        node = node->m_left_ptr;
      }
      else
      {
        node->m_left_ptr = std::make_shared<BRTreeNode<T>>();
        return std::make_tuple(node, node->m_left_ptr);
      }
    }
  }
}

template<typename T>
bool BRTree<T>::adjust_tree(std::shared_ptr<BRTreeNode<T>> start_node)
{
  if (is_root_node(start_node))
  {
    return adjust_head(start_node);
  }
  else if (is_parent_red(start_node))
  {
    std::shared_ptr<BRTreeNode<T>> uncle;
    UncleLocation uncle_location;
    tie(uncle, uncle_location) = find_uncle_node(start_node);

    auto parent = start_node->m_parent_ptr;
    auto grandparent = parent->m_parent_ptr;

    if (!grandparent)
    {
      // error: root node need to be black
      std::cerr << "root node need to be black" << __LINE__ << std::endl;
      // parent node is root node
      parent->m_color = BLACK;
    }
    else if (!uncle)
    {
      // rotate
      // if grandparent's left node is parent, then rotate right
      // if grandparent's right node is parent, then rotate left
      if (grandparent->m_left_ptr == parent)
      {
        rotate_right(parent);
      }
      else
      {
        rotate_left(parent);
      }

      parent->m_color = BLACK;
      start_node->m_color = RED;
      grandparent->m_color = RED;
    }
    else if (is_uncle_red(start_node))
    {
      // grandparent change to red
      // parent and uncle change to black
      // self change to red

      // grandparent is black, change to red
      grandparent->m_color = RED;
      parent->m_color = BLACK;
      uncle->m_color = BLACK;

      adjust_tree(grandparent);
    }
    else // uncle is black
    {
    }
    
  }
  else
  {
    // only need change color of this node
    start_node->m_color = RED;
  }

  return true;
}

template<typename T>
bool BRTree<T>::adjust_head(std::shared_ptr<BRTreeNode<T>> start_node)
{
  if (start_node->m_color != BLACK)
  {
    start_node->m_color = BLACK;
  }

  m_brtree_ptr = start_node;

  return true;
}

template<typename T>
bool BRTree<T>::is_root_node(std::shared_ptr<BRTreeNode<T>> node)
{
  if (node->m_parent_ptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

template<typename T>
bool BRTree<T>::is_parent_red(std::shared_ptr<BRTreeNode<T>> node)
{
  if (!node->m_parent_ptr)
  {
    return false;
  }

  auto parent = node->m_parent_ptr;
  return parent->m_color == RED;
}

template<typename T>
bool BRTree<T>::is_uncle_red(std::shared_ptr<BRTreeNode<T>> node)
{
  std::shared_ptr<BRTreeNode<T>> uncle;
  UncleLocation uncle_location;
  tie(uncle, uncle_location) = find_uncle_node(node);
  if (node)
  {
    return node->m_color == RED;
  }
  else
  {
    return false;
  }
}

template<typename T>
std::tuple<std::shared_ptr<BRTreeNode<T>>, UncleLocation> BRTree<T>::find_uncle_node(std::shared_ptr<BRTreeNode<T>> node)
{
  auto parent = node->m_parent_ptr;
  if (!parent)
  {
    return std::make_tuple(nullptr, NOT_EXISTS);
  }

  auto grandparent = parent->m_parent_ptr;
  if (!grandparent)
  {
    return std::make_tuple(nullptr, NOT_EXISTS);
  }

  if (grandparent->m_left_ptr == parent)
  {
    return std::make_tuple(grandparent->m_right_ptr, RIGHT_NODE);
  }
  else
  {
    return std::make_tuple(grandparent->m_left_ptr, LEFT_NODE);
  }
}

template<typename T>
bool BRTree<T>::rotate_right(std::shared_ptr<BRTreeNode<T>> node)
{
  auto parent = node->m_parent_ptr;
  // parent don't exists? FATAL ERROR
  if (!parent)
  {
    std::cerr << "rotate a node that no parent" << std::hex << node << std::endl;
    std::terminate();
  }

  // node change to parent
  auto grandparent = parent->m_parent_ptr;
  node->m_parent_ptr = grandparent;

  if (grandparent)
  {
    if (grandparent->m_left_ptr == parent)
    {
      grandparent->m_left_ptr = node;
    }
    else
    {
      grandparent->m_right_ptr = node;
    }
  }

  // node's right child change to parent's left child
  parent->m_left_ptr = node->m_right_ptr;
  if (node->m_right_ptr)
  {
    node->m_right_ptr->m_parent_ptr = parent;
  }

  // parent change to node's right child
  parent->m_parent_ptr = node;
  node->m_right_ptr = parent;
  return true;
}

template<typename T>
bool BRTree<T>::rotate_left(std::shared_ptr<BRTreeNode<T>> node)
{
  auto parent = node->m_parent_ptr;
  // parent don't exists? FATAL ERROR
  if (!parent)
  {
    std::cerr << "rotate a node that no parent" << std::hex << node << std::endl;
    std::terminate();
  }

  // node change to parent
  auto grandparent = parent->m_parent_ptr;
  node->m_parent_ptr = grandparent;

  // parent is root node
  if (!grandparent)
  {
    m_brtree_ptr = node;
  }
  else
  {
    if (grandparent->m_left_ptr == parent)
    {
      grandparent->m_left_ptr = node;
    }
    else
    {
      grandparent->m_right_ptr = node;
    }
  }

  // node's left child change to parent's right child
  parent->m_right_ptr = node->m_left_ptr;
  if (node->m_left_ptr)
  {
    node->m_left_ptr->m_parent_ptr = parent;
  }

  // change parent to node's left child
  node->m_left_ptr = parent;
  parent->m_parent_ptr = node;
  return true;
}