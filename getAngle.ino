void getAngle() {

  theta =  atan2((secondLonAvg - firstLonAvg) , (secondLatAvg - firstLatAvg)) * 180 / PI ;
  if (theta < 0) {
    theta = theta + 360;
  }
  setPointLat = lats[desIndex];
  setPointLon = longs[desIndex];
  //  setPointLat = 318346306;
  //  setPointLon = 543579004;
  gama = atan2((setPointLon - secondLonAvg) , (setPointLat - secondLatAvg)) * 180 / PI ;
  if (gama < 0) {
    gama = gama + 360;
  }
  zavie = gama - theta;
  if (zavie < 0) {
    zavie += 360;
  }

  if (zavie > yawDegree && zavie < 180) {
    if (zavie < 80) {
      err = zavie * kga;
      rMotor += err;
      lMotor += err;
      if (rMotor >= fwMoMaxVal - gpsFwMoChVal) {
        rMotor = fwMoMaxVal - gpsFwMoChVal;
      }
      if (lMotor >= fwMoMaxVal) {
        lMotor = fwMoMaxVal;
      }
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
    }
    if (zavie > 80) {
      rMotor += err;
      lMotor = fwMoMaxVal;
      if (rMotor >= fwMoMaxVal - gpsFwMoChVal) {
        rMotor = fwMoMaxVal - gpsFwMoChVal;
      }
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
    }
  }
  if (zavie > 180 && zavie < (360 - yawDegree)) {
    if (zavie > 280) {
      err =abs(360-zavie) * kga;
      lMotor += err;
      rMotor += err;
      if (lMotor >= fwMoMaxVal - gpsFwMoChVal) {
        lMotor = fwMoMaxVal - gpsFwMoChVal;
      }
      if (rMotor >= fwMoMaxVal) {
        rMotor = fwMoMaxVal;
      }
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
    }
    if (zavie < 280) {
      rMotor = fwMoMaxVal;
      lMotor += err;
      if (lMotor >= fwMoMaxVal - gpsFwMoChVal) {
        lMotor = fwMoMaxVal - gpsFwMoChVal;
      }
      servo3.writeMicroseconds(lMotor);
      servo2.writeMicroseconds(rMotor);
    }
  }
  if (zavie <= yawDegree || zavie >= (360 - yawDegree)) {
    rMotor = gpsFwMoVal;
    lMotor = gpsFwMoVal;
    servo3.writeMicroseconds(lMotor);
    servo2.writeMicroseconds(rMotor);
  }
  //  Serialll.print("zavie:   ");
  //  Serialll.print(zavie);
  //  Serialll.print('\t');
}
