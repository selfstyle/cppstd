#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> stringmap;

stringmap merge(stringmap a, stringmap b){
  stringmap temp(a);
  temp.insert(b.begin(), b.end());
  return temp;
}

int main(){
  //构造函数
  stringmap first;
  stringmap second({
                   { "apple", "red"},
                   { "lemon", "yellow"},
                   });
  stringmap third({
                   { "orange", "orange"},
                   { "strawberry", "red"},
                   });
  stringmap fourth(second);
  stringmap fifth(merge(third, fourth));
  stringmap sixth(fifth.begin(), fifth.end());

  std::cout << "sixth contains: " << std::endl;
  for (auto& x : sixth){
    std::cout << " " << x.first << ":" << x.second;
  }
  std::cout << std::endl;
  //--------------------
  //capacity
  std::unordered_map<int, int> first2;
  std::unordered_map<int, int> second2 = {
    {1,10},{2,20},{3,30}
  };
  std::cout << "first2" << (first2.empty() ? "is empty" : "is not empty") << std::endl;
  std::cout << "second2" << (second2.empty() ? "is empty" : "is not empty") << std::endl;
  std::cout << "second2.size() is: " << second2.size()<< std::endl;
  std::cout << "max_size = " << second2.max_size() << std::endl;
  std::cout << "max_bucket_count = " << second2.max_bucket_count() << std::endl;
  std::cout << "max_load_factor = " << second2.max_load_factor() << std::endl;
  //------------------
  //element lookup
  std::unordered_map<std::string, double> mymap = {
    {"mom", 5.4},
    {"dad", 6.4},
    {"bro", 5.9}
  };
  std::string input;
  std::cout << "who ?" << std::endl;
  //getline(std::cin, input);
  input = "mom";
  std::unordered_map<std::string, double>::const_iterator got = mymap.find(input);
  if(got == mymap.end()){
    std::cout << "not found";
  }else
    std::cout << got->first << " is " << got->second;
  std::cout << std::endl;

  std::unordered_map<std::string, double> mymap2 = {
    {"Burger", 2.99},
    {"Fries", 1.99},
    {"Soda", 1.50}
  };

  for(auto& x : {"Burger", "Pizza", "Salad", "Soda"}){
    if(mymap2.count(x) > 0)
      std::cout << "mymap2 has " << x << std::endl;
    else
      std::cout << "mymap2 has no" << x << std::endl;
  }
  //-----------------------
  //bucket
  std::unordered_map<std::string, std::string> mymap3 = {
    {"house", "maison"},
    {"apple", "pomme"},
    {"tree", "arbre"},
    {"book", "livre"},
    {"door", "porte"},
    {"grapefruit", "pamplemoussse"}
  };
  std::cout << "-------------------------------------" << std::endl;
  unsigned n = mymap3.bucket_count();
  std::cout << "mymap3 bucket_count " << n << std::endl;
  std::cout << "mymap3 max_bucket_count " << mymap3.max_bucket_count() << std::endl;
  std::cout << "mymap3 load_factor " << mymap3.load_factor() << std::endl;
  std::cout << "mymap3 max_load_factor " << mymap3.max_load_factor() << std::endl;

  for(unsigned i = 0; i < n ; ++i){
    std::cout << "bucket # " << i << " contains: " << std::endl;
    std::cout << "bucket # " << i << " has " << mymap3.bucket_size(i) << " element" << std::endl;
    for (auto it = mymap3.begin(i); it != mymap3.end(i); ++it){
      std::cout << "[" << it->first << ":" << it->second << "]";
    }
    std::cout << std::endl;
  }
  //----------------------
  //Hash policy
  std::cout << "-------------------------------" << std::endl;
  std::unordered_map<int, int> mymap4;
  std::cout << "size = " << mymap4.size() << std::endl;
  std::cout << "bucket_count = " << mymap4.bucket_count() << std::endl;
  std::cout << "load_factor = " << mymap4.load_factor() << std::endl;
  std::cout << "max_load_factor = " << mymap4.max_load_factor() << std::endl;
  return 0;

}
