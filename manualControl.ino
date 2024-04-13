void manualControl() {
  while (1) {
    if (millis() < runUntill) {
      input = Serialll.read();
      //========================== saving location ===========================
      if (input == 'm' || input == 'M') {
        runUntill = millis() + runCodeUntill;
        if ( processGPS() ) {
          lats[saveIndex] = posllh.lat;
          longs[saveIndex] = posllh.lon;
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
      //======================================================================
      if(input == 'i' || input == 'I'){
        saveIndex = 0;
        Serialll.println("Array Reset");
        }
      //========================== going upside with pressing '8' ===========================
      if (input == '8') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("going upside");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //=========================going downside with pressing '2'===========================
      if (input == '2') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("going downside");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //===================================================================================
      if (input == '6') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("head up");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //====================================================================================
      if (input == '4') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("head down");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //====================================================================================
      if (input == '7') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("roll right");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }
      //====================================================================================
      if (input == '9') {
        runUntill = millis() + runCodeUntill;
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
        Serialll.println("roll left");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);

      }
      //======================== plus speed with pressing 'w' ==============================
      if (input == 'w' || input == 'W') {
        runUntill = millis() + runCodeUntill;
        leftMotorSpeed += fwMoChVal;
        rightMotorSpeed += fwMoChVal;

        if (leftMotorSpeed >= fwMoMaxVal ) {
          leftMotorSpeed = fwMoMaxVal;
        }
        if ( rightMotorSpeed >= fwMoMaxVal) {
          rightMotorSpeed = fwMoMaxVal;
        }
        Serialll.println("plus speed");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //================ minus speed and reverse with pressing 's' ================
      if (input == 's' || input == 'S') {
        runUntill = millis() + runCodeUntill;
        leftMotorSpeed -= fwMoChVal;
        rightMotorSpeed -= fwMoChVal;
        if (leftMotorSpeed <= fwMoMaxReVal ) {
          leftMotorSpeed = fwMoMaxReVal;
        }
        if ( rightMotorSpeed <= fwMoMaxReVal) {
          rightMotorSpeed = fwMoMaxReVal;
        }
        Serialll.println("minus speed");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //==================================turn right=================================
      if (input == 'd' || input == 'D') {
        runUntill = millis() + runCodeUntill;
        leftMotorSpeed += fwMoChVal;
        rightMotorSpeed -= fwMoChVal;
        if (leftMotorSpeed >= fwMoMaxVal) {
          leftMotorSpeed = fwMoMaxVal;
        }
        if (rightMotorSpeed <= fwMoMaxReVal) {
          rightMotorSpeed = fwMoMaxReVal;
        }
        Serialll.println("turn right");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //==================================turn left==================================
      if (input == 'a' || input == 'A') {
        runUntill = millis() + runCodeUntill;
        leftMotorSpeed -= fwMoChVal;
        rightMotorSpeed += fwMoChVal;
        if (rightMotorSpeed >= fwMoMaxVal) {
          rightMotorSpeed = fwMoMaxVal;
        }
        if (leftMotorSpeed <= fwMoMaxReVal) {
          leftMotorSpeed = fwMoMaxReVal;
        }
        Serialll.println("turn left");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      //=============================turning off the motor=============================
      if (input == 'f' || input == 'F') {
        runUntill = millis() + runCodeUntill;
        leftMotorSpeed = 1500;
        rightMotorSpeed = 1500;
        Serialll.println("turn off forward motors");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo3.writeMicroseconds(leftMotorSpeed);
        servo2.writeMicroseconds(rightMotorSpeed);
      }
      if (input == '5') {
        runUntill = millis() + runCodeUntill;
        frontRightMotorSpeed = 1500;
        frontLeftMotorSpeed = 1500;
        backRightMotorSpeed = 1500;
        backLeftMotorSpeed = 1500;
        Serialll.println("turn off upside motors");
        Serialll.print("L motor: ");
        Serialll.print(leftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("R motor: ");
        Serialll.print(rightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BR motor:");
        Serialll.print(backRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("BL motor:");
        Serialll.print(backLeftMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FR motor:");
        Serialll.print(frontRightMotorSpeed);
        Serialll.print("\t");
        Serialll.print("FL motor:");
        Serialll.println(frontLeftMotorSpeed);
        servo4.writeMicroseconds(frontRightMotorSpeed);
        servo5.writeMicroseconds(frontLeftMotorSpeed);
        servo6.writeMicroseconds(backRightMotorSpeed);
        servo7.writeMicroseconds(backLeftMotorSpeed);
      }

      //    if (input == 't') {
      //      t = 0;
      //      i = 0;
      //      sensors.requestTemperatures();
      //
      //      //print the temperature in Celsius
      //      Serialll.print("Temperature: ");
      //      Serialll.print(sensors.getTempCByIndex(0));
      //      Serialll.print((char)176);//shows degrees character
      //      Serialll.print("C  |  ");
      //
      //      //print the temperature in Fahrenheit
      //      Serialll.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
      //      Serialll.print((char)176);//shows degrees character
      //      Serialll.println("F");
      //    }

      //    Serialll.print("L motor: ");
      //    Serialll.print(leftMotorSpeed);
      //    Serialll.print("\t");
      //    Serialll.print("R motor: ");
      //    Serialll.print(rightMotorSpeed);
      //    Serialll.print("\t");
      //    Serialll.print("BR motor:");
      //    Serialll.print(backRightMotorSpeed);
      //    Serialll.print("\t");
      //    Serialll.print("BL motor:");
      //    Serialll.print(backLeftMotorSpeed);
      //    Serialll.print("\t");
      //    Serialll.print("FR motor:");
      //    Serialll.print(frontRightMotorSpeed);
      //    Serialll.print("\t");
      //    Serialll.print("FL motor:");
      //    Serialll.println(frontLeftMotorSpeed);
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
      printed = false;
      break;
    }
  }
}
