# KeypadMCP23017
Matriz con dos multiplexores MCP23017

Se ha utilizado la librería de Adafruit_MCP23X17.
Se puede montar tal cual pero lo ideal es añadir un diodo (no led) a cada pulsador que se vaya a poner, con el kátodo hacia el pin de las columnas.
Con este diodo evitaremos que al pulsar varios pulsadores simultáneamente, se detecten pulsaciones de otros que no debería