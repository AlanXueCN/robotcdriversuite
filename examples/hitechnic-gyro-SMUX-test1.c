#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-gyro-SMUX-test1.c $
 */

/**
 * hitechnic-gyro.h provides an API for the HiTechnic Gyroscopic Sensor.  This program
 * demonstrates how to use that API in combination with the Sensor MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Now uses HTSMUX driver which has been split from common.h\n
 *        HTSMUX initialisation and scanning functions have been removed\n
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.60 AND HIGHER.

 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.2
 */

#include "hitechnic-sensormux.h"
#include "hitechnic-gyro.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTGYRO = msensor_S1_1;

task main () {

  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "GYRO");
  displayCenteredTextLine(3, "SMUX Test");
  displayCenteredTextLine(5, "Connect SMUX to");
  displayCenteredTextLine(6, "S1 and sensor to");
  displayCenteredTextLine(7, "SMUX Port 1");

  sleep(2000);
  eraseDisplay();
  time1[T1] = 0;
  while(true) {
    if (time1[T1] > 1000) {
      eraseDisplay();
      displayTextLine(1, "Resetting");
      displayTextLine(1, "heading");
      sleep(500);

      // Start the calibration and display the offset
      displayTextLine(2, "Offset: %4d", HTGYROstartCal(HTGYRO));
      playSound(soundBlip);
      while(bSoundActive) EndTimeSlice();
      time1[T1] = 0;
    }

    while(nNxtButtonPressed != kEnterButton) {
      eraseDisplay();

      displayTextLine(1, "Reading");
      // Read the current calibration offset and display it
      displayTextLine(2, "Offset: %4d", HTGYROreadCal(HTGYRO));

      displayClearTextLine(4);
      // Read the current rotational speed and display it
      displayTextLine(4, "Gyro:   %4d", HTGYROreadRot(HTGYRO));
      displayTextLine(6, "Press enter");
      displayTextLine(7, "to recalibrate");
      sleep(100);
    }
  }
}

/*
 * $Id: hitechnic-gyro-SMUX-test1.c $
 */