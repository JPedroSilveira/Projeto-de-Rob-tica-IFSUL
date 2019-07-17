
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


Versão avançada EEPROM seguidor_linear_(digital usando porta analog) calibrador_direcional (com música) semi-FUNCIONAL
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
 
  int atual = 0;
  unsigned long melody_Time[3] = {0,0,0};
  boolean melody_Reset[3] = {true,true,true};
  boolean melody_timeSet[3] = {true,true,true};
  int melody_before = 0;
 
 int melody1[78] = {
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

int tempo1[78] = {
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

int melody2[99] = {
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                 
  
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                       
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
  NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,
  
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4, 0,
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4
};

int tempo2[99] = {
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,
  
  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,
  
  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,
  
  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4,
  
  4,8,4,4,4,
  4,16,4,
  4,8,4,4,4,
  4,20,
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

int X = 0;

int contraste_melhorado = 0;

int botao2 = 2;
int leitura_botao2 = 0;

int calibrar = 0;
unsigned long Time = 0;

 unsigned long Time3 = 0;

 int direita_frente = 0;
 int esquerda_frente = 0;
 int direita_atras = 0;
 int esquerda_atras = 0;

void setup() {
  
  
  direita.attach(10); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */
  
  esquerda.write(90);
  direita.write(90);

  Serial.begin(9600);

  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

//caso seja necessario o uso de digital
 pinMode(leitor_de_linha_direita, INPUT);
 pinMode(leitor_de_linha_esquerda, INPUT);
  
 pinMode(buzzer, OUTPUT);
  
  ler_direcoes();

/*forçar calibragem linear
calibrar=1;
*/
/*forçar calibragem direcional
calibrar=2;
*/
/*forçar mudança de modo*
modo=1;
*/
}
//play(melody2 ,tempo2, sizeof(melody2)/sizeof(int), 0, 1);
void loop() {
//------------------------------------------------------------
  
  botao_troca();
  
  if(modo == 0){  
  botao_calibrador();
  calibrador_linear();
  calibrador_direcoes();
  }

  if(modo == 1){
    
    leitura_linear_melhorada(0);    
    play(melody2 ,tempo2, sizeof(melody2)/sizeof(int), 0, 1.3);
    
  }  
  
  
  if(modo == 0){
  
  play(melody1 ,tempo1, sizeof(melody1)/sizeof(int), 1, 1.3);
 
 }
   
 

//------------------------------------------------------------
}

int botao2_contador(int tempo){
int cont = 0;

leitura_botao2 = digitalRead(botao2);

if (leitura_botao2 == 0) {
  
Time3 = millis();
cont=1;

  do{
  
  if(calibrador_direcoes_botao() == 1){
    
    cont++;
    Time3 = millis();
   
  }
    
  }while(millis()-Time3 <= tempo);
  
}
return cont;
}


void ler_direcoes(){
  
  
 direita_frente = EEPROM_read(1);
 esquerda_frente = EEPROM_read(2);
 
 if(direita_frente == 180){
   
  direita_atras = 0;
   
 }else{
   
   direita_atras = 180;
   
 }
 
  if(esquerda_frente == 180){
   
  esquerda_atras = 0;
   
 }else{
   
   esquerda_atras = 180;
   
 }
 
 Serial.println("----------------------");
 Serial.println("frente direita esquerda");
 Serial.println(direita_frente);
 Serial.println(esquerda_frente);
 Serial.println("----------------------");
 Serial.println("atras direita esquerda");
 Serial.println(direita_atras);
 Serial.println(esquerda_atras);
 Serial.println("----------------------");
  
}



void calibrador_linear(){
  
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

}

void calibrador_direcoes(){
  
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
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  direita.write(90);
  esquerda.write(90);
  
  }


  int calibrador_direcoes_botao(){
    
  int ativar = 0;
  
leitura_botao2 = digitalRead(botao2);

if (leitura_botao2 == 0) {

 ativar = 1;    

do{
  
  delay(10);
  
  leitura_botao2 = digitalRead(botao2);
  
}while(leitura_botao2 == 0);

}  
  return ativar;
}

void botao_troca(){
 
leitura_botao1 = digitalRead(botao1);

if (leitura_botao1 == 0 && X==0) {
 
digitalWrite(led1, HIGH);

modo = 1;    
X = 1;

do{
  
  delay(10);
  
 leitura_botao1 = digitalRead(botao1);
  
}while(leitura_botao1 == 0);

}  
}

void botao_calibrador(){
  
 int resultado = botao2_contador(4000);
 
  if(resultado != 0){
    noTone(buzzer);
    
  digitalWrite(led2, HIGH);
    
switch(resultado){
  
  case 1:
  
  calibrador_linear();
  
  break;
  default:
  
  calibrador_direcoes();
  
  break;
  
  
  
}
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

void robot_speed(int speed_esquerda, int speed_direita){
  
  int speed_direita_high = speed_direita;
  int speed_direita_low = (speed_direita - 180)*-1;
  
  int speed_esquerda_high = speed_esquerda;
  int speed_esquerda_low = (speed_esquerda - 180)*-1;
  
  
  if(direita_frente == 180){
   
   direita_frente = speed_direita_high;
   direita_atras = speed_direita_low;  
    
  }else if(direita_frente == 0){
    
   direita_frente = speed_direita_low;
   direita_atras = speed_direita_high;
    
  }
  
    if(esquerda_frente == 180){
   
   esquerda_frente = speed_esquerda_high;
   esquerda_atras = speed_esquerda_low;  
    
  }else if(esquerda_frente == 0){
    
   esquerda_frente = speed_esquerda_low;
   esquerda_atras = speed_esquerda_high;
    
  }
  
  Serial.print("velocidade mudada com sucesso, velocidade esquerda agora é: ");
  Serial.print(speed_esquerda);
  Serial.print(" e direita é: ");
  Serial.println(speed_direita);
  
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

//----------------------------------------- direcoes especiais unicas não testadas ------------------------------------------------

void  ir_esquerda_unico(int tempo) {

  direita.write(direita_frente);
  esquerda.write(90);
  delay(tempo);


}
void  ir_direita_unico(int tempo) {


  direita.write(90);
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



void play (int *melody, int *tempo, int tamanho, int Magic_number, float tempo_Extra){

int tempo_Real = 1000/tempo[atual];

if(melody_before != 0 && melody_before != Magic_number){
  
  atual = 0;
  noTone(buzzer);
  melody_Reset[Magic_number] == true;
  melody_timeSet[Magic_number] == true;
  melody_before = Magic_number;
  
}



if(melody_Reset[Magic_number] == true){
  melody_Time[Magic_number] = millis();
  melody_Reset[Magic_number] = false;
}
  
  if(melody[atual]!=0){
  if(millis()-melody_Time[Magic_number] >= tempo_Real){
noTone(buzzer);
    if(tempo_Extra != 0){
if(melody_timeSet[Magic_number]==true){
tempo_Real=(tempo_Real*2)+(tempo_Real*tempo_Extra);
melody_timeSet[Magic_number]==false;
}


      if(millis()- melody_Time[Magic_number] >= tempo_Real){
  atual++;
  melody_Time[Magic_number]=millis();
  melody_timeSet[Magic_number]==true;
  }
    }else{

  atual++;
  melody_Time[Magic_number]=millis();
      
    }
  }else{
  tone(buzzer, melody[atual]);
  }
  }else if(melody[atual]==0){
    
   if(millis()-melody_Time[Magic_number] >= tempo_Real){
    atual++;
    melody_Time[Magic_number]=millis();
  }
  
  }
  if(atual >= tamanho){ 
  atual=0;
  melody_Reset[Magic_number] = true;
  }
}
