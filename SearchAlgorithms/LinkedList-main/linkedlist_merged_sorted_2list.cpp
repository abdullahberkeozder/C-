//The program reads any number of integers in sorted order in two seperate linked lists until “-1”’s are entered. 
// Then the program construct and print a new, merged, sorted list out of the seperate lists.

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

    void merging(LinkedList list1, LinkedList list2,LinkedList& list3) 
    {
        node *first, *second;
        first=list1.head;
        second=list2.head;

        int dat;
        while(first!=NULL && second!=NULL)
        {
            if(first->data > second->data)
            {
                dat=second->data;
                list3.insertToEnd(dat);
                second=second->next;
            }

            else{
                dat=first->data;
                list3.insertToEnd(dat);
                first=first->next;
            }
        }
        if(first==NULL)
        {
            while(second!=NULL)
            {
                dat=second->data;
                list3.insertToEnd(dat);
                second=second->next;
            }
        }
        else{
                while(first!=NULL)
            {
                dat=first->data;
                list3.insertToEnd(dat);
                first=first->next;
            }
        }
    }
};

int main() {

    LinkedList linkedList_first;
    LinkedList linkedList_second;
    LinkedList linkedList_merged;

    int data1, data2;

    cout<<"Enter first list: ";
    cin>>data1;

    while(data1 != -1)
    {
        linkedList_first.insertToEnd(data1);
        cin>>data1;
    }

    cout<<"Enter second list: ";
    cin>>data2;

    while(data2 != -1)
    {
        linkedList_second.insertToEnd(data2);
        cin>>data2;
    }

    cout << "Merged list: ";
    linkedList_merged.merging(linkedList_first, linkedList_second, linkedList_merged);
    linkedList_merged.print();


    return 0;
}
