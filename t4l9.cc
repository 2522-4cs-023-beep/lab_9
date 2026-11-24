#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* items;
    int capacity;
    int top; 

public:
    Stack(int cap) {
        capacity = (cap < 1) ? 1 : cap;
        top = 0;
        items = new T[capacity];
    }

    ~Stack() {
        delete[] items;
        items = nullptr;
    }

    bool isEmpty() const {
        return top == 0;
    }

    bool isFull() const {
        return top == capacity;
    }

    int size() const {
        return top;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full, cannot push " << value << endl;
            return;
        }
        items[top] = value;
        top++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        top--;
        return items[top];
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return items[top - 1];
    }
};

int main() {
    Stack<int> nums(3);
    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40); 

    cout << "Popping: ";
    while (!nums.isEmpty()) {
        cout << nums.pop();
        if (!nums.isEmpty()) {
            cout << " ";
        }
    }
    cout << endl;

    string word = "LAHORE";
    Stack<char> letters(word.length());
    for (size_t i = 0; i < word.length(); i++) {
        letters.push(word[i]);
    }

    cout << word << " reversed: ";
    while (!letters.isEmpty()) {
        cout << letters.pop();
    }
    cout << endl;

    Stack<string> history(10);
    history.push("google.com");
    history.push("github.com");
    history.push("gutech.edu.pk");

    cout << "Current page: " << history.peek() << endl;
    history.pop(); // go Back
    cout << "After Back: " << history.peek() << endl;

    return 0;
}