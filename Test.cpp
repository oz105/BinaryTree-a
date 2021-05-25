#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/BinaryTree.hpp"

using namespace std;
using namespace ariel;



TEST_CASE("check root on int and char"){
    
    //check char

    CHECK_NOTHROW(BinaryTree<char> c);
    BinaryTree<char> bt_char;

    CHECK_NOTHROW (bt_char.add_root('a'));
    CHECK_EQ('a',*bt_char.begin_preorder());
    //try to change the root after there is one
    CHECK_NOTHROW (bt_char.add_root('b'));
    CHECK_EQ('b',*bt_char.begin_preorder());


    CHECK_NOTHROW(BinaryTree<int> b);
    BinaryTree<int> bt_int;

    CHECK_NOTHROW (bt_int.add_root(10));
    CHECK_EQ(10,*bt_int.begin_preorder());
    //try to change the root after there is one
    CHECK_NOTHROW (bt_int.add_root(15));
    CHECK_EQ(15,*bt_int.begin_preorder());

}

TEST_CASE("check add left on int and char"){
    CHECK_NOTHROW(BinaryTree<char> c);
    BinaryTree<char> bt_char;
    CHECK_THROWS(bt_char.add_left('a','b')); // there is no root should throw err
    bt_char.add_root('a');
    CHECK_NOTHROW(bt_char.add_left('a','b'));
    CHECK_EQ('b',*bt_char.begin_inorder());
    CHECK_NOTHROW(bt_char.add_left('a','d'));
    CHECK_EQ('d',*bt_char.begin_inorder());
    CHECK_NOTHROW(bt_char.add_left('d','e'));
    CHECK_THROWS(bt_char.add_left('z','b')); // there is no data of 'z' int the tree should throw err


    CHECK_NOTHROW(BinaryTree<int> c);
    BinaryTree<int> bt_int;
    CHECK_THROWS(bt_int.add_left(0,1)); // there is no root should throw err
    bt_int.add_root(0);
    CHECK_NOTHROW(bt_int.add_left(0,1));
    int x = *bt_int.begin_inorder();
    CHECK_EQ(1,*bt_int.begin_inorder());
    CHECK_NOTHROW(bt_int.add_left(0,3));
    CHECK_EQ(3,*bt_int.begin_inorder());
    CHECK_NOTHROW(bt_int.add_left(3,6));
    CHECK_THROWS(bt_int.add_left(100,2)); // there is no data of 100 int the tree should throw err

}


TEST_CASE("check add right on int and char"){
    CHECK_NOTHROW(BinaryTree<char> c);
    BinaryTree<char> bt_char;
    CHECK_THROWS(bt_char.add_right('a','b')); // there is no root should throw err
    bt_char.add_root('a');
    CHECK_NOTHROW(bt_char.add_right('a','b'));
    // CHECK_EQ('b',*bt_char.begin_postorder());
    CHECK_NOTHROW(bt_char.add_right('a','d'));
    // CHECK_EQ('d',*bt_char.begin_postorder());
    CHECK_NOTHROW(bt_char.add_right('d','e'));
    CHECK_THROWS(bt_char.add_right('z','b')); // there is no data of 'z' int the tree should throw err


    CHECK_NOTHROW(BinaryTree<int> c);
    BinaryTree<int> bt_int;
    CHECK_THROWS(bt_int.add_right(0,1)); // there is no root should throw err
    bt_int.add_root(1);
    CHECK_NOTHROW(bt_int.add_right(0,1));
    // CHECK_EQ(1,*bt_int.begin_postorder());
    CHECK_NOTHROW(bt_int.add_right(0,3));
    CHECK_EQ(3,*bt_int.begin_postorder());
    CHECK_NOTHROW(bt_int.add_right(3,6));
    CHECK_THROWS(bt_int.add_right(100,2)); // there is no data of 100 int the tree should throw err

}

TEST_CASE ("iterators - inorder"){
    BinaryTree<int> bt_int;
    int res = 1 ;
    CHECK_NOTHROW (bt_int.add_root(1));
    CHECK_NOTHROW (bt_int.add_right(1,2));
    CHECK_NOTHROW (bt_int.add_left(1,3));
    /**   tree 
     *     1
     *    / \
     *   3   2 
     * 1 + 1/3 =(4/3)  
     * 4/3 + 4/3/1 = 8/3 
     * 8/3 + 8/3/2 = 4
    */

    for(auto val : bt_int ){ //should be inorder so 3 -> 1 -> 2 
        res = res + res/val ;
    }
    CHECK_EQ(4,res);

    BinaryTree<char> bt_char;
    string ans = "" ;
    CHECK_NOTHROW (bt_char.add_root('a'));
    CHECK_NOTHROW (bt_char.add_left('a','b'));
    CHECK_NOTHROW (bt_char.add_right('a','c'));
    /**   tree 
     *     a
     *    / \
     *   b   c
    */
   for(auto it = bt_char.begin_inorder();it!=bt_char.end_inorder(); ++it){
        ans = ans + *it;
   }
   CHECK_EQ("bac",ans);

}








