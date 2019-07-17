
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


Versão simples (sem música) FUNCIONAL 


*/
 


#include <Servo.h>

Servo direita;
Servo esquerda;

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

int contraste = 750;

//botão de acionamento (inicial)

int botao = 3;
int leitura_botao = 0;

//variaveis de estado do botao;

int X = 0;

int K = 0;
int G = 0;


void setup() {
  
  
  direita.attach(10); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */

  Serial.begin(9600);

  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(botao, INPUT);
 
  esquerda.write(90);
  direita.write(90);
   
}

void loop() {
//------------------------------------------------------------
  
  
  
  botao_troca();

  if(modo == 1){
    
    leitura_linear(0);    
    
  }  



//------------------------------------------------------------
}


void botao_troca(){


  
leitura_botao = digitalRead(botao);

if (leitura_botao == 1 && X==0) {
 
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
modo = 1;    
X = 1;

do{
  
  delay(50);
  
  leitura_botao = digitalRead(botao);
  
}while(leitura_botao == 1);

}  
}


void leitura_linear(int tempo) {

  

  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);


/*
  Serial.print("direita");
  Serial.println(leitura_de_linha_direita);
  Serial.print("esquerda");
  Serial.println(leitura_de_linha_esquerda);
*/


  if (leitura_de_linha_direita >= contraste && leitura_de_linha_esquerda < contraste) {

    ir_direita(tempo);    

  } else if (leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita < contraste ) {

      ir_esquerda(tempo);
      
    }  else {

      ir_frente(tempo);
      
    }         
  }


void  parado(int tempo) {


  direita.write(90);
  esquerda.write(90);
  delay(tempo);


}
void  ir_esquerda(int tempo) {

  direita.write(180);
  esquerda.write(180);
  delay(tempo);


}
void  ir_direita(int tempo) {


  direita.write(0);
  esquerda.write(0);
  delay(tempo);

}
void ir_frente(int tempo) {

  direita.write(0);
  esquerda.write(180);

  delay(tempo);

}
void ir_atras(int tempo) {


  direita.write(180);
  esquerda.write(0);

  delay(tempo);

}
