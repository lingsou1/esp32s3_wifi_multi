/*
接线说明:无

程序说明:存储多个WiFi,自动连接信号最强的WiFi

注意事项:无

函数示例:无

作者:灵首

时间:2023_3_8

*/
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>


WiFiMulti wifi_multi;  //建立WiFiMulti 的对象,对象名称是 wifi_multi

/*
# brief 连接WiFi的函数
# param 无
# retval 无
*/
void wifi_multi_con(void){
  int i=0;
  while(wifi_multi.run() != WL_CONNECTED){
    delay(1000);
    i++;
    Serial.print(i);
  }
  Serial.print("wifi connected!!");

}


/*
# brief 写入自己要连接的WiFi名称及密码,之后会自动连接信号最强的WiFi
# param 无
# retval  无
*/
void wifi_multi_init(void){
  wifi_multi.addAP("LINGSOU123","123455678");
  wifi_multi.addAP("LINGSOU12","123455678");
  wifi_multi.addAP("LINGSOU1","123455678");
  wifi_multi.addAP("LINGSOU234","12345678");   //通过 wifi_multi.addAP() 添加了多个WiFi的信息,当连接时会在这些WiFi中自动搜索最强信号的WiFi连接
}

void setup() {
  Serial.begin(115200);//打开串口

  wifi_multi_init();//设置待添加的WiFi

  wifi_multi_con();   //连接WiFi

}

void loop() {
  Serial.print("\n IP address:");
  Serial.print(WiFi.localIP());   //输出开发板的IP地址
  Serial.print("\n wifi's ssid:");
  Serial.print(WiFi.SSID());    //输出开发板连接的WiFi名称
  delay(1000);
  // put your main code here, to run repeatedly:
}