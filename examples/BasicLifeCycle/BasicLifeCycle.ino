#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char serverAddress[] = SERVER_ADDR;
char nearPrivateKey[] = NEAR_PRIVATE_KEY;
char nearAccountId[] = NEAR_ACCOUNT_ID;
uint16_t port = SERVER_PORT;

WiFiClient wifi;
ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);
int status = WL_IDLE_STATUS;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }

  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println("Communication with WiFi module failed!");
    while (true)
      ;
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println("Please upgrade the firmware");
  }

  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  Serial.println("Connected to WiFi");
}

void loop()
{
  Serial.println("Sending request...");
  doTask();
  delay(30000);
}

void doTask()
{
  String registryName = "myNewRegistry585280752075250";
  String deviceName = "myNewDevice7052508502502752";
  if (contract.createRegistry(registryName))
  {
    bool newDevice = contract.addDeviceToRegistry(
        registryName, deviceName, "Device for Arduiuno lib test.");
    if (newDevice)
    {
      DynamicJsonDocument req(1024);
      req["value1"] = true;
      req["value2"] = 1;
      req["value3"] = "My value";
      contract.setDeviceData(registryName, deviceName, req);
      req.clear();
      Serial.println(contract.getDeviceDataParam(registryName, deviceName, "value3"));
    }else{
      Serial.println("Failed to create the device");
    }
  }else{
    Serial.println("Failed to create the registry");
  }

  if (contract.deleteDeviceFromRegistry(registryName, deviceName))
  {
    contract.deleteRegistry(registryName);
    Serial.println("Cleaned up");
  }else{
    Serial.println("Failed to delete the registry");
  }
}
