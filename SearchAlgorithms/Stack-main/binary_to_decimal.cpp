//reads a binary expression and converts it into decimal form using a stack.

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

	bool peek() {
		if (isEmpty())
			return false;
        cout<<top->data;
		return true;
	}

};

int main() {
	StackLinkedList stk;

    int value = 0;
    int digit = 1;
    int binNum;

    cout << "Enter binary number to convert an integer: ";
    cin >> binNum;

    while (binNum != 0){
        value += (binNum % 10) * digit;

        stk.push(value);

        binNum = binNum / 10;
        digit = digit * 2;
    }
    cout << "\nYour integer is: ";
    stk.peek();

    cout << "\nThe Stack is: ";
    int dig_item;
    int i = 1;
	while (!stk.isEmpty()){
		stk.pop(dig_item);
		cout <<dig_item << " ";
		i++;
	}
    cout<<endl;
	return 0;
}
