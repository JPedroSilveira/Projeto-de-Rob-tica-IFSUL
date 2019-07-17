
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
#include <EEPROM.h>

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
int contraste_melhorado = 0;

//direita = 900 esquerda = 300     direita>=900   esquerda<900: go direita
//direita = 900 esquerda = 300 direita-esquerda = 600>=200: go direita


//botão de acionamento (inicial)

int botao = 3;
int leitura_botao = 0;

//variaveis de estado do botao;

int X = 0;

// EEPROM

int C0,C1,C2,C3;
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

for(int i = 0;i<4;i++){
contraste_melhorado = contraste_melhorado + EEPROM.read(i); 
}
contraste_melhorado = contraste_melhorado, DEC;
Serial.println(contraste_melhorado);

}

void loop() {
//------------------------------------------------------------
  
  
  
  botao_troca();

  if(modo == 1){
    
    leitura_linear_melhorada(0);    
    
  }  
delay(2000);
int calibrar = 0;
if(calibrar == 1){
calibrador();
}

//------------------------------------------------------------
}

void calibrador(){
  
int C[] = {0,0,0,0};
  
  Serial.println("coloque os leitores do robo no preto");
  delay(5000);
 int leitura_de_linha_esquerda_preto = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_preto = analogRead(leitor_de_linha_direita);
  
  Serial.println("coloque os leitores do robo no branco");
  delay(5000);
 int leitura_de_linha_esquerda_branco = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_branco = analogRead(leitor_de_linha_direita);
 
 float pre_contraste_melhorado = (((leitura_de_linha_esquerda_preto + leitura_de_linha_direita_preto)/2)-((leitura_de_linha_esquerda_branco + leitura_de_linha_direita_branco)/2))/1.5;
 contraste_melhorado = round(pre_contraste_melhorado);
 Serial.println(contraste_melhorado);
 C[0] = contraste_melhorado;
 if(C[0]>255){
  
   C[1]=255;
   C[0]=C[0]-255;
   
     if(C[0]>255){
    
      C[2]=255;
      C[0]=C[0]-255; 
     
        if(C[0]>255){
    
            C[3]=255;
            C[0]=C[0]-255; 
     
   } 
   }   
 }
 for(int i = 0;i<4;i++){
 EEPROM.write(i, C[i]);
  
}
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
  
  
void leitura_linear_melhorada(int tempo) {

  
  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);

/*
  Serial.print("direita");
  Serial.println(leitura_de_linha_direita);
  Serial.print("esquerda");
  Serial.println(leitura_de_linha_esquerda);
 */

//direita > esquerda
  if (leitura_de_linha_direita-leitura_de_linha_esquerda >= contraste_melhorado) {

    ir_direita(tempo);    

//esquerda > direita
  } else if (leitura_de_linha_esquerda-leitura_de_linha_direita >= contraste_melhorado) {

      ir_esquerda(tempo);
      
    } else {

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
