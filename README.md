# TP_Arduino_UNSAM
Tp para laboratorio de computación 1


Consiste en un juego para el que necesitas un LED RGB, 3 potenciómetros y 2 botones.

https://www.tinkercad.com/things/6CsZi6EjP59-tp-arduino

El juego consiste en armar el color que se te indica moviendo intensidades de rojo, azul y verde (que se mueven en valores entre 0 y 255) para acercarte al color final antes de que se acabe el tiempo.
Si ya subiste el programa lo primero que vas a notar va a ser el color violeta que indica que está esperando a que pulses el botón de inicio.
Luego va a titilar en celeste indicando que empieza el nivel uno (uno de tres), muestra el color objetivo y empieza el juego.
Durante el juego podés pulsar el otro botón que no es el de inicio para activar la pista que muestra el colo al que tenés que llegar durante un tiempo determinado, mientras se te muestra la pista el tiempo sigue corriendo.
Cuando estés lo suficientemente cerca del color objetivo el led va a empezar a titilar en verde, indicando que pasaste el primer nivel.
El proceso se repite dos veces más (dos niveles) en los que se reduce el tiempo límite y el margen en el que los valores de RGB tienen que estar para pasar el nivel.
Si el tiempo termina en cualquiera de los niveles el LED va a titilar en rojo y va a volver al estado de espera de botón de inicio (LED brillando en violeta) y se puede volver a intentar.

Al terminar el 3er nivel, el LED mostrará varios colores aleatorios (en el código es una función llamada fiestita()), indicando que terminó el juego y vuelve a mostrar el violeta de inicio y dando la posibilidad de volver a jugar.

