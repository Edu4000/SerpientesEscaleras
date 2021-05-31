SerpientesEscaleras

INSTRUCCIONES

Por favor leer antes de usar el programa.
Para compilar el programa se requiere usar un IDE (ejemplo Visual Studio Code)
y entrar a la carpeta donde se encuentren todos los archivos de el programa.
En la terminal, escribir lo siguiente: 
  g++ snakes.cpp Dice.cpp Player.cpp Tiles.cpp -o main
  ./main

Cuando comience la ejecucion del programa se solicitara al usuario si quiere
que el programa corra con la ayuda de un archivo anexo o con la interaccion 
del usuario.
Para esto ingrese a la consola el numero 0 para el archivo o el numero 1 para 
la interaccion.

En caso de seleccionar el archivo se pedira que escriba el nombre del archivo 
de la forma: ejemplo.txt

Las reglas para jugar el juego tras introducir el numero de jugadores y el numero 
de turnos, es escribir la letra C para continuar con los turnos o E para acabar 
el juego. Esto se repetira hasta que se acaben los turnos o un jugador gane.


CONCEPTOS USADOS

En el proceso del desarrollo de esta entrega, desarrollamos 3 objetos por medio de
la abstraccion. Estos fueron Dice, Player y Tiles.
Decidimos abstraer estos objetos ya que son los elementos necesarios para jugar 
Serpientes y Ecaleras en la vida real.
En el caso de Dice, el objeto solo tiene un valor el cual cambia con el metodo
rollDice() al igual que sucede al lanzar un dado en la vida real.
Por otra parte, los objetos Player y Tiles fueron creados con el proposito de
almacenar informacion sobre el juego dentrp de ellos en vez de tener distintos arrays
para generar las tablas y turnos.
