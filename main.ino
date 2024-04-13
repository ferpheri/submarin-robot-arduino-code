#include <Servo.h>
#include <MPU6050_light.h>
#include "Wire.h"
#include "MS5837.h"
float dc = 0;
MS5837 sensor;
#define ONE_WIRE_BUS 9
#include <DallasTemperature.h>
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
UART Seriall(8, 9); // for GPS // change the rx and tx pin in raspberry pico to 8 and 9
UART Serialll(12, 13); //for Comunication
byte servoPin2 = 3;
byte servoPin3 = 7;
byte servoPin4 = 11;
byte servoPin5 = 15;
byte servoPin6 = 20;
byte servoPin7 = 26; // اگردرست نشد عدد پین Servo6 و Servo7 رو عوض کن
Servo servo2;  //right motor
Servo servo3;  //left motor
Servo servo4;  //front right motor
Servo servo5;  //front left motor
Servo servo6;  //back right motor
Servo servo7;  //back left motor
float tacx = 0, tacy = 0, tacz = 0;
MPU6050 mpu(Wire);
const int numLocations = 20;
long lats[numLocations];
long longs[numLocations];
long latInput = 0;
long lonInput = 0;
float kga = 10;
int err = 0;
int err2 = 0;
float l = 0;
float kgl = 9.5;
int ind = 0;
int kh = 0;
float az1 = 0;
long latt[10];
long lonn[10];
long tempLat = 0 ;
long tempLon = 0;
long myLat = 0;
long myLon = 0;
double disLat = 0;
double disLon = 0;
double firstLatAvg = 0;
double firstLonAvg = 0;
double secondLatAvg = 0;
double secondLonAvg = 0;
long latSum = 0;
long lonSum = 0;
float r = 1;
float r2 = 5;
long setPointLat = 1;
long setPointLon = 1;
float latj = 0;
float lonj = 0;
float latjj = 0;
float lonjj = 0;
float theta = 0;
float gama = 0;
float fi = 0;
float zavie = 0;
int desIndex = 0;
int saveIndex = 0;
int desArrSize = 1;
int a = 0;
unsigned long goUntill;
unsigned long runUntill;
int runCodeUntill = 300000;
int gpsGoingForward = 5000;
long timer = 0;
float acx = 0;
float acy = 0;
float acz = 0;
float ax = 0;
float ay = 0;
float az = 0;
float gax = 0.02;
float gay = 0.02;
float gaz = 0.03;
float kr = 8.8;
float kp = 8.8;
float ky = 8.8;
//float k1 = 5.5;
float zan = 0.00;
float yan = 0.00;
float xan = 0.00;
int xsp = 1500;
int ysp = 1500;
int zsp = 1500;
bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 1;
bool flag5 = 1;
bool flag6 = 0;
bool flag7 = 1;
bool flag8 = 1; //for enable roll
bool flag9 = 1; //for enable pitch
bool flag10 = 1; //for enable yaw
bool flag11 = 1; //for enable turning right or left when the yaw is disable
bool flag12 = 1; //for enable rolling right or left when the roll is disable
bool flag13 = 1; //for enable pitching right or left when the pitch is disable
bool flag14 = 1; //for enable or disable gps
bool flag15 = 0; //for enable or pressure sensor
int t = 0;
int leftMotorSpeed = 1500;
int rightMotorSpeed = 1500;
int frontLeftMotorSpeed = 1500;
int backLeftMotorSpeed = 1500;
int frontRightMotorSpeed = 1500;
int backRightMotorSpeed = 1500;
int lMotor = 1500;
int rMotor = 1500;
int flMotor = 1500;
int blMotor = 1500;
int frMotor = 1500;
int brMotor = 1500;
float yawDegree = 5;
float pitchDegree = 5;
float rollDegree = 5;
int fwMoChVal = 30;
int uwMoChVal = 30;
int pressureSensorChVal = 10;
int fwMoMaxVal = 1900;
int uwMoMaxVal = 1900;
int fwMoMaxReVal = 1100;
int uwMoMaxReVal = 1100;
int gpsFwMoVal = 1700;
int gpsFwMoChVal = 300;
char exitInput = ' ';
char moodInput = ' ';
char kInput = ' ';
char angleInput = ' ';
char uwMotorInput = ' ';
char fwMotorInput = ' ';
char degreeInput = ' ';
int MVInput = 0;
float AVInput = 0.0;
char input = ' ';
bool printed = false;
float depthInput = 0.00;
float depth = 0.00;
float sensorDepth = 0.00;
float depthK = 6;
float depthError = 0.00;
float  sensorDepth2 = 0.00;
float da = 0.00;
byte status = 0;
char b;
const unsigned char UBX_HEADER[] = { 0xB5, 0x62 };
struct NAV_POSLLH {
  unsigned char cls;
  unsigned char id;
  unsigned short len;
  unsigned long iTOW;
  long lon;
  long lat;
  long height;
  long hMSL;
  unsigned long hAcc;
  unsigned long vAcc;
};
NAV_POSLLH posllh;
void calcChecksum(unsigned char* CK) {
  memset(CK, 0, 2);
  for (int i = 0; i < (int)sizeof(NAV_POSLLH); i++) {
    CK[0] += ((unsigned char*)(&posllh))[i];
    CK[1] += CK[0];
  }
}
float dis(float lt1 , float lt2, float ln1, float ln2) {
  return 6378137 * sqrt(1 - 0.00669437999014 * pow(sin(lt1 * 0.000000001745329252), 2) ) * acos(sin(lt1 * 0.000000001745329252) * sin(lt2 * 0.000000001745329252) + cos(lt1 * 0.000000001745329252) * cos(lt2 * 0.000000001745329252) * cos((ln2 - ln1) * 0.000000001745329252));
}
float degree(double degr) {
  return (degr * 22) / (7 * 180);
}
void setup() {
  //    sensors.begin();
  Serialll.begin(9600);
  Seriall.begin(115200);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  servo6.attach(servoPin6);
  servo7.attach(servoPin7);

  servo2.writeMicroseconds(rightMotorSpeed);
  servo3.writeMicroseconds(leftMotorSpeed);
  servo4.writeMicroseconds(frontRightMotorSpeed);
  servo5.writeMicroseconds(frontLeftMotorSpeed);
  servo6.writeMicroseconds(backRightMotorSpeed);
  servo7.writeMicroseconds(backLeftMotorSpeed);

  Wire.begin();
  //  while (!sensor.init()) {
  //    Serialll.println("Init failed!");
  //    Serialll.println("Are SDA/SCL connected correctly?");
  //    Serialll.println("Blue Robotics Bar30: White=SDA, Green=SCL");
  //    Serialll.println("\n\n\n");
  //    delay(5000);
  //  }
  //  sensor.setModel(MS5837::MS5837_30BA);
  //  sensor.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
  status = mpu.begin();
  Serialll.print(F("mpu status: "));
  Serialll.println(status);
  //  while (status != 0) {}  // stop everything if could not connect to mpu
  Serialll.println(F("Calculating offsets, do not move mpu"));

  mpu.calcOffsets(true, true);  // gyro and accelero
  Serialll.println("Done!\n");
  Serialll.println("Press any key to start the robot:");
  runUntill = millis() + runCodeUntill;
}

void loop() {
//  if (millis() < runUntill) {
    mpu.update();
    //========================================================================================
    if (Serialll.available() > 0) {
      if (!printed) {
        Serialll.println();
        Serialll.println("Please Select Your Mood:");
        Serialll.println("1 => Manual Control");
        Serialll.println("2 => Automatic Control");
        Serialll.println("3 => Automatic Balance");
        Serialll.println("4 => Manual Control with Automatic Balance");
        Serialll.println("5 => Setting");
        printed = true;
      }
      moodInput = Serialll.read();
      Serialll.read();
      //===================================manual control=====================================
      if (moodInput == '1') {
        runUntill = millis() + runCodeUntill;
        Serialll.println();
        Serialll.println("Manual Control Selected");
        Serialll.println("You Can Exit The Mood By Pressing 'p' Button");
        delay(500);
        input = ' ';
        manualControl();
      }
      //=========================Manual Control with Automatic Balance========================
      if (moodInput == '4') {
        runUntill = millis() + runCodeUntill;
        acx = (mpu.getAccX());
        acy = (mpu.getAccY());
        acz = (mpu.getAccZ());
        if (abs(acx - tacx) > gax || abs(acy - tacy) > gay || abs(acz - tacz) > gaz) {
          ax = (mpu.getAngleX());
          ay = (mpu.getAngleY());
          az = (mpu.getAngleZ());
          if (az > 0) {
            kh = az / 360;
            az1 = az - (360 * kh);
          }
          if (az < 0) {
            kh = az / 360;
            az1 = az - (360 * kh);
          }
          tacx = acx;
          tacy = acy;
          tacz = acz;
        }
        if (flag2 == 0) {
          zan = az1;
          yan = mpu.getAngleY();
          xan = mpu.getAngleX();
        }
        flag2 = 1;
        az1 = 0;
        dc = 0;
        if (flag15 == 1) {
          sensor.read();
          while (dc - sensor.depth() != 0) {
            sensor.read();
            dc = sensor.depth();
            sensor.read();
          }
        }
        Serialll.println();
        Serialll.println("Manual Control with Automatic Balance Selected");
        Serialll.println("You Can Exit The Mood By Pressing 'p' Button");
        delay(500);
        input = ' ';
        manualControlWithAutomaticBalance();
      }
      //==================================Automatic Balance====================================
      if (moodInput == '3') {
        acx = (mpu.getAccX());
        acy = (mpu.getAccY());
        acz = (mpu.getAccZ());
        if (abs(acx - tacx) > gax || abs(acy - tacy) > gay || abs(acz - tacz) > gaz) {
          ax = (mpu.getAngleX());
          ay = (mpu.getAngleY());
          az = (mpu.getAngleZ());
          if (az > 0) {
            kh = az / 360;
            az1 = az - (360 * kh);
          }
          if (az < 0) {
            kh = az / 360;
            az1 = az - (360 * kh);
          }
          tacx = acx;
          tacy = acy;
          tacz = acz;
        }
        if (flag1 == 0) {
          zan = az1;
          yan = mpu.getAngleY();
          xan = mpu.getAngleX();
        }
        flag1 = 1;
        az1 = 0;
        Serialll.println();
        Serialll.println("Automatic Balance Selected");
        Serialll.println("You Can Exit The Mood By Pressing 'p' Button");
        delay(500);
        exitInput = ' ';
        automaticBalance();
      }
      //==================================Automatic Control====================================
      if (moodInput == '2') {
        flag14 = 1;
        runUntill = millis() + runCodeUntill;
        Serialll.println();
        Serialll.println("Automatic Control Selected");
        Serialll.println("You Can Exit The Mood By Pressing 'p' Button");
        dc = 0;
        if (flag15 == 1) {
          sensor.read();
          while (dc - sensor.depth() != 0) {
            sensor.read();
            dc = sensor.depth();
            sensor.read();
            if (!printed) {
              Serialll.println("Please Wait to Set the Depth");
              printed = true;
            }
          }
          Serialll.println("DONE");
          delay(1000);
          Serialll.print(".");
          delay(1000);
          Serialll.print(".");
          delay(1000);
          Serialll.println(".");
          delay(1000);
        }
        delay(500);
        exitInput = ' ';
        desIndex = 0;
        autoControl();
      }
      //========================================Options========================================
      if (moodInput == '5') {
        Serialll.println();
        Serialll.println("Setting Selected");
        Serialll.println("You Can Exit The Mood By Pressing 'p' Button");
        input = ' ';
        setting();
      }
    }
//  }
//  else {
//    lMotor = 1500;
//    rMotor = 1500;
//    frMotor = 1500;
//    brMotor = 1500;
//    flMotor = 1500;
//    blMotor = 1500;
//    servo4.writeMicroseconds(frMotor);
//    servo5.writeMicroseconds(flMotor);
//    servo6.writeMicroseconds(brMotor);
//    servo7.writeMicroseconds(blMotor);
//    servo3.writeMicroseconds(lMotor);
//    servo2.writeMicroseconds(rMotor);
//  }
}
