/*Código 3 Trocas
                                  ^          ^          
                                 aaa        aaa           Z   
                                aaaaaaaaaaaaaaaa        Z       
                               aaaaaaaaaaaaaaaaaa     Z         
                              aaaa ~ aaaaa ~ aaaaa  <            
                              aaaaaaaaaaaaaaaaaaaa    
                               aaaaaaaa__aaaaaaaa        
                                aaaaaaaaaaaaaaaa
                                *|*|*|*|*|*|*|*|
                      a         aaaaaaaaaaaaaaaa
                     aaa       aaaaaaaaaaaaaaaaaa
                     aaa      aaaaaaaaaaaaaaaaaaaa
                     aaa     aaaaaaaaaaaaaaaaaaaaaa
                     aaa    aaaaaaaaaaaaaaaaaaaaaaaa
                     aaa    aaaaaaaaaaaaaaaaaaaaaaaa
                     aaa    aaaaaaaaaaaaaaaaaaaaaaaa
                      aaa    aaaaaaaaaaaaaaaaaaaaaa
                       aaa    aaaaaaaaaaaaaaaaaaaa
                        aaaaaaaaaaaaaaaaaaaaaaaaaa
                         aaaaaaaaaaaaaaaaaaaaaaaaa 

                         DICAS: # + (1 = leitura linear || 2 = labirinto || 3 = sumô || 4 = direções || 5 = batidão)




 */                        

//  BATIDÃO DEFINE

int toneM = 0;
int beat = 0;
long duration  = 0;
int thisNote = 0; 
int noteDuration = 0;
int pauseBetweenNotes = 0;
long delayValue = 0;                                    
long numCycles = 0;                                           
long i = 0;
 
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


#define melodyPin 9
//Mario main theme melody
int melody[] = {
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
//Mario main them tempo
int song = 0;
int size = 0;

int tempo1[] = {
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
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
//-------//---------------//---------

//  SERVOS

  #include <Servo.h>

  Servo direita;
  Servo esquerda;

//------//---------------//----------

//  LEDs
  
  int led1 = 4;
  int led2 = 6;
  int led3 = 8;

  int led = 13;
  
//------//--------------//-----------

//  ULTRA-SÔNICO

  int leitor_echo_frente = A5;
  int trigger_frente = 7;
  long leitura_echo_frente = 0;
  long distancia_ultrasonica_frente = 0;


//------//--------------//-----------

//  SEGUIDOR DE LINHA

  int leitura_de_linha_direita = 0;
  int leitura_de_linha_esquerda = 0;

  int leitor_de_linha_direita = A2;
  int leitor_de_linha_esquerda = A3;

 
//------//--------------//-----------

//  BOTÕES  + MODO

  int modo = 0;
  int botao = 3; //Botão para iniciar
  int leitura_botao = 0;

  int X = 0;
  int Y = 0;
  int Z = 0;
  int K = 0;
  int G = 0;
  
//------//--------------//-----------

//  CONTRASTE

  int contraste = 750;

//------//--------------//-----------

//  DEFINIÇÕES

/* VARIAVEIS A DEFINIR */

  int direcao = 0;
  int valor_minimo_leitura_linha_sumo = 650; /*  +CONFIGURAR-, Valor da leitura da linha branca para o robo parar e ficar na preta*/
  int distancia_minima_inimigo_ultra = 45; /*  +CONFIGURAR-, Distancia do Robo inimigo minima para ele avançar pelo ultra, inimigo pelo ultra em cm*/
  int distancia_minima_inimigo_infra = 0; /*Setar como 1 caso Digital, Distancia do Robo inimigo minima para ele avançar pelo infra*/
  int tempo_ir_atras_sumo_linha = 1000; /* +CONFIGURAR-,  Tempo que o robo deve ir para tras quando ler a linha branca*/
  int tempo_ir_atras_sumo_inimigo = 0; /* Tempo para ele ir para tras caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int tempo_ir_frente_sumo = 0; /* Tempo para ele ir para frente caso detecte o inimigo, por padrão para não interferir nas leituras 0 */
  int tempo_ir_direta_sumo = 0; /* Tempo para ele ir para direita caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int tempo_ir_esquerda_sumo = 0; /* Tempo para ele ir para esquerda caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int Contagem_Para_Entrar_Sumo = 0; /* Contagem para o delay antes de entrar na linha sumo, definido como 0 e depois tranformado em 1 na primeira rodada para o delay não se repetir */
  int ja_fui_para_atras; /* Variavel para ele saber se já foi para trás atrás do inimigo */
  int ja_fui_para_atras_tempo_frente = 0; /*CONFIGURAR- , Tempo para ele ir para frente logo após ter ido para trás atrás do inimigo e ele não estiver mais lá  */

  int delay_da_primeira_vez_que_o_sumo_rodar;
  int tempo_do_delay_da_primeira_vez_que_o_sumo_rodar  = 10000; /*CONFIGURAR*/

//**********//************//*************//***********//**********

void setup() {
  

  Serial.begin(9600);
  
  
//  BATIDÃO SETUP

 

//  SERVOS SETUP

  direita.attach(10); 
  esquerda.attach(11); 

//  LEDs SETUP

  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);

  pinMode(led, OUTPUT);

// BOTÃO SETUP

  pinMode(botao, INPUT);

//  ULTRA-SÔNICO

    
  pinMode(trigger_frente, OUTPUT);

  pinMode(leitor_echo_frente, INPUT);

// LEITOR DE LINHA SETUP

  pinMode(leitor_de_linha_direita, INPUT);
  pinMode(leitor_de_linha_esquerda, INPUT);

  
} // FIM DO SETUP


//**********//************//*************//***********//**********

void loop() {

  delay(100);

  if(modo == 0 || K == 0){
    
    esquerda.write(90);
    direita.write(90);
    sing(1);
    sing(2);
  }else{

      digitalWrite(melodyPin, LOW);
  }

   botao_troca();

  if(modo != 0){  //PARA EVITAR O TESTE DE TODAS AS CONDIÇÕES

    if (modo == 1) {
      
      leitura_linear(0);
  
      }else if (modo == 2) {

        labirinto();
      

        }else if (modo == 3) {

          sumo();
        }
  }

     
} // FIM DO LOOP

//**********//************//*************//***********//**********


// BOTÃO TROCADOR
  void botao_troca(){
// #0
    leitura_botao = digitalRead(botao);
  
    if(K == 1 && G == 0){

    G = 1;
    leitura_botao = 1;
  
    }
  
    if (leitura_botao == 1 && X == 0) {

    digitalWrite(led1, HIGH);     //ACENDE A PRIMEIRA LED "VERMELHA"
    modo = 1;                     //ENTRA NO MODO 1 "SEGUIDOR DE LINHA"
    X = 1;

      do{                        
  
        delay(50);
  
        leitura_botao = digitalRead(botao);
  
      }while(leitura_botao == 1);

    }else{

      if(leitura_botao == 1 && Y == 0 && X == 1){

        digitalWrite(led2, HIGH);  //ACENDE O SEGUNDO LED "AMARELO"
        modo = 2;                  //ENTRA NO MODO 2 "LABIRINTO" "NÃO FUNCIONAL"
        Y = 1;

          do{
  
            delay(50);
  
            leitura_botao = digitalRead(botao);
  
          }while(leitura_botao == 1);

      }else{
      
        if(leitura_botao == 1 && Y == 1 &&  Z == 0 && X == 1){

          digitalWrite(led3, HIGH);  //ACENDO O TERCEIRO LED "VERDE"
          modo = 3;                  //ENTRA NO MODO SUMÔ "EXPERIMENTAL"
          Z = 1;

          do{
  
            delay(50);
  
            leitura_botao = digitalRead(botao);
  
          }while(leitura_botao == 1);
        }else{

          if(leitura_botao == 1 && Y == 1 && Z == 1 && X == 1){
            
            asm volatile ("jmp 0"); //RESETA A PLACA PARA O PONTO 0 DA MEMÓRIA
          }
        }
      }
    }
  } //FIM DO BOTÃO TROCADOR

  

  
//**********//************//*************//***********//**********


//  SEGUIDOR DE LINHA
  void leitura_linear(int tempo) {
//  #1
    leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);
    leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
  /*
    Serial.println("esquerda");
    Serial.println(leitura_de_linha_esquerda);
    Serial.println("direita");
    Serial.println(leitura_de_linha_direita);
    */

    if (leitura_de_linha_direita >= contraste && leitura_de_linha_esquerda < contraste) {

      ir_direita(tempo);
    

    }else{
      if (leitura_de_linha_esquerda >= contraste && leitura_de_linha_direita < contraste ) {

        ir_esquerda(tempo);
      
      
      }else{
  
        ir_frente(tempo);
   
      }
    }
  }


//**********//************//*************//***********//**********


// LABIRINTO

  void labirinto(){
// #2
    esquerda.write(90);
    direita.write(90);
   
  }


//**********//************//*************//***********//**********


// SUMÔ

  void sumo() {
// #3
    leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda); /* Leitura de Linha para Ver se está Na Arena*/
    leitura_de_linha_direita = analogRead(leitor_de_linha_direita);

    /*
    Caso queira testar os valores:
    Serial.print("Direita  ");
    Serial.println(leitura_de_linha_direita);
    Serial.print("Esquerda ");
    Serial.println(leitura_de_linha_esquerda);
    */


    /* REAÇÕES CASO ESTEJA NA LINHA BRANCA */

    if (leitura_de_linha_direita < valor_minimo_leitura_linha_sumo) {
      
      ir_atras(tempo_ir_atras_sumo_linha);
    // tenque ser diferente de 0          /* Ir para trás caso Esteja na linha branca */
    
    } else {
      
      if (leitura_de_linha_esquerda < valor_minimo_leitura_linha_sumo) {
      ir_atras(tempo_ir_atras_sumo_linha);
      // tenque ser diferente de 0
      }
    }

    ultrasonico_frente();
    
    if (distancia_ultrasonica_frente < distancia_minima_inimigo_ultra) {
      ir_frente(tempo_ir_frente_sumo);
      // tempo_ir_frente_sumo tenque ser = 0
    } else {
      
      ir_direita(0);                   
    }   
  } //FIM DO SUMÔ


//**********//************//*************//***********//**********



// DIREÇÕES

  void  ir_esquerda(int tempo) {
// #4
    direita.write(180);
    esquerda.write(180);
    delay(tempo);

  }
  
  void  parado(int tempo) {

  direita.write(90);
  esquerda.write(90);
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



//**********//************//*************//***********//**********


//  ULTRASONICO_FRENTE
void ultrasonico_frente() {
//#6

  delayMicroseconds(2);
  digitalWrite(trigger_frente, HIGH);
  delayMicroseconds(13);
  digitalWrite(trigger_frente, LOW);
    delayMicroseconds(2);
  

  leitura_echo_frente = pulseIn(leitor_echo_frente, HIGH);

  distancia_ultrasonica_frente = leitura_echo_frente / 29 / 2;



 /* Serial.print(distancia_ultrasonica_frente);
  Serial.println("cm");
  Serial.println();*/



}

//**********//************//*************//***********//**********



// BATIDÃO

  void sing(int s) {
//#5 
    song = s;
    if (song == 2) {
      //  Underworld Theme
      
      size = sizeof(underworld_melody) / sizeof(int);           //DEFINIR ANTES
      for (thisNote = 0; thisNote < size; thisNote++) {
      leitura_botao = digitalRead(botao);
      
      if(leitura_botao == 1 || K == 1){
        K = 1;
       size = thisNote;
        
      }else{
     
        noteDuration = 1000 / underworld_tempo[thisNote];           //DEFINIR ANTES
 
        buzz(melodyPin, underworld_melody[thisNote], noteDuration);
        
        pauseBetweenNotes = noteDuration * 1.30;                        //DEFINIR ANTES
        delay(pauseBetweenNotes);   
 
        buzz(melodyPin, 0, noteDuration);
      }
      }
    
    } else {
 
    // Mario Theme
    
      size = sizeof(melody) / sizeof(int);                              //DEFINIR ANTES
    
      for (thisNote = 0; thisNote < size; thisNote++) {                       //DEFINIR ANTES
      
        leitura_botao = digitalRead(botao);
        if(leitura_botao == 1 || K == 1){
        K = 1;
        size = thisNote;
        
        }else{

        noteDuration = 1000 / tempo1[thisNote];                              //DEFINIR ANTES
 
        buzz(melodyPin, melody[thisNote], noteDuration); 
        
        pauseBetweenNotes = noteDuration * 1.30;                                //DEFINIR ANTES
        delay(pauseBetweenNotes);
 
      
        buzz(melodyPin, 0, noteDuration);
      
      }
    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
   delayValue = 1000000 / frequency / 2;                                       //DEFINIR ANTES
   numCycles = frequency * length / 1000;                                              //DEFINIR ANTES
   for (i = 0; i < numCycles; i++) {                                                        //DEFINIR ANTES
     digitalWrite(targetPin, HIGH); 
     delayMicroseconds(delayValue); 
     digitalWrite(targetPin, LOW); 
     delayMicroseconds(delayValue); 
   }

   digitalWrite(13, LOW);
 
}
/*
███████████████████████████████████   
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█     █████ 
█▒▒████▒▒▒█████▒▒▒█████▒▒▒██▒▒▒▒▒▒█     █     █    
█▒▒█▒▒█▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒█▒▒▒▒▒█     ██████      
█▒▒█████▒▒███▒▒▒▒▒▒▒█▒▒▒▒████▒▒▒▒▒█     █       █       
█▒▒█▒▒▒█▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒█▒▒█▒▒▒▒▒█     █       █    
█▒▒█████▒▒█████▒▒▒▒▒█▒▒▒▒█▒▒█▒▒▒▒▒█     ██████          
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█     █       
███████████████████████████████████

█████████████████████████████████████████
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█       ███████
█▒▒█████▒▒██▒▒▒██▒▒█████▒▒█████▒▒▒███▒▒▒█      █           █
█▒▒█▒▒▒█▒▒█▒█▒█▒█▒▒█▒▒▒▒▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█     █             █
█▒▒█▒▒▒█▒▒█▒▒█▒▒█▒▒███▒▒▒▒█▒▒██▒▒█████▒▒█    █               █
█▒▒█▒▒▒█▒▒█▒▒▒▒▒█▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█     █             █
█▒▒█████▒▒█▒▒▒▒▒█▒▒█████▒▒█████▒▒█▒▒▒█▒▒█      █           █
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█    ███         ███
█████████████████████████████████████████   

███████████████████████████████████████
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█          █████       ██
█▒▒▒███▒▒▒█▒▒▒▒▒▒█████▒▒█▒▒▒█▒▒▒███▒▒▒█         █        █   █
█▒▒█▒▒▒█▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█▒▒▒█▒▒█        █           █ 
█▒▒█████▒▒█▒▒▒▒▒▒█████▒▒█████▒▒█████▒▒█        █           █
█▒▒█▒▒▒█▒▒█▒▒▒▒▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█         █        █   █
█▒▒█▒▒▒█▒▒█████▒▒█▒▒▒▒▒▒█▒▒▒█▒▒█▒▒▒█▒▒█          █████       ██
█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█           
███████████████████████████████████████
*/
