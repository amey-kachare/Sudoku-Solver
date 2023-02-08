#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
HANDLE console_color;
#define N 9
using namespace std;
int grid[N][N];

bool isPresentInCol(int col, int num)
{
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInRow(int row, int num)
{
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row + boxStartRow][col + boxStartCol] == num)
            return true;
   return false;
}

void sudokuGrid()
{
   console_color = GetStdHandle(STD_OUTPUT_HANDLE);
for(int i=0;i<N;i++){
   SetConsoleTextAttribute(
                console_color, 12);
   cout<<"===";
   }
   cout<< endl << "SOLUTION IS:-" << endl;
   SetConsoleTextAttribute(
                console_color, 15);
   for (int row = 0; row < N; row++)
   {
      for (int col = 0; col < N; col++)
      {
         if (col == 3 || col == 6)
         {
            SetConsoleTextAttribute(
                console_color, 12);
            cout << " | ";
            SetConsoleTextAttribute(
                console_color, 15);
         }
         cout << grid[row][col] << " ";
      }
      if (row == 2 || row == 5)
      {
         cout << endl;
         for (int i = 0; i < N; i++)
         {
            SetConsoleTextAttribute(
                console_color, 12);
            cout << "---";
            SetConsoleTextAttribute(
                console_color, 15);
         }
      }
      cout << endl;
   }
   SetConsoleTextAttribute(
       console_color, 15);
}
bool findEmptyPlace(int &row, int &col)
{
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0)
            return true;
   return false;
}
bool isValidPlace(int row, int col, int num)
{

   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}

bool solveSudoku()
{
   int row, col;
   if (!findEmptyPlace(row, col))
      return true;
   for (int num = 1; num <= 9; num++)
   {
      if (isValidPlace(row, col, num))
      {
         grid[row][col] = num;
         if (solveSudoku())
            return true;
         grid[row][col] = 0;
      }
   }
   return false;
}

int main()
{
   cout << "Enter your Sudoku with empty spaces as 0" << endl;
   for (int row = 0; row < N; row++)
   {
      for (int col = 0; col < N; col++)
         cin >> grid[row][col];
   }
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}