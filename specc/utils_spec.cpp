#include "src/specc.h"

#include "../headers/utils.hpp"

module(utility,{
  describe("str_startsWith",{
    it("blank string",{
      should(utils::str_startsWith("",""));
      should_not(utils::str_startsWith("","greg"));
    });

    it("blank input",{
      should(utils::str_startsWith("greg",""));
    });
    
    it("populated string and single-character input",{
      should(utils::str_startsWith("greg","g"));
      should_not(utils::str_startsWith("greg","r"));
    });

    it("populated string and multi-character input",{
      should(utils::str_startsWith("iwosens","iwos"));
      should_not(utils::str_startsWith("iwosens","jwos"));
    });

    it("identical string and input",{
      should(utils::str_startsWith("greg","greg"));
    });
  });

  describe("splits a string",{
    it("with zero length",{
      auto split = utils::str_split("",'s');
      should_eq(0,split.size(),int);
    });

    it("that doesn't contain delimiter",{
      auto split = utils::str_split("hello",'s');
      should_eq(1,split.size(),int);
      should_eq("hello",split[0],std::string);
    });

    it("that only contains delimiter",{
      auto split = utils::str_split("s",'s');
      should_eq(1,split.size(),int);
      should_eq("",split[0],std::string);
    });

    it("with first character delimiter",{
      auto split = utils::str_split("hello",'h');
      should_eq(2,split.size(),int);
      should_eq("",split[0],std::string);
      should_eq("ello",split[1],std::string);
    });

    it("with delimiter in middle",{
      auto split = utils::str_split("hello",'e');
      should_eq(2,split.size(),int);
      should_eq("h",split[0],std::string);
      should_eq("llo",split[1],std::string);
    });

    it("with multiple instances of delimiter",{
      auto split = utils::str_split("hellohello",'e');
      should_eq(3,split.size(),int);
      should_eq("h",split[0],std::string);
      should_eq("lloh",split[1],std::string);
      should_eq("llo",split[2],std::string);
    });

    it("with multiple delimiters in a row",{
      auto split = utils::str_split("hello",'l');
      should_eq(3,split.size(),int);
      should_eq("he",split[0],std::string);
      should_eq("",split[1],std::string);
      should_eq("o",split[2],std::string);
    });
  });

  describe("gets lines",{
    it("of a non-existent file",{
      auto lines = utils::get_lines("specc/get_lines/idontexist.txt");
      should_eq(0,lines.size(),int);
    });

    it("of an empty file",{
      auto lines = utils::get_lines("specc/get_lines/empty.txt");
      should_eq(0,lines.size(),int);
    });

    it("of a populated file",{
      auto lines = utils::get_lines("specc/get_lines/test.txt");
      should_eq(3,lines.size(),int);
      should_eq("greg",lines[0],std::string);
      should_eq("the",lines[1],std::string);
      should_eq("hello",lines[2],std::string);
    });
  });
});