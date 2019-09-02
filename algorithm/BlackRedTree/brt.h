#include <list>
#include <memory>
#include <iostream>

enum BRTreeColor
{
  RED,
  BLACK
};

template<typename T>
class BRTreeNode
{
public:
  T value;
  BRTreeColor color;
  std::shared_ptr<BRTreeNode<T>> left_ptr;
  std::shared_ptr<BRTreeNode<T>> right_ptr;
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
  std::shared_ptr<BRTreeNode<T>> create_insert_node(const T &value);
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
}

template<typename T>
bool BRTree<T>::insert(const T &value) 
{
  if (!m_brtree_ptr)
  {
    return insert_head(value);
  }

  auto node = create_insert_node(value);
  if (!node)
  {
    std::cerr << "Cannot find a node for " << value << std::endl;
    std::terminate();
  }

  node->value = value;
  node->color = RED;
  node->left_ptr = nullptr;
  node->right_ptr = nullptr;
  return true;
}

template<typename T>
bool BRTree<T>::insert_head(const T &value)
{
  m_brtree_ptr = std::make_shared<BRTreeNode<T>>();
  m_brtree_ptr->value = value;
  m_brtree_ptr->color = BLACK;
  m_brtree_ptr->left_ptr = nullptr;
  m_brtree_ptr->right_ptr = nullptr;
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
  if (node_ptr->left_ptr)
  {
    travel_subtree(node_ptr->left_ptr);
  }

  std::cout << "value is " << node_ptr->value << " color is " << node_ptr->color << std::endl;

  if (node_ptr->right_ptr)
  {
    travel_subtree(node_ptr->right_ptr);
  }
}

template<typename T>
std::shared_ptr<BRTreeNode<T>> BRTree<T>::create_insert_node(const T &value)
{
  auto node = m_brtree_ptr;
  if (node == nullptr)
  {
    return node;
  }

  while(true)
  {
    if (node->value < value)
    {
      if (node->right_ptr)
      {
        node = node->right_ptr;
      }
      else
      {
        node->right_ptr = std::make_shared<BRTreeNode<T>>();
        return node->right_ptr;
      }
    }
    else
    {
      if (node->left_ptr)
      {
        node = node->left_ptr;
      }
      else
      {
        node->left_ptr = std::make_shared<BRTreeNode<T>>();
        return node->left_ptr;
      }
    }
  }
}