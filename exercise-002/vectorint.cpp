#include "vectorint.hpp"

VectorInt::VectorInt (int size) {
   mp_Data = new int[size];
}

VectorInt::VectorInt() {
    if(mp_Data l = nullptr) {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}