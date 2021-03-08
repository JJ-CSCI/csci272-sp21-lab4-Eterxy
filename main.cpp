//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {
  int Cone;
  int Ctwo;
public:
  Complex():Cone{0}, Ctwo{0}{}
  Complex(int one):Cone{0}, Ctwo{0} {
    Cone = one;
  }
  Complex(int one, int two): Cone{0}, Ctwo{0}{
    Cone = one;
    Ctwo = two;
  }
  int re(){
    return Cone;
  }
  int im(){
    return Ctwo;
  }
  void operator>>(std::string& s) const{
    s += std::to_string(Cone);
    if (Ctwo < 0){
      s += std::to_string(Ctwo);
    }
    else{
      s += '+';
      s += std::to_string(Ctwo);
    }
    s += 'i';
  }
  void operator<<(const std::string& a){
    std::string b;
    b = a;
    Cone = std::stoi(a);
    if (Cone < 0){
      b.erase(0,2);
    }
    else{
      b.erase(0,1);
    }
    Ctwo = std::stoi(b);
  }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
