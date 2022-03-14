void gForceGraph(void)
{
  display.clearDisplay();

  drawDottedLineHorizontal(32); /* 0G */

  if(gForceData.index > (SCREEN_WIDTH - 1))    gForceData.index = 0;

  /* Get Acceleration Update Data */
  compass.read();
  // gForceData.accelAmplitudeX[gForceData.index] = compass.a.x;
  // gForceData.accelAmplitudeY[gForceData.index] = compass.a.y;
  // gForceData.accelAmplitudeZ[gForceData.index] = compass.a.z;

  /* Get Max G Force Value */
  gForceData.max_aX = max(gForceData.max_aX, compass.a.x);
  gForceData.max_aY = max(gForceData.max_aY, compass.a.y);
  gForceData.max_aZ = max(gForceData.max_aZ, compass.a.z);

  /* Get Min G Force Value */
  gForceData.min_aX = min(gForceData.min_aX, compass.a.x);
  gForceData.min_aY = min(gForceData.min_aY, compass.a.y);
  gForceData.min_aZ = min(gForceData.min_aZ, compass.a.z);

  display.setCursor(0, 0);  display.print("aX: ");
  display.setCursor(25, 0); display.print(compass.a.x/_1_G);
  display.setCursor(0, 9);  display.print("aY: ");
  display.setCursor(25, 9); display.print(compass.a.y/_1_G);
  display.setCursor(0, 18);  display.print("aZ: ");
  display.setCursor(25, 18); display.print(compass.a.z/_1_G);

  display.setCursor(25, 34); display.print(gForceData.max_aX/_1_G);
  display.setCursor(25, 43); display.print(gForceData.max_aY/_1_G);
  display.setCursor(25, 52); display.print(gForceData.max_aZ/_1_G);

  display.setCursor(65, 34); display.print(gForceData.min_aX/_1_G);
  display.setCursor(65, 43); display.print(gForceData.min_aY/_1_G);
  display.setCursor(65, 52); display.print(gForceData.min_aX/_1_G);


  gForceData.index++;
  display.display();
}
