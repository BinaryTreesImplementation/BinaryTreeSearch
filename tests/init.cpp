#include <BST.hpp>
#include <catch.hpp>

TEST_CASE("insert_root", "[root]") {
  
  BST<int> test;
  
  test.insert(5);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getLeftKey(5) == nullptr);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.getParentKey(5) == nullptr);
   REQUIRE(test.getCount() == 1);
}
