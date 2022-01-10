Alejandra Araya
Sebastián Navarrete
-----------------------------------------

-Se encuentra creardo el archivo MAKEFILE para poder compilar todo sólo ingresando el comando make en la consola
dentro del directorio del proyecto.
-La compilación del proyecto debe ser en un ambiente Linux (probado en y funcional en Ubuntu) y en modo SuperUser.
-En orden de una correcta ejecución, abrir el archivo server, definir la cantidad de jugadores, abrir 
la cantidad de clientes correspondiente a la cantidad de jugadores para que cada uno maneje e identificar
el número de jugador correspondiente.
una consola.
-Al notar que un jugador envió su coordenada después que el otro jugador, el servidor responderá con el mensaje
"muy lento".

Comentarios:
-En el archivo client.c, desde la línea 60 a la 75 se hacen los envíos de datos ingresados hacia el sevidor.
-En en archivo server.c, desde la línea 169 se definen las tuberías, para luego de la 184 , abrirlas, por lo que si estas se encuentran
abiertas, en la línea 37 a 41 se cerrarán en caso de volver a querer utilizarlas.
