# SerpientesEscaleras

Por favor leer antes de usar el programa.
Para compilar el programa se requiere usar un IDE (ejemplo Visual Studio Code) y entrar a la carpeta donde se encuentren todos los archivos de el programa.
En la terminal, escribir lo siguiente: 
  g++ snakes.cpp Dice.cpp Player.cpp Tiles.cpp -o main
  ./main

Cuando comience la ejecucion del programa se solicitara al usuario si quiere que el programa corra con la ayuda de un archivo anexo o con la interaccion del usuario.
Para esto ingrese a la consola el numero 0 para el archivo o el numero 1 para la interaccion.

En caso de seleccionar el archivo se pedira que escriba el nombre del archivo de la forma: ejemplo.txt

Las reglas para jugar el juego tras introducir el numero de jugadores y el numero de turnos, es escribir la letra C para continuar con los turnos o E para acabar el juego. Esto se repetira hasta que se acaben los turnos o un jugador gane.
