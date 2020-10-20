import unittest
from Python.DataStructures.DoublyLinkedList.doubly_linked_list import DoublyLinkedList

class TestDoublyLinkedList(unittest.TestCase):

    def test_list_is_empty_on_initialization(self):
        a_doubly_linked_list = DoublyLinkedList()
        self.assertEqual(a_doubly_linked_list.length(), 0)

    def test_adding_to_front_should_append_node_to_front(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        self.assertEqual(a_doubly_linked_list.length(), 1)
        a_doubly_linked_list.insert_at_beginning(4)
        self.assertEqual(a_doubly_linked_list.__str__(), "4 --> 5")

    def test_adding_to_end_should_append_node_to_end(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        self.assertEqual(a_doubly_linked_list.length(), 1)
        a_doubly_linked_list.insert_at_end(4)
        self.assertEqual(a_doubly_linked_list.__str__(), "5 --> 4")
        self.assertEqual(a_doubly_linked_list.length(), 2)

    def test_insert_at_should_append_node_to_correct_position_for_a_short_list(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(3)

        a_doubly_linked_list.insert_at(4, 1)
        self.assertEqual(a_doubly_linked_list.__str__(), "3 --> 4 --> 5")
        self.assertEqual(a_doubly_linked_list.length(), 3)

    def test_insert_at_should_append_node_to_correct_position(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(2)
        a_doubly_linked_list.insert_at_beginning(1)

        a_doubly_linked_list.insert_at(3, 2)
        self.assertEqual(a_doubly_linked_list.__str__(), "1 --> 2 --> 3 --> 4 --> 5")
        self.assertEqual(a_doubly_linked_list.length(), 5)

    def test_insert_at_should_insert_at_start(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(4)

        a_doubly_linked_list.insert_at(3, 0)
        self.assertEqual(a_doubly_linked_list.__str__(), "3 --> 4 --> 5")
        self.assertEqual(a_doubly_linked_list.length(), 3)

    def test_insert_at_should_insert_at_end_for_short_list(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(4)

        a_doubly_linked_list.insert_at(6, 2)
        self.assertEqual(a_doubly_linked_list.__str__(), "4 --> 5 --> 6")
        self.assertEqual(a_doubly_linked_list.length(), 3)

    def test_insert_at_should_insert_at_end(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)

        a_doubly_linked_list.insert_at(6, 4)
        self.assertEqual(a_doubly_linked_list.__str__(), "4 --> 4 --> 4 --> 5 --> 6")
        self.assertEqual(a_doubly_linked_list.length(), 5)

    def test_remove_val_should_remove_values_from_list(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(3)
        a_doubly_linked_list.insert_at_beginning(2)
        a_doubly_linked_list.insert_at_beginning(1)

        a_doubly_linked_list.remove_val(1)
        self.assertEqual(a_doubly_linked_list.length(), 3)
        self.assertEqual(a_doubly_linked_list.__str__(), "2 --> 3 --> 4")

    def test_remove_val_should_remove_values_from_list_when_values_are_all_the_same(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)

        a_doubly_linked_list.remove_val(4)
        self.assertEqual(a_doubly_linked_list.length(), 0)
        self.assertEqual(a_doubly_linked_list.__str__(), "")

    def test_remove_val_should_remove_values_from_list_when_values_are_all_the_same_except_one(self):
        a_doubly_linked_list = DoublyLinkedList()
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(5)
        a_doubly_linked_list.insert_at_beginning(4)
        a_doubly_linked_list.insert_at_beginning(4)

        a_doubly_linked_list.remove_val(4)
        self.assertEqual(a_doubly_linked_list.__str__(), "5")
        self.assertEqual(a_doubly_linked_list.length(), 1)
        self.assertEqual(a_doubly_linked_list.__str__(), "5")
