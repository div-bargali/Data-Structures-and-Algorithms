import sys

# index of given char
def index(inputCh):
    return ord(inputCh) - ord('a')


# empty Node
class Node(object):
    children = None

    def __init__(self):
        self.children = [None] * 26
        self.ch = ' '
        self.word = ""
        self.isLeaf = False
        self.parent = None


class Trie(object):
    root = None

    def __init__(self):
        self.root = Node()

    def insertString(self, in_string):

        current = self.root
        for c in in_string[:-1]:
            idx = index(c)
            try:
                if current.children[idx] is None:
                    current.children[idx] = Node()
                    current.children[idx].ch = c
                    current.children[idx].word = current.word + c
                    current.children[idx].parent = current
            except IndexError as ie:
                print("idx = {}\nchar = {}\nstring = {}".format(idx, c, in_string))

            current = current.children[idx]
        current.isLeaf = True

    def searchString(self, in_string):

        current = self.root

        for c in in_string:
            idx = index(c)

            # if character is in the trie
            if current.children[idx] is not None:
                current = current.children[idx]

            # character is not in the trie, word is not exist
            else:
                return False

        # if word is in the trie, returns true
        return current.isLeaf

    def deleteString(self, in_string):

        current = self.root
        if self.searchString(in_string):
            for c in in_string:
                idx = index(c)
                current = current.children[idx]

            current.isLeaf = False




# Examples

if __name__ == '__main__':

	new_trie = Trie()


	# insertion
	new_trie.insertString("apple\n")
	new_trie.insertString('app\n')
	new_trie.insertString("application\n")
	new_trie.insertString("homework\n")

	# search
	print(new_trie.searchString("app"))         # expected output: true
	print(new_trie.searchString("apply"))       # expected output: false

	# delete
	new_trie.deleteString('app')

	# search after delete
	print(">>>Search after delete<<<")
	print(new_trie.searchString('app'))          # expected output: false
	print(new_trie.searchString('application'))  # expected output: true
