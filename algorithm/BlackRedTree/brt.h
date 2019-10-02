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
  T m_value;
  BRTreeColor m_color;
  std::shared_ptr<BRTreeNode<T>> m_left_ptr;
  std::shared_ptr<BRTreeNode<T>> m_right_ptr;
  std::shared_ptr<BRTreeNode<T>> m_parent_prt;
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
  m_brtree_ptr = nullptr;
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

  node->m_value = value;
  node->m_color = RED;
  node->m_left_ptr = nullptr;
  node->m_right_ptr = nullptr;
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
std::shared_ptr<BRTreeNode<T>> BRTree<T>::create_insert_node(const T &value)
{
  auto node = m_brtree_ptr;
  if (node == nullptr)
  {
    return node;
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
        return node->m_right_ptr;
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
        return node->m_left_ptr;
      }
    }
  }
}