#include "typewise-alert.h"
#include <stdio.h>


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  double ltemp = temperatureInC;
  BreachType retVal;
  if (coolingType !=END){
retVal = apicooling(coolingType, ltemp);
}
}



BreachType apicooling( CoolingType coolingType, double temperatureInC)
{
  double ltemp = temperatureInC;
  int lowerLimit =0;
  int upperLimit = 35;
if(coolingType == MED_ACTIVE_COOLING) {
      upperLimit = 40;  
}
else if(coolingType == HI_ACTIVE_COOLING){
      upperLimit = 45;
  }
  return inferBreach(ltemp, lowerLimit, upperLimit);
}
void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
       printf("To: %s\n", recepient);
      printf("Hi, the temperature is TOO_LOW");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is TOO_HIGH");
      break;
  }
}


