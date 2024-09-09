#include <iostream>



class Linked_List_Node {
private:
    int data;
    Linked_List_Node *next_node; // pointer to the next node in the linked list
public:
    // no args constructor
    Linked_List_Node() : data {0}, next_node {nullptr} {}
    // overloaded constructor
    Linked_List_Node(int data) : data {data}, next_node {nullptr} {};

    void set_next(Linked_List_Node *next) {
        next_node = next;
    }
    Linked_List_Node *get_next_node() {
        return next_node;
    }
    int get_data() const {
        return this->data;
    }
    void set_data(int new_data_value) {
        this->data = new_data_value;
    }
};

class Linked_List {
private:
    Linked_List_Node *head;
    Linked_List_Node *tail;
    int size;
public:
    // constructor
    Linked_List() : head {nullptr}, tail {nullptr}, size {0} {};
    // append function
    void append(Linked_List_Node &new_node) {
        if (size == 0) {
            head = &new_node;
            tail = &new_node;
            size++;
        }
        else if (size == 1) {
            head->set_next(&new_node);
            tail = &new_node;
            size++;
        }
        else {
            Linked_List_Node *current = head;
            while (current != nullptr) {
                if (current->get_next_node() == nullptr) {
                    current->set_next(&new_node);
                    tail = &new_node;
                    size++;
                    return;
                }
                current = current->get_next_node();
            }
        }
    }

    void display() {
        std::cout << "[";
        Linked_List_Node *current = head;
        while (current != nullptr) {
            std::cout << current->get_data() << "->";
            current = current->get_next_node();
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Linked_List_Node node1 (2);
    Linked_List_Node node2 (6);
    Linked_List_Node node3 (8);

    Linked_List My_linked_list;
    My_linked_list.append(node1);
    My_linked_list.append(node2);
    My_linked_list.append(node3);

    My_linked_list.display();
    return 0;
}
