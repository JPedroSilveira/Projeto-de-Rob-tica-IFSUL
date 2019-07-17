#include <Servo.h>

Servo direita;
int diferenca_E = 0;

Servo esquerda;
int diferenca_D = 0;

int distancia = 0;

int infra = 13;
int receptor = 0;
int R;
int cont = 0;
int cont_tempo = 0;

int controle1 = 0;

int G_corrigido;

int G_ = 0;
int CF_ = 180;

int CA_ = 30;
int CDE_ = 180;

int leitura;

void setup() {
  
  direita.attach(12);
  esquerda.attach(11);
  pinMode(infra, OUTPUT);
  pinMode(receptor, INPUT);
  Serial.begin(9600);

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void loop() {

 piscar_do_infravermelho();
  
  leitura = analogRead(receptor);
  
  Serial.println(leitura);
  
  if(leitura > distancia){
    cont_tempo = 0;
    Serial.println("OBJETO DETECTADO");
    Serial.println("indo: atras");
    do{
                  
    ir_atras(G_,CA_);
    delay(100);
    cont_tempo++;
    
    leitura = analogRead(receptor);
   
    }while(cont_tempo<40);
    controle1 = 1;
    
  }else{
    if(controle1 == 1){
      cont_tempo = 0;
      Serial.println("randomico: direita e esquerda");
      do{
    randomico_CDE(G_,CDE_);
    delay(100);
    cont_tempo++;
    
    leitura = analogRead(receptor);
    if(leitura > distancia){
      cont_tempo = 30;      
    }
    }while(cont_tempo<30);
   
      controle1 = 0;
      
    }else{
      cont_tempo = 0;
      Serial.println("randomico: direita, esquerda, frente, atras");
      do{
    randomico_geral(G_,CDE_,CA_,CF_);
    delay(100);
    cont_tempo++;
    
    leitura = analogRead(receptor);
    if(leitura > distancia){
      cont_tempo = 50;      
    }
    }while(cont_tempo<50);
      
       
           
    }      
  }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 void piscar_do_infravermelho (){
    
    for(int frequencia = 0; frequencia < 38; frequencia++){
      
    digitalWrite(infra, HIGH);
    delayMicroseconds(13);
    digitalWrite(infra, LOW);
    delayMicroseconds(13);
    
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
 void randomico_CDE(int G, int CDE){
   
 int R = random(2);
   
   if(R==0){
     ir_direita(G,CDE);
   }else{
     ir_esquerda(G,CDE);
     
   }   
 }
 
 void randomico_geral(int G, int CDE, int CA, int CF){
   
   int R = random(4);
   
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
 }  
   
   
   
   
 

