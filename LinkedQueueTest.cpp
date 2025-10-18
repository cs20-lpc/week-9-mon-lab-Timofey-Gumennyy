#include "LinkedQueue.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
void testQueueBreaking(LinkedQueue<T>& q, const string& typeName, const T& v1, const T& v2, const T& v3) {

    // Test empty queue operations
    cout << "Trying to call front() and back() on empty queue...\n";
    try {
        q.front();
        cout << "[ERROR] front() did not throw\n";
    } catch (string& e) {
        cout << "Caught expected exception (front): " << e << "\n";
    } catch (...) {
        cout << "Caught unknown exception for front()\n";
    }

    try {
        q.back();
        cout << "[ERROR] back() did not throw\n";
    } catch (string& e) {
        cout << "Caught expected exception (back): " << e << "\n";
    } catch (...) {
        cout << "Caught unknown exception for back()\n";
    }

    // Test dequeue() on empty queue
    cout << "Trying to dequeue() empty queue...\n";
    try {
        q.dequeue();
        cout << "[ERROR] dequeue() did not throw\n";
    } catch (string& e) {
        cout << "Caught expected exception (dequeue): " << e << "\n";
    } catch (...) {
        cout << "Caught unknown exception for dequeue()\n";
    }

    // Normal enqueue/dequeue with valid input
    cout << "Enqueuing 3 elements...\n";
    q.enqueue(v1);
    q.enqueue(v2);
    q.enqueue(v3);
    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";

    cout << "Dequeuing all elements...\n";
    while (!q.isEmpty()) {
        cout << "Removing " << q.front() << "\n";
        q.dequeue();
    }

    cout << "Queue is now empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";

    // Test clear() with already-empty queue
    cout << "Calling clear() on already empty queue...\n";
    try {
        q.clear();
        cout << "clear() executed safely.\n";
    } catch (...) {
        cout << "[ERROR] clear() threw unexpectedly.\n";
    }

    cout << "Test complete for type: " << typeName << "\n";
}

int main() {
    // Test with int
    LinkedQueue<int> qInt;
    testQueueBreaking(qInt, "int", 1, 2, 3);

    // Test with double
    LinkedQueue<double> qDouble;
    testQueueBreaking(qDouble, "double", 1.1, 2.2, 3.3);

    // Test with string
    LinkedQueue<string> qString;
    string v1 = "apple";
    string v2 = "banana";
    string v3 = "cherry";
    testQueueBreaking(qString, "string", v1, v2, v3);

    //  Deep copy (copy constructor) test
    cout << "\n=== Testing deep copy integrity ===\n";
    LinkedQueue<int> original;
    original.enqueue(10);
    original.enqueue(20);
    original.enqueue(30);

    cout << "Original queue front: " << original.front()
    << ", back: " << original.back() << "\n";

    LinkedQueue<int> copy = original;  // invokes copy constructor

    cout << "Copy queue front: " << copy.front()
         << ", back: " << copy.back() << "\n";

    // Modify original, ensure copy is unaffected
    original.dequeue();
    original.enqueue(99);

    cout << "\nAfter modifying original:\n";
    cout << "Original front/back: " << original.front() << ", " << original.back() << "\n";
    cout << "Copy front/back:     " << copy.front()     << ", " << copy.back()     << "\n";

    cout << (copy.front() != 10 && copy.back() != 30
             ? " Deep copy successful (no shared pointers)"
             : "Shallow copy detected (shared pointers)") << "\n";

    return 0;
}
