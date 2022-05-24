//
//  LL.cpp
//  DSA-LinkList
//
//  Created by Hina Khalid  on 14/02/2022.
//  Copyright © 2022 Hina Khalid . All rights reserved.
//

#include<iostream>
#include<stdio.h>
using namespace::std;

class node
{
public:
    string data;
    node* link;
};

class Linklist
{
    public:
    node* head;
    
public:
    Linklist()
    {
        head=NULL;
    }
    
    // insert at the start of the list
    void insertH(string y)
    {  

       node* newnode=new node();
       newnode->data=y;
       newnode->link=head;
       head=newnode;

        
    }
    // insert at the end of the list
    void insertT(string y)
      { node* newnode=new node();
        node* previous=head;
        newnode->data=y;
        newnode->link=NULL;

    
        if (head==NULL){
            head=newnode;
        }
        else{
        while(previous->link!=NULL){
            previous=previous->link;
        }
        previous->link=newnode;
        
    }}
    
    // position starting from 0
    void insertAfter(int y,int pos)
    {
        node* newnode=new node();
        node* previous=head;
        int count=1;
        while(count!=pos){
            previous=previous->link;
            count++;
        }
        
        newnode->data=y;
        newnode->link=previous->link;
        previous->link=newnode;

        
    }
    // delete from the head/start of the list
    void deleteH()
    
    {   node* previous=head;
        node* temp=new node();
        if (head==NULL){
        cout<<"linked list is empty!"<<endl;

    }
    else{
        temp=head;
        previous=previous->link;
        head=previous;
        delete temp;
    }
 
        
    }
    
    // delete from the tail of the list and return the deleted value
   
    
    //returns the no of node  being searched

    
    void print()
    {
        node * tptr=head;
        while(tptr!=NULL)
        {
            cout<<tptr->data<<" -> ";
            tptr=tptr->link;
            
        }
        cout<<"NULL\n"    ;
    }
    
   
    int isEmpty()
    {
        if(head==NULL)
            return 1;  // for true
        else return 0;  // for false
    }
};


