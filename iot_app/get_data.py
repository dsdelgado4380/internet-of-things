# Script description: This script is used to get data from hardware Layer
# Temperature 1:DHT11/ DHT22 Sensor
# Humidity 1:DHT11/ DHT22 Sensor
#Temperature 2:LM35

import time
import serial

arduino_port = 'COM5'  # Change this to your Arduino port
baud_rate = 9600
ser = serial.Serial(
    arduino_port,
    baud_rate,
    timeout=1
)

time.sleep(2)  # Wait for the connection to establish

while True:
    data = ser.readline().decode('utf-8').rstrip()
    print(data)
