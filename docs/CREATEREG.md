# Create a registry

>When using the ConnectIoT project you'll be required to create a registry for each group of devices you want to administrate.

---
## How do I create a new registry?
By including the ConnectIoT.h file to your C++/ino script you can create a registry using the createRegistry method. You will have to get and validate the server address, the Near account ID, the Near private key, the SSID and password from secrets.h file.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.createRegistry("registryName");
```

---
## createRegistry Method
|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                 | The name of the registry you want to create  |bool                                                                                                                                
```cpp
bool ConnectIoT::createRegistry(const char *registryName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  response = this->callMethodApi(
      "create_registry", req);
  return response["data"];
}

bool ConnectIoT::createRegistry(const String &registryName)
{
  return createRegistry(registryName.c_str());
}
```