#include "ConnectIoT.h"

ConnectIoT::ConnectIoT(
    WiFiClient &wifi,
    const char *serverAddress,
    uint16_t port,
    const char *nearAccountId,
    const char *nearAccountPrivateKey)
{
  this->wifiClient = &wifi;
  this->serverPort = port;
  this->serverAddress = serverAddress;
  this->nearAccountId = nearAccountId;
  this->nearAccountPrivateKey = nearAccountPrivateKey;
}

ConnectIoT::ConnectIoT(
    WiFiClient &wifi,
    const String &serverAddress,
    uint16_t port,
    const String &nearAccountId,
    const String &nearAccountPrivateKey)
    : ConnectIoT(wifi, serverAddress.c_str(), port, nearAccountId.c_str(), nearAccountPrivateKey.c_str())
{
}

DynamicJsonDocument ConnectIoT::callMethodApi(
    const String &methodName,
    DynamicJsonDocument &params)
{
  HttpClient client = HttpClient(*this->wifiClient, this->serverAddress, this->serverPort);
  DynamicJsonDocument req(2048);
  req["account_id"] = this->nearAccountId;
  req["method"] = methodName;
  req["params"] = params;

  String jsonstringify = "";
  serializeJson(req, jsonstringify);
  String authHeader = "Bearer ";
  authHeader.concat(this->nearAccountPrivateKey);
  client.beginRequest();
  client.post("/call");
  client.sendHeader("Content-Type", "application/json; charset=utf-8");
  client.sendHeader("Content-Length", jsonstringify.length());
  client.sendHeader("Authorization", authHeader);
  client.beginBody();
  client.print(jsonstringify);
  client.endRequest();

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  req.clear();

  DynamicJsonDocument doc(2048);

  if (200 != statusCode)
  {
#ifdef LOGGING
    Serial.println("Error in request");
#endif
    return doc;
  }

#ifdef LOGGING
  Serial.println("Response " + response);
#endif
  DeserializationError error = deserializeJson(doc, response);
  if (error)
  {
#ifdef LOGGING
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
#endif
    return doc;
  }

  return doc;
}

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

bool ConnectIoT::addDeviceToRegistry(
    const char *registryName,
    const char *deviceName,
    const char *description)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["description"] = description;
  response = this->callMethodApi(
      "add_device_to_registry", req);
  return response["data"];
}

bool ConnectIoT::addDeviceToRegistry(
    const String &registryName,
    const String &deviceName,
    const String &description)
{
  return addDeviceToRegistry(registryName.c_str(), deviceName.c_str(), description.c_str());
}

bool ConnectIoT::deleteDeviceFromRegistry(
    const char *registryName,
    const char *deviceName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  response = this->callMethodApi(
      "delete_device_from_registry", req);
  return response["data"];
}

bool ConnectIoT::deleteDeviceFromRegistry(
    const String &registryName,
    const String &deviceName)
{
  return deleteDeviceFromRegistry(registryName.c_str(), deviceName.c_str());
}

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

DynamicJsonDocument &ConnectIoT::getDeviceData(
    const char *registryName,
    const char *deviceName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  response = this->callMethodApi(
      "get_device_data", req);
  return response;
}

DynamicJsonDocument &ConnectIoT::getDeviceData(
    const String &registryName,
    const String &deviceName)
{
  return getDeviceData(registryName.c_str(), deviceName.c_str());
}

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

bool ConnectIoT::setDeviceMetadata(
    const char *registryName,
    const char *deviceName,
    DynamicJsonDocument &metadata)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  req["metadata"] = metadata;
  response = this->callMethodApi(
      "set_device_metadata", req);
  return (bool)response["data"];
}

bool ConnectIoT::setDeviceMetadata(
    const String &registryName,
    const String &deviceName,
    DynamicJsonDocument &metadata)
{
  return setDeviceMetadata(registryName.c_str(), deviceName.c_str(), metadata);
}

DynamicJsonDocument &ConnectIoT::getDeviceMetadata(
    const char *registryName,
    const char *deviceName)
{
  DynamicJsonDocument req(512);
  DynamicJsonDocument response(2048);
  req["registry_name"] = registryName;
  req["device_name"] = deviceName;
  response = this->callMethodApi(
      "get_device_metadata", req);
  return response;
}

DynamicJsonDocument &ConnectIoT::getDeviceMetadata(
    const String &registryName,
    const String &deviceName)
{
  return getDeviceMetadata(registryName.c_str(), deviceName.c_str());
}

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