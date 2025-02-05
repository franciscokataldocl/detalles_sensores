#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    
    // Obtiene la dirección MAC del ESP32
    uint8_t mac[6];
    WiFi.macAddress(mac);

    // Convierte la MAC en un número único
    uint64_t uniqueID = 0;
    for (int i = 0; i < 6; i++) {
        uniqueID = (uniqueID << 8) | mac[i];
    }

    Serial.print("ID único del ESP32: ");
    Serial.print((uint32_t)(uniqueID >> 32));  // Parte alta
    Serial.print((uint32_t)(uniqueID & 0xFFFFFFFF));  // Parte baja
    Serial.println();
}

void loop() {}
