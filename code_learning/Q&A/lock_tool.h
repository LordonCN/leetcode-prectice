#include <mutex>
#include <iostream>

namespace lockClass {
template<typename T>
class Locked {
 public:
  // Locked loc1;
  // Locked loc2(loc1);
  // Locked loc3(std::move(loc1));
  // 默认构造
  Locked() : lock_(), value_(), read_count_(0) {}
  // 拷贝构造 必须显式构造
  explicit Locked(const T& value) : lock_(), value_(value), read_count_(0) {}// 拷贝构造
  // 移动构造
  explicit Locked(T&& value) : lock_(), value_(std::move(value)), read_count_(0) {}//移动构造
  // 赋值构造 value作为左值进行赋值 为了防止value被改变所以加const
  // loc1 = loc3 = loc2;
  Locked<T>& operator= (const T& value) {
      lock();
      value_ = value;
      read_count_ = 0;
      unlock();
      return *this;
  }
  // 移动构造 value作为右值被使用
  // loc1 = std::move(loc3);
  Locked<T>& operator= (T&& value) {
      lock();
      value_ = std::move(value);
      read_count_ = 0;
      unlock();
      return *this;
  }
  ~Locked() = default;

  // 这里lock_guard更好一点 这样包装起来问题很大 因为析构没有检测是否锁住
  void lock() { lock_.lock(); }
  void unlock() { lock_.unlock(); }
  void write_lock() { lock_.lock(); }
  void write_unlock() { lock_.unlock(); }

  // 通过对锁与解锁的次数进行查询
  // 应该是测试用的
  void read_lock() {
    while (read_count_ == 0 &&
        !lock_.try_lock()) {
    }
    ++read_count_;
  }
  void read_unlock() {
    if (read_count_ > 0)
      --read_count_;
    if (read_count_ == 0)
      lock_.unlock();
  }
  bool try_lock() { return lock_.try_lock(); }

  const T& operator() () const {
    return value_;
  }
  T& operator() () {
    return value_;
  }


 private:
  T value_;
  std::mutex lock_;
  int read_count_;
};  // class Locked
}  //
#endif
