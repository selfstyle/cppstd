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

int main(){
  /*
  std::shared_ptr<int> p(new int(5));
  std::cout << "p use count: " << p.use_count() << std::endl;
  //print1(p);
  //print2(p);
  print3(&p);
  std::cout << "p use count: " << p.use_count() << std::endl;
  */

  std::shared_ptr<int> pt(new int(5));
  std::cout << "pt use count: " << pt.use_count() << std::endl;
  //getptr4(pt);
  //getptr5(pt);
  getptr6(&pt);
  std::cout << "pt use count: " << pt.use_count() << std::endl;
  std::cout << "pt value: " << *pt << std::endl;

  return 0;
}
