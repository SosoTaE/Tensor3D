#include <iostream>
#include "matrix.h"


template <class type>
class Tensor3D: private Vector<type>, private Matrix<type> {
    private:
        Vector<Matrix<type>> tensor;
        
    public:
        Tensor3D(unsigned int length, unsigned int rows, unsigned int cols) {
            if (length == 0 || rows == 0 || cols == 0) {
                std::cerr<<"A dimension should not be equal to 0"<<std::endl;
                exit(1);
            }
            this -> length = length;
            this -> rows = rows;
            this -> cols = cols;

            for (int i = 0;i < length;i++) {
                Matrix<type> each(rows,cols);
                tensor.append(each);
            }
        }

        template <class T>
        friend void print(Tensor3D<T>& tensor3d);

        void randomize(int a,int b) {
            for (int i = 0;i < this -> length;i++) {
                tensor.at(i).randomize(a,b);
            }
        }

};

template <class T>
void print(Tensor3D<T>& tensor3d) {
    std::cout<<"[";
    for (int i = 0;i < tensor3d.length - 1;i++) {
        print(tensor3d.tensor.at(i),",\n");
    }

    print(tensor3d.tensor.at(tensor3d.length - 1),"");


    std::cout<<"]"<<std::endl;
}
