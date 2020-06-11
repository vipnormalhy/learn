#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <iostream>

std::mutex mutex;
std::condition_variable produce_cond;
std::vector<int> shared_data;

class Consumer
{
public:
  void operator()()
  {
    while (true)
    {
      std::unique_lock lock(mutex);
      produce_cond.wait(lock, []() -> bool { return !shared_data.empty(); });
      std::cout << "receive message ==============================";
      int data = shared_data.back();
      shared_data.pop_back();
      std::cout << "get data " << data << std::endl;
    }
  }
};

class Producer
{
public:
  Producer() { m_index = 0; }
  void operator()()
  {
    while (true)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));

      {
        std::lock_guard lock(mutex);
        shared_data.emplace_back(m_index++);
        std::cout << "start notify one ++++++++++++++++++++++++++++++" << std::endl;
      }
      produce_cond.notify_one();
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "end notify one -------------------------------" << std::endl;
    }
  }

private:
  int m_index;
};

class Tester
{
  public:
    Tester() {};
    void operator()()
    {
      char test[19];
      memset(test, 0, 19);

      int *p = reinterpret_cast<int *>(test + 1);
      *p = 67898;
      int a = *(reinterpret_cast<int *>(test + 1));
      std::cout << "result is " << a << std::endl;
    }
};

int main()
{
  // Consumer c1, c2;
  Consumer c1;
  Producer p1, p2;
  Tester t1;

  std::thread t_c1(c1);
  // std::thread t_c2(c2);
  std::thread t_p1(p1);
  std::thread t_p2(p2);
  std::thread t_t1(t1);

  t_c1.join();
  // t_c2.join();
  t_p1.join();
  t_p2.join();
  t_t1.join();

  return 0;
}