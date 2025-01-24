#include <iostream>
#include <string>
using namespace std;


struct Node {
    string key;      
    string value;    
    Node* next;      

    
    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};


const int tableSize = 5;  
Node* table[tableSize];  


int hashFunction(string key) {
    int hash = 0;
    for (char ch : key) {
        hash += ch;  // Add ASCII value of each character in the string
    }
    return hash % tableSize;  
}


void insert(string key, string value) {
    int index = hashFunction(key);  
    Node* newNode = new Node(key, value);  

    
    newNode->next = table[index];
    table[index] = newNode;
}


string search(string key) {
    int index = hashFunction(key);  
    Node* current = table[index];

    
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;  
        }
        current = current->next;
    }
    return "Not found";  
}


void display() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) {
            cout << "Index " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << "[" << current->key << " -> " << current->value << "] ";
                current = current->next;
            }
            cout << endl;
        }
    }
}

void clearTable() {
    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete; 
        }
    }
}

int main() {
    
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }

    
    insert("AIT", "Army Institute of Technology");
    insert("IIT", "Indian Institute of Technology");
    insert("NIT", "National Institute of Technology");

    
    cout << "Meaning of 'AIT': " << search("AIT") << endl;
    cout << "Meaning of 'IIT': " << search("IIT") << endl;

   
    cout << "Hash Table:" << endl;
    display();

    
    clearTable();

    return 0;
}
