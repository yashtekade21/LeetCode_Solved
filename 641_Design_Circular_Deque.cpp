class MyCircularDeque {
public:
    struct node {
        int val;
        node *next, *prev;
        node(int val) {
            this->val = val;
            next = prev = NULL;
        }
    };
    node *head, *tail;
    int size, capacity;
    MyCircularDeque(int k) {
        head = tail = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (size == capacity)
            return false;

        node* newnode = new node(value);
        if (head == NULL) {
            head = tail = newnode;
            head->next = head;
        } else {
            newnode->next = head;
            head->prev = newnode;
            tail->next = newnode;
            newnode->prev = tail;
            head = newnode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == capacity)
            return false;
        node* newnode = new node(value);

        if (head == NULL) {
            head = tail = newnode;
            head->next = head;
            tail->prev = head;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            tail = newnode;
            head->prev = tail;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;

        if (size == 1) {
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;

            temp->next = temp->prev = NULL;
            delete temp;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0)
            return false;

        if (size == 1) {
            delete head;
            head = tail = NULL;
        } else {
            node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;

            temp->next = temp->prev = NULL;
            delete temp;
        }
        size--;
        return true;
    }

    int getFront() {
        if (size == 0)
            return -1;

        return head->val;
    }

    int getRear() {
        if (size == 0)
            return -1;

        return tail->val;
    }

    bool isEmpty() {
        if (size == 0)
            return true;

        return false;
    }

    bool isFull() {
        if (size == capacity)
            return true;

        return false;
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
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
