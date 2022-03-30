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
  if (coolingType !=MED_ACTIVE_COOLING){
retVal = apicooling(coolingType, ltemp);
}
  else{
  int lowerLimit =0;
  int upperLimit = 35;
   return inferBreach(ltemp, lowerLimit, upperLimit);
  }
}



BreachType apicooling( CoolingType coolingType, double temperatureInC)
{
  double ltemp = temperatureInC;
  int lowerLimit =0;
  int upperLimit = 0;
if(coolingType == PASSIVE_COOLING) {
      upperLimit = 35;  
}
else if(coolingType == HI_ACTIVE_COOLING){
      upperLimit = 45;
  }
  return inferBreach(ltemp, lowerLimit, upperLimit);
}


int checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar.coolingType, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
  
  if(alertTarget == TO_CONTROLLER){
  sendToController(breachType);
    return TRUE;
  }
  else{
  sendToEmail(breachType);
    return FALSE;
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


