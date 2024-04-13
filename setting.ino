void setting() {
  while (1) {
    if (Serialll.available() > 0) {
      if (printed) {
        Serialll.println();
        Serialll.println("Please Select the Parameter You Want to Change:");
        Serialll.println("1 => K Values and R Values");
        Serialll.println("2 => Forward Motor Values");
        Serialll.println("3 => Upward Motor Values");
        Serialll.println("4 => Degree Values");
        Serialll.println("5 => Enable/Disable ROll,PITCH,YAW,GPS,Pressure Sensor");
        Serialll.println("6 => gyro accuracy");
        Serialll.println("7 => time");
        Serialll.println("p => exit");
        printed = false;
      }
      input = Serialll.read();
    }
    while (input == '1') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.println("1 => K Value for GYRO Angles");
          Serialll.println("2 => K Value for GPS");
          Serialll.println("3 => R Value for GPS");
          Serialll.println("p => exit");
          printed = true;
        }
        kInput = Serialll.read();
      }
      while (kInput == '1') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Please Select the Parameter You Want to Change:");
            Serialll.print("1 => K Value for roll Angle: "); Serialll.println(kr);
            Serialll.print("2 => K Value for pitch Lenght: "); Serialll.println(kp);
            Serialll.print("3 => K Value for yaw Angle: "); Serialll.println(ky);
            Serialll.println("p => exit");
            printed = false;
          }
          angleInput = Serialll.read();
        }
        while (angleInput == '1') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("roll's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                kr = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        while (angleInput == '2') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("pitch's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                kp = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        while (angleInput == '3') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("yaw's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                ky = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        if (angleInput == 'p' || input == 'P') {
          printed = true;
          angleInput = ' ';
          input = ' ';
          break;
        }
      }
      while (kInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Please Select the Parameter You Want to Change:");
            Serialll.print("1 => K Value for GPS Depth: "); Serialll.println(depthK);
            Serialll.print("2 => K Value for GPS Lenght: "); Serialll.println(kgl);
            Serialll.print("3 => K Value for GPS Angle: "); Serialll.println(kga);
            Serialll.println("p => exit");
            printed = false;
          }
          angleInput = Serialll.read();
        }
        while (angleInput == '1') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("depth's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 1000) {
                depthK = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        while (angleInput == '2') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("Lenght's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                kgl = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        while (angleInput == '3') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("Angle's K value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                kga = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        if (angleInput == 'p' || input == 'P') {
          printed = true;
          angleInput = ' ';
          input = ' ';
          break;
        }
      }
      while (kInput == '3') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Please Select the Parameter You Want to Change:");
            Serialll.print("1 => R1 Value: "); Serialll.println(r);
            Serialll.print("2 => R2 Value: "); Serialll.println(r2);
            Serialll.println("p => exit");
            printed = false;
          }
          angleInput = Serialll.read();
        }
        while (angleInput == '1') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("R1 value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 1000) {
                r = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        while (angleInput == '2') {
          if (Serialll.available() > 0) {
            if (!printed) {
              Serialll.println();
              Serialll.println("R2 value: ");
              Serialll.println("0 => exit");
            }
            AVInput = Serialll.parseFloat();
            delay(1000);
            if (AVInput != 0) {
              if (AVInput >= 1 && AVInput <= 50) {
                r2 = AVInput;
                Serialll.println();
                Serialll.println("DONE!");
                AVInput = 0;
                printed = true;
                angleInput = ' ';
                break;
              } else {
                Serialll.println("this value must be between 1 and 50 ");
              }
            }
            if (AVInput == 0) {
              printed = true;
              angleInput = ' ';
              break;
            }
          }
        }
        if (angleInput == 'p' || angleInput == 'P') {
          printed = true;
          angleInput = ' ';
          input = ' ';
          break;
        }
      }
    }
    while (input == '2') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => Forward Motor MAX Value: "); Serialll.println(fwMoMaxVal);
          Serialll.print("2 => Forward Motor Reverse MAX Value: "); Serialll.println(fwMoMaxReVal);
          Serialll.print("3 => Forward Motor Changing Value: "); Serialll.println(fwMoChVal);
          Serialll.print("4 => GPS Forward Motor Value: "); Serialll.println(gpsFwMoVal);
          Serialll.print("5 => GPS Forward Motor Change Value: "); Serialll.println(gpsFwMoChVal);
          Serialll.println("p => exit");
          printed = true;
        }
        fwMotorInput = Serialll.read();
      }
      while (fwMotorInput == '1' ) {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Forward motor MAX value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1501 && MVInput <= 1900) {
              fwMoMaxVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              fwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1501 and 1900 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            fwMotorInput = ' ';
            break;
          }
        }
      }
      while (fwMotorInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Forward motor reverse MAX value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1100 && MVInput <= 1499) {
              fwMoMaxReVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              fwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1100 and 1499 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            fwMotorInput = ' ';
            break;
          }
        }
      }
      while (fwMotorInput == '3') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Forward motor Change value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1 && MVInput <= 100) {
              fwMoChVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              fwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1 and 100 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            fwMotorInput = ' ';
            break;
          }
        }
      }
      while (fwMotorInput == '4') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("GPS Forward motor value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1501 && MVInput <= 1900) {
              gpsFwMoVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              fwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1501 and 1900 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            fwMotorInput = ' ';
            break;
          }
        }
      }
      while (fwMotorInput == '5') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("GPS Forward motor Change value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1 && MVInput <= 1000) {
              gpsFwMoChVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              fwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1 and 1000 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            fwMotorInput = ' ';
            break;
          }
        }
      }
      if (fwMotorInput == 'p' || input == 'P') {
        printed = true;
        fwMotorInput = ' ';
        input = ' ';
        break;
      }
    }
    while (input == '3') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => Upward Motor MAX Value: "); Serialll.println(uwMoMaxVal);
          Serialll.print("2 => Upward Motor Reverse MAX Value: "); Serialll.println(uwMoMaxReVal);
          Serialll.print("3 => Upward Motor Changing Value: "); Serialll.println(uwMoChVal);
          Serialll.print("4 => Pressure Sensor Changing Value: "); Serialll.println(pressureSensorChVal);
          Serialll.println("p => exit");
          printed = true;
        }
        uwMotorInput = Serialll.read();
      }
      while (uwMotorInput == '1') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Upward motor MAX value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput <= 1900 && MVInput >= 1501) {
              uwMoMaxVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1501 and 1900 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      while (uwMotorInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Upward motor reverse MAX value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 1100 && MVInput <= 1499) {
              uwMoMaxReVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1100 and 1499 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      while (uwMotorInput == '3') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Upward motor CHANGE value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput <= 100 && MVInput >= 1) {
              uwMoChVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1 and 100 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      while (uwMotorInput == '4') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Pressure Sensor Changing Value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput <= 100 && MVInput >= 1) {
              pressureSensorChVal = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1 and 100 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      if (uwMotorInput == 'p' || input == 'P') {
        printed = true;
        uwMotorInput = ' ';
        input = ' ';
        break;
      }
    }
    while (input == '4') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => Degree of YAW rotation: "); Serialll.println(yawDegree);
          Serialll.print("2 => Degree of PITCH rotation: "); Serialll.println(pitchDegree);
          Serialll.print("3 => Degree of ROLL rotation: "); Serialll.println(rollDegree);
          Serialll.println("p => exit");
          printed = true;
        }
        degreeInput = Serialll.read();
      }
      while (degreeInput == '1') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Degree of YAW rotation: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 90 && AVInput >= 0.5) {
              yawDegree = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.5 and 90 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      while (degreeInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Degree of PITCH rotation: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 90 && AVInput >= 0.5) {
              pitchDegree = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.5 and 90 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      while (degreeInput == '3') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Degree of ROLL rotation: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 90 && AVInput >= 0.5) {
              rollDegree = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.5 and 90 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      if (degreeInput == 'p' || input == 'P') {
        printed = true;
        degreeInput = ' ';
        input = ' ';
        break;
      }
    }
    while (input == '5') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => ROLL Degree: "); if (flag8 == 1) {
            Serialll.println("Enable");
          } else {
            Serialll.println("Disable");
          }
          Serialll.print("2 => PITCH Degree: "); if (flag9 == 1) {
            Serialll.println("Enable");
          } else {
            Serialll.println("Disable");
          }
          Serialll.print("3 => YAW Degree: "); if (flag10 == 1) {
            Serialll.println("Enable");
          } else {
            Serialll.println("Disable");
          }
          Serialll.print("4 => GPS: "); if (flag14 == 1) {
            Serialll.println("Enable");
          } else {
            Serialll.println("Disable");
          }
          Serialll.print("5 => Pressure Sensor: "); if (flag15 == 1) {
            Serialll.println("Enable");
          } else {
            Serialll.println("Disable");
          }
          Serialll.println("p => exit");
          printed = true;
        }
        degreeInput = Serialll.read();
      }
      while (degreeInput == '1') {
        if (flag8 == 1) {
          flag8 = 0;
        } else if (flag8 == 0) {
          flag8 = 1;
        }
        printed = false;
        degreeInput = ' ';
        break;
      }
      while (degreeInput == '2') {
        if (flag9 == 1) {
          flag9 = 0;
        } else if (flag9 == 0) {
          flag9 = 1;
        }
        printed = false;
        degreeInput = ' ';
        break;
      }
      while (degreeInput == '3') {
        if (flag10 == 1) {
          flag10 = 0;
        } else if (flag10 == 0) {
          flag10 = 1;
        }
        printed = false;
        degreeInput = ' ';
        break;
      }
      while (degreeInput == '4') {
        if (flag14 == 1) {
          flag14 = 0;
        } else if (flag14 == 0) {
          flag14 = 1;
        }
        printed = false;
        degreeInput = ' ';
        break;
      }
      while (degreeInput == '5') {
        if (flag15 == 1) {
          flag15 = 0;
        } else if (flag15 == 0) {
          flag15 = 1;
        }
        printed = false;
        degreeInput = ' ';
        break;
      }
      if (degreeInput == 'p' || input == 'P') {
        printed = true;
        degreeInput = ' ';
        input = ' ';
        break;
      }
    }

    while (input == '6') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => yaw: "); Serialll.println(gaz);
          Serialll.print("2 => pitch: "); Serialll.println(gay);
          Serialll.print("3 => roll: "); Serialll.println(gax);
          Serialll.println("p => exit");
          printed = true;
        }
        degreeInput = Serialll.read();
      }
      while (degreeInput == '1') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("yaw accuracy: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 1 && AVInput >= 0.00) {
              gaz = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.00 and 1.00 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      while (degreeInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("pitch accuracy: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 1 && AVInput >= 0.00) {
              gay = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.00 and 1.00 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      while (degreeInput == '3') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("roll accuracy: ");
            Serialll.println("0 => exit");
          }
          AVInput = Serialll.parseFloat();
          delay(1000);
          if (AVInput != 0) {
            if (AVInput <= 1.00 && AVInput >= 0.00) {
              gax = AVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              degreeInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 0.00 and 1.00 ");
            }
          }
          if (AVInput == 0) {
            printed = false;
            degreeInput = ' ';
            break;
          }
        }
      }
      if (degreeInput == 'p' || input == 'P') {
        printed = true;
        degreeInput = ' ';
        input = ' ';
        break;
      }
    }
    while (input == '7') {
      if (Serialll.available() > 0) {
        if (!printed) {
          Serialll.println();
          Serialll.println("Please Select the Parameter You Want to Change:");
          Serialll.print("1 => Time of Going Forward in GPS: "); Serialll.println(gpsGoingForward);
          Serialll.print("2 => Time of Running Code: "); Serialll.println(runCodeUntill);
          Serialll.println("p => exit");
          printed = true;
        }
        uwMotorInput = Serialll.read();
      }
      while (uwMotorInput == '1') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Time of Going Forward Value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput <= 60000 && MVInput >= 1000) {
              gpsGoingForward = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 1000 and 60000 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      while (uwMotorInput == '2') {
        if (Serialll.available() > 0) {
          if (printed) {
            Serialll.println();
            Serialll.println("Time of Running Value: ");
            Serialll.println("0 => exit");
          }
          MVInput = Serialll.parseInt();
          delay(1000);
          if (MVInput != 0) {
            if (MVInput >= 30000 && MVInput <= 7200000) {
              runCodeUntill = MVInput;
              Serialll.println();
              Serialll.println("DONE!");
              printed = false;
              uwMotorInput = ' ';
              break;
            }
            else {
              Serialll.println("this value must be between 30000 and 7200000 ");
            }
          }
          if (MVInput == 0) {
            printed = false;
            uwMotorInput = ' ';
            break;
          }
        }
      }
      if (uwMotorInput == 'p' || input == 'P') {
        printed = true;
        uwMotorInput = ' ';
        input = ' ';
        break;
      }
    }
    if (input == 'p' || input == 'P') {
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
      flag2 = 0;
      printed = false;
      break;
    }
  }
}
