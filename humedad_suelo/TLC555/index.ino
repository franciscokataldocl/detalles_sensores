#define AO_PIN 27 // Pin donde conectaste el sensor

void setup() {
  Serial.begin(115200);
}

void loop() {
  int rawValue = analogRead(AO_PIN);  // Leer el valor analógico

  // Imprimir el valor en bruto para que puedas observar los cambios más fácilmente
  Serial.print("Raw Value: ");
  Serial.println(rawValue);

  // Determinar la condición de humedad (simple ejemplo)
  if (rawValue > 3400) {
    Serial.println("Tierra seca o ligeramente humeda");
  } else if (rawValue > 3300 && rawValue <= 3400) {
    Serial.println("Tierra moderadamente humeda");
  } else {
    Serial.println("Tierra muy humeda");
  }

  delay(1000); // Leer cada segundo
}
