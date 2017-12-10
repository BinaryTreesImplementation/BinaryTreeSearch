#include <AATree.hpp>
#include <catch.hpp>
TEST_CASE("insert_root", "[root]") {
	AATree<int> test;
	test.insert(6);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getcount() == 1);
	REQUIRE(test.getroot() != 0);
	REQUIRE(*test.getLevel(6) == 1);
		
}
/*

              6
	    /	\
	  2	  8
*/

TEST_CASE("insert2", "[ins2]") {
	AATree<int> test;
	test.insert(6);
	test.insert(2);
	test.insert(8);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getcount() == 3);
	REQUIRE(test.getroot() != 0);
	REQUIRE(*test.getLevel(6) == 2);
	REQUIRE(*test.getLevel(2) == 1);
	REQUIRE(*test.getLevel(8) == 1);
	REQUIRE(*test.getLeftKey(6) == 2);
        REQUIRE(*test.getRightKey(6) == 8);
	REQUIRE(*test.getLeftKey(2) == 2);
        REQUIRE(*test.getRightKey(2) == 2);
	REQUIRE(*test.getLeftKey(8) == 8);
        REQUIRE(*test.getRightKey(8) == 8);
}
