#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> global_counter(0);

void increase_global(int n){
  for (int i = 0; i < n; ++i){
    ++global_counter;
  }
}

void increase_reference(std::atomic<int>& variable, int n){
  for(int i =0; i < n; ++i){
    ++variable;
  }
}

struct C : std::atomic<int> {
  C(): std::atomic<int>(0){}
  void increase_member(int n){
    for(int i = 0; i < n; ++i){
      fetch_add(1);
    }
  }
};

void pause_thread(int n){
  std::this_thread::sleep_for(std::chrono::seconds(n));
  std::cout << "pause of " << n <<" seconds ended" << std::endl;
}

int main(){
  std::vector<std::thread> threads;
  std::cout << "increase global counter with 10 threads.." << std::endl;
  for(int i = 1; i <= 10; ++i){
    threads.push_back(std::thread(increase_global, 1000));
  }

  std::cout << "increase counter (foo) with 10 threads using reference.." << std::endl;
  std::atomic<int> foo(0);
  for(int i = 1; i<= 10; ++i){
    threads.push_back(std::thread(increase_reference, std::ref(foo), 1000));
  }

  std::cout << "increase counter (bar) with 10 threads using member .." << std::endl;
  C bar;
  //the next two is all right
  for (int i=1; i<=10; ++i)
    //threads.push_back(std::thread(std::mem_fun_ref(&C::increase_member),std::ref(bar),1000));
    threads.push_back(std::thread(std::mem_fn(&C::increase_member), &bar,1000));

  std::cout << "synchronizing all threads..." << std::endl;;
  for(auto& th : threads ){
    th.join();
  }

  std::cout << "global_counter: " << global_counter << std::endl;
  std::cout << "foo: " << foo << std::endl;
  std::cout << "bar: " << bar << std::endl;
  //----------------------
  //join
  std::cout << "---------------------------" << std::endl;
  std::cout << "Spawning 3 threads .." << std::endl;
  std::thread t1(pause_thread, 1);
  std::thread t2(pause_thread, 2);
  std::thread t3(pause_thread, 3);
  std::cout << "Done spawning threads. Now waiting for them to join:" <<std::endl;
  t1.join();
  t2.join();
  t3.join();
  std::cout << "All threads joined !" << std::endl;

  return 0;
}

