# CS 104 Student Repository HW8

- **Name**: Alden Falcon
- **USC ID**: 2291459231
- **Email**: afalcon@usc.edu

Problem 6 compiling:
g++ -g -Wall zipf.cpp hash.cpp -o zipf

I was not able to test my code on zipf because I had not
finished debugging
the hash algorithm should have run faster however
because its add function should take constant time on
average case (when not rehashing), while the splay tree
could take up to linear time

An unsorted list would be linear time to add, because
we would have to see if it already exists
A sorted list would take log n time, because we could use
binary search to see if it already exists
A binary search tree could take linear time because we
 wouldnt know if it's balanced
A balanced tree (AVL) we are guaranteed log n time.

