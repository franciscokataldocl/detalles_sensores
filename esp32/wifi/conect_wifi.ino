#include <WiFi.h>
#include <time.h>

// Credenciales WiFi
const char* ssid = "";
const char* password = "";

// Servidor NTP para obtener la hora
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -3 * 3600;  // Chile UTC-3
const int daylightOffset_sec = 0;

unsigned long previousMillis = 0;
const unsigned long interval = 30 * 60 * 1000;  // 30 minutos

String ultimaConexion = "Desconocida";

void obtenerHora(String &horaActual) {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        horaActual = "Error al obtener hora";
        return;
    }
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeinfo);
    horaActual = String(buffer);
}

void conectarWiFi() {
    WiFi.begin(ssid, password);
    unsigned long startAttemptTime = millis();
    
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        obtenerHora(ultimaConexion);
        Serial.println("Conectado a WiFi: " + ultimaConexion);
    } else {
        Serial.println("No se pudo conectar a WiFi.");
    }
}

void setup() {
    Serial.begin(115200);
    conectarWiFi();
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        if (WiFi.status() == WL_CONNECTED) {
            obtenerHora(ultimaConexion);
            Serial.println("Sigue conectado a WiFi: " + ultimaConexion);
        } else {
            Serial.println("WiFi desconectado. Última conexión: " + ultimaConexion);
            conectarWiFi();
        }
    }
}
