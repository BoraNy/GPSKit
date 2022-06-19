void gForceGraph(void) {
  display.clearDisplay();

  // drawDottedLineHorizontal(32); /* 0G */

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
  display.setCursor(0, 0);
  display.print("aX");
  display.setCursor(38, 0);
  display.print("MIN");
  display.setCursor(76, 0);
  display.print("MAX");
  display.setCursor(0, 10);
  display.print(compass.a.x / _1_G);
  display.setCursor(38, 10);
  display.print(gForceData.min_aX / _1_G);
  display.setCursor(76, 10);
  display.print(gForceData.max_aX / _1_G);

  /* Show Y Acceleration */
  display.setCursor(0, 20);
  display.print("aY");
  display.setCursor(0, 30);
  display.print(compass.a.y / _1_G);
  display.setCursor(38, 30);
  display.print(gForceData.min_aY / _1_G);
  display.setCursor(76, 30);
  display.print(gForceData.max_aY / _1_G);

  /* Show Z Acceleration */
  display.setCursor(0, 40);
  display.print("aZ");
  display.setCursor(0, 50);
  display.print(compass.a.z / _1_G);
  display.setCursor(38, 50);
  display.print(gForceData.min_aZ / _1_G);
  display.setCursor(76, 50);
  display.print(gForceData.max_aZ / _1_G);

  display.display();
}