

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>


// the structure of each node in a linked list
template<typename DC>
class Node
{
    DC data; // data stored
    public:
        Node<DC> *prev; // pointer to last node
        Node<DC> *next; // pointer to next node

        //constructor
        Node(){
            this->prev = NULL;
            this->next = NULL;
        }
        Node(DC data)
        {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        // setter : data
        void setData(DC data){this->data = data;}
        
        // getter : data
        DC getdata(){return this->data;}
};

template<typename vtype>
class LinearLinkedList
{
    Node<vtype> *head = NULL;
    Node<vtype> *end;
    int length = 0;
    
    void updateEnd()
    {
        Node<vtype> *curr = head;
        while(curr->next != NULL) curr = curr->next;
        this->end = curr;
    }

    public:

    //constructor-initialization
    LinearLinkedList()
    {
        std::cout<<std::endl<<"[ Linear Linked List ] created."<<std::endl;
        end = head;
    }

    // add item to the linked list by index
    // returns, 0: unsuccessfull, 1: successfull
    int insertAtIndex(vtype value, int idx)
    {  
        try{
            int res;
            if(idx == 0)
            {
                res = insertAtStart(value);
                if(res == 1) return 1;
                else return 0;
            }
            else if(idx >= length) return 0;

            Node<vtype> *curr = head;
            Node<vtype> *temp = new Node<vtype>(value);
            int count = 0;
            
            while(count < idx-1) { curr = curr->next; ++count;}
            temp->next = curr->next;
            curr->next = temp;
            this->updateEnd();
            this->length += 1;
            return 1;
        }catch(...){}
        return 0;    
    }

    // used to add item at the start of linked list
    // returns, 0: unsuccessfull, 1: successfull
    int insertAtStart(vtype value)
    {
        try{
            Node<vtype> *temp = new Node<vtype>(value);
            temp->next = this->head;
            head = temp;
            this->length += 1;
            this->updateEnd();
            return 1;
        }
        catch(...){}
        return 0;
    }

    // used to add item at the end of linked list
    // returns, 0: unsuccessfull, 1: successfull
    int insertAtEnd(vtype value)
    {
        try{
            if(length == 0)
            {
                int res = insertAtStart(value);
                if(res == 1) return 1;
                else return 0;
            }   
            Node<vtype> *temp = new Node<vtype>(value);
            this->end->next = temp;
            this->end = temp;
            this->length += 1;
            return 1;
        }
        catch(...){}
        return 0;
    }


    // used to view the length of Linked List
    // returns : Integer
    int getLength()
    { return this->length;}

    // used to delete item form linked list using item value
    // returns, 0: unsuccessfull, 1: successfull
    int deleteItem(vtype value)
    {
        try{
            if(this->length == 0) return 0;     
            int idx = searchItem(value);
            int res = deleteByIndex(idx);
            if(res == 1) return 1;
        }catch(...){}
        return 0;
    }

    // used to delete item from linked list using item index
    // returns, 0: unsuccessfull, 1: successfull
    int deleteByIndex(int idx = 0)
    {
        try{
            if(this->length == 0) return 0;
            if(idx == 0) {head = head->next; return 1;}
            if(idx >= length) return 0;
            int count = 0;
            Node<vtype> *curr = head;
            Node<vtype> *temp = new Node<vtype>();
            while(count++ < idx-1) curr = curr->next;
            temp = curr;
            temp = temp->next;
            curr->next = temp->next;
            delete temp;
            this->length -= 1;
            return 1;
        }catch(...){}
        return 0;
    }

    // used to display the whole liked list
    // format : -->[index, data]
    void displayList()
    {
        std::cout<<std::endl<<"-----< Linked List >-----"<<std::endl;
        if(head == NULL)
        {
            std::cout<<" List is Empty"<<std::endl;
            return;
        }
        Node<vtype> *ptr = head;
        int idx = 0;
        
        while(ptr != NULL)
        {
            std::cout<<"-->["<<idx<<", "<<ptr->getdata()<<"]";
            ptr = ptr->next;
            ++idx;
        }
        std::cout<<"-->[END] (" <<this->length <<" items)"<<std::endl;;
    }

    // used to search the linked list for a specific item
    // return the index of that item
    // -1 : not found, +ve number : index of item
    int searchItem(vtype value)
    {
        if(head == NULL) return -1;
        int found = -1;
        int idx = 0;
        Node<vtype> *temp = head;
        while(temp != NULL)
        {
            if(temp->getdata() == value)
            {
                found = idx;
                break;
            }
            temp = temp->next;
            ++idx;
        }
        return found;
    }
};



#endif