#pragma once

#include <sstream>
template <typename T>
class MyVector
{
public:
    MyVector() : m_size{ 0 }, m_capacity{ 1 }, m_region{ new T[1] }{}    
    MyVector(const std::initializer_list<T> list){
        size_t i = 0;
        m_region = new T[list.size()];
        for(auto it = list.begin(); it != list.end(); ++it, ++i){           
            m_region[i] = *it;
            ++m_size;
        }
    }
    ~MyVector() { delete[] m_region; }

    void push_back(T value);
    size_t getSize() const { return m_size; }
    size_t getCapacity() const { return m_capacity; }
    void insert(size_t index, T value);
    void erase(size_t index);    
    T& operator[](size_t index);
    std::string print() const;
private:    
    size_t m_size;
    size_t m_capacity;
    T* m_region;
};


template <typename T>
void MyVector<T>::push_back(T value) {
    if (m_size < m_capacity) {
        m_region[m_size] = value;
        ++m_size;
    }
    else {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            temp[i] = m_region[i];
        }
        temp[m_size] = value;
        delete[] m_region;
        m_region = temp;
        ++m_size;
    }
}


template<typename T>
void MyVector<T>::insert(size_t index, T value)
{
    if (index < 0 || index > m_size) {        
        std::cout << "Insert is impossible. Index " << index << " out of range." << std::endl;
        return;
    }

    if (m_size != m_capacity) {
        for (size_t i = m_size; i > index; --i) {
            m_region[i] = m_region[i - 1];
        }
        m_region[index] = value;
        ++m_size;
    }
    else {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            temp[i] = m_region[i];
        }
        delete[] m_region;
        m_region = temp;
        insert(index, value);
    }    
}

template <typename T>
void MyVector<T>::erase(size_t index) 
{
    if (index < 0 || index >= m_size) {
        std::cout << "Erase is impossible. Index " << index << " out of range." << std::endl;
        return;
    }
    if (index == m_size - 1)
        m_region[index] = 0;
    for (size_t i = index; i < m_size - 1; ++i)
        m_region[i] = m_region[i + 1];
    --m_size;   
}

template<typename T>
inline T& MyVector<T>::operator[](size_t index)
{
    // TODO: insert return statement here
    if (index < 0 || index >= m_size) {        
        std::cout << "Take value is impossible. Index " << index << " out of range." << std::endl;       
    } else 
        return m_region[index];    
}

template<typename T>
std::string MyVector<T>::print() const
{
    std::stringstream buffer{};
    if (m_size == 0) return buffer.str();// пустая строка 
    for (size_t i = 0; i < m_size; ++i)
        buffer << m_region[i] << " ";
    buffer << std::endl;    
}
