#include    <DigiUSB.h>
 
#define IRpin       0                           // 赤外線受信モジュール接続ピン番号
 
// 初期化処理
void setup()
{
     DigiUSB.begin();                           // パソコン(DigiUSB)とシリアル通信の準備を行う
     pinMode(IRpin,INPUT);                      // 赤外線受信モジュールに接続したピンをデジタル入力に設定
}
 
// メインの処理
void loop()
{
     unsigned long t, pre_t;
     int state, preState;
      
     preState = digitalRead(IRpin);             // 現在の状態を取得
     pre_t = 0;
      
     while(1) {
         state = digitalRead(IRpin);
         if(state != preState) {                // 状態が変化するまで待つ
             preState = state;
             t = micros();                      // 時間(マイクロ秒を)を記録
             if(pre_t != 0) {
                 DigiUSB.println(t - pre_t);    // その状態が継続した時間を出力
             };
             pre_t = t;
         }
         DigiUSB.delay(1);                      // refresh the USB port
     }
}
