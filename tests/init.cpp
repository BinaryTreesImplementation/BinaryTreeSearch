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


/*

              6
	    /	\						6 ------ 10   (the same level)
	   /     \					       /        /  \
	  2	  8  --- 16 			-->>          2        8    16 
                         /  (the same level)  
			10  
*/

TEST_CASE("insert3", "[ins3]") {
	AATree<int> test;
	test.insert(6);
	test.insert(2);
	test.insert(8);
	test.insert(16);
	test.insert(10);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getcount() == 5);
	REQUIRE(test.getroot() != 0);
	REQUIRE(*test.getLevel(6) == 2);
	REQUIRE(*test.getLevel(10) == 2);
	REQUIRE(*test.getLevel(2) == 1);
	REQUIRE(*test.getLevel(8) == 1);
	REQUIRE(*test.getLevel(16) == 1);
	REQUIRE(*test.getLeftKey(6) == 2);
        REQUIRE(*test.getRightKey(6) == 10);
	REQUIRE(*test.getLeftKey(10) == 8);
        REQUIRE(*test.getRightKey(10) == 16);
	REQUIRE(*test.getLeftKey(2) == 2);
        REQUIRE(*test.getRightKey(2) == 2);
	REQUIRE(*test.getLeftKey(8) == 8);
        REQUIRE(*test.getRightKey(8) == 8);
	REQUIRE(*test.getLeftKey(16) == 16);
        REQUIRE(*test.getRightKey(16) == 16);
}


/*

              
	     6 ------ 10                       6 ------- 10
	    /        /  \      ----->        /          /  \
    1 ---- 2        8    16                 1 -- 2     8    16
    

*/

TEST_CASE("insert4", "[ins4]") {
	AATree<int> test;
	test.insert(6);
	test.insert(2);
	test.insert(8);
	test.insert(16);
	test.insert(10);
	test.insert(1);
	REQUIRE(*test.getKeyRoot() == 6);
	REQUIRE(test.getcount() == 6);
	REQUIRE(test.getroot() != 0);
	REQUIRE(*test.getLevel(6) == 2);
	REQUIRE(*test.getLevel(10) == 2);
	REQUIRE(*test.getLevel(2) == 1);
	REQUIRE(*test.getLevel(8) == 1);
	REQUIRE(*test.getLevel(16) == 1);
	REQUIRE(*test.getLevel(1) == 1);
	REQUIRE(*test.getLeftKey(6) == 1);
        REQUIRE(*test.getRightKey(6) == 10);
	REQUIRE(*test.getLeftKey(10) == 8);
        REQUIRE(*test.getRightKey(10) == 16);
	REQUIRE(*test.getLeftKey(2) == 2);
        REQUIRE(*test.getRightKey(2) == 2);
	REQUIRE(*test.getLeftKey(8) == 8);
        REQUIRE(*test.getRightKey(8) == 8);
	REQUIRE(*test.getLeftKey(16) == 16);
        REQUIRE(*test.getRightKey(16) == 16);
	REQUIRE(*test.getLeftKey(1) == 1);
        REQUIRE(*test.getRightKey(1) == 2);
}


TEST_CASE("remove root", "[root]") {
   AATree<int> test;
   test.insert(15);
   test.remove(15);      
   REQUIRE(test.getcount() == 0);
}

/*
      6                         
    /   \      (-2) ----->      6 -> 8 
   2     8   

*/
TEST_CASE("remove_1", "[r1]") {
   AATree<int> test;
   test.insert(6);
   test.insert(2);  
   test.insert(8);
   REQUIRE(test.getcount() == 3);
   REQUIRE(*test.getLevel(6) == 2);
   REQUIRE(*test.getLevel(2) == 1);
   REQUIRE(*test.getLevel(8) == 1);
   REQUIRE(*test.getLeftKey(6) == 2);
   REQUIRE(*test.getRightKey(6) == 8);
   REQUIRE(*test.getLeftKey(2) == 2);
   REQUIRE(*test.getRightKey(2) == 2);
   REQUIRE(*test.getLeftKey(8) == 8);
   REQUIRE(*test.getRightKey(8) == 8);
   
   test.remove(2);
   REQUIRE(test.getcount() == 2);
   REQUIRE(*test.getLevel(6) == 1);
   REQUIRE(*test.getLevel(2) == 0);
   REQUIRE(*test.getLevel(8) == 1);
   REQUIRE(*test.getLeftKey(6) == 6);
   REQUIRE(*test.getRightKey(6) == 8);
   REQUIRE(*test.getLeftKey(8) == 8);
   REQUIRE(*test.getRightKey(8) == 8);
}


/*
      6                         
    /   \      (-8) ----->      2 -> 6 
   2     8   

*/
TEST_CASE("remove_2", "[r2]") {
   AATree<int> test;
   test.insert(6);
   test.insert(2);  
   test.insert(8);
   
   test.remove(8);
   REQUIRE(test.getcount() == 2);
   REQUIRE(*test.getLevel(6) == 1);
   REQUIRE(*test.getLevel(2) == 1);
   REQUIRE(*test.getLevel(8) == 0);
   REQUIRE(*test.getLeftKey(6) == 6);
   REQUIRE(*test.getRightKey(6) == 6);
   REQUIRE(*test.getLeftKey(2) == 2);
   REQUIRE(*test.getRightKey(2) == 6);
}


