Not having a 2nd [M5Dial](https://docs.m5stack.com/en/core/M5Dial) available, [FakeVoltSender](https://github.com/BluDotz/FakeVolt/tree/main/FakeVoltSender) was written to test [Remote Voltage Monitor](https://www.youtube.com/watch?v=hWHHfaTxZC0) when it is operating in Receiver Mode.

The code - depolyed to an [M5 Atom Lite](https://shop.m5stack.com/products/atom-lite-esp32-development-kit) - helped gain understanding of [ESP-NOW](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/api-reference/network/esp_now.html) when using it in Broadcast mode. When the built-in button is pressed, a new Voltage Reading is sent to the [Remote Voltage Monitor](https://www.youtube.com/watch?v=hWHHfaTxZC0).

[FakeVoltReceiver](https://github.com/BluDotz/FakeVolt/tree/main/FakeVoltReceiver) was written to gain understanding of [ESP-NOW](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/api-reference/network/esp_now.html) when used as a receiver.
