#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// --- CONFIGURAÇÕES ---
const char* ssid = "********";
const char* password = "*********";

// Substitua pelo IP do seu PC (ex: 192.168.1.15) se estiver local
// Ou pela URL do Render (ex: https://onrender.com)
const char* serverName = "http://192.168.**.***:3000/sensor";
#define DHTPIN 4

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);

  // Inicia conexão Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConectado!");
  Serial.print("IP do ESP32:192.168.*.**.***");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Verifica se o Wi-Fi ainda está conectado
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;

    // Inicia a requisição no servidor
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    
    // Cria o JSON para o POST
    String httpRequestData = "{\"temperatura\":" + String(temp) + ",\"umidade\":" + String(umid) + "}";

    // Envia o POST
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("Resposta do servidor: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro no envio: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Wi-Fi desconectado");
  }

  // Espera 10 segundos para enviar a próxima leitura
  delay(10000);
}

    


  

 

