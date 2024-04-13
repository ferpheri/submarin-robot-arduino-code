void getDepth() {
  sensor.read();
  sensorDepth = (sensor.depth() - dc) * 100;
  depthError = abs(sensorDepth) * depthK;
  if (sensorDepth < depth && sensorDepth2 - sensorDepth != 0) {
    if (abs(sensorDepth - depth) > 2) {
      lMotor = leftMotorSpeed;
      rMotor = rightMotorSpeed;
      frMotor = frontRightMotorSpeed;
      brMotor = backRightMotorSpeed;
      flMotor = frontLeftMotorSpeed;
      blMotor = backLeftMotorSpeed;
      flMotor -= depthError;
      frMotor -= depthError;
      blMotor -= depthError;
      brMotor -= depthError;
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
  }
  if (sensorDepth > -depth && sensorDepth2 - sensorDepth != 0) {
    if (abs(sensorDepth - depth) > 2) {
      lMotor = leftMotorSpeed;
      rMotor = rightMotorSpeed;
      frMotor = frontRightMotorSpeed;
      brMotor = backRightMotorSpeed;
      flMotor = frontLeftMotorSpeed;
      blMotor = backLeftMotorSpeed;
      flMotor += depthError;
      frMotor += depthError;
      blMotor += depthError;
      brMotor += depthError;
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
  }
  if (abs(sensorDepth - depth) <= 2) {
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
  sensorDepth2 = (sensor.depth() - dc) * 100;
  //  Serialll.print("L motor: ");
  //  Serialll.print(lMotor);
  //  Serialll.print("\t");
  //  Serialll.print("R motor: ");
  //  Serialll.print(rMotor);
  //  Serialll.print("\t");
  //  Serialll.print("BR motor:");
  //  Serialll.print(brMotor);
  //  Serialll.print("\t");
  //  Serialll.print("BL motor:");
  //  Serialll.print(blMotor);
  //  Serialll.print("\t");
  //  Serialll.print("FR motor:");
  //  Serialll.print(frMotor);
  //  Serialll.print("\t");
  //  Serialll.print("FL motor:");
  //  Serialll.print(flMotor);
  //  Serialll.print("\t");
  //  Serialll.print("dc: ");
  //  Serialll.print(dc);
  //  Serialll.print("\t");
  //  Serialll.print("err: ");
  //  Serialll.print(depthError);
  //  Serialll.print("\t");
  //  Serialll.print("depth: ");
  //  Serialll.print(sensorDepth);
  //  Serialll.print("\t");
  //  Serialll.println(depth);
}
