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
  int lowerLimit = 0;
  int upperLimit = 0;
  BreachType retVal;
  switch(coolingType) {
    case PASSIVE_COOLING:
      upperLimit = 35;
      retVal= inferBreach(temperatureInC, lowerLimit, upperLimit);
      break;
    case HI_ACTIVE_COOLING:
      upperLimit = 45;
      retVal= inferBreach(temperatureInC, lowerLimit, upperLimit);
      break;
    case MED_ACTIVE_COOLING:
      upperLimit = 40;
      retVal= inferBreach(temperatureInC, lowerLimit, upperLimit);
      break;
  }
  return retVal;
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
    case NORMAL:
      break;
  }
}


