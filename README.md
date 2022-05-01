# GPS Kit

For this GPS Kit contained a fully functional GNSS Receiver with Digital Compass

## Hardware Components

* Arduino MEGA 256kB Flash Storage/ 8kB SRAM (Older Build)
* ATMEGA 1284P 128kB Flash Storage/ 16kB SRAM / 4kB EEPROM
* LSM303DLHC 3D accelerometer and 3D magnetometer
* NEO-6M u-blox GPS Module
* DHT11 Temperature-Humidity Sensor

## Features

The location recovery will save automatically on start up once the GPS
receiver connected to the satellites, In case of an accident power loss
the location data will recover from EEPROM memory

* Full Location Logging and Data from GNSS Data Encoding
* Start Point Recovery
* Distance From Start Point Measurement
* Satellite Connection Tracker
* Deviation Map
* Altimeter Graph
* Digital Compass
* Hardware Info Logging

## Usage & Info
Press B and C button for navigation, and Press A for select

# GPS Menu
* Shows the detailed info data received from the satellites
 
# SAT Menu
* Shows the satellites ID and signal reception strength

# DEVIATION Menu
* Shows the position deviation through time

# COMPASS Menu
* Shows the digital compass with two headings
* 1. True north with circle
* 2. Heading
* Press B will show the accelerometer menu of real time, min, and maximum graviational pull
* Press C will shows the detailed info of the start and current coordinates, along with traveled distance from the start point

# ALTIMETER Menu
* Shows the approximate altitude graph based on the altitude calculated by the satellites (Not accurate)

# SYSTEM Menu
* Show the sunrise and sunset times based on the calculation of the coordinate and time zone
* Shows the log of build info
* Press C will shows the detailed info of the start and current coordinates, along with traveled distance from the start point

# LOG Menu
* Press and hold B for erasing all the logged coordinates data from the EEPROM
* Press and hold C for logging the current coordinate to the EEPROM for later use in **NAVIGATION** menu

# NAVIGATION Menu
* Press C for selecting the waypoints from 0 to 5, these waypoints are obtained from the **LOG** menu
* Press B for select the waypoint and starts navigation
*** During Navigation ***
* Press and hold C for zoom in
* Press and hold B for zoom out
