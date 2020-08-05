
// modem:
#define TINY_GSM_MODEM_SIM800

// Set serial for debug console (to the Serial Monitor, default speed 115200)
#define SerialMon Serial

// Library
#include <SoftwareSerial.h>
#include <TinyGsmClient.h>
#include <PubSubClient.h>
#include <Sleep_n0m1.h>
#include "../setting_jeager.c"



SoftwareSerial SerialAT(Pin_RX_AT, Pin_TX_AT); // Masukan nilai RX, dan  TX
Sleep sleep;


// Define the serial console for debug prints, if needed
#define TINY_GSM_DEBUG SerialMon

// Range to attempt to autobaud

// Add a reception delay - may be needed for a fast processor at a slow baud rate
// #define TINY_GSM_YIELD() { delay(2); }

// Define how you're planning to connect to the internet
#define TINY_GSM_USE_GPRS true

// set GSM PIN, if any
#define GSM_PIN "12"    // Masukan nilai pin yang digunakan 
#undef TINY_GSM_USE_GPRS
#define TINY_GSM_USE_GPRS true

#ifdef DUMP_AT_COMMANDS
#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif
TinyGsmClient client(modem);
PubSubClient mqtt(client);

#define LED_PIN 13 // Masukan nilai indikator yang akan digunakan 

#include "gsm_jeager.c"

#include "init_jeager.c"


