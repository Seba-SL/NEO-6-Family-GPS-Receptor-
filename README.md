<h1>  <img src="https://github.com/user-attachments/assets/e49b248e-e4dd-4d7a-8cec-ccf3e0536521" alt="imagen" width="60"/>   NEO-6-Family-GPS-Receptor </h1>

La familia de modulos NEO-6 utilizan principalmente el chip u-blox NEO-6 y una antena para comuncarse con satelites y calcular la posicion actual.

![imagen](https://github.com/user-attachments/assets/544d5e16-8f6c-4a94-8195-289462f75792)


<ul>
  <li>Alimentacipon : 3,6 V  (1,75 V para NEO-6G)</li>
  <li>Interfaces : UART , I²C , USB , SPI , DDC (Compilación i²C)</li>
  <li>Canales de Recepcion : 50 </li>
  <li>Exactitud de Velocidad : 0.1 m/s</li>
  <li>Limite de velocidad: 500 m/s</li>
  <li>Limite de altura: 50 Km</li>
  <li>Frecuencia de Trabajo : L1 (1575.42 MHz)</li>
</ul>

![imagen](https://github.com/user-attachments/assets/9ed037de-69e0-47d4-ad28-7ba564aa744f)

<ul>

  <li>Antena: La antena generalmente es del tipo path, su tamaño varia segun el rango de frecuencias a mayor tamaño fisico mejor disposicion para frecuencias mas bajas.</li>

  <li>SAW: El filtro de ondas acústicas superficiales (Surface Acoustic Wave, -Filtro SAW) es un dispositivo piezoeléctrico que ayuda a filtrar ruidos,el filtro SAW selecciona y    permite pasar solo la frecuencia específica (en este caso, L1) mientras rechaza las señales en otras frecuencias cercanas. Esto ayuda a reducir el ruido y las interferencias que podrían afectar la precisión del GPS.</li>

  <li>RF: Sistema de radiofrecuencia que se encarga de la recepción y transmisión de señales de radiofrecuencia (RF), aumenta la potencia de la señal recibida para que sea suficiente para el procesamiento posterior.Esto se hace mediante amplificadores de bajo ruido (LNA: Amplifier noise low) en la recepción y amplificadores de potencia (PA) en la transmisión.</li>
 
  <li>Baseband Processor: Se encarga de manejar y procesar las señales después de que han sido captadas y amplificadas en la etapa RF (radiofrecuencia).</li>

  
</ul>
Recepción de Señales de Satélites: El NEO-6 recibe señales de radiofrecuencia de múltiples satélites GPS. Los satélites GPS emiten señales en frecuencias específicas, y el receptor NEO-6 está diseñado para captar estas señales.

Decodificación de Señales: El chip NEO-6 decodifica las señales de los satélites. Cada señal contiene información sobre el tiempo y la posición del satélite que la envió, así como datos de corrección.

Cálculo de Posición: El NEO-6 usa un algoritmo de trilateración para calcular la posición exacta del receptor. Necesita recibir señales de al menos cuatro satélites para calcular la posición en tres dimensiones (latitud, longitud y altitud) y para corregir el error en el reloj interno del receptor.

Corrección y Filtro: Para mejorar la precisión, el módulo aplica correcciones adicionales y filtros a los datos recibidos. Esto puede incluir ajustes basados en errores sistemáticos conocidos y condiciones atmosféricas.

Envío de Datos: Una vez calculada la posición, el NEO-6 envía estos datos a un microcontrolador o sistema externo a través de una interfaz de comunicación, que puede ser UART (seria), I2C, o SPI. Los datos típicos incluyen coordenadas geográficas (latitud, longitud), altitud y la calidad de la señal.

Configuración y Ajustes: El NEO-6 puede ser configurado para diferentes modos de operación y tasas de actualización de datos. Estas configuraciones se realizan mediante comandos específicos enviados al módulo a través de su interfaz de comunicación.


![imagen](https://github.com/user-attachments/assets/160fa5bc-f899-49b8-8466-c738445b300f)


Sistema de Coordenadas:

Se utiliza el estandar WGS World Geodetic System (https://en.wikipedia.org/wiki/World_Geodetic_System), define el centreo de masa de la Tierra como referencia (0,0,0), el eje z esta en direccion al Polo Norte Geografico, el eje x en la interseccion del plano Ecuatorial y el Meridiano de Greenwich y finalmente el eje y esta dado por el producto vectorial de estos anteriores.

<img src="https://github.com/user-attachments/assets/ceb2f1bc-f852-43de-a33f-b388b77b5925" alt="imagen" width="600"/>  

La informacion de la posición se da en terminos de Latitud y Longitud.
La latitud mide la distancia al norte o al sur del ecuador. Es una coordenada que varía entre 90 grados Norte y 90 grados Sur.
L longitud mide la distancia al este o al oeste del meridiano de Greenwich, que es la línea de longitud 0° que pasa por Greenwich, Londres.

![imagen](https://github.com/user-attachments/assets/15d23f7f-f6b9-4a25-ae17-5f2c3532c5f6)



<h1>  <img src="https://github.com/user-attachments/assets/c6e1de60-26ce-4e06-ba65-9f307ec6c238" alt="imagen" width="80"/>   Prácticas de comunicación GPS </h1>

Se utilizara el modulo GY-GPS6MV2 con el modulo NEO-6M.

<img src="https://github.com/user-attachments/assets/1d375b55-1171-4abb-8274-c8b25dc86bf0" alt="imagen" width="200"/>
<img src="https://github.com/user-attachments/assets/7c5f267f-fd30-41fa-bf6f-8baf8c459392" alt="imagen" width="270"/>

Para procesar y utilizar la información proporcionada, se utilizan diferentes entornos de desarrollo:
<ul>
<li>Arduino : Mediante comunicación UART</li>
<li>Esp8266 : Mediante comunicación UART</li>
<li>Computadora : USB con convertidor TTL</li>
<li>Raspberry : Mediante comunicación UART</li>
</ul>

Entorno de Desarrollo Arduino
Libreria TinyGPS++ : Esta biblioteca proporciona métodos compactos y fáciles de usar para extraer posición, fecha, hora, altitud, velocidad y desde dispositivos GPS.
https://github.com/mikalhart/TinyGPSPlus
http://arduiniana.org/libraries/tinygpsplus/


Los datos llegan de la siguiente manera , usando una libreria se pueden extraer para su uso:

![imagen](https://github.com/user-attachments/assets/e0d207dd-c5a8-44de-943d-778296c1d2a3)



<h3>Prueba con Arduino UNO: Ver datos en Monitor Serial</h3>

```cpp
#include <SoftwareSerial.h> // Para usar otros pines para comunicacion UART
#include <TinyGPS++.h>

// Configura el puerto serial para el GPS
SoftwareSerial gpsSerial(10, 11); // RX, TX

// Crea un objeto de la biblioteca TinyGPS++
TinyGPSPlus gps;

void setup() {
  // Inicia el puerto serial para la comunicación con la computadora
  Serial.begin(9600);
  // Inicia el puerto serial para el GPS
  gpsSerial.begin(9600);

  Serial.println("Esperando señal GPS...");
}

void loop() {
  // Lee datos del GPS
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    
    if (gps.location.isUpdated()) 
    
    {
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

```

Utilizando la informacion en google maps:

![imagen](https://github.com/user-attachments/assets/7dd9ea08-13c9-414e-8b6f-533e614be279)

![imagen](https://github.com/user-attachments/assets/2df2f34f-9290-43b9-b925-c768596f0f0b)

[Grabación de pantalla desde 2024-09-23 08-04-08.webm](https://github.com/user-attachments/assets/17a56163-4ef6-4cc0-86d6-d1a2dda2eb41)

![Captura desde 2024-09-23 08-03-53](https://github.com/user-attachments/assets/1da0c731-36c3-4ac3-91bc-229d1e32e4b7)


https://github.com/user-attachments/assets/98074e19-e4a9-4ae0-a0b0-53d778a2b726


Uso de Stellarium (software libre) para visualizaciones en el espacio : 

https://stellarium.org/

![imagen](https://github.com/user-attachments/assets/1c9fbf53-d3b7-46d6-8613-76ec4f892dac)

![imagen](https://github.com/user-attachments/assets/827d8392-e175-4d93-a228-8e58712ed3cf)






 



