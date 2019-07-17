
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

//botão de acionamento (inicial)

int botao1 = 3;
int leitura_botao1 = 0;

//variaveis de estado do botao;

int X = 0;

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

contraste_melhorado = EEPROM_read(0);
Serial.println(contraste_melhorado);

/*forçar calibragem 
calibrar=1;
*/
/*forçar mudança de modo
modo=1;
*/

}

void loop() {
//------------------------------------------------------------
  
  botao_troca();
  calibrador();

  if(modo == 1){
    
    leitura_linear_melhorada(0);    
    
  }  

//------------------------------------------------------------
}

void calibrador(){
  
  botao_calibrador();
  
  if(calibrar == 1){
  
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

EEPROM_write(contraste_melhorado, 0);

delay(500);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);

calibrar = 0;
}
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

  
  
void leitura_linear_melhorada(int tempo) {

  
  leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
  leitura_de_linha_direita = analogRead(leitor_de_linha_direita);


  Serial.print("direita  ");
  Serial.print(leitura_de_linha_direita);
  Serial.print("  esquerda  ");
  Serial.println(leitura_de_linha_esquerda);
 

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

void EEPROM_write(int Valor, int i){
//int(16bits) = -32,768 to 32767
  
    if (i*2+1 >= EEPROM.length() || i < 0) {
    Serial.println("Esta posicao não existe");
    }else{
  
  byte hiByte = highByte(Valor);
  byte loByte = lowByte(Valor);

  EEPROM.write(i*2, hiByte);
  EEPROM.write((i*2)+1, loByte);
  
  Serial.println("operacao de escrita realizada na EEPROM");
  
    }    
}

int EEPROM_read(int i){
//int(16bits) = -32,768 to 32767
  
    if (i*2+1 >= EEPROM.length() || i < 0) {
    Serial.println("Esta posicao nao existe");
    }else{
  
  byte hiByte = EEPROM.read(i*2);
  byte loByte = EEPROM.read((i*2)+1);;

  int Valor_byte  = word(hiByte, loByte);
 
  Serial.println("operacao de leitura realizada na EEPROM");
  
  return Valor_byte;
  
    }    
}

void EEPROM_tamanho(){
//int(16bits) = -32,768 to 32767
  
  Serial.print(EEPROM.length()/2);
  Serial.print(" posicoes na EEPROM(16bits)");
  Serial.print("\ncomecando em 0 e terminando em ");
  Serial.println((EEPROM.length()/2)-1);
  
}
