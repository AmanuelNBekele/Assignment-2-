#include "Single_Linked_List.h"

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List()
    : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
  while (!empty()) {
    pop_front();
  }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type &item) {
  Node<Item_Type> *new_node = new Node<Item_Type>(item);
  if (empty()) {
    head = tail = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
  num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type &item) {
  Node<Item_Type> *new_node = new Node<Item_Type>(item);
  if (empty()) {
    head = tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
  num_items++;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  Node<Item_Type> *temp = head;
  Item_Type data = temp->data;
  head = head->next;
  delete temp;
  num_items--;
  if (num_items == 0) {
    tail = nullptr;
  }
  return data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  Item_Type data;
  if (num_items == 1) {
    data = head->data;
    delete head;
    head = tail = nullptr;
  } else {
    Node<Item_Type> *temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    data = tail->data;
    delete tail;
    tail = temp;
    tail->next = nullptr;
  }
  num_items--;
  return data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return head->data;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
  return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index,
                                           const Item_Type &item) {
  if (index < 0 || index > num_items) {
    push_back(item); // Insert at the end if index is out of bounds
  } else if (index == 0) {
    push_front(item);
  } else {
    Node<Item_Type> *new_node = new Node<Item_Type>(item);
    Node<Item_Type> *current = head;
    for (size_t i = 0; i < index - 1; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    num_items++;
    if (index == num_items - 1) {
      tail = new_node;
    }
  }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
  if (index < 0 || index >= num_items) {
    return false;
  }
  if (index == 0) {
    Node<Item_Type> *temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (num_items == 0) {
      tail = nullptr;
    }
  } else {
    Node<Item_Type> *current = head;
    for (size_t i = 0; i < index - 1; i++) {
      current = current->next;
    }
    Node<Item_Type> *temp = current->next;
    current->next = temp->next;
    delete temp;
    num_items--;
    if (index == num_items) {
      tail = current;
    }
  }
  return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type &item) const {
  Node<Item_Type> *current = head;
  size_t index = 0;
  while (current != nullptr) {
    if (current->data == item) {
      return index;
    }
    current = current->next;
    index++;
  }
  return num_items;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
  return num_items;
}
