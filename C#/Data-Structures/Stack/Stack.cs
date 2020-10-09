using System;
using System.Collections.Generic;

namespace DataStructures
{
    class Stack<T>
    {
        /// <summary>
        /// Implementation of a Stack
        /// </summary>
        public Stack()
        {
            // initialize stack
            stack = new List<T>();
        }

        /// <summary>
        /// Checks if stack is empty
        /// </summary>
        /// <returns>true if stack is empty</returns>
        public bool isEmpty()
        {
            return count == 0;
        }

        /// <summary>
        /// Adds value to the top of stack
        /// </summary>
        /// <param name="value"></param>
        public void Push (T value)
        {
            stack.Add(value);
            count++;
        }

        /// <summary>
        /// Removes the item at the top of the stack
        /// </summary>
        /// <param name="value"></param>
        public T Pop()
        {
            if (count == 0) throw new InvalidOperationException("The stack is empty.");

            T item = stack[count - 1];
            stack.RemoveAt(count - 1);
            count--;
            return item;
        }

        /// <summary>
        /// Returns value at stack's top if available
        /// </summary>
        /// <returns>return item if found</returns>
        public T Peek()
        {
            if (count == 0) throw new InvalidOperationException("The stack is empty.");

            return stack[^1];
        }

        /// <summary>
        /// Checks for the size of stack
        /// </summary>
        /// <returns>size of stack</returns>
        public int Size()
        {
            return stack.Count;
        }

        /// <summary>
        /// print out values in stack
        /// </summary>
        public void Print()
        {
            if(count == 0)
            {
                Console.WriteLine("The stack is empty.");
                return;
            }

            foreach (var item in stack)
            {
                Console.WriteLine(item);
            }
        }
		
        // declare the structure of stack
        private List<T> stack
        {
            get;
            set;
        }
		
        // initialize stack size to zero
        private int count = 0;
    }
}
