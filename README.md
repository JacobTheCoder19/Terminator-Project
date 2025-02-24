<h2><em>💎 Key Features 💎</em></h2>
<div>
  🟩 <strong>Ultrasonic Object Detection</strong><br>
  &emsp;🔸 Utilizes an ultrasonic sensor to detect objects within a specified range, allowing the robot to respond to its environment.<br><br>
</div>
<div>
  🟩 <strong>Servo-Controlled Head Movement</strong><br>
  &emsp;🔸 The robot's head is controlled by a servo motor, enabling it to smoothly track detected objects.<br><br>
</div>
<div>
  🟩 <strong>PIR Sensor Activation</strong><br>
  &emsp;🔸 The robot is equipped with a Passive Infrared (PIR) sensor that triggers tracking mode when motion is detected.<br><br>
</div>
<div>
  🟩 <strong>Smooth Tracking</strong><br>
  &emsp;🔸 The head movement is designed to be smooth and gradual, enhancing the realism of the robot's tracking behavior.<br><br>
</div>
<div>
  🟩 <strong>Serial Monitoring</strong><br>
  &emsp;🔸 Serial output provides real-time distance readings from the ultrasonic sensor, useful for debugging and monitoring.<br><br>
</div>

<h2><em>✨ Purpose / Inspiration ✨</em></h2>
&emsp;This project was inspiration came from my mom buying me this really cool realistic terminator skull where the face comes off and their is space in the actual skull to store stuff. Once I got it I knew right away that I wanted to make it come to life. In the first stages of making it come to life instead of it following the person it actually was hooked up to a laser module that would then point the laser at the nearest person. Of course I changed it so it was more realistic and just followed the person like in the movies.

<h2><em>⚙️ How It Works ⚙️</em></h2>
&emsp;The project consists of an Arduino board controlling a servo motor for the head and another servo motor for the ultrasonic sensor. The ultrasonic sensor is used to measure distances to nearby objects, while the PIR sensor detects motion to activate tracking mode.

&emsp;In the code, the head motor and sensor motor are initialized, and the system continuously checks the PIR sensor for motion. When motion is detected, the robot enters tracking mode, where it scans the area by moving the ultrasonic sensor from 60 to 170 degrees. The distance readings from the ultrasonic sensor are used to determine the closest object.

&emsp;If an object is detected within a valid range, the head smoothly moves to track the object. If no object is detected, the head remains in its last known position. The system also outputs distance readings to the serial monitor for debugging and monitoring purposes.
