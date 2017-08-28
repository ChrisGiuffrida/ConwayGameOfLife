// Name: Chris Giuffrida
// Class: Fundamentals of Computing Lab 8
// lifeboard.cpp

#include <iostream>
#include "lifeboard.h"
using namespace std;


// Constructs a board by setting all cells to spaces (dead cells).
Lifeboard::Lifeboard() 
{
  for(int i=0; i < 40; i++) {
    for(int j=0; j < 40; j++)  {
      board[i][j] = ' ';
    }
  } 
}

// Deconstructor.
Lifeboard::~Lifeboard() { }

// Returns the value for a given cell of the board.
char Lifeboard::getABoardValue(int row, int col)
{
  return board[row][col];
}

// Sets a given cell of the board to a given char value if the cell is inbounds.
void Lifeboard::setABoardValue(int row, int col, char value)
{
  if(checkInBound(row, col) == true) {
    board[row][col] = value;
  }
}

// Prints the entire board out with a full border.
void Lifeboard::printBoard()
{
  //Print top left corner
  cout << "\u2554";
  // Print top border
  for(int i=1; i <=  40; i++) {
    cout << "\u2550";
  }
  //Print top right corner
  cout << "\u2557" << endl;
  
  // Print side borders with the board itself (alive and dead cells).
  for(int row = 2; row <= 41; row ++) {
    for(int col = 1; col <= 42; col++) {
      if((col==1)||(col==42)) {
        cout << "\u2551";
      }else {
        cout << board[row-2][col-2];
      }
    }
    cout << endl;
  }
  //Print bottom left corner
  cout << "\u255A";
  // Print bottom border
  for(int i=1; i <= 40; i++) {
    cout << "\u2550";
  }
  //Print bottom right corner
  cout << "\u255d" << endl;
}

// Checks to see if the give x and y coordinates are in bounds.
int Lifeboard::checkInBound(int x, int y)
{
  if ((x > -1) && (x < 40) && (y > -1) && (y < 40)) {
    return true;
  }else {
    return false;
  }
}

// Counts the number of neighbors a given cell has.
int Lifeboard::countsNeighbors(int row, int col)
{
  int count = 0;  

  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j<= 1; j++) {
      if(checkInBound(row + i, col + j) == true) {
        if(board[row+i][col+j] == 'X') {
          count++;
        }
      }
    }
  }
  // Subtract one from the count if the given cell was alive itself.
  if(board[row][col] == 'X') {
    count--;
  }  
   return count;
}

