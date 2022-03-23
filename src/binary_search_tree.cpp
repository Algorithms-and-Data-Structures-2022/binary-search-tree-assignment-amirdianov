#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::Clear() {
    clear(root());
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr){
      return std::nullopt;
    }
    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    // Write your code here...
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr){
      return std::nullopt;
    }
    Node* current_node = root_;
    while (current_node ->left != nullptr){
      current_node = current_node->left;
    }
    return current_node->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    if (key == node->key){
      return node;
    }
    if (key < node->key){
      return find(key, node->left);
    }
    if (key > node->key){
      return find(key, node->right);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment