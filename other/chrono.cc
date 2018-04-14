#include <iostream>
#include <chrono>

int main(){
  using std::chrono::system_clock;
  system_clock::time_point today = system_clock::now();
  std::cout << today << std::endl;
  return 0;
}
