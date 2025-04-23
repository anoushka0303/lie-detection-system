Lie Detection System

A real-time lie detection system that uses physiological and visual cues to determine deception. Built with Python, and powered by Raspberry Pi 5 and Arduino Uno, this project combines eye tracking, GSR (Galvanic Skin Response), and tremor detection to analyze potential indicators of lying.

Features

- Visual Analysis: Tracks eye movement, blink rate, and pupil dilation via webcam.
- Physiological Sensing: GSR Sensor to measure skin conductivity changes (stress indicator), Flex Sensor to detect subtle hand tremors.
- Real-time Processing: Data is processed live on the Raspberry Pi. Arduino Uno collects analog signals and communicates via serial.

Hardware Requirements

- Raspberry Pi 5 (8GB recommended)
- Arduino Uno
- USB Webcam
- GSR Sensor (e.g., Grove GSR or homemade setup)
- Flex Sensor
- Jumper wires, resistors, breadboard
- Optional: Cooling fan for Raspberry Pi (for heavy processing)

Software Requirements

Install the following on the Raspberry Pi:

<pre>sudo apt update  
sudo apt install python3-pip python3-opencv cmake libboost-all-dev  
pip3 install dlib opencv-python pyserial numpy gaze_tracking </pre>

If dlib fails to build, increase swap memory:

<pre> sudo nano /etc/dphys-swapfile  
Change CONF_SWAPSIZE=100 to CONF_SWAPSIZE=2048  
sudo /etc/init.d/dphys-swapfile restart</pre>

Arduino libraries (in the Arduino IDE): No special libraries needed unless using sensor-specific ones

How It Works

1. Arduino Uno reads:
   - GSR value from analog pin
   - Flex sensor value from another analog pin
   - Sends both as comma-separated values over serial to Raspberry Pi

2. Raspberry Pi:
   - Captures video frames using OpenCV
   - Uses gaze_tracking to extract eye movement and blink rate
   - Reads GSR and tremor values via serial from Arduino
   - Applies basic heuristics (or ML model) to evaluate likelihood of deception

Running the System

1. Upload Arduino Code

Flash your Arduino Uno with the code to read analog sensors and print to serial:

<pre>void setup() {  
  Serial.begin(9600);  
}

void loop() {  
  int gsr = analogRead(A0);  
  int flex = analogRead(A1);  
  Serial.print(gsr);  
  Serial.print(",");  
  Serial.println(flex);  
  delay(100);  
}</pre>

2. Run Python Code on Pi

<pre>python3 main.py</pre>

Sample main.py handles webcam, serial reading, and prints analysis output.

Output

- Console prints or logs:
  - Eye state: blinking, looking left/right/center
  - GSR levels
  - Tremor values
- Optional: display warning if suspicious behavior is detected

Disclaimer

This system is built for educational and experimental purposes. Human behavior is complex, and physiological signals alone are not reliable for definitive lie detection in legal, medical, or ethical contexts.

Author

Developed by Anoushka Prakash and Vaibhav Goyal
For queries or contributions, feel free to open an issue or reach out.
