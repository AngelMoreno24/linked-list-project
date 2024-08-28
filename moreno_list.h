
/*
Name: Angel Moreno
Date: 11-21-2021
Description: This file declared functions that will be defined as methons in the moreno_list.cpp file
Usage: this will be compiled with the makefile.
*/

#pragma once
#ifndef MORENO_LIST_H
#define MORENO_LIST_H
#include <string>
#include <stdio.h>
#include <stdlib.h>


//creates the node class
class node{

  //creats public variables
 public:
  char data;
  node* next;

  //getters
  char getData(){
    return data;
  };

  node* getNext(){
    return next;
  };

    void printlist(node*);
};

class linkedList{

 private:
  //creates private nodes
  node* head;
  node* next;

  node* current;
  node* temp;


 public:
  //constructor
  linkedList();

  //destructor
  ~linkedList();

  //creates methods
  int length();

  void PrintList();

  void addToFront(char color);

  void addToEnd(char color);

  bool addAtIndex(char data, int index);

  char retrieveFront();

  char retrieveEnd();

  char retrieve(int index);

  char removeFromFront();

  char removeFromEnd();

  void removeTheFirst(char data);

  void removeAllOf(char data);

  char elementExist(char data);

  int indexOf(char data);

  void empty();

  //getters
  node* getHead(){
    return head;
  }
  
  node* getNext(){           
    return next;
  }
  
};


#endif
