#include <iostream>
#include "Array.h"

using namespace dsa;

int main(int argc, char const *argv[])
{
  Array<int> arr{11, 22, 33};
  arr.print();

  arr.addFirst(1);
  arr.addLast(2);
  arr.add(1, 3);
  arr.print();
  std::cout << arr.contains(1) << std::endl;;
  std::cout << arr.contains(66) << std::endl;
  std::cout << arr.get(1) << std::endl;
  std::cout << arr.find(33) << std::endl;
  std::cout << arr.find(44) << std::endl;
  arr.removeFirst();
  arr.removeLast();
  arr.removeElement(22);
  arr.print();
  int i = 0;
  while(i++ < 20){
    arr.addLast(i);
    arr.print();
  }
  i = 0;
  while(i++ < 20){
    arr.removeLast();
    arr.print();
  }

  return 0;
}
