#include "snowman.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;

    string nospaces(string input)
{
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

/* body part list: (each part, has 4 options)
    1. hat
        1. Straw Hat - _===_
        2. Mexican Hat -  ___ 
                         .....
        3. Fez -   _  
                  /_\ 
        4. Russian Hat - ___ 
                        (_*_)
    2. nose/mouth
        1. Normal ,
        2. Dot .
        3. Line _
        4. None
    3. left eye
        1. Dot .
        2. Bigger Dot o
        3. Biggest Dot O
        4. Closed -
    4. right eye
        1. Dot - .
        2. Bigger Dot - o
        3. Biggest Dot - O
        4. Closed - -
    5. left arm
        1. Normal Arm - < 
        2. Upwards Arm - \
        3. Downwards Arm - /
        4. None
    6. right arm
        1. Normal Arm - > 
        2. Upwards Arm - /
        3. Downwards Arm - \
        4. None
    7. torso
        1. Buttons - : 
        2. Vest - ] [
        3. Inward Arms - > <
        4. None    
    8. base 
        1. Buttons - : 
        2. Feet - " "
        3. Flat - ___
        4. None     
        
        
        
        */
    

TEST_CASE("wrong input - number length too long")
{
    CHECK_THROWS(snowman(123442413)); // 9 digits long. should fail.
}

TEST_CASE("wrong input - number length too small")
{
    CHECK_THROWS(snowman(2));
    CHECK_THROWS(snowman(24));
    CHECK_THROWS(snowman(234));
    CHECK_THROWS(snowman(2341));
    CHECK_THROWS(snowman(23413));
    CHECK_THROWS(snowman(234132));
    CHECK_THROWS(snowman(2341321));
}


TEST_CASE("wrong input - wrong hat index")
{
    CHECK_THROWS(snowman(52341234));
    CHECK_THROWS(snowman(02341234));
}

TEST_CASE("wrong input - wrong nose index")
{
    CHECK_THROWS(snowman(16341234));
    CHECK_THROWS(snowman(10341234));

}

TEST_CASE("wrong input - wrong left eye index")
{
    CHECK_THROWS(snowman(12741234));
    CHECK_THROWS(snowman(12041234));

}

TEST_CASE("wrong input - wrong right eye index")
{
    CHECK_THROWS(snowman(12381234));
    CHECK_THROWS(snowman(12301234));
}

TEST_CASE("wrong input - wrong left arm index")
{
    CHECK_THROWS(snowman(12349234));
    CHECK_THROWS(snowman(12340234));

}

TEST_CASE("wrong input - wrong right arm index")
{
    CHECK_THROWS(snowman(12341834));
    CHECK_THROWS(snowman(12341034));
}

TEST_CASE("wrong input - wrong torso index")
{
    CHECK_THROWS(snowman(12341274));
    CHECK_THROWS(snowman(12341204));
}

TEST_CASE("wrong input - wrong base index")
{
    CHECK_THROWS(snowman(12341236));
    CHECK_THROWS(snowman(12341230));
}

TEST_CASE("good snowman code input")
{
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_ (.,.)<( : )> ( : )"));
}

TEST_CASE("good input - hat indexs")
{
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_ (.,.)<( : )> ( : )"));

    CHECK(nospaces(snowman(21111111)) == nospaces("  ___ ..... (.,.)<( : )> ( : )"));

    CHECK(nospaces(snowman(31111111)) == nospaces("   _    /_\\ (.,.)<( : )> ( : )"));

    CHECK(nospaces(snowman(41111111)) == nospaces("  ___ (_*_) (.,.)<( : )> ( : )"));
}

TEST_CASE("good input - nose indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(12111111)) == " _===_ (...)<( : )> ( : )");
    
    CHECK(nospaces(snowman(13111111)) == " _===_ (._.)<( : )> ( : )");

    CHECK(nospaces(snowman(14111111)) == " _===_ (. .)<( : )> ( : )");
}

TEST_CASE("good input - left eye indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11211111)) == " _===_ (o,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11311111)) == " _===_ (O,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11411111)) == " _===_ (-,.)<( : )> ( : )");
}

TEST_CASE("good input - right eye indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11121111)) == " _===_ (.,o)<( : )> ( : )");

    CHECK(nospaces(snowman(11131111)) == " _===_ (.,O)<( : )> ( : )");

    CHECK(nospaces(snowman(11141111)) == " _===_ (.,-)<( : )> ( : )");
}

TEST_CASE("good input - left arm indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11112111)) == " _===_\\(.,.) ( : )> ( : )");

    CHECK(nospaces(snowman(11113111)) == " _===_ (.,.)/( : )> ( : )");

    CHECK(nospaces(snowman(11114111)) == " _===_ (.,.) ( : )> ( : )"); 
}

TEST_CASE("good input - right arm indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11111211)) == " _===_ (.,.)/<( : ) ( : )");

    CHECK(nospaces(snowman(11111311)) == " _===_ (.,.)<( : )\\ ( : )");

    CHECK(nospaces(snowman(11111411)) == " _===_ (.,.)<( : )  ( : )");
}

TEST_CASE("good input - torso indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11111121)) == " _===_ (.,.)<(] [)> ( : )");

    CHECK(nospaces(snowman(11111131)) == " _===_ (.,.)<(> <)> ( : )");

    CHECK(nospaces(snowman(11111141)) == " _===_ (.,.)<(   )> ( : )");
} 

TEST_CASE("good input - base indexs")
{
    CHECK(nospaces(snowman(11111111)) == " _===_ (.,.)<( : )> ( : )");

    CHECK(nospaces(snowman(11111112)) == " _===_ (.,.)<( : )> (\" \")");

    CHECK(nospaces(snowman(11111113)) == " _===_ (.,.)<( : )> (___)");

    CHECK(nospaces(snowman(11111114)) == " _===_ (.,.)<( : )> (   )");
}
