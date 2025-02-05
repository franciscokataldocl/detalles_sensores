int sensorPin = 34;  // Pin analógico D34
int sensorValue = 0;  // Variable para almacenar la lectura del sensor
const int SERIAL_BAUDRATE = 115200; //SERIAL PORT
int min_value = 0;
int max_value = 4095; 


void setup() {
  Serial.begin(SERIAL_BAUDRATE);  // Inicia comunicación serie
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Lee el valor analógico del sensor

  // Invertir el valor mapeado para que 0% sea sin luz y 100% con luz
  int lightPercentage = map(sensorValue, min_value, max_value, 100, 0); 

  Serial.print("Valor del sensor (0-4095): ");
  Serial.print(sensorValue);
  Serial.print(", Porcentaje de luz: ");
  Serial.print(lightPercentage);
  Serial.println(" %");

  delay(1000);  // Espera 1 segundo antes de la próxima lectura
}
