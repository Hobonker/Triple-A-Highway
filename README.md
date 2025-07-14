# Waymo Car

## Introduction // Motivation

For this hackathon we wanted to make a project that...
1. Resonated with the San Francisco culture, while still making something that,
2. Looks cool and does something functional.

Now while we seriously fumbled on the apperances portion of the project (mainly due to our lack of access to 3d printers), we believe we were still able to make a project that aligns with our set goals. Our initial goal was to create a sphero-type robot that would use some implementation of obstcable avoidance to avoid walls and move irregularly to ultimately form a complex pong game. However, after much revision, we eventually settled on making a miniature waymo car, that would have object avoidance- specifically, it would automatically steer away from obstacales it would detect using the ultrasonic sensor.

## The Vehicle
![IMG_20250714_060519985](https://github.com/user-attachments/assets/7b8d2fca-92cf-4555-9101-6d561126d5ab)


The powertrain of the vehicle consists of two n20 DC motors, that connect to a adafruit DRV8833 motor driver. This motor driver allows us to control the motors and gives us some directional control (forward / backwards). In the interest of conserving resources and time, we decided to attach the motors to a pencil for stability and easy connection to the frame. The chassis of vehicle is formed from two large breadboards joined together via zip ties and cardboard cutouts. There is also a small breadboard connected to two ultrasonic sensors at the front of the vehicle to give the vehicle object detection on the left and right sides. The idea was that the algorithm would constantly check whether the left or right side object is closer, and once it reaches a certain threshold, like 10 cm or so, it would turn the opposite way to the sensor with the smallest reading, hence turning away from the object. 


# Schematic
schematic can be found in assets as undercity_car.pdf

<img width="1064" height="662" alt="image" src="https://github.com/user-attachments/assets/6d2701bc-176b-421e-a77d-38a6ff2eab5a" />

# How did the project go?
![IMG_20250714_060516756](https://github.com/user-attachments/assets/92295c37-17ad-40a1-a5af-dacab1e2a9d2)

The project was a partial success, we aimed to use a pi 2 zero w and run computer vision models on that using a webcam that we bought seperately. However, due to delays in 3d printing and materials, we werent able to achieve this. However, we were able to get a partially functioning model that we have footage of the device responding to obstructions in its path and turning, although gradually. This can be found at the youtube link (https://youtube.com/shorts/9KcorfMXRC8?si=_dh3rigBQr6FOdhY). The model was able to move on its own power using a 9v battery powering the two motors and the servos to turn when required. We all strongly believe that with more time and adequate supplies, this project could have resembled a mini waymo car in function, although it is not completely there yet. 

Other than that, we did in fact get the pi zero to run partially in that we were able to use the webcam to run the computer vision used for classifying objects. All that is left is to add code to use the size of the classification boxes to estimate the distance to the object. This was one way we were thinking of using comp.vision in the vehicle, that we were so close to achieving had we had more time and resources. 

![IMG_1405.jpeg](images/IMG_1405.jpeg)
![IMG_1406.jpeg](images/IMG_1406.jpeg)
![IMG_1408.jpeg](images/IMG_1408.jpeg)
