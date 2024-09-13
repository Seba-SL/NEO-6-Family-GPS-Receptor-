#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Configura el puerto serial para el GPS
SoftwareSerial gpsSerial(10, 11); // RX, TX

// Crea un objeto de la biblioteca TinyGPS++
TinyGPSPlus gps;

void setup() {
  // Inicia el puerto serial para la comunicación con el ordenador
  Serial.begin(9600);
  // Inicia el puerto serial para el GPS
  gpsSerial.begin(9600);

  Serial.println("Esperando señal GPS...");
}

void loop() {
  // Lee datos del GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    
    if (gps.location.isUpdated()) {
      Serial.print("Latitud= "); 
      Serial.print(gps.location.lat(), 6); 
      Serial.print(" Longitud= "); 
      Serial.print(gps.location.lng(), 6); 
      Serial.println();
    }

    if (gps.date.isUpdated()) {
      Serial.print("Fecha: ");
      Serial.print(gps.date.day());
      Serial.print("/");
      Serial.print(gps.date.month());
      Serial.print("/");
      Serial.print(gps.date.year());
      Serial.println();
    }

    if (gps.time.isUpdated()) {
      Serial.print("Hora: ");
      Serial.print(gps.time.hour());
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.print(gps.time.second());
      Serial.println();
    }
  }
}
