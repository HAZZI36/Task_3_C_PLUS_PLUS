#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data, Node* next = nullptr, Node* prev = nullptr) :
            data(data), next(next), prev(prev) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    const T& front() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    const T& back() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    void pushFront(const T& data) {
        head = new Node(data, head, nullptr);
        if (tail == nullptr) {
            tail = head;
        }
        else {
            head->next->prev = head;
        }
        ++size;
    }

    void pushBack(const T& data) {
        tail = new Node(data, nullptr, tail);
        if (head == nullptr) {
            head = tail;
        }
        else {
            tail->prev->next = tail;
        }
        ++size;
    }

    void popFront() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
        delete temp;
        --size;
    }

    void popBack() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        delete temp;
        --size;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    // Example with int
    DoublyLinkedList<int> list;
    list.pushFront(3);
    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    list.popFront();
    list.popBack();
    list.print();

    // Example with string
    DoublyLinkedList < std::string > list2;
    list2.pushFront("world");
    list2.pushFront("hello");
    list2.pushBack("!");
    std::cout << "Front: " << list2.front() << std::endl;
    std::cout << "Back: " << list2.back() << std::endl;
    list2.popFront();
    list2.popBack();
    list2.print();

    return 0;
}
