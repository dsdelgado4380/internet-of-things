# Script description: This script is used to get data from hardware Layer
# Temperature 1:DHT11/ DHT22 Sensor
# Humidity 1:DHT11/ DHT22 Sensor
#Temperature 2:LM35
import serial
from get_port import get_arduino_port
import time
port = get_arduino_port()
arduino_port= port
baud_rate= '9600'

ser = serial.Serial(
    arduino_port,
    baud_rate,
    timeout=1
)

time.sleep(2)
while True:
    data=ser.readline().decode('utf-8').rstrip()
    print(data)
