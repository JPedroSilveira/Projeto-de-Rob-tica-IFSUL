#include <Servo.h>

Servo direita;
Servo esquerda;

// testes

int led1 = 10;
int led2 = 9;
int led3 = 8;
int led4 = 7;
int led5 = 6;

unsigned long controle_millis = 0;

int C = 0;
int reset = 0;


void setup() {
  
  direita.attach(12);
  esquerda.attach(11);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  
  Serial.begin(9600);
  
}

//---------------------------------------------------------------------------------

void loop() {
  

  
  
  
  
  
  
  
  
  
  
  
  
}

//---------------------------------------------------------------------------------


void controle_direcional(int tempo, int direcao, int modo){

/*
direcao:
0 = frente
1 = atras
2 = direita
3 = esquerda
4 = parado
*/

if(direcao != reset){
  
 C = 0;
 
 reset = direcao;

}

if(modo == 1){
  
 controle_millis = millis(); 
  
  
  
}else if((unsigned long)(millis() - controle_millis >= tempo)){
   
  controle_millis = millis();
  
  if(direcao == 0){
    
    if(C == 0){
    digitalWrite(led1,HIGH);
    C = 1;
    }else{
    digitalWrite(led1,LOW);
    C = 0;
    }
    
    
    
  }else if(direcao == 1){
    
    if(C == 0){
    digitalWrite(led2,HIGH);
    C = 1;
    }else{
    digitalWrite(led2,LOW);
    C = 0;
    }
    
    
    
    
  }else if(direcao == 2){
    
    if(C == 0){
    digitalWrite(led3,HIGH);
    C = 1;
    }else{
    digitalWrite(led3,LOW);
    C = 0;
    }
    
    
    
    
  }else if(direcao == 3){
    
    if(C == 0){
    digitalWrite(led4,HIGH);
    C = 1;
    }else{
    digitalWrite(led4,LOW);
    C = 0;
    }
    
    
    
    
  }else if(direcao == 4){
    
    if(C == 0){
    digitalWrite(led5,HIGH);
    C = 1;
    }else{
    digitalWrite(led5,LOW);
    C = 0;
    }
    
  }    
  
}}
  
  
  
  
  
  
  









void ir_frente(){
  
  direita.write(180);
  esquerda.write(180);
  
  
  
  
}


void ir_atras(){
  
  direita.write(0);
  esquerda.write(0);
  
  
  
  
}


void ir_direita(){
  
  direita.write(0);
  esquerda.write(180);
  
  
  
  
}



void ir_esquerda(){
  
  direita.write(180);
  esquerda.write(0);
  
  
  
  
  
}


void parado(){
  
  
  direita.write(90);
  esquerda.write(90);
  
  
  
}

