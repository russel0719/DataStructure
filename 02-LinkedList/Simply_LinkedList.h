#include "Node.h"

template <typename T>
class Simply_LinkedList
{
public :
  Simply_LinkedList();
  ~Simply_LinkedList();
  void insert(T data);
  void delete_index(size_t idx);
  size_t find(T data);
  void print();
private :
  Node<T>* head;
  size_t size;
}
