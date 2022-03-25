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
    if (node == nullptr) {
      // узел не найден
      return false;
    }

    if (key == node->key) {

      // Случай 1. Два потомка
      if (node->left != nullptr && node->right != nullptr) {

        // наименьший узел в правом поддереве
        // пояснение:
        //  1. в правом поддереве любой элемент гарантированно больше
        //  любого элемента из левого поддерева
        //  2. на месте удаляемого узла должен стоять элемент:
        //    2.1. значение элемента > любого элемента из левого поддерева
        //    2.2. значение элемента < любого элемента из правого поддерева
        Node* min = find_min(node->right);

        node->key = min->key;
        node->value = min->value;

        return remove(min->key, node->right);
      }

      // Случай 2. Левый потомок
      if (node->left != nullptr && node->right == nullptr) {
        Node* left_child = node->left;
        delete node;
        node = left_child;
        return true;
      }

      // Случай 3. Правый потомок или нет потомков
      Node* right_node = node->right;
      delete node;
      node = right_node;
      return true;
    }

    if (key < node->key) {
      return remove(key, node->left);
    }

    // key > node->key
    return remove(key, node->right);
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
    while (node->left != nullptr){
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    while (node->right != nullptr){
      node = node->right;
    }
    return node;
  }

}  // namespace assignment