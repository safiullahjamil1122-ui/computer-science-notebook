#include <iostream>

struct Node {
    int value;
    Node* next;
};

void insert_front(Node*& head, int value) {
    Node* node = new Node{value, head};
    head = node;
}

void traverse(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
    Node* head = nullptr;
    insert_front(head, 30);
    insert_front(head, 20);
    insert_front(head, 10);

    traverse(head);

    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}