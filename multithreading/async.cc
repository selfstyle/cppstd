#include <iostream>
#include <future>

bool is_prime(int x){
  std::cout << "Calculating. Please, wait..." << std::endl;
  for(int i = 2; i < x; ++i)
    if(x % i == 0)
      return false;
  return true;
}

int main(){
  std::future<bool> fut = std::async(is_prime, 313222313);
  std::cout << "Checking whether 313222313 is prime." << std::endl;
  bool ret = fut.get();
  if(ret)
    std::cout << "It is prime!" << std::endl;
  else
    std::cout << "It is not prime." << std::endl;
  return 0;
}
