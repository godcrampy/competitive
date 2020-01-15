#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int data = 0) : data(data), next(nullptr) {}
};

typedef struct Node Node;

class SinglyLinkedList {
 private:
  Node *head;
  Node *tail;
  int length;

  Node *get_iterator_at_index(int index);

 public:
  SinglyLinkedList() : head(nullptr), tail(nullptr), length(0) {}
  int get_length() { return this->length; }
  void print();
  void unshift(int data);
  int shift();
  void push(int data);
  int pop();
  void insert(int index, int data);
  int erase(int index);
};

Node *SinglyLinkedList::get_iterator_at_index(int index) {
  if (index >= this->length)
    return nullptr;
  Node *iterator = this->head;
  for (auto i = 0; i < index; ++i)
    iterator = iterator->next;
  return iterator;
}

void SinglyLinkedList::print() {
  // works
  Node *iterator = this->head;
  while (iterator != nullptr) {
    cout << iterator->data << " ";
    iterator = iterator->next;
  }
  cout << endl;
}

void SinglyLinkedList::unshift(int data) {
  // works
  Node *node = new Node(data);
  node->next = this->head;
  this->head = node;
  if (this->length == 0)
    this->tail = node;
  ++this->length;
}

int SinglyLinkedList::shift() {
  // works
  --this->length;
  if (this->head == nullptr)
    return -1;
  int value = this->head->data;
  this->head = this->head->next;
  return value;
}

void SinglyLinkedList::push(int data) {
  // works
  Node *node = new Node(data);
  if (this->length != 0)
    this->tail->next = node;
  this->tail = node;
  if (this->length == 0)
    this->head = node;
  ++this->length;
}

int SinglyLinkedList::pop() {
  // works
  if (this->tail == nullptr)
    return -1;
  --this->length;
  if (this->length == 0) {
    int val = this->tail->data;
    this->head = nullptr;
    this->tail = nullptr;
    return val;
  }
  Node *pre_tail = this->get_iterator_at_index(this->length - 1);
  int val = this->tail->data;
  pre_tail->next = nullptr;
  return val;
}

void SinglyLinkedList::insert(int index, int data) {
  // works
  if (index < 0 || index > this->length)
    return;
  if (index == 0)
    return this->unshift(data);
  if (index == this->length)
    return this->push(data);
  Node *pre = this->get_iterator_at_index(index - 1);
  Node *post = pre->next;
  Node *temp = new Node(data);
  temp->next = post;
  pre->next = temp;
  ++this->length;
}

int SinglyLinkedList::erase(int index) {
  // works
  if (index < 0 || index >= this->length)
    return -1;
  if (index == 0)
    return this->shift();
  if (index == this->length - 1)
    return this->pop();
  Node *pre = this->get_iterator_at_index(index - 1);
  Node *post = pre->next;
  pre->next = pre->next->next;
  --this->length;
  return post->data;
}

int main(int argc, char const *argv[]) {
  SinglyLinkedList list;
  list.insert(0, 0);
  list.insert(1, 1);
  list.insert(2, 3);
  list.insert(2, 2);
  list.print();
  list.erase(0);
  list.erase(0);
  list.erase(0);
  list.erase(0);
  list.print();
  return 0;
}
