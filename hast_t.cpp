#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashNode {
public:
    int key;
    string value;
    bool isDeleted;

    HashNode(int k, string v) {
        key = k;
        value = v;
        isDeleted = false;
    }
};

class HashTable {
private:
    HashNode* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != nullptr && !table[index]->isDeleted && table[index]->key != key) {
            index = (originalIndex + ++i) % TABLE_SIZE;
            if (i == TABLE_SIZE) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        if (table[index] == nullptr || table[index]->isDeleted) {
            table[index] = new HashNode(key, value);
        } else {
            table[index]->value = value; // Update value if key already exists
        }
    }

    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != nullptr) {
            if (!table[index]->isDeleted && table[index]->key == key) {
                table[index]->isDeleted = true;
                cout << "Key " << key << " removed." << endl;
                return;
            }
            index = (originalIndex + ++i) % TABLE_SIZE;
        }

        cout << "Key " << key << " not found." << endl;
    }

    string search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != nullptr) {
            if (!table[index]->isDeleted && table[index]->key == key) {
                return table[index]->value;
            }
            index = (originalIndex + ++i) % TABLE_SIZE;
        }

        return "Key not found";
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr && !table[i]->isDeleted)
                cout << i << ": [" << table[i]->key << " -> " << table[i]->value << "]" << endl;
            else
                cout << i << ": [Empty]" << endl;
        }
    }
};

// Main function to demonstrate the hash table
int main() {
    HashTable ht;

    ht.insert(1, "Apple");
    ht.insert(11, "Banana"); // collision with key 1 (if TABLE_SIZE is 10)
    ht.insert(21, "Cherry");
    ht.insert(3, "Date");

    ht.display();

    cout << "\nSearch key 11: " << ht.search(11) << endl;

    ht.remove(11);
    ht.display();

    return 0;
}
