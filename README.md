# JeagerGSMLibrary

Before use this library install 
1. PubSubClient   # MQTT client
2. TinyGSM        # Modul GSM SIMxxx
3. Sleep_n0m1     # DeepSleep arduino board

Setting parameter in file setting_jeager.c :
  - pin TX and RX SoftwareSerial arduino to modul GSM
  - APN, user, and password GPRS credentials
  - sleep time (minutes)
  - MQTT broker server
  - username and password MQTT broker
  - topic data from device
  
Please contact info@jeager.io if you have problems in setting
