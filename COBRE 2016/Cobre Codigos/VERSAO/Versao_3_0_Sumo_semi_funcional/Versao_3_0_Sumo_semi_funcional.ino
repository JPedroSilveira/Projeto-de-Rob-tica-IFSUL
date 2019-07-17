 
 #include <Servo.h>

  Servo direita;
  Servo esquerda;

  
  /*Parte que tem no código do Gabriel */
  int leitor_echo_frente = A5;
  int leitor_echo_atras =  A1; /*Adicionado para o Sumô */
  int trigger_frente = 7;
  int trigger_atras = 8; /*Adicionado para o Sumô */
  long leitura_echo_frente = 0; 
  long leitura_echo_atras = 0; /*Adicionado para o Sumô */
  long distancia_ultrasonica_frente = 0;
  long distancia_ultrasonica_atras = 0; /*Adicionado para o Sumô */

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
  int tempo_ir_atras_sumo_linha = 0; 
  int tempo_ir_frente_sumo = 0;
  int tempo_ir_atras_sumo_inimigo = 0;
  int tempo_ir_direta_sumo = 0;
  int tempo_ir_esquerda_sumo = 0;
  int Contagem_Para_Entrar_Sumo = 0; /* Delay antes de entrar na linha sumo */
  
  int leitura_infra_direita;
  int leitura_infra_esquerda;

 /* Essa parte (dos infravermelhos)  já tem no código feito pelo eduardo. funçoes criadas ja (gabriel) */
  int infravermelho_direita = 4;
  int infravermelho_esquerda = 5;
  int Receptor_Direito = 6;
  int Receptor_Esquerdo = 9;
 
// Fim da parte do Eduardo

//botão de acionamento (inicial)
  
  int botao = 3;
  int leitura_botao = 0;


  void setup() {
    /* Setup da Parte que está com o Gabriel colocar direita 11 e esquerda 10 */
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
   
   parado(0);
    
  }




  void loop() {

  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    
    
    if(leitura_botao==0){
   
   leitura_botao = digitalRead(botao); 
    
  }else{
    
  
 // 10 segundos de delay antes do inicio do sumo
    if(Contagem_Para_Entrar_Sumo == 0){
      delay(10000);  
      Contagem_Para_Entrar_Sumo = 1;
    }


   sumo();


  }
  }
  
  
  
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
     void sumo(){

    leitura_de_linha_esquerda = analogRead(leitor_de_linha_esquerda);      /* Leitura de Linha para Ver se está Na Arena*/
    leitura_de_linha_direita = analogRead(leitor_de_linha_direita);
   /* 
        Caso queira testar os valores: 
        Serial.print("Direita  ");
        Serial.println(leitura_de_linha_direita);
        Serial.print("Esquerda ");
        Serial.println(leitura_de_linha_esquerda);
    */
   
    if(leitura_de_linha_direita <= valor_min_l_linha_sumo){
      ir_atras(tempo_ir_atras_sumo_linha);        /* Ir para trás caso Esteja na linha branca */
    }else{
      if(leitura_de_linha_esquerda <= valor_min_l_linha_sumo){
       ir_atras(tempo_ir_atras_sumo_linha);
      
    }
    
      ultrasonico_frente();
  
       
     if(distancia_ultrasonica_frente < distancia_minima_inimigo_ultra){
      ir_frente(tempo_ir_frente_sumo);
     }else{
       
      
      ultrasonico_atras();


       
       
      
        if(distancia_ultrasonica_atras < distancia_minima_inimigo_ultra){
          ir_atras(tempo_ir_atras_sumo_inimigo);
        }else{
         teste_while_sumo=0; /* Zerar o Teste para não ficar em 1 no loop */
           do{
              
              infra_direita();
          
           if(leitura_infra_direita < distancia_minima_inimigo_infra){
              ir_direita(tempo_ir_direta_sumo);
           }else{
               
               infra_esquerda();
               
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
               leitura_infra_direita = analogRead(Receptor_Direito);
            // leitura_infra_direita = digitalRead(Receptor_Direito);
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
               
               leitura_infra_esquerda = analogRead(Receptor_Esquerdo);
            // leitura_infra_esquerda = digitalRead(Receptor_Esquerdo);           
                /*
  
              Serial.print(leitura_infra_esquerda);
              Serial.println("cm");
              Serial.println(); 
  
                */                         
                         
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
     
