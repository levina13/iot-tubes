#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

  String Link;
  HTTPClient http;
  WiFiClient client;
//WiFiClient wifiClient;

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// Ganti dengan informasi Wi-Fi Anda
const char *SSID_WIFI = "NamaWifiAnda";
const char *PASSWORD_WIFI = "PasswordWifiAnda";

// Ganti dengan alamat IP server dan path yang sesuai
const char *SERVER_IP = "192.168.0.202";
const int SERVER_PORT = 9000;
const char *PATH = "/testWebSensor/";

// void setup() {
//   Serial.begin(115200);

//   // Menghubungkan ke jaringan Wi-Fi
//   WiFi.begin(SSID_WIFI, PASSWORD_WIFI);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
// }

// void loop() {
//   // Mengambil nilai sensor (gantilah dengan implementasi sesuai kebutuhan Anda)
//   float sensorValue = 25.5;

//   // Membuat URL lengkap
//   String url = "http://" + String(SERVER_IP) + ":" + String(SERVER_PORT) + String(PATH);
//   url += "?sensor=" + String(sensorValue);

//   // Membuat objek HTTPClient
//   HTTPClient http;

//   Serial.print("Sending data to server... ");

//   // Mulai koneksi HTTP
//   if (http.begin(url)) {
//     // Kirim GET request dan periksa respons
//     int httpCode = http.GET();

//     if (httpCode > 0) {
//       Serial.println("Success");
//     } else {
//       Serial.println("Failed. Error code: " + String(httpCode));
//     }

//     // Akhiri koneksi
//     http.end();
//   } else {
//     Serial.println("Unable to connect to server");
//   }

//   // Tunggu selama 5 detik sebelum mengirim data lagi (sesuaikan sesuai kebutuhan)
//   delay(5000);
// }

const char* ssid = "TOTOLINK_N350RT";
const char* password = "lintang123";
const char* host = "192.168.0.202";

void setup(){
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }

  Serial.println("Connected!");
}

void loop(){
  int sensor = analogRead(A0);
  Serial.println("LDR : " + String(sensor));
  Serial.println("haloo");
  if ( !client.connect(host, 9000) ){
    Serial.println("Connection Failed!");
    return;
  }else
  {
    Serial.println("Connection success!");
  }


  Link = "http://192.168.0.202:9000/testWebSensor/sendData.php?sensor=" + String(sensor);
  
  //http.begin(Link); // Assuming 'client' is an instance of WiFiClient

  http.begin(Link);
  http.GET();

  String respon = http.getString();
  Serial.println(respon);
  http.end();

  delay(1000);
}
