# Set a data parameter to a device

>When using the ConnectIoT project you'll have devices taking in data with specific parameters so with this method you will be able to register those parameters individualy.
---
## How do I set a data param with its value?
By including the ConnectIoT.h file to your C++/ino script you can set a single data parameter with its value to an existing device using the setDeviceDataParam method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before setting a data param to a device make sure that the device exists. Remeber that this method is only for single param/value setting.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.setDeviceDataParam("registryName", "deviceName", "my_param","my_value");

```
## ssetDeviceDataParam Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |bool        
|device_name : String |                The device you want to set data to|
|param : String| The key you want to set for the new param in the device data|
|value : String|The value you want to set for the new param in the device data|

```cpp
bool ConnectIoT::setDeviceDataParam(
    const char *registryName,
    const char *deviceName,
    const char *param,
    const char *value)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["param"] = param;
  req["value"] = value;
  response = this->callMethodApi(
      "set_device_data_param", req);
  return response["data"];
}

bool ConnectIoT::setDeviceDataParam(
    const String &registryName,
    const String &deviceName,
    const String &param,
    const String &value)
{
  return setDeviceDataParam(registryName.c_str(), deviceName.c_str(), param.c_str(), value.c_str());
}

```