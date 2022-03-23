#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root());
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return std::nullopt;
    }
    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return false;
    }
    return true;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* current_node = root_;
    while (current_node->left != nullptr) {
      current_node = current_node->left;
    }
    return current_node->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* current_node = root_;
    while (current_node->right != nullptr) {
      current_node = current_node->right;
    }
    return current_node->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr) {
      Node* new_node = new Node(key, value);
      node = new_node;
    } else {
      if (key == node->key) {
        node->value = value;
      }
      if (key < node->key) {
        return insert(key, value, node->left);
      }
      if (key > node->key) {
        return insert(key, value, node->right);
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    //code
    }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (key == node->key) {
      return node;
    }
    if (key < node->key) {
      return find(key, node->left);
    }
    if (key > node->key) {
      return find(key, node->right);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    return nullptr;
  }

}  // namespace assignment