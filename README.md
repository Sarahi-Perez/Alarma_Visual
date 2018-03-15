# Alarma_Visual

Programa de una alarma visual, que usa un LED RGB para cambiar de color y un REED SWITCH como un pulsador.
Cuando la puerta se abre, la cual tiene un iman, el LED cambia a color rojo y parpadea dando aviso de que la puerta fue abierta, ademas se escucha un sonido dando a entender esto.
Cuando esta todo normal, el LED esta de color azul y no se escucha ningun sonido.
Tambien tiene agregado el MODO SLEEP, para el bajo consumo del arduino.

Que usa las funciones:
SLEEP_xS: Fija el tiempo que estará "dormido" usando para ello el Watchdog.
ADC_OFF: Apaga los convertidores Analógico a Digital.
BOD_OFF: Apaga el circuito de Brown Out Detection, que es un circuito que sirve como detector de niveles de tensión
peligrosamente bajos que podrían incluso llegar dañar los circuitos.

Materiales:
- 1 LED RGB (Es un led que se conforma con el Rojo(Red), Verde(Green) y Azul(Blue), y en combinacion de estos 3 conforma otros colores) 
- 1 REED SWITCH (es como un boton)
- 2 resistencias de 220 ohms (pueden ser de 330 ohms)
- 1 resistencia de 1000 ohms (1kilo)
- 1 Buzzer
- 1 Arduino UNO
- Varios cables de colores 

Software:
- Programa Arduino: para realizar la programacion del Arduino UNO
- fritzing: para realizar los esquemas del circuito.

![Esquema del Circuito](https://github.com/Sarahi-Perez/Alarma_Visual/blob/master/Esquema_Alarma.jpg "Esquema del circuito")

![Circuito con iman](https://github.com/Sarahi-Perez/Alarma_Visual/blob/master/IMG_20180315_092442.jpg "Circuito cuando el iman esta cerca")
