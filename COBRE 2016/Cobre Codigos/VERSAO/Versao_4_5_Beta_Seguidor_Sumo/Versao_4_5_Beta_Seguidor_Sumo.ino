//servo

#include <Servo.h>

Servo direita;
Servo esquerda;


int w; /*Variavel para o for da leitura do infravermelho */ 

//ultra

int leitor_echo = A5;
int leitor_echo_tras =  A1; /*Adicionado para o Sumô */
int trigger = 7; /* Trig */
int trigger_tras = 8; /*Adicionado para o Sumô */
long leitura_echo = 0; 
long leitura_echo_tras = 0; /*Adicionado para o Sumô */
long distancia_ultrasonica = 0;
long distancia_ultrasonica_tras = 0; /*Adicionado para o Sumô */


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

//Sumô

  

  int valor_min_l_linha_sumo = 0;
  int distancia_minima_inimigo_ultra = 0;
  int distancia_minima_inimigo_infra = 0; /* Setar como 1 caso Digital */ 
  int teste_while_sumo = 0;   /* Teste do do while que mostra que o robo está de frente para o inimigo */
  int tempo_ir_tras_sumo_linha = 0; 
  int tempo_ir_frente_sumo = 0;
  int tempo_ir_tras_sumo_inimigo = 0;
  int tempo_ir_direta_sumo = 0;
  int tempo_ir_esquerda_sumo = 0;
  int Contagem_Para_Entrar_Sumo = 0; /* Delay antes de entrar na linha sumo */
  int Delay_Para_Entrar_Sumo = 0;
  
  int leitura_infra_direita;
  int leitura_infra_esquerda;

 /* Essa parte (dos infravermelhos)  já tem no código feito pelo eduardo */
  int infravermelho_direita = 4;
  int infravermelho_esquerda = 5;
  int Receptor_Direito = 6;
  int Receptor_Esquerdo = 9;

void setup() {
  //colocar direita 11 esquerda 10
  direita.attach(12); /*Motor Direita */
  esquerda.attach(11);  /*Motor Esquerda */
  
  Serial.begin(9600);

  pinMode(trigger, OUTPUT);
  pinMode(trigger_tras, OUTPUT);
  
  pinMode(leitor_echo, INPUT);
  pinMode(leitor_echo_tras, INPUT);

  pinMode(infravermelho_direita, OUTPUT);
  pinMode(infravermelho_esquerda, OUTPUT);

  pinMode(Receptor_Direito, INPUT);
  pinMode(Receptor_Esquerdo, INPUT);

  pinMode(leitor_de_linha_direita, INPUT);
  pinMode(leitor_de_linha_direita, INPUT);

  pinMode(led, OUTPUT);
  pinMode(leitor_ldr, INPUT);   
}


  void loop() {
  
 //falta botão de acionamento
 //verificar regras da COBRE
  
  
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
     
     
     
 if((unsigned long)millis()-tempo_modo >= 5000 && timer_modo == 1 || pular_millis == 1){
   
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
 
}

void labirinto(){
  
  //faz o codigo alguem : eduardo
  
  
  
}

void sumo(){
  
 /* Sumô_Labirinto */
    if(Contagem_Para_Entrar_Sumo == 0){
      ir_frente(Delay_Para_Entrar_Sumo);  /* Parte para ele entrar no campo de sumô no Percurso de Sábado ( APENAS NO PERCURSO DE SÁBADO ) */
      Contagem_Para_Entrar_Sumo = 1;
    }

     

    leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);      /* Leitura de Linha para Ver se está Na Arena*/
    leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   /* 
    *   Caso queira testar os valores: 
    *   Serial.print("Direita  ");
        Serial.println(leitura_de_linha_direita);
        Serial.print("Esquerda ");
        Serial.println(leitura_de_linha_esquerda);
    */
   
    if(leitura_de_linha_direita <= valor_min_l_linha_sumo){
      ir_atras(tempo_ir_tras_sumo_linha);        /* Ir para trás caso Esteja na linha branca */
    }else{
      if(leitura_de_linha_esquerda <= valor_min_l_linha_sumo){
       ir_atras(tempo_ir_tras_sumo_linha);
      
    }
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      leitura_echo = pulseIn(leitor_echo, HIGH); 
      distancia_ultrasonica = (leitura_echo / 29) / 2;

      
       /* Teste de Valores: 
       * 
       * Serial.println("Distancia Frontal:");
          Serial.print(distacia_ultrasonica);
          Serial.println("cm");
  
       */
     if(distancia_ultrasonica < distancia_minima_inimigo_ultra){
      ir_frente(tempo_ir_frente_sumo);
     }else{
      digitalWrite(trigger_tras, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger_tras, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger_tras, LOW);
      delayMicroseconds(2);
      
      
      leitura_echo_tras = pulseIn(leitor_echo_tras, HIGH);
      distancia_ultrasonica_tras = (leitura_echo_tras / 29) / 2;


       /* Teste de Valores: 
       * 
       * Serial.println("Distancia Trasiera:");
          Serial.print(DistanciaTraseira);
          Serial.println("cm");
  
       */
      
        if(distancia_ultrasonica_tras < distancia_minima_inimigo_ultra){
          ir_atras(tempo_ir_tras_sumo_inimigo);
        }else{
         teste_while_sumo=0; /* Zerar o Teste para não ficar em 1 no loop */
           do{
                
               for( w = 0 ; w < 33 ; w++){
                digitalWrite(infravermelho_direita, HIGH);
                delayMicroseconds(13);
                digitalWrite(infravermelho_direita,LOW);
                delayMicroseconds(13);
               }
               leitura_infra_direita = analogRead(Receptor_Direito);
          
           if(leitura_infra_direita < distancia_minima_inimigo_infra){
              ir_direita(tempo_ir_direta_sumo);
           }else{
            
               for( w = 0 ; w < 33 ; w++){
                digitalWrite(infravermelho_esquerda, HIGH);
                delayMicroseconds(13);
                digitalWrite(infravermelho_esquerda, LOW);
                delayMicroseconds(13);
               }
               
               leitura_infra_esquerda = analogRead(Receptor_Esquerdo);
                             
              
              if(leitura_infra_esquerda < distancia_minima_inimigo_infra) {
                ir_esquerda(tempo_ir_esquerda_sumo);
              }else{
                      teste_while_sumo=1;
              }
                     }
                  }while(teste_while_sumo==1);
           }
        }
 
  
  
  
}
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
  



