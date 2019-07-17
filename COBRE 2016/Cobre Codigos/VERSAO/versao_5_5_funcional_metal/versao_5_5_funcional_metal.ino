#include <Servo.h>

Servo direita;
Servo esquerda;

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = 2;
int leitor_de_linha_esquerda = 3;

int buzzer_ = 13;
//controle

int CF = 180;
int CA = 30;
int CDE = 150;

// CF = controle_frente CA = controle_atras CDE = controle_direita_esquerda
int acumulador = 0;
int controle_temporal = 0;

void setup() {
  direita.attach(12);
  esquerda.attach(11);
  
  pinMode(buzzer_,OUTPUT);
  pinMode(leitor_de_linha_direita, INPUT);
  pinMode(leitor_de_linha_esquerda, INPUT);
  
  Serial.begin(9600);
}



  
void loop() {
  

 //-----------------------------------------------------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------------------------------------------------
 
 
  leitura_linear(1);


  
  
  
  
  
  

  
  
  
  
  
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------
  }
  
 void leitura_linear(int tempo){
   
   
   
   leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
   leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   
   
   
   
   
   
   Serial.println(leitura_de_linha_direita);
   Serial.println(leitura_de_linha_esquerda);
   
   
   
   if(leitura_de_linha_direita >= 600 && leitura_de_linha_esquerda < 600){
     
    ir_direita(tempo);
    
   
   }else{
   if(leitura_de_linha_esquerda >= 600 && leitura_de_linha_direita < 600 ){
    
    ir_esquerda(tempo);     
     
   }else{
     if(leitura_de_linha_esquerda >= 600 && leitura_de_linha_direita >= 600){
     ir_frente(tempo);
     }else{
       
       ir_frente(tempo);
       
       
     
 }}} 
   }
   
   

void buzzer (int tempo,int frequencia){
  
  // tempo = 5; frequencia  = 1
  
  int tempo_frequencia = 0;
  int milisegundos = 0;
  acumulador  = millis();
   
  
  do{   
    
    milisegundos = millis() - acumulador;
    
 if(tempo_frequencia - milisegundos == frequencia){
       
 tempo_frequencia = milisegundos;
 digitalWrite(buzzer_,HIGH);
 
  }
  
  
  digitalWrite(buzzer_,LOW);
  
  }while(milisegundos <= tempo);
  
 }



void  ir_direita(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(CDE);
 esquerda.write(CF); 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
  }

void  parado(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(90);
 esquerda.write(90); 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
  }

void  ir_esquerda(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(CA);
 esquerda.write(CA);
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
 }
 
 void ir_frente(int tempo){
   
 int tempo_controle = 0;
   do{
  
 direita.write(CF);
 esquerda.write(CA);
 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
 }
 
void ir_atras(int tempo){
   
int tempo_controle = 0;
   do{
  
 direita.write(CA);
 esquerda.write(CF);
 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
}
  
  
  



