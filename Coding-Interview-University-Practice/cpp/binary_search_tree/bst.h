#include <iostream>
#include <queue>

using namespace std;

// BSTNode
template <class T>
struct BSTNode {
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// BST class
template <class T>
class BST {

public:
    BSTNode<T> *root;

    void insertHelper(BSTNode<T>*& node, T value);
    bool searchHelper(BSTNode<T> *node, T key) const;
    void removeHelper(BSTNode<T>*& node, T key);
    T getMax(BSTNode<T>* node) const;
    T getMin(BSTNode<T>* node) const;
    void inOrder(BSTNode<T> *node) const;
    void levelOrder(BSTNode<T> *node) const;

public:

    BST() {
        root = nullptr;
    }

    ~BST() {}

    inline void insert(T value) { insertHelper(root, value); }

    inline bool search(T key) const { return searchHelper(root, key); }

    inline void remove(T key) { removeHelper(root, key); }

    inline void inOrder() { inOrder(root); }

    inline void levelOrder() { levelOrder(root); }
};


template <class T>
void BST<T>::insertHelper(BSTNode<T>*& node, T value) {
    if (!node) {
        BSTNode<T> *newNode = new BSTNode<T>(value);
        node = newNode;
        return;
    }

    if (value < node->data) {
        insertHelper(node->left, value);
    } else if (value > node->data) {
        insertHelper(node->right, value);
    }
}

template <class T>
bool BST<T>::searchHelper(BSTNode<T> *node, T key) const {
    if (!node)
        return false;

    if (key < node->data) {
        return searchHelper(node->left, key);
    } else if (key > node->data) {
        return searchHelper(node->right, key);
    } else {
        return true;
    }
}

template <class T>
void BST<T>::removeHelper(BSTNode<T>*& node, T key) {
    if (!node)
        return;

    if (key < node->data) {
        removeHelper(node->left, key);
    } else if (key > node->data) {
        removeHelper(node->right, key);
    } else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if (!node->right) {
            BSTNode<T>* temp = node;
            node = node->left;
            delete temp;
        } else if (!node->left) {
            BSTNode<T>* temp = node;
            node = node->right;
            delete temp;
        } else {
            T max_in_left = getMax(node->left);
            node->data = max_in_left;
            removeHelper(node->left, max_in_left);
        }
    }
}

template <class T>
T BST<T>::getMax(BSTNode<T> *node) const {
    if (!node)
        return -1;

    if (!node->right)
        return node->data;

    return getMax(node->right);
}

template <class T>
T BST<T>::getMin(BSTNode<T> *node) const {
    if (!node)
        return -1;

    if (!node->left)
        return node->data;

    return getMin(node->left);
}

template <class T>
void BST<T>::inOrder(BSTNode<T> *node) const {
    if (!node)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

template <class T>
void BST<T>::levelOrder(BSTNode<T> *node) const {
    queue<BSTNode<T> *> q;
    q.push(node);

    while (!q.empty()) {
        BSTNode<T> *front = q.front();
        cout << front->data << " ";
        q.pop();
        if (front->left)
            q.push(front->left);

        if (front->right)
            q.push(front->right);
    }
}
