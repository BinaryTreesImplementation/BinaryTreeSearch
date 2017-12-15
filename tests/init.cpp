#include <BST.hpp>
#include <catch.hpp>

TEST_CASE("insert_root", "[root]") {
  
  BST<int> test;
  
  test.insert(5);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getLeftKey(5) == nullptr);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.getParentKey(5) == nullptr);
   REQUIRE(test.get_count() == 1);
}

/* insert left child
  
       5        ---+3---->      5  
                               /
                              3



*/

TEST_CASE("insert_leftCh", "[insLeft]") {
  
  BST<int> test;
  
  test.insert(5);
  test.insert(3);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(*test.getLeftKey(5) == 3);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.getParentKey(5) == nullptr);
   REQUIRE(*test.getParentKey(3) == 5);
   REQUIRE(test.getLeftKey(3) == nullptr);
   REQUIRE(test.getRightKey(3) == nullptr);
   REQUIRE(test.get_count() == 2);
}
