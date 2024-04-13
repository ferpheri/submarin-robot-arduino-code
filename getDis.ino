void getDis() {
  for (int i = 0 ; i < 10 ; i++) {
    latSum += (latt[i] % 10000000);
    lonSum += (lonn[i] % 10000000);
  }
  disLat = (latSum / 10) + 270000000;
  disLon = (lonSum / 10) + 560000000;
  latSum = 0;
  lonSum = 0;
  l = dis(disLat, setPointLat, disLon, setPointLon);
  if (l <= r) {
    rMotor = 1500;
    lMotor = 1500;
    servo3.writeMicroseconds(lMotor);
    servo2.writeMicroseconds(rMotor);
    if (desIndex <= desArrSize) {
      desIndex++;
      Serialll.print("GO TO NEXT LOCATION ");
      delay(500);
      Serialll.print(".");
      delay(500);
      Serialll.print(".");
      delay(500);
      Serialll.println(".");
      delay(500);
    }
    //    Serialll.print(rMotor);
    //    Serialll.print('\t');
    //    Serialll.print(lMotor);
  }
  else if (l > r && l <= r2) {
    err2 = (l + r) * kgl;
    rMotor -=  err2;
    lMotor -=  err2;
    if (lMotor <= 1500) {
      lMotor = 1500;
    }
    if (rMotor <= 1500) {
      rMotor = 1500;
    }
    servo3.writeMicroseconds(lMotor);
    servo2.writeMicroseconds(rMotor);
    //        Serialll.print(rMotor);
    //        Serialll.print('\t');
    //        Serialll.print(lMotor);
    //    Serialll.print("    ,   ");
    //    Serialll.println(l);
  }
}
