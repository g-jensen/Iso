#include "src/specc.h"

#include "../headers/WavefrontObj.hpp"

module(wavefrontObj,{
  describe("parseObj",{
    it("parses a cube",{
      WavefrontObj obj = parseObj("specc/parseObj/numbered_cube.obj");
      should_eq(8,obj.vertices.size(),int);
      should_eq(Vec3f(1,1,-1),obj.vertices[0],Vec3f);
      should_eq(Vec3f(1,-1,-1),obj.vertices[1],Vec3f);
      should_eq(Vec3f(1,1,1),obj.vertices[2],Vec3f);
      should_eq(Vec3f(1,-1,1),obj.vertices[3],Vec3f);
      should_eq(Vec3f(-1,1,-1),obj.vertices[4],Vec3f);
      should_eq(Vec3f(-1,-1,-1),obj.vertices[5],Vec3f);
      should_eq(Vec3f(-1,1,1),obj.vertices[6],Vec3f);
      should_eq(Vec3f(-1,-1,1),obj.vertices[7],Vec3f);

      should_eq(6,obj.faces.size(),int);

      should_eq(1,obj.faces[0][0],int);
      should_eq(5,obj.faces[0][1],int);
      should_eq(7,obj.faces[0][2],int);
      should_eq(3,obj.faces[0][3],int);
    
      should_eq(4,obj.faces[1][0],int);
      should_eq(3,obj.faces[1][1],int);
      should_eq(7,obj.faces[1][2],int);
      should_eq(8,obj.faces[1][3],int);

      should_eq(8,obj.faces[2][0],int);
      should_eq(7,obj.faces[2][1],int);
      should_eq(5,obj.faces[2][2],int);
      should_eq(6,obj.faces[2][3],int);

      should_eq(6,obj.faces[3][0],int);
      should_eq(2,obj.faces[3][1],int);
      should_eq(4,obj.faces[3][2],int);
      should_eq(8,obj.faces[3][3],int);

      should_eq(2,obj.faces[4][0],int);
      should_eq(1,obj.faces[4][1],int);
      should_eq(3,obj.faces[4][2],int);
      should_eq(4,obj.faces[4][3],int);

      should_eq(6,obj.faces[5][0],int);
      should_eq(5,obj.faces[5][1],int);
      should_eq(1,obj.faces[5][2],int);
      should_eq(2,obj.faces[5][3],int);
    });
  });
});