# GPS Kit

For this GPS Kit contained a fully functional GNSS Receiver with Digital Compass

## Hardware Components

* Arduino MEGA 256kB Flash Storage/ 8kB SRAM
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

* **Using Waypoint Menu** Go to **LOG** Menu to say Waypoint, Exit and go back to **NAVI** and select Waypoint from Index 0-5 to show way point on **NAVI** menu

In case of the reception signal took too long the info screen will pop up
and show how to get a better reception signal

## Button Function in Home Menu
  * **A Button** Press to switch to respected icon menu
  * **B Button** Press to switch to previous menu icon
  * **C Button** Press to switch to next menu icon

## Button Function in Menu
  * **A Button** Press to switch to main menu
  * **B Button** Press to switch to sub Menu 1
  * **C Button** Press to switch to sub Menu 2

## Log Menu
* Press and Hold **C Button** to Log Current Location to memory
* Press and Hold **B Button** to clear Location in memory

## Git Commands
* **git push -f origin [branch]** force push file to repository case repository conflict
* **git init** Start local folder as new repository
* **git remote add [link]** get project origin from github to current directory
* **git pull** get files from github to current folder
* **git add .** add all new update file to commit
* **git commit -m "[comments]"** get new update files committed
* **git push** push all commited file to github
* **git status** get status on working directory
