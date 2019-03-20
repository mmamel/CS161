/*********************************************************************
** Program Filename: Fractal Recursion
** Author: L
** Date: March 2, 2019
** Description: User enters in a power of 2 and a shifting value
** and program outputs a fractal based on inpuits
** Input:  i: a power of 2 that represents the number of * for the longest
** line in the middle. j: how many spaces the fractal is shifted to
** the right
** Output: A fractal composed of * with i number of * in the middle
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

/*********************************************************************
** Function: pattern
** Description: Prints out * and spaces to create a fractal pattern
** Parameters: int i - a power of 2 and int j - any positive int
** Pre-Conditions: i is a power of 2 and j is a positive int
** Post-Conditions: N/A
*********************************************************************/
void pattern (int i, int j){
  if(i!=1){
    pattern((i/2), j);
  }
  cout<<endl;
  for(int z = 0; z<j; z++){
    cout<< "  ";
  }
  for (int a =0; a < i; a++){
    cout << "* ";
  }
  for(int z = 0; z<j; z++){
    cout<< "  ";
  }
  if(i!=1){
  pattern((i/2),j+(i/2));
}

}



int main(int argc, char const *argv[]) {
  cout << "Enter a power of 2 for the largest length of *" << endl;
  int i = 0;
  cin >> i;
  cout << "Enter a positive integer value to shift pattern" << endl;
  int j = 0;
  cin >> j;
  pattern(i, j);

  return 0;
}
