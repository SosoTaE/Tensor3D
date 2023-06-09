#include <iostream>
#include "vector.h"
#include <cstdlib>


template <class type>
class Matrix {
    protected:
        unsigned int rows;
        unsigned int cols;
        Vector<Vector<type>> matrix;
    public:
        Matrix(unsigned int rows,unsigned int cols) {
            if (rows == 0 || cols == 0) {
                std::cerr<<"A dimension should not be equal to 0"<<std::endl;
                exit(1);
            }
            this->rows = rows;
            this->cols = cols;
            
            for (int i = 0;i < rows;i++) {
                matrix.append(Vector<type>(cols));
            }
        }

        Matrix() {

        }

        void fill(type item) {
            for (int i = 0;i < rows;i++) {
                matrix.at(i).fill(item);
            }
        }

        Matrix<type>& randomize(int a,int b) {
            if (b < a) {
                b = a;
            }
            else if (a == b) {
                b++;
            }

            srand(time(0));
            
            for (int i = 0; i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    int random = a + (rand() % (b - a));
                    matrix.at(i).at(j) = random;
                }
            }

            return *this;
        }

        type& at(unsigned int row_index,unsigned int col_index) {
            if (row_index >= this->rows || col_index >= this->cols) {
                std::cerr<<"index is out of range"<<std::endl;
                exit(1);
            }   

            return matrix.at(row_index).at(col_index);
        }

        Matrix<type> operator+(Matrix<type> matrix_2) {
             if (rows != matrix_2.rows || cols != matrix_2.cols) {
                std::cerr<<"Dimesions are not equal to each other"<<std::endl;
                exit(1);
            }
            Matrix<type> new_matrix(rows,cols);
            for (int i = 0;i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    new_matrix.at(i,j) = matrix.at(i).at(j) + matrix_2.at(i,j);
                }
            }

            return new_matrix;
        }

        Matrix<type> operator-(Matrix<type> matrix_2) {
            if (rows != matrix_2.rows || cols != matrix_2.cols) {
                std::cerr<<"Dimesions are not equal to each other"<<std::endl;
                exit(1);
            }
            Matrix<type> new_matrix(rows,cols);
            new_matrix.fill(0);
            for (int i = 0;i < rows;i++) {
                for (int j = 0;j < cols;j++) {
                    new_matrix.at(i,j) = matrix.at(i).at(j) - matrix_2.at(i,j);
                }
            }

            return new_matrix;
        }

        template<class T>
        friend void print(Matrix<T> matrix, char* end);
};


template<class T>
void print(Matrix<T> matrix, char* end) {
    std::cout<<"[";
    for (int i = 0;i < matrix.rows - 1;i++) {
        std::cout<<"[";
        for (int j = 0;j < matrix.cols - 1;j++) {
            std::cout<<matrix.at(i,j)<<",";
        }

        std::cout<<matrix.at(i,matrix.cols - 1)<<"],"<<std::endl;
    }

    std::cout<<"[";
    for (int j = 0;j < matrix.cols - 1;j++) {
        std::cout<<matrix.at(matrix.rows - 1,j)<<",";
    }

    std::cout<<matrix.at(matrix.rows - 1,matrix.cols - 1)<<"]]"<<end;
}
