#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include<iostream>

template<typename vtype>
class Queue
{
    int max_size = 1000;
    int min_size = 1;
    int curr_size;
    vtype *dataset;
    public:
        // constructor : sets the Queue size to default
        Queue()
        {
            this->max_size = 10;
            this->curr_size = 0;
            this->dataset = new vtype[this->max_size]; // sets the size for dataset
        }

        // constructor : sets the Queue size as per user requirement
        Queue(int Queue_size)
        {
            if(Queue_size > this->max_size){}
            else if(Queue_size < min_size) this->max_size = this->min_size;
            else if(Queue_size <= max_size) this->max_size = Queue_size;
            this->curr_size = 0;
            this->dataset = new vtype[this->max_size]; // sets the size for dataset
        }

        // returns true, if the Queue is Full
        bool isFull()
        {
            if(this->curr_size >= this->max_size) return true;
            return false;
        }

        // returns true, if the Queue is Empty
        bool isEmpty()
        {
            if(this->curr_size == 0) return true;
            return false;
        }

        // returns the value of top item in Queue
        vtype peek()
        {
            if(this->isEmpty()) throw std::underflow_error("\n Queue is empty. \n");
            return this->dataset[0];
        }


        // used to add item into the Queue
        // returns, 0: unsuccessfull, 1: successfull
        int pushItem(vtype item)
        {
            if(this->isFull()) return 0;
            int idx = this->curr_size;
            this->dataset[idx] = item;
            this->curr_size += 1;
            return 1;
        }

        // used to remove item from the Queue
        // returns, 0: unsuccessfull, 1: successfull
        vtype popItem()
        {
            if(this->isEmpty()) throw std::underflow_error("\n Queue is empty. \n");
            vtype data = this->dataset[0];

            for(int i = 0; i<curr_size-1; ++i) this->dataset[i] = this->dataset[i+1];
            this->curr_size -= 1;
            return data;
        }

        // returns the max size of Queue
        int getQueueSize(){return this->max_size;}
};



#endif