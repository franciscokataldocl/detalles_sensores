//install Adafruit_SHTC3 with dependecies
#include <Wire.h>
#include <Adafruit_SHTC3.h>

// Crear una instancia del sensor SHTC3
Adafruit_SHTC3 sensor;

// Pines I2C para ESP32
const int SDA_PIN = 21; //D21
const int SCL_PIN = 22;  //D22
const int SERIAL_BAUDRATE = 115200; //SERIAL PORT

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  
  // Iniciar comunicación I2C en los pines especificados
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Inicializar el sensor
  if (!sensor.begin()) {
    Serial.println("Error de comunicación con el sensor.");
    while (1);  // Detener ejecución si el sensor no responde
  }

  Serial.println("Sensor SHTC3 encontrado!");
}

void loop() {
  // Estructura para almacenar los datos del sensor
  sensors_event_t temp_event, humidity_event;
  
  // Leer temperatura y humedad
  sensor.getEvent(&humidity_event, &temp_event);

  // Mostrar los valores en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temp_event.temperature);
  Serial.print(" °C, Humedad: ");
  Serial.print(humidity_event.relative_humidity);
  Serial.println(" %");

  delay(1000);  // Esperar 1 segundo antes de la siguiente lectura
}
