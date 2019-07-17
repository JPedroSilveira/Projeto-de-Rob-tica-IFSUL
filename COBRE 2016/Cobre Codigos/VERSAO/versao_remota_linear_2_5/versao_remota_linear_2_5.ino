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
 
  controle_remoto();
  leitura_linear(50);
  
  
  
  
  
  
  
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------
  }
  
 void leitura_linear(int tempo){
   
   leitura_de_linha_direita = digitalRead(leitor_de_linha_direita);
   leitura_de_linha_esquerda = digitalRead(leitor_de_linha_esquerda);
   
   Serial.println(leitura_de_linha_direita);
   Serial.println(leitura_de_linha_esquerda);
   
   if(leitura_de_linha_esquerda == 1){
   
   ir_direita(tempo);
     
   }else{
   if(leitura_de_linha_direita == 1){
    
    ir_esquerda(tempo); 
   
   }} 
   }


 void controle_remoto(){
  
   leitura_controle_frente = digitalRead(controle_frente);
   leitura_controle_atras = digitalRead(controle_atras);
   leitura_controle_direita = digitalRead(controle_direita);
   leitura_controle_esquerda = digitalRead(controle_esquerda);

  if(leitura_controle_atras == 1){
    
    ir_atras(50);
    
  }else{
   if(leitura_controle_frente == 1){
    
    ir_frente(50);
    
  }else{
   if(leitura_controle_esquerda == 1){
    
    ir_esquerda(50);
    
  }else{
  if(leitura_controle_direita == 1){
    
    ir_direita(50);
        
  }
  }
  }
  }
 }

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
  
  



