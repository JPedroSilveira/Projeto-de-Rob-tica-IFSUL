


// portas sendo usadas atualmente pelo arduino


//todas analog nao precisam ser declaradas no setup

/*analog


configurar


//digital


configurar


*/
//servo


/*
  Arduino Mario Bros Tunes
  With Piezo Buzzer and PWM
 
  Connect the positive side of the Buzzer to pin 3,
  then the negative side to a 1k ohm resistor. Connect
  the other side of the 1 k ohm resistor to
  ground(GND) pin on the Arduino.
 
  by: Dipto Pratyaksa
  last updated: 31/3/13
*/
 
/*************************************************
 * Public Constants
 *************************************************/
 
 
 #define  c3    7634
#define  d3    6803
#define  e3    6061
#define  f3    5714
#define  g3    5102
#define  a3    4545
#define  b3    4049
#define  c4    3816    // 261 Hz 
#define  d4    3401    // 294 Hz 
#define  e4    3030    // 329 Hz 
#define  f4    2865    // 349 Hz 
#define  g4    2551    // 392 Hz 
#define  a4    2272    // 440 Hz 
#define  a4s   2146
#define  b4    2028    // 493 Hz 
#define  c5    1912    // 523 Hz
#define  d5    1706
#define  d5s   1608
#define  e5    1517    // 659 Hz
#define  f5    1433    // 698 Hz
#define  g5    1276
#define  a5    1136
#define  a5s   1073
#define  b5    1012
#define  c6    955
 
#define  R     0      // Define a special note, 'R', to represent a rest

 
 
// Melody 1: Star Wars Imperial March
int melody1[] = {  a4, R,  a4, R,  a4, R,  f4, R, c5, R,  a4, R,  f4, R, c5, R, a4, R,  e5, R,  e5, R,  e5, R,  f5, R, c5, R,  g5, R,  f5, R,  c5, R, a4, R};
int beats1[]  = {  50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5,  20, 5, 60, 40};
 
int MAX_COUNT = sizeof(melody1) / 2; // Melody length, for looping.
 
long tempo = 10000; // Set overall tempo
 
int pause = 1000; // Set length of pause between notes
 
int rest_count = 50; // Loop variable to increase Rest length (BLETCHEROUS HACK; See NOTES)
 
// Initialize core variables
int toneM = 0;
int beat = 0;
long duration  = 0;
 
 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 9
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo1[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
 

#include <Servo.h>

Servo direita;
Servo esquerda;

// parte do sistema de diagnostico

int led1 = 4;
int led2 = 6;
int led3 = 8;

int led_sensor = 9;

//ultra

int leitor_echo_frente = A5;
int trigger_frente = 7;
long leitura_echo_frente = 0;
long distancia_ultrasonica_frente = 0;

//troca por botao

int modo = 0;

//leitor_de_luz

int leitor_ldr = A4;
int leitura_ldr = 0;
int led = 13;

//seguidor de linha

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = A2;
int leitor_de_linha_esquerda = A3;

int contraste = 650;

//Sumô



//labirinto

int controle_labirinto = 0;
int distancia_labirinto = 1;

/* VARIAVEIS A DEFINIR */

int direcao = 0;
int valor_minimo_leitura_linha_sumo = 650; /*  +CONFIGURAR-, Valor da leitura da linha branca para o robo parar e ficar na preta*/
int distancia_minima_inimigo_ultra = 45; /*  +CONFIGURAR-, Distancia do Robo inimigo minima para ele avançar pelo ultra, inimigo pelo ultra em cm*/
int distancia_minima_inimigo_infra = 0; /*Setar como 1 caso Digital, Distancia do Robo inimigo minima para ele avançar pelo infra*/
int tempo_ir_atras_sumo_linha = 1000; /* +CONFIGURAR-,  Tempo que o robo deve ir para tras quando ler a linha branca*/
int tempo_ir_atras_sumo_inimigo = 0; /* Tempo para ele ir para tras caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
int tempo_ir_frente_sumo = 0; /* Tempo para ele ir para frente caso detecte o inimigo, por padrão para não interferir nas leituras 0 */
int tempo_ir_direta_sumo = 0; /* Tempo para ele ir para direita caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
int tempo_ir_esquerda_sumo = 0; /* Tempo para ele ir para esquerda caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
int Contagem_Para_Entrar_Sumo = 0; /* Contagem para o delay antes de entrar na linha sumo, definido como 0 e depois tranformado em 1 na primeira rodada para o delay não se repetir */
int ja_fui_para_atras; /* Variavel para ele saber se já foi para trás atrás do inimigo */
int ja_fui_para_atras_tempo_frente = 0; /*CONFIGURAR- , Tempo para ele ir para frente logo após ter ido para trás atrás do inimigo e ele não estiver mais lá  */

int delay_da_primeira_vez_que_o_sumo_rodar;
int tempo_do_delay_da_primeira_vez_que_o_sumo_rodar  = 10000; /*CONFIGURAR*/

/*______________________________________________________________*/


//botão de acionamento (inicial)
int buzzer = 9;
int botao = 3;
int leitura_botao = 0;

int X = 0;
int Y = 0;
int Z = 0;

int K = 0;

void setup() {
  //colocar direita 11 esquerda 10
  direita.attach(10); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */

  Serial.begin(9600);

pinMode(buzzer, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led1, OUTPUT);
 
  pinMode(botao, INPUT);

  pinMode(trigger_frente, OUTPUT);

  pinMode(leitor_echo_frente, INPUT);

  //apagar analogico nao precisa anunciar

  //pinMode(leitor_de_linha_direita, INPUT);
 // pinMode(leitor_de_linha_esquerda, INPUT);

  pinMode(leitor_ldr, INPUT);

  pinMode(led, OUTPUT);


esquerda.write(90);
direita.write(90);

}


void loop() {


//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------
  
  
  if(modo == 1){
  
  sing(2);
  sing(1);
  
 }
  

   botao_troca();


   Serial.println(modo);

}
  
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------








void botao_troca(){

leitura_botao = digitalRead(botao);

if (leitura_botao == 1 && X == 0) {

   
digitalWrite(led1, HIGH);
modo = 1;    
X = 1;

do{
  
  delay(50);
  
  leitura_botao = digitalRead(botao);
  
}while(leitura_botao == 1);

  

  } else {

if(leitura_botao == 1 && Y == 0 && X == 1){

digitalWrite(led2, HIGH);

modo = 2;
Y = 1;

do{
  
  delay(50);
  
  leitura_botao = digitalRead(botao);
  
}while(leitura_botao == 1);


}else{
if(leitura_botao == 1 && Y == 1 &&  Z == 0 && X == 1){

digitalWrite(led3, HIGH);

modo = 3;
Z = 1;

do{
  
  delay(50);
  
  leitura_botao = digitalRead(botao);
  
}while(leitura_botao == 1);

   
}
}
}
 

}











int song = 0;

void sing(int s) {
  K = 0;
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      
      
     
      
      
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(melodyPin, underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
      
    }
    
  } else {
 
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      
      
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo1[thisNote];
 
      buzz(melodyPin, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
      
      
    }
  }
}

void labirinto(){

}


void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
 
}




  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------


void RGB_RED(){
  
  
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
}
void RGB_GREEN(){
  
  
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
}
void RGB_BLUE(){
  
  
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
}







void leitura_linear(int tempo) {

  

  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);



  Serial.print("direita  ");
  Serial.println(leitura_de_linha_direita);
  Serial.print("esquerda ");
  Serial.println(leitura_de_linha_esquerda);



  if (leitura_de_linha_direita >= contraste && leitura_de_linha_esquerda < contraste) {

    ir_esquerda(tempo);
    

  } else {
    if (leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita < contraste ) {

      ir_direita(tempo);
      
      
    } else {

      ir_frente(0);
        
      }



    }
  }

void star_wars(){
  
  
  
   // Set up a counter to pull from melody1[] and beats1[]
  for (int i=0; i<MAX_COUNT; i++) {
    toneM = melody1[i];
    beat = beats1[i];
 
 
      leitura_botao = digitalRead(botao);
      if(leitura_botao == 1 || K == 1){
        K = 1;
       i = MAX_COUNT;
        
      }else{
 
 
    duration = beat * tempo; // Set up timing
 
    playTone(); // A pause between notes
    delayMicroseconds(pause);
      }
    }
  
  
}


void playTone() {
  long elapsed_time = 0;
  if (toneM > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {
 
      digitalWrite(buzzer,HIGH);
      delayMicroseconds(toneM / 2);
 
      // DOWN
      digitalWrite(buzzer, LOW);
      delayMicroseconds(toneM / 2);
 
      // Keep track of how long we pulsed
      elapsed_time += (toneM);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}



void leitor_de_luz() {

  leitura_ldr = analogRead(leitor_ldr);
  
Serial.println(leitura_ldr);
  
  // 1 = numero a ser definido
  if (leitura_ldr <= 850) {

    digitalWrite(led, HIGH);

  } else {

    digitalWrite(led, LOW);


  }


}






void ultrasonico_frente() {


  delayMicroseconds(2);
  digitalWrite(trigger_frente, HIGH);
  delayMicroseconds(13);
  digitalWrite(trigger_frente, LOW);
    delayMicroseconds(2);
  

  leitura_echo_frente = pulseIn(leitor_echo_frente, HIGH);

  distancia_ultrasonica_frente = leitura_echo_frente / 29 / 2;



 /* Serial.print(distancia_ultrasonica_frente);
  Serial.println("cm");
  Serial.println();*/



}



void sumo() {

 


  /*VERIFICANDO SE JÁ FOI PARA TRÁS E SE O INIMIGO AINDA ESTÁ ATRÁS DELE, CASO NÃO ESTEJA ELE IRÁ PARA FRENTE ( RECUARÁ ) POR UM CERTO TEMPO*/

  /*FAZENDO LEITURA DA LINHA*/

  
    
  
  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda); /* Leitura de Linha para Ver se está Na Arena*/
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);

  /*
  Caso queira testar os valores:
  Serial.print("Direita  ");
  Serial.println(leitura_de_linha_direita);
  Serial.print("Esquerda ");
  Serial.println(leitura_de_linha_esquerda);
  */


  /* REAÇÕES CASO ESTEJA NA LINHA BRANCA */

  if (leitura_de_linha_direita < valor_minimo_leitura_linha_sumo) {
    ir_atras(tempo_ir_atras_sumo_linha);
    // tenque ser diferente de 0          /* Ir para trás caso Esteja na linha branca */
  } else {
    if (leitura_de_linha_esquerda < valor_minimo_leitura_linha_sumo) {
      ir_atras(tempo_ir_atras_sumo_linha);
      // tenque ser diferente de 0
    }
  }


    ultrasonico_frente();
    
    if (distancia_ultrasonica_frente < distancia_minima_inimigo_ultra) {
      ir_frente(tempo_ir_frente_sumo);
      // tempo_ir_frente_sumo tenque ser = 0
    } else {

            ir_direita(0);            
            
    }

        
}



//----------------------------------inicio--------direcoes-------------------------------------------------------------------------------------------------------------------------------

// ir frente direita = 0 ir frente esquerda = 180

//pode ser necessaria uma completa mudança nas funçoes de direçoes

void  ir_esquerda(int tempo) {

  direita.write(180);
  esquerda.write(180);
  delay(tempo);


}
void  parado(int tempo) {


  direita.write(90);
  esquerda.write(90);
  delay(tempo);


}
void  ir_direita(int tempo) {


  direita.write(0);
  esquerda.write(0);
  delay(tempo);

}
void ir_frente(int tempo) {

  direita.write(0);
  esquerda.write(180);

  delay(tempo);

}
void ir_atras(int tempo) {


  direita.write(180);
  esquerda.write(0);

  delay(tempo);

}

//----------------------------------fim--------direcoes-------------------------------------------------------------------------------------------------------------------------------





