
#include "Jeager/src/jeager.c"

void bacaSensor(){
  sensorValue = analogRead(gas_sensor); //Read analog values of sensor
  sensor_volt = sensorValue * (5.0 / 1023.0); //Convert analog values to voltage
  RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas
  ratio = RS_gas / R0; // Get ratio RS_gas/RS_air
  
  //convert to ppm value//
  ppm_log = (log10(ratio) - b) / m; 
  ppm = pow(10, ppm_log); 
  if(ppm>500)ppm=500;
  
  //display value//
//  Serial.print("sensor voltage: "); 
//  Serial.print(sensor_volt);
//  Serial.print("\t Ammonia: ");
//  Serial.println(ppm);
}

void setup() {
  initJeager();
  pinMode(gas_sensor, INPUT); //Set gas sensor as input
//  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  bacaSensor();
  
  isiData= String (ppm);
  
  jeagerRUN();

}
