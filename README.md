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
</ul>

![imagen](https://github.com/user-attachments/assets/9ed037de-69e0-47d4-ad28-7ba564aa744f)

Recepción de Señales de Satélites: El NEO-6 recibe señales de radiofrecuencia de múltiples satélites GPS. Los satélites GPS emiten señales en frecuencias específicas, y el receptor NEO-6 está diseñado para captar estas señales.

Decodificación de Señales: El chip NEO-6 decodifica las señales de los satélites. Cada señal contiene información sobre el tiempo y la posición del satélite que la envió, así como datos de corrección.

Cálculo de Posición: El NEO-6 usa un algoritmo de trilateración para calcular la posición exacta del receptor. Necesita recibir señales de al menos cuatro satélites para calcular la posición en tres dimensiones (latitud, longitud y altitud) y para corregir el error en el reloj interno del receptor.

Corrección y Filtro: Para mejorar la precisión, el módulo aplica correcciones adicionales y filtros a los datos recibidos. Esto puede incluir ajustes basados en errores sistemáticos conocidos y condiciones atmosféricas.

Envío de Datos: Una vez calculada la posición, el NEO-6 envía estos datos a un microcontrolador o sistema externo a través de una interfaz de comunicación, que puede ser UART (seria), I2C, o SPI. Los datos típicos incluyen coordenadas geográficas (latitud, longitud), altitud y la calidad de la señal.

Configuración y Ajustes: El NEO-6 puede ser configurado para diferentes modos de operación y tasas de actualización de datos. Estas configuraciones se realizan mediante comandos específicos enviados al módulo a través de su interfaz de comunicación.


![imagen](https://github.com/user-attachments/assets/160fa5bc-f899-49b8-8466-c738445b300f)


<h1>  <img src="https://github.com/user-attachments/assets/c6e1de60-26ce-4e06-ba65-9f307ec6c238" alt="imagen" width="80"/>   Prácticas de comunicación GPS </h1>

Se utilizara el modulo GY-GPS6MV2 con el modulo NEO-6M.


<img src="https://github.com/user-attachments/assets/1d375b55-1171-4abb-8274-c8b25dc86bf0" alt="imagen" width="200"/>
<img src="https://github.com/user-attachments/assets/7c5f267f-fd30-41fa-bf6f-8baf8c459392" alt="imagen" width="270"/>

Para procesar y utilizar la información proporcionada, se utilizan diferentes entornos de desarrollo:

Arduino : Mediante comunicación UART 
Esp8266 : Mediante comunicación UART 
Computadora : USB con convertidor TTL 
Raspberry : Mediante comunicación UART 




