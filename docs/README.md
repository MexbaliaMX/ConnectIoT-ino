# ConnectIoT C++ Library

>This library is designed for connecting the ConnectIoT smart contract project with C++ scripts.


## Features

- [Create](#overview)/[Delete](#overview) a registry 
- [Add](#overview)/[Delete](#overview) a device to registry
- [Set](#overview)/[Get](#overview) device data
- [Set](#overview)/[Get](#overview) device metadata
- [Set](#overview)/[Get](#overview) device data parmeters
- [Set](#overview)/[Get](#overview) device metadata parmeters

## What can you do with this library?
With this library you can create any IoT device C++ script and use the ConnectIoT smart contract in the Near Protocol blockchain to keep control of your IoT devices and their state using data and metadata fields.

---


## Overview

| Method                                     |Description   ||                                                                                                              
 ------------------------------------------ | ------ |--------------------------------------------------------------------------------------------------------------------------- |
| **CONNECTIOT C++ LIB**                   |             All methods recive a response from the **_call_method_api**                                                                                                                        |                                                          |
|[`Create registry`](CREATEREG.md#create-a-registry)         | Method to create a registry in the contract. It communicates with the [*create_resgistry*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Delete registry`](DELETEREG.md#delete-a-registry)                           |Method to delete a registry in the contract. It communicates with the [*delete_resgistry*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Add device to registry`](ADDDEVICE.md#add-device-to-registry)                           | Method to add a device into a registry. It communicates with the [*add_device_to_resgistry*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Delete device from registry`](DELDEVICE.md#delete-a-device-from-a-registry)                           | Method to delete a device from a registry. It communicates with the [*delete_device_from_resgistry*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Set device data`](SETDEVDATA.md#set-data-to-a-device)                           | Method to set data to a device. It communicates with the [*set_device_data*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Get device data`](GETDEVDATA.md#get-data-from-device)                           |Method to get data from a device. It communicates with the [*get_device_data*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Set device metadata`](SETDEVMET.md#set-metadata-to-a-device)                           | Method to set a device metadata. It communicates with the [*set_device_metadata*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Get device metadata`](GETDEVMET.md#get-metadata-from-a-device)                           |Method to get a device metadata. It communicates with the [*get_device_metadata*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Set device data param`](SETDATPARM.md#set-a-data-parameter-to-a-device)                           |Method for setting a parameter to a device data. It communicates with the [*set_device_data_param*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Get device data param`](GETDATPARM.md#get-a-device-data-parameter-value)                           |Method to get a parameter from a device data. It communicates with the [*get_device_data_param*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Set device metadata param`](SETMETPARM.md#set-a-metadata-paramater-to-a-device)                           |Method for setting a parameter from a device metadata. It communicates with the [*set_device_metadata_param*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|
[`Get device metadata param`](GETMETPARM.md#get-a-metadata-parameter-value-from-a-device)                           |Method for getting a parameter from a device metadata. It communicates with the [*get_device_metadata_param*](https://github.com/paul-cruz/Connect-IoT) function from ConnectIoT's smart contract.|

