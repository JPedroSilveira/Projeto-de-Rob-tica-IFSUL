
/*                         
█████████████████████████████████████████
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       ███████
█▒▒█████▒▒██▒▒▒██▒▒█████▒▒█████▒▒▒███▒▒▒█      █           █
█▒▒█▒▒▒█▒▒█▒█▒█▒█▒▒█▒▒▒▒▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█     █             █
█▒▒█▒▒▒█▒▒█▒▒█▒▒█▒▒███▒▒▒▒█▒▒██▒▒█████▒▒█    █               █
█▒▒█▒▒▒█▒▒█▒▒▒▒▒█▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█     █             █
█▒▒█████▒▒█▒▒▒▒▒█▒▒█████▒▒█████▒▒█▒▒▒█▒▒█      █           █
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█    ███         ███
█████████████████████████████████████████   


Versão avançada EEPROM seguidor_linear_melhorado calibrador_direcional (com música) semi-FUNCIONAL 

*/
 
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
#include <EEPROM.h>

Servo direita;
Servo esquerda;

// musica

int buzzer = 9;

// parte do sistema de diagnostico

int led1 = 4;
int led2 = 6;
int led3 = 8;

//troca por botao

int modo = 0;

//seguidor de linha

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = A2;
int leitor_de_linha_esquerda = A3;

//botão de acionamento (inicial)

int botao1 = 3;
int leitura_botao1 = 0;

//variaveis de estado do botao;

int X = 0;
int K1 = 0;
int G1 = 0;

int K2 = 0;

int contraste_melhorado = 0;

int botao2 = 2;
int leitura_botao2 = 0;

int calibrar = 0;
unsigned long Time = 0;

 int direita_frente = 0;
 int esquerda_frente = 0;
 int direita_atras = 0;
 int esquerda_atras = 0;

void setup() {
  
  
  direita.attach(10); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */

  Serial.begin(9600);

  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  
  pinMode(buzzer, OUTPUT);
 
  esquerda.write(90);
  direita.write(90);
  
  ler_direcoes();

contraste_melhorado = EEPROM_read(0);
Serial.println(contraste_melhorado);

/*forçar calibragem linear
calibrar=1;
*/
/*forçar calibragem direcional
calibrar=2;
*/
/*forçar mudança de modo
modo=1;
*/

}

void loop() {
//------------------------------------------------------------
  
  botao_troca();
  botao_calibrador();
  calibrador_linear();
  calibrador_direcoes();

  if(modo == 1){
    
    leitura_linear_melhorada(0);    
    
  }  
  
  
   if(modo == 0 || K1 == 0){
  
  sing(1);
  sing(2);
 
 }else{
   
   digitalWrite(buzzer, LOW);
   
 }

//------------------------------------------------------------
}

void ler_direcoes(){
  
  
 direita_frente = EEPROM_read(1);
 esquerda_frente = EEPROM_read(2);
 
 if(direita_frente = 180){
   
  direita_atras = 0;
   
 }else{
   
   direita_atras = 180;
   
 }
 
  if(esquerda_frente = 180){
   
  esquerda_atras = 0;
   
 }else{
   
   esquerda_atras = 180;
   
 }
  
}


void calibrador_linear(){
  
  if(calibrar == 1){
  
  Serial.println("coloque os leitores do robo no preto");
  delay(10000);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
 int leitura_de_linha_esquerda_preto = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_preto = analogRead(leitor_de_linha_direita);
  digitalWrite(led3, LOW); 
  
  Serial.println("coloque os leitores do robo no branco");
  delay(10000);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
 int leitura_de_linha_esquerda_branco = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_branco = analogRead(leitor_de_linha_direita);
  digitalWrite(led3, LOW);
 
 float pre_contraste_melhorado = (((leitura_de_linha_esquerda_preto + leitura_de_linha_direita_preto)/2)-((leitura_de_linha_esquerda_branco + leitura_de_linha_direita_branco)/2))/1.5;
 contraste_melhorado = round(pre_contraste_melhorado);
 Serial.println(contraste_melhorado);

EEPROM_write(contraste_melhorado, 0);

delay(500);
digitalWrite(led2, LOW);

calibrar = 0;
K2=0;
}
}

void calibrador_direcoes(){
  
  if(calibrar==2){
  
  digitalWrite(led3,HIGH);  
  delay(500);
  digitalWrite(led2,LOW);  
  delay(500);
  digitalWrite(led2,HIGH);
    
  int estado_direita_frente = 0, estado_esquerda_frente = 0;
  int estado_direita_atras = 180, estado_esquerda_atras = 180;
    
  direita.write(90);
  esquerda.write(90);    
  Serial.println("verifique se o robo esta parado se nao estiver e importante que voce o deixe antes de iniciar a calibragem");  
  delay(10000);  
  Serial.println("aperte o botao se o motor direito esta indo frente");
  esquerda.write(90);
  direita.write(180);
  Time = millis();
  do{
  
  if(calibrador_direcoes_botao() == 1){
    
    estado_direita_frente = 180;
    estado_direita_atras = 0;  
   
  }
    
  }while(millis()-Time <= 10000);
  
  Serial.println("aperte o botao se o motor esquerdo esta indo frente");
  direita.write(90);
  esquerda.write(180);
  Time = millis();
  do{
  
  if(calibrador_direcoes_botao() == 1){
    
    estado_esquerda_frente = 180;
    estado_esquerda_atras = 0;  
   
  }
    
  }while(millis()-Time <= 10000);
    
  EEPROM_write(estado_direita_frente, 1);
  EEPROM_write(estado_esquerda_frente, 2);
  
  direita_frente = estado_direita_frente;
  esquerda_frente = estado_esquerda_frente;
  direita_atras = estado_direita_atras;
  esquerda_atras = estado_esquerda_atras;
  
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  direita.write(90);
  esquerda.write(90);
  
calibrar = 0;
K2=0;
  }
}

  int calibrador_direcoes_botao(){
  int ativar = 0;
  
leitura_botao2 = digitalRead(botao2);

if (leitura_botao2 == 0) {

 ativar = 1;    

do{
  
  delay(50);
  
  leitura_botao2 = digitalRead(botao2);
  
}while(leitura_botao2 == 0);

}  
  return ativar;
}

void botao_troca(){
 
leitura_botao1 = digitalRead(botao1);

if(K1 == 1 && G1 == 0){

  G1 = 1;
  leitura_botao1 = 0;
  
}

if (leitura_botao1 == 0 && X==0) {
 
digitalWrite(led1, HIGH);

modo = 1;    
X = 1;
K1 = 1;

do{
  
  delay(50);
  
 leitura_botao1 = digitalRead(botao1);
  
}while(leitura_botao1 == 0);

}  
}

void botao_calibrador(){
  
 
leitura_botao2 = digitalRead(botao2);

if(K2 == 1){

  leitura_botao2 = 0;
  
}

if (leitura_botao2 == 0) {
 
digitalWrite(led2, HIGH);

calibrar = 1;    

do{
  
  delay(50);
  
  leitura_botao2 = digitalRead(botao2);
  
}while(leitura_botao2 == 0);

   Time = millis();
  do{
  
  if(calibrador_direcoes_botao() == 1){
    
    calibrar = 2;
   
  }
    
  }while(millis()-Time <= 4000);


}
}
  
  
void leitura_linear_melhorada(int tempo) {

  
  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);

  Serial.print("direita  ");
  Serial.print(leitura_de_linha_direita);
  Serial.print("  esquerda  ");
  Serial.println(leitura_de_linha_esquerda);

//direita > esquerda
  if (leitura_de_linha_direita-leitura_de_linha_esquerda >= contraste_melhorado) {
    
    ir_direita(tempo);    

//esquerda > direita
  } else if (leitura_de_linha_esquerda-leitura_de_linha_direita >= contraste_melhorado) {

      ir_esquerda(tempo);
      
    } else {

      ir_frente(tempo);
      
    }         
  }  


void  parado(int tempo) {


  direita.write(90);
  esquerda.write(90);
  delay(tempo);


}
void  ir_esquerda(int tempo) {

  direita.write(direita_frente);
  esquerda.write(esquerda_atras);
  delay(tempo);


}
void  ir_direita(int tempo) {


  direita.write(direita_atras);
  esquerda.write(esquerda_frente);
  delay(tempo);

}
void ir_atras(int tempo) {

  direita.write(direita_atras);
  esquerda.write(esquerda_atras);

  delay(tempo);

}
void ir_frente(int tempo) {


  direita.write(direita_frente);
  esquerda.write(esquerda_frente);

  delay(tempo);

}

void EEPROM_write(int Valor, int i){
//int(16bits) = -32,768 to 32767
  
    if (i*2+1 >= EEPROM.length() || i < 0) {
    Serial.println("Esta posicao não existe");
    }else{
  
  byte hiByte = highByte(Valor);
  byte loByte = lowByte(Valor);

  EEPROM.update(i*2, hiByte);
  EEPROM.update((i*2)+1, loByte);
  
  Serial.println("operacao de escrita realizada na EEPROM");
  
    }    
}

int EEPROM_read(int i){
//int(16bits) = -32,768 to 32767
  
    if (i*2+1 >= EEPROM.length() || i < 0) {
    Serial.println("Esta posicao nao existe");
    }else{
  
  byte hiByte = EEPROM.read(i*2);
  byte loByte = EEPROM.read((i*2)+1);;

  int Valor_byte  = word(hiByte, loByte);
 
  Serial.println("operacao de leitura realizada na EEPROM");
  
  return Valor_byte;
  
    }    
}

void EEPROM_tamanho(){
//int(16bits) = -32,768 to 32767
  
  Serial.print(EEPROM.length()/2);
  Serial.print(" posicoes na EEPROM(16bits)");
  Serial.print("\ncomecando em 0 e terminando em ");
  Serial.println((EEPROM.length()/2)-1);
  
}




int song = 0;

void sing(int s) {
  
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      
      leitura_botao1 = digitalRead(botao1);
      leitura_botao2 = digitalRead(botao2);
      
      if(leitura_botao1 == 0 || K1 == 1 || leitura_botao2 == 0 || K2 == 1){
       size = thisNote;
       if(leitura_botao1 == 0){
         
        K1 = 1;
       
       }
       if(leitura_botao2 == 0){
        K2 = 1;
       }
      }else{
     
      
      
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
    }
    
  } else {
 
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      
      leitura_botao1 = digitalRead(botao1);
      leitura_botao2 = digitalRead(botao2);
      
      if(leitura_botao1 == 0 || K1 == 1 || leitura_botao2 == 0 || K2 == 1){
       size = thisNote;
       if(leitura_botao1 == 0){
         
        K1 = 1;
       
       }
       if(leitura_botao2 == 0){
         
        K2 = 1;
        
       }
      }else{
 
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

