void manualControlWithAutomaticBalance() {
  while (1) {
    if (millis() < runUntill) {
      mpu.update();
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
      xsp = abs(xan - ax) * kr;
      ysp = abs(yan - ay) * kp;
      zsp = abs(zan - az1) * ky;
      input = Serialll.read();
      //========================== saving location ===========================
      if (input == 'm' || input == 'M') {
        runUntill = millis() + runCodeUntill;
        if ( processGPS() ) {
          getAvg();
          getDis();
          lats[saveIndex] = disLat;
          longs[saveIndex] = disLon;
          saveIndex++;
          if (saveIndex > numLocations) {
            saveIndex = 0;
          }
          Serialll.println("location saved");
          for (int i = 0 ; i < saveIndex ; i++) {
            Serialll.print(lats[i]);
            Serialll.print(',');
            Serialll.println(longs[i]);
          }
        }
      }
      //========================== going upside with pressing '8' ===========================
      if (input == '8') {
        runUntill = millis() + runCodeUntill;
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1;
        }
        flag2 = 1;
        flag4 = 1;
        flag5 = 1;
        flag3 = 0;
        if (flag15 == 1) {
          depth = (sensor.depth() - dc) * 100 - pressureSensorChVal;
          getDepth();
        } else {
          frontLeftMotorSpeed += uwMoChVal;
          frontRightMotorSpeed += uwMoChVal;
          backLeftMotorSpeed += uwMoChVal;
          backRightMotorSpeed += uwMoChVal;
          if (frontRightMotorSpeed >= uwMoMaxVal ) {
            frontRightMotorSpeed = uwMoMaxVal;
          }
          if (frontLeftMotorSpeed >= uwMoMaxVal ) {
            frontLeftMotorSpeed = uwMoMaxVal;
          }
          if ( backLeftMotorSpeed >= uwMoMaxVal) {
            backLeftMotorSpeed = uwMoMaxVal;
          }
          if ( backRightMotorSpeed >= uwMoMaxVal) {
            backRightMotorSpeed = uwMoMaxVal;
          }
        }
        Serialll.println("going upside");
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //=========================going downside with pressing '2'===========================
      if (input == '2') {
        runUntill = millis() + runCodeUntill;
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1;
        }
        flag2 = 1;
        flag4 = 1;
        flag5 = 1;
        flag3 = 0;
        if (flag15 == 1) {
          depth = (sensor.depth() - dc) * 100 + pressureSensorChVal;
          getDepth();
        } else {
          frontLeftMotorSpeed -= uwMoChVal;
          frontRightMotorSpeed -= uwMoChVal;
          backLeftMotorSpeed -= uwMoChVal;
          backRightMotorSpeed -= uwMoChVal;
          if (frontRightMotorSpeed <= uwMoMaxReVal ) {
            frontRightMotorSpeed = uwMoMaxReVal;
          }
          if (frontLeftMotorSpeed <= uwMoMaxReVal ) {
            frontLeftMotorSpeed = uwMoMaxReVal;
          }
          if ( backLeftMotorSpeed <= uwMoMaxReVal) {
            backLeftMotorSpeed = uwMoMaxReVal;
          }
          if ( backRightMotorSpeed <= uwMoMaxReVal) {
            backRightMotorSpeed = uwMoMaxReVal;
          }
        }
        Serialll.println("going downside");
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //===================================================================================
      if (input == '6') {
        runUntill = millis() + runCodeUntill;
        if (flag9 == 0) {
          flag13 = 1;
        } else {
          flag13 = 0;
        }
        if (flag13 == 1) {
          frontRightMotorSpeed += uwMoChVal;
          frontLeftMotorSpeed += uwMoChVal;
          backRightMotorSpeed -= uwMoChVal;
          backLeftMotorSpeed -= uwMoChVal;
          if (frontRightMotorSpeed >= uwMoMaxVal) {
            frontRightMotorSpeed = uwMoMaxVal;
          }
          if (frontLeftMotorSpeed >= uwMoMaxVal) {
            frontLeftMotorSpeed = uwMoMaxVal;
          }
          if (backRightMotorSpeed <= uwMoMaxReVal) {
            backRightMotorSpeed = uwMoMaxReVal;
          }
          if (backLeftMotorSpeed <= uwMoMaxReVal) {
            backLeftMotorSpeed = uwMoMaxReVal;
          }
          servo4.writeMicroseconds(frontRightMotorSpeed);
          servo5.writeMicroseconds(frontLeftMotorSpeed);
          servo6.writeMicroseconds(backRightMotorSpeed);
          servo7.writeMicroseconds(backLeftMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          yan = mpu.getAngleY() - pitchDegree;
        }
        flag2 = 1;
        flag5 = 0;
        flag4 = 1;
        flag3 = 1;
        Serialll.println("head up");
      }
      //====================================================================================
      if (input == '4') {
        runUntill = millis() + runCodeUntill;
        if (flag9 == 0) {
          flag13 = 1;
        } else {
          flag13 = 0;
        }
        if (flag13 == 1) {
          frontRightMotorSpeed -= uwMoChVal;
          frontLeftMotorSpeed -= uwMoChVal;
          backRightMotorSpeed += uwMoChVal;
          backLeftMotorSpeed += uwMoChVal;
          if (backRightMotorSpeed >= uwMoMaxVal) {
            backRightMotorSpeed = uwMoMaxVal;
          }
          if (backLeftMotorSpeed >= uwMoMaxVal) {
            backLeftMotorSpeed = uwMoMaxVal;
          }
          if (frontRightMotorSpeed <= uwMoMaxReVal) {
            frontRightMotorSpeed = uwMoMaxReVal;
          }
          if (frontLeftMotorSpeed <= uwMoMaxReVal) {
            frontLeftMotorSpeed = uwMoMaxReVal;
          }
          servo4.writeMicroseconds(frontRightMotorSpeed);
          servo5.writeMicroseconds(frontLeftMotorSpeed);
          servo6.writeMicroseconds(backRightMotorSpeed);
          servo7.writeMicroseconds(backLeftMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          yan = mpu.getAngleY() + pitchDegree;
        }
        flag2 = 1;
        flag4 = 0;
        flag5 = 1;
        flag3 = 1;
        Serialll.println("head down");
      }
      //====================================================================================
      if (input == '9') {
        runUntill = millis() + runCodeUntill;
        if (flag8 == 0) {
          flag12 = 1;
        } else {
          flag12 = 0;
        }
        if (flag12 == 1) {
          frontRightMotorSpeed -= uwMoChVal;
          frontLeftMotorSpeed += uwMoChVal;
          backRightMotorSpeed -= uwMoChVal;
          backLeftMotorSpeed += uwMoChVal;
          if (backRightMotorSpeed <= uwMoMaxReVal) {
            backRightMotorSpeed = uwMoMaxReVal;
          }
          if (backLeftMotorSpeed >= uwMoMaxVal) {
            backLeftMotorSpeed = uwMoMaxVal;
          }
          if (frontRightMotorSpeed <= uwMoMaxReVal) {
            frontRightMotorSpeed = uwMoMaxReVal;
          }
          if (frontLeftMotorSpeed >= uwMoMaxVal) {
            frontLeftMotorSpeed = uwMoMaxVal;
          }
          servo4.writeMicroseconds(frontRightMotorSpeed);
          servo5.writeMicroseconds(frontLeftMotorSpeed);
          servo6.writeMicroseconds(backRightMotorSpeed);
          servo7.writeMicroseconds(backLeftMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          xan = mpu.getAngleX() + rollDegree;
        }
        Serialll.println("roll right");
        flag2 = 1;
        flag4 = 0;
        flag5 = 1;
        flag3 = 1;
      }
      //====================================================================================
      if (input == '7') {
        runUntill = millis() + runCodeUntill;
        if (flag8 == 0) {
          flag12 = 1;
        } else {
          flag12 = 0;
        }
        if (flag12 == 1) {
          frontRightMotorSpeed += uwMoChVal;
          frontLeftMotorSpeed -= uwMoChVal;
          backRightMotorSpeed += uwMoChVal;
          backLeftMotorSpeed -= uwMoChVal;
          if (backRightMotorSpeed >= uwMoMaxVal) {
            backRightMotorSpeed = uwMoMaxVal;
          }
          if (backLeftMotorSpeed <= uwMoMaxReVal) {
            backLeftMotorSpeed = uwMoMaxReVal;
          }
          if (frontRightMotorSpeed >= uwMoMaxVal) {
            frontRightMotorSpeed = uwMoMaxVal;
          }
          if (frontLeftMotorSpeed <= uwMoMaxReVal) {
            frontLeftMotorSpeed = uwMoMaxReVal;
          }
          servo4.writeMicroseconds(frontRightMotorSpeed);
          servo5.writeMicroseconds(frontLeftMotorSpeed);
          servo6.writeMicroseconds(backRightMotorSpeed);
          servo7.writeMicroseconds(backLeftMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          xan = mpu.getAngleX() - rollDegree;
        }
        flag2 = 1;
        flag5 = 0;
        flag4 = 1;
        flag3 = 1;
        Serialll.println("roll left");
      }
      //======================== plus speed with pressing 'w' ==============================
      if (input == 'w' || input == 'W') {
        runUntill = millis() + runCodeUntill;
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1;
        }
        flag4 = 1;
        flag5 = 1;
        flag2 = 1;
        flag3 = 0;
        leftMotorSpeed += fwMoChVal;
        rightMotorSpeed += fwMoChVal;
        Serialll.println("plus speed");
        if (leftMotorSpeed >= fwMoMaxVal ) {
          leftMotorSpeed = fwMoMaxVal;
        }
        if ( rightMotorSpeed >= fwMoMaxVal) {
          rightMotorSpeed = fwMoMaxVal;
        }
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //================ minus speed and reverse with pressing 's' ================
      if (input == 's' || input == 'S') {
        runUntill = millis() + runCodeUntill;
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1;
        }
        flag4 = 1;
        flag5 = 1;
        flag2 = 1;
        flag3 = 0;
        // reverse the motor
        leftMotorSpeed -= fwMoChVal;
        rightMotorSpeed -= fwMoChVal;
        if (leftMotorSpeed <= fwMoMaxReVal ) {
          leftMotorSpeed = fwMoMaxReVal;
        }
        if ( rightMotorSpeed <= fwMoMaxReVal) {
          rightMotorSpeed = fwMoMaxReVal;
        }
        Serialll.println("minus speed");
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //==================================turn right=================================
      if (input == 'd' || input == 'D') {
        runUntill = millis() + runCodeUntill;
        if (flag10 == 0) {
          flag11 = 1;
        } else {
          flag11 = 0;
        }
        if (flag11 == 1) {
          leftMotorSpeed += fwMoChVal;
          rightMotorSpeed -= fwMoChVal;
          if (leftMotorSpeed >= fwMoMaxVal) {
            leftMotorSpeed = fwMoMaxVal;
          }
          if (rightMotorSpeed <= fwMoMaxReVal) {
            rightMotorSpeed = fwMoMaxReVal;
          }
          servo3.writeMicroseconds(leftMotorSpeed);
          servo2.writeMicroseconds(rightMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1 - yawDegree;
        }
        flag2 = 1;
        flag3 = 1;
        flag4 = 0;
        flag5 = 1;
        Serialll.println("turn right");
      }
      //==================================turn left==================================
      if (input == 'a' || input == 'A') {
        runUntill = millis() + runCodeUntill;
        if (flag10 == 0) {
          flag11 = 1;
        } else {
          flag11 = 0;
        }
        if (flag11 == 1) {
          leftMotorSpeed -= fwMoChVal;
          rightMotorSpeed += fwMoChVal;
          if (rightMotorSpeed >= fwMoMaxVal) {
            rightMotorSpeed = fwMoMaxVal;
          }
          if (leftMotorSpeed <= fwMoMaxReVal) {
            leftMotorSpeed = fwMoMaxReVal;
          }
          servo3.writeMicroseconds(leftMotorSpeed);
          servo2.writeMicroseconds(rightMotorSpeed);
        }
        flag2 = 0;
        if (flag2 == 0) {
          zan = az1 + yawDegree;
        }
        flag2 = 1;
        flag3 = 1;
        flag5 = 0;
        flag4 = 1;
        Serialll.println("turn left");
      }
      //=============================turning off the motor=============================
      if (input == 'f' || input == 'F') {
        runUntill = millis() + runCodeUntill;
        flag3 = 0;
        flag2 = 0;
        flag4 = 1;
        flag5 = 1;
        flag2 = 0;
        flag15 = 0;
        if (flag2 == 0) {
          zan = az1;
        }
        leftMotorSpeed = 1500;
        rightMotorSpeed = 1500;
        Serialll.println("turn off forward motors");
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      if (input == '5') {
        runUntill = millis() + runCodeUntill;
        flag3 = 0;
        flag2 = 0;
        flag4 = 1;
        flag5 = 1;
        flag2 = 0;
        flag15 = 0;
        if (flag2 == 0) {
          yan = mpu.getAngleY();
          xan = mpu.getAngleX();
        }
        frontRightMotorSpeed = 1500;
        frontLeftMotorSpeed = 1500;
        backRightMotorSpeed = 1500;
        backLeftMotorSpeed = 1500;
        Serialll.println("turn off upside motors");
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //    if (input == 't') {
      //      t = 0;
      //      flag2 = 0;
      //      sensors.requestTemperatures();
      //
      //      //print the temperature in Celsius
      //      Serialll.print("Temperature: ");
      //      Serialll.print(sensors.getTempCByIndex(0));
      //      Serialll.print((char)176);  //shows degrees character
      //      Serialll.print("C  |  ");
      //
      //      //print the temperature in Fahrenheit
      //      Serialll.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
      //      Serialll.print((char)176);  //shows degrees character
      //      Serialll.println("F");
      //    }
      if (flag3 == 0) {
        frMotor = frontRightMotorSpeed;
        brMotor = backRightMotorSpeed;
        flMotor = frontLeftMotorSpeed;
        blMotor = backLeftMotorSpeed;
        lMotor = leftMotorSpeed;
        rMotor = rightMotorSpeed;
        if (flag8 == 1) {
          if (xan - ax < -rollDegree) {
            if (abs(xan - ax) < 45) {
              frMotor += xsp;
              brMotor += xsp;
              flMotor -= xsp;
              blMotor -= xsp;
              if (frMotor >= uwMoMaxVal ) {
                frMotor = uwMoMaxVal;
              }
              if (brMotor >= uwMoMaxVal ) {
                brMotor = uwMoMaxVal;
              }
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor = uwMoMaxVal ;
              brMotor = uwMoMaxVal ;
              flMotor -= xsp;
              blMotor -= xsp;
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (xan - ax > rollDegree) {
            if (abs(xan - ax) < 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              flMotor += xsp;
              blMotor += xsp;
              if (flMotor >= uwMoMaxVal ) {
                flMotor = uwMoMaxVal;
              }
              if (blMotor >= uwMoMaxVal ) {
                blMotor = uwMoMaxVal;
              }
              if (frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if (brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              blMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              if ( frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if ( brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag9 == 1) {
          if (yan - ay < -pitchDegree) {
            if (abs(yan - ay) < 45) {
              frMotor += ysp;
              flMotor += ysp;
              brMotor -= ysp;
              blMotor -= ysp;
              if (frMotor >= uwMoMaxVal) {
                frMotor = uwMoMaxVal;
              }
              if (flMotor >= uwMoMaxVal) {
                flMotor = uwMoMaxVal;
              }
              if (brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              if (blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(yan - ay) > 45) {
              frMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              brMotor -= ysp;
              blMotor -= ysp;
              if (brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              if (blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (yan - ay > pitchDegree) {
            if (abs(yan - ay) < 45) {
              frMotor -= ysp;
              flMotor -= ysp;
              brMotor += ysp;
              blMotor += ysp;
              if (brMotor >= uwMoMaxVal) {
                brMotor = uwMoMaxVal;
              }
              if (blMotor >= uwMoMaxVal) {
                blMotor = uwMoMaxVal;
              }
              if (frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if (flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(yan - ay) > 45) {
              frMotor -= ysp;
              flMotor -= ysp;
              brMotor = uwMoMaxVal;
              blMotor = uwMoMaxVal;
              if (frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if (flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag10 == 1) {
          if (zan - az1 > yawDegree) {
            if (abs(zan - az1) < 45) {
              lMotor -= zsp;
              rMotor += zsp;
              if (rMotor >= fwMoMaxVal) {
                rMotor = fwMoMaxVal;
              }
              if (lMotor <= fwMoMaxReVal) {
                lMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
            if (abs(zan - az1) > 45) {
              rMotor = fwMoMaxVal;
              lMotor -= zsp;
              if (lMotor <= fwMoMaxReVal) {
                lMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
          if (zan - az1 < -yawDegree) {
            if (abs(zan - az1) < 45) {
              lMotor += zsp;
              rMotor -= zsp;
              if (lMotor >= fwMoMaxVal) {
                lMotor = fwMoMaxVal;
              }
              if (rMotor <= fwMoMaxReVal) {
                rMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
            if (abs(zan - az1) > 45) {
              rMotor -= zsp;
              lMotor = fwMoMaxVal;
              if (rMotor <= fwMoMaxReVal) {
                rMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
        }
        if (abs(xan - ax) <= rollDegree && abs(yan - ay) <= pitchDegree && abs(zan - az1) <= yawDegree) {
          frMotor = frontRightMotorSpeed;
          brMotor = backRightMotorSpeed;
          flMotor = frontLeftMotorSpeed;
          blMotor = backLeftMotorSpeed;
          lMotor = leftMotorSpeed;
          rMotor = rightMotorSpeed;
          servo4.writeMicroseconds(frMotor);
          servo5.writeMicroseconds(flMotor);
          servo6.writeMicroseconds(brMotor);
          servo7.writeMicroseconds(blMotor);
          servo3.writeMicroseconds(lMotor);
          servo2.writeMicroseconds(rMotor);
        }
      }
      if (flag4 == 0) {
        frMotor = frontRightMotorSpeed;
        brMotor = backRightMotorSpeed;
        flMotor = frontLeftMotorSpeed;
        blMotor = backLeftMotorSpeed;
        lMotor = leftMotorSpeed;
        rMotor = rightMotorSpeed;
        if (flag8 == 1) {
          if (xan - ax < -rollDegree / 2) {
            if (abs(xan - ax) < 45) {
              frMotor += xsp;
              brMotor += xsp;
              flMotor -= xsp;
              blMotor -= xsp;
              if (frMotor >= uwMoMaxVal ) {
                frMotor = uwMoMaxVal;
              }
              if (brMotor >= uwMoMaxVal ) {
                brMotor = uwMoMaxVal;
              }
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor = uwMoMaxVal ;
              brMotor = uwMoMaxVal ;
              flMotor -= xsp;
              blMotor -= xsp;
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (xan - ax > rollDegree / 2) {
            if (abs(xan - ax) < 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              flMotor += xsp;
              blMotor += xsp;
              if (flMotor >= uwMoMaxVal ) {
                flMotor = uwMoMaxVal;
              }
              if (blMotor >= uwMoMaxVal ) {
                blMotor = uwMoMaxVal;
              }
              if (frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if (brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              blMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              if ( frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if ( brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag9 == 1) {
          if (yan - ay > pitchDegree / 2) {
            frMotor -= ysp;
            flMotor -= ysp;
            brMotor += ysp;
            blMotor += ysp;
            if (brMotor >= uwMoMaxVal) {
              brMotor = uwMoMaxVal;
            }
            if (blMotor >= uwMoMaxVal) {
              blMotor = uwMoMaxVal;
            }
            if (frMotor <= uwMoMaxReVal) {
              frMotor = uwMoMaxReVal;
            }
            if (flMotor <= uwMoMaxReVal) {
              flMotor = uwMoMaxReVal;
            }
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            if (abs(yan - ay) > 45) {
              frMotor -= ysp;
              flMotor -= ysp;
              brMotor = uwMoMaxVal;
              blMotor = uwMoMaxVal;
              if ( frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (yan - ay < -pitchDegree / 2) {
            frMotor += ysp;
            flMotor += ysp;
            brMotor -= ysp;
            blMotor -= ysp;
            if (frMotor >= uwMoMaxVal) {
              frMotor = uwMoMaxVal;
            }
            if (flMotor >= uwMoMaxVal) {
              flMotor = uwMoMaxVal;
            }
            if (brMotor <= uwMoMaxReVal) {
              brMotor = uwMoMaxReVal;
            }
            if (blMotor <= uwMoMaxReVal) {
              blMotor = uwMoMaxReVal;
            }
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            if (abs(yan - ay) > 45) {
              frMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              brMotor -= ysp;
              blMotor -= ysp;
              if ( brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag10 == 1) {
          if (zan - az1 < -yawDegree / 2) {
            lMotor += zsp;
            rMotor -= zsp;
            if (lMotor >= fwMoMaxVal) {
              lMotor = fwMoMaxVal;
            }
            if (rMotor <= fwMoMaxReVal) {
              rMotor = fwMoMaxReVal;
            }
            servo3.writeMicroseconds(lMotor);
            servo2.writeMicroseconds(rMotor);
            if (abs(zan - az1) > 45) {
              lMotor = fwMoMaxVal;
              rMotor -= zsp;
              if ( rMotor <= fwMoMaxReVal) {
                rMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
          if (zan - az1 > yawDegree / 2) {
            lMotor -= zsp;
            rMotor += zsp;
            if (rMotor >= fwMoMaxVal) {
              rMotor = fwMoMaxVal;
            }
            if (lMotor <= fwMoMaxReVal) {
              lMotor = fwMoMaxReVal;
            }
            servo3.writeMicroseconds(lMotor);
            servo2.writeMicroseconds(rMotor);
            if (abs(zan - az1) > 45) {
              rMotor = fwMoMaxVal;
              lMotor -= zsp;
              if ( lMotor <= fwMoMaxReVal) {
                lMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
        }
      }
      if (flag5 == 0) {
        frMotor = frontRightMotorSpeed;
        brMotor = backRightMotorSpeed;
        flMotor = frontLeftMotorSpeed;
        blMotor = backLeftMotorSpeed;
        lMotor = leftMotorSpeed;
        rMotor = rightMotorSpeed;
        if (flag8 == 1) {
          if (xan - ax < -rollDegree / 2) {
            if (abs(xan - ax) < 45) {
              frMotor += xsp;
              brMotor += xsp;
              flMotor -= xsp;
              blMotor -= xsp;
              if (frMotor >= uwMoMaxVal ) {
                frMotor = uwMoMaxVal;
              }
              if (brMotor >= uwMoMaxVal ) {
                brMotor = uwMoMaxVal;
              }
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor = uwMoMaxVal ;
              brMotor = uwMoMaxVal ;
              flMotor -= xsp;
              blMotor -= xsp;
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (xan - ax > rollDegree / 2) {
            if (abs(xan - ax) < 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              flMotor += xsp;
              blMotor += xsp;
              if (flMotor >= uwMoMaxVal ) {
                flMotor = uwMoMaxVal;
              }
              if (blMotor >= uwMoMaxVal ) {
                blMotor = uwMoMaxVal;
              }
              if (frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if (brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
            if (abs(xan - ax) > 45) {
              frMotor -= xsp;
              brMotor -= xsp;
              blMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              if ( frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if ( brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag9 == 1) {
          if (yan - ay < -pitchDegree / 2 ) {
            frMotor += ysp;
            flMotor += ysp;
            brMotor -= ysp;
            blMotor -= ysp;
            if (frMotor >= uwMoMaxVal) {
              frMotor = uwMoMaxVal;
            }
            if (flMotor >= uwMoMaxVal) {
              flMotor = uwMoMaxVal;
            }
            if (brMotor <= uwMoMaxReVal) {
              brMotor = uwMoMaxReVal;
            }
            if (blMotor <= uwMoMaxReVal) {
              blMotor = uwMoMaxReVal;
            }
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            if (abs(yan - ay) > 45) {
              frMotor = uwMoMaxVal;
              flMotor = uwMoMaxVal;
              brMotor -= ysp ;
              blMotor -= ysp;
              if ( brMotor <= uwMoMaxReVal) {
                brMotor = uwMoMaxReVal;
              }
              if ( blMotor <= uwMoMaxReVal) {
                blMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
          if (yan - ay > pitchDegree / 2) {
            frMotor -= ysp;
            flMotor -= ysp;
            brMotor += ysp;
            blMotor += ysp;
            if (brMotor >= uwMoMaxVal) {
              brMotor = uwMoMaxVal;
            }
            if (blMotor >= uwMoMaxVal) {
              blMotor = uwMoMaxVal;
            }
            if (frMotor <= uwMoMaxReVal) {
              frMotor = uwMoMaxReVal;
            }
            if (flMotor <= uwMoMaxReVal) {
              flMotor = uwMoMaxReVal;
            }
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            if (abs(yan - ay) > 45) {
              frMotor -= ysp;
              flMotor -= ysp;
              brMotor = uwMoMaxVal ;
              blMotor = uwMoMaxVal;
              if ( frMotor <= uwMoMaxReVal) {
                frMotor = uwMoMaxReVal;
              }
              if ( flMotor <= uwMoMaxReVal) {
                flMotor = uwMoMaxReVal;
              }
              servo4.writeMicroseconds(frMotor);
              servo5.writeMicroseconds(flMotor);
              servo6.writeMicroseconds(brMotor);
              servo7.writeMicroseconds(blMotor);
            }
          }
        }
        if (flag10 == 1) {
          if (zan - az1 > yawDegree / 2 ) {
            lMotor -= zsp;
            rMotor += zsp;
            if (rMotor >= fwMoMaxVal) {
              rMotor = fwMoMaxVal;
            }
            if (lMotor <= fwMoMaxReVal) {
              lMotor = fwMoMaxReVal;
            }
            servo3.writeMicroseconds(lMotor);
            servo2.writeMicroseconds(rMotor);
            if (abs(zan - az1) > 45) {
              rMotor = fwMoMaxVal;
              lMotor -= zsp;
              if ( lMotor <= fwMoMaxReVal) {
                lMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
          if (zan - az1 < -yawDegree / 2) {
            lMotor += zsp;
            rMotor -= zsp;
            if (lMotor >= fwMoMaxVal) {
              lMotor = fwMoMaxVal;
            }
            if (rMotor <= fwMoMaxReVal) {
              rMotor = fwMoMaxReVal;
            }
            servo3.writeMicroseconds(lMotor);
            servo2.writeMicroseconds(rMotor);
            if (abs(zan - az1) > 45) {
              rMotor -= zsp;
              lMotor = fwMoMaxVal;
              if ( rMotor <= fwMoMaxReVal) {
                rMotor = fwMoMaxReVal;
              }
              servo3.writeMicroseconds(lMotor);
              servo2.writeMicroseconds(rMotor);
            }
          }
        }
      }

      //    Serialll.print(xan);
      //    Serialll.print('\t');
      //    Serialll.print(ax);
      //    Serialll.print('\t');
      //        Serialll.print(yan);
      //        Serialll.print('\t');
      //        Serialll.print(ay);
      //        Serialll.print('\t');
      //        Serialll.print(zan);
      //        Serialll.print('\t');
      //        Serialll.print(az1);
      //        Serialll.print('\t');
      //=================================================
      //    Serialll.print("Lm:");
      //    Serialll.print(leftMotorSpeed);
      //    Serialll.print('\t');
      //    Serialll.print("Rm:");
      //    Serialll.print(rightMotorSpeed);
      //    Serialll.print('\t');
      //    Serialll.print("BRm:");
      //    Serialll.print(backRightMotorSpeed);
      //    Serialll.print('\t');
      //    Serialll.print("BLm:");
      //    Serialll.print(backLeftMotorSpeed);
      //    Serialll.print('\t');
      //    Serialll.print("FRm:");
      //    Serialll.print(frontRightMotorSpeed);
      //    Serialll.print('\t');
      //    Serialll.print("FLm:");
      //    Serialll.print(frontLeftMotorSpeed);
      //    Serialll.print('\t');
      //=================================================
      Serialll.print("GLm:");
      Serialll.print(lMotor);
      Serialll.print('\t');
      Serialll.print("GRm:");
      Serialll.print(rMotor);
      Serialll.print('\t');
      Serialll.print("GFLm:");
      Serialll.print(flMotor);
      Serialll.print('\t');
      Serialll.print("GFRm:");
      Serialll.print(frMotor);
      Serialll.print('\t');
      Serialll.print("GBLm:");
      Serialll.print(blMotor);
      Serialll.print('\t');
      Serialll.print("GBRm:");
      Serialll.print(brMotor);
      Serialll.print("\t");
      //    Serialll.print(yan);
      //    Serialll.print("\t");
      //    Serialll.print(zan);
      //    Serialll.print("\t");
      //    Serialll.print(xan);
      //    Serialll.print("\t");
      Serialll.print(ay);
      Serialll.print("\t");
      Serialll.print(az1);
      Serialll.print("\t");
      Serialll.print(ax);
      Serialll.print("\t");
      Serialll.print("dc: ");
      Serialll.print(dc);
      Serialll.print("\t");
      Serialll.print("depth: ");
      Serialll.print(sensorDepth);
      Serialll.print("\t");
      Serialll.println(depth);

      if (input == 'p' || input == 'P') {
        leftMotorSpeed = 1500;
        rightMotorSpeed = 1500;
        frontRightMotorSpeed = 1500;
        frontLeftMotorSpeed = 1500;
        backRightMotorSpeed = 1500;
        backLeftMotorSpeed = 1500;
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
        flag2 = 0;
        flag15 = 1;
        printed = false;
        break;
      }
    } else {
      leftMotorSpeed = 1500;
      rightMotorSpeed = 1500;
      frontRightMotorSpeed = 1500;
      frontLeftMotorSpeed = 1500;
      backRightMotorSpeed = 1500;
      backLeftMotorSpeed = 1500;
      servo4.writeMicroseconds(frontRightMotorSpeed);
      servo5.writeMicroseconds(frontLeftMotorSpeed);
      servo6.writeMicroseconds(backRightMotorSpeed);
      servo7.writeMicroseconds(backLeftMotorSpeed);
      servo3.writeMicroseconds(leftMotorSpeed);
      servo2.writeMicroseconds(rightMotorSpeed);
      flag2 = 0;
      flag15 = 1;
      printed = false;
      break;
    }
  }
}
