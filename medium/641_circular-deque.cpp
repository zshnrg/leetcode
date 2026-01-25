

class MyCircularDeque {
    struct Node {
        int val;
        Node* next;
        Node* prev;

        Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int capacity;
    int size;
public:

    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        Node* p = new Node(value);
        if (isEmpty()) {
            tail = p;
        } else {
            head->prev = p;
            p->next = head;
        }
        head = p;
        
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        
        Node* p = new Node(value);
        if (isEmpty()) {
            head = p;
        } else {
            tail->next = p;
            p->prev = tail;
        }
        tail = p;

        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        Node* temp = head;

        if (size == 1) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        
        Node* temp = tail;
        if (size == 1) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete tail;

        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */