# Delete a device from a registry

>When using the ConnectIoT project you'll probably have to delete certain devices from your registries.
---
## How do I delete a device from a registry?
By including the ConnectIoT.h file to your C++/ino script you can delete a registry using the deleteDeviceFromRegistry method. You will have to get and validate the server address, the Near account ID, the Near private key, the SSID and password from secrets.h file. Before deleting a device make sure that both registry and device exist.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.deleteDeviceFromRegistry("registryName", "deviceName");
```
## deleteDeviceFromRegistry Method
|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |bool        
|device_name : String |                The name of the device you want to delete|

```cpp
bool ConnectIoT::deleteDeviceFromRegistry(
    const char *registryName,
    const char *deviceName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  response = this->callMethodApi(
      "delete_device_from_registry", req);
  return response["data"];
}

bool ConnectIoT::deleteDeviceFromRegistry(
    const String &registryName,
    const String &deviceName)
{
  return deleteDeviceFromRegistry(registryName.c_str(), deviceName.c_str());
}
```
