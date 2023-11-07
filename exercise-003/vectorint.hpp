#ifndef MY_INTEGER_VECTOR_HPP
#define MY_INTEGER_VECTOR_HPP

class VectorInt {
public:
    VectorInt(int size);
    ~VectorInt();

    int& at(int place);
    void resize(int size);
    int size();
    void clear();
    void push_back(int value);
    void push_back_better(int value);
    void print_vector();
private:
    int m_size;
    int* mp_Data;
    int m_capacity;
};

#endif