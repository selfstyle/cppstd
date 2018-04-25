#include <iostream>
#include <string>

int main(){
  //stoi
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;

  int i_dec = std::stoi(str_dec, &sz);
  int i_hex = std::stoi(str_hex, nullptr, 16);
  int i_bin = std::stoi(str_bin, nullptr, 2);
  int i_auto = std::stoi(str_auto,nullptr, 0);

  std::cout << str_dec << ":" << i_dec << "and [" << str_dec.substr(sz) << "]" << std::endl;
  std::cout << str_hex << ":" << i_hex << std::endl;
  std::cout << str_bin << ":" << i_bin << std::endl;
  std::cout << str_auto << ":" << i_auto << std::endl;
  //--
  //to_string
  std::string pi = "pi is " + std::to_string(3.1415926);
  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
  std::cout << pi << std::endl;
  std::cout << perfect << std::endl;
  return 0;
}
