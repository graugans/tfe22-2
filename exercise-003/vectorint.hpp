#ifndef MY_INTEGER_VECTOR_HPP
#define MY_INTEGER_VECTOR_HPP

class VectorInt {
public:
    VectorInt(int size);
    ~VectorInt();
    void push_back (int val);
    auto size() -> int;
    auto at(int index) -> int;
private:
    int m_size;
    int* mp_Data;
};

#endif