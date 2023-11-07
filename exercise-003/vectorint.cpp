#include "vectorint.hpp"
#include<iostream>

VectorInt::VectorInt(int size) 
{
    m_size  = size;
    m_capacity = m_size;
    mp_Data = new int[size];
}

VectorInt::~VectorInt() 
{
    if(mp_Data != nullptr) 
    {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}

void VectorInt::resize(int size)
{
    m_size = size;
    int* tmp = new int[size];
    delete[]mp_Data;
    mp_Data = tmp;
}

void VectorInt::push_back(int value)
{
    int* tmp = new int[m_size + 1];
    for(int i = 0; i < m_size; i++)
    {
        tmp[i] = mp_Data[i];
    }
    tmp[m_size] = value;
    delete[] mp_Data;
    mp_Data = tmp;
    m_size = m_size + 1;
}

void VectorInt::print_vector()
{
    for(int i = 0; i < m_size; i++)
    {
        std::cout << mp_Data[i] << " ";
    }
    std::cout << std::endl;
}

void VectorInt::at(int place)
{
    std::cout << mp_Data[place] << std::endl;
}

void VectorInt::size()
{
    std::cout << m_size << std::endl;
}

void VectorInt::clear()
{
    delete [] mp_Data;
    mp_Data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

void VectorInt::push_back_better(int value)
{
    if(m_size == m_capacity)
    {
        m_capacity *= 2;
        int* tmp = new int[m_capacity];
        for(int i = 0; i < m_size; i++)
        {
            tmp[i] = mp_Data[i];
        }
        delete[] mp_Data;
        mp_Data = tmp;
    }
    mp_Data[m_size] = value;
    m_size++;
}