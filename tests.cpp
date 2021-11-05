#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Basic Tests") {
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Rovvy, Gybvn!", 10) != "Hello, World!");
}

TEST_CASE("More complicated tests") {
    CHECK(solve("vovo if gc tibbm!") != "haha ur so funny!");
    CHECK(solve("B tf zhbgz mh lxx fr fhf. Ftrux B pbee ukbgz axk yehpxkl.") == "I am going to see my mom. Maybe I will bring her flowers.");
}
