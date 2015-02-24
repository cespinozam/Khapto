//Hay que instalar las librerias I2Cdev.h y MPU6050.h
//estan en la carpeta librerias del github
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;
//sensbilidad del acelerometro
float sensitivityAccel= 16384.0; //viene en LBS/g. Este valor es para un rango de 2g
//float sensitivityGiro= 131.0; //viene en LBS/°/s. Este valor es para un rango de 250[°/s]
int fuerza;
//Sensor de fuerza conectado al Pin Analogo 0
int PinSensorFuerza=A0;
float x,y,z;
//Tiempo entre mediciones (milisegundos)
int periodo=50;


void setup() 
{
    Wire.begin();
    Serial.begin(9600);
    Serial.println("Initialize MPU");
    mpu.initialize();
    Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}

void loop() 
{
    //Se leen los valores del acelerometro para aceleracion y giro
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    //Se convierten los valores de la aceleración a g 
    x=ax/sensitivityAccel;
    z=az/sensitivityAccel;
    y=ay/sensitivityAccel;
    //lectura sensor de fuerza
    fuerza=analogRead(PinSensorFuerza);
    //Enviar valores
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.print(z);
    Serial.print(",");
    Serial.println(fuerza);
    delay(periodo);
}
