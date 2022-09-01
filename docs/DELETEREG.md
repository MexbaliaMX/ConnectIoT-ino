# Delete a registry

>When using the ConnectIoT project you'll probably need to delete an entire registry from the contract.

---
## How do I delete a registry?
By including the ConnectIoT.h file to your C++/ino script you can delete a registry using the deleteRegistry method. You will have to get and validate the server address, the Near account ID, the Near private key, the SSID and password from secrets.h file. Before deleting make sure that the registry is empty, this means there are no devices registered.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

contract.deleteRegistry("registryName");
```

---
## deleteRegistry Method
|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry you want to delete  |bool                                                                                                                                
```cpp
bool ConnectIoT::deleteRegistry(const char *registryName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  response = this->callMethodApi(
      "delete_registry", req);
  return response["data"];
}

bool ConnectIoT::deleteRegistry(const String &registryName)
{
  return deleteRegistry(registryName.c_str());
}
```