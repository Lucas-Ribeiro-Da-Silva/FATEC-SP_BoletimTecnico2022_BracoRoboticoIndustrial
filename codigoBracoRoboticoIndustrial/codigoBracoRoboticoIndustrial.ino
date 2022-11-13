#include <Servo.h> //inclui biblioteca de reconheicmento de servos motores
Servo servo1; // Cria um objeto servo 1
Servo servo2; // Cria um objeto servo 2
Servo servo3; // Cria um objeto servo 3
Servo servo4; // Cria um objeto servo 4

int trig = 10; //define uma variavel inteira para o led1,o pino trig envia uma onda sonora 
int echo = 9; //define uma variavel inteira para o led1,o pino echo recebe uma onda sonora
int led1 = 8; //define uma variavel inteira para o led1
int led2 = 7; //define uma variavel inteira para o led2
int piezo = 6; //define uma variavel inteira para o piezo


float distancia; // distancia fica em float porque assim o monitor serial mostrada valores decimais e não apenas inteiros
float cm; //define a variavel cm 

void setup()
{

pinMode(11, INPUT); //define o pino 3 como entrada
  
servo1.attach(5); // Anexa o servo no pino 7
servo1.write(0);  // Define posição inicial
servo2.attach(4); // Anexa o servo no pino 6
servo2.write(0);  // Define posição inicial
servo3.attach(3); // Anexa o servo no pino 5
servo3.write(0);  // Define posição inicial
servo4.attach(2); // Anexa o servo no pino 4
servo4.write(0);  // Define posição inicial
Serial.begin(9600);//inicia o monitor serial  
  
  
pinMode(trig, OUTPUT); // trig é definido como saída porque ele recebe a onda sonora
pinMode(echo, INPUT); // echo é definido como entrada porque ele envia a onda sonora
pinMode(piezo, OUTPUT); //Define o piezo como saída 
pinMode(led1, OUTPUT); //Define o led1 como saída
pinMode(led2, OUTPUT); //Define o led2 como saída 

}

void loop()
{
  cm = distancia; // distancia em centímetros
  int valor = digitalRead(11); //váriavel inteira denominada "valor" (faz a leitura da posição da chave)
  
  if(valor == 1 && cm > 50)//define uma condição analisando a chave e define uma condição para distancia
  {
noTone(piezo); //Mantem o piezo sem tocar
digitalWrite(led1, LOW); //Desliga o led1
digitalWrite(led2, HIGH); //Liga o led2
  { 
int angulo1 = analogRead(3); // Lê o valor do potenciômetro
angulo1=map(angulo1, 0, 1023, 0, 180); // Mapeia os valores de 0 a 180 graus
servo1.write(angulo1); // Escreve o ângulo para o servo movimentar
Serial.print("anguloServo1:"); //título no monitor serial
Serial.println(angulo1); //informação impressa no monitor serial
delay(5); // Espera de 15ms, para permitir que o servo atinja a posição
}
{
int angulo2 = analogRead(2); // Lê o valor do potenciômetro
angulo2=map(angulo2, 0, 1023, 0, 180); // Mapeia os valores de 0 a 180 graus
servo2.write(angulo2); // Escreve o ângulo para o servo movimentar
Serial.print("anguloServo2:"); //título no monitor serial
Serial.println(angulo2); //informação impressa no monitor serial
delay(5); // Espera de 15ms, para permitir que o servo atinja a posição
}
{
int angulo3 = analogRead(1); // Lê o valor do potenciômetro
angulo3=map(angulo3, 0, 1023, 0, 180); // Mapeia os valores de 0 a 180 graus
servo3.write(angulo3); // Escreve o ângulo para o servo movimentar
Serial.print("anguloServo3:"); //título no monitor serial
Serial.println(angulo3); //informação impressa no monitor serial
delay(5); // Espera de 15ms, para permitir que o servo atinja a posição
}
{
int angulo4 = analogRead(0); // Lê o valor do potenciômetro
angulo4=map(angulo4, 0, 1023, 0, 180); // Mapeia os valores de 0 a 180 graus
servo4.write(angulo4); // Escreve o ângulo para o servo movimentar
Serial.print("anguloServo4:"); //título no monitor serial
Serial.println(angulo4); //informação impressa no monitor serial
delay(5); // Espera de 15ms, para permitir que o servo atinja a posição
}
  }
 else if(valor == 0 && cm > 50)//define uma condição analisando a chave e define uma condição para distancia
  {
    noTone(piezo); //Mantem o piezo sem tocar
    digitalWrite(led1, LOW); //Desliga o led1
    digitalWrite(led2, HIGH); //Liga o led2
   { 
 servo1.write(90); //gira o motor para a posição desejada
 delay(1000); //tempo de espera entre movimentos
 servo2.write(90);  //gira o motor para a posição desejada
 delay(1000);  //tempo de espera entre movimentos
 servo3.write(90);  //gira o motor para a posição desejada
 delay(1000);//tempo de espera entre movimentos
 servo4.write(90);  //gira o motor para a posição desejada
 delay(1000);  //tempo de espera entre movimentos
 servo1.write(0);  //gira o motor para a posição desejada
 delay(1000);  //tempo de espera entre movimentos
 servo2.write(0);  //gira o motor para a posição desejada
 delay(1000);//tempo de espera entre movimentos
 servo3.write(0);  //gira o motor para a posição desejada
 delay(1000);//tempo de espera entre movimentos
 servo4.write(0);  //gira o motor para a posição desejada
 delay(1000);  //tempo de espera entre movimentos
   }
 }
  
  else if (cm < 50) 
  { 
  digitalWrite(led1, HIGH); //Liga o led1
  tone (piezo,2000,1000); //faz o piezo fazer barulho
  digitalWrite(led2, LOW); //Mantem o led2 desligado
  }
 
  digitalWrite(trig, LOW); //Desliga o pino do trig
  delay(5); //tempo de espera  
  digitalWrite(trig, HIGH); //Liga o pino do trig
  delay(10); //tempo de espera 
  digitalWrite(trig, LOW); //Desliga o pino do trig

  distancia = pulseIn(echo, HIGH); //Define o estado do início da medição

  distancia = distancia/58; //Divide o pulso da distancia por 58 

}
