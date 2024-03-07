#pragma once


template <typename T>
class MyVector
{
public:
    MyVector() : m_size{ 0 }, m_capacity{ 1 }, m_region{ new T[1] }{}
    MyVector(T value) : m_value{ value } {}
    ~MyVector() { delete[] m_region; }

    void push_back(T value);
    T getSize() const { return m_size; }
    T getCapacity() const { return m_capacity; }
    void insert(size_t index, T value);
    void erase(size_t index);    
    T& operator[](T index);

    void print() const {
        for (size_t i = 0; i < m_size; ++i)
            std::cout << m_region[i] << " ";
        std::cout << std::endl;
    }

private:
    T m_value;
    size_t m_size;
    size_t m_capacity;
    T* m_region;
    size_t index;
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
        std::cout << "Erase is impossible. Index " << index << " out of range." << std::endl;
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
void MyVector<T>::erase(size_t index) {
    if (index < 0 || index > m_size) {
        std::cout << "Erase is impossible. Index " << index << " out of range." << std::endl;
        return;
    }   
    for (size_t i = index; i < m_size; ++i)
        m_region[i] = m_region[i + 1];
    --m_size;   
}

template<typename T>
inline T& MyVector<T>::operator[](T index)
{
    // TODO: insert return statement here
    if (index < 0 || index > m_size) {        
        std::cout << "Erase is impossible. Index " << index << " out of range." << std::endl;       
    } else 
        return m_region[index];    
}
