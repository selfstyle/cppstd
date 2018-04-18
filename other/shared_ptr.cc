#include <iostream>
#include <memory>

void print1(std::shared_ptr<int> p1){
  std::cout << "value: " << *p1 << std::endl;
  std::cout << "p1 use count: " << p1.use_count() << std::endl;
}

void print2(std::shared_ptr<int>& p2){
  std::cout << "value: " << *p2 << std::endl;
  std::cout << "p2 use count: " << p2.use_count() << std::endl;
}

void print3(std::shared_ptr<int>* p3){
  std::cout << "value: " << **p3 << std::endl;
  std::cout << "p3 use count: " << p3->use_count() << std::endl;
}

void getptr4(std::shared_ptr<int> p4){
  std::cout << "p4 use count: " << p4.use_count() << std::endl;
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  p4 = p;
  std::cout << "p use count: " << p.use_count() << std::endl;
}

void getptr5(std::shared_ptr<int>& p5){
  std::cout << "p5 use count: " << p5.use_count() << std::endl;
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  p5 = p;
  std::cout << "p use count: " << p.use_count() << std::endl;
}

void getptr6(std::shared_ptr<int>* p6){
  std::cout << "p6 use count: " << p6->use_count() << std::endl;
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  *p6 = p;
  std::cout << "p6 use count: " << p6->use_count() << std::endl;
  std::cout << "p use count: " << p.use_count() << std::endl;
}

std::shared_ptr<int> getptr7(){
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  return p;
}

std::shared_ptr<int>& getptr8(){
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  return p;
}

std::shared_ptr<int>* getptr9(){
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  return &p;
}

int main(){
  /*
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  //print1(p);
  //print2(p);
  print3(&p);
  std::cout << "p use count: " << p.use_count() << std::endl;
  */

  /*
  std::shared_ptr<int> pt(new int(5));
  std::cout << "pt use count: " << pt.use_count() << std::endl;
  //getptr4(pt);
  //getptr5(pt);
  getptr6(&pt);
  std::cout << "pt use count: " << pt.use_count() << std::endl;
  std::cout << "pt value: " << *pt << std::endl;
  */

  std::shared_ptr<int> ptr;
  std::cout << "ptr use count: " << ptr.use_count() << std::endl;
  //ptr = getptr7();
  //ptr = std::move(getptr7());
  //ptr = getptr8(); // 这种情况下调用失败
  //ptr = std::move(getptr8()); //这种情况下调用也失败
  //std::cout << "ptr use count: " << ptr.use_count() << std::endl;
  //std::cout << "ptr value: " << *ptr << std::endl;

  /* // 错误的写法
  std::shared_ptr<int>* ptr9;
  ptr9 = getptr9();
  std::cout << "ptr9 use count: " << ptr9->use_count() << std::endl;
  std::cout << "ptr9 value: " << **ptr9 << std::endl;
  */


  return 0;
}
