#include <iostream>
#include <functional>

double my_divide(double x, double y){
  return x/y;
}

struct MyPair {
  double a,b;
  double multiply(){
    return a*b;
  }
};

struct int_holder{
  int value;
  int triple(){
    return value * 3;
  }
};

int main(){
  //bind
  using namespace std::placeholders; // adds visibility of _1, _2, _3..

  auto fn_five = std::bind(my_divide, 10, 2);
  std::cout << fn_five() << std::endl;

  auto fn_half = std::bind(my_divide, _1, 2);
  std::cout << fn_half(10) << std::endl;

  auto fn_invert = std::bind(my_divide, _2, _1);
  std::cout << fn_invert(10, 2) << std::endl;

  auto fn_rounding = std::bind<int>(my_divide, _1, _2);
  std::cout << fn_rounding(10, 3) << std::endl;

  MyPair ten_two{10,2};
  auto bound_member_fn = std::bind(&MyPair::multiply, _1);
  std::cout << bound_member_fn(ten_two) << std::endl;

  auto bound_member_data = std::bind(&MyPair::a, ten_two);
  std::cout << bound_member_data() << std::endl;
  //-------------------------------
  //ref
  std::cout << "-------------------------" << std::endl;
  int foo(10);
  auto bar = std::ref(foo);
  ++bar;
  std::cout << foo << std::endl;
  //-------------------------------
  //mem_fn
  int_holder five{5};
  std::cout << five.triple() << std::endl;
  auto triple = std::mem_fn(&int_holder::triple);
  std::cout << triple(five) << std::endl;

  return 0;
}
