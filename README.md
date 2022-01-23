# M5Stack_Avatar_BTSPK
Bluetooth Speaker対応のM5Stack_Avatarです。<br>
スピーカーの音に合わせてAvatarの口が動きます（リップシンク）。<br>

---
### このプログラムを動かすのに必要な物 ###
* [M5Stack](http://www.m5stack.com/ "Title") (M5Stack Core2、M5Stack Core2 for AWS、M5Stack Grayで動作確認をしました。)<br>
* Arduino IDE (バージョン 1.8.15で動作確認をしました。)<br>
* [M5Stack-Avatar](https://github.com/meganetaaan/m5stack-avatar/ "Title")ライブラリ(バージョン 0.7.3で動作確認をしました。)<br>
* [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP/ "Title")ライブラリ<br>

### 事前にESP32-A2DPライブラリを変更しておきます ###
* "BluetoothA2DPSink.cpp"の下図赤枠部分を追加します。<br>
![画像1](images/image1.png)<br>
<br>
---
### 使い方 ###
* スマホなどでペアリングを選択すると"Avatar"というデバイスが表示されるので選択して接続してください。
<br><br>

