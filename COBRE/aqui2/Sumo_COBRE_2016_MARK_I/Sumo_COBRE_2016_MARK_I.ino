/*IR
 
const int IR_atras_direita = 0;
const int Receptor_IR_direita = 0;
int distancia_IR_direita;

const int IR_atras_esquerda = 0;
const int Receptor_IR_esquerda  = 0;
int distancia_IR_esquerda;
*/

#include <Servo.h>
#include <EEPROM.h>

Servo direita;
Servo esquerda;

//BUTTON

const int button = 0;
int button_read = 0;
int Go = 0;
int i;

//ULTRASONICO
const int TrigPin_frente = 0;
const int EchoPin_frente = 0;
int distancia_frente;
long leitura_echo;

const int TrigPin_direita = 0;
const int EchoPin_direita = 0;
int distancia_direita;

//QTI
const int pin_Qti_direita = A1;
const int pin_Qti_esquerda = A0;
int Qti_esquerda;
int Qti_direita;

//EEPROM velocity variables

int direita_frente = 0;
int esquerda_frente = 0;
int direita_atras = 0;
int esquerda_atras = 0;

//RGB

const int redPin = 0;
const int greenPin = 0;
const int bluePin = 0;

void setup() {
  
  direita.attach(5);  /*Motor Direita */
  esquerda.attach(6); /*Motor Esquerda */
 
  esquerda.write(90);
  direita.write(90);

  //Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  pinMode(button, INPUT_PULLUP);

  pinMode(TrigPin_frente, OUTPUT);
  pinMode(EchoPin_frente, INPUT);
  
  pinMode(TrigPin_direita, OUTPUT);
  pinMode(EchoPin_direita, INPUT);
  
  ler_direcoes();
  RGB_color("red");
  do{  
    if(button_read==0){
     button_read = digitalRead(button);
    }else{
     /* 10 segundos de delay antes do inicio do sumo*/
      RGB_color("yellow");
      delay(10000); 
      RGB_color("green");
      Go=1; 
    }
  }while(Go==0);
}

void loop() {

  Qti_esquerda = analogRead(pin_Qti_esquerda);
  Qti_direita = analogRead(pin_Qti_direita);
  /*
  Caso queira testar os valores:
  Serial.print("Direita  ");
  Serial.println(Qti_direita);
  Serial.print("Esquerda ");
  Serial.println(Qti_esquerda);
  */

  /*Reações caso esteja na linha branca*/
  if (Qti_direita < 500 || Qti_esquerda < 500) {
    ir_atras();
    delay(1000);
  }

  /*Que comece a luta...*/
  ultrasonico_frente();
  if(distancia_frente < 40) {
    ir_frente();
    delay(1000);
  }else{
    ultrasonico_direita();
    if(distancia_direita < 40){
      ir_direita(); 
      delay(1000);                  
    }else{
      ir_esquerda();
      delay(1000);
    }
  }
}//FIM LOOP

void ultrasonico_frente(){

  delayMicroseconds(2);
  digitalWrite(TrigPin_frente, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_frente, LOW);
  delayMicroseconds(2);
  
  leitura_echo = pulseIn(EchoPin_frente, HIGH, 100000);
  if(leitura_echo == 0){
    distancia_frente = 450;
  }else{
    distancia_frente = leitura_echo / 58;
  }
  /*
  Serial.print("distancia direita: ");
  Serial.print(distancia_direita);
  Serial.println("cm");
  */
}//FIM DO ULTRASONICO FRENTE

void ultrasonico_direita(){

  delayMicroseconds(2);
  digitalWrite(TrigPin_direita, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_direita, LOW);
  delayMicroseconds(2);
  
  leitura_echo = pulseIn(EchoPin_direita, HIGH, 100000);
  if(leitura_echo == 0){
  distancia_direita = 450;
  }else{
  distancia_direita = leitura_echo / 58;
  }

  /*
  Serial.print("distancia direita: ");
  Serial.print(distancia_direita);
  Serial.println("cm");
  */

}//FIM DO ULTRASONICO DIREITA

/*void infra_atras(){  
              
  for(i = 0 ; i < 33 ; i++){
    digitalWrite(IR_atras, HIGH);
    delayMicroseconds(13);
    digitalWrite(IR_atras,LOW);
    delayMicroseconds(13);
  }      
    distancia_atras = digitalRead(Receptor_IR);
    
    Serial.print(leitura_infra_direita);
    Serial.println("cm");
    Serial.println(); 
               
}
*/

void ir_atras() {
  direita.write(direita_atras);
  esquerda.write(esquerda_atras);
}
void ir_frente() {
  direita.write(direita_frente);
  esquerda.write(esquerda_frente);
}
void  ir_esquerda() {
  direita.write(direita_frente);
  esquerda.write(esquerda_atras);
}
void  ir_direita() {
  direita.write(direita_atras);
  esquerda.write(esquerda_frente);
}

//Funções de pré sumo

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
 
 /*
 Serial.println("------------------------------------------------------------------------------------------------------");
 Serial.println("frente direita esquerda");
 Serial.println(direita_frente);
 Serial.println(esquerda_frente);
 Serial.println("------------------------------------------------------------------------------------------------------");
 Serial.println("atras direita esquerda");
 Serial.println(direita_atras);
 Serial.println(esquerda_atras);
 Serial.println("------------------------------------------------------------------------------------------------------");
 */
}

void set_RGB(int red, int green, int blue){

  //Red, Green, Blue: set the PWM level 0 to 255

  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  
}

void RGB_color(String color){
    
if(color.equalsIgnoreCase("black")){
set_RGB(0, 0, 0); 
}else if(color.equalsIgnoreCase("red")){
set_RGB(255, 0, 0);
}else if(color.equalsIgnoreCase("green")){
set_RGB(0, 255, 0);
}else if(color.equalsIgnoreCase("yellow")){
set_RGB(255, 255, 0);
}else if(color.equalsIgnoreCase("aqua")){
set_RGB(0, 255, 255);
}else if(color.equalsIgnoreCase("purple")){
set_RGB(255, 0, 255);
}else if(color.equalsIgnoreCase("blue")){
set_RGB(0, 0, 255);
}else if(color.equalsIgnoreCase("white")){
set_RGB(255, 255, 255);
}else{
/*  
Serial.println("cor nao existe");
Serial.println(color);
*/
}                      
}

//EEPROM

void EEPROM_write(int Valor, int i){
  //int(16bits) = -32768 to 32767
  
  if (i*2+1 >= EEPROM.length() || i < 0) {
    //Serial.println("Esta posicao não existe");
  }else{
  
    byte hiByte = highByte(Valor);
    byte loByte = lowByte(Valor);

    EEPROM.update(i*2, hiByte);
    EEPROM.update((i*2)+1, loByte);
  
    //Serial.println("operacao de escrita realizada na EEPROM");
    }    
}

int EEPROM_read(int i){
  //int(16bits) = -32768 to 32767
  
  if (i*2+1 >= EEPROM.length() || i < 0) {
    //Serial.println("Esta posicao nao existe");
  }else{
  
    byte hiByte = EEPROM.read(i*2);
    byte loByte = EEPROM.read((i*2)+1);;

    int Valor_byte  = word(hiByte, loByte);
 
    //Serial.println("operacao de leitura realizada na EEPROM");
  
    return Valor_byte;
  
    }    
}

/*
void EEPROM_tamanho(){
  //int(16bits) = -32768 to 32767
  
  Serial.print(EEPROM.length()/2);
  Serial.print(" posicoes na EEPROM(16bits)");
  Serial.print("\ncomecando em 0 e terminando em ");
  Serial.println((EEPROM.length()/2)-1);
  
}
*/

