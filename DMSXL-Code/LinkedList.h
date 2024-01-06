#pragma once
#include <stdexcept>

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* head;
    int size;
public:
    LinkedList() {
        head = new Node;
        head->next = nullptr;
        size = 0;
    }

    ~LinkedList() {
        clear();
        delete head;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void addFirst(const T& value) {
        add(0, value);
    }

    void add(int index, const T& value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        Node* newNode = new Node;

        newNode->data = value;

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }

    void addLast(const T& value) {
        add(size, value);
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = value;
    }

    bool contains(const T& value) const {
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* current = prev->next;
        prev->next = current->next;
        delete current;
        size--;
    }

    void clear() {
        while (head->next != nullptr) {
            Node* temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        size = 0;
    }

};
