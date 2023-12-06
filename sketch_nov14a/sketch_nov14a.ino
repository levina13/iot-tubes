#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Alvin";
const char* password = "12345678";
const char* serverAddress = "192.168.146.135"; // Ganti dengan alamat IP atau domain server Anda
const int serverPort = 8080; // Port HTTP umum adalah 80
const char* path = "/iot-tubes/SendData.php"; // Ubah sesuai dengan path PHP Anda

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  // Menghubungkan ke Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Simulasikan data sensor (ganti dengan data sensor sesungguhnya)
  int sensor = analogRead(A0);

  // Membuat objek HTTPClient
  HTTPClient http;

  // Membuat URL lengkap
  String url = "http://" + String(serverAddress) + ":" + String(serverPort) + String(path);

  // Mengatur header untuk tipe konten yang akan dikirim
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Membuat data yang akan dikirim ke server
  String postData = "sensor=" + String(sensor);

  Serial.print("Sending data to server... ");

  // Memulai koneksi HTTP
  if (http.begin(client, url)) {
    // Mengirim data ke server dengan metode POST
    int httpCode = http.POST(postData);

    if (httpCode == HTTP_CODE_OK) {
      Serial.println("Success");
    } else {
      Serial.println("Failed. HTTP error code: " + String(httpCode));
    }

    // Mengakhiri koneksi
    http.end();
  } else {
    Serial.println("Unable to connect to server");
  }

  // Tunggu selama 5 detik sebelum mengirim data lagi (sesuaikan sesuai kebutuhan)
  delay(5000);
}
