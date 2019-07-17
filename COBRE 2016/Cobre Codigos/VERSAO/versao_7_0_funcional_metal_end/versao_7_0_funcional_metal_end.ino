#include <Servo.h>

 Servo direita;
Servo esquerda;

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = 2;
int leitor_de_linha_esquerda = 3;

int contraste = 600;

void setup() {
  direita.attach(12);
  esquerda.attach(11);
  
  pinMode(leitor_de_linha_direita, INPUT);
  pinMode(leitor_de_linha_esquerda, INPUT);
  
  Serial.begin(9600);
}



  
void loop() {
  

 //-----------------------------------------------------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------------------------------------------------
 

 leitura_linear(20);


  

  
 
  
 

  
  
  
  
  
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  //-----------------------------------------------------------------------------------------------------------------------------
  }
  
 void leitura_linear(int tempo){
   
   
   
   leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
   leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   
   
   
   
   
   Serial.print("direita  ");
   Serial.println(leitura_de_linha_direita);
   Serial.print("esquerda ");
   Serial.println(leitura_de_linha_esquerda);
   
   
   
   if(leitura_de_linha_direita >= contraste && leitura_de_linha_esquerda < contraste){
     
    ir_direita(tempo);
    
   
   }else{
   if(leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita < contraste ){
    
    ir_esquerda(tempo);     
     
   }else{
     
     /*
     if(leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita >= contraste){
     ir_frente(tempo);
     }else{
     */  
       ir_frente(tempo);
  
// }
 
 }}
 
 }
   
   

//----------------------------------inicio--------direcoes-------------------------------------------------------------------------------------------------------------------------------

void  ir_direita(int tempo){
          
 direita.write(180);
 esquerda.write(180); 
  delay(tempo);
  
   
  }
void  parado(int tempo){

  
 direita.write(90);
 esquerda.write(90); 
  delay(tempo);
  
  
  }
void  ir_esquerda(int tempo){
     

 direita.write(0);
 esquerda.write(0);
  delay(tempo);

 }
void ir_frente(int tempo){
  
 direita.write(180);
 esquerda.write(0);
 
  delay(tempo);
   
 } 
void ir_atras(int tempo){

  
 direita.write(0);
 esquerda.write(180);
 
  delay(tempo);
   
}

//----------------------------------fim--------direcoes------------------------------------------------------------------------------------------------------------------------------- 
  



