#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void swap_nums(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

class Heap
{
private:
  vector<int> heap;

public:
  int parent_index(int index);
  int parent_value(int index) { return this->heap[parent_index(index)]; }
  int left_child_index(int index);
  int left_child_value(int index) { return this->heap[left_child_index(index)]; }
  int right_child_index(int index);
  int right_child_value(int index) { return this->heap[right_child_index(index)]; }
  bool index_in_range(int index);
  void shift_up(int index);
  void shift_down(int index);
  void insert(int value);
  int extract_max();
  void print_heap();

  void Heap::print_heap()
  {
    for (auto number : this->heap)
      cout << number << " ";
    cout << endl;
  }

  int Heap::parent_index(int index)
  {
    if (index <= 0)
      return -1;
    return (index - 1) / 2;
  }

  int Heap::left_child_index(int index)
  {
    if (2 * index + 1 < heap.size())
      return 2 * index + 1;
    return -1;
  }

  int Heap::right_child_index(int index)
  {
    if (2 * index + 2 < heap.size())
      return 2 * index + 2;
    return -1;
  }

  bool Heap::index_in_range(int index)
  {
    return index >= 0 && index < heap.size();
  }

  void Heap::shift_up(int index)
  {
    if (parent_index(index) == -1 || !index_in_range(index))
      // no parent we are at root
      return;
    if (this->parent_value(index) < this->heap[index])
    {
      swap_nums(this->heap[parent_index(index)], this->heap[index]);
      shift_up(parent_index(index));
    }
  }

  void Heap::insert(int value)
  {
    this->heap.push_back(value);
    this->shift_up(this->heap.size() - 1);
  }

  void Heap::shift_down(int index)
  {
    if (!index_in_range(index))
      return;
    int node_value = this->heap[index];
    if (this->left_child_index(index) == -1)
      return;
    int l_value = this->left_child_value(index);
    int r_value = this->right_child_index(index) == -1 ? INT_MIN : this->right_child_value(index);

    if (l_value > node_value)
    {
      if (r_value > l_value)
      {
        // swap with right
        swap_nums(this->heap[right_child_index(index)], this->heap[index]);
        this->shift_down(this->right_child_index(index));
      }
      else
      {
        // swap with left
        swap_nums(this->heap[left_child_index(index)], this->heap[index]);
        this->shift_down(this->left_child_index(index));
      }
    }
  }

  int Heap::extract_max()
  {
    auto final = this->heap[0];
    swap_nums(this->heap[0], this->heap[this->heap.size() - 1]);
    this->heap.pop_back();
    this->shift_down(0);
    return final;
  }
};

int main(int argc, char const *argv[])
{
  Heap heap;
  heap.insert(4);
  heap.print_heap();
  heap.insert(5);
  heap.insert(2);
  heap.insert(6);
  heap.insert(3);
  heap.extract_max();
  heap.print_heap();
  return 0;
}
