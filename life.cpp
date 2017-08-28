// Name:  Chris Giuffrida
// Class: Fundamentals of Computing Lab 8
// life.cpp

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "lifeboard.h"

using namespace std;

void displayMenu();
void addLiveCell(int, int, Lifeboard&);
void deleteLiveCell(int, int, Lifeboard&);
void iterateBoard(Lifeboard&);
int runCorrectMode(istream&);

int main(int argc, char *argv[])
{
  // Declare variables
  string filename;
  ifstream ifs;

  system("clear");
  // Use if statement to check to see if user entered file name in command line. 
  if(argc == 1) {
    runCorrectMode(cin);
    
    // Enter this if statement if user has provided a file as a second command line argument.
  } else if (argc == 2) {
      filename = argv[1];
      ifs.open(filename.c_str());
      if(!ifs) {
        cout << "Not a valid file name." << endl;
        return 1;
      }
      runCorrectMode(ifs);
    }
}

// Ouput the menu to be provided to user for input options.
void displayMenu()
{
  cout << "Interactive Mode Menu Options\n";
  cout << "a:  Enter 'a' followed by two coordinates for a new live cell.\n";
  cout << "r:  Enter 'b' followed the coordinates of a cell to be removed.\n";
  cout << "n:  Enter 'n' to advance the simulation to the next iteration.\n";
  cout << "q:  Enter 'q' to quit the program.\n";
  cout << "p:  Enter 'p' to play the game continously forever.\n";
  cout << "User input:  ";
}

// Add a live cell to the board given an x and y coordinate from the user.
void addLiveCell(int x, int y, Lifeboard& board)
{
  int row = y;
  int col = x;
 
  board.setABoardValue(row, col, 'X'); 
}

// Delete a live cell from the board given an x and y coordinate from the user.
void deleteLiveCell(int x, int y, Lifeboard& board)
{
  int row = y;
  int col = x;
  
  board.setABoardValue(row, col, ' ');
}

// Move the board forward one iteration of the game.
void iterateBoard(Lifeboard& board)
{
  Lifeboard tempBoard;
  int numNeighbors;
  
  // Set tempBoard to board
  tempBoard = board;

  // Modify tempBoard for iteration
  for(int row = 0; row < 40; row++) {
    for(int col = 0; col < 40; col++) {
      numNeighbors = board.countsNeighbors(row, col);
      if(board.getABoardValue(row, col) == 'X') {
        if((numNeighbors < 2) || (numNeighbors > 3)) {
          tempBoard.setABoardValue(row, col, ' ');
        }
      }else {
        if(numNeighbors == 3) {
          tempBoard.setABoardValue(row, col, 'X');
        }
      }
    }
   }
  
  // Change original board by setting it equal to tempBoard
  board = tempBoard; 
}

// Runs program in iteration mode or data file mode.
int runCorrectMode(istream& stream1)
{
  Lifeboard board;
  int x, y;
  char command;
  board.printBoard();
      // Continue to show menu and take user input until user quits or chooses to run non-stop.
      while((command != 'q')||(command != 'p')) {
        displayMenu();
        stream1 >> command;
        // Call the correct function by using a switch with the user inputted letter command.
        switch (command) {
          case 'a':
            // Input x and y, should be 2 remaining user-inputs from terminal.
            stream1 >> x >> y;
            cout << endl;
            addLiveCell(x, y, board);
            break;
          case 'r':
            // Input x and y, should be 2 remaining user-inputs from terminal.
            stream1 >> x >> y;
            cout << endl;
            deleteLiveCell(x, y, board);
            break;
          case 'n':
            iterateBoard(board);
            break;
          case 'q':
            // Terminate program by returning 1.
            return 1;
            break;
          case 'p':
            // Create a continuous loop for the game.
            while(0!=1) {
              iterateBoard(board);
              system("clear");
              board.printBoard();
              cout << "\nTo exit out of the program please press Ctrl-C." << endl;
              usleep(100000);
            }
            break;  
        }
        // Clear and reprint board after every user-input.
        system("clear");
        board.printBoard();
      }
}




