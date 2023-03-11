//The program reads any number of integers in a linked list until “-1” is entered. 
//Then the program display all numbers between the smallest and largest numbers in this list.

#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}Node;

class LinkedList {
private:
    Node *head;

    Node* createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode ->next = NULL;
        return newNode;
    }
public:
    LinkedList():head(NULL) {}

    void print() {
        Node *curr = head;
        while(curr != NULL) {
            cout<<curr->data<<"->";
            curr = curr->next;
        }
        cout<<"NULL"<<endl;
    }

    void insertToEnd(int data) {
        Node *newNode = createNode(data);

        if(head == NULL){
            head = newNode;
            return;
        }

        Node *curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    void max_min_Node(){
        Node *curr = head;
        Node *temp = head;
        int maxNode, minNode;
        int maxInd = 0, minInd = 0, index = 0;

        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else{
            maxNode = head->data;
            minNode = head->data;
            while(curr != NULL) {
                 if(maxNode < curr->data) {
                     maxNode = curr->data;
                     maxInd = index;
                 }
                 if(minNode > curr->data){
                     minNode = curr->data;
                     minInd = index;
                 }
                curr = curr->next;
                index++;
            }
        if(minInd > maxInd)
            swap(minInd, maxInd);
        }
        index = 0;
        while(index < minInd){
            temp = temp->next;
            index++;
        }
        cout<<"Result: ";
        while(index < maxInd)
        {
            cout<<temp->data<<"->";
            index++;
            temp = temp->next;
        }
        cout<< temp->data;
    }
};
int main() {

    LinkedList linkedList;
    int data;

    cout<<"Enter your list: ";
    cin>>data;

    while(data != -1)
    {
        linkedList.insertToEnd(data);
        cin>>data;
    }
    linkedList.print();
    linkedList.max_min_Node();

    return 0;
}
