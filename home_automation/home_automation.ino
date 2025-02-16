#define BLYNK_TEMPLATE_ID "TMPL6Idv6BoiV"
#define BLYNK_TEMPLATE_NAME "NodeMCU"
#define BLYNK_AUTH_TOKEN "fehVTFiCpKOZNiutc_UbnF4quLiwxld1"

// Include necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WebServer.h>

// Replace with your WiFi credentials
char ssid[] = "Meow"; // replace with your ssid
char pass[] = "0xANBUINFOSEC#1337#XD"; // replace with your password

// New SSID credentials
char ssidName[] = "Home Automation";
char ssidPwd[] = "ANBU#1337#";

// Pin definitions
const int RelayPin1 = D1;
const int RelayPin2 = D2;
const int RelayPin3 = D3;
const int RelayPin4 = D4;
const int SwitchPin1 = D5;
const int SwitchPin2 = D6;
const int SwitchPin3 = D7;
const int SwitchPin4 = D8;

// Blynk virtual pins for relay control
#define VPIN_BUTTON_1 V1
#define VPIN_BUTTON_2 V2
#define VPIN_BUTTON_3 V3
#define VPIN_BUTTON_4 V4

// Variables to store switch and relay states
bool toggleState_1 = LOW;
bool toggleState_2 = LOW;
bool toggleState_3 = LOW;
bool toggleState_4 = LOW;
bool SwitchState_1 = LOW;
bool SwitchState_2 = LOW;
bool SwitchState_3 = LOW;
bool SwitchState_4 = LOW;

// Timer for periodic tasks
BlynkTimer timer;
ESP8266WebServer server(80); // Create a web server object

// Function to update relay states from Blynk
BLYNK_WRITE(VPIN_BUTTON_1)
{
  toggleState_1 = param.asInt();
  digitalWrite(RelayPin1, toggleState_1 ? LOW : HIGH);
}

BLYNK_WRITE(VPIN_BUTTON_2)
{
  toggleState_2 = param.asInt();
  digitalWrite(RelayPin2, toggleState_2 ? LOW : HIGH);
}

BLYNK_WRITE(VPIN_BUTTON_3)
{
  toggleState_3 = param.asInt();
  digitalWrite(RelayPin3, toggleState_3 ? LOW : HIGH);
}

BLYNK_WRITE(VPIN_BUTTON_4)
{
  toggleState_4 = param.asInt();
  digitalWrite(RelayPin4, toggleState_4 ? LOW : HIGH);
}

// Manual control function
void manual_control()
{
  if (digitalRead(SwitchPin1) == LOW && SwitchState_1 == LOW)
  {
    toggleState_1 = HIGH;
    digitalWrite(RelayPin1, LOW);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_1, HIGH);
    SwitchState_1 = HIGH;
    Serial.println("Switch-1 on");
  }
  else if (digitalRead(SwitchPin1) == HIGH && SwitchState_1 == HIGH)
  {
    toggleState_1 = LOW;
    digitalWrite(RelayPin1, HIGH);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_1, LOW);
    SwitchState_1 = LOW;
    Serial.println("Switch-1 off");
  }

  if (digitalRead(SwitchPin2) == LOW && SwitchState_2 == LOW)
  {
    toggleState_2 = HIGH;
    digitalWrite(RelayPin2, LOW);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_2, HIGH);
    SwitchState_2 = HIGH;
    Serial.println("Switch-2 on");
  }
  else if (digitalRead(SwitchPin2) == HIGH && SwitchState_2 == HIGH)
  {
    toggleState_2 = LOW;
    digitalWrite(RelayPin2, HIGH);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_2, LOW);
    SwitchState_2 = LOW;
    Serial.println("Switch-2 off");
  }

  if (digitalRead(SwitchPin3) == LOW && SwitchState_3 == LOW)
  {
    toggleState_3 = HIGH;
    digitalWrite(RelayPin3, LOW);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_3, HIGH);
    SwitchState_3 = HIGH;
    Serial.println("Switch-3 on");
  }
  else if (digitalRead(SwitchPin3) == HIGH && SwitchState_3 == HIGH)
  {
    toggleState_3 = LOW;
    digitalWrite(RelayPin3, HIGH);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_3, LOW);
    SwitchState_3 = LOW;
    Serial.println("Switch-3 off");
  }

  if (digitalRead(SwitchPin4) == LOW && SwitchState_4 == LOW)
  {
    toggleState_4 = HIGH;
    digitalWrite(RelayPin4, LOW);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_4, HIGH);
    SwitchState_4 = HIGH;
    Serial.println("Switch-4 on");
  }
  else if (digitalRead(SwitchPin4) == HIGH && SwitchState_4 == HIGH)
  {
    toggleState_4 = LOW;
    digitalWrite(RelayPin4, HIGH);
    if (Blynk.connected())
      Blynk.virtualWrite(VPIN_BUTTON_4, LOW);
    SwitchState_4 = LOW;
    Serial.println("Switch-4 off");
  }
}

void ledCon()
{
  digitalWrite(16, LOW);
  delay(100);
  digitalWrite(16, HIGH);
  delay(100);
}

// Function to sync relay states with Blynk cloud
void syncRelayStates()
{
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);
  Blynk.syncVirtual(VPIN_BUTTON_4);
}

// Web server function to control relays
void handleRoot()
{
  String html = "<!DOCTYPE html>";
  html += "<html lang=\"en\">";
  html += "<head>";
  html += "<meta charset=\"UTF-8\">";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Home Automation | anbuinfosec</title>";
  html += "<link href=\"https://www.plumsteadrunners.co.uk/css/styles.css\" rel=\"stylesheet\" media=\"all\">";
  html += "<link href=\"https://www.plumsteadrunners.co.uk/bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\">";
  html += "<link href=\"https://www.plumsteadrunners.co.uk/bootstrap/css/style.css\" rel=\"stylesheet\">";
  html += "<link href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css\" rel=\"stylesheet\">";
  html += "<style>";
  html += "@import url('https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&display=swap');";
  html += "* {";
  html += "box-sizing: border-box;";
  html += "margin: 0;";
  html += "padding: 0;";
  html += "font-family: 'Poppins', sans-serif;";
  html += "}";
  html += "body {";
  html += "background: linear-gradient(-45deg, #ee7752, #e73c7e, #23a6d5, #23d5ab);";
  html += "background-size: 400% 400%;";
  html += "animation: gradient 15s ease infinite;";
  html += "height: 100vh;";
  html += "}";
  html += "@keyframes gradient {";
  html += "0% {";
  html += "background-position: 0% 50%;";
  html += "}";
  html += "50% {";
  html += "background-position: 100% 50%;";
  html += "}";
  html += "100% {";
  html += "background-position: 0% 50%;";
  html += "}";
  html += "}";
  html += ".container {";
  html += "display: flex;";
  html += "justify-content: center;";
  html += "align-items: center;";
  html += "width: 100%;";
  html += "height: 100%;";
  html += "}";
  html += ".glass-card {";
  html += "background: rgba(255, 255, 255, 0.15);";
  html += "border-radius: 15px;";
  html += "padding: 20px;";
  html += "width: 350px;";
  html += "backdrop-filter: blur(10px);";
  html += "-webkit-backdrop-filter: blur(10px);";
  html += "box-shadow: 0 4px 30px rgba(0, 0, 0, 0.1);";
  html += "border: 1px solid rgba(255, 255, 255, 0.3);";
  html += "}";
  html += ".card-header {";
  html += "display: flex;";
  html += "justify-content: flex-end;";
  html += "gap: 10px;";
  html += "margin-bottom: 20px;";
  html += "}";
  html += ".control-btn {";
  html += "width: 12px;";
  html += "height: 12px;";
  html += "border-radius: 50%;";
  html += "background: #ff5f56;";
  html += "cursor: pointer;";
  html += "}";
  html += ".control-btn.maximize {";
  html += "background: #ffbd2e;";
  html += "}";
  html += ".control-btn.minimize {";
  html += "background: #27c93f;";
  html += "}";
  html += ".card-content h1 {";
  html += "text-align: center;";
  html += "font-weight: 600;";
  html += "margin-bottom: 10px;";
  html += "}";
  html += ".card-content p {";
  html += "text-align: center;";
  html += "margin-bottom: 30px;";
  html += "}";
  html += ".button-container {";
  html += "display: flex;";
  html += "flex-direction: column;";
  html += "gap: 20px;";
  html += "text-align: center; /* Center align buttons */";
  html += "}";
  html += ".cool-button {";
  html += "position: relative;";
  html += "display: inline-block;";
  html += "padding: 15px 30px;";
  html += "font-size: 16px;";
  html += "text-transform: uppercase;";
  html += "color: #fff;";
  html += "border: none;";
  html += "outline: none;";
  html += "cursor: pointer;";
  html += "border-radius: 10px;";
  html += "overflow: hidden;";
  html += "transition: 0.5s;";
  html += "font-weight: 600;";
  html += "box-shadow: 0 0 15px rgba(255, 255, 255, 0.1);";
  html += "}";
  html += ".cool-button::before,";
  html += ".cool-button::after {";
  html += "content: '';";
  html += "position: absolute;";
  html += "top: -50%;";
  html += "left: -50%;";
  html += "width: 200%;";
  html += "height: 200%;";
  html += "transition: 0.5s;";
  html += "mix-blend-mode: overlay;";
  html += "}";
  html += ".cool-button:hover::before,";
  html += ".cool-button:hover::after {";
  html += "top: 0;";
  html += "left: 0;";
  html += "width: 100%;";
  html += "height: 100%;";
  html += "}";
  html += ".cool-button::after {";
  html += "opacity: 0;";
  html += "transition: opacity 0.5s;";
  html += "}";
  html += ".cool-button:hover::after {";
  html += "opacity: 1;";
  html += "animation: shimmer 2s infinite;";
  html += "}";
  html += "@keyframes shimmer {";
  html += "0% {";
  html += "background-position: -200% -200%;";
  html += "}";
  html += "100% {";
  html += "background-position: 200% 200%;";
  html += "}";
  html += "}";
  html += ".cool-button:hover {";
  html += "box-shadow: 0 0 15px rgba(255, 255, 255, 0.7), 0 0 25px rgba(255, 255, 255, 0.5), 0 0 35px rgba(255, 255, 255, 0.3);";
  html += "animation: glow 1.5s infinite alternate;";
  html += "}";
  html += "@keyframes glow {";
  html += "0% {";
  html += "box-shadow: 0 0 15px rgba(255, 255, 255, 0.7), 0 0 25px rgba(255, 255, 255, 0.5), 0 0 35px rgba(255, 255, 255, 0.3);";
  html += "}";
  html += "100% {";
  html += "box-shadow: 0 0 30px rgba(255, 255, 255, 1), 0 0 50px rgba(255, 255, 255, 0.7), 0 0 70px rgba(255, 255, 255, 0.5);";
  html += "}";
  html += "}";
  html += ".btn {";
  html += "background: linear-gradient(135deg, #ff512f 0%, #dd2476 100%);";
  html += "animation: gradient 3s infinite alternate;";
  html += "}";
  html += ".btn::before {";
  html += "background: linear-gradient(135deg, #ff512f 0%, #dd2476 100%);";
  html += "clip-path: polygon(0 0, 100% 0, 50% 50%);";
  html += "}";
  html += ".btn::after {";
  html += "background: linear-gradient(135deg, #dd2476 0%, #ff512f 100%);";
  html += "clip-path: polygon(50% 50%, 100% 100%, 0 100%);";
  html += "}";
  html += "@keyframes gradient {";
  html += "0% {";
  html += "background-position: 0% 50%;";
  html += "}";
  html += "100% {";
  html += "background-position: 100% 50%;";
  html += "}";
  html += "}";
  html += "footer {";
  html += "background-color: #222;";
  html += "color: #777;";
  html += "padding: 44px 0 0;";
  html += "}";
  html += ".social-icons {";
  html += "text-align: right;";
  html += "padding-left: 0;";
  html += "margin-bottom: 0;";
  html += "list-style: none;";
  html += "}";
  html += ".social-icons li {";
  html += "display: inline-block;";
  html += "margin-bottom: 12px;";
  html += "}";
  html += ".social-icons a {";
  html += "width: 44px;";
  html += "height: 44px;";
  html += "line-height: 44px;";
  html += "margin: 0 auto 0 auto;";
  html += "border-radius: 50%;";
  html += "background-color: #33353d;";
  html += "display: inline-block;";
  html += "text-align: center;";
  html += "font-size: 24px;";
  html += "color: #818a91;";
  html += "transition: all .2s linear;";
  html += "}";
  html += ".social-icons a:active,";
  html += ".social-icons a:focus,";
  html += ".social-icons a:hover {";
  html += "color: #fff;";
  html += "background-color: #29aafe;";
  html += "}";
  html += ".social-icons a.instagram:hover {";
  html += "background-color: #f00077;";
  html += "}";
  html += "</style>";
  html += "</head>";
  html += "<body>";
  html += "<div class=\"container\">";
  html += "<div class=\"glass-card\">";
  html += "<div class=\"card-header\">";
  html += "<div class=\"control-btn close\"></div>";
  html += "<div class=\"control-btn maximize\"></div>";
  html += "<div class=\"control-btn minimize\"></div>";
  html += "</div>";
  html += "<div class=\"card-content\">";
  html += "<h1>Welcome to control panel!</h1>";
  html += "<p>Control your project from here!<br>Developer:- Mohammad Alamin</p>";
  html += "<p>Access IP: " + WiFi.localIP().toString() + "</p>";
  html += "<p id=\"time\"></p>";
  html += "<div style=\"-ms-flex-item-align:center;\" class=\"button-container\">";
  html += "<form action=\"/relay1\" method=\"POST\"><button type=\"submit\" class=\"cool-button btn\">";
  html += toggleState_1 ? "Turn Off Relay 1" : "Turn On Relay 1";
  html += "</button></form>";
  html += "<form action=\"/relay2\" method=\"POST\"><button type=\"submit\" class=\"cool-button btn\">";
  html += toggleState_2 ? "Turn Off Relay 2" : "Turn On Relay 2";
  html += "</button></form>";
  html += "<form action=\"/relay3\" method=\"POST\"><button type=\"submit\" class=\"cool-button btn\">";
  html += toggleState_3 ? "Turn Off Relay 3" : "Turn On Relay 3";
  html += "</button></form>";
  html += "<form action=\"/relay4\" method=\"POST\"><button type=\"submit\" class=\"cool-button btn\">";
  html += toggleState_4 ? "Turn Off Relay 4" : "Turn On Relay 4";
  html += "</button></form>";
  html += "</div>";
  html += "</div>";
  html += "</div>";
  html += "</div>";
  html += "<footer id=\"footerWrapper\" class=\"footer5\">";
  html += "<div class=\"container\">";
  html += "<div class=\"row\">";
  html += "<div class=\"col-md-6\">";
  html += "<p class=\"copyright\">Copyright © 2024 <a href=\"https://anbuinfosec.xyz\">anbuinfosec.</a></p>";
  html += "</div>";
  html += "<div class=\"col-md-6\">";
  html += "<ul class=\"social-icons\">";
  html += "<li><span><a class=\"facebook\" href=\"https://facebook.com/anbuinfosec\" title=\"Follow me on Facebook\"><i class=\"fa fa-facebook\"></i></a></span></li>";
  html += "<li><span><a class=\"twitter\" href=\"https://github.com/anbuinfosec\" title=\"Follow me on Github\"><i class=\"fa fa-github\"></i></a></span></li>";
  html += "<li><span><a class=\"instagram\" href=\"https://instagram.com/anbuinfosec\" title=\"Follow me on Instagram\"><i class=\"fa fa-instagram\"></i></a></span></li>";
  html += "</ul>";
  html += "</div>";
  html += "</div>";
  html += "</div>";
  html += "</footer>";
  html += "<script>";
  html += "function updateTime() {";
  html += "var options = { timeZone: 'Asia/Dhaka', hour: '2-digit', minute: '2-digit', second: '2-digit' };";
  html += "var formatter = new Intl.DateTimeFormat([], options);";
  html += "document.getElementById('time').innerHTML = 'Current Time: ' + formatter.format(new Date());";
  html += "}";
  html += "setInterval(updateTime, 1000);";
  html += "updateTime();";
  html += "</script>";
  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}


void handleRelay1()
{
  toggleState_1 = !toggleState_1;
  digitalWrite(RelayPin1, toggleState_1 ? LOW : HIGH);
  if (Blynk.connected())
  {
    Blynk.virtualWrite(VPIN_BUTTON_1, toggleState_1 ? HIGH : LOW);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay2()
{
  toggleState_2 = !toggleState_2;
  digitalWrite(RelayPin2, toggleState_2 ? LOW : HIGH);
  if (Blynk.connected())
  {
    Blynk.virtualWrite(VPIN_BUTTON_2, toggleState_2 ? HIGH : LOW);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay3()
{
  toggleState_3 = !toggleState_3;
  digitalWrite(RelayPin3, toggleState_3 ? LOW : HIGH);
  if (Blynk.connected())
  {
    Blynk.virtualWrite(VPIN_BUTTON_3, toggleState_3 ? HIGH : LOW);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay4()
{
  toggleState_4 = !toggleState_4;
  digitalWrite(RelayPin4, toggleState_4 ? LOW : HIGH);
  if (Blynk.connected())
  {
    Blynk.virtualWrite(VPIN_BUTTON_4, toggleState_4 ? HIGH : LOW);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Starting Home Automation....");
  Serial.println("Made By @anbuinfosec");

  // Set pin modes
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  // Initialize relays to off state
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);

  // Setup a timer to read manual inputs
  timer.setInterval(100L, manual_control);

  // Connect to WiFi with retry logic
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, pass);

  // Wait for connection with retry logic
  int retryCount = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retryCount++;

    // Retry every 10 seconds
    if (retryCount >= 20) {
      Serial.println("Retrying WiFi connection...");
      WiFi.begin(ssid, pass);
      retryCount = 0;
    }
  }

  Serial.println("Connected to WiFi");

  // Non-blocking attempt to connect to Blynk
  Blynk.config(BLYNK_AUTH_TOKEN);

  // Setup a timer to periodically attempt to connect to Blynk
  timer.setInterval(10000L, []() {
    if (WiFi.status() == WL_CONNECTED && !Blynk.connected()) {
      Blynk.connect();
      if (Blynk.connected()) {
        Serial.println("Blynk connected");
        syncRelayStates();
      }
    }
  });

  // Setup access point and web server
  WiFi.softAP(ssidName, ssidPwd);
  server.on("/", handleRoot);
  server.on("/relay1", HTTP_POST, handleRelay1);
  server.on("/relay2", HTTP_POST, handleRelay2);
  server.on("/relay3", HTTP_POST, handleRelay3);
  server.on("/relay4", HTTP_POST, handleRelay4);
  server.begin();
  Serial.println("Access point started");
  Serial.print("Connect to the SSID: ");
  Serial.println(ssidName);
  Serial.println("Access the web interface at IP: 192.168.4.1");
}


void loop()
{
  // Run Blynk process if connected
  if (Blynk.connected())
  {
    Blynk.run();
  }

  // Run the timer for manual control
  timer.run();

  // Handle client requests to the web server
  server.handleClient();

  // Blink the LED to show the device is running
  ledCon();
}