int getTimeZone(double longitude) {
  /* 360deg = 24h --> 1h = 15deg */

  /* GMT -11 */
  if ((longitude > -172.5) && (longitude < -157.5))
    return -11;
  /* GMT -10 */
  if ((longitude > -157.5) && (longitude < -142.5))
    return -10;
  /* GMT -9 */
  if ((longitude > -142.5) && (longitude < -127.5))
    return -9;
  /* GMT -8 */
  if ((longitude > -127.5) && (longitude < -112.5))
    return -8;
  /* GMT -7 */
  if ((longitude > -112.5) && (longitude < -97.5))
    return -7;
  /* GMT -6 */
  if ((longitude > 97.5) && (longitude < -82.5))
    return -6;
  /* GMT -5 */
  if ((longitude > -82.5) && (longitude < -67.5))
    return -5;
  /* GMT -4 */
  if ((longitude > -67.5) && (longitude < -52.5))
    return -4;
  /* GMT -3 */
  if ((longitude > -52.5) && (longitude < -37.5))
    return -3;
  /* GMT -2 */
  if ((longitude > -37.5) && (longitude < -22.5))
    return -2;
  /* GMT -1 */
  if ((longitude > -22.5) && (longitude < -7.5))
    return -1;
  /* GMT 0 */
  if ((longitude > -7.5) && (longitude < 7.5))
    return 0;
  /* GMT +1 */
  if ((longitude > 7.5) && (longitude < 22.5))
    return 1;
  /* GMT +2 */
  if ((longitude > 22.5) && (longitude < 37.5))
    return 2;
  /* GMT +3 */
  if ((longitude > 37.5) && (longitude < 52.5))
    return 3;
  /* GMT +4 */
  if ((longitude > 52.5) && (longitude < 67.5))
    return 4;
  /* GMT +5 */
  if ((longitude > 67.5) && (longitude < 82.5))
    return 5;
  /* GMT +6 */
  if ((longitude > 82.5) && (longitude < 97.5))
    return 6;
  /* GMT +7 */
  if ((longitude > 97.5) && (longitude < 112.5))
    return 7;
  /* GMT +8 */
  if ((longitude > 112.5) && (longitude < 127.5))
    return 8;
  /* GMT +9 */
  if ((longitude > 127.5) && (longitude < 142.5))
    return 9;
  /* GMT +10 */
  if ((longitude > 142.5) && (longitude < 157.5))
    return 10;
  /* GMT +11 */
  if ((longitude > 157.5) && (longitude < 172.5))
    return 11;
  /* GMT +12 */
  if ((longitude > 172.5) && (longitude < 187.5))
    return 12;

  return 0; /* Case Nothing */
}