int esquerda_frente_super;
int direita_atras_super;
int esquerda_atras_super;
int direita_frente_super;
/*                         
█████████████████████████████████████
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
█▒▒████▒▒█████▒▒████▒▒▒████▒▒▒████▒▒█
█▒▒█▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█▒▒▒█▒▒█▒▒▒▒▒█
█▒▒█▒▒▒▒▒█▒▒▒█▒▒████▒▒▒████▒▒▒████▒▒█
█▒▒█▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█▒▒▒█▒▒█▒▒▒▒▒█
█▒▒████▒▒█████▒▒████▒▒▒█▒▒▒█▒▒████▒▒█
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█ 
█████████████████████████████████████   
*/
 
#include <Servo.h>
#include <EEPROM.h>

Servo direita;
Servo esquerda;

// ultra

const int TrigPin_direita = 0;
const int EchoPin_direita = 0;

const int TrigPin_esquerda = 0;
const int EchoPin_esquerda = 0;

int distancia_direita = 0;
int distancia_esquerda = 0;

// parte do sistema de diagnostico

const int redPin = 26;
const int greenPin = 28;
const int bluePin = 30;

//troca por botao

int mode = 0;

//seguidor de linha

const int pin_Qti_direita = A1;
const int pin_Qti_esquerda = A0;

int Qti_esquerda;
int Qti_direita;

//botão de acionamento (inicial)

int button[2] = {2, 3};

int activate;
int button_reading;

//number of active modes 
int total_modes = 1;
unsigned long Time[3] = {0,0,0};

//EEPROM velocity variables

 int direita_frente = 0;
 int esquerda_frente = 0;
 int direita_atras = 0;
 int esquerda_atras = 0;



void setup() {
   
  direita.attach(5);  /*Motor Direita */
  esquerda.attach(6); /*Motor Esquerda */
  
  esquerda.write(90);
  direita.write(90);

  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);

pinMode(TrigPin_direita, OUTPUT);
pinMode(EchoPin_direita, INPUT);

pinMode(TrigPin_esquerda, OUTPUT);
pinMode(EchoPin_esquerda, INPUT);
  
  
  ler_direcoes();
robot_speed(100, 100);

  RGB_color("aqua");

}
void loop() {
//-------------------------------------------------------------------------------------------------
 
  mode_changer(0);
  
  if(mode == 0){ 
    
    calibrator_button(1);
    
  }else if(mode == 1){

         line_align();

  }else if(mode == 2){

         //labirinto
         
  }else if(mode == 3){

         //sumo
         
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


void  parado() {

  direita.write(90);
  esquerda.write(90);

}
void  ir_esquerda() {

  direita.write(direita_frente);
  esquerda.write(esquerda_atras);

}
void  ir_direita() {

  direita.write(direita_atras);
  esquerda.write(esquerda_frente);

}
void ir_atras() {

  direita.write(direita_atras);
  esquerda.write(esquerda_atras);

}
void ir_frente() {

  direita.write(direita_frente);
  esquerda.write(esquerda_frente);

}

void  super_ir_direita(int tempo){
  
esquerda_frente_super = 0;
direita_atras_super = 0;

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
  
}
void  super_ir_esquerda(){
  
direita_frente_super = 0;
esquerda_atras_super = 0;

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
  
}
//----------------------------------------- direcoes especiais unicas não testadas inicio ------------------------------------------------

void  ir_esquerda_unico() {

  direita.write(direita_frente);
  esquerda.write(90);

}
void  ir_direita_unico() {

  direita.write(90);
  esquerda.write(esquerda_frente);

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

void line_align(){

  Qti_esquerda = analogRead(pin_Qti_esquerda);
  Qti_direita = analogRead(pin_Qti_direita);

  Serial.println("esquerda");
  Serial.println(Qti_esquerda);
  Serial.println("direita");
  Serial.println(Qti_direita);

  if(Qti_esquerda > 500 && Qti_direita <= 500){
    
ir_esquerda();
RGB_color("green");
  
}else if(Qti_direita > 500 && Qti_esquerda <= 500){

ir_direita();
RGB_color("blue");
  
}else{

ir_frente();
RGB_color("yellow");
  
}
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
  parado(); 
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
		 
		activate = 0;
		 
	button_reading = digitalRead(button[i]);

	if (button_reading == 0) {
        
		activate = 1;    

	do{
	  
	  button_reading = digitalRead(button[i]);
	  
	}while(button_reading == 0);

	}

		return activate;
	  
	}

void ultrasonico_direita(){

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

    /*
  Serial.print("distancia direita: ");
  Serial.print(distancia_direita);
  Serial.println("cm");
  */

}

void ultrasonico_esquerda(){

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
  
        /*
  Serial.print("distancia esquerda: ");
  Serial.print(distancia_esquerda);
  Serial.println("cm");
  */

}
