#include <iostream>
#include <vector>
using namespace std;

class BPlusNode {
public:
    vector<int> keys;
    vector<BPlusNode*> children;
    BPlusNode* next;
    bool isLeaf;

    BPlusNode(bool leaf) {
        isLeaf = leaf;
        next = nullptr;
    }
};

class BPlusTree {
public:
    BPlusNode* root;
    int t;  // Order

    BPlusTree(int _t) {
        t = _t;
        root = new BPlusNode(true);
    }

    void insert(int key);
    void display();
    void displayLeaves();
private:
    BPlusNode* insertInternal(BPlusNode* node, int key, int& upKey, BPlusNode*& newChild);
};

void BPlusTree::insert(int key) {
    int upKey;
    BPlusNode* newChild = nullptr;

    BPlusNode* newRoot = insertInternal(root, key, upKey, newChild);

    if (newRoot) {
        BPlusNode* r = new BPlusNode(false);
        r->keys.push_back(upKey);
        r->children.push_back(root);
        r->children.push_back(newChild);
        root = r;
    }
}

BPlusNode* BPlusTree::insertInternal(BPlusNode* node, int key, int& upKey, BPlusNode*& newChild) {
    int pos = 0;
    while (pos < node->keys.size() && key > node->keys[pos])
        pos++;

    if (node->isLeaf) {
        node->keys.insert(node->keys.begin() + pos, key);

        if (node->keys.size() < t)
            return nullptr;

        // Split
        int mid = (t + 1) / 2;
        newChild = new BPlusNode(true);
        newChild->keys.assign(node->keys.begin() + mid, node->keys.end());
        node->keys.resize(mid);

        newChild->next = node->next;
        node->next = newChild;

        upKey = newChild->keys[0];
        return newChild;
    } else {
        BPlusNode* temp = insertInternal(node->children[pos], key, upKey, newChild);

        if (temp == nullptr)
            return nullptr;

        node->keys.insert(node->keys.begin() + pos, upKey);
        node->children.insert(node->children.begin() + pos + 1, newChild);

        if (node->keys.size() < t)
            return nullptr;

        // Split internal node
        int mid = (t + 1) / 2;
        upKey = node->keys[mid];

        BPlusNode* sibling = new BPlusNode(false);
        sibling->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
        sibling->children.assign(node->children.begin() + mid + 1, node->children.end());

        node->keys.resize(mid);
        node->children.resize(mid + 1);

        newChild = sibling;
        return sibling;
    }
}

void BPlusTree::displayLeaves() {
    BPlusNode* node = root;
    while (!node->isLeaf)
        node = node->children[0];

    cout << "Leaf nodes: ";
    while (node) {
        for (int k : node->keys)
            cout << k << " ";
        node = node->next;
    }
    cout << endl;
}

void BPlusTree::display() {
    vector<BPlusNode*> level;
    level.push_back(root);

    while (!level.empty()) {
        vector<BPlusNode*> nextLevel;
        for (auto node : level) {
            cout << "[";
            for (int k : node->keys)
                cout << k << " ";
            cout << "] ";
            if (!node->isLeaf)
                nextLevel.insert(nextLevel.end(), node->children.begin(), node->children.end());
        }
        cout << endl;
        level = nextLevel;
    }
}

// ---------- MAIN FOR B+ TREE ----------
int main() {
    BPlusTree tree(3);  // Order 3

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "\nB+ Tree Structure:\n";
    tree.display();

    cout << "\nB+ Tree Leaves:\n";
    tree.displayLeaves();

    return 0;
}
