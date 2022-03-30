#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

extern const BatteryCharacter TestBatteryCharacter;
TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == TOO_LOW);
}
// TEST_CASE("infers the breach according to alerter") {
// REQUIRE(checkAndAlert(TO_CONTROLLER,TestBatteryCharacter,12));

// }
