//reads a string of parantheses from the user and checks if the parantheses are balanced or not using a stack.

#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 50

class Stack{
    private:
        int items[MAX]; // creating array to fill the stack.
        int top; // top index of stack.
    public:
            // constructor
            Stack()
            {
                top = -1; // setting top = -1 when that is empty.
            }

        // Push operation to insert an element on top of stack.
        void pushOfStack(int x){
          if(top == MAX -1){
                printf("Error: stack overflow\n");
                return;
            }
            items[++top] = x;
        }

        // Pop operation to remove an element from top of stack.
        void popOfStack(){
            if(top == -1){
                printf("Error: No element to pop\n");
                return;
            }
            top--;
        }

        // Top operation to return element at top of stack.
        int topOfStack(){
            return items[top];
        }

        // This function will return 1 (true) if stack is empty, 0 (false) otherwise
        int isEmptyOfStack()
        {
            if(top == -1)
                return 1;
            return 0;
        }
        void printOfStack(){
            int i;
            printf("Stack: ");
            for(i = 0;i<=top;i++)
                    printf("%d ",items[i]);
            printf("\n");
        }
};

int main()
{
    Stack stk;
    char paranthes;
    cout<<"Enter your string: ";
    paranthes = getchar();
    while(paranthes != '\n'){
        if(paranthes == '('){
            stk.pushOfStack(paranthes);
        }
        else if(paranthes == ')'){
            if(stk.isEmptyOfStack() || (stk.topOfStack()!='(' && paranthes==')'));
            else
                stk.popOfStack();
        }
        paranthes = getchar();
    }
    if(stk.isEmptyOfStack())
    {
        cout<<"The string is balanced.";
    }
    else
        cout<<"The string is not balanced.";

    return 0;
}
