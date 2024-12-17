#pragma once

#include "esphome/core/component.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <BearSSLHelpers.h>
#include <time.h>
#include <string>

namespace my_tls_mqtt {

class MyTLSMQTTClient : public esphome::Component {
 public:
  void setup() override;
  void loop() override;

  // Setter-Methoden für Konfigurationsparameter
  void set_broker_host(const std::string &host);
  void set_broker_port(uint16_t port);
  void set_username(const std::string &username);
  void set_password(const std::string &password);
  void set_device_name(const std::string &name);

 private:
  // Private Methoden
  void connect_to_mqtt_();
  void send_discovery_message_();

  // Member-Variablen
  std::string broker_host;
  uint16_t broker_port;
  std::string username_;
  std::string password_;
  std::string device_name;

  bool initialized_ = false;  // Initialisierungstatus
  BearSSL::X509List *trust_anchors_;  // Root-CA Zertifikate

  WiFiClientSecure wifi_client;
  PubSubClient mqtt_client;
};

}  // namespace my_tls_mqtt
