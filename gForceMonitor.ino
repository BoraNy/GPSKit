void gForceGraph(void)
{
  display.clearDisplay();

  drawDottedLineHorizontal(32); /* 0G */

  /* Get Acceleration Update Data */
  compass.read();

  /* Get Max G Force Value */
  gForceData.max_aX = max(gForceData.max_aX, compass.a.x);
  gForceData.max_aY = max(gForceData.max_aY, compass.a.y);
  gForceData.max_aZ = max(gForceData.max_aZ, compass.a.z);

  /* Get Min G Force Value */
  gForceData.min_aX = min(gForceData.min_aX, compass.a.x);
  gForceData.min_aY = min(gForceData.min_aY, compass.a.y);
  gForceData.min_aZ = min(gForceData.min_aZ, compass.a.z);

  /* Show X Acceleration */
  display.setCursor(0, 0); display.print("aX");
  display.setCursor(0, 10); display.print(compass.a.x);
  display.setCursor(38, 10); display.print(gForceData.min_aX);
  display.setCursor(76, 10); display.print(gForceData.max_aX);

  /* Show Y Acceleration */
  display.setCursor(0, 12); display.print("aY");
  display.setCursor(0, 22); display.print(compass.a.y);
  display.setCursor(38, 22); display.print(gForceData.min_aY);
  display.setCursor(76, 22); display.print(gForceData.max_aY);

  /* Show Z Acceleration */
  display.setCursor(0, 24); display.print("aZ");
  display.setCursor(0, 34); display.print(compass.a.z);
  display.setCursor(38, 34); display.print(gForceData.min_aZ);
  display.setCursor(76, 34); display.print(gForceData.max_aZ);

  display.display();
}
