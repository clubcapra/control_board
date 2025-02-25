# Control Board for Rove
This repository contains the embedded firmware for the **Control Board** of *Rove*, CAPRA's new search and rescue robot. The control board is a custom PCB designed to handle **RGB LED indicators, a winch motor, and front/rear fog lights**, all controlled via **CAN Bus communication** from the **Jetson Orin**.


## 🌟 Features
- **RGB LED Strip Control (WS2811, 27 LEDs)** – Provides real-time status indication based on robot operation.
- **Winch Motor Control** – Enables pulling heavy objects using a motorized winch.
- **Front & Rear Fog Lights** – Enhances visibility in dark environments.
- **CAN Bus Communication** – Receives commands from the Jetson Orin to offload processing to a real-time MCU.
- **ST-Link Debugging Support** – Allows real-time debugging via an ST-Link connector.

## 🔧 Hardware Details
- **MCU**: STM32F446RET6 (Running the Arduino framework with PlatformIO)
- **Custom PCB**: Located in the *Topbox* portion of Rove.
- **Communicates with**: Jetson Orin via CAN Bus
- **External Components**:
  - WS2811 RGB LED strip (27 LEDs)
  - Winch motor
  - Front & rear fog lights

## 📨 Control Message Structure
In the context of the provided `API.cpp` code, the control messages follow a specific structure to manage various components:

1. **Byte 0**: Control flags for LEDs and winch brake.
   - Bit 0: Front LED (1 = ON, 0 = OFF)
   - Bit 1: Back LED (1 = ON, 0 = OFF)
   - Bit 2: Debug LED (1 = ON, 0 = OFF)
   - Bit 3: Winch brake (1 = BRAKE, 0 = CONTROL)
   - Bits 4-7: Status code for RGB LED (0 to 15)
2. **Byte 1**: Winch control data.
   - Bits 0-7: Winch percent (-100 to 100, signed value)

## Status dictionnary
The **RGB LED strip** indicates Rove’s current state. Below is the mapping of colors and effects:

| Code | Status                  | Color (Effect)            | Meaning |
|------|-------------------------|---------------------------|---------|
| **0**  | ✅ **OK**                | 🟢 Green (Static)         | System running normally |
| **1**  | ⚠️ **Running (Warning)** | 🟠 Orange / OFF (Pattern) | Operating with a warning |
| **2**  | ❌ **Unknown Error**     | 🔴 Red (Static)          | Unspecified error |
| **3**  | ⏳ **Timeout**           | 🟡 Yellow / Green (Pattern) | System timeout detected |
| **4**  | 🔋 **Battery Low**       | 🔴 Red / OFF (Swap)      | Battery running low |
| **5**  | 📡 **Lost Communication** | 🟣 Purple (Fade)        | Lost connection with the operator |
| **14** | 🚔 **Police Mode**       | 🔴🔵 Red/Blue (Alternating) | *wee-woo-wee-woo*|
| **15** | 🌈 **Rainbow Mode**      | 🌈 Multi-Color (Rainbow) | Decorative mode |

---

### 🎯 Prerequisites

- Install [Visual Studio Code](https://code.visualstudio.com/)
- Install the **PlatformIO** extension:
  1. Open **VS Code**.
  2. Navigate to `Extensions` (`Ctrl+Shift+X`).
  3. Search for **PlatformIO IDE** and click **Install**.
  4. Restart **VS Code**.

### 📂 Clone the Repository

```sh
git clone git@github.com:clubcapra/control_board.git
cd ControlBoard
```

### 🔧 Build & Flash the Firmware

1. Connect an **ST-Link** debugger to the Control Board.
2. Open **PlatformIO** in VS Code.
3. Click **Build** (`✓`) to compile the firmware.
4. Click **Upload** (`→`) to flash the firmware to the board.

## 🔗 Dependencies

- **Adafruit NeoPixel** (`Adafruit NeoPixel@^1.12.4`): Controls the WS2811 LED strip.
- **STM32_CAN** (`STM32_CAN@^1.1.2`): Provides CAN communication.

Note: All dependencies should be installed according to platform.ini in platformio.

## Usage & Debugging
 - The Control Board listens for commands via CAN Bus from the Jetson Orin
 - The Winch Motor is controlled based on received CAN messages.
 - Fog Lights (front and rear) turn on/off as required for visibility based on received CAN messages.
 - RGB LED Strip updates based on the robot's state based on the received CAN messages.
 - **ST-Link Debugging** allows real-time debugging and firmware flashing.