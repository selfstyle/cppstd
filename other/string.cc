#include <string>
#include <iostream>

int main(){
  //element access
  // front back
  /*
  std::string str("test string");
  str.front() = 'T';
  str.back() = 'G';
  std::cout << str << std::endl;
  */
  //Modifiers
  /*
  std::string str;
  std::string str2 = "Writing ";
  std::string str3 = "print 10 and then 5 more";

  str.append(str2);
  std::cout << str << std::endl;
  */
  //operations
  std::string str = "There are two needles in.";
  std::string str2 = "needles";
  std::size_t found = str.find(str2);
  if(found != std::string::npos){
    std::cout << "found: " << found << std::endl;
  }
  return 0;
}
