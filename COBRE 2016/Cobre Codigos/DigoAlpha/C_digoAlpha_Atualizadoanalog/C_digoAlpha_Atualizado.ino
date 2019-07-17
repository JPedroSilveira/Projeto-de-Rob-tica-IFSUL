#include <Servo.h>

//Portas ocupadas: A2, A3, 4, A4, A5 , 7, 6, 9, 11, 12.

//SERVO MOTOR{

Servo MotorDireito;  //Analógico
Servo MotorEsquerdo; //Analógico

int FrenteDireito = 0;
int FrenteEsquerdo = 180;
int PararMotor = 90;

//}

//SENSORES{

int QTIDireito = A2;  //Analógico
int QTIEsquerdo = A3; //Analógico

int SuperficieEscura = 600;

int Trig = 7; //Digital
int EchoFrontal = A5; //Analógico
int EchoTraseiro = A4; //Analógico

int Longinquidade = 5; //cm

int Infravermelho1 = 4;  //Digital
int Infravermelho2 = 5;  //Digital
int ReceptorDireito = A0; //Analógico
int ReceptorEsquerdo = A1;//Analógico

int LED = 1; //Analógico ou Digital
int LDR = 0; //Analógico

//}

void setup() {

  Serial.begin(9600);

  MotorDireito.attach(12);
  MotorEsquerdo.attach(11);
  MotorDireito.write(PararMotor); //FRENTE Direito: 0       //RÉ(Regredir): Direito: 180
  MotorEsquerdo.write(PararMotor); //FRENTE Esquerdo: 180   //RÉ(Regredir): Esquerdo: 0                        PARAR Ambos:90         Branco: < 200 Preto: > 200

  pinMode(Trig, OUTPUT);
  pinMode(EchoFrontal, INPUT);
  pinMode(EchoTraseiro, INPUT);

  pinMode(Infravermelho1, OUTPUT);
  pinMode(Infravermelho2, OUTPUT);
  pinMode(ReceptorDireito, INPUT);

  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);

}

void loop() {

  SeguirLinha();

  Labirinto();

  int Luminosidade = analogRead(LDR);
  analogWrite(LED, Luminosidade);

}

//FUNCIONAMENTOS{

//-Seguir Linha:

void SeguirLinha() {

  int Leitura_QTIDireito = analogRead(QTIDireito);
  int Leitura_QTIEsquerdo = analogRead(QTIEsquerdo);

  Serial.println("Direito:");
  Serial.println(Leitura_QTIDireito);
  Serial.println("Esquerdo:");
  Serial.println(Leitura_QTIEsquerdo);

  //seguir em frente:
  if (Leitura_QTIDireito >= SuperficieEscura
      && Leitura_QTIEsquerdo >= SuperficieEscura) {

    SeguirFrente();

  } else if (Leitura_QTIDireito < SuperficieEscura
             && Leitura_QTIEsquerdo < SuperficieEscura) {

    SeguirFrente();

    //curvar à direita:
  } else if (Leitura_QTIDireito >= SuperficieEscura) {

    CurvarDireita();

    //curvar à esquerda:
  } else if (Leitura_QTIEsquerdo >= SuperficieEscura) {

    CurvarEsquerda();

  }

}


//-Labririnto (Ultrassonico e Infravermelho):

void Labirinto() {

  digitalWrite(Infravermelho1, HIGH);
  digitalWrite(Infravermelho2, HIGH);

  int ReflexaoDireita = analogRead(ReceptorDireito);
  int ReflexaoEsquerda = analogRead(ReceptorEsquerdo);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long DuracaoSom_Frontal = pulseIn(EchoFrontal, HIGH);  //-> Verificar diferença entre "pulseIn" e "analogWrite"| pulseIn = retorno em microssegundos
  long DuracaoSom_Traseiro = pulseIn(EchoTraseiro, HIGH);
  long DistanciaFrontal = (DuracaoSom_Frontal / 29) / 2; //->Verificar diferença entre "long" e "double" | -> Pode se utilizar com cálculo (DuraçãoSom * 350)/1000000)/2
  long DistanciaTraseira = (DuracaoSom_Traseiro / 29) / 2;

  Serial.println("Distancia Frontal:");
  Serial.print(DistanciaFrontal);
  Serial.println("cm");

  Serial.println("Distancia Traseira:");
  Serial.print(DistanciaTraseira);
  Serial.println("cm");


  if (DistanciaFrontal <= Longinquidade) {

    if (ReflexaoDireita > ReflexaoEsquerda) {

      CurvarEsquerda();

    } else if (ReflexaoDireita < ReflexaoEsquerda) {

      CurvarDireita();

    } else if (ReflexaoDireita == ReflexaoEsquerda) {

      int SemRetorno = random (0, 1);

      if (SemRetorno == 0) {
        CurvarDireita();
      } else {
        CurvarEsquerda();
      }

    }

  } else {

    SeguirFrente();

  }


}


//-Sumô:




//}


//DIREÇÕES{

//Seguir em Frente:

void  SeguirFrente() {

  MotorDireito.write(FrenteDireito);
  MotorEsquerdo.write(FrenteEsquerdo);

}

//Curvar à Direita:

void  CurvarDireita() {

  MotorDireito.write(FrenteEsquerdo);
  MotorEsquerdo.write(FrenteEsquerdo);

}

//Curvar à Esquerda:

void  CurvarEsquerda() {

  MotorEsquerdo.write(FrenteDireito);
  MotorDireito.write(FrenteDireito);

}

//Curvar à Esquerda:

void Recuar() {

  MotorEsquerdo.write(FrenteDireito);
  MotorDireito.write(FrenteEsquerdo);

}

//}

