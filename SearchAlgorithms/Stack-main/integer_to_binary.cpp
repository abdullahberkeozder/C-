//reads an integer and converts it into binary form using a stack.

#include <iostream>
using namespace std;

#define MAX 50
class Stack {
private:
	int items[MAX];
	int top;
public:
	Stack() :
			top(-1) {
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == (MAX-1);
	}

	bool push(int item) {
		if (isFull())
			return false;
		items[++top] = item;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;
        else{
            item = items[top--];
            return true;
        }
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		item = items[top];
		return true;
	}
};

typedef struct node {
	int data;
	struct node *next;
} Node;

class StackLinkedList {
private:
	Node *top;

	Node* createNode(int data) {
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
	}
public:
	StackLinkedList() :
			top(NULL) {
	}

	bool isEmpty() {
		return top == NULL;
	}

	bool isFull() {
		return false;
	}

	bool push(int item) {
		Node *newNode = createNode(item);
		newNode->next = top;
		top = newNode;
		return true;
	}

	bool pop(int &item) {
		if (isEmpty())
			return false;

		item = top->data;
		Node *tmp = top;
		top = top->next;
		delete tmp;
		return true;
	}

	bool peek(int &item) {
		if (isEmpty())
			return false;
		return top->data;
	}

};

int main() {
	StackLinkedList stk;

    int value, stackNum = 0;
    int binNum;

    cout << "Enter a integer to convert into binary: ";
    cin >> value;

    while (value != 0){
        binNum = value % 2;
        stk.push(binNum);
        stackNum++;

        value = value / 2;
    }
    cout << "\nYour binary is: ";
    int item;
	while (!stk.isEmpty()){
		stk.pop(item);
		cout << item << " ";
	}
	return 0;

}
