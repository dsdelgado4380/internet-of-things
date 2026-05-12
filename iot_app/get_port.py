from serial.tools.list_ports import comports

def get_arduino_port():
    #ports = serial.tools.list_ports.comports()
    ports = comports()  
    for port in ports:
        #if 'Arduino' in port.description or 'CH340' in port.description:
            return port.device
    return None

#arduino_port= get_arduino_port()
#if arduino_port:
#    print(arduino_port)
#else:
#    print("No port detected :::")