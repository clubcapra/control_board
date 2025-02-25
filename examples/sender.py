import can

useCAN = True

bus = None
if useCAN:
    bus = can.Bus("can0", bustype="socketcan", bytrate=250000)

def message(front_led=False, back_led=False, debug_led=False, winch_brake=False, winch_percent=0, status=0):
    """
    Send a CAN message to control the device.
    
    :param interface: CAN interface (e.g., 'can0')
    :param front_led: Boolean, turn front LED on/off
    :param back_led: Boolean, turn back LED on/off
    :param debug_led: Boolean, turn debug LED on/off
    :param winch_brake: Boolean, apply winch brake
    :param winch_percent: Integer, winch motor control (-128 to 127)
    :param status: Integer, status bits (0-15)
    """
    # Construct the first byte with LED and brake states
    first_byte = (front_led << 0) | (back_led << 1) | (debug_led << 2) | (winch_brake << 3) | (status << 4)
    
    # Convert signed winch_percent to unsigned (two's complement)
    second_byte = winch_percent & 0xFF
    
    # Create CAN message
    msg = can.Message(arbitration_id=0x1, data=[first_byte, second_byte], is_extended_id=False)

    print("msg: ", first_byte, second_byte)
  
    
    if useCAN: 
        bus.send(msg)

def keyboard_control():
    print("Press 'q' to quit.")
    try:
        while True:
            key = input()
            print(key)
            if key[0] == 'q':
                print("Exiting...")
                break
            if key[0] == 'f':
                message(front_led=True)
            if key[0] == 'd':
                message(debug_led=False)
            if key[0] == 's':
                message(debug_led=True)
            if key[0] == 'w':
                message(winch_brake=True)
            
            if key[0] == '1':
                message(status=0)
            
            if key[0] == '2':
                message(status=1)

            if key[0] == '3':
                message(status=2)
            
            if key[0] == '4':
                message(status=3)
            
            if key[0] == '5':
                message(status=4)
            
            if key[0] == '6':
                message(status=5)
            
            if key[0] == '7':
                message(status=14)
            
            if key[0] == '8':
                message(status=15)

    
    except can.CanError as e:
        print(f"CAN error: {e}")
    finally:
        if useCAN:
            bus.shutdown()

if __name__ == "__main__":
    keyboard_control()
