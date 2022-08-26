#ifndef ConnectIoT_h
#define ConnectIoT_h

#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>
#include <ArduinoJson.h>

class ConnectIoT
{
public:
    ConnectIoT(
        WiFiClient &wifi,
        const char *serverAddress,
        uint16_t port,
        const char *nearAccountId,
        const char *nearAccountPrivateKey);

    ConnectIoT(
        WiFiClient &wifi,
        const String &serverAddress,
        uint16_t port,
        const String &nearAccountId,
        const String &nearAccountPrivateKey);

    bool createRegistry(const String &registryName);
    bool createRegistry(const char *registryName);

    bool deleteRegistry(const String &registryName);
    bool deleteRegistry(const char *registryName);

    bool addDeviceToRegistry(
        const String &registryName,
        const String &deviceName,
        const String &description);
    bool addDeviceToRegistry(
        const char *registryName,
        const char *deviceName,
        const char *description);

    bool deleteDeviceFromRegistry(
        const String &registryName,
        const String &deviceName);

    bool deleteDeviceFromRegistry(
        const char *registryName,
        const char *deviceName);

    bool setDeviceData(
        const String &registryName,
        const String &deviceName,
        DynamicJsonDocument &data);

    bool setDeviceData(
        const char *registryName,
        const char *deviceName,
        DynamicJsonDocument &data);

    DynamicJsonDocument &getDeviceData(
        const String &registryName,
        const String &deviceName);

    DynamicJsonDocument &getDeviceData(
        const char *registryName,
        const char *deviceName);

    bool setDeviceDataParam(
        const String &registryName,
        const String &deviceName,
        const String &param,
        const String &value);

    bool setDeviceDataParam(
        const char *registryName,
        const char *deviceName,
        const char *param,
        const char *value);

    String getDeviceDataParam(
        const String &registryName,
        const String &deviceName,
        const String &param);

    String getDeviceDataParam(
        const char *registryName,
        const char *deviceName,
        const char *param);

    bool setDeviceMetadata(
        const String &registryName,
        const String &deviceName,
        DynamicJsonDocument &metadata);

    bool setDeviceMetadata(
        const char *registryName,
        const char *deviceName,
        DynamicJsonDocument &metadata);

    DynamicJsonDocument &getDeviceMetadata(
        const String &registryName,
        const String &deviceName);

    DynamicJsonDocument &getDeviceMetadata(
        const char *registryName,
        const char *deviceName);

    bool setDeviceMetadataParam(
        const String &registryName,
        const String &deviceName,
        const String &param,
        const String &value);

    bool setDeviceMetadataParam(
        const char *registryName,
        const char *deviceName,
        const char *param,
        const char *value);

    String getDeviceMetadataParam(
        const String &registryName,
        const String &deviceName,
        const String &param);

    String getDeviceMetadataParam(
        const char *registryName,
        const char *deviceName,
        const char *param);

private:
    WiFiClient *wifiClient;
    uint16_t serverPort;
    const char *serverAddress;
    const char *nearAccountId;
    const char *nearAccountPrivateKey;

    DynamicJsonDocument callMethodApi(const String &methodName, DynamicJsonDocument &params);
};

#endif
