# Set a metadata paramater to a device
>When using the ConnectIoT project you'll have devices taking in metadata with specific parameters and values so with this method you will be able to register those parameters and values individualy.
---
## How do I set a data param with its value?
By importing the ConnectIoT class to your Python script you can set a single metadata parameter with its value to an existing device using the setDeviceMetadataParam method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before setting a metadata param to a device make sure that the device exists. Remeber that this method is only for single param/value setting.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);


contract.setDeviceMetadataParam('registry_name', 'device_name', 'my_param', 'my_value')

```
## setDeviceMetadataParam Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |bool        
|device_name : String |                The device you want to set data to|
|param : String| The key you want to set for the new param in the device metadata|
|value : String|The value you want to set for the new param in the device metadata|

```cpp
bool ConnectIoT::setDeviceMetadataParam(
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
      "set_device_metadata_param", req);
  return response["data"];
}

bool ConnectIoT::setDeviceMetadataParam(
    const String &registryName,
    const String &deviceName,
    const String &param,
    const String &value)
{
  return setDeviceMetadataParam(registryName.c_str(), deviceName.c_str(), param.c_str(), value.c_str());
}

```