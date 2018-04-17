#include <utility>
#include <iostream>
#include <vector>
#include <string>

int main(){
  std::string foo = "foo-string";
  std::string bar = "bar-string";
  std::vector<std::string> myvector;

  myvector.push_back(foo);
  myvector.push_back(std::move(bar));

  std::cout << "myvecotr contains: ";
  for(auto& x : myvector)
    std::cout << ' ' << x;
  std::cout << std::endl;
  std::cout << "foo: " << foo << std::endl;
  std::cout << "bar: " << bar << std::endl;
  return 0;
}
