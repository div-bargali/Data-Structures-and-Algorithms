#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

using std::cout;
using std::endl;
using std::for_each;
using std::initializer_list;
using std::make_move_iterator;
using std::move;
using std::size_t;
using std::swap;

template <typename T>
class stack {
    struct node {
        T data;
        node* next;
        node(const T& value, node* ne = nullptr) : data{value}, next{ne} {}
        node(T&& value, node* ne = nullptr) : data{move(value)}, next{ne} {}
    };

   public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    // Create an empty stack
    stack() {}
    // Copy a stack
    stack(const stack&);
    // Move a stack
    stack(stack&&);
    // Create a stack from a initializer list
    stack(initializer_list<T>);
    // Destroy the stack
    ~stack();

    // Coppy assign the stack
    stack& operator=(const stack&);
    // Move assign the stack
    stack& operator=(stack&&);

    // Push an element in the stack
    void push(const T&);
    void push(T&&);

    // Retrieve the top element of the stack
    reference top();
    const_reference top() const;

    // Remove the top element of the stack
    void pop();

    // Retrieve the size of the stack
    size_t size() const { return size_; }
    // Queries if the stack is empty
    bool empty() const { return !top_; }

    // Remove all the elements of the stack
    void clear();

   private:
    node* top_ = nullptr;
    size_t size_ = 0;

    void _copy_from(const stack&);
};

template <typename T>
stack<T>::stack(const stack& o) {
    _copy_from(o);
}

template <typename T>
stack<T>::stack(stack&& o) {
    swap(this->top_, o.top_);
}

template <typename T>
stack<T>::stack(initializer_list<T> il) {
    for (const T& item : il) {
        push(item);
    }
}

template <typename T>
stack<T>::~stack() {
    clear();
}

template <typename T>
auto stack<T>::operator=(const stack& o) -> stack& {
    clear();
    _copy_from(o);
    return *this;
}

template <typename T>
auto stack<T>::operator=(stack&& o) -> stack& {
    swap(top_, o.top_);
    return *this;
}

template <typename T>
void stack<T>::push(const T& value) {
    top_ = new node(value, top_);
    ++size_;
}

template <typename T>
void stack<T>::push(T&& value) {
    top_ = new node(move(value), top_);
    ++size_;
}

template <typename T>
auto stack<T>::top() -> reference {
    return top_->data;
}

template <typename T>
auto stack<T>::top() const -> const_reference {
    return top_->data;
}

template <typename T>
void stack<T>::pop() {
    if (top_) {
        node* aux = top_;
        top_ = top_->next;
        delete aux;
        --size_;
    }
}

template <typename T>
void stack<T>::clear() {
    while (top_) {
        pop();
    }
}
template <typename T>
void stack<T>::_copy_from(const stack& o) {
    node** aux = &top_;
    for (node* n = o.top_; n; n = n->next) {
        *aux = new node(n->data);
        aux = &(*aux)->next;
    }
}

/* Makes a copy of the stack and prints each element while popping them. */
template <typename T>
void print_stack(stack<T> s) {
    while (!s.empty()) {
        cout << s.top() << ", ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;  // declaring an empty stack
    s.push(10);    // pushing elements
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    cout << "s.size() : " << s.size() << endl;
    cout << "s.top() : " << s.top() << endl;
    cout << "The stack is : ";
    print_stack(s);  // calling our stack function
    cout << "s.pop() : ";
    s.pop();
    print_stack(s);
    cout << "s.pop() : ";
    s.pop();
    print_stack(s);

    s = {1, 4, 5, 3, 2, 6};  // assign new stack
    cout << "New stack:  {1, 4, 5, 3, 2, 6}\n";
    print_stack(s);  // calling our stack function
    cout << "s.pop() : ";
    s.pop();
    print_stack(s);
    cout << "s.pop() : ";
    s.pop();
    print_stack(s);

    return 0;
}

/*
Output:
s.size() : 5
s.top() : 1
The stack is : 1, 5, 20, 30, 10,
s.pop() : 5, 20, 30, 10,
s.pop() : 20, 30, 10,
New stack:  {1, 4, 5, 3, 2, 6}
6, 2, 3, 5, 4, 1,
s.pop() : 2, 3, 5, 4, 1,
s.pop() : 3, 5, 4, 1,
*/
