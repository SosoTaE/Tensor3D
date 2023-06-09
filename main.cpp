#include <iostream>
#include "tensor3D.h"
using namespace std;


int main() {
    Tensor3D<int> Tensor(1,2,34);
    print(Tensor);
}