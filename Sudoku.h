#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku
{
public:

    int a[10][10],b[10][10],ans,TIME;
	Sudoku();
    void giveQuestion();
    void readIn();
    void printBoard();
    void solve();
    void transform();
    void change();
    void flip(int n);
    void rotate(int n);
    void changeCol(int col_a, int col_b);
    void changeRow(int row_a, int row_b);
    void changeNum(int digit1,int digit2);
    int check(int num,int i,int j);
};
