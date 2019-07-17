#include <Servo.h>

Servo direita;
Servo esquerda;

int resposta = A5;
int pulso = 7;
long duracao = 0; 
long distancia = 0;

unsigned long tempo_modo = 0;
int carregador_modo = 0;
int modo = 1;
int pre_modo = 1;
int timer_modo = 0;
int zero_modo = 0;

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = A2;
int leitor_de_linha_esquerda = A3;

int contraste = 600;

void setup() {
  direita.attach(12);
  esquerda.attach(11);
  
  Serial.begin(9600);
  pinMode(pulso, OUTPUT);
  
  
}



  
void loop() {
  

 //-----------------------------------------------------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------------------------------------------------
 

//leitura_linear(0);

  
troca_de_modo();
  
 
  delay(300);
 

  
  
  
  
  
  
  
  
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
    zero_modo = 0;
   
   }else{
   if(leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita < contraste ){
    
    ir_esquerda(tempo);     
     zero_modo = 0;
   }else{
    
     if(leitura_de_linha_esquerda <= contraste && leitura_de_linha_direita <= contraste){
       
     ir_frente(tempo);
     zero_modo = 0;
     }
      
       troca_de_modo();
 
 }}
 
 }
   
   void troca_de_modo(){
     
     leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
     leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   
   
   
     
     if(leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita >= contraste){
     
     if(carregador_modo == 0 && zero_modo == 0){
       
       tempo_modo = millis();
       carregador_modo = 1;
       timer_modo = 1;
       Serial.println(carregador_modo);
       //primeira vez ao passar da linha dupla
       
     }else if(carregador_modo == 1 && zero_modo == 0){
       
       carregador_modo = 2;
       pre_modo = 2;
       Serial.println(carregador_modo);
     }else if(carregador_modo == 2 && zero_modo == 0){
      carregador_modo = 3;
      pre_modo = 3;
      Serial.println(carregador_modo);
      
     } 
     
     zero_modo = 1; 
     
     }else{
 
       zero_modo = 0;
    
     }
     
    
     
 if((unsigned long)millis()-tempo_modo >= 4000 && timer_modo == 1){
   
  tempo_modo = millis(); 
  
   timer_modo = 0;
   carregador_modo = 0;
   
   modo = pre_modo;
   Serial.println("passados 4000 miliseconds");
   Serial.print("modo = ");
   Serial.print(modo);
   Serial.println();
   zero_modo = 0;
   
   
 }

     
     
     
     
     
   }
   
   
   void ultrasonico(){
  
  
  
  digitalWrite(pulso, HIGH);
  delayMicroseconds(10);
  digitalWrite(pulso, LOW);
  
  duracao = pulseIn(resposta, HIGH);
  
  distancia = duracao /29 / 2; 
  
  Serial.print(distancia);
  Serial.println("cm");
  Serial.println();
  
  delay(100);
  
  
  
      
    
   if(distancia < 25){
   ir_frente(0); 
   
  }else{
    if(distancia >= 25){
    ir_atras(0);
    
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
  



