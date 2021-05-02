
const int MAX_SIZE = 20;
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class stack{
    public:
    stack();
    void push(T val);
    void pop();
    T top();
    bool empty();

    private:
    T data[MAX_SIZE];
    unsigned size;
};

template<typename T>
stack<T>::stack()
{
    size = 0;
}

template<typename T>
void stack<T>::push(T val)
{
    if (size == 0)
    {
        data[0] = val;
        ++size;
    }
    else if (size == 20)
    {
        throw overflow_error("Called push on full stack.");
    }

    else
    {
        for (unsigned i = size; i > 0; --i)
        {
            data[i] = data[i-1];
        }
        data[0] = val;
        ++size;
    }

}

template<typename T>
void stack<T>::pop()
{
    if (size == 0)
    {
        throw out_of_range("Called pop on empty stack.");
    }

    else
    {
        for (unsigned i = 0; i < size; ++i)
        {
            data[i] = data[i+1];
        }
        --size;
    }
}

template<typename T>
T stack<T>::top()
{
    if (size == 0)
    {
        throw underflow_error("Called top on empty stack.");
    }

    else
    {
        return data[0];
    }
}

template<typename T>
bool stack<T>::empty()
{
    if (size == 0)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

