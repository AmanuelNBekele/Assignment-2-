#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>

template <typename Item_Type> class Node {
public:
  Item_Type data;
  Node *next;

  Node(const Item_Type &item) : data(item), next(nullptr) {}
};

template <typename Item_Type> class Single_Linked_List {
private:
  Node<Item_Type> *head;
  Node<Item_Type> *tail;
  size_t num_items;

public:
  Single_Linked_List();
  ~Single_Linked_List();

  void push_front(const Item_Type &item);
  void push_back(const Item_Type &item);
  Item_Type pop_front();
  Item_Type pop_back();
  Item_Type front() const;
  Item_Type back() const;
  bool empty() const;
  void insert(size_t index, const Item_Type &item);
  bool remove(size_t index);
  size_t find(const Item_Type &item) const;
  size_t size() const;
};

#endif // SINGLE_LINKED_LIST_H
