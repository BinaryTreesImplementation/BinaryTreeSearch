#include <AATree.hpp>
#include <catch.hpp>
TEST_CASE("insert_root", "[root]") {
	AATree<int> test;
	at.insert(6);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getCount() == 1);
  	REQUIRE(test.getRoot() != 0);
	REQUIRE(test.getLevel() == 1);
		
}
