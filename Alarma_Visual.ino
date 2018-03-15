
/* Programa de una alarma visual, que usa un LED RGB para cambiar de color y un REED SWITCH como un pulsador.
 *  cuando la puerta se abre, la cual tiene un iman, el LED cambia a color rojo y parpadea dando aviso de que la puerta fue abierta, ademas se escucha un sonido dando a entender esto,
 *  Cuando esta todo normal, el LED esta de color azul y no se escucha ningun sonido.
 *  Tambien tiene agregado el MODO SLEEP, para el bajo consumo del arduino.
*/
//------------------------------------------------------
//Incluye la libreria
#include <LowPower.h>

//Declaracion de los puertos de entradas y salidas. Variables
int contacto = 4; //Pin asignado al REED SWITCH
int ledAzul = 2; //Pin asignado al LED Azul
int ledRojo = 3; //Pin asignado al LED Rojo
int zumbador = 13; //Pin asignado al BUZZER
int frecuencia = 220; //Constante con la que se repetira el sonido

//Funcion Principal, se ejecuta cada vez que el arduino se inicia
void setup() 
{
  pinMode(contacto, INPUT); //El REED SWITCH como una entrada
  pinMode(ledAzul, OUTPUT); //El LED Azul como una salida
  pinMode(ledRojo, OUTPUT); //El LED Rojo como una salida
  pinMode(zumbador, OUTPUT); //El BUZZER como salida
}

//Funcion ciclica, esta funcion se mantiene ejecutando cuando este energizado el Arduino
void loop() 
{
  //Si el iman se aleja al REED SWITCH
  if(digitalRead(contacto) == LOW)
  {
    for(int a = 0; a < 50; a++)
    {
      color(255,0,0); //Prende el LED Rojo
      delay(50); //Tiempo
      color(0,0,0); //Para que se apague el LED
      delay(50); //Tiempo
      tone(zumbador, frecuencia); //Sueno o se escucha el sonido
    }
  }
  else
  {
    //Si el iman se acerca al REED SWITCH, el LED Azul, permanece encendido
    color(0,0,255); 
    delay(50); //Tiempo
    noTone(zumbador); //No se escucha nada
  }
  //Le envio un valor al sleep, que son los segundos que queremos que duerma el arduino
  sleep(15);
}

//Funcion Color
void color(int rojo, int verde, int azul){
  //Escritura del PWM del color Rojo
  analogWrite(ledRojo, 255 - rojo);

  //Escritura de PWM del color Azul
  analogWrite(ledAzul, 255 - azul);
}

//Se hace uso de intervalos de 8 segundos y hace comprobaciones en intervalos pequeños, como esto lo hace en microsegundo, no se ve afectado entre cuando se duerme y se vuelve a despertar
//el arduino, su funcion continua como si nunca se durmiera.
void sleep(int sec)
{
  while(sec >= 8)
  {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    sec -= 8;
  }

  if(sec >= 4)
  {
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    sec -= 4;
  }

  if(sec >= 2)
  {
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
    sec -= 2;
  }

  if(sec >= 1)
  {
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    sec -= 1;
  }
}
