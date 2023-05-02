// lab6_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//STACK USING LINKED LIST

#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;


class StackNode {
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;

}

int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

// Driver code
int main()
{
    StackNode* root = NULL;

    cout << "Stack using Linked List" << endl;
    auto start = high_resolution_clock::now();
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);

    pop(&root);
    pop(&root);
    pop(&root);
    pop(&root);
    pop(&root);

    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);
    push(&root, rand() % 1000 + 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken:  " << duration.count() << " nanoseconds" << "\n";

    return 0;
}
