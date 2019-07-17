
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


Versão simples EEPROM seguidor_linear_melhorado (sem música) semi-FUNCIONAL 


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

//botão de acionamento (inicial)

int botao1 = 3;
int leitura_botao1 = 0;

//variaveis de estado do botao;

int X = 0;

// EEPROM

int contraste_melhorado = 0;

int botao2 = 2;
int leitura_botao2 = 0;
int calibrar = 0;

void setup() {
  
  
  direita.attach(10); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */

  Serial.begin(9600);

  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
 
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
  
botao_calibrador();
if(calibrar == 1){
calibrador();
calibrar = 0;
}

//------------------------------------------------------------
}

void calibrador(){
  
int C[] = {0,0,0,0};
  
  Serial.println("coloque os leitores do robo no preto");
  delay(10000);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
 int leitura_de_linha_esquerda_preto = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_preto = analogRead(leitor_de_linha_direita);
  digitalWrite(led3, HIGH);
  
  Serial.println("coloque os leitores do robo no branco");
  delay(10000);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
 int leitura_de_linha_esquerda_branco = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_branco = analogRead(leitor_de_linha_direita);
  digitalWrite(led3, HIGH);
 
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

delay(500);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}

void botao_troca(){
 
leitura_botao1 = digitalRead(botao1);

if (leitura_botao1 == 0 && X==0) {
 
digitalWrite(led1, HIGH);

modo = 1;    
X = 1;

do{
  
  delay(50);
  
  leitura_botao1 = digitalRead(botao1);
  
}while(leitura_botao1 == 0);

}  
}

void botao_calibrador(){
 
leitura_botao2 = digitalRead(botao2);

if (leitura_botao2 == 0) {
 
digitalWrite(led2, HIGH);

calibrar = 1;    

do{
  
  delay(50);
  
  leitura_botao2 = digitalRead(botao2);
  
}while(leitura_botao2 == 0);

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
