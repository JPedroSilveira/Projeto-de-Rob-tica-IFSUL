
/*                         
█████████████████████████████████████
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
█▒▒████▒▒▒▒███▒▒▒███▒▒████▒▒▒█▒▒▒█▒▒█
█▒▒█▒▒▒█▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█
█▒▒████▒▒▒█████▒▒▒█▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█
█▒▒█▒▒▒█▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█
█▒▒████▒▒▒█▒▒▒█▒▒███▒▒████▒▒▒█████▒▒█
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█ 
█████████████████████████████████████   


Versão avançada EEPROM seguidor_linear_(digital usando porta analog) calibrador_direcional (com música) semi-FUNCIONAL
*/
 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
  int atual = 0;
  unsigned long melody_Time[3] = {0, 0, 0};
  boolean melody_Reset[3] = {true, true, true};
  boolean melody_timeSet[3] = {true, true, true};
  int melody_before = 0;
 
 int melody1[78] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int tempo1[78] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int melody2[99] = {
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                 
  
  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
  NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
  NOTE_C4, NOTE_D4,0,                                       
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
  NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58
  
  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
  NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,
  
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4, 0,
  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
  NOTE_C4, NOTE_D4
};

int tempo2[99] = {
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,
  
  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,
  
  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,
  
  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4,
  
  4,8,4,4,4,
  4,16,4,
  4,8,4,4,4,
  4,20,
};
 
 
#include <Servo.h>
#include <EEPROM.h>

Servo direita;
Servo esquerda;

// ultra

int TrigPin_frente = 5;
int EchoPin_frente = 4;

int TrigPin_atras = 0;
int EchoPin_atras  = 0;

int TrigPin_direita = 0;
int EchoPin_direita = 0;

int TrigPin_esquerda = 0;
int EchoPin_esquerda = 0;

int distancia_atras = 0;
int distancia_frente = 0;
int distancia_direita = 0;
int distancia_esquerda = 0;

int conter = 0;
unsigned long tempo_ultra = 0;

// musica

int buzzer = 10;

// parte do sistema de diagnostico

int led[3] = {4, 6, 8};

int redPin = 26;
int greenPin = 28;
int bluePin = 30;

//troca por botao

int mode = 0;

//seguidor de linha


int IR_read[8] = {0,0,0,0,0,0,0,0};
int IR[8] = {53,52,51,50,49,48,47,46};

//  pos 0 = extrema direita |  pos 2 direita alinhamento(meio)        |        |         pos 5 esquerda alinhamento(meio)   |  pos 7 = extrema esquerda

// robo demonstrou grande precisão em baixa velocidade!!! foi usado: robot_speed(100, 100); plus baixo consumo de energia!!!(teórico)

//botão de acionamento (inicial)

int button[2] = {2, 3};

int contraste_melhorado = 0;

//number of active modes 
int total_modes = 1;
unsigned long Time[3] = {0,0,0};

//EEPROM velocity variables

 int direita_frente = 0;
 int esquerda_frente = 0;
 int direita_atras = 0;
 int esquerda_atras = 0;

void setup() {
randomSeed(analogRead(0));

   
  direita.attach(9); /*Motor Direita */
  esquerda.attach(8);  /*Motor Esquerda */
  
  esquerda.write(90);
  direita.write(90);

  Serial.begin(9600);

  pinMode(led[2], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[0], OUTPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
 
//caso seja necessario o uso de digital

for(int cont = 0; cont<8 ; cont++){
 pinMode(IR[cont], INPUT);
}

pinMode(TrigPin_frente, OUTPUT);
pinMode(EchoPin_frente, INPUT);

pinMode(TrigPin_atras, OUTPUT);
pinMode(EchoPin_atras, INPUT);

pinMode(TrigPin_direita, OUTPUT);
pinMode(EchoPin_direita, INPUT);

pinMode(TrigPin_esquerda, OUTPUT);
pinMode(EchoPin_esquerda, INPUT);
  
 pinMode(buzzer, OUTPUT);
  
  ler_direcoes();
robot_speed(100, 100);

  RGB_color("aqua");

/*forçar mudança de modo*
mode=1;
*/
}
//play(melody2 ,tempo2, sizeof(melody2)/sizeof(int), 0, 1);
void loop() {
//-------------------------------------------------------------------------------------------------

  mode_changer(0);
  calibrator_button(1);
  
  if(mode == 0){ 
    
  play(melody1 ,tempo1, sizeof(melody1)/sizeof(int), 1, 0);
  
  }else if(mode == 1){

  calibrator_button(1);
    
  leitura_linear(0);    
  play(melody2 ,tempo2, sizeof(melody2)/sizeof(int), 0, 0);
    
  }     

//-------------------------------------------------------------------------------------------------
}

void ler_direcoes(){
  
 direita_frente = EEPROM_read(1);
 esquerda_frente = EEPROM_read(2);
 
 if(direita_frente == 180){
   
  direita_atras = 0;
   
 }else{
   
   direita_atras = 180;
   
 }
 
  if(esquerda_frente == 180){
   
  esquerda_atras = 0;
   
 }else{
   
   esquerda_atras = 180;
   
 }
 
 Serial.println("------------------------------------------------------------------------------------------------------");
 Serial.println("frente direita esquerda");
 Serial.println(direita_frente);
 Serial.println(esquerda_frente);
 Serial.println("------------------------------------------------------------------------------------------------------");
 Serial.println("atras direita esquerda");
 Serial.println(direita_atras);
 Serial.println(esquerda_atras);
 Serial.println("------------------------------------------------------------------------------------------------------");
  
}

void robot_speed(int speed_esquerda, int speed_direita){
  
  int speed_direita_high = speed_direita;
  int speed_direita_low = (speed_direita - 180)*-1;
  
  int speed_esquerda_high = speed_esquerda;
  int speed_esquerda_low = (speed_esquerda - 180)*-1;
  
  
  if(direita_frente > 90){
   
   direita_frente = speed_direita_high;
   direita_atras = speed_direita_low;  
    
  }else if(direita_frente < 90){
    
   direita_frente = speed_direita_low;
   direita_atras = speed_direita_high;
    
  }
  
    if(esquerda_frente > 90){
   
   esquerda_frente = speed_esquerda_high;
   esquerda_atras = speed_esquerda_low;  
    
  }else if(esquerda_frente < 90){
    
   esquerda_frente = speed_esquerda_low;
   esquerda_atras = speed_esquerda_high;
    
  }
  
  Serial.print("velocidade mudada com sucesso, velocidade esquerda agora e: ");
  Serial.print(speed_esquerda);
  Serial.print(" e direita e: ");
  Serial.println(speed_direita);
  Serial.println("------------------------------------------------------------------------------------------------------");
  
}


void  parado(int tempo) {


  direita.write(90);
  esquerda.write(90);
  delay(tempo);


}
void  ir_esquerda(int tempo) {

  direita.write(direita_frente);
  esquerda.write(esquerda_atras);
  delay(tempo);


}
void  ir_direita(int tempo) {


  direita.write(direita_atras);
  esquerda.write(esquerda_frente);
  delay(tempo);

}
void ir_atras(int tempo) {

  direita.write(direita_atras);
  esquerda.write(esquerda_atras);

  delay(tempo);

}
void ir_frente(int tempo) {


  direita.write(direita_frente);
  esquerda.write(esquerda_frente);

  delay(tempo);

}
void Pro_90 (String direcao, int tempo){
// direcao pode ser direita ou esquerda

//noTone(buzzer);
RGB_color("white");
boolean ativar = false;

do{
read_all_IR();
//print_all_IR();
  
if(direcao.equalsIgnoreCase("direita")){
  ir_direita(tempo);
}else{
  ir_esquerda(tempo);
}

if(IR_read[0] == 0 && IR_read[1] == 0 && IR_read[2] == 0 && IR_read[3] == 1 || IR_read[4] == 1 && IR_read[5] == 0 && IR_read[6] == 0 && IR_read[7] == 0 ){
  ativar = true;
}
play(melody2 ,tempo2, sizeof(melody2)/sizeof(int), 0, 0);
}while(ativar == false);
 
}



void  super_ir_direita(int tempo){
  
int esquerda_frente_super = 0;
int direita_atras_super = 0;

if(esquerda_frente < 90){
esquerda_frente_super = 0;
}else{
esquerda_frente_super = 180;  
}
if(direita_atras < 90){
direita_atras_super = 0;
}else{
direita_atras_super = 180;  
}

  direita.write(direita_atras_super);
  esquerda.write(esquerda_frente_super);
  delay(tempo);
  
}
void  super_ir_esquerda(int tempo){
  
int direita_frente_super = 0;
int esquerda_atras_super = 0;

if(direita_frente < 90){
direita_frente_super = 0;
}else{
direita_frente_super = 180;  
}
if(esquerda_atras < 90){
esquerda_atras_super = 0;
}else{
esquerda_atras_super = 180;  
}

  direita.write(direita_frente_super);
  esquerda.write(esquerda_atras_super);
  delay(tempo);
  
}
//----------------------------------------- direcoes especiais unicas não testadas inicio ------------------------------------------------

void  ir_esquerda_unico(int tempo) {

  direita.write(direita_frente);
  esquerda.write(90);
  delay(tempo);


}
void  ir_direita_unico(int tempo) {


  direita.write(90);
  esquerda.write(esquerda_frente);
  delay(tempo);

}

//----------------------------------------- direcoes especiais unicas não testadas fim ------------------------------------------------

void EEPROM_write(int Valor, int i){
//int(16bits) = -32768 to 32767
  
    if (i*2+1 >= EEPROM.length() || i < 0) {
    Serial.println("Esta posicao não existe");
    }else{
  
  byte hiByte = highByte(Valor);
  byte loByte = lowByte(Valor);

  EEPROM.update(i*2, hiByte);
  EEPROM.update((i*2)+1, loByte);
  
  Serial.println("operacao de escrita realizada na EEPROM");
  
    }    
}

int EEPROM_read(int i){
//int(16bits) = -32768 to 32767
  
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
//int(16bits) = -32768 to 32767
  
  Serial.print(EEPROM.length()/2);
  Serial.print(" posicoes na EEPROM(16bits)");
  Serial.print("\ncomecando em 0 e terminando em ");
  Serial.println((EEPROM.length()/2)-1);
  
}



void play (int *melody, int *tempo, int tamanho, int Magic_number, float tempo_Extra){

int tempo_Real = 1000/tempo[atual];

if(melody_before != 0 && melody_before != Magic_number){
  
  atual = 0;
  noTone(buzzer);
  melody_Reset[Magic_number] == true;
  melody_timeSet[Magic_number] == true;
  melody_before = Magic_number;
  
}



if(melody_Reset[Magic_number] == true){
  melody_Time[Magic_number] = millis();
  melody_Reset[Magic_number] = false;
}
  
  if(melody[atual]!=0){
  if(millis()-melody_Time[Magic_number] >= tempo_Real){
noTone(buzzer);
    if(tempo_Extra != 0){
if(melody_timeSet[Magic_number]==true){
tempo_Real=(tempo_Real*2)+(tempo_Real*tempo_Extra);
melody_timeSet[Magic_number]==false;
}


      if(millis()- melody_Time[Magic_number] >= tempo_Real){
  atual++;
  melody_Time[Magic_number]=millis();
  melody_timeSet[Magic_number]==true;
  }
    }else{

  atual++;
  melody_Time[Magic_number]=millis();
      
    }
  }else{
  tone(buzzer, melody[atual]);
  }
  }else if(melody[atual]==0){
    
   if(millis()-melody_Time[Magic_number] >= tempo_Real){
    atual++;
    melody_Time[Magic_number]=millis();
  }
  
  }
  if(atual >= tamanho){ 
  atual=0;
  melody_Reset[Magic_number] = true;
  }
}


void set_RGB(int red, int green, int blue){

	//Red, Green, Blue: set the PWM level 0 to 255

    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  
}

void RGB_color(String color){

	//color: color write in english write black to turn it off

        if(color.equalsIgnoreCase("black")){
          set_RGB(0, 0, 0); 
        }else if(color.equalsIgnoreCase("red")){
          set_RGB(255, 0, 0);
          }else if(color.equalsIgnoreCase("green")){
            set_RGB(0, 255, 0);
            }else if(color.equalsIgnoreCase("yellow")){
              set_RGB(255, 255, 0);
              }else if(color.equalsIgnoreCase("aqua")){
                set_RGB(0, 255, 255);
                }else if(color.equalsIgnoreCase("purple")){
                  set_RGB(255, 0, 255);
                  }else if(color.equalsIgnoreCase("blue")){
                   set_RGB(0, 0, 255);
                  }else if(color.equalsIgnoreCase("white")){
                    set_RGB(255, 255, 255);
                  }else{
                    Serial.println("cor nao existe");
                    Serial.println(color);
                  }
                  	  
}


void blink_led(int i, int cycles, int delay_time){
	
	//i: led number
	//cycles: number of blink cycles
	//delay_time: time the led will stay on and off
	
	for(int l = 0; l < cycles; l++){
	digitalWrite(led[i], HIGH);
	delay(delay_time);
	digitalWrite(led[i], LOW);
	delay(delay_time);
	
	}
}


void blink_RGB(String color, int cycles, int delay_time){
	
	//i: led number
	//cycles: number of blink cycles
	//delay_time: time the led will stay on and off
	
	for(int l = 0; l < cycles; l++){
	RGB_color(color);
	delay(delay_time);
	RGB_color("black");
	delay(delay_time);
	
	}
}


void calibrador_direcoes(){
  
  blink_RGB("purple", 5, 300);
  blink_RGB("green", 2, 500);
    
  direita_frente = 0; 
  esquerda_frente = 0;
  direita_atras = 180; 
  esquerda_atras = 180;
    
  direita.write(90);
  esquerda.write(90);    
  Serial.println("verifique se o robo esta parado se nao estiver e importante que voce o deixe antes de iniciar a calibragem");  
  blink_RGB("purple", 7, 300);
  blink_RGB("green", 2, 500);
  RGB_color("purple");
  Serial.println("aperte o botao se o motor direito esta indo frente");
  esquerda.write(90);
  direita.write(180);
  Time[0] = millis();
  do{
  
  if(read_and_wait_button(1) == 1){
    
    direita_frente = 180;
    direita_atras = 0;  
   
  }
    
  }while(millis()-Time[0] <= 7000);
  blink_RGB("green", 2, 300);
  RGB_color("purple");
  Serial.println("aperte o botao se o motor esquerdo esta indo frente");
  direita.write(90);
  esquerda.write(180);
  Time[0] = millis();
  do{
  
  if(read_and_wait_button(1) == 1){
    
    esquerda_frente = 180;
    esquerda_atras = 0;  
   
  }
    
  }while(millis()-Time[0] <= 7000);
    
  EEPROM_write(direita_frente, 1);
  EEPROM_write(esquerda_frente, 2);
  

  direita.write(90);
  esquerda.write(90);
  
   blink_RGB("yellow", 2, 300);
   RGB_color("aqua");

  robot_speed(100, 100);
 
 
  }
/*
void calibrador_linear(){
  
  Serial.println("coloque os leitores do robo no preto");
  blink_RGB("blue", 9, 300);
  blink_RGB("green", 2, 500);

 int leitura_de_linha_esquerda_preto = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_preto = analogRead(leitor_de_linha_direita); 
  
  Serial.println("coloque os leitores do robo no branco");
  blink_RGB("blue", 9, 300);
  blink_RGB("green", 2, 500);


 int leitura_de_linha_esquerda_branco = analogRead(leitor_de_linha_esquerda);
 int leitura_de_linha_direita_branco = analogRead(leitor_de_linha_direita);
 
 float pre_contraste_melhorado = (((leitura_de_linha_esquerda_preto + leitura_de_linha_direita_preto)/2)-((leitura_de_linha_esquerda_branco + leitura_de_linha_direita_branco)/2))/1.5;
 contraste_melhorado = round(pre_contraste_melhorado);
 Serial.println(contraste_melhorado);

EEPROM_write(contraste_melhorado, 0);

  blink_RGB("yellow", 3, 200);
  RGB_color("aqua");
  
}*/

void print_all_IR(){
  
  for(int cont = 7; cont >= 0 ; cont--){
  Serial.print("porta");
  Serial.print(cont);
  Serial.print(": ");
  Serial.print(IR_read[cont]);
  Serial.print(" ");
  }
  Serial.println("");
  
}

void read_all_IR(){
  
  for(int cont = 0; cont < 8 ; cont++){
  IR_read[cont] = digitalRead(IR[cont]);
  }  
  
}

void align_center(int tempo){

if(IR_read[2] == 1 && IR_read[5] == 0){

ir_direita(tempo);
RGB_color("blue");
  
}else if(IR_read[5] == 1 && IR_read[2] == 0){

ir_esquerda(tempo);
RGB_color("green");
  
}else if(IR_read[5] == 1 && IR_read[2] == 1){

ir_atras(tempo);
RGB_color("purple");

}else{

ir_frente(tempo);
RGB_color("yellow");
  
}
}
//ideia mantenha o robo girando ate ir "(frente)"
//ideia aumente a velocidade de rotação e diminua o ir frente

void align_extreme(int tempo){

  RGB_color("yellow");

  int prioridade_direita = 0;
  int prioridade_esquerda = 0;

  if(IR_read[0] == 1 && IR_read[1] == 1){
    prioridade_direita = 2;
  }else if(IR_read[0] == 0 && IR_read[1] == 1){
    prioridade_direita = 1;    
  }else if(IR_read[0] == 1 && IR_read[1] == 0){
    prioridade_direita = 1;
  }

  if(IR_read[6] == 1 && IR_read[7] == 1){
    prioridade_esquerda = 2;
  }else if(IR_read[6] == 0 && IR_read[7] == 1){
    prioridade_esquerda = 1;    
  }else if(IR_read[6] == 1 && IR_read[7] == 0){
    prioridade_esquerda = 1;
  }

//Serial.println(prioridade_esquerda);
//Serial.println(prioridade_direita);

if(prioridade_esquerda > prioridade_direita){
  
ir_esquerda(tempo);

}else if(prioridade_esquerda < prioridade_direita){

ir_direita(tempo);

}else if(prioridade_esquerda == 0 && prioridade_direita == 0){

ir_frente(tempo);
  
}else if(prioridade_esquerda == prioridade_direita){

ir_atras(tempo);
  
}

  
}

//ativado = 1 ou seja linha preta (sensor na linha preta) leitura = 1
void leitura_linear(int tempo) {
  

  read_all_IR(); 
  
  //print_all_IR();


  if(millis()-tempo_ultra  >= 30){
  ultrasonico_frente(true);
  tempo_ultra = millis();
  }
  
  if(distancia_frente <= 7 && conter <5){

    conter++;
    
  }else if(distancia_frente == 450){
    conter = 0;
  }
  
  if(conter >= 5){
 
    desviador("direita", tempo, 4500, 1500);
    conter = 0;
    
  }else if(IR_read[0] == 1 && IR_read[1] == 1 && IR_read[2] == 1 && IR_read[7] == 0){
  
  RGB_color("red");  
 /*ir_frente(750);
  ir_esquerda(500);*/ 
  Pro_90("direita", tempo);
  
  }else if(IR_read[0] == 0 && IR_read[5] == 1 && IR_read[6] == 1 && IR_read[7] == 1){
  
  RGB_color("red");
 /*ir_frente(750);
   ir_esquerda(500);*/ 
  Pro_90("esquerda", tempo);
  
  }else if(IR_read[0] == 0 && IR_read[1] == 0 && IR_read[6] == 0 && IR_read[7] == 0){

  align_center(0);   

  
  }else if(IR_read[0] != 1 || IR_read[1] != 1 || IR_read[2] != 1 || IR_read[3] != 1 || IR_read[4] != 1 || IR_read[5] != 1 || IR_read[6] != 1 || IR_read[7] != 1){

  align_extreme(0);

  }else{
  
  RGB_color("red");  
  ir_frente(750);
  long rr = random(0,2);
  if(rr==0){
     Pro_90("esquerda", tempo);  
  }else{
     Pro_90("direita", tempo); 
  }
     
  }
  }
void desviador(String direcao, int tempo , int tempo2, int tempo_frente){
  //time1: "line" time time2: rotating time
  
  
  noTone(buzzer);

boolean ativar = false;
RGB_color("black");

if(direcao.equalsIgnoreCase("direita")){
  
     ir_direita(tempo2);
     ir_frente(tempo_frente+1500);
     ir_esquerda(tempo2);
     ir_frente(tempo_frente+tempo_frente);
     ir_esquerda(tempo2);
     robot_speed(95, 180); 
     
}else{
  
     ir_esquerda(tempo2);
     ir_frente(tempo_frente+1500);
     ir_direita(tempo2);
     ir_frente(tempo_frente+tempo_frente+tempo_frente-1000);
     ir_esquerda(tempo2);
     robot_speed(180, 95);   
     
}
ir_frente(0);
RGB_color("purple");
do{
  
  read_all_IR();

  //print_all_IR();
  
  if(IR_read[0] == 1 || IR_read[1] == 1 || IR_read[2] == 1 || IR_read[3] == 1 || IR_read[4] == 1 || IR_read[5] == 1 || IR_read[6] == 1 || IR_read[7] == 1){
    ativar = true;
  }
  
}while(ativar == false);
  ler_direcoes();
  robot_speed(100, 100);
  Pro_90(direcao, tempo);
  
}

void calibrator_button(int i){

	//i indicates the position of the button at the array 
  
 int result = 0;
 if(mode == 0){ 
 result = cont_button(3000, i);
 }else{
 result = cont_button(0, i);
 }
 
  if(result != 0 && mode == 0){
    
    Serial.println("iniciando calibracao");
      
switch(result){
  
  case 1:
  
  
  break;
  default:
  
  calibrador_direcoes();
  
  break;
  
  
  
}
}else if(result != 0 && mode != 0){
  mode = 0;
  RGB_color("aqua");
  parado(0); 
}
}


void mode_changer(int i){

	//i indicates the position of the button at the array 
 
 	if(read_and_wait_button(i) == 1 && mode < total_modes){
	mode++;
	RGB_color("red");
	}

}


int cont_button(int wait_time, int i){

	//i: indicates the position of the button at the array
	//wait_time: tells the time that the board will wait for the button to be pressed

		int cont = 0;

	int button_reading = digitalRead(button[i]);

	if (button_reading == 0) {
  
    noTone(buzzer);
	Time[i] = millis();

	  do{
	  
	  if(read_and_wait_button(i) == 1){
		
		cont++;
		Time[i] = millis();
	   
	  }
		
	  }while(millis()-Time[i] <= wait_time);  
	}

		return cont;
	}


int read_and_wait_button(int i){

	//i indicates the position of the button at the array 
		 
		int activate = 0;
		 
	int button_reading = digitalRead(button[i]);

	if (button_reading == 0) {
        
		noTone(buzzer);
		activate = 1;    

	do{
	  
	  button_reading = digitalRead(button[i]);
	  
	}while(button_reading == 0);

	}

		return activate;
	  
	}
void ultrasonico_frente(boolean mostrar){

  delayMicroseconds(2);
  digitalWrite(TrigPin_frente, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_frente, LOW);
  delayMicroseconds(2);
  
  long leitura_echo = pulseIn(EchoPin_frente, HIGH, 2000);
  if(leitura_echo == 0){
  distancia_frente = 450;
  }else{
  distancia_frente = leitura_echo / 58;
  }
/*
  if(distancia_frente == 0){

distancia_frente = 450;
    
  }*/

  if(mostrar == true){
  Serial.print("distancia frente: ");
  Serial.print(distancia_frente);
  Serial.println("cm");
}
}
void ultrasonico_atras(boolean mostrar){

  delayMicroseconds(2);
  digitalWrite(TrigPin_atras, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_atras, LOW);
  delayMicroseconds(2);
  
  long leitura_echo = pulseIn(EchoPin_atras, HIGH);
  if(leitura_echo == 0){
  distancia_atras = 450;
  }else{
  distancia_atras = leitura_echo / 58;
  }
  
  if(mostrar == true){
  Serial.print("distancia atras: ");
  Serial.print(distancia_atras);
  Serial.println("cm");
}
}
void ultrasonico_direita(boolean mostrar){

  delayMicroseconds(2);
  digitalWrite(TrigPin_direita, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_direita, LOW);
  delayMicroseconds(2);
  
  long leitura_echo = pulseIn(EchoPin_direita, HIGH, 100000);
  if(leitura_echo == 0){
  distancia_direita = 450;
  }else{
  distancia_direita = leitura_echo / 58;
  }
  
  if(mostrar == true){
  Serial.print("distancia direita: ");
  Serial.print(distancia_direita);
  Serial.println("cm");
}
}
void ultrasonico_esquerda(boolean mostrar){

  delayMicroseconds(2);
  digitalWrite(TrigPin_esquerda, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin_esquerda, LOW);
  delayMicroseconds(2);
  
  long leitura_echo = pulseIn(EchoPin_esquerda, HIGH, 100000);
  if(leitura_echo == 0){
  distancia_esquerda = 0;
  }else{
  distancia_esquerda = leitura_echo / 58;
  }
  
  if(mostrar == true){
  Serial.print("distancia esquerda: ");
  Serial.print(distancia_esquerda);
  Serial.println("cm");
}
}

void all_ultra(boolean mostrar){
ultrasonico_esquerda(mostrar);
ultrasonico_direita(mostrar);
ultrasonico_atras(mostrar);
ultrasonico_frente(mostrar);
}
