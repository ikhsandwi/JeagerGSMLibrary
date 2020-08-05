// Set console baud rate

void initJeager(){
  SerialMon.begin(GSM_AUTOBAUD_MAX);
  SerialAT.begin(GSM_AUTOBAUD_MIN);
  mqtt.setServer(broker, 1883);
  delay(10);
  SerialMon.println("Wait...");
  delay(6000);
  SerialMon.println("Initializing modem...");
  modem.restart();
  String modemInfo = modem.getModemInfo();
  SerialMon.print("Modem Info: ");
  SerialMon.println(modemInfo);
}