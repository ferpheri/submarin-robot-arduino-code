void automaticBalance() {
  while (1) {
    exitInput = Serialll.read();
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
    lMotor = leftMotorSpeed;
    rMotor = rightMotorSpeed;
    frMotor = frontRightMotorSpeed;
    brMotor = backRightMotorSpeed;
    flMotor = frontLeftMotorSpeed;
    blMotor = backLeftMotorSpeed;
    xsp = abs(xan - ax) * kr;
    ysp = abs(yan - ay) * kp;
    zsp = abs(zan - az1) * ky;
    //======================ROLL===============================
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
    }
    //======================PITCH===============================
    if (flag9 == 1) {
      if (yan - ay <= -pitchDegree) {
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
    }
    //==========================YAW===========================
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
    }
    //=======================ROLL==============================
    if (flag8 == 1) {
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
        if (abs(xan - mpu.getAngleX()) > 45) {
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
    //========================PITCH=============================
    if (flag9 == 1) {
      if (yan - ay >= pitchDegree) {
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
    //==========================YAW===========================
    if (flag10 == 1) {
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
    //========================MOTOR OFF=============================
    if (abs(xan - ax) <= rollDegree && abs(yan - ay) <= pitchDegree && abs(zan - az1) <= yawDegree) {
      lMotor = 1500;
      rMotor = 1500;
      frMotor = 1500;
      brMotor = 1500;
      flMotor = 1500;
      blMotor = 1500;
      servo4.writeMicroseconds(frMotor);
      servo5.writeMicroseconds(flMotor);
      servo6.writeMicroseconds(brMotor);
      servo7.writeMicroseconds(blMotor);
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
    }
    Serialll.print("GL motor: ");
    Serialll.print(lMotor);
    Serialll.print("\t");
    Serialll.print("GR motor: ");
    Serialll.print(rMotor);
    Serialll.print("\t");
    Serialll.print("GFL motor: ");
    Serialll.print(flMotor);
    Serialll.print("\t");
    Serialll.print("GFR motor: ");
    Serialll.print(frMotor);
    Serialll.print("\t");
    Serialll.print("GBL motor: ");
    Serialll.print(blMotor);
    Serialll.print("\t");
    Serialll.print("GBR motor: ");
    Serialll.print(brMotor);
    Serialll.print("\t");
    Serialll.print(yan);
    Serialll.print("\t");
    Serialll.print(zan);
    Serialll.print("\t");
    Serialll.print(xan);
    Serialll.print("\t");
    Serialll.print(ay);
    Serialll.print("\t");
    Serialll.print(az1);
    Serialll.print("\t");
    Serialll.println(ax);

    if (exitInput == 'p' || input == 'P') {
      flag1 = 0;
      lMotor = 1500;
      rMotor = 1500;
      frMotor = 1500;
      brMotor = 1500;
      flMotor = 1500;
      blMotor = 1500;
      servo4.writeMicroseconds(frMotor);
      servo5.writeMicroseconds(flMotor);
      servo6.writeMicroseconds(brMotor);
      servo7.writeMicroseconds(blMotor);
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
      printed = false;
      break;
    }
  }
}
