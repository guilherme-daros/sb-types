#include <gtest/gtest.h>
#include <string_view>

using namespace std::string_view_literals;

#include "types/StringLiteral.hpp"

template <sb::types::StringLiteral domain>
struct Helper {
  static consteval auto get_domain() { return domain.data; }
};

TEST(StringLiteral, AsTemplateParameter) {
  using H = Helper<"Help">;

  ASSERT_EQ(H::get_domain(), "Help"sv);
}
