Here’s the revised README with the requested changes:

---

# Home Automation

This project allows you to control your home appliances using a NodeMCU ESP8266, Blynk IoT app, and a custom web UI. It supports multiple control methods, including a mobile app, web interface, and manual switches.

## Features

1. **Easy to use**: Simple setup and control process.
2. **Blynk IoT app control**: Manage your devices through the [Blynk IoT app](https://play.google.com/store/apps/details?id=cloud.blynk&hl=en).
3. **Customized Web UI**: Access and control devices via a sleek, user-friendly web interface.
4. **Web control panel**: A web-based control panel accessible from any browser at [192.168.4.1](http://192.168.4.1/).
5. **Manual Switch Control**: Physical switches to manually control appliances.

## Installation Process

### 1. Install Arduino IDE

- Download and install the Arduino IDE from [here](https://www.arduino.cc/en/software).

### 2. Install Required Libraries

- Open the Arduino IDE.
- Go to **Sketch > Include Library > Manage Libraries...**
- Search for and install the following libraries:
  - **ESP8266WiFi** by ESP8266 Community
  - **Blynk** by Volodymyr Shymanskyy
  - **ESP8266WebServer** by ESP8266 Community

### 3. Configure Blynk

1. Create an account on [Blynk.Console](https://blynk.cloud/dashboard/register).
2. Log in to your account on [Blynk.Console](https://blynk.cloud/dashboard/login).
3. Click on **New Template** and configure your template as needed.
4. Save the template and note down the **Template ID** and **Auth Token**.

### 4. Prepare the Arduino Sketch

1. Download the project code from the [GitHub repository](https://github.com/anbuinfosec/home-automation/blob/main/home_automation.ino).
2. Open the `home_automation.ino` file in the Arduino IDE.
3. Replace the placeholders in the code with your Blynk Auth Token, Wi-Fi credentials, and any other necessary details.

   ```cpp
   #define BLYNK_TEMPLATE_ID "XXXXXXXXX" // replace with your Blynk project template ID
   #define BLYNK_TEMPLATE_NAME "XXXXXXX" // replace with your Blynk project name
   #define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" // replace with your Blynk project auth token
   char ssid[] = "XXXXXXXXXXX"; // replace with your SSID
   char pass[] = "XXXXXXXXXXX"; // replace with your Wi-Fi password
   ```

4. Ensure the required libraries are included at the top of your sketch:

   ```cpp
   #include <ESP8266WiFi.h>
   #include <BlynkSimpleEsp8266.h>
   #include <ESP8266WebServer.h>
   ```

5. Replace the Wi-Fi SSID credentials for the new SSID:

   ```cpp
   // New SSID credentials
   char ssidName[] = "XXXXXXXXXXXXXXXX";
   char ssidPwd[] = "XXXXXXXXXXXXXXXXX";
   ```

### 5. Upload the Code to NodeMCU

1. Connect your NodeMCU to your computer using a USB data cable.
2. Select the correct board and port under **Tools > Board** and **Tools > Port**.
3. Click **Upload** to flash the code to your NodeMCU.

### 6. Connect to the Blynk IoT App

1. Open the Blynk app on your smartphone.
2. Create a new project using the template you configured in Blynk.Console.
3. Add widgets to control your devices.
4. Run the project to start controlling your home automation system.

### 7. Access the Web Control Panel

1. Once the NodeMCU is connected to Wi-Fi, it will start a web server.
2. Open a browser and enter the IP address `192.168.4.1` to access the control panel.
3. Use the web UI to control your devices.

---

## Congratulations!

Your home automation system is now set up and ready to use. Control your devices via the Blynk app, the web UI, or manual switches.

---

### [+] Developer: [Mohammad Alamin](https://anbusec.xyz)

---
