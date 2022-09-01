# Add Device To Registry

>When using the ConnectIoT project you'll have to add devices to your registries.

---

## How do I add a device to a registry?
By including the ConnectIoT.h file to your C++/ino script you can add a device to a registry using the addDeviceToRegistry method. You will have to get and validate the server address, the Near account ID, the Near private key, the SSID and password from secrets.h file. Before adding a device make sure that the registry exists.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.addDeviceToRegistry(
        "registryName", "deviceName", "Device for Arduiuno lib test.");
    
```
---
## addDeviceToRegistry Method
|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that will store your device  |bool        
|device_name : String |                The name of the device you want to create|
|description : String|      The description you want to give to the device |                                                                              
```cpp
bool ConnectIoT::addDeviceToRegistry(
    const char *registryName,
    const char *deviceName,
    const char *description)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["description"] = description;
  response = this->callMethodApi(
      "add_device_to_registry", req);
  return response["data"];
}

bool ConnectIoT::addDeviceToRegistry(
    const String &registryName,
    const String &deviceName,
    const String &description)
{
  return addDeviceToRegistry(registryName.c_str(), deviceName.c_str(), description.c_str());
}

```