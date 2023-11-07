#include "vectorint.hpp"

VectorInt::VectorInt(int size) : m_size(size)
{
    mp_Data = new int[size];
}

VectorInt::~VectorInt() {
    if(mp_Data != nullptr) {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}
void VectorInt::push_back(int val) {
    m_size = m_size+1;                      //change the size and add one element
    int *tmp = new int[m_size];             //initialize temp Array with the new size

    int i = 0;
     for (int i = 0; i < m_size; i++)
     {
        tmp[i] = mp_Data[i];
     }

    tmp[m_size-1] = val;
    delete []  mp_Data;                     //release storage --> empty Vector
    mp_Data = tmp;                          //write the new size in the empty Vector
}

auto VectorInt::size() -> int{
    return m_size;
}

auto VectorInt::at(int index) -> int{
        return mp_Data[index];
}