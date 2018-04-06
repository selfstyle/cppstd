#include <iostream>
#include <vector>

int main(){
  //构造函数
  std::vector<int> first;
  std::vector<int> second(4, 100);
  std::vector<int> third(second.begin(), second.end());
  std::vector<int> fourth(third);
  std::vector<int> sixth(4);
  //---------------------
  //遍历
  int myints[]={
    16,2,77,29
  };
  std::vector<int> fifth(myints, myints+sizeof(myints)/sizeof(int));
  for(std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it){
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
  for(auto &it : fifth){
    std::cout << ' ' <<  it;
  }
  std::cout << '\n';
  //--------------------
  //容量操作
  std::cout << "before fifth size: " << fifth.size() << std::endl;
  std::cout << "before fifth capacity: " << fifth.capacity() << std::endl;
  std::cout << "before fifth max size: " << fifth.max_size() << std::endl;
  for(int i = 0; i < 10; ++i) {
    fifth.push_back(i);
  }
  std::cout << "after fifth size: " << fifth.size() << std::endl;
  std::cout << "after fifth capacity: " << fifth.capacity() << std::endl;
  std::cout << "after fifth max size: " << fifth.max_size() << std::endl;
  int sum(0);
  while(!fifth.empty()){
   sum += fifth.back();
   fifth.pop_back();
  }
  std::cout << "sum fifth :" << sum << std::endl;
  //----------------------------------
  //改变操作
  first.assign(7, 100);
  std::cout << "before first size: " << first.size() << std::endl;
  std::cout << "before first capacity: " << first.capacity() << std::endl;
  std::vector<int>::iterator it = first.begin() + 1;
  first.assign(it, first.end() - 1);
  std::cout << "after first size: " << first.size() << std::endl;
  std::cout << "after first capacity: " << first.capacity() << std::endl;
  return 0;
}
