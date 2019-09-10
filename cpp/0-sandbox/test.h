void optimum_print(const std::vector<int> &numbers)
{
  static int call_frequency = 0;
  for (auto number : numbers)
    std::cout << number << " ";
  std::cout << std::endl;
  ++call_frequency;
  std::cout << call_frequency << std::endl;
}

void print_pointer(const int *pointer, const size_t size)
{
  for (size_t i = 0; i < size; i++)
    std::cout << *(pointer + i) << " ";
  std::cout << std::endl;
}

auto apply_all(int *array_1, int *array_2, size_t size_1, size_t size_2)
{
  int *final = new int[size_1 * size_2];
  size_t iterator = 0;
  for (size_t i = 0; i < size_2; i++)
    for (size_t j = 0; j < size_1; j++)
    {
      *(final + iterator) = *(array_1 + j) * *(array_2 + i);
      ++iterator;
    }
  return final;
}