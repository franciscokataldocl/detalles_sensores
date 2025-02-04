#define AO_PIN 27 // Pin de conexion del sensor

void setup() {
  Serial.begin(115200);
}

void loop() {
  int rawValue = analogRead(AO_PIN);
  float voltage = (rawValue / 4095.0) * 3.0; // Usamos 3V

  // Invertimos la relación entre los valores analógicos y la humedad
  int humidity = map(rawValue, 1136, 4095, 0, 100); // Invertido el rango
  humidity = constrain(humidity, 0, 100); // Asegurarnos que la humedad esté entre 0 y 100

  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print(" - Voltage: ");
  Serial.print(voltage);
  Serial.print("V - Humedad: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000); // Leer cada segundo
}
