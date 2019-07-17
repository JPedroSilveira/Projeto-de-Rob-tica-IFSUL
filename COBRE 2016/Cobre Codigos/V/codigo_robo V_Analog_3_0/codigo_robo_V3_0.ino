#include <Servo.h>

Servo direita;
int diferenca_E = 0;

Servo esquerda;
int diferenca_D = 0;

int distancia = 13;

int infra = 13;
const int receptor = 0;
int R;
int R2;
int cont = 0;
int cont_tempo = 0;

int controle1 = 0;

int G_corrigido;

int G_ = 0;
int CF_ = 180;

int CA_ = 70;
int CDE_ = 150;

byte leitura;

void setup() {
  
  direita.attach(12);
  esquerda.attach(11);
  pinMode(infra, OUTPUT);
  pinMode(receptor, INPUT);
  Serial.begin(9600);

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop() {
  
//----------------------------------simples_emissao_leitura_impressao area-------------------------------------------------------------------------------------------------------------------------  

 piscar_do_infravermelho();
  
  leitura = analogRead(receptor);
  
  Serial.println(leitura);
  
//----------------------------------Deteccao_e_reacao_imediata area-------------------------------------------------------------------------------------------------------------------------  
  
  if(leitura < distancia){
    cont_tempo = 0;
    Serial.println("OBJETO DETECTADO");
    Serial.println("indo: atras");
    do{
                  
    ir_atras(G_,CA_);
    delay(100);
    cont_tempo++;
    piscar_do_infravermelho();
    leitura = analogRead(receptor);
   
    }while(cont_tempo<20);
    controle1 = 1;
    
//----------------------------------Randomico_com_Direita_Esquerda area-------------------------------------------------------------------------------------------------------------------------    
    
  }else{
    if(controle1 == 1){
      cont_tempo = 0;
      Serial.println("randomico: direita e esquerda");
      randomico_CDE(G_,CDE_,0);
      do{
        
        
    piscar_do_infravermelho();    
    randomico_CDE(G_,CDE_,1);
    delay(100);
    cont_tempo++;
    
    leitura = analogRead(receptor);
    if(leitura < distancia){
      cont_tempo = 30;      
    }
    }while(cont_tempo<30);
   
      controle1 = 0;
      
//----------------------------------Randomico_geral_area-------------------------------------------------------------------------------------------------------------------------
      
    }else{
      cont_tempo = 0;
      Serial.println("randomico: direita, esquerda, frente, atras");
      randomico_geral(G_,CDE_,CA_,CF_,0);
      do{
    piscar_do_infravermelho();
    randomico_geral(G_,CDE_,CA_,CF_,1);
    delay(100);
    cont_tempo++;
    
    leitura = analogRead(receptor);
    if(leitura < distancia){
      cont_tempo = 50;
Serial.println(cont_tempo);      
    }
    }while(cont_tempo<50);
      
       
           
    }      
  }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 void piscar_do_infravermelho (){
    
    for(byte x = 0;x <= 38; x++){
    digitalWrite(infra, HIGH);
    delayMicroseconds(13);
    digitalWrite(infra, LOW);
    delayMicroseconds(13);
    
    
  }
    leitura = analogRead(receptor);
  }
  

 void  ir_esquerda(int G, int CDE){
   
   if(CDE>0){
   G_corrigido = CDE - diferenca_E;
 esquerda.write(G_corrigido); 
   }else{
   
    G_corrigido = G - diferenca_E;
 esquerda.write(G_corrigido);
   }
 }
 void  ir_direita(int G, int CDE){
     
   if(CDE>0){
   G_corrigido = CDE - diferenca_D;
 direita.write(G_corrigido); 
   }else{
   
    G_corrigido = G - diferenca_D;
 direita.write(G_corrigido);
   }
 }
 
 void ir_frente(int G, int CF){
 
   if(CF>0){
   ir_direita(CF,0);
  ir_esquerda(CF,0);  
   }else{
   ir_direita(G,0);
   ir_esquerda(G,0);
   }
 }
 void ir_atras(int G, int CA){
 
   if(CA>0){
   ir_direita(CA,0);
   ir_esquerda(CA,0);  
   }else{
   ir_direita(G,0);
   ir_esquerda(G,0);
   }
 }
 void randomico_CDE(int G, int CDE, int cosmos){
   
   if(cosmos == 0){
   
  R2 = random(2);
 
   }else{
   
   if(R==0){
     ir_direita(G,CDE);
   }else{
     ir_esquerda(G,CDE);
     
   }   
 }}
 
 void randomico_geral(int G, int CDE, int CA, int CF, int cosmos){
   
   if(cosmos == 0){
   
    R2 = random(4);
   
   }else{
   
   if(R==0){
     ir_frente(G,CF);
   }else{
     if(R==1){
       ir_atras(G,CA);
     }else{
       if(R==2){
         ir_direita(G,CDE);
       }else{
         ir_esquerda(G,CDE);
       }
     }
   }
 }}  
   
   
   
   
 

