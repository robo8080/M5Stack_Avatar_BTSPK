# if defined(ARDUINO_M5STACK_Core2)
  #include <M5Core2.h>
#elif defined( ARDUINO_M5STACK_FIRE ) || defined( ARDUINO_M5Stack_Core_ESP32 )
  #include <M5Stack.h>
# endif
#include <Avatar.h>
#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

using namespace m5avatar;

Avatar avatar;

extern int16_t audio_level;
void lipSync(void *args)
{
  DriveContext *ctx = (DriveContext *)args;
  Avatar *avatar = ctx->getAvatar();
   for (;;)
  {
    int level = audio_level;
    level = abs(level);
    if(level > 3500)
    {
      level = 3500;
    }
    float open = (float)level/3500.0;
    avatar->setMouthOpenRatio(open);
    delay(33);
//    delay(50);
  }
}

void setup()
{
  M5.begin();
#if defined(ARDUINO_M5STACK_Core2)
  M5.Axp.SetSpkEnable(true);
  i2s_pin_config_t tx_pin_config;
  tx_pin_config.bck_io_num    = 12;
  tx_pin_config.ws_io_num     = 0;
  tx_pin_config.data_out_num  = 2;
  tx_pin_config.data_in_num   = I2S_PIN_NO_CHANGE;
  a2dp_sink.set_pin_config(tx_pin_config);
#elif defined( ARDUINO_M5STACK_FIRE ) || defined( ARDUINO_M5Stack_Core_ESP32 )
  static const i2s_config_t i2s_config = {
      .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
      .sample_rate = 44100, // corrected by info from bluetooth
      .bits_per_sample = (i2s_bits_per_sample_t) 16, /* the DAC module will only take the 8bits from MSB */
      .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
      .communication_format = I2S_COMM_FORMAT_I2S_MSB,
      .intr_alloc_flags = 0, // default interrupt priority
      .dma_buf_count = 8,
      .dma_buf_len = 64,
      .use_apll = false
  };
  a2dp_sink.set_i2s_config(i2s_config);  
#endif
  a2dp_sink.start("Avatar");
  
  avatar.init(); // start drawing
  avatar.addTask(lipSync, "lipSync");
}

void loop()
{
  // avatar's face updates in another thread
  // so no need to loop-by-loop rendering
}
