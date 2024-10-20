#include <gtest/gtest.h>
#include <cstdint>
#include "types/Singleton.hpp"

class Helper : public sb::types::Singleton<Helper> {
 public:
  auto set_value(uint32_t v) -> void { value_ = v; };
  auto get_value() -> uint32_t { return value_; }

 protected:
  Helper() {}

 private:
  uint32_t value_;
};

TEST(Singleton, WithValue) {
  auto& ref1 = Helper::Instance();
  auto& ref2 = Helper::Instance();

  ref1.set_value(42);

  ASSERT_EQ(42, ref2.get_value());
}
