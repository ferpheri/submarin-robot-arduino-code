void autoControl() {
  while (1) {
    if (flag6 == 0) {
      Serialll.print("Please Enter the Number of Destination You Want to GO: ");
      while (!Serialll.available()) { }
      if (Serialll.available() > 0) {
        a = Serialll.parseInt();
        Serialll.read();
        if (a > 0) {
          runUntill = millis() + runCodeUntill;
          desArrSize = a;
        }
        else if (a == 0) {
          flag6 = 0;
          lMotor = 1500;
          rMotor = 1500;
          frMotor = 1500;
          flMotor = 1500;
          brMotor = 1500;
          blMotor = 1500;
          servo2.writeMicroseconds(rMotor);
          servo3.writeMicroseconds(lMotor);
          servo4.writeMicroseconds(frMotor);
          servo5.writeMicroseconds(flMotor);
          servo6.writeMicroseconds(brMotor);
          servo7.writeMicroseconds(blMotor);
          printed = false;
          break;
        }
        Serialll.println(desArrSize);
      }
      if (flag15 == 1) {
        Serialll.print("Please Enter the Depth You Want to GO:");
        while (!Serialll.available()) { }
        if (Serialll.available() > 0) {
          depthInput = Serialll.parseFloat();
          Serialll.read();
          if (depthInput > 0) {
            runUntill = millis() + runCodeUntill;
            depth = depthInput;
          }
          else if (depthInput == 0) {
            runUntill = millis() + runCodeUntill;
            flag6 = 0;
            lMotor = 1500;
            rMotor = 1500;
            frMotor = 1500;
            flMotor = 1500;
            brMotor = 1500;
            blMotor = 1500;
            servo2.writeMicroseconds(rMotor);
            servo3.writeMicroseconds(lMotor);
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            printed = false;
            break;
          }
          Serialll.println(depth);
        }
      }
      for (int i = saveIndex; i < desArrSize; i++) {
        Serialll.print("Enter latitude for location: ");
        Serialll.println(i + 1);
        while (!Serialll.available()) { }
        if (Serialll.available() > 0) {
          latInput = Serialll.parseInt();
          Serialll.read();
          if (latInput != 0) {
            runUntill = millis() + runCodeUntill;
            lats[i] = latInput;
          }
          else if (latInput == 0) {
            runUntill = millis() + runCodeUntill;
            flag6 = 0;
            lMotor = 1500;
            rMotor = 1500;
            frMotor = 1500;
            flMotor = 1500;
            brMotor = 1500;
            blMotor = 1500;
            servo2.writeMicroseconds(rMotor);
            servo3.writeMicroseconds(lMotor);
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            printed = false;
            break;
          }
        }
        Serialll.print("Enter longitude for location: ");
        Serialll.println(i + 1);
        while (!Serialll.available()) { }
        if (Serialll.available() > 0) {
          lonInput = Serialll.parseInt();
          Serialll.read();
          if (lonInput != 0) {
            runUntill = millis() + runCodeUntill;
            longs[i] = lonInput;
          }
          else if (lonInput == 0) {
            runUntill = millis() + runCodeUntill;
            flag6 = 0;
            lMotor = 1500;
            rMotor = 1500;
            frMotor = 1500;
            flMotor = 1500;
            brMotor = 1500;
            blMotor = 1500;
            servo2.writeMicroseconds(rMotor);
            servo3.writeMicroseconds(lMotor);
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
            printed = false;
            break;
          }
        }
      }
      // Print out the locations
      for (int i = 0; i < desArrSize; i++) {
        Serialll.print("Location ");
        Serialll.print(i + 1);
        Serialll.print(" - Lat: ");
        Serialll.print(lats[i]);
        Serialll.print(" Long: ");
        Serialll.println(longs[i]);
      }
      goUntill = millis() + gpsGoingForward;
      flag6 = 1;
    }
    exitInput = Serialll.read();
    if (exitInput == 'p' || input == 'P') {
      runUntill = millis() + runCodeUntill;
      flag6 = 0;
      frMotor = 1500;
      brMotor = 1500;
      flMotor = 1500;
      blMotor = 1500;
      lMotor = 1500;
      rMotor = 1500;
      servo4.writeMicroseconds(frMotor);
      servo5.writeMicroseconds(flMotor);
      servo6.writeMicroseconds(brMotor);
      servo7.writeMicroseconds(blMotor);
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
      printed = false;
      break;
    }
    if ( processGPS() ) {
      if (millis() < goUntill) {
        lMotor = gpsFwMoVal;
        rMotor = gpsFwMoVal;
        servo3.writeMicroseconds(lMotor);
        servo2.writeMicroseconds(rMotor);
      } else if (millis() < runUntill) {
        //==============================================================================
        input = Serialll.read();
        if (flag15 == 0) {
          if (input == '8') {
            runUntill = millis() + runCodeUntill;
            flMotor += uwMoChVal;
            frMotor += uwMoChVal;
            blMotor += uwMoChVal;
            brMotor += uwMoChVal;
            if (frMotor >= uwMoMaxVal ) {
              frMotor = uwMoMaxVal;
            }
            if (flMotor >= uwMoMaxVal ) {
              flMotor = uwMoMaxVal;
            }
            if ( blMotor >= uwMoMaxVal) {
              blMotor = uwMoMaxVal;
            }
            if ( brMotor >= uwMoMaxVal) {
              brMotor = uwMoMaxVal;
            }
            Serialll.println("going upside");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          //=========================going downside with pressing '2'===========================
          if (input == '2') {
            runUntill = millis() + runCodeUntill;
            flMotor -= uwMoChVal;
            frMotor -= uwMoChVal;
            blMotor -= uwMoChVal;
            brMotor -= uwMoChVal;
            if (frMotor <= uwMoMaxReVal ) {
              frMotor = uwMoMaxReVal;
            }
            if (flMotor <= uwMoMaxReVal ) {
              flMotor = uwMoMaxReVal;
            }
            if ( blMotor <= uwMoMaxReVal) {
              blMotor = uwMoMaxReVal;
            }
            if ( brMotor <= uwMoMaxReVal) {
              brMotor = uwMoMaxReVal;
            }
            Serialll.println("going downside");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          //===================================================================================
          if (input == '6') {
            runUntill = millis() + runCodeUntill;
            frMotor += uwMoChVal;
            flMotor += uwMoChVal;
            brMotor -= uwMoChVal;
            blMotor -= uwMoChVal;
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
            Serialll.println("head up");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          //====================================================================================
          if (input == '4') {
            runUntill = millis() + runCodeUntill;
            frMotor -= uwMoChVal;
            flMotor -= uwMoChVal;
            brMotor += uwMoChVal;
            blMotor += uwMoChVal;
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
            Serialll.println("head down");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          //====================================================================================
          if (input == '7') {
            runUntill = millis() + runCodeUntill;
            frMotor += uwMoChVal;
            flMotor -= uwMoChVal;
            brMotor += uwMoChVal;
            blMotor -= uwMoChVal;
            if (brMotor >= uwMoMaxVal) {
              brMotor = uwMoMaxVal;
            }
            if (blMotor <= uwMoMaxReVal) {
              blMotor = uwMoMaxReVal;
            }
            if (frMotor >= uwMoMaxVal) {
              frMotor = uwMoMaxVal;
            }
            if (flMotor <= uwMoMaxReVal) {
              flMotor = uwMoMaxReVal;
            }
            Serialll.println("roll right");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          //====================================================================================
          if (input == '9') {
            runUntill = millis() + runCodeUntill;
            frMotor -= uwMoChVal;
            flMotor += uwMoChVal;
            brMotor -= uwMoChVal;
            blMotor += uwMoChVal;
            if (brMotor <= uwMoMaxReVal) {
              brMotor = uwMoMaxReVal;
            }
            if (blMotor >= uwMoMaxVal) {
              blMotor = uwMoMaxVal;
            }
            if (frMotor <= uwMoMaxReVal) {
              frMotor = uwMoMaxReVal;
            }
            if (flMotor >= uwMoMaxVal) {
              flMotor = uwMoMaxVal;
            }
            Serialll.println("roll left");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
          if (input == '5') {
            runUntill = millis() + runCodeUntill;
            frMotor = 1500;
            flMotor = 1500;
            brMotor = 1500;
            blMotor = 1500;
            Serialll.println("turn off upside motors");
            servo4.writeMicroseconds(frMotor);
            servo5.writeMicroseconds(flMotor);
            servo6.writeMicroseconds(brMotor);
            servo7.writeMicroseconds(blMotor);
          }
        }
        if (input == 'p' || input == 'P') {
          runUntill = millis() + runCodeUntill;
          lMotor = 1500;
          rMotor = 1500;
          frMotor = 1500;
          flMotor = 1500;
          brMotor = 1500;
          blMotor = 1500;
          servo2.writeMicroseconds(rMotor);
          servo3.writeMicroseconds(lMotor);
          servo4.writeMicroseconds(frMotor);
          servo5.writeMicroseconds(flMotor);
          servo6.writeMicroseconds(brMotor);
          servo7.writeMicroseconds(blMotor);
          flag6 = 0;
          printed = false;
          break;
        }
        //==============================================================================
        if (flag14 == 1) {
          getAvg();
          getAngle();
          getDis();
        }
        if (flag15 == 1) {
          getDepth();
        }
        //        getDepth();
        if (desIndex == desArrSize) {
          flag14 = 0;
          flag6 = 0;
          lMotor = 1500;
          rMotor = 1500;
          frMotor = 1500;
          flMotor = 1500;
          brMotor = 1500;
          blMotor = 1500;
          servo2.writeMicroseconds(rMotor);
          servo3.writeMicroseconds(lMotor);
          servo4.writeMicroseconds(frMotor);
          servo5.writeMicroseconds(flMotor);
          servo6.writeMicroseconds(brMotor);
          servo7.writeMicroseconds(blMotor);
          Serialll.println("YOU ACHIVE YOUR LAST LOCATION");
          Serialll.println("HAVE A NICE DAY :)");
          break;
          if (flag15 == 1) {
            Serialll.println("Enter the Depth You Want to Go:");
            while (!Serialll.available()) { }
            if (Serialll.available() > 0) {
              depthInput = Serialll.parseFloat();
              Serialll.read();
              if (depthInput > 0) {
                depth = depthInput;
              }
              else if (depthInput == 0) {
                flag6 = 0;
                lMotor = 1500;
                rMotor = 1500;
                frMotor = 1500;
                flMotor = 1500;
                brMotor = 1500;
                blMotor = 1500;
                servo2.writeMicroseconds(rMotor);
                servo3.writeMicroseconds(lMotor);
                servo4.writeMicroseconds(frMotor);
                servo5.writeMicroseconds(flMotor);
                servo6.writeMicroseconds(brMotor);
                servo7.writeMicroseconds(blMotor);
                printed = false;
                break;
              }
              Serialll.println(depth);
            }
          }
        }
        if (sensorDepth == depth && flag14 == 0 && flag15 == 1) {
          lMotor = 1500;
          rMotor = 1500;
          frMotor = 1500;
          flMotor = 1500;
          brMotor = 1500;
          blMotor = 1500;
          servo2.writeMicroseconds(rMotor);
          servo3.writeMicroseconds(lMotor);
          servo4.writeMicroseconds(frMotor);
          servo5.writeMicroseconds(flMotor);
          servo6.writeMicroseconds(brMotor);
          servo7.writeMicroseconds(blMotor);
          Serialll.println("turn off upside motors");
          Serialll.println("You Achive the Depth You Want");
          Serialll.println("HAVE A NICE DAY :)");
          flag6 = 0;
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
        flag6 = 0;
        printed = false;
        break;
      }
      Serialll.print("L motor: ");
      Serialll.print(lMotor);
      Serialll.print("\t");
      Serialll.print("R motor: ");
      Serialll.print(rMotor);
      Serialll.print("\t");
      Serialll.print("BR motor:");
      Serialll.print(brMotor);
      Serialll.print("\t");
      Serialll.print("BL motor:");
      Serialll.print(blMotor);
      Serialll.print("\t");
      Serialll.print("FR motor:");
      Serialll.print(frMotor);
      Serialll.print("\t");
      Serialll.print("FL motor:");
      Serialll.print(flMotor);
      Serialll.print('\t');
      Serialll.print(l);
      Serialll.print('\t');
      Serialll.println(zavie);
    }
    //    else {
    //      getDepth();
    //      Serialll.print("L motor: ");
    //      Serialll.print(lMotor);
    //      Serialll.print("\t");
    //      Serialll.print("R motor: ");
    //      Serialll.print(rMotor);
    //      Serialll.print("\t");
    //      Serialll.print("BR motor:");
    //      Serialll.print(brMotor);
    //      Serialll.print("\t");
    //      Serialll.print("BL motor:");
    //      Serialll.print(blMotor);
    //      Serialll.print("\t");
    //      Serialll.print("FR motor:");
    //      Serialll.print(frMotor);
    //      Serialll.print("\t");
    //      Serialll.print("FL motor:");
    //      Serialll.print(flMotor);
    //      Serialll.print("\t");
    //      Serialll.print("dc: ");
    //      Serialll.print(dc);
    //      Serialll.print("\t");
    //      Serialll.print("depth: ");
    //      Serialll.print(sensorDepth);
    //      Serialll.print("\t");
    //      Serialll.println(depth);
    //    }
  }
}
