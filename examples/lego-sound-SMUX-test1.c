#pragma config(Sensor, S1,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: lego-sound-SMUX-test1.c $
 */

/**
 * lego-sound.h provides an API for the Lego sound sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.60 AND HIGHER.

 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "hitechnic-sensormux.h"
#include "lego-sound.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor LEGOSND = msensor_S1_1;

task main () {
  int soundraw = 0;
  int soundnorm = 0;
  bool dba = false;

  nNxtButtonTask  = -2;

  displayCenteredTextLine(0, "Lego");
  displayCenteredBigTextLine(1, "Sound");
  displayCenteredTextLine(3, "SMUX Test");
  displayCenteredTextLine(5, "Connect SMUX to");
  displayCenteredTextLine(6, "S1 and snd sensor");
  displayCenteredTextLine(7, "to SMUX Port 1");
  sleep(2000);

  eraseDisplay();
  displayTextLine(0, "Lego Sound Sensor");
  displayTextLine(6, "[enter] to switch");
  displayTextLine(7, "dB and dBA mode");

  // Set the sensor to dB mode.
  SNDsetDB(LEGOSND);
  displayCenteredTextLine(1, "dB mode");

  while(true) {
    // The enter button has been pressed, switch
    // to the other mode
    if (nNxtButtonPressed == kEnterButton) {
      dba = !dba;
      if (!dba) {
        // set the sensor to DB mode
        SNDsetDB(LEGOSND);
        displayCenteredTextLine(1, "dB mode");
      } else {
        // set the sensor to dBA mode.
        SNDsetDBA(LEGOSND);
        displayCenteredTextLine(1, "dBA mode");
      }

      // wait 500ms to debounce the switch
      sleep(500);
    }

    // Read the normalised value of the sensor
    soundraw = SNDreadRaw(LEGOSND);

    // Display the raw and normalised values
    soundnorm = SNDreadNorm(LEGOSND);

    // display the info from the sensor
    displayTextLine(3, "Raw:  %3d", soundraw);
    displayTextLine(4, "Norm: %3d", soundnorm);
    sleep(50);
  }
}

/*
 * $Id: lego-sound-SMUX-test1.c $
 */