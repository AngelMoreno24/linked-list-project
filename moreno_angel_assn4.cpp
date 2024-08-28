/*
Name: Angel Moreno
Date: 11-21-2021
Description: This file will call linked list methods to create a zombie conga line and randomly perform actions as many times as the user wants or if the line is empty
Usage: must use makefile to compile. to use type ./output which is compiled from the make file. the user will be asked for the amount of rounds. after the rounds are done the user if asked if they want to continue. if they want to continue they must type yes. if not type no.
*/

#include "moreno_list.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

//this declares a random color generator
char randomC();

//these lines declare the action mathods 
void engine(char zombie);
void caboose(char zombie);
void jumpIn(char zombie);
void everyoneOut(char zombie);
void youreDone(char zombie);
void brains(char zombie);
void rainbowBrains(char zombie);
void action(int roll,char zombie);

//creats an object of linked list
linkedList conga;

int main(int argc,char** argv){

  //these variables are used as counters
  int rounds;
  int roundCounter = 0;
  int roundRemoveCounter = 1;

  //this will setup the random number generator
  srand((unsigned int)time(NULL));

  //color is used to stored a random color
  char color;
  color = randomC();

  //performs rainbow brains action
  rainbowBrains(color);

  //num chooses a number between 2 and 5 and performs that manny actions. roll then chooses a random number to performa a random action
  int num = (rand() % 3 + 1) + 2;
  for(int i=0; i<num; i++){
    int roll = (rand() % 7 + 1);
    action(roll,color);
  }

  //confirm keeps track of whether the user wants to continue the party
  string confirm = "yes";

  //action will be used to randomly choose an action
  int roll;

  //end keeps track of the length of the list and endIt wil be used to end the loop if the list is empty 
  int end;
  string endIt;

  //this while loop will produce rounds as long as the user wants or until the list is empty
  while(confirm != "no" && confirm == "yes" && endIt != "end"){

    //asks the user to inout the amount of rounds and saves it
    cout << "\nhow many rounds" << endl;
    cin >> rounds;

    //this for loop loopes for the amount of rounds chosen
    for(int i = 0; i<rounds; i++){

      //chooses a random number between 1 and 7 in order to perform a random action based on the number
      int rol1 = (rand() % 7 + 1);

      //these two lines display the current round
      cout << "Round: " << roundCounter << endl;
      cout << "The Zombie Party keeps on Groaning!" << endl;
      
      //displays the size of the conga line and the line
      int size = conga.length();
      cout << "Size: " << size << " :: ";
      conga.PrintList();
      
      //chooses a random zombie color
      char zombie = randomC();

      //this function performs an action based on the random inputs
      action(rol1,zombie);

      //this if statement will check if the list is empty and end the party if it is empty
      end = conga.length();

      //check contains the head value
      char check = conga.retrieveFront();

      //this if statement checks if the list is empty and end the party if it is
      if((end == 1 && check != 'R' && check != 'Y' && check != 'G' && check != 'B' && check != 'M' && check != 'C')||(end == 0)||(check != 'R' && check != 'Y' && check != 'G' && check != 'B' && check != 'M' && check != 'C')){

	//this variable is used to end the loop when it is "end"
	endIt = "end";

	//this outputs the empty list in the correct format
	cout << "size: " << "0" << " :: " << endl;
        cout << "***********************************************\n\n";
	break;
      }
          
      //this variable is used to keep track of the length of the list 
      int amount2 = conga.length();      

      //the following 4 lines output the list in the correct format
      cout << "The conga line is now:" << endl;
      cout << "size: " << amount2 << " :: ";
      conga.PrintList();
      cout << "***********************************************\n\n\n";

      //this if statement will remove the front and back zombie every 5 rounds starting at 0
      if(roundRemoveCounter == 5){

	//this line resets the counter for the 5 rounds
	roundRemoveCounter = 0;

	//these 2 lines delete the front and last nodes
	conga.removeFromFront();
	conga.removeFromEnd();
      }
      //these two line update the round counter and the counter that keeps track of every 5 rounds to remove the front and back zombie
      roundCounter += 1;
      roundRemoveCounter += 1;
      
    }
    
    //This will ask the user if they want to continue the party
    if(endIt != "end"){
    cout << "\ndo you want to continue the party? (yes/no)" << endl;
    cin >> confirm;    
    //if(confirm != "yes" && confirm != "no"){
      while(confirm != "yes" && confirm != "no"){
	cout << "\ninvalide input" << endl; 
	cout << "\ndo you want to continue the party? (yes/no)" << endl;
	cin >> confirm;
      }
      //}

    }

  }//end of while loop

  
  //this prompts the user that the pary is over
  cout << "\nthe party is over\n\n";
  return 0;
  
}//end of main

//this function will output a random zombie as a char value;
char randomC(){
  
  //num stores a random number and color will store a colored zombie and output it
  int num =(rand() % 6 + 1);
  char color;

  //this series of if and else-if's will determine the zombie color based on the random number from "num" and store it in "color"
  if(num == 1){
    color = 'R';   

  }else if(num == 2){
    color = 'B';
    
  }else if(num == 3){
    color = 'G';
    
  }else if(num == 4){
    color = 'Y';

  }else if(num == 5){
    color = 'M';

  }else if(num == 6){
    color = 'C';
  }
  return color;
}
//performs engine action
void engine(char zombie){

  //adds a zombie to the front
  conga.addToFront(zombie);

  //displays zombie and action
  cout << zombie << " jumps into the front (Engine!)" << endl;
}

//performs caboose action
void caboose(char zombie){

  //adds a zombie to the end
  conga.addToEnd(zombie);

  //displays zombie and action
  cout << zombie << " jumps into the back (Caboose!)" << endl;
}

//performs jump in the line action
void jumpIn(char zombie){

  //these two find the length of the line then add a zombie to that index
  int index = conga.length();
  conga.addAtIndex(zombie,index);

  //displays zombie and action
  cout << zombie << " jumps into the line (Jump in the Line!)" << endl;
}

//performs everyone out action
void everyoneOut(char zombie){

  //removes all matches of zombie  
  conga.removeAllOf(zombie);

  //displays zombie and action
  cout << "all " << zombie << " are escorted out the party (Everyone Out!)" << endl;
}

//performs you're done action
void youreDone(char zombie){

  //removes the first match of zombie
  conga.removeTheFirst(zombie);

  //displays zombie and action
  cout << "The first " << zombie << " is escorted out the party (You're done!)" << endl;
}

//performs brain action
void brains(char zombie){

  //finds the index of the middle of the conga line
  int index = (conga.length()/2)+1;
  
  //the first adda a zombie to the front. the second adds a zombie to the end. the third adds a zombie in the middle
  conga.addToFront(zombie);
  conga.addToEnd(zombie);
  conga.addAtIndex(zombie,index);  
  cout << "three  " << zombie << " join the line (Brains!)" << endl;
}

//this performs the rainbow brains action
void rainbowBrains(char zombie){

  //these lines create char variables and each stores a different color
  char red,yellow,green,blue,magenta,cyan;
  red = 'R';
  yellow = 'Y';
  green = 'G';
  blue = 'B';
  magenta = 'M';
  cyan = 'C';

  //the first adds a random zombie to the frons and the rest add one of each color to the end
  conga.addToFront(zombie);
  conga.addToEnd(red);
  conga.addToEnd(yellow);
  conga.addToEnd(green);
  conga.addToEnd(blue);
  conga.addToEnd(magenta);
  conga.addToEnd(cyan);

  //displays zombie and action
  cout << zombie << " zombie brought a whole party itself (Rainbow Brains!)" << endl;

}

//this function randomly performs an action
void action(int roll,char zombie){

  //engine
  if(roll == 1){
    engine(zombie);
  }

  //caboose
  if(roll == 2){
    caboose(zombie);
  }

  //jump in the line
  if(roll == 3){
    jumpIn(zombie);
  }

  //eveyone out
  if(roll == 4){
    everyoneOut(zombie);
  }

  //your done
  if(roll == 5){
    youreDone(zombie);
  }

  //Brains
  if(roll == 6){
    brains(zombie);
  }

  //Rainbow Brains
  if(roll == 7){
    rainbowBrains(zombie);
  }
}













