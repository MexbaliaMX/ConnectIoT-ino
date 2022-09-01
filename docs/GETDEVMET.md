# Get metadata from a device

>When using the ConnectIoT project you'll have devices taking in metadata so with this method you will be able to get and see that metadata.
---
## How do I get a device's metadata?

By including the ConnectIoT.h file to your C++/ino script you can get metadata from an existing device using the get_device_data method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before getting metadata from a device make sure that the device exists.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

print(contract.getDeviceMetadata("registryName", "deviceName"));
```
## getDeviceMetadata Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |JSON        
|device_name : String |                The name of the device you want to delete|

```cpp
DynamicJsonDocument &ConnectIoT::getDeviceMetadata(
    const char *registryName,
    const char *deviceName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  response = this->callMethodApi(
      "get_device_metadata", req);
  return response;
}

DynamicJsonDocument &ConnectIoT::getDeviceMetadata(
    const String &registryName,
    const String &deviceName)
{
  return getDeviceMetadata(registryName.c_str(), deviceName.c_str());
}
```