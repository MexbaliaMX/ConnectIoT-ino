# Set data to a device

>When using the ConnectIoT project you'll have devices taking in data so with this method you will be able to register that data.
---
## How do I set data to a device?
By including the ConnectIoT.h file to your C++/ino script you can set data to an existing device using the setDeviceData method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before setting data to a device make sure that the device exists.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.setDeviceData("registryName", "deviceName", {
                'value1': 1, 'value2': 3.5, 'value3': 'foobar'});

```

## setDeviceData Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |bool        
|device_name : String |                The device you want to set data to|
|data : String|The data you want to set to the device|

```cpp
bool ConnectIoT::setDeviceData(
    const char *registryName,
    const char *deviceName,
    DynamicJsonDocument &data)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["data"] = data;
  response = this->callMethodApi(
      "set_device_data", req);
  return (bool)response["data"];
}

bool ConnectIoT::setDeviceData(
    const String &registryName,
    const String &deviceName,
    DynamicJsonDocument &data)
{
  return setDeviceData(registryName.c_str(), deviceName.c_str(), data);
}

```