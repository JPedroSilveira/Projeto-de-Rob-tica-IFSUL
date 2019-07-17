 
 #include <Servo.h>

  Servo direita;
  Servo esquerda;

  int w; /* Para o for do infravermelho*/
  /*Parte que tem no código do Gabriel */
  int leitor_echo = A5;
  int leitor_echo_tras =  A1; /*Adicionado para o Sumô */
  int trigger = 7;
  int trigger_tras = 8; /*Adicionado para o Sumô */
  long leitura_echo = 0; 
  long leitura_echo_tras = 0; /*Adicionado para o Sumô */
  long distancia_ultrasonica = 0;
  long distancia_ultrasonica_tras = 0; /*Adicionado para o Sumô */

  //seguidor de linha

  int leitura_de_linha_direita = 0;
  int leitura_de_linha_esquerda = 0;

  int leitor_de_linha_direita = A2;
  int leitor_de_linha_esquerda = A3;


  // Fim da parte do Gabriel
  
  int valor_min_l_linha_sumo = 1;
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
 
// Fim da parte do Eduardo

  void setup() {
    /* Setup da Parte que está com o Gabriel */
    direita.attach(12); /*Motor Direita */
    esquerda.attach(11); /*Motor Esquerda */
  
    Serial.begin(9600);
  
    pinMode(leitor_echo, INPUT);
    pinMode(leitor_echo_tras, INPUT);

    pinMode(trigger, OUTPUT);
    pinMode(trigger_tras, OUTPUT);

    pinMode(infravermelho_direita, OUTPUT);
    pinMode(infravermelho_esquerda, OUTPUT);

    pinMode(Receptor_Direito, INPUT);
    pinMode(Receptor_Esquerdo, INPUT);

    pinMode(leitor_de_linha_direita, INPUT);
    pinMode(leitor_de_linha_direita, INPUT);

    
    /* Fim do Setup da Parte do Gabriel */

    
  }

  void loop() {

  
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
     
