
//Setting, device akan mengirim data lagi dalam berapam menit ? (Satuan  dalam menit )
const char sleepTime = 20; // menit

// Setting MQTT
//Masukan IP Server, Contoh :  34.87.144.83
const char* broker = "34.87.144.83";            

//Masukan Topic Data, Contoh : Evomo/5f0e7893658acc00108aa821/1594785600355478693
const char* topicData = "Evomo/5f0e7893658acc00108aa821/1594785600355478693";        

//Masukan nilai, lamanya MQTT akan konek ke Server, (Satuan dalam Mili Second)
uint32_t lastReconnectAttempt = 0; 

//Masukan username yang telah didapat dengan menhubungi Jeager
const char* usernameMQTT ="";

//Masukan password MQTT yang telah didapt
const char* passwordMQTT ="";


//Masukan nilai pin TX dan RX pada saat ini  menggunakan pin 10 dan 11
#define Pin_RX_AT 10 
#define Pin_TX_AT 11

// Setting nilai BaudRate
#define GSM_AUTOBAUD_MIN 9600    //Masukan nilai buadrate yang akan digunakan ( nilai minimum)
#define GSM_AUTOBAUD_MAX 115200  // Masukan nilai baudrate yang akan digunakan ( nilai maksimum)

// Your GPRS credentials, if any
const char tipeGPRS="SIM800L";
const char apn[] = "internet";
const char gprsUser[] = "";
const char gprsPass[] = "";



//Silahkan hubungi info@jeager.io apabila memiliki kendala dalam melakukan Setting

