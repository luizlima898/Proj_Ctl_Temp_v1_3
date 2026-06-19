#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Luiz Fernando 2.4Ghz"; //Nome do WiFi
const char* password = "971942255"; //Senha do WiFi
const char* serverUrl = "http://192.168.15.181:3000/update-sensor"; // Use o IP que você anotou

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nConectado ao WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Simulando a leitura do sensor (substitua pela leitura real do seu sensor)
     float t = dht.readTemperature();
    float h = dht.readHumidity();
    String httpRequestData = "{\"temperatura\":" + String(t) + ",\"umidade\":"+String(h)+"}";

    int httpResponseCode = http.POST(httpRequestData);
    
    if (httpResponseCode > 0) {
      Serial.print("Resposta do servidor: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  delay(5000); // Envia a cada 5 segundos
}