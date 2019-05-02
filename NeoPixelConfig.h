// NEOPIXEL SETTINGS
#define NUM_LEDS                      240
#define PIN                           6       //Pin number used to communicate with the Neopixel Strip
#define INPUT_BUFFER_SIZE             26
#define AURORA_GLOW_GROUPSIZE         10
#define RANDOM_COLOR_GROUPSIZE        5
#define STRIP_TYPE                    NEO_GRB //NEO_GRBW for RGBW strip

// COMMON SETTINGS
// ----------------------------------------------------------------------------------------------
// These settings are used in both SW UART, HW UART and SPI mode
// ----------------------------------------------------------------------------------------------
#define BUFSIZE                        128   // Size of the read buffer for incoming data
#define VERBOSE_MODE                   true  // If set to 'true' enables debug output
#define ENABLE_BLUETOOTH               true  // Set to true if this arduino is using bluetooth, otherwise set to false so bluetooth code does not run

// SOFTWARE UART SETTINGS
// ----------------------------------------------------------------------------------------------
// The following macros declare the pins that will be used for 'SW' serial.
// You should use this option if you are connecting the UART Friend to an UNO
// ----------------------------------------------------------------------------------------------
#define BLUEFRUIT_SWUART_RXD_PIN       9    // Required for software serial!
#define BLUEFRUIT_SWUART_TXD_PIN       10   // Required for software serial!
#define BLUEFRUIT_UART_CTS_PIN         11   // Required for software serial!
#define BLUEFRUIT_UART_RTS_PIN         8   // Optional, set to -1 if unused


// HARDWARE UART SETTINGS
// ----------------------------------------------------------------------------------------------
// The following macros declare the HW serial port you are using. Uncomment
// this line if you are connecting the BLE to Leonardo/Micro or Flora
// ----------------------------------------------------------------------------------------------
//#ifdef Serial1    // this makes it not complain on compilation if there's no Serial1
#define BLUEFRUIT_HWSERIAL_NAME      Serial
//#endif


// SHARED UART SETTINGS
// ----------------------------------------------------------------------------------------------
// The following sets the optional Mode pin, its recommended but not required
// ----------------------------------------------------------------------------------------------
#define BLUEFRUIT_UART_MODE_PIN        -1    // Set to -1 if unused

//Other Settings
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"
