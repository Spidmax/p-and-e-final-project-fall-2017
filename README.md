# Automated Room Humidifier System

A device that automatically detects the room humidity and turns on/off humidifier to control the humidity in the range comfortable for humans. 

<br/>

## Summary

The automated Room Humidifier System is an enhanced humidifier that controls the room humidity in a certain level claimed by the user. The Photon controls the power state of the humidifier and connects the system to the cloud. Its website enables users to remotely turn on/off the humidifier or set it to automatically work based on the current room humidity. The users are able to set a specific number of humidity that they feel comfortable working in. The Photon will detect the room humidity with its connected sensor. It will keep the power off if the humidity level is within or higher than the range, and turn the power on if it is lower than the range until it reaches. 

The main goal of the project is to deliver a trouble-free experience of humidifying the environment in winter. People don't need to worry about when it is the right time to turn off the humidifier or turning on when they already started to feel uncomfortable. By setting a range and keeping the system on, everything is automatically under control in the background. 

<br/>

## Component Parts

The hardware includes:

- Photon: Wi-Fi-enabled and attached to the humidifier as an intelligent switch. <br/>
Purchase on AdaFruit: https://www.adafruit.com/product/2721 <br/>

- A relay: controlling the power of the humidifier. (OUTPUT) <br/>
Purchase on AdaFruit: https://www.adafruit.com/product/2935 <br/>

- A humidity sensor: detecting the room humidity. (INPUT) I will purchase this item if the hybrid lab doesn't have it. <br/>
Purchase on AdaFruit: https://www.adafruit.com/product/3251 <br/>

The software includes a html file that displays the power state.

- A switch: connected to the APIs of the Photon console to control the state of the humidifier. (INPUT)

<br/>

## Timeline

### Week 1-2
I purchased Photon, a cheap alternative for Arduino Wi-Fi. It has a totally different console system from Arduino, so it's quite difficult to control and I have to search a lot for solutions. <br/>
I also purchased Adafruit Si7021 Temperature & Humidity Sensor. AdaFruit provides a tutorial website, and Photon has a sample project in the library too, which significantly benefits my building process. <br/>
The humidity sensor is connected to the D7 input on Photon. <br/>

### Week 3-5
I prototyped the circuit with sensors and devices, built the website, connected with the system, and made it functional. <br/>
Photon has the variables & events feature as a replacement for the print function and possible wireless connection to other services. I referenced a tutorial of working with Photon and the humidity sensor and created the variables:
  - `Sensor`: detect if the sensor is working properly <br/>
  - `h`: the value of humidity (%) <br/>
  - `t`: the value of temperature (degrees of Celsius) <br/>
  - `userHumidity`: the value of humidity declared by the user <br/>
<br/>
In the website html, the user input will influence the value `arg`, which will be transfered into `userHumidity` in the core code. 
  


<br/>

## Challenges

1. I don't understand how to make the micro-computer work under high voltage that the humidifier requires. I will research to make sure that there would be no safe concerns.
2. I am not familiar with the network connection feature either. I will research and determine how to build the background online structure. (database, if it is necessary to include a user-login feature, etc.)
3. Photon's console could be confusing and buggy sometimes. I didn't successfully create a webhook to display the humidity & temperature data on the web dashboard. 

<br/>

## References and link

https://thecustomizewindows.com/2017/10/arduino-temperature-humidity-sensor-new-dht11-dht21-dht22-tests/ <br/>
http://www.instructables.com/id/Controlling-AC-light-using-Arduino-with-relay-modu/ <br/>
http://arduino-info.wikispaces.com/TemperatureHumidity <br/>
https://docs.particle.io/guide/getting-started/start/photon <br/>
http://www.instructables.com/id/PhotonConnect-LCD-With-I2C/ <br/>
https://www.hackster.io/moritz/measuring-temperature-and-humidity-with-particle-photon-f1c300

<br/>
