#define AO_PIN 27

void setup() {
  Serial.begin(115200);
}

void loop() {
  int rawValue = analogRead(AO_PIN);//retorna un valor entre 0 y 4095
  //conversion de valor leido por esp32 a volts - 0 representa 0V y 4095 3.3v
  float voltage = (rawValue / 4095.0) * 3.3; //normalizar valor y multiplicar por voltage total

  // Invertimos la relación entre valores analógicos y humedad
  //map(value, fromLow, fromHigh, toLow, toHigh)
  //map(lectura_analogia_sensor, lectura_aire_seco, lectura_tierra_humeda, seco, humedo)
  int humidity = map(rawValue, 4095, 1136, 0, 100);

  //limita el valor dentro de un rango especifico para menor y mayor
  humidity = constrain(humidity, 0, 100); 

  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print(" - Voltage: ");
  Serial.print(voltage);
  Serial.print("V - Humedad: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000);
}
