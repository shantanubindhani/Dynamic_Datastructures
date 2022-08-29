#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include<iostream>

template<typename vtype>
class Stack
{
    int max_size = 1000;
    int min_size = 1;
    int curr_size;
    vtype *dataset;
    public:
        // constructor : sets the stack size to default
        Stack()
        {
            this->max_size = 10;
            this->curr_size = 0;
            this->dataset = new vtype[this->max_size]; // sets the size for dataset
        }

        // constructor : sets the stack size as per user requirement
        Stack(int stack_size)
        {
            if(stack_size > this->max_size){}
            else if(stack_size < min_size) this->max_size = this->min_size;
            else if(stack_size <= max_size) this->max_size = stack_size;
            this->curr_size = 0;
            this->dataset = new vtype[this->max_size]; // sets the size for dataset
        }

        // returns true, if the stack is Full
        bool isFull()
        {
            if(this->curr_size >= this->max_size) return true;
            return false;
        }

        // returns true, if the stack is Empty
        bool isEmpty()
        {
            if(this->curr_size == 0) return true;
            return false;
        }

        // returns the value of top item in Stack
        vtype peek()
        {
            if(this->isEmpty()) throw std::underflow_error("\n Stack is empty. \n");
            return this->dataset[this->curr_size-1];
        }


        // used to add item into the Stack
        // returns, 0: unsuccessfull, 1: successfull
        int pushItem(vtype item)
        {
            if(this->isFull()) return 0;
            int idx = this->curr_size;
            this->dataset[idx] = item;
            this->curr_size += 1;
            return 1;
        }

        // used to remove item from the Stack
        // returns, 0: unsuccessfull, 1: successfull
        vtype popItem()
        {
            if(this->isEmpty()) throw std::underflow_error("\n Stack is empty. \n");
            this->curr_size -= 1;
            return this->dataset[this->curr_size];
        }

        // returns the max size of Stack
        int getStackSize(){return this->max_size;}
};



#endif