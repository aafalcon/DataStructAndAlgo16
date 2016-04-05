#include <vector>
#include <cstdlib>

template <class T>
  class MinHeap {
     public:
       MinHeap (int d);
       /* Constructor that builds a d-ary Min Heap
          This should work for any d >= 2,
          but doesn't have to do anything for smaller d.*/

       ~MinHeap ();

       void add (T item, int priority);
         /* adds the item to the heap, with the given priority. */

       const T & peek () const;
         /* returns the element with smallest priority. */

       void remove ();
         /* removes the element with smallest priority. */

       bool isEmpty ();
         /* returns true iff there are no elements on the heap. */

   private:
      // whatever you need to naturally store things.
      // You may also add helper functions here.
      std::vector<std::pair<T, int> > data;
      int d_ary;
      int size;
      void bubbleUp(int pos);
      void trickleDown(int pos);
      void swap(int pos1, int pos2);
  };

  template <class T>
  MinHeap<T>::MinHeap(int d) {
    d_ary = d;
    size = 0;
  }

  template <class T>
  MinHeap<T>::~MinHeap() {

  }

  template <class T>
  void MinHeap<T>::add(T item, int priority) {
    std::pair<T, int> node;
    node = std::make_pair(item, priority);
    data.push_back(node);
    bubbleUp(size);
    size++;
  }

  template <class T>
  const T & MinHeap<T>::peek() const {
    return data[0].first;
  }

  template <class T>
  void MinHeap<T>::remove() {
    swap(0, size-1);
    data.pop_back();
    size--;
    trickleDown(0);
  }

  template <class T>
  bool MinHeap<T>::isEmpty() {
    if (size == 0) return true;
    else return false;
  }

  template <class T> 
  void MinHeap<T>::bubbleUp(int pos) {
    int parent = (pos-1) / d_ary;
    if (pos > 0 && data[pos].second < data[parent].second) {
      swap(pos, parent);
      bubbleUp(parent);
    }
  }

  template <class T>
  void MinHeap<T>::trickleDown(int pos) {
    int child = d_ary * pos + 1;
    if (child < size)
    {
      for (int i=0; i<d_ary; ++i)
      {
        if (child+1 < size && data[child+1].second < data[child].second) child++;
      }
      if (data[child].second < data[pos].second)
      {
        swap(child, pos);
        trickleDown(child);
      }
    }
  }

  template <class T>
  void MinHeap<T>::swap(int pos1, int pos2) {
    std::pair<T, int> temp;
    temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
  }