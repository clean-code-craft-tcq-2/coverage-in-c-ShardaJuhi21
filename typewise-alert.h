#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
 
  #define TRUE 1
#define FALSE 0
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
BreachType apicooling( CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

int checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter *batteryChar->coolingType, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
  
#ifdef __cplusplus
}
#endif
