#include <iostream>
#include <chrono>
#include <thread>

int main(){
  //当前时间转换微妙
  std::chrono::time_point<std::chrono::system_clock> time_now =
      std::chrono::system_clock::now();
  int64_t time1 = std::chrono::duration_cast<std::chrono::milliseconds>(
      time_now.time_since_epoch()).count();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  time_now = std::chrono::system_clock::now();
  int64_t time2 = std::chrono::duration_cast<std::chrono::milliseconds>(
      time_now.time_since_epoch()).count();
  std::cout << "time1: " << time1 << std::endl;
  std::cout << "time2: " << time2 << std::endl;
  std::cout << "time2 - time1: " << time2 - time1<< std::endl;
  std::cout << "-----------------------" << std::endl;
  //当前时间转换毫秒
  std::chrono::time_point<std::chrono::system_clock> time_now2 =
      std::chrono::system_clock::now();
  int64_t time3 = std::chrono::duration_cast<std::chrono::seconds>(
      time_now2.time_since_epoch()).count();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  time_now2 = std::chrono::system_clock::now();
  int64_t time4 = std::chrono::duration_cast<std::chrono::seconds>(
      time_now2.time_since_epoch()).count();
  std::cout << "time3: " << time3 << std::endl;
  std::cout << "time4: " << time4 << std::endl;
  std::cout << "time4 - time3: " << time4 - time3 << std::endl;
  std::cout << "-----------------------" << std::endl;
  //当前时间转换分钟
  std::chrono::time_point<std::chrono::system_clock> time_now3 =
      std::chrono::system_clock::now();
  int64_t time5 = std::chrono::duration_cast<std::chrono::minutes>(
      time_now3.time_since_epoch()).count();
  std::this_thread::sleep_for(std::chrono::minutes(2));
  time_now3 = std::chrono::system_clock::now();
  int64_t time6 = std::chrono::duration_cast<std::chrono::minutes>(
      time_now3.time_since_epoch()).count();
  std::cout << "time5: " << time5 << std::endl;
  std::cout << "time6: " << time6 << std::endl;
  std::cout << "time6 - time5: " << time6 - time5 << std::endl;

  return 0;
}
