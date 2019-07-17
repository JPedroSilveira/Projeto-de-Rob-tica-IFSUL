#include <Servo.h>

Servo direita;
Servo esquerda;

 /*ULTRASONICO VARIÁVEIS*/
 int leitor_echo_frente = A5;
 int leitor_echo_atras =  A1; /*Adicionado para o Sumô */
 int trigger_frente = 7;
 int trigger_atras = 8; /*Adicionado para o Sumô */
 long leitura_echo_frente = 0; 
 long leitura_echo_atras = 0; /*Adicionado para o Sumô */
 long distancia_ultrasonica_frente = 0;
 long distancia_ultrasonica_atras = 0; /*Adicionado para o Sumô */
 /*_____________________________________________________________*/
 
 /*LEITURA DE LINHA*/
  int leitura_de_linha_direita = 0;
  int leitura_de_linha_esquerda = 0;

  int leitor_de_linha_direita = A2;
  int leitor_de_linha_esquerda = A3;
 /*_____________________________________________________________*/

 /*LEITURA DE INFRAVERMELHO*/
 
  int leitura_infra_direita;
  int leitura_infra_esquerda;
  int infravermelho_direita = 4;
  int infravermelho_esquerda = 5;
  int Receptor_Direito = 6;
  int Receptor_Esquerdo = 9;
  
 
 /*_____________________________________________________________*/
  
 /*  THE BUTOM  */

  int botao = 3;
  int leitura_botao = 0;

 /*______________________________________________________________*/

 /* VARIAVEIS A DEFINIR */
 
  int direcao = 0;
  int valor_minimo_leitura_linha_sumo = 1; /*  +CONFIGURAR-, Valor da leitura da linha branca para o robo parar e ficar na preta*/
  int distancia_minima_inimigo_ultra = 0; /*  +CONFIGURAR-, Distancia do Robo inimigo minima para ele avançar pelo ultra, inimigo pelo ultra em cm*/
  int distancia_minima_inimigo_infra = 1; /*Setar como 1 caso Digital, Distancia do Robo inimigo minima para ele avançar pelo infra*/ 
  int tempo_ir_atras_sumo_linha = 0; /* +CONFIGURAR-,  Tempo que o robo deve ir para tras quando ler a linha branca*/
  int tempo_ir_atras_sumo_inimigo = 0; /* Tempo para ele ir para tras caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int tempo_ir_frente_sumo = 0; /* Tempo para ele ir para frente caso detecte o inimigo, por padrão para não interferir nas leituras 0 */
  int tempo_ir_direta_sumo = 0; /* Tempo para ele ir para direita caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int tempo_ir_esquerda_sumo = 0; /* Tempo para ele ir para esquerda caso detecte o inimigo, por padrão para não interferir nas leituras 0*/
  int Contagem_Para_Entrar_Sumo = 0; /* Contagem para o delay antes de entrar na linha sumo, definido como 0 e depois tranformado em 1 na primeira rodada para o delay não se repetir */
  int ja_fui_para_atras; /* Variavel para ele saber se já foi para trás atrás do inimigo */
  int ja_fui_para_atras_tempo_frente = 0; /*+CONFIGURAR- , Tempo para ele ir para frente logo após ter ido para trás atrás do inimigo e ele não estiver mais lá  */

 /*______________________________________________________________*/
 
void setup() {
    // direita = 11 direita 10
    direita.attach(12); /*Motor Direita */
    esquerda.attach(11); /*Motor Esquerda */
  
    Serial.begin(9600);

    pinMode(leitor_echo_frente, INPUT);
    pinMode(leitor_echo_atras, INPUT);

    pinMode(trigger_frente, OUTPUT);
    pinMode(trigger_atras, OUTPUT);

    pinMode(infravermelho_direita, OUTPUT);
    pinMode(infravermelho_esquerda, OUTPUT);
  
    //apagar analogico nao precisa anunciar
/*
    pinMode(Receptor_Direito, INPUT);
    pinMode(Receptor_Esquerdo, INPUT);

    pinMode(leitor_de_linha_direita, INPUT);
    pinMode(leitor_de_linha_esquerda, INPUT);
*/
    
    /* Fim do Setup da Parte do Gabriel */ 
   
    direita.write(90);
    esquerda.write(90); 

}

void loop() {

  if(leitura_botao==0){
   
  leitura_botao = digitalRead(botao); 
    
  }else{

   /* 10 segundos de delay antes do inicio do sumo*/
    
   if(Contagem_Para_Entrar_Sumo == 0){
    delay(10000);  
    Contagem_Para_Entrar_Sumo = 1;
   }


   sumo();

  
  

}
}

void sumo(){
   
   
      do{
         /*VERIFICANDO SE JÁ FOI PARA TRÁS E SE O INIMIGO AINDA ESTÁ ATRÁS DELE, CASO NÃO ESTEJA ELE IRÁ PARA FRENTE ( RECUARÁ ) POR UM CERTO TEMPO*/
         
        ultrasonico_atras();
        if(ja_fui_para_atras==1 && distancia_ultrasonica_atras >= distancia_minima_inimigo_ultra){
          ja_fui_para_atras=0;
          ir_frente(ja_fui_para_atras_tempo_frente);
          // deve ser diferente de 0
         
          
        }

   /*___________________________________________________________________________________________________________________________________________*/
       
         
        /*FAZENDO LEITURA DA LINHA*/
        leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda); /* Leitura de Linha para Ver se está Na Arena*/
        leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
        
        /* 
        Caso queira testar os valores: 
        Serial.print("Direita  ");
        Serial.println(leitura_de_linha_direita);
        Serial.print("Esquerda ");
        Serial.println(leitura_de_linha_esquerda);
        */

        /*____________________________________________________________________________________________________________*/

        /* REAÇÕES CASO ESTEJA NA LINHA BRANCA */
        
        if(leitura_de_linha_direita <= valor_minimo_leitura_linha_sumo){
          ir_atras(tempo_ir_atras_sumo_linha);
          // tenque ser diferente de 0          /* Ir para trás caso Esteja na linha branca */
        }else{ 
        if(leitura_de_linha_esquerda <= valor_minimo_leitura_linha_sumo){
          ir_atras(tempo_ir_atras_sumo_linha);
         // tenque ser diferente de 0 
        }
        }
        
        /*FIM DA REAÇÕES DA LINHA BRANCA*/

 
        /*PREPARANDO PARA AVANÇAR NO INIMIGO*/
      
       ultrasonico_atras();

       if(distancia_ultrasonica_atras < distancia_minima_inimigo_ultra){
        ir_atras(tempo_ir_atras_sumo_inimigo);
        // tempo_ir_atras_inimigo tenque ser = 0
        ja_fui_para_atras=1;
            
       }else{

       
  
       ultrasonico_frente();

       if(distancia_ultrasonica_frente < distancia_minima_inimigo_ultra){
         ir_frente(tempo_ir_frente_sumo);
         // tempo_ir_frente_sumo tenque ser = 0
       }else{

             infra_direita();
             if(leitura_infra_direita < distancia_minima_inimigo_infra){
              direcao = 0;
             }else{

             infra_esquerda();
             if(leitura_infra_esquerda < distancia_minima_inimigo_infra) {
               direcao = 1;
             }else{
               
               if(direcao == 0){
                 
                 ir_direita(0); 
                 
               }else{
               if(direcao == 1){  
                 ir_esquerda(0);
               }
               }
                
             }               
       }
       }  
       }
              
       }while(0==0);

       /* FIM DA LUTA (DO-WHILE) */
}


  /*==========================*/
  /*   FUNÇÕES DOS SENSORES   */
  /*==========================*/

void ultrasonico_atras(){
  
          digitalWrite(trigger_atras, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigger_atras, LOW);
         
          leitura_echo_atras = pulseIn(leitor_echo_atras, HIGH);
      
          distancia_ultrasonica_atras = (leitura_echo_atras / 29) / 2;
  
  /*
  
  Serial.print(distancia_ultrasonica_atras);
  Serial.println("cm");
  Serial.println(); 
  
  */
  
}

void ultrasonico_frente(){
  
  
  
          digitalWrite(trigger_frente, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigger_frente, LOW);
  
          leitura_echo_frente = pulseIn(leitor_echo_frente, HIGH);
  
          distancia_ultrasonica_frente = leitura_echo_frente /29 / 2; 
  
           /*
  
           Serial.print(distancia_ultrasonica_frente);
           Serial.println("cm");
           Serial.println();  

           */  
 
}

void infra_direita(){  
              
          for(int i = 0 ; i < 33 ; i++){
            digitalWrite(infravermelho_direita, HIGH);
            delayMicroseconds(13);
            digitalWrite(infravermelho_direita,LOW);
            delayMicroseconds(13);
            }
            
            leitura_infra_direita = digitalRead(Receptor_Direito);
                /*
  
              Serial.print(leitura_infra_direita);
              Serial.println("cm");
              Serial.println(); 
  
                */
               
              }

void infra_esquerda(){
                
        for(int i = 0 ; i < 33 ; i++){
          digitalWrite(infravermelho_esquerda, HIGH);
          delayMicroseconds(13);
          digitalWrite(infravermelho_esquerda, LOW);
          delayMicroseconds(13);
         }

         leitura_infra_esquerda = digitalRead(Receptor_Esquerdo); 

}

  /*====================================*/
  /*   FINAL DAS FUNÇÕES DOS SENSORES   */
  /*====================================*/


  /*=========================*/
  /*   FUNÇÕES DE DIREÇÕES   */
  /*================== ======*/
  
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

 /*===================================*/
 /*   FINAL DAS FUNÇÕES DE DIREÇÕES   */
 /*===================================*/

 /*=============*/
 /*    FIM      */
 /*=============*/


