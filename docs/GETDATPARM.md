# Get a device data parameter value
>When using the ConnectIoT project you'll have devices taking in data parameters with values so with this method you will be able to get and see those parameters values individualy.
---
## How do I get a data parameter value?
By including the ConnectIoT.h file to your C++/ino script you can get a single data parameter value from an existing device using the getDeviceDataParam method. You will have to get and validate the server address, the Near account ID, the Near private key, the SSID and password from secrets.h file. Before getting a data param value from a device make sure that the device and the parameter exist. Remeber that this method is only for single param/value getting.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

print(contract.getDeviceDataParam("registryName", "deviceName", "my_param"));
```
## getDeviceDataParam Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |String        
|device_name : String |                The device you want to set data to|
|param : String| The key you want to get from a device data param|


```cpp
String ConnectIoT::getDeviceDataParam(
    const char *registryName,
    const char *deviceName,
    const char *param)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["param"] = param;
  response = this->callMethodApi(
      "get_device_data_param", req);
  return response["data"];
}

String ConnectIoT::getDeviceDataParam(
    const String &registryName,
    const String &deviceName,
    const String &param)
{
  return getDeviceDataParam(registryName.c_str(), deviceName.c_str(), param.c_str());
}
```