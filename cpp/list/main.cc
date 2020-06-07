#include <iostream>
#include "SingleList.h"
#include "DoubleList.h"

using namespace dsa;

void testSingleList();
void testDoubleList();

int main()
{

  testSingleList();
  testDoubleList();

  return 0;
}

void testDoubleList()
{
  DoubleList<int> dList;
  dList.add(0, 1);
  dList.add(1, 2);
  dList.add(1, 3);
  dList.add(1, 4);
  dList.addFirst(66);
  dList.addLast(77);
  dList.print();

  std::cout << "after remove\n";
  dList.remove(0);
  dList.removeFirst();
  dList.removeLast();
  dList.removeElement(4);
  dList.print();

  std::cout << "set and get test\n";
  dList.set(1, 66);
  std::cout << dList.get(1) << " " << dList.getFirst() << " " << dList.getLast() << std::endl;
  dList.print();

  std::cout << "other\n";
  std::cout << dList.contains(3) << " " << dList.contains(88) << " " << dList.size() << " " << dList.empty() << std::endl;
  DoubleList<int> dList2(dList);
  dList2.print();

  std::cout << "copy ctor\n";
  DoubleList<int> dList3;
  dList3.addLast(66);
  dList3.addLast(77);
  dList3.addLast(88);
  dList3.print();

  std::cout << "operator assigment\n";
  dList3 = dList2;
  dList3.print();
}

void testSingleList()
{
  SingleList<int> sList;
  sList.add(0, 1);
  sList.add(1, 2);
  sList.add(1, 3);
  sList.add(1, 4);
  sList.addFirst(66);
  sList.addLast(77);
  sList.print();

  std::cout << "after remove\n";
  sList.remove(0);
  sList.removeFirst();
  sList.removeLast();
  sList.removeElement(4);
  sList.print();

  std::cout << "set and get test\n";
  sList.set(1, 66);
  std::cout << sList.get(1) << " " << sList.getFirst() << " " << sList.getLast() << std::endl;
  sList.print();

  std::cout << "other\n";
  std::cout << sList.contains(3) << " " << sList.contains(88) << " " << sList.size() << " " << sList.empty() << std::endl;
  SingleList<int> sList2(sList);
  sList2.print();

  std::cout << "copy ctor\n";
  SingleList<int> sList3;
  sList3.addLast(66);
  sList3.addLast(77);
  sList3.addLast(88);
  sList3.print();

  std::cout << "operator assigment\n";
  sList3 = sList2;
  sList3.print();
}
