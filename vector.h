#include <iostream>


template <class type>
class Vector {
    protected:
        unsigned int capacity = 50;
        unsigned int length = 0;
        type* arr;
    public:
        Vector() {
            arr = new type[capacity];
        };

        Vector(unsigned int capacity) {
            if (capacity > 50) {
                this->capacity = capacity + 50;
            }

            length = capacity;
            
            arr = new type[capacity];
        };

        void fill(type item) {
            for (int i = 0;i < length;i++) {
                arr[i] = item;
            }
        }

        void append(type item) {
            if (capacity == length) {
                capacity *= 2;
                type* new_arr = new type[capacity];
                for (int i = 0;i < length;i++) {
                    new_arr[i] = arr[i];
                }

                arr = new_arr;
            }

            arr[length] = item;
            length++;
        }

        void remove(unsigned int index) {
            if (index >= length) {
                std::cerr<<"index "<<index<<" is out of range"<<std::endl;
                exit(1);
            }

            for (int i = index;i < length - 1;i++) {
                arr[i] = arr[i + 1];
            }

            length--;
        }

        type& at(unsigned int index) {
             if (index >= length) {
                std::cerr<<"index "<<index<<" is out of range"<<std::endl;
                exit(1);
            }

            return arr[index];
        }

        template <class T>
        friend void print(Vector<T> vector);

        unsigned int size() {
            return length;
        }
};

template <class type>
void print(Vector<type> vector) {
    std::cout<<"[";
    if (vector.length == 0) {
        std::cout<<"]"<<std::endl;
    }
    for (int i = 0;i < vector.length - 1;i++) {
        std::cout<<vector.arr[i]<<",";
    }

    std::cout<<vector.arr[vector.length - 1]<<"]"<<std::endl;
}
