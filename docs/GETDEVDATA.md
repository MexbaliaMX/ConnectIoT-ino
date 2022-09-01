# Get data from device

>When using the ConnectIoT project you'll have devices taking in data so with this method you will be able to get and see that data.
---
## How do I get data from a device?

By including the ConnectIoT.h file to your C++/ino script you can get data from an existing device using the getDeviceData method. You will have to get and validate the Near contract url, the Near account ID and the private key. Before getting data from a device make sure that the registry and device exist.

```cpp
#include <WiFiNINA.h>
#include <ConnectIoT.h>
#include "secrets.h"

ConnectIoT contract = ConnectIoT(wifi, serverAddress, port, nearAccountId, nearPrivateKey);

print(contract.getDeviceData("registryName", "deviceName"));
```

## getDeviceData Method

|Parameter                                     |Description|Method Return                                                        |                                                      
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| registry_name : String                  | The name of the registry that stores the device  |Dict        
|device_name : String |                The name of the device you want to delete|

```py
def get_device_data(self,
                        registry_name: str,
                        device_name: str) -> dict:
        response = self.__call_method_api(
            'get_device_data', {
                'registry_name': registry_name,
                'device_name': device_name
            })
        if response.status_code != 200:
            return None
        return response.json()

```