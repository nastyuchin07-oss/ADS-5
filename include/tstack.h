#ifndef TSTACK_H
#define TSTACK_H

#include <stdexcept>

template<typename T, int N>
class TStack {
 private:
    T data[N];
    int topIndex;

 public:
    TStack() : topIndex(-1) {}

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        data[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[topIndex--];
    }

    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == N - 1;
    }

    int size() const {
        return topIndex + 1;
    }

    void clear() {
        topIndex = -1;
    }
};

#endif
