/*********************************************************************
** Program Filename: word frequency checker
** Author: L
** Date: March 2, 2019
** Description: User enters a sentence and a word and program counts
** how many times that word appears in the sentence
** Input: User enters a c-style string for the sentence, an integer
** for the number of words they want to check, and a c-style string
** the user wants to check
** Output: the number of times the words the user entered occured
** in the sentence.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;
/*********************************************************************
** Function: error_handle
** Description: checks if the input is between 0-9
** Parameters: int min - lower bound of ascii int max - upper bound of ascii
** Pre-Conditions: N/A
** Post-Conditions: user input will be a positive integer
*********************************************************************/
int error_handle(int min, int max){
    int good_input = 0;
    string user_input;
    while (good_input == 0){
        int counter = 0;
        getline(cin, user_input);
        if(user_input.size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
        //checks if each character inputed is between 0-9
        for (int i = 0; i < user_input.size(); i++){
            if (int(user_input.at(i)) <min|| int(user_input.at(i)) > max){
                counter++;
            }
        }
            //checks edge case of first number being 0
        if (counter > 0 || user_input.at(0) == '0'){
            cout << "Enter valid input" << endl;
        }
        else
        {
            good_input = 1;
        }
        }
    }
    return atoi(user_input.c_str());
}
/*********************************************************************
** Function: string input
** Description: reads in 300 chars and stores it in a c-style string
** then converts all chars into lower case
** Parameters: the address to where a dynamic array begins
** Pre-Conditions: a pointer to an array on the heap has been created
** Post-Conditions: user inputed sentence will be in all lower case
*********************************************************************/
void string_input(char *sentence){
  cout << "Enter a sentence/paragraph" << endl;
  cin.getline(sentence, 300);
  int length = strlen(sentence);
  for(int i =0; i<length; i++){
    //if a letter is uppercase, tolower makes it lowercase
    //this enables non-case-sensitive checking
    sentence[i] = tolower(sentence[i]);
  }
}

/*********************************************************************
** Function: n words
** Description: asks user to enter the number of words they want to check
** and store it
** Parameters: N/a
** Pre-Conditions: error_handle() must be declared
** Post-Conditions: user input will be a positive integer number
*********************************************************************/
int n_words(){
  int n;
  cout << "Enter how many words you want to check" << endl;
  n = error_handle(48, 57);
  return n;
}
/*********************************************************************
** Function: frequency checker
** Description: using strstr to see if the user inputed word appears
** in the sentence. If it does, replace the word with '-' increase
**frequency counter by one and keep looking until all words are found
** Parameters: pointer to an array on the heap that stores the sentence
** a pointer to an array that stores a pointer to a c-style string -
** stores the words the user wants to search for, rows - # words
** Pre-Conditions: all pointers must be initialized and c-style strings
** must be stored in them
** Post-Conditions: All occurances of the word will replaced with '-'
** and the temporary memory on the heap will be deallocated
*********************************************************************/
void frequency_checker(char *sentence, char **array, int rows){
  int len_sentence = strlen(sentence);
  for(int i=0; i<rows; i++){
    int frequency=0;
    char *temp = strstr(sentence, array[i]);
    int length = strlen(array[i]);
    while(temp!=NULL){
      int len_temp = strlen(temp);
      //handles when the searched word is at the begining of the sentence
      //because the char behind the word does not exist
      if(len_temp == len_sentence){
        if((int(sentence[length]) < 97 || int(sentence[length]) > 122||sentence[length+1]=='\0' )&& sentence[length+1] != '-' ){
          frequency++;
          cout << "++1" << endl;
        }
    }else{
      //checks a char behind and in front of the word to make sure it is one word
      //handles if the searched word exists within another word e.g. is -> th(is)
      if(((int(*(temp-1))<97 || int(*(temp-1)) > 122) && (int(*(temp+length)) > 122 || int(*(temp+length)) <97)) && (int(*(temp+length))
      != 45 && int(*(temp-1)) != 45)){
        frequency++;
      //  cout << int(sentence[*temp-1]);
//cout << "This is temp-1"<< *(temp-2) << endl;
//cout << "Tbis is temp[-1]" << temp[-2]<<endl;
        cout << "+1" << endl;

      }
    }
//makes sure the strstr doesnt find the same word again
      for(int j=0;j<length;j++){
        temp[j] = '-';;
    }
    //checks for the next word if it exists
    temp = strstr(temp, array[i]);

}
//cout<< "this is sentence"<< sentence;
//cout<< "this is sentence"<< sentence;

delete [] temp;
  cout << array[i] << " appears " << frequency<< " # of times" << endl;
    }

  }

  /*********************************************************************
  ** Function: allocateArr
  ** Description: allocates memory for a pointer to an array that contains
  ** pointers to a c-style string on the heap
  ** Parameters: rows - number of words to check for
  ** Pre-Conditions: N/A
  ** Post-Conditions: **arr will point to an array and the elements
  ** point to a c-style string
  *********************************************************************/
char ** allocateArr(int rows){
    char **arr = new char *[rows];
    for(int i = 0; i<rows; i++){
      cout << "Enter word" << endl;
      //temporary c-style to string, used to copy later
      char *s = new char[256];
      cin.getline(s, 256);
      int length = strlen(s);
      //pointer to c-style string, +1 is used to hold null char
      arr[i] = new char [length+1];
      strcpy(arr[i],s);
      delete [] s;
    }
    return arr;
}
/*********************************************************************
** Function: freeArr
** Description: deletes each element in the array that points to
** c-style strings
** Parameters: address to the double pointer and # of words to check
** Pre-Conditions: the double pointer must be initialized
** Post-Conditions: elements in the double array and the array itself
** will be deallocated
*********************************************************************/
void freeArr(char **array, int rows){
    for(int i =0; i<rows; i++){
        delete [] array[i] ;
    }
    delete [] array;
}
int main(){
  char *sentence = new char[300];
  string_input(sentence);
  int n=n_words();
  char **array = allocateArr(n);
 frequency_checker(sentence, array, n);
 delete [] sentence;
 freeArr(array, n);
  return 0;
}
