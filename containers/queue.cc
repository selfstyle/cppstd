#include <iostream>
#include <queue>
#include <deque>
#include <list>

int main(){

  std::deque<int> mydeque(3, 100);
  std::list<int> mylist(2, 200);
  std::queue<int> first;
  std::queue<int> second(mydeque);
  std::queue<int, std::list<int> > third;
  std::queue<int, std::list<int> > fourth(mylist);

  //error
  //std::queue<int> fifth(mylist);
  //std::queue<int, std::list<int> seventh(mydeque);

  std::cout << "size of first: " << first.size() << std::endl;
  std::cout << "size of second: " << second.size() << std::endl;
  std::cout << "size of third: " << third.size() << std::endl;
  std::cout << "size of fourth: " << fourth.size() << std::endl;

  /*
  std::queue<int> myqueue;
  int myint;
  std::cout << "Please enter some integers(enter 0 to end):" << std::endl;

  do {
    std::cin >> myint;
    myqueue.push(myint);
  }while(myint);

  std::cout << "size: " << myqueue.size() << std::endl;
  std::cout << "front: " << myqueue.front() << std::endl;
  std::cout << "back: " << myqueue.back() << std::endl;
  while(!myqueue.empty()){
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << std::endl;
  */
  return 0;
}
