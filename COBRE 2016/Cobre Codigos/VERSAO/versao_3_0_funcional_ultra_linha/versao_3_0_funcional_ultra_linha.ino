//servo

#include <Servo.h>

Servo direita;
Servo esquerda;

//ultra

int leitor_echo = A5;
int trigger = 7;
long leitura_echo = 0; 
long distancia_ultrasonica = 0;

//leitor_de_modo

unsigned long tempo_modo = 0;
int carregador_modo = 0;
int modo = 1;
int pre_modo = 1;
int timer_modo = 0;
int zero_modo = 0;

//leitor_de_luz

int leitor_ldr = A4;
int leitura_ldr = 0;

int led = 13;

//seguidor de linha

int leitura_de_linha_direita = 0;
int leitura_de_linha_esquerda = 0;

int leitor_de_linha_direita = A2;
int leitor_de_linha_esquerda = A3;

int contraste = 600;



void setup() {
  //colocar direita 11 esquerda 10
  direita.attach(12);
  esquerda.attach(11);
  
  Serial.begin(9600);
  
  pinMode(leitor_echo, OUTPUT);
  pinMode(led, OUTPUT);
  
}



  
void loop() {
  

 //-----------------------------------------------------------------------------------------------------------------------------
 //-----------------------------------------------------------------------------------------------------------------------------
 
  
 
    
  
     if(modo == 1){
       
       leitura_linear(0);
       leitor_de_luz();
       leitor_de_modo();       
       
     }else if(modo == 2){
       
       labirinto();
       leitor_de_modo();
                  
     }else if(modo == 3){
       
       sumo();
       
     }   
  
  
  
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
      
      
 
 }}
 
 }
   
   
     
     
     
     
     
     
   void leitor_de_luz(){
     
      leitura_ldr = analogRead(leitor_ldr);
     // 1 = numero a ser definido
     if(leitura_ldr <= 1){
       
      digitalWrite(led, HIGH); 
       
     }else{
       
       digitalWrite(led, LOW);
       
       
     }
     
  
   }
   
   
   
   
   
   void leitor_de_modo(){
     
     int pular_millis = 0;
     leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
     leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   
   
   
     
     if(leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita >= contraste){
     
       ir_frente(0);
       
     if(carregador_modo == 0 && zero_modo == 0){
       
       tempo_modo = millis();
       carregador_modo = 1;
       timer_modo = 1;
       Serial.println(carregador_modo);
       //primeira vez ao passar da linha dupla
       
     }else if(carregador_modo == 1 && zero_modo == 0){
       
       carregador_modo = 2;
       
       Serial.println(carregador_modo);
     }else if(carregador_modo == 2 && zero_modo == 0){
      carregador_modo = 3;
      modo = modo + 1;
      pular_millis = 1;
      Serial.println(carregador_modo);
      
     } 
     
     zero_modo = 1; 
     
     }else{
 
       zero_modo = 0;
    
     }
     
     
     
 if((unsigned long)millis()-tempo_modo >= 4000 && timer_modo == 1 || pular_millis == 1){
   
  tempo_modo = millis(); 
  
   timer_modo = 0;
   carregador_modo = 0;
   
   Serial.println("passados 4000 miliseconds");
   Serial.print("modo = ");
   Serial.print(modo);
   Serial.println();
      
 }       
   }
   
   
   void ultrasonico(){
  
  
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  leitura_echo = pulseIn(leitor_echo, HIGH);
  
  distancia_ultrasonica = leitura_echo /29 / 2; 
  
  Serial.print(distancia_ultrasonica);
  Serial.println("cm");
  Serial.println();      
 
 /*   
   if(distancia < 25){
   ir_frente(0); 
   
  }else{
    if(distancia >= 25){
    ir_atras(0);
    
}}
*/
}

void labirinto(){
  
  
  
  
  
}

void sumo(){
  
  
  
  
  
  
}
   

//----------------------------------inicio--------direcoes-------------------------------------------------------------------------------------------------------------------------------
// ir frente direita = 0 ir frente esquerda = 180
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
  
 direita.write(0);
 esquerda.write(180);
 
  delay(tempo);
   
 } 
void ir_atras(int tempo){

  
 direita.write(180);
 esquerda.write(0);
 
  delay(tempo);
   
}

//----------------------------------fim--------direcoes------------------------------------------------------------------------------------------------------------------------------- 
  



