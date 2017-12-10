#include <AATree.hpp>
#include <catch.hpp>
TEST_CASE("insert_root", "[root]") {
	AATree<int> test;
	test.insert(6);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getcount() == 1);
//  	REQUIRE(test.getRoot() != 0);
	REQUIRE(*test.getLevel(6) == 1);
		
}
