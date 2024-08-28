/*
Name: Angel Moreno
Date: 11-21-2021
Description: The purpose of this file is to define methods created in the moreno_list.h file
Usage: This will be compiled with the make file
*/

#include <iostream>
#include "moreno_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

//constructor
linkedList::linkedList(){
  head=NULL;
  current=NULL;
  temp=NULL;
}

//destructor
linkedList::~linkedList(){

}

//this will output the conga line
void linkedList::PrintList(){

  //moves current node to head
    current=head;

    //loops until it reaches the end of the line
    while(current != NULL){

      //outputs the content of the node
      cout << " [" << current->data << "] ";

      //changes current to the next node
      current = current->next;
    }

    //after all nodes are outputed, this ends the line
    cout << endl;
    
}

//this adds a node to the end
void linkedList::addToEnd(char color){

  //this if statement prevents ignores everything if the node is null
 
  //this uses temp to store "color" into it and set the next node to NULL;
  temp = new node();
  temp->next = NULL;
  temp->data = color;
  
  //this checks of head is null and if so, it sets current to head
  if(head != NULL){
    current = head;
    
    //this checks if the next noce is NULL, if false, it moves current to the next node 
    while(current->next != NULL){
      current = current->next;
    }
  
    //makes the next of current to temp  
    current->next = temp;
    
    //sets the position of head to node since the list was empty 
    }else{
    head=temp;
    }
  
}

//this method will return the length of the linked list.
int linkedList::length(){

  //makes a variable to count the length
  int count = 0;

  //moves current to the front of the list
  current=head;
  
  //loops until current reaches the end of the list
  while(current!=NULL){
    current= current->next;
    count = count+1;
  }
  
  //returns the length of the list
  return count;
}

//this returns the data of the front node
char linkedList::retrieveFront(){

  //moves current to the front
  current = head;
  
  //saves the data of the front and returns it
  char data = current->data;
  return data;
}

//returns the end of the list and returns it
char linkedList::retrieveEnd(){

  //moves current to the front
  current = head;
  
  //loops until the next node of current is the last 
  while(current->next!=NULL){
    current= current->next;
  }

  //save the data and returns it
  char data = current->data;
  return data;
}

//retrieve data at a certain index
char linkedList::retrieve(int index){

  //moves current to the front of the list
  current = head;

  //loops until it reaches the desired index
  for(int i=1; i<index; i++){
    current= current->next;
  }

  //save data of the desired node and returns it
  char data = current->data;
  return data;
}

//adds a node to the front
void linkedList::addToFront(char color){

  //first makes temp a new node, second saves color to it, third makes the next of the node the head of the list, then sets temp to be the new head
    temp = new node();
    temp->data = color;
    temp->next = head;
    head = temp;
 
}

//removes the first node
char linkedList::removeFromFront(){

  //if there is no list,return 0
  if(head == NULL){

    return 0;
  }else{ 

    //data will store the data of the node that will be deleted
    char data;
    
    //first sets current to the second node, second saves the data in head into data, third deletes head, finally sets current as the new head of the list
    current = head->next;
    data = head->data;
    delete head;
    head = current;
    
    //returns the data from the deleted node
    return data;
  }
}

//this method removes the last node and returns its data
char linkedList::removeFromEnd(){

  //checks if the list is empty
  if(head == NULL){
    return 0;   
  }else{

    //creats a char variable to store the data of a node 
    char data;

    //sets current to the head node
    current = head;
    
    //checks if head is the only value and deletes it if it is
    if(head->next == NULL){
      data= head->data;
      delete head;
      return data;
    }
    
    //loops through the nodes until current reaches the second to last node
    while(current->next->next != NULL){
      current = current->next;
    }
    
    //these lines save the data of the last node, delete it, and returns the data . it also sets the next of the new last node to NULL so that other methods continue to work
    data = current->next->data;
    delete current->next;
    current->next = NULL;
    return data;
  }
}

//removes the first match of the desired element
void linkedList::removeTheFirst(char data){
  
  //checks of the list is empty
  if(head == NULL){
    
  }else{
    
    //moves temp and current to the front of the list
    current = head;
    temp = current;
    
    //if the element is in the head, the head is deleted 
    if(head->data == data && current != NULL){
      removeFromFront();
    }else{
      
      //loops through the list until it finds the element or current reaches the end of the list
      while(current->data != data && current->next != NULL){
	temp = current;
	current = current->next;
      }
      
      //if the last node matches the element, it is deleted      
      if(current->next  == NULL){
	removeFromEnd();	
      }else{
	
	//if the next of current isnt the end of the list, the node is deleted 
	temp->next = current->next;
	delete current;
      }
      
    }
  }
}

//removes all matches of an element
void linkedList::removeAllOf(char data){

  //this checks if head is empty
  if(head == NULL){  
  }else{

    //moves curent and temp to the front of the list
    current = head;
    temp = current;
    
    //checks if head matches data and removes. looped to prevent an error that can break the list
    for(int i =0; i < 50; i++){
      if(head->data == data && current != NULL){
	current = head->next;
	delete head;
	head = current;
	current = head;
      }
    }
  }

  //checks again if the head is empty 
  if(head == NULL){    
  }else{

    //loops until the end of the list
    while(current->next != NULL){      
      temp = current;
      current = current->next;            
      
      //checks the head and if there is a matche it is deleted
      if(head->data == data && head != NULL){
	current = head->next;
	delete head;
	head = current;
	current = head;
      }
      
      //loops through the list and delete any matches
      if(current->data == data){	
	temp->next = current->next;
	delete current;
	current = temp->next;
	current = head;
      }    
    }
  }
}

//adds an element at a certain index
bool linkedList::addAtIndex(char data, int index){
  //creates a boolean value for true or fals
    typedef enum{failure,success}boolean;
    
    //stores a boolean value
    boolean x = failure;
    boolean y = success;
    
    //saves the size of the list to use later and instantiates a variable that will later store a new list size
    int size = length();
    int newSize;  
    
    //moves current to the front
    current = head;

    //creates nodes that will be used to add the new node
    node* prev = new node();
    node* newNode = new node();
    for(int i = 0; i<index; i++){
      
      //save current in prev and moves current to the next node;
      prev = current;
      current = current->next;
      
    }
    
    //these lines saves data into the new node, sets the next of prev to the new Node, thensets the next of the new node to current; 
    newNode->data = data;
    prev->next = newNode;
    newNode->next = current;
    
    //thses last lines use the length of the list to determine if the function passed or failed. If the new size at he end is the same as the size from the begining of the function, itfailed.
    newSize = length();
    if(size == newSize){
      return failure;
    }else{
      return success;
    }
  
}

//empties the list
void linkedList::empty(){

  //moves current to the head of the list
  current = head;

  //loops until all nodes are deleted
  while(head != NULL){
    current = head;
    head = head->next;
    delete current;

  }
}

//returns the index of a certain element
int linkedList::indexOf(char data){

  //count will keep track of the index
  int count = 0;
  
  //moves current to the front off the list
  current = head;
  
  //checks the head of the list
  if(head->data == data){
    return 0;
  }

  //loops through the list until it finds the element
  while(current->data != data && current != NULL){
    
    count = count + 1;
    current = current->next;
  }

  //returns index
  return count;
}

//checks if an element exists in the list and returns T/F
char linkedList::elementExist(char data){

  //creates char variables to later output T or F
  char true1 = 'T';
  char false1 = 'F';
  
  //moves current to the front
  current = head;
  
  //if the element is in the head it returns T
  if(head->data == data){
    return true1;
    
  }else{

    //loops throught the list until it finds the element or it goes through the whole list
    while(current->data != data && current->next != NULL){
      current = current->next;
      
      //returns T if the element is found
      if(current->data == data){
	return true1;
      }
    }

    //if the element is not found it returns F
    return false1;
  }
}


