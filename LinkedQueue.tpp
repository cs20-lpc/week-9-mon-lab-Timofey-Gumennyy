template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (this->length == 0) throw string("Can't access back. Empty Queue");
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* temp = head;
    while (temp)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    if (copyObj.isEmpty()) throw string("Can't copy empty Queue");
    Node* tempCopyObj = copyObj.head->next;
    head = new Node(copyObj.head->value);
    Node* tempThis = head;

    while (tempCopyObj)
    {
        tempThis->next = new Node(tempCopyObj->value);
        last = tempThis->next;
        tempThis = tempThis->next;
        tempCopyObj = tempCopyObj->next;
    }
    this->length = copyObj.length;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (this->length == 0) throw string("Can't dequeue. Empty Queue");
    Node *temp = head;
    head = head->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem, head);
    head = newNode;
    if (this->length == 0) last = newNode;
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (this->length == 0) throw string("Can't access front. Empty Queue");
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
