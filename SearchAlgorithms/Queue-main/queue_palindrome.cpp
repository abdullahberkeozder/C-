// This program reads a sequence of letters from the user and checks if the entered string is a palindrome or not.

#include <iostream>
using namespace std;

#define MAX 50
class Stack {
private:
    char items[MAX];
    char top;
public:
    Stack() :
        top(-1) {
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == (MAX - 1);
    }

    bool push(char item) {
        if (isFull())
            return false;
        items[++top] = item;
        return true;
    }

    bool pop(char& item) {
        if (isEmpty())
            return false;
        item = items[top--];
        return true;
    }

    bool peek(char& item) {
        if (isEmpty())
            return false;
        item = items[top];
        return true;
    }
};
class Queue {
private:
    char items[MAX];
    int front;
    int rear;

public:
    Queue() :front(0), rear(-1) {}

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool enqueue(char data) {
        if (isFull())
            return false;

        items[++rear] = data;
        return true;
    }

    bool dequeue(char& data) {
        if (isEmpty())
            return false;
        data = items[front++];
        return true;
    }

    bool peek(char& data) {
        if (isEmpty())
            return false;
        data = items[front];
        return true;
    }
};

int main() {
    Stack stack;
    Queue queue;
    Queue temp_queue;

    char data;
    char temp_data;

    string str_queue;
    
    cout << "Enter your string: ";
    cin >> str_queue;
    
    int i = 0;

    while (i > str_queue.size()) {
        stack.push(str_queue[i]);
        i++;
    }
    while (stack.isEmpty() != 0) {
        stack.pop(data);
        temp_queue.enqueue(data);
        queue.enqueue(data);
    }
    while (temp_queue.isEmpty()!=0)
    {
        temp_queue.dequeue(temp_data);
        stack.push(temp_data);
    }
    data = 'N';
    temp_data = 'N';
    for (i = 0; i < str_queue.size(); i++) {
        queue.dequeue(temp_data);
        stack.pop(data);
        if (data == temp_data)
            continue;
        else {
            cout << str_queue << "is not palindrome.";
            break;
        }
    }
    return 0;
}
