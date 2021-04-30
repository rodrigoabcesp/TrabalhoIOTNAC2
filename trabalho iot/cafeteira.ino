/*
 Este código faz o controle de posição de 6 servos motores 
 sem a utilização de biblioteca pronta

 O Servo motor faz o controle de posição atraves de pulso entre 1000 e 2000 milisegundos




 Obs: Por algum motivo, que ainda não descobri, 
      o controle de multiplos servo motores no simulide 
      não fica bom. Por essa razão, fazer o controle sem biblioteca
      usando o PWM.
 E
*/
#include <Ultrasonic.h>

HC_SR04 sensor1(9,10);
HC_SR04 sensor2(11,12);

int angle;
int pwm;


//declara os pinos do arduino que estão conectados nos servos motores
int servo1 = 3;
int servo2 = 5;
int dist1, dist2;


void setup() {
  Serial.begin(9600);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);

  servoPulse(servo1, 0);
  servoPulse(servo2, 0);

}

void loop() {

 dist1 = sensor1.distance();
 dist2 = sensor2.distance();

 servoPulse(servo1, dist1);
 servoPulse(servo2, dist2);

 delay(15);

 if(dist1 <= 150){
  servoPulse(servo1, 1023);
  delay(2500);
  servoPulse(servo1, 0);
  

 }

 if(dist2 >= 250){ // 250 cm é  altura para o cafe forte ja antes disso é cafe fraco
  servoPulse(servo2, 0); // o numero 90 serve para indicar o lado do cafe forte
  delay(700);
  servoPulse(servo2, 1023);
  delay(4000);
 }
 if(dist2 <=249){
  servoPulse(servo2, 1023);
  delay(700);
  servoPulse(servo2, 0);
  delay(4000);
  
 }

}

//Função que controla a posição do servo motor. 
void servoPulse (int servo, int angle)
{
  int pwm = {angle*11}; + 500;
  digitalWrite(servo, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(servo, LOW);
  delay(50);                  
}
