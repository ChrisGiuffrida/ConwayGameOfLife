// Name: Chris Giuffrida
// Class:  Funamentals of Computing Lab 8
// lifeboard.h
// Interface for Lifeboard class

class Lifeboard {
  public:
    Lifeboard();
    ~Lifeboard();
    char getABoardValue(int, int); 
    void setABoardValue(int, int, char);
    void printBoard();
    int countsNeighbors(int, int);
    int checkInBound(int, int);
  private:
    char board[40][40];
};    
  
