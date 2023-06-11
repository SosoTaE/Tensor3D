#include <iostream>
#include "tensor3D.h"
using namespace std;


int main() {
    Tensor3D<int> tensor(1,2,3);
    tensor.randomize(-100,100);
    print(tensor);
}