import unittest
from Python.DataStructures.Stack.stack import Stack

class TestStack(unittest.TestCase):

    def test_stack_is_empty_on_initialization(self):
        s = Stack()
        self.assertTrue(s.is_empty())
        self.assertEqual(s.size(), 0)

    def test_pop_on_an_empty_stack_raises_error(self):
        s = Stack()
        self.assertRaises(IndexError, s.peek)

    def test_peek_on_an_empty_stack_raises_error(self):
        s = Stack()
        self.assertRaises(IndexError, s.peek)

    def test_size_should_return_the_correct_number_of_elements_on_the_stack(self):
        s = Stack()

        s.push(1)
        s.push(3)
        self.assertEqual(s.size(), 2)

        s.push(5)
        self.assertEqual(s.size(), 3)

        s.pop()
        s.pop()
        self.assertEqual(s.size(), 1)
        s.pop()
        self.assertEqual(s.size(), 0)
        self.assertTrue(s.is_empty())

    def test_pop_should_correctly_remove_and_return_values_in_reverse_order(self):
        s = Stack()

        s.push(1)
        s.push(3)
        self.assertEqual(s.pop(), 3)
        self.assertEqual(s.pop(), 1)

    def test_peek_should_return_the_value_at_the_top_of_the_stack_without_altering_the_stack(self):
        s = Stack()

        s.push(1)
        s.push(3)
        self.assertEqual(s.peek(), 3)
        self.assertEqual(s.size(), 2)
