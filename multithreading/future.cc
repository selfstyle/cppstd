#include <iostream>
#include <functional>
#include <thread>
#include <future>

void print_int(std::future<int>& fut, int i){
  std::cout << "thread :" << i <<" waiting..."<< std::endl;
  //阻塞函数
  int x = fut.get();
  std::cout << "value: " << x << std::endl;
}

int main(){
  std::promise<int> prom;
  std::future<int> fut = prom.get_future();
  std::thread th1(print_int, std::ref(fut), 1);
  std::thread th2(print_int, std::ref(fut), 2);
  std::thread th3(print_int, std::ref(fut),3);
  std::this_thread::sleep_for(std::chrono::seconds(3));
  prom.set_value(10);

  th1.join();
  th2.join();
  return 0;
}
