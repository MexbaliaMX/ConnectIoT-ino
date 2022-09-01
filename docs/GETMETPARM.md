# Get a metadata parameter value from a device

>When using the ConnectIoT project you'll have devices taking in metadata parameters with their values so with this method you will be able to get and see those metadata parameters values individualy.
---
## How do I get a metadata parameter value?
By including the ConnectIoT.h file to your C++/ino script you can get a single metadata parameter value from an existing device using the getDeviceMetadataParam method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before getting a metadata param value from a device make sure that the device and the parameter exist. Remeber that this method is only for single param/value getting.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.getDeviceMetadataParam("registryName", "deviceName", "my_param");
```
## getDeviceMetadataParam Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                   | The name of the registry that stores the device  |String       
|device_name : String  |                The device you want to set data to|
|param : String | The key you want to get from a device metadata param|


```cpp
String ConnectIoT::getDeviceMetadataParam(
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
      "get_device_metadata_param", req);
  return response["data"];
}

String ConnectIoT::getDeviceMetadataParam(
    const String &registryName,
    const String &deviceName,
    const String &param)
{
  return getDeviceMetadataParam(registryName.c_str(), deviceName.c_str(), param.c_str());
}
```