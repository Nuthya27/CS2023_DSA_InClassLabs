// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//STACK USING ARRAY

#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;


#define MAX 100

class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}


// Driver program to test above functions
int main()
{
    class Stack newStack;
    cout << "Stack using Array" << endl;
    auto start = high_resolution_clock::now();
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    newStack.push(rand() % 1000 + 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken:  " << duration.count() << " nanoseconds" << "\n";

    return 0;
}