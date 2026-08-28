import serial
import subprocess
import math

arduino = serial.Serial("/dev/ttyACM1", 115200)

while True:
    line = arduino.readline().decode().strip()
    print(line)
    values = line.split(",")
#   print(values)

    x = float(values[0])
    y = float(values[1])
    z = float(values[2])

    magnitude = math.sqrt(x**2 + y**2 + z**2)
    print(magnitude)

    if magnitude>50:
        subprocess.run(["mpv", "OOF.mp3"])










"""
SerialPortObj = serial.Serial('/dev/ttyACM0')
print('\nStatus -> ',SerialPortObj)
 
SerialPortObj.close()    
"""