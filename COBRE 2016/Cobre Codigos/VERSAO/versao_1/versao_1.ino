#include <Servo.h>

Servo direita;
Servo esquerda;

int controle_frente = 5;
int controle_atras = 6;
int controle_esquerda = 7;
int controle_direita = 8;

int leitura_controle_frente = 0;
int leitura_controle_atras = 0;
int leitura_controle_esquerda = 0;
int leitura_controle_direita = 0;

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = 0;
int leitor_de_linha_esquerda = 1;

//controle

int CF = 180;
int CA = 30;
int CDE = 150;




void setup() {
  direita.attach(12);
  esquerda.attach(11);
  
  pinMode(leitor_de_linha_direita, INPUT);
  pinMode(leitor_de_linha_esquerda, INPUT);
  
  pinMode(controle_frente, INPUT);
  pinMode(controle_atras, INPUT);
  pinMode(controle_esquerda, INPUT);
  pinMode(controle_direita, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------

  

  

  
void  ir_esquerda(int tempo){
     
int tempo_controle = 0;
   do{
  
 esquerda.write(CDE);
 
  delay(1);
  
   }while(tempo_controle < tempo);
  
 }
 

void  ir_direita(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(CDE);
 
  delay(1);
  
   }while(tempo_controle < tempo);
   
 }
 
 void ir_frente(int tempo){
   
 int tempo_controle = 0;
   do{
  
 direita.write(CF);
 esquerda.write(CF);
 
  delay(1);
  
   }while(tempo_controle < tempo);
   
 }
 
void ir_atras(int tempo){
   
int tempo_controle = 0;
   do{
  
 direita.write(CA);
 esquerda.write(CA);
 
  delay(1);
  
   }while(tempo_controle < tempo);
   
 
}
  // CF = controle_frente CA = controle_atras CDE = controle_direita_esquerda
  
  

}
