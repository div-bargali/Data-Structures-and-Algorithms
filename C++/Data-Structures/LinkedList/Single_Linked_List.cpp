// Single Linked List

// A generic C++ implementation of a linked list
#include <cstddef>
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::move;
using std::initializer_list;
using std::swap;

template <typename T>
struct _SingleLinkedListNode {
    T data;
    _SingleLinkedListNode* next;
    explicit _SingleLinkedListNode(const T& data_, _SingleLinkedListNode* n = nullptr)
        : data(data_), next(n) {}
    explicit _SingleLinkedListNode(T&& data_, _SingleLinkedListNode* n = nullptr)
        : data(move(data_)), next(n) {}
};

template <typename T>
class SingleLinkedList {
   public:
    using Node = _SingleLinkedListNode<T>;
    using value_type = T;

    /*
    Default constructor

    Initialize an empty list.
    */
    SingleLinkedList() {}

    /*
    Copy constructor

    Initialize a list copying the values of another one.
    */
    SingleLinkedList(const SingleLinkedList& o) {
        Node* node = o.head_;
        for (Node** aux = &head_; node != nullptr; node = node->next) {
            *aux = new Node(node->data);
            aux = &(*aux)->next;
        }
    }

    /*
    Move constructor

    Initialize a list by moving from another list.
    */
    SingleLinkedList(SingleLinkedList&& o) {
        swap(head_, o.head_);
        swap(size_, o.size_);
    }

    /*
    Constructor

    Initialize a list with the values of a range given as a pair
    of iterators.
    */
    template <typename Iter>
    SingleLinkedList(Iter first, Iter last) {
        for (Node** aux = &head_; first != last; ++first) {
            *aux = new Node(*first);
            aux = &(*aux)->next;
        }
    }

    /*
    Constructor

    Initialize a list with an initializer_list
    */
    SingleLinkedList(initializer_list<T> data)
        : SingleLinkedList(data.begin(), data.end()) {}

    /*
    Copy Assignment operator
    */
    SingleLinkedList& operator=(const SingleLinkedList& o) {
        clear();
        Node* node = o.head_;
        for (Node** aux = &head_; node != nullptr; node = node->next) {
            *aux = new Node(node->data);
            aux = &(*aux)->next;
        }
        return *this;
    }

    /*
    Move Assignment operator
    */
    SingleLinkedList& operator=(SingleLinkedList&& o) {
        swap(head_, o.head_);
        swap(size_, o.size_);
        return *this;
    }

    /*
    Destructor
    */
    ~SingleLinkedList() noexcept { clear(); }

    /*
    Erases all nodes from the list.
    */
    void clear() {
        while (this->size() > 0) {
            pop_front();
        }
    }

    /*
    Inserts a single value at the front of the list
    */
    void push_front(const T& value) {
        if (!head_) {
            head_ = new Node(value, nullptr);
        } else {
            head_ = new Node(value, head_);
        }
        ++size_;
    }

    /*
    Inserts a single value at the front of the list by moving it.
    */
    void push_front(T&& value) {
        if (!head_) {
            head_ = new Node(move(value), nullptr);
        } else {
            head_ = new Node(move(value), head_);
        }
        ++size_;
    }

    /*
    Removes the front element of the list.
    */
    void pop_front() {
        if (head_) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            size_--;
        }
    }

    /*
    Returns the size of the list.

    Example:

    SingleLinkedList<int> list = {1, 2, 3, 4};
    assert(list.size() == 4);
    list.pop_front();
    assert(list.size() == 3);
    list.clear();
    assert(list.size() == 0);
    */
    size_t size() const { return size_; }

    /*
    Retrieves the front element of the list.
    Calling this method when the the list is empty is undefined behavior.
    */
    T& front() { return head_->data; }
    const T& front() const { return head_->data; }

    /*
    Call a function with each element of the list as argument.
    */
    template <typename Func>
    Func for_each(Func f) {
        for (Node* i = head_; i != nullptr; i = i->next) {
            f(i->data);
        }
        return move(f);
    }
    template <typename Func>
    Func for_each(Func f) const {
        for (const Node* i = head_; i != nullptr; i = i->next) {
            f(i->data);
        }
        return move(f);
    }

   private:
    Node* head_ = nullptr;
    size_t size_ = 0u;
};

// Creates a list and prints its elements
int main() {
    // Create a likned list with 4 int's
    //     +---+---+	 +---+---+	  +---+---+     +---+---+     +---+---------+
    //     | 1 | o-----> | 2 | o----->| 3 | o-----> | 3 | o-----> | 4 | nullptr |
    //     +---+---+	 +---+---+	  +---+---+     +---+---+     +---+---------+
    SingleLinkedList<int> list = {1, 2, 3, 4};

    // Print each element of the list
    list.for_each([](const int& i) { cout << i << ", "; });
    cout << endl;

    // Assign an empty list
    list = {};
    cout << "List size: " << list.size() << endl;  // size => 0
}
