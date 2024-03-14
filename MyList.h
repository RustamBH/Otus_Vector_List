#pragma once


template <typename T>
class MyList
{
public:
    MyList() : m_size{ 0 }, m_head{ nullptr }, m_last{ nullptr }{}
    ~MyList() { clear(); }
    void clear();
    void push_back(const T& value);
    void push_front(const T& value);
    T getSize() const { return m_size; }
    void insert(size_t index, const T& value);    
    void erase(T value);
    T& operator[](const T index);
    void print() const;
    bool is_empty() { return m_head == nullptr; };
    void pop_front();
    void pop_back();

private:
    template <typename T>
    class Node {
    public:
        Node* prev;
        Node* next;
        T data;
        Node(T data_ = T(), Node* prev_ = nullptr, Node* next_ = nullptr) : data{ data_ }, prev{ prev_ }, next{ next_ }{}
    };

    size_t m_size;
    Node<T>* m_head;
    Node<T>* m_last;
};

template<typename T>
void MyList<T>::clear()
{
    auto current = this->m_head;
    while (current != nullptr)
    {
        auto temp = current->next;
        delete current;
        current = temp;        
    }
    m_size = 0;
    m_last = nullptr;
}

template<typename T>
void MyList<T>::push_back(const T& value)
{
    auto new_node = new Node<T>{ value }; // создание нового узла
    if (is_empty()) {
        this->m_head = new_node;
        this->m_last = new_node;        
    }
    else {
        new_node->prev = m_last;
        m_last->next = new_node;
        m_last = new_node;
    }
    m_size++; 
}

template<typename T>
void MyList<T>::push_front(const T& value)
{
    m_head = new Node<T>{ value, nullptr, m_head };
    m_size++;
}

template<typename T>
void MyList<T>::insert(size_t index, const T& value)
{
    if (is_empty()) return;
    if (m_head == nullptr || index < 0 || index > m_size) {
        std::cout << "Insert is impossible. Out of range." << std::endl;
        return;
    }

    if (index == 0) {
        push_front(value);
    }
    else if (index == m_size) {
        push_back(value);
    }
    else {
        auto current = this->m_head;
        size_t n{ 0 };
        while (n != index)
        {
            current = current->next;
            ++n;
        }

        auto newNode = new Node<T>{ value, current->prev, current };
        current->prev->next = newNode;
        current->prev = newNode;
        m_size++;
    }
}

template<typename T>
void MyList<T>::erase(T value)
{
    if (is_empty()) return;
    if (m_head->data == value) {
        pop_front();
        return;
    }
    else if (m_last->data == value) {
        pop_back();
        return;
    }

    auto current = m_head;
    auto next_node = m_head->next;

    while (next_node && next_node->data != value) {
        next_node = next_node->next;
        current = current->next;
    }

    if (!next_node) {        
        std::cout << "This element \"" << value << "\" does not exist" << std::endl;
        return;
    }
    current->next = next_node->next;
    next_node->next->prev = current;
    delete next_node;
    m_size--;
}

template<typename T>
T& MyList<T>::operator[](const T index)
{
    // TODO: insert return statement here    
    if (m_head == nullptr || index < 0 || index >= m_size) {        
        std::cout << "Take value is impossible. Index " << index << " out of range." << std::endl;
    }
    else {
        int counter = 0;
        auto current = this->m_head;
        while (current != nullptr)
        {
            if (counter == index) {
                return current->data;
            }
            current = current->next;
            counter++;
        }
    }
}

template<typename T>
void MyList<T>::print() const
{    
    if (this->m_head == nullptr) return;
    auto current = this->m_head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
void MyList<T>::pop_front()
{
    if (is_empty()) return;
    auto temp = this->m_head;
    this->m_head = m_head->next;
    delete temp;
    m_size--;
}

template<typename T>
void MyList<T>::pop_back()
{
    if (is_empty()) return;
    if (this->m_head == this->m_last) {
        pop_front();
        return;
    }
    Node<T>* current = this->m_head;
    while (current->next != this->m_last)
        current = current->next;
    current->next = nullptr;
    delete m_last;
    m_last = current;
    m_size--;
}
