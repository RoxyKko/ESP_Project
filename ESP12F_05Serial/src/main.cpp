/*
EPS8266无线终端模式连接WIFI
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>

const char *ssid = "dxxy16-402-1";  // wifi名
const char *password = "dxxy16402"; // wifi密码

void setup()
{
  Serial.begin(115200); // 初始化串口通讯波特率为115200

  WiFi.mode(WIFI_STA);               // 设置Wifi工作模式为STA,默认为AP+STA模式
  WiFi.begin(ssid, password);        // 通过wifi名和密码连接到Wifi
  Serial.print("\r\nConnecting to"); // 串口监视器输出网络连接信息
  Serial.print(ssid);                // 显示NodeMCU正在尝试WiFi连接
  Serial.println(" ...");

  int i = 0;                            // 检查WiFi是否连接成功
  while (WiFi.status() != WL_CONNECTED) // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。
  {                                     // 如果WiFi连接成功则返回值为WL_CONNECTED
    delay(1000);                        // 此处通过While循环让NodeMCU每隔一秒钟检查一次WiFi.status()函数返回值
    Serial.print("waiting for ");
    Serial.print(i++);
    Serial.println(" s...");
  }

  Serial.println("");                // WiFi连接成功后
  Serial.println("WIFI connectde!"); // NodeMCU将通过串口监视器输出"连接成功"信息。
  Serial.print("IP address: ");      // 同时还将输出NodeMCU的IP地址。这一功能是通过调用
  Serial.println(WiFi.localIP());    // WiFi.localIP()函数来实现的。该函数的返回值即NodeMCU的IP地址。
}

void loop()
{
  // put your main code here, to run repeatedly:
}