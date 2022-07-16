#include <Arduino.h>
#include <ESP8266WiFi.h>

#define AP_HOST "Control"
#define STA_HOST "dxxy16-402-1"
const char *ap_ssid = AP_HOST;         // wifi名
const char *ap_password = "dxxy16402"; // wifi密码

const char *sta_ssid = STA_HOST;        // wifi名
const char *sta_password = "dxxy16402"; // wifi密码

const uint16_t port = 8266; //端口

WiFiServer server(port); // TCP服务器

void WiFi_Init(void)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ap_ssid, ap_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("SERVER");
  Serial.println(ap_ssid);
  Serial.println(WiFi.localIP());
  Serial.println(port);
  server.begin();
}

void setup()
{
  Serial.begin(115200);

  /* WiFi */
  WiFi_Init();
}

//循环执行
void loop()
{
   /* 新建一个WiFiClient类对象，作为TCP服务端对象 */
  WiFiClient client = server.available();

  if (client)
  {
    /* 如果有tcp连接成功 */
    if (!client.connected())
    {
      Serial.println("connection failed");
    }
    /* 串口和tcp客户端互传数据 */
    while (client.connected())
    {
      while (client.available() > 0)
      {
        Serial.write(client.read());
      }

      while (Serial.available() > 0)
      {
        client.write(Serial.read());
      }
    }
    client.stop();
  }
}