//The program filter out repeated characters and display the final queue on screen

#include <iostream>
using namespace std;

#define MAX 50
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

    Queue que;
    char data = '0';
    int que_counter = 0;
    cout << "Enter: ";
    while (data != '.') {
        cin >> data;
        if (data != '.') {
            que.enqueue(data);
            que_counter++;
        }

    }
    cout << "Initial size of queue: " << que_counter << endl;

    Queue temp;
    Queue unique;
    int temp_counter = 0, final_counter = 0;
    char repeated, temp_repeated;

    que.dequeue(data);
    repeated = data;

    que.dequeue(data);
    temp_repeated = data;
    int index = 0;
    while (index < que_counter - 1) {
        if (repeated == temp_repeated) {
            cout <<"ayni cikan-> " << data << endl;
            que.enqueue(temp_repeated);
            temp.enqueue(temp_repeated);
            temp_counter++;
        }
        else{
            cout << "farkli cikan-> " << data << endl;
            que.enqueue(repeated);
            que.enqueue(temp_repeated);
            final_counter++;
        }
        que.dequeue(data);
        repeated = data;

        que.dequeue(data);
        temp_repeated = data;
        index++;
    }
    cout << "Dropped Chars: ";
    while (!temp.isEmpty()) {
        temp.dequeue(data);
        cout << data << " ";
    }
    cout << endl;

    cout << "Final size of queue: " << final_counter << endl;
    cout << "Final queue: ";
    while (!que.isEmpty()) {
        que.dequeue(data);
        cout << data << " ";
    }
    return 0;
}
