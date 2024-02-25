#include "src/specc.h"
#include "../headers/Vec.hpp"

module(vector, {
  describe("distance",{
    it("2d",{
      should_eq(0,vec::dist(Vec2f(),Vec2f()),float);
      should_eq(1,vec::dist(Vec2f(),Vec2f(1,0)),float);
      should_float_eq(sqrt(2),vec::dist(Vec2f(),Vec2f(1,1)),0.01);
    });

    it("3d",{
      should_eq(0,vec::dist(Vec3f(),Vec3f()),float);
      should_eq(1,vec::dist(Vec3f(),vec::i),float);
      should_float_eq(sqrt(3),vec::dist(Vec3f(),Vec3f(1,1,1)),0.01);
    });
  });

  describe("normal",{
    it("2d",{
      should_eq(Vec2f(1,0),vec::normal(Vec2f()),Vec2f);
      should_eq(Vec2f(1,0),vec::normal(Vec2f(2,0)),Vec2f);
      should_eq(Vec2f(0,1),vec::normal(Vec2f(0,1)),Vec2f);
      should_eq(Vec2f(M_SQRT1_2,M_SQRT1_2),vec::normal(Vec2f(1,1)),Vec2f);
    });

    it("3d",{
      should_eq(vec::i,vec::normal(Vec3f()),Vec3f);
      should_eq(vec::i,vec::normal(Vec3f(2,0,0)),Vec3f);
      should_eq(Vec3f(0,1,0),vec::normal(Vec3f(0,1,0)),Vec3f);
      should_eq(Vec3f(1/sqrt(3),1/sqrt(3),1/sqrt(3)),vec::normal(Vec3f(1,1,1)),Vec3f);
    });
  });

  describe("2d dot",{

    it("degenerate vecs", {
      float out = vec::dot({0,0},{0,0});
      should_eq(0,out,float);
      out = vec::dot({1,2},{0,0});
      should_eq(0,out,float);
    });

    it("non-degenerate vecs", {
      float out = vec::dot({1,1},{1,1});
      should_eq(2,out,float);
      out = vec::dot({1,2},{3,4});
      should_eq(11,out,float);
    });
  });

  describe("3d dot",{

    it("degenerate vecs", {
      float out = vec::dot({0,0,0},{0,0,0});
      should_eq(0,out,float);
      out = vec::dot({1,2,3},{0,0,0});
      should_eq(0,out,float);
    });

    it("non-degenerate vecs", {
      float out = vec::dot({1,1,1},{1,1,1});
      should_eq(3,out,float);
      out = vec::dot({1,2,3},{4,5,6});
      should_eq(32,out,float);
    });
  });

  describe("cross",{
    it("2d",{
      should_eq(Vec2f(),vec::cross(Vec2f()),Vec2f);
      should_eq(Vec2f(0,1),vec::cross(Vec2f(1,0)),Vec2f);
      should_eq(Vec2f(-1,0),vec::cross(Vec2f(0,1)),Vec2f);
    });

    it("3d",{
      should_eq(Vec3f(),vec::cross(Vec3f(),Vec3f()),Vec3f);
      should_eq(vec::k,vec::cross(vec::i,vec::j),Vec3f);
      should_eq(-vec::j,vec::cross(vec::i,vec::k),Vec3f);
    });
  });
});