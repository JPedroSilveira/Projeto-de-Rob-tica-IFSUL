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
 
 
//  leitura_linear(50);

  ir_direita(2000);
  parado(2000);
  ir_esquerda(2000);
  ir_frente(2000);
  ir_atras(2000);
  ir_frente(1000);
  ir_atras(1000);
  ir_frente(500);
  ir_atras(500            );
  
  
  
  
  
  
  

  
  
  
  
  
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------
  }
  
 void leitura_linear(int tempo){
   
   leitura_de_linha_esquerda = digitalRead(leitor_de_linha_esquerda);
   leitura_de_linha_direita = digitalRead(leitor_de_linha_direita);
   
   
   if(controle_temporal - millis() == 500)
   
   controle_temporal = millis();
   
   Serial.println("esquerda "+leitura_de_linha_esquerda);
   Serial.println("direita "+leitura_de_linha_direita);
   
   
   
   
   if(leitura_de_linha_esquerda == 1){
     
    ir_direita(tempo);
    buzzer(50, 50);
   
   }else{
   if(leitura_de_linha_direita == 1){
    
    ir_esquerda(tempo); 
    buzzer(50, 50);
   
   }} 
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



void  ir_esquerda(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(CDE);
 esquerda.write(CA); 
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

void  ir_direita(int tempo){
     
int tempo_controle = 0;
   do{
  
 direita.write(CA);
 esquerda.write(CDE);
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
 }
 
 void ir_frente(int tempo){
   
 int tempo_controle = 0;
   do{
  
 direita.write(CF);
 esquerda.write(CF);
 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
 }
 
void ir_atras(int tempo){
   
int tempo_controle = 0;
   do{
  
 direita.write(CA);
 esquerda.write(CA);
 
  delay(1);
  tempo_controle++;
   }while(tempo_controle < tempo);
   
}
  
  
  



