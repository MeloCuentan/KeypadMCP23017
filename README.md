# KeypadMCP23017
Matriz con dos multiplexores MCP23017

Se ha utilizado la librería de Adafruit_MCP23X17.
Se puede montar tal cual pero lo ideal es añadir un diodo (no led) a cada pulsador que se vaya a poner, con el kátodo hacia el pin de las columnas.
Con este diodo evitaremos que al pulsar varios pulsadores simultáneamente, se detecten pulsaciones de otros que no debería

El archivo matrizMultiplexores.ino crea una matriz con los pines de filas y columnas, que 
luego recorreremos con bucle for en el loop, y en la pruebas realizadas tarda aproximadamente 150ms en recorrer todo el bucle con un arduino NANO.
Tiene agregada la matriz con valores que van de 0 a 255.
