# Set metadata to a device

>When using the ConnectIoT project you'll want your devices to have certain metadata. With this method you can set metadata to a device.    
---
## How do I set metadata to a device?
By including the ConnectIoT.h file to your C++/ino script you can set metdata to an existing device using the setDeviceMetadata method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before setting metadata to a device make sure that the device exists.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.setDeviceMetadata(registry_name, device_name, {
                'date': '01/01/1999', 'battery': '88%', 'Mod': 'DHT11'})
```

## setDeviceMetadata Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |bool        
|device_name : String |                The device you want to set data to|
|metadata : String|The data you want to set to the device|

```cpp
bool ConnectIoT::setDeviceMetadata(
    const char *registryName,
    const char *deviceName,
    DynamicJsonDocument &metadata)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["metadata"] = metadata;
  response = this->callMethodApi(
      "set_device_metadata", req);
  return (bool)response["data"];
}

bool ConnectIoT::setDeviceMetadata(
    const String &registryName,
    const String &deviceName,
    DynamicJsonDocument &metadata)
{
  return setDeviceMetadata(registryName.c_str(), deviceName.c_str(), metadata);
}

```