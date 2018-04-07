#include <iostream>
#include <string>
#include <map>

bool fncomp(char lhs, char rhs) {
  return lhs < rhs;
}

struct classcomp {
  bool operator()(const char& lhs, const char& rhs) const {
    return lhs < rhs;
  }

};

int main(){

  //构造函数
  std::map<char, int> first;
  first['a'] = 10;
  first['b'] = 30;
  first['c'] = 50;
  first['d'] = 70;

  std::map<char, int> second(first.begin(), first.end());
  std::map<char, int> third(second);
  std::map<char, int, classcomp> fourth;

  bool (*fn_pt)(char, char) = fncomp;
  std::map<char, int, bool(*)(char, char)> fifth(fn_pt);
  //----------------------------------
  //元素访问
  std::map<char, std::string> mymap;
  mymap['a'] = "an element";
  mymap['b'] = "another element";
  mymap['c'] = mymap['b'];

  std::cout << "mymap['a'] is: " << mymap['a'] << std::endl;
  std::cout << "mymap['b'] is: " << mymap['b'] << std::endl;
  std::cout << "mymap['c'] is: " << mymap['c'] << std::endl;
  std::cout << "mymap['d'] is: " << mymap['d'] << std::endl;
  std::cout << "mymap now contains: " << mymap.size() << std::endl;

  std::map<std::string, int> mymap2 = {
    {
      "alaha", 0
    },
    {
      "beta", 0
    },
    {
      "gamma", 0
    }
  };
  mymap2.at("alaha") = 10;
  mymap2.at("beta") = 20;
  mymap2.at("gamma") = 30;
  for( auto& x : mymap2){
    std::cout << x.first << ":" << x.second << std::endl;
  }
  //----------------------------------
  //修改容器 insert
  std::map<char, int> mymap3;
  mymap3.insert(std::pair<char,int>('a', 100));
  mymap3.insert(std::pair<char,int>('z', 200));
  std::pair<std::map<char,int>::iterator, bool> ret;

  ret = mymap3.insert(std::pair<char, int>('z', 500));
  if(ret.second == false){
    std::cout << "element 'z' already existed";
    std::cout << "with a value of" << ret.first->second << std::endl;
  }
  std::map<char, int>::iterator it = mymap3.end();
  mymap3.insert(it, std::pair<char, int>('b', 300));
  mymap3.insert(it, std::pair<char, int>('c', 400));
  std::map<char, int> anothermap;
  anothermap.insert(mymap3.begin(), mymap3.find('c'));
  std::cout << "mymap contains: " << std::endl;
  for(it = mymap3.begin(); it != mymap3.end(); ++it){
    std::cout << it->first << ":" << it->second << std::endl;
  }
  std::cout << "another contains: " << std::endl;
  for(it = anothermap.begin(); it != anothermap.end(); ++it){
    std::cout << it->first << ":" << it->second << std::endl;
  }
  //修改容器 erase
  std::map<char, int> mymap4;
  std::map<char, int>::iterator it4;
  mymap4['a'] = 10;
  mymap4['b'] = 20;
  mymap4['c'] = 30;
  mymap4['d'] = 40;
  mymap4['e'] = 50;
  mymap4['f'] = 60;
  it4 = mymap4.find('b');
  mymap4.erase(it4);
  mymap4.erase('c');
  it4 = mymap4.find('e');
  mymap4.erase(it4, mymap4.end());
  for(it4 = mymap4.begin(); it4 != mymap4.end(); ++it4){
    std::cout << it4->first << ":" << it4->second << std::endl;
  }
  return 0;
}

