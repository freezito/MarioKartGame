#include <Servo.h>                  // SE DEFINE AL SERVOMOTOR.

Servo servo1;
int pinservo = A4;
int pulsomin = 700; // 900microseg=1ms equivale a 0grados
int pulsomax = 2550; // 2720 microseg=2ms equivale a 180grados

int TRIG = A0;
int ECHO = A1;
int DURACION;
int DISTANCIA;
int DISTANCIAR;
int DISTANCIAL;
int medirDistancia();
int lookRight();
int lookLeft();
int moveStop();
int moveBackward();
int moveForward();
int moveForward2();
int ataque();

int getRojo();
int getVerde();
int getAzul();
int getBlanco();
//int turnLeft();
//int turnRight();

int S0 = 4;
int S1 = 7;
int S2 = 8;
int S3 = 12;
int salidaTCS = 13;

const int motorPin1  = 3;          
const int motorPin2  = 5;          
const int motorPin3  = 6;          
const int motorPin4  = 11; 


void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
 // pinMode(9, OUTPUT);
  servo1.attach(pinservo, pulsomin, pulsomax);
  //Serial.begin(9600);
  
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(salidaTCS, INPUT);
//digitalWrite(5,LOW);
digitalWrite(S0, HIGH);
digitalWrite(S1, HIGH);
        servo1.write(90); 
       // sing(1);
       // sing(1);
       // sing(2);
        
}

void loop() {
DISTANCIA = medirDistancia(); // medir distancia
//delay(150); 
  if(DISTANCIA<18 && DISTANCIA >=0)
  { 
     moveStop();
     delay(100);
      int rojo=getRojo();
      //delay(50);
      int verde = getVerde();
      //delay(50);
      int azul = getAzul();
      //delay(50);
      int blanco = getBlanco();
      //delay(50);  
    //Serial.print("Distancia: " + String(DISTANCIA));
    //Serial.print("\t");
    //Serial.print("R: " + String(rojo));
    //Serial.print("\t");
    //Serial.print("V: " + String(verde));
    //Serial.print("\t");
    //Serial.print("A: " + String(azul));
    //Serial.print("\t");
    //Serial.println("B: " + String(blanco));
    //Serial.println(DISTANCIA);
    //Serial.println(rojo);
    //Serial.println(verde);
    //Serial.println(azul);
    //Serial.println(blanco);
          // if  (rojo<46 && verde>50 && azul>55 && blanco>15)
      if  (rojo<51 && verde>50 && azul>55 && blanco>10)
      { 
      ataque();
      
        Serial.println("rojo");
     
       
        } 
     //   if (rojo>40 && verde<50 && azul<55 && blanco<21){
          //Serial.println("azul");
      //  ataque();}
      else{  
        //moveStop();
        //delay(100);
        DISTANCIAR=lookRight();
        delay(150);
        DISTANCIAL=lookLeft();
        //Serial.println(DISTANCIAR<DISTANCIAL);
        delay(150);
        if (DISTANCIAR < DISTANCIAL) {                   
      
      moveStop();
      delay(100);
      moveBackward();
      delay(600);
      turnRight(); 
      delay(450);
      }  
       else
      {
       moveStop();
       delay(100);
       moveBackward();
       delay(600);
       turnLeft(); 
       delay(450);
              }}}
  else moveForward();
        //delay(100);
}

int medirDistancia() {
   int DISTANCIA = 0;
   int DURACION = 0;
   digitalWrite(TRIG, HIGH);
  delay(2);  //pulso alto de un 5 mseg 
  digitalWrite(TRIG, LOW); //pulso se suprime
  DURACION = pulseIn(ECHO, HIGH); //tiempo en microseg del rebote en un pulso alto
  DISTANCIA = DURACION/58.2; // distancia de deteción
  //Serial.println(DISTANCIA); //imprimir en el monitor serial, si el dato es negativo esta fuera de rango
  //delay(5);
  return DISTANCIA;
}

int getRojo(){    //detecta rojo
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
int rojo =pulseIn(salidaTCS, LOW);
return rojo;
}

int getVerde(){
  // detecta color verde
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
int verde =pulseIn(salidaTCS, LOW);
return verde;
}

int getAzul(){
  //detecta azul
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
int azul =pulseIn(salidaTCS, LOW);
return azul;
}
int getBlanco(){
  //detecta azul
digitalWrite(S2,HIGH);
digitalWrite(S3,LOW);
int blanco =pulseIn(salidaTCS, LOW);
return blanco;
}


int moveStop() {              // SE APAGAN MOTORES y SE DETIENE
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
     //delay(5);    
  } 
  
int moveForward() {        //CARRITO AVANZA, RUEDA DERECHA E IZQUIERDA AVANZAN HACIA ADELANTE
    analogWrite(motorPin1, 255);       
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);     
    analogWrite(motorPin4, 255);
     //delay(5);      
  }

int moveForward2() {        //CARRITO AVANZA, RUEDA DERECHA E IZQUIERDA AVANZAN HACIA ADELANTE
    analogWrite(motorPin1, 255);       
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);     
    analogWrite(motorPin4, 255);
     //delay(5);      
  }
int moveBackward() {        //HACIA ATRAS, RUEDA DERECHA E IZQUIERDA AVANZAN HACIA ATRAS
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 255);       
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 0);
    //delay(5);      
  }  

void turnLeft() {     //GIRA A LA DERECHA, RUEDA DERECHA AVANZA ADELANTE E IZQUIERDA AVANZAN HACIA ATRAS
   
    analogWrite(motorPin1, 0);     
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 255);   
    //delay(5);
  } 
 
void turnRight() {           //GIRA A LA IZQUIERDA, RUEDA DERECHA AVANZA ATRAS E IZQUIERDA AVANZAN HACIA ADELANTE
    
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);   
    analogWrite(motorPin3, 255);    
    analogWrite(motorPin4, 0);     
    //delay(5);
    }  

int lookLeft() {
    servo1.write(180);    
   delay(350);
   DISTANCIAL = medirDistancia();
   delay(100);
   servo1.write(85);        
    return DISTANCIAL;
}

int lookRight(){
   servo1.write(0); 
   delay(350);
   DISTANCIAR = medirDistancia();
   delay(100);
   servo1.write(85); 
   return DISTANCIAR;
   }

int ataque(){
     moveForward2();
        delay(400);
        moveStop();
        delay(50);
        turnLeft();
        delay(150);
}
