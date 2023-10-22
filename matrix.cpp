#include <iostream>
#include <fstream>
#include <iomanip> //Header file to aid in the formating of the output

using namespace std;

static const int Max_Size = 100; //Sets the maximum size of the square matrix

void Read_From_File(int matrix[Max_Size][Max_Size], int& size, const char* file_name){
  ifstream file(file_name);
  if(!file.is_open()){ //Checks if the file is not open
      cerr << "Error: Cannot Open The File." << endl;
      exit(1);
  }
  file >> size; // reads the size of the square matrix from the matrix.txt and stores it in the size variable

  for (int i = 0; i < size; i++){ // the rows of the matrix
    for(int j = 0; j < size; j++){ // the column of the matrix
      file >> matrix[i][j];
    }
  }

  file.close();
}

//Function to print the matrix

void print_Matrix(const int matrix[Max_Size][Max_Size], int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      cout << setw(4) << matrix[i][j]; //setw is used to set the width and align to the right for output formatting, I experimented with the amount of characters it should space by and 4 was the perfect width setting
    }
    cout << endl; //Prints a newline after each row
  }
}

//Function for adding two matrices and putting the result in a third matrix
void ADD_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int matrix_result[Max_Size][Max_Size], int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
       matrix_result[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
  }
}

//Function for multiply two matrices and storing the result in a third matrix
void MULTIPLY_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int matrix_result[Max_Size][Max_Size], int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      matrix_result[i][j] = 0;
      for(int x = 0; x < size; x++){
        matrix_result[i][j] += matrix_1[i][x] * matrix_2[x][j];
      }
    }
  }
}

//Function for subtractinf one matrix from another and store the result in a third matix
void SUBTRACT_matrix(const int matrix_1[Max_Size][Max_Size], const int matrix_2[Max_Size][Max_Size], int matrix_result[Max_Size][Max_Size], int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      matrix_result[i][j] = matrix_1[i][j] - matrix_2[i][j];
    }
  }
}

int main(){
  int size;
  int matrix_A[Max_Size][Max_Size];
  int matrix_B[Max_Size][Max_Size];
  int matrix_result[Max_Size][Max_Size];

  Read_From_File(matrix_A, size, "matrix_input.txt");
  Read_From_File(matrix_B, size, "matrix_input.txt");

  cout << "Victor Maduka" << '\n';
  cout << "Lab #6: Matrix Manipulation.";

  cout << "Matrix A:" << '\n';
  print_Matrix(matrix_A, size);

  cout << "Matrix B:" << '\n';
  print_Matrix(matrix_B, size);

//Output for addition matrix
  ADD_matrix(matrix_A, matrix_B, matrix_result, size);
  cout << "Matrix Sum (A + B):" << '\n';
  print_Matrix(matrix_result, size);

//Output for multiplication matrix
  MULTIPLY_matrix(matrix_A, matrix_B, matrix_result, size);
  cout << "Matrix Product (A * B):" << '\n';
  print_Matrix(matrix_result, size);

//Output for Subtracting matrix
  SUBTRACT_matrix(matrix_A, matrix_B, matrix_result, size);
  cout << "Matrix Difference (A - B):" << '\n';
  print_Matrix(matrix_result, size);

  return(0);
}
