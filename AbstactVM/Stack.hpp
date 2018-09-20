#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
#include <deque>

template<class T> class Stack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;
    Stack();
    Stack(Stack const &obj);
    ~Stack();
    Stack & operator=(Stack const & value);

    Stack::iterator begin();
    Stack::iterator end();
};

template<class T> Stack<T>::Stack() {

}

template<class T> Stack<T>::Stack(Stack<T> const &obj) {
    *this = obj;
}

template<class T> Stack<T>::~Stack() {

}

template<class T> Stack<T> & Stack<T>::operator=(Stack<T> const &value) {
    this->std::stack<T>::operator=(value);
    return *this;
}

template<class T> typename Stack<T>::iterator Stack<T>::begin() {
    return this->c.begin();
}

template<class T> typename Stack<T>::iterator Stack<T>::end() {
    return this->c.end();
}

#endif