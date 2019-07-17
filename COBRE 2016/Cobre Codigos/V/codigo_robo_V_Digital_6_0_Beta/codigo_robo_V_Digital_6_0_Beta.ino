#include <Servo.h>

Servo direita;
int diferenca_E = 0;

Servo esquerda;
int diferenca_D = 0;

int distancia = 1;

int campainha = 8;
int led = 9;

int infra_atras = 7;
int infra = 13;
double a;

const int receptor = 4;
const int receptor_atras = 3;

int key = 0;
int key2 = 0;
int R;
int R2;
int cont = 0;
int cont_tempo = 0;

int controle1 = 0;

int G_corrigido;

int G_ = 0;
int CF_ = 180;

int CA_ = 30;
int CDE_ = 150;

int U = 0;
int Y = 0;

byte leitura;
byte leitura2;

void setup() {
  
  direita.attach(12);
  esquerda.attach(11);
  pinMode(infra, OUTPUT);
  pinMode(infra_atras, OUTPUT);
  pinMode(receptor, INPUT);
  pinMode(receptor_atras, INPUT);
  pinMode(led, OUTPUT);
  pinMode(campainha, OUTPUT);
  Serial.begin(9600);
  

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop() {
  
//----------------------------------simples_emissao_leitura_impressao area-------------------------------------------------------------------------------------------------------------------------  

 piscar_do_infravermelho();
  
  leitura = digitalRead(receptor);
  
  Serial.println(leitura);
 
//----------------------------------Frente_e_reação_imediate area--------------------------------------------------------------------------------------------------------------------------- 
 
  cont_tempo = 0;
  if(Y == 1){
    
    Serial.println("indo: frente");
    do{
                  
    ir_frente(G_,CF_);
    delay(10);
    cont_tempo++;
    
    piscar_do_led(cont_tempo);
    
    piscar_do_infravermelho();
    
    leitura = digitalRead(receptor);
    
    if(leitura < distancia){
      cont_tempo = 100;
      U = 1;
Serial.println("CANCELADO = OBJETO DETECTADO: atras");      
    }
   
    }while(cont_tempo<100);
    Y = 0;
    
    digitalWrite(led, LOW);
    key = 0;
    
  }else{
//----------------------------------Deteccao_e_reacao_imediata area-------------------------------------------------------------------------------------------------------------------------  
  cont_tempo = 0;
  if(leitura < distancia || U == 1){
    
    Serial.println("OBJETO DETECTADO");
    Serial.println("indo: atras");
    do{
                  
    ir_atras(G_,CA_);
    delay(10);
    cont_tempo++;
    
    buzzer(cont_tempo);
    
    piscar_do_infravermelho_atras();
    
    leitura2 = digitalRead(receptor_atras);
    
    if(leitura2 < distancia){
      cont_tempo = 150;
      Y = 1;
Serial.println("CANCELADO = OBJETO DETECTADO: atras");      
    }
   
    }while(cont_tempo<150);
    controle1 = 1;
    U = 0;
    
    digitalWrite(campainha, LOW);
    key2 = 0;
    
//----------------------------------Randomico_com_Direita_Esquerda area-------------------------------------------------------------------------------------------------------------------------    
    
  }else{
    if(controle1 == 1){
      Serial.println("randomico: direita e esquerda");
      randomico_CDE(G_,CDE_,0);
      do{
        
    delay(10);    
    randomico_CDE(G_,CDE_,1);
    cont_tempo++;
    piscar_do_infravermelho();
    leitura = digitalRead(receptor);
    if(leitura < distancia){
      cont_tempo = 100;
      U = 1;
Serial.println("CANCELADO = OBJETO DETECTADO: frente");      
    }
    }while(cont_tempo<100);
   
      controle1 = 0;
      
//----------------------------------Randomico_geral_area-------------------------------------------------------------------------------------------------------------------------
      
    }else{
      
      Serial.println("randomico: direita, esquerda, frente");
      
      randomico_geral(G_,CDE_,CA_,CF_,0);
      
      digitalWrite(led, HIGH);
      
      do{
        
    delay(10);    
    randomico_geral(G_,CDE_,CA_,CF_,1);
    cont_tempo++;
    piscar_do_infravermelho();
    leitura = digitalRead(receptor);
    if(leitura < distancia){
      cont_tempo = 200;
      U = 1;
Serial.println("CANCELADO = OBJETO DETECTADO: frente");      
    }
    }while(cont_tempo<200);
      
       digitalWrite(led, LOW);
           
    }      
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
  }
  
void piscar_do_infravermelho_atras (){
    
    for(byte x = 0;x <= 38; x++){    
    digitalWrite(infra_atras, HIGH);
    delayMicroseconds(13);
    digitalWrite(infra_atras, LOW);
    delayMicroseconds(13);
    
    
  }
  }
  
void piscar_do_led  (int A){
 int cont = 0;
 int cont2 = 0;
 
 if(A-cont > 40 && key == 0){
 cont = A;
 key = 1;
 digitalWrite(led, HIGH);  
 }else{
 if(A-cont2 > 40 && key == 1){
 cont2 = A;
 key = 0; 
 digitalWrite(led, LOW); 
 }
 }
 }
 
 void buzzer (int A){
 int cont = 0;
 int cont2 = 0;
 
 if(A-cont > 20 && key2 == 0){
 cont = A;
 key2 = 1;
 digitalWrite(campainha, HIGH); 
 }else{
 if(A-cont2 > 20 && key2 == 1){
 cont2 = A;
 key2 = 0;
 digitalWrite(campainha, LOW); 
 }
 }
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
   
  R = random(2);
 
   }else{
   
   if(R==0){
     ir_direita(G,CDE);
   }else{
     if(R==1){
     ir_esquerda(G,CDE);
     }
   }   
 }
 }
 
 void randomico_geral(int G, int CDE, int CA, int CF, int cosmos){
   
   if(cosmos == 0){
   
    R2 = random(3);
   
   }else{
   
   if(R2==0){
     ir_frente(G,CF);   
     }else{
       if(R2==1){
         ir_direita(G,CDE);
       }else{
         if(R2==2){
         ir_esquerda(G,CDE);
         }
       }
     }
   }
 }

