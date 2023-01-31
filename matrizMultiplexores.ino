#include <Adafruit_MCP23X17.h>

// Creamos los objetos MCP23017
Adafruit_MCP23X17 mcpFilas;
Adafruit_MCP23X17 mcpColumnas;

// Añadimos las direcciones I2C de cada multiplexor
const int ADDR_mcpFilas = 0x20;
const int ADDR_mcpColumnas = 0x21;

// Establecemosd la configuracion de la matriz
const int filas = 16;
const int columnas = 16;

// Configuración de los pines
byte pinFilas[filas] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
byte pinColumnas[columnas] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void setup() {
  // Inicializamos 
  mcpFilas.begin_I2C(ADDR_mcpFilas);
  mcpColumnas.begin_I2C(ADDR_mcpColumnas);

  // Configuramos los pines de las filas
  for (int i = 0; i < filas; i++) {
    mcpFilas.pinMode(pinFilas[i], OUTPUT);
    mcpFilas.digitalWrite(pinFilas[i], HIGH);
  }
  // Configuramos los pines de las columnas
  for (int i = 0; i < columnas; i++) {
    mcpColumnas.pinMode(pinColumnas[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < filas; i++) {   // Recorremos todas las filas
    mcpFilas.digitalWrite(pinFilas[i], LOW);

    for (int j = 0; j < columnas; j++) {  // Recorremos todas las columnas
      if (!mcpColumnas.digitalRead(pinColumnas[j])) {   // Si ha sido presionado
        Serial.print("Se ha presionado la fila ");
        Serial.print(i);
        Serial.print(", columna ");
        Serial.println(j);
      }
    }

    // Volvemos a poner la fila actual en estado alto
    mcpFilas.digitalWrite(pinFilas[i], HIGH);
  }
}
