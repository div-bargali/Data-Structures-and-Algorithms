using System;
using System.Collections.Generic;

/// <summary>
/// A DoublyLinkedList
/// </summary>
namespace DataStructures
{
    public class DoublyLinkedListNode<T>
    {
        // Constructs a new node with the specified value.
        public DoublyLinkedListNode(T value)
        {
            Value = value;
            Next = null;
            Prev = null;
        }
        // The node value
        public T Value { get; set; }
        // The next node in the Doubly linked list (null if last node)
        public DoublyLinkedListNode<T> Next { get; set; }
        public DoublyLinkedListNode<T> Prev { get; set; }
    }

    /// <summary>
    /// A Doubly linked list collection capable of basic operations such as 
    /// Add, Remove, Check, Search, IsEmpty, Size, Insert and Index
    /// </summary>
    public class DoublyLinkedList<T>
    {
        /// <summary>
        /// Adds the specified value to the tail of the doublylinked list
        /// </summary>
        public int Add(T item)
        {
            DoublyLinkedListNode<T> node = new DoublyLinkedListNode<T>(item);
            if (count == 0)
            {
                head = node;
                tail = head;
            }
            else
            {
                node.Prev = tail;
                tail.Next = node;
                tail = node;
            }

            return ++count;
        }

        /// <summary>
        /// Inserts the specified item at the specified index
        /// </summary>
        /// <param name="index"></param>
        /// <param name="item"></param>
        public void Insert(int index, T item)
        {
            if (index > count + 1 || (count == 0 && index > 0) || index < 0)
            {
                throw new IndexOutOfRangeException("Index out of range.");
            }
            if (count == 0 || index == count)
            {
                Add(item);
                return;
            }
            var currentIndex = 0;
            DoublyLinkedListNode<T> current = head;
            DoublyLinkedListNode<T> node = new DoublyLinkedListNode<T>(item);
            while (currentIndex <= index)
            {
                if(currentIndex == index)
                {
                    DoublyLinkedListNode<T> previous = current.Prev;
                    if (previous == null) head = node;
                    node.Prev = previous;
                    node.Next = current;
                    //previous.Next = node;
                    current.Prev = node;
                    count++;
                    return;
                }
                current = current.Next;
                currentIndex++;
            }
            return;
        }

        /// <summary>
        /// Removes a VALUE from the list if found.
        /// </summary>
        public bool Remove(T item)
        {
            var check = false;

            DoublyLinkedListNode<T> node = new DoublyLinkedListNode<T>(item);

            // Checks if only one item is in the list
            // and if the item is the same as the item to be removed
            if (count == 1 && item.Equals(head.Value))
            {
                check = true;
                head = null;
                tail = head;
            }

            // Iterates through the doublylinked list to check for the item
            while (Check(item))
            {
                check = true;

                DoublyLinkedListNode<T> current = head;
                while (current != null)
                {
                    if (current.Value.Equals(item))
                    {
                        DoublyLinkedListNode<T> previous = current.Prev;
                        DoublyLinkedListNode<T> next = current.Next;

                        if (previous == null)
                        {
                            head = next;
                            next.Prev = null;
                        }
                        else if (next == null)
                        {
                            tail = previous;
                            previous.Next = null;
                        }
                        else
                        {
                            previous.Next = current.Next;
                            next.Prev = current.Prev;

                        }
                        count--;
                    }

                    current = current.Next;
                }                
            }
            return check;
        }

        /// <summary>
        /// Returns true if the list contains the specified item,
        /// false otherwise.
        /// </summary>
        public bool Check(T item)
        {
            DoublyLinkedListNode<T> current = head;
            while (current != null)
            {
                if (current.Value.Equals(item))
                {
                    return true;
                }

                current = current.Next;
            }
            return false;
        }

        /// <summary>
        /// Returns item if the list contains the specified item
        /// </summary>
        /// <returns>Returns item if found</returns>
        public T Search(T item)
        {
            if (!Check(item))
            {
                throw new InvalidOperationException("Item not found in list.");
            }

            DoublyLinkedListNode<T> current = head;
            while (current != null)
            {
                if (current.Value.Equals(item))
                {
                    return current.Value;
                }

                current = current.Next;
            }

            return item;
        }

        /// <summary>
        /// Returns true if the list is empty, otherwise false.
        /// </summary>
        public bool isEmpty()
        {
            return count == 0;
        }

        /// <summary>
        /// Checks for the length of list
        /// </summary>
        /// <returns>Length of list</returns>
        public int Size()
        {
            return count;
        }

        /// <summary>
        /// Finds the index of the specified item
        /// </summary>
        /// <param name="item"></param>
        /// <returns>the index of item</returns>
        public int Index(T item)
        {
            if (!Check(item))
            {
                throw new InvalidOperationException("Item not in list");
            }

            DoublyLinkedListNode<T> current = head;
            var currentIndex = 0;

            while (currentIndex != count)
            {
                if (current.Value.Equals(item))
                {
                    return currentIndex;
                }

                current = current.Next;
                currentIndex++;
            }
            return -1;
        }

        /// <summary>
        /// Length of list, zero if list is empty
        /// </summary>
        public int count
        {
            get;
            private set;
        }

        /// <summary>
        /// The first node in the list or null if empty
        /// </summary>
        private DoublyLinkedListNode<T> head
        {
            get;
            set;
        }

        /// <summary>
        /// The last node in the list or null if empty
        /// </summary>
        private DoublyLinkedListNode<T> tail
        {
            get;
            set;
        }
    }
}
