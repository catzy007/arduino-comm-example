# ------------------------------------------------------------------------------
# Python program using the library to interface with the arduino sketch above.
# ------------------------------------------------------------------------------

import PyCmdMessenger
import time

# Initialize an ArduinoBoard instance.  This is where you specify baud rate and
# serial timeout.  If you are using a non ATmega328 board, you might also need
# to set the data sizes (bytes for integers, longs, floats, and doubles).  
arduino = PyCmdMessenger.ArduinoBoard("/dev/ttyUSB0",baud_rate=9600)

# List of command names (and formats for their associated arguments). These must
# be in the same order as in the sketch.
commands = [["on",""],
            ["off",""],
            ["reply","s"],
            ["error","s"]]

# Initialize the messenger
c = PyCmdMessenger.CmdMessenger(arduino,commands)

c.send("on")
msg = c.receive()
print(msg)

time.sleep(2)

c.send("off")
msg = c.receive()
print(msg)
