### Disjoint Set

Dispoint sets are data structures that store and manipulate information about elements divided into non-redundant subsets.
Bit vectors, arrays, connection lists, trees, etc. can be used to implement a set, but they are implemented using the most efficient tree structure of them.
Operation of the Dispoint Set
make-set(x): Initialization operation, creating a new roll-unset with x as the only element.
find(x): Returns the representative value (root node) of the set to which x belongs. That is, an operation to find out which set x belongs to.
union(x, y): Add the set to which x belongs and the set to which y belongs.

- [Disjoint SEt Ranked by Size of Set](Disjoint_set_ranked_by_size_of_set.cpp)

    Time complexity = O(n)

- [Implementation of Disjoint Set](Implementation%20of%20disjoint%20set.cpp)

    Time complexity = O(n)