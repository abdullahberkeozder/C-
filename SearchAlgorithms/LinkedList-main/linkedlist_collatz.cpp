//The program reads an integer from the user and populates a Collatz linked list until either 1 is observed, or 100 integers have been generated. 
//Then the program must ask the user to enter an integer and search for this integer in the list. 
//If it has been found, it must display the position of this number and a list of all numbers prior to the entered number.

#include<iostream>
#include<cstdlib>

using namespace std;

struct collatzNode{
    int data;
    collatzNode *next;
};
struct collatzNode *head = NULL;

void insertNode(int value){
    struct collatzNode *collatzNode = (struct collatzNode * ) malloc(sizeof(struct collatzNode));

    collatzNode->data = value;
    collatzNode->next = head;

    head = collatzNode;
}

void reverse() {
    struct collatzNode *t = NULL;
    struct collatzNode *prev = NULL;
    struct collatzNode *curr = (head);
    while(curr != NULL) {
        t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    (head) = prev;
}

void checking(int searchNum){
    struct collatzNode* searchPtr;
    struct collatzNode* ptr;

    searchPtr = head;
    ptr = head;
    int position = 1;

    while (searchPtr != NULL){
        if(searchPtr->data == searchNum){
            cout<<searchNum<<" is found in node "<<position<<". Numbers leading to "<<searchNum<<" in the list are:"<<endl;
            while(ptr != searchPtr){
                cout<<ptr->data<<"->";
                ptr = ptr->next;
            }
            cout<<ptr->next->data;
            break;
        }
        else if(searchPtr->data != searchNum){
            cout<<searchNum<<" is not in the list.";
            break;
        }
        else{
            searchPtr = searchPtr->next;
        }
        position++;
    }
}

void display() {
    struct collatzNode* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout<< ptr->data;
        ptr = ptr->next;

        if(ptr != NULL)
            cout<<"->";
    }
}


void deleteList(){
   struct collatzNode* current = head;
   struct collatzNode* nextnode;

   while (current != NULL){
       nextnode = current->next;
       free(current);
       current = nextnode;
   }

   head = NULL;
}


int main() {
    //declarations
    int numOfTerms = 0;
    int maxNumOfTerms = 0;

    int numWithLongestChain = 0;
    int collatzTerm = 0;

    long long sequenceNum;
    int userNum;
    int searchNum;

    //get user input
    cout << "Enter starting number: ";
    cin >> userNum;

    for (int i = collatzTerm; i <= userNum; i++) {

        sequenceNum = i;
        numOfTerms = 1;

        //calculating the section of numOfTerms for this current sequenceNum
        while (sequenceNum > 1) {
            if (sequenceNum % 2 == 0)
                sequenceNum = sequenceNum / 2;

            else
                sequenceNum = 3 * sequenceNum + 1;

            numOfTerms += 1; //increment numOfTerms
        }
        if (numOfTerms >= maxNumOfTerms) {
            maxNumOfTerms = numOfTerms;
            numWithLongestChain = i;
        }
    }

    //display the message
    cout << "List has been generated "<< "(" << maxNumOfTerms <<" integers):"<< endl;

    //insert node to link list
    sequenceNum = numWithLongestChain;
    while (sequenceNum > 1) {
        if (sequenceNum % 2 == 0)
            sequenceNum = sequenceNum / 2;

        else
            sequenceNum = 3 * sequenceNum + 1;

                // insert value
                insertNode(sequenceNum);
        numOfTerms += 1; //increment numOfTerms
    }

    cout<< numWithLongestChain << "->";

    // reverse linked list
    reverse();
    // display linked list
    display();

    cout<<"\n";
    cout<<"Enter search term: ";
    cin>>searchNum;

    checking(searchNum);

    // delete linked list
    deleteList();

    return 0;
}
