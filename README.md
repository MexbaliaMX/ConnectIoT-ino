# ConnectIoT-ino


<center>

![Arq,use](assets/images/ConnectIoTino.png)

</center>

> ### Library to connect Arduino projects to the ConnectIoT project in the NEAR Protocol Blockchain using the ConnectIoT-API.


## Overview

*This library contains the ConnectIoT class that will help you build the strucutre for using the ConnectIoT smart contract by calling the ConnectIoT-API.*

_Click on a route for more information and examples_


| Route                                      | Method | Description                                                                                                                 |
| ------------------------------------------ | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| **CONNECTIOT PYTHON LIB**                   |        |     All methods recive a response from the **callMethodApi**                                                                                                                        |
| [`callMethodApi`](https://github.com/paul-cruz/ConnectIoT-API#call)                           | POST   | Performs a call to the ConnectIoT API, validating the Near Account ID, params & method.                                                           |
|[`createRegistry`](https://github.com/paul-cruz/Connect-IoT#dcreate_registry)                           | POST   | Method to create a registry in the contract. It communicates with the **create_resgistry** function from ConnectIoT's smart contract.|
[`deleteRegistry`](https://github.com/paul-cruz/Connect-IoT#delete_registry)                           | POST   | Method to delete a registry in the contract. It communicates with the **delete_resgistry** function from ConnectIoT's smart contract.|
[`addDeviceToRegistry`](https://github.com/paul-cruz/Connect-IoT#add_device_to_registry)                           | POST   | Method to add a device into a registry. It communicates with the **add_device_to_resgistry** function from ConnectIoT's smart contract.|
[`deleteDeviceFromRegistry`](https://github.com/paul-cruz/Connect-IoT#delete_device_to_registry)                           | POST   | Method to delete a device from a registry. It communicates with the **delete_device_from_resgistry** function from ConnectIoT's smart contract.|
[`setDeviceData`](https://github.com/paul-cruz/Connect-IoT#set_device_data)                           | POST   | Method to set data to a device. It communicates with the **set_device_data** function from ConnectIoT's smart contract.|
[`getDeviceData`](https://github.com/paul-cruz/Connect-IoT#get_device_data)                           | POST   | Method to get data from a device. It communicates with the **get_device_data** function from ConnectIoT's smart contract.|
[`setDeviceMetadata`](https://github.com/paul-cruz/Connect-IoT#set_device_metadata)                           | POST   | Method to set a device metadata. It communicates with the **set_device_metadata** function from ConnectIoT's smart contract.|
[`getDeviceMetadata`](https://github.com/paul-cruz/Connect-IoT#get_device_metadata)                           | POST   | Method to get a device metadata. It communicates with the **get_device_metadata** function from ConnectIoT's smart contract.|
[`setDeviceDataParam`](https://github.com/paul-cruz/Connect-IoT#set_device_data_param)                           | POST   | Method for setting a parameter to a device data. It communicates with the **set_device_data_param** function from ConnectIoT's smart contract.|
[`getDeviceDataParam`](https://github.com/paul-cruz/Connect-IoT#get_device_data_param)                           | POST   | Method for getting a parameter from a device data. It communicates with the **get_device_data_param** function from ConnectIoT's smart contract.|
[`setDeviceMetadataParam`](https://github.com/paul-cruz/Connect-IoT#set_device_metadata_param)                           | POST   | Method for setting a parameter from a device metadata. It communicates with the **set_device_metadata_param** function from ConnectIoT's smart contract.|
[`getDeviceMetadataParam`](https://github.com/paul-cruz/Connect-IoT#get_device_metadata_param)                           | POST   | Method for getting a parameter from a device metadata. It communicates with the **get_device_metadata_param** function from ConnectIoT's smart contract.|

---
## Requirements

- [NEAR Account](https://docs.near.org/concepts/basics/account) _(with access to private key or seed phrase)_
- [ConnectIoT-API](https://github.com/paul-cruz/ConnectIoT-API.git) (*This allows you to connect with the ConnectIoT smart contract for example an ip with its port*)


---
## Credits
<center>

>
  [![Logo Mexbalia](assets/images/Screenshot%20from%202022-08-10%2010-41-59.png)](https://mexbalia.com/)

  </center>

---

## Support

Reach out via [website](https://mexbalia.com/contact/) or send an email to [info@mexbalia.com](https://google.com)
