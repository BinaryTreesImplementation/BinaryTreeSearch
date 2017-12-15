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



/* insert left child
  
       5        ---+7---->      5  
                                  \
                                    7



*/

TEST_CASE("insert_rightCh", "[insRight]") {
  
  BST<int> test;
  
  test.insert(5);
  test.insert(7);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getLeftKey(5) == nullptr);
   REQUIRE(*test.getRightKey(5) == 7);
   REQUIRE(test.getParentKey(5) == nullptr);
  
   REQUIRE(*test.getParentKey(7) == 5);
   REQUIRE(test.getLeftKey(7) == nullptr);
   REQUIRE(test.getRightKey(7) == nullptr);
  
   REQUIRE(test.get_count() == 2);
}



/* insert left and right children
  
       5        ---+3 +7---->       5  
                                   /  \
                                 3      7



*/

TEST_CASE("insert_2_LR_child", "[ins2]") {
  
  BST<int> test;
  
  test.insert(5);
  test.insert(3);
  test.insert(7);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(*test.getLeftKey(5) == 3);
   REQUIRE(*test.getRightKey(5) == 7);
   REQUIRE(test.getParentKey(5) == nullptr);
  
   REQUIRE(*test.getParentKey(7) == 5);
   REQUIRE(test.getLeftKey(7) == nullptr);
   REQUIRE(test.getRightKey(7) == nullptr);
  
   REQUIRE(*test.getParentKey(3) == 5);
   REQUIRE(test.getLeftKey(3) == nullptr);
   REQUIRE(test.getRightKey(3) == nullptr);
  
   REQUIRE(test.get_count() == 3);
}



/* insert left child with left parent
  
       5        ---+3 +7---->       5  
                                   /  
                                 3      
                                /
                               1



*/

TEST_CASE("insert_left_left", "[insLL]") {
  
  BST<int> test;
  
  test.insert(5);
  test.insert(3);
  test.insert(1);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(*test.getLeftKey(5) == 3);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.getParentKey(5) == nullptr);
  
   REQUIRE(*test.getParentKey(3) == 5);
   REQUIRE(*test.getLeftKey(3) == 1);
   REQUIRE(test.getRightKey(3) == nullptr);
  
   REQUIRE(*test.getParentKey(1) == 3);
   REQUIRE(test.getLeftKey(1) == nullptr);
   REQUIRE(test.getRightKey(1) == nullptr);
  
   REQUIRE(test.get_count() == 3);
}



/* insert left and right children with left parent/ left and right children with right parent
  
       5        ---+3 +7---->        5  
                                   /   \ 
                                3         7
                               / \       / \
                              1   4     6   10



*/

TEST_CASE("insert_2left2right", "[ins2L2R]") {
  
  BST<int> test;
  
  test.insert(5);
  test.insert(3);
  test.insert(1);
  test.insert(4);
  test.insert(7);
  test.insert(6);
  test.insert(10);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(*test.getLeftKey(5) == 3);
   REQUIRE(*test.getRightKey(5) == 7);
   REQUIRE(test.getParentKey(5) == nullptr);
  
   REQUIRE(*test.getParentKey(3) == 5);
   REQUIRE(*test.getLeftKey(3) == 1);
   REQUIRE(*test.getRightKey(3) == 4);
  
   REQUIRE(*test.getParentKey(1) == 3);
   REQUIRE(test.getLeftKey(1) == nullptr);
   REQUIRE(test.getRightKey(1) == nullptr);
  
   REQUIRE(*test.getParentKey(4) == 3);
   REQUIRE(test.getLeftKey(4) == nullptr);
   REQUIRE(test.getRightKey(4) == nullptr);
  
   REQUIRE(*test.getParentKey(7) == 5);
   REQUIRE(*test.getLeftKey(7) == 6);
   REQUIRE(*test.getRightKey(7) == 10);
  
   REQUIRE(*test.getParentKey(6) == 7);
   REQUIRE(test.getLeftKey(6) == nullptr);
   REQUIRE(test.getRightKey(6) == nullptr);
  
   REQUIRE(*test.getParentKey(10) == 7);
   REQUIRE(test.getLeftKey(10) == nullptr);
   REQUIRE(test.getRightKey(10) == nullptr);
  
   REQUIRE(test.get_count() == 7);
}



TEST_CASE("remove root", "[rr]") {
   BST<int> test;
   test.insert(5);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.get_count() == 1);

   test.remove(5); 
   REQUIRE(test.getKeyRoot() == nullptr);
   REQUIRE(test.get_count() == 0);
  
}


/*   remove left child

        5
       /    --------(-3)---->        5
     3

*/


TEST_CASE("remove left child", "[removeLeft]") {
   BST<int> test;
   test.insert(5);
   test.insert(3);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(*test.getLeftKey(5) == 3);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.get_count() == 2);

   test.remove(3); 
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getLeftKey(5) == nullptr);
   REQUIRE(test.get_count() == 1);
}



/*   remove left child

        5
         \    --------(-7)---->        5
          7

*/


TEST_CASE("remove right child", "[removeLeft]") {
   BST<int> test;
   test.insert(5);
   test.insert(7);
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getLeftKey(5) == nullptr);
   REQUIRE(*test.getRightKey(5) == 7);
   REQUIRE(test.get_count() == 2);

   test.remove(7); 
   REQUIRE(*test.getKeyRoot() == 5);
   REQUIRE(test.getRightKey(5) == nullptr);
   REQUIRE(test.get_count() == 1);
}
