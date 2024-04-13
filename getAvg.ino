void getAvg() {
  latt[0] = latt[1];
  lonn[0] = lonn[1];

  for (int i = 1; i < 9; i++) {
    latt[i] = latt[i + 1];
    lonn[i] = lonn[i + 1];
  }

  latt[9] = posllh.lat;
  lonn[9] = posllh.lon;
  ind++;
  if (ind >= 10) {
    ind = 0;
  }
  for (int i = 0 ; i < 5 ; i++) {
    latSum += (latt[i] % 10000000);
    lonSum += (lonn[i] % 10000000);
  }

  firstLatAvg = (latSum / 5) + 270000000;
  firstLonAvg = (lonSum / 5) + 560000000;
  latSum = 0;
  lonSum = 0;

  for (int i = 5 ; i < 10 ; i++) {
    latSum += (latt[i] % 10000000);
    lonSum += (lonn[i] % 10000000);
  }
  secondLatAvg = (latSum / 5) + 270000000;
  secondLonAvg = (lonSum / 5) + 560000000;
  latSum = 0;
  lonSum = 0;

}
