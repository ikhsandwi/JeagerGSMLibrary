
String isiData;


void mqttCallback(char* topic, byte* payload, unsigned int len) {
  SerialMon.print("Message arrived [");
  SerialMon.print(topic);
  SerialMon.print("]: ");
  SerialMon.write(payload, len);
  SerialMon.println();
}


// Masukan nilai dari Variabel Global
int ledStatus = LOW;
int gas_sensor = A1;                      //Sensor pin
float m = -0.263,                         //Slope
      b = 0.42,                           //Y-Intercept
      R0 = 2.77,                          //Sensor Resistance in fresh air from previous code
      sensor_volt,                        //Define variable for sensor voltage
      RS_gas,                             //Define variable for sensor resistance
      ratio,                              //Define variable for ratio
      sensorValue;                        //get value from sensor
double ppm_log;                           //Get ppm value in linear scale according to the the ratio value
double ppm;                               //Convert ppm value to log scale




//Function untuk koneksi ke MQTT
boolean mqttConnect() {
  SerialMon.print("Connecting to ");
  SerialMon.print(broker);

  // Connect to MQTT Broker
  boolean status = mqtt.connect(tipeGPRS, usernameMQTT, passwordMQTT);

  if (status == false) {
    SerialMon.println(" fail");
    return false;
  }
  SerialMon.println(" success");
  //payload data
  String json = "{\"O\": "+ isiData +"}";
  unsigned int jsonLength=json.length();
  //send/publish data
  mqtt.publish(topicData,(char*)json.c_str() );
  Serial.print("The length of payload sent:");
  Serial.println(jsonLength);
  return mqtt.connected();
}



void GPRSConnect(){
  #if TINY_GSM_USE_GPRS
  // Unlock your SIM card with a PIN if needed
  if ( GSM_PIN && modem.getSimStatus() != 3 ) {
    modem.simUnlock(GSM_PIN);
  }
#endif

  SerialMon.print("Waiting for network...");
  if (!modem.waitForNetwork()) {
    SerialMon.println(" fail");
    delay(10000);
    return;
  }
  SerialMon.println(" success");

  if (modem.isNetworkConnected()) {
    SerialMon.println("Network connected");
  }

#if TINY_GSM_USE_GPRS
  // GPRS connection parameters are usually set after network registration
    SerialMon.print(F("Connecting to "));
    SerialMon.print(apn);
    if (!modem.gprsConnect(apn, gprsUser, gprsPass)) {
      SerialMon.println(" fail");
      delay(10000);
      return;
    }
    SerialMon.println(" success");

  if (modem.isGprsConnected()) {
    SerialMon.println("GPRS connected");
  }
#endif
}

void jeagerConnectInternet(){
    if(!modem.isGprsConnected()){
    GPRSConnect(); 
  }
}


void jeagerDeepSleep(){
  Serial.println("MQTT Disconnect");
  delay(100);
  Serial.print("Sleep ");
  Serial.print(sleepTime);
  Serial.println("Minute"); 
  
  //digitalWrite(LED_PIN,LOW);
  delay(100); //delay to allow serial to fully print before sleep

  sleep.pwrDownMode(); //set sleep mode
  sleep.sleepDelay(sleepTime * 60000); //sleep for: sleepTime

}

void sentDatakeServer()
{
  if (!mqtt.connected()) {
    SerialMon.println("=== MQTT NOT CONNECTED ===");
    uint32_t t = millis();
    if (t - lastReconnectAttempt > 10000L) {
      lastReconnectAttempt = t;
      if (mqttConnect()) {
        lastReconnectAttempt = 0;
      }
    }
    delay(1000);
    return;
  }
  mqtt.disconnect();

}


void jeagerRUN(){
  digitalWrite(LED_PIN,HIGH);
   //MEMASTIKAN TERKONEKSI DENGAN INTERNET
  jeagerConnectInternet();
    
  //KIRIM DATA KE SERVER
  sentDatakeServer();
  
  //DEEPSLEEP
  jeagerDeepSleep();

}
