#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "NeoPixelConfig.h"
#include <SoftwareSerial.h>


enum Animation { STRIPSTATICCOLOR, STRIPFADECOLOR, RAINBOWCYCLE, RAINBOWCHASE, THEATERCHASE, RANDOMCOLORPIXEL, AURORAGLOW };
enum ColorSelection { RED, GREEN, BLUE, YELLOW, PURPLE, ORANGE };
enum Direction { FADEIN, FADEOUT, FORWARD, REVERSE };
//enum States { NONE, GOT_A, GOT_R, GOT_G, GOT_B, GOT_S, GOT_D, GOT_T, GOT_W};

class NeoPixelAnimations : public Adafruit_NeoPixel
{
public:
	Animation selectedAnimation;
	ColorSelection selectedColor;
	Direction selectedDirection;
	unsigned int totalRGBCycleSteps;
	unsigned long previousMilliTime;
	uint8_t currentColorStep; //Used to track range from 0-255
	uint8_t totalColorStep;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t white;
	uint8_t groupStep;
	uint8_t numOfGroups;
	uint8_t numOfPreSetColors = 5; //Starting count from 0
	uint8_t numOfPasses;
	uint8_t LEDIndex;
	uint32_t curColor;
	uint8_t next_blue;
	uint8_t next_green;
	uint8_t next_red;
	uint32_t curr_col;
	float currentT;
	bool flag;

	//Constructor
	NeoPixelAnimations(uint16_t pixels, uint8_t pin, uint8_t type) : Adafruit_NeoPixel(pixels, pin, type)
	{}

	void Update(unsigned int delayLength)
	{
		if (millis() - previousMilliTime >= delayLength)
		{
			previousMilliTime = millis();

			switch (selectedAnimation)
			{
			case STRIPSTATICCOLOR: break; //Do nothing since a static effect does not need constant updating, only need to set once
			case STRIPFADECOLOR: StripFadeColorUpdate(); break;
			case RAINBOWCYCLE: RainbowCycleUpdate(); break;
			case RAINBOWCHASE: RainbowChaseUpdate(); break;
			case THEATERCHASE: TheaterChaseUpdate(); break;
			case RANDOMCOLORPIXEL: RandomColorPixelUpdate(); break;
			case AURORAGLOW: AuroraGlowUpdate(); break;
			}
		}
	}


	void StripStaticColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
	{
		red = r;
		green = g;
		blue = b;
		white = w;
		selectedAnimation = STRIPSTATICCOLOR;
		SetEntireStrip(red, green, blue, white);
	}

	void StripFadeColor()
	{
		selectedAnimation = STRIPFADECOLOR;
		currentColorStep = 0;
		totalColorStep = 255;
		selectedColor = RED;
		selectedDirection = FADEIN;
		currentT = 0;
		red = 0;
		green = 0;
		blue = 0;
		white = 0;
	}

	void StripFadeColorUpdate()
	{
		currentT = (float)currentColorStep / (float)255;

		switch (selectedColor)
		{
		case RED:
		{
			if (selectedDirection == FADEIN && currentColorStep < totalColorStep)
			{
				LerpedColorGradient(0, 0, 0, 0, 255, 0, 0, 0, currentT);
				currentColorStep++;
			}
			else if (selectedDirection == FADEIN && currentColorStep == totalColorStep)
			{
				currentColorStep -= 1;
				selectedDirection = FADEOUT;
			}
			else if (selectedDirection == FADEOUT && currentColorStep > 0)
			{
				LerpedColorGradient(0, 0, 0, 0, 255, 0, 0, 0, currentT);
				currentColorStep--;
			}
			else
			{
				selectedDirection = FADEIN;
				selectedColor = GREEN;
			}

			SetEntireStrip(red, green, blue, white);

			break;
		}
		case GREEN:
		{
			if (selectedDirection == FADEIN && currentColorStep < totalColorStep)
			{
				LerpedColorGradient(0, 0, 0, 0, 0, 255, 0, 0, currentT);
				currentColorStep++;
			}
			else if (selectedDirection == FADEIN && currentColorStep == totalColorStep)
			{
				currentColorStep--;
				selectedDirection = FADEOUT;
			}
			else if (selectedDirection == FADEOUT && currentColorStep > 0)
			{
				LerpedColorGradient(0, 0, 0, 0, 0, 255, 0, 0, currentT);
				currentColorStep--;
			}
			else
			{
				selectedDirection = FADEIN;
				selectedColor = BLUE;
			}

			SetEntireStrip(red, green, blue, white);

			break;
		}
		case BLUE:
		{
			if (selectedDirection == FADEIN && currentColorStep < totalColorStep)
			{
				LerpedColorGradient(0, 0, 0, 0, 0, 0, 255, 0, currentT);
				currentColorStep++;
			}
			else if (selectedDirection == FADEIN && currentColorStep == totalColorStep)
			{
				currentColorStep--;
				selectedDirection = FADEOUT;
			}
			else if (selectedDirection == FADEOUT && currentColorStep > 0)
			{
				LerpedColorGradient(0, 0, 0, 0, 0, 0, 255, 0, currentT);
				currentColorStep--;
			}
			else
			{
				selectedDirection = FADEIN;
				selectedColor = RED;
			}

			SetEntireStrip(red, green, blue, white);

			break;
		}
		}
	}

	void RainbowCycle()
	{
		selectedAnimation = RAINBOWCYCLE;
		currentColorStep = 0;
		totalColorStep = 255;
		totalRGBCycleSteps = 0;
		red = 255;
		green = 0;
		blue = 0;
		white = 0;
		selectedColor = RED;
	}

	void RainbowCycleUpdate()
	{
		currentT = (float)currentColorStep / (float)255;

		if (selectedColor == RED)
		{
			LerpedColorGradient(255, 0, 0, 0, 0, 255, 0, 0, currentT);
		}
		else if (selectedColor == GREEN)
		{
			LerpedColorGradient(0, 255, 0, 0, 0, 0, 255, 0, currentT);
		}
		else //Selected color is blue
			LerpedColorGradient(0, 0, 255, 0, 255, 0, 0, 0, currentT);

		SetEntireStrip(red, green, blue, white);

		if (selectedColor == RED && currentColorStep == 255)
		{
			selectedColor = GREEN;
			currentColorStep = 0;
		}
		else if (selectedColor == GREEN && currentColorStep == 255)
		{
			selectedColor = BLUE;
			currentColorStep = 0;
		}
		else if (selectedColor == BLUE && currentColorStep == 255)
		{
			selectedColor = RED;
			currentColorStep = 0;
		}
		else
			currentColorStep++;
	}

	void RainbowChase(uint8_t dir = 0)
	{
		selectedAnimation = RAINBOWCHASE;
		selectedColor = RED;
		if (dir == 0)
			selectedDirection = FORWARD;
		else if (dir == 1)
			selectedDirection = REVERSE;
		else
			selectedDirection = FORWARD;
		groupStep = 0;
		currentColorStep = 0;
		totalColorStep = 0;
		currentT = 0;
		red = 0;
		green = 0;
		blue = 0;
		next_blue = 0;
		next_green = 0;
		next_red = 0;
		curr_col = 0;
		setPixelColor(0, 255, 0, 0, 0);
		show();
	}

	void RainbowChaseUpdate()
	{
		currentT = (float)totalColorStep / (float)50;

		switch (selectedDirection)
		{
		case FORWARD:
		{
			if (selectedColor == RED)
			{
				LerpedColorGradient(255, 0, 0, 0, 0, 255, 0, 0, currentT);
				setPixelColor(0, red, green, blue, white);
			}
			else if (selectedColor == GREEN)
			{
				LerpedColorGradient(0, 255, 0, 0, 0, 0, 255, 0, currentT);
				setPixelColor(0, red, green, blue, white);
			}
			else
			{
				LerpedColorGradient(0, 0, 255, 0, 255, 0, 0, 0, currentT);
				setPixelColor(0, red, green, blue, white);
			}

			for (int i = 0; i < NUM_LEDS; i++)
			{
				if (i == 0)
				{
					curr_col = getPixelColor(i); // get the current color
					// separate into RGB components
					blue = curr_col & 0xFF;
					green = (curr_col >> 8) & 0xFF;
					red = (curr_col >> 16) & 0xFF;
				}
				else
				{
					blue = next_blue;
					green = next_green;
					red = next_red;
				}

				curr_col = getPixelColor(i + 1);

				next_blue = curr_col & 0xFF;
				next_green = (curr_col >> 8) & 0xFF;
				next_red = (curr_col >> 16) & 0xFF;

				setPixelColor(i + 1, red, green, blue);

			}
			break;
		}
		case REVERSE:
		{
			if (selectedColor == RED)
			{
				LerpedColorGradient(255, 0, 0, 0, 0, 255, 0, 0, currentT);
				setPixelColor(NUM_LEDS - 1, red, green, blue, white);
			}
			else if (selectedColor == GREEN)
			{
				LerpedColorGradient(0, 255, 0, 0, 0, 0, 255, 0, currentT);
				setPixelColor(NUM_LEDS - 1, red, green, blue, white);
			}
			else
			{
				LerpedColorGradient(0, 0, 255, 0, 255, 0, 0, 0, currentT);
				setPixelColor(NUM_LEDS - 1, red, green, blue, white);
			}

			for (int i = NUM_LEDS - 1; i >= 0; i--)
			{
				if (i == NUM_LEDS - 1)
				{
					curr_col = getPixelColor(i); // get the current color
					// separate into RGB components
					blue = curr_col & 0xFF;
					green = (curr_col >> 8) & 0xFF;
					red = (curr_col >> 16) & 0xFF;
				}
				else
				{
					blue = next_blue;
					green = next_green;
					red = next_red;
				}

				curr_col = getPixelColor(i - 1);

				next_blue = curr_col & 0xFF;
				next_green = (curr_col >> 8) & 0xFF;
				next_red = (curr_col >> 16) & 0xFF;

				setPixelColor(i - 1, red, green, blue);
			}
			break;
		}
		}
		if (currentT == 1)
		{
			if (selectedColor == RED)
				selectedColor = GREEN;
			else if (selectedColor == GREEN)
				selectedColor = BLUE;
			else
				selectedColor = RED;
		}

		show();

		if (totalColorStep == 50)
			totalColorStep = 0;
		else
			totalColorStep++;
	}

	void TheaterChase(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
	{
		selectedAnimation = THEATERCHASE;
		currentColorStep = 0;

		if (r == 0 && g == 0 && b == 0 && w == 0) //Default to blue
		{
			red = 0;
			green = 0;
			blue = 255;
			white = 0;
		}
		else
		{
			red = r;
			green = g;
			blue = b;
			white = w;
		}
	}

	void TheaterChaseUpdate()
	{
		for (int i = 0; i < NUM_LEDS; i++)
		{
			if ((i + currentColorStep) % 5 == 0)
				setPixelColor(i, red, green, blue, 0);
			else
				setPixelColor(i, 0, 0, 0, 0);
		}

		show();

		IncrementCurrentStep();
	}

	void RandomColorPixel()
	{
		selectedAnimation = RANDOMCOLORPIXEL;
		selectedDirection = REVERSE;
		currentColorStep = 0;
		totalColorStep = 255;
		red = 0;
		green = 0;
		blue = 0;
		next_blue = 0;
		next_green = 0;
		next_red = 0;
		curr_col = 0;
		randomSeed(analogRead(0));
		//Initilize the strip with a random color for each LED

		numOfGroups = (NUM_LEDS + RANDOM_COLOR_GROUPSIZE - 1) / RANDOM_COLOR_GROUPSIZE; //Round up the number of groups

		for (int i = 0; i < numOfGroups; i++)
		{
      uint8_t rand = random(0,5);
      cur_color = SetColor(rand, true);
      red = curColor & 0xFF;
      green = (curColor >> 8) & 0xFF;
      blue = (curColor >> 16) & 0xFF;
			FillLEDRange(LEDIndex, LEDIndex + groupSize, red, green, blue, 0);
			LEDIndex += groupSize;
		}

		show();
	}

	void RandomColorPixelUpdate()
	{
		switch (selectedDirection)
		{
		case FORWARD:
		{
			for (int i = 0; i < NUM_LEDS; i++)
			{
				if (i == 0)
				{
					curr_col = getPixelColor(i); // get the current color
					// separate into RGB components
					blue = curr_col & 0xFF;
					green = (curr_col >> 8) & 0xFF;
					red = (curr_col >> 16) & 0xFF;
				}
				else
				{
					blue = next_blue;
					green = next_green;
					red = next_red;
				}


				if (i + 1 == NUM_LEDS)
				{
					curr_col = getPixelColor(0);

					next_blue = curr_col & 0xFF;
					next_green = (curr_col >> 8) & 0xFF;
					next_red = (curr_col >> 16) & 0xFF;

					setPixelColor(0, red, green, blue);
				}
				else
				{
					curr_col = getPixelColor(i + 1);

					next_blue = curr_col & 0xFF;
					next_green = (curr_col >> 8) & 0xFF;
					next_red = (curr_col >> 16) & 0xFF;

					setPixelColor(i + 1, red, green, blue);
				}
			}
		}
		case REVERSE:
		{
			for (int i = NUM_LEDS - 1; i >= 0; i--)
			{
				if (i == NUM_LEDS - 1)
				{
					curr_col = getPixelColor(i); // get the current color
					// separate into RGB components
					blue = curr_col & 0xFF;
					green = (curr_col >> 8) & 0xFF;
					red = (curr_col >> 16) & 0xFF;
				}
				else
				{
					blue = next_blue;
					green = next_green;
					red = next_red;
				}

				if (i - 1 < 0)
				{
					curr_col = getPixelColor(NUM_LEDS - 1);

					next_blue = curr_col & 0xFF;
					next_green = (curr_col >> 8) & 0xFF;
					next_red = (curr_col >> 16) & 0xFF;

					setPixelColor(NUM_LEDS - 1, red, green, blue);
				}
				else
				{
					curr_col = getPixelColor(i - 1);

					next_blue = curr_col & 0xFF;
					next_green = (curr_col >> 8) & 0xFF;
					next_red = (curr_col >> 16) & 0xFF;

					setPixelColor(i - 1, red, green, blue);
				}
			}
		}
		}

		show();
	}

	void AuroraGlow()
	{
		selectedAnimation = AURORAGLOW;
		selectedDirection = FADEOUT;
		groupStep = 0;
		currentColorStep = 0;
		totalColorStep = 0;
		currentT = 0;
		flag = false;
		red = 0;
		green = 0;
		blue = 0;
		next_blue = 0;
		next_green = 0;
		next_red = 0;
		numOfGroups = (NUM_LEDS + AURORA_GLOW_GROUPSIZE - 1) / AURORA_GLOW_GROUPSIZE; //Round up the number of groups

		for (int i = 0; i < NUM_LEDS; i++)
		{
			SetColor(i, false);
			setPixelColor(i, red, green, blue, white);
		}
	}

	//Hackish code to try to simulate an aurora effect
	void AuroraGlowUpdate()
	{
		currentT = (float)totalColorStep / (float)255;

		if (groupStep == 0)
		{
			curColor = SetColor(5, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 50, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
			curColor = SetColor(4, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 40, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
			curColor = SetColor(3, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 30, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
			curColor = SetColor(2, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 20, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
			curColor = SetColor(1, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 10, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
			curColor = SetColor(0, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
		}
		else if (groupStep == 1)
		{
			curColor = SetColor(5, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 50, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
			curColor = SetColor(4, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 40, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
			curColor = SetColor(3, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 30, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
			curColor = SetColor(2, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 20, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
			curColor = SetColor(1, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep + 10, groupSize, FADEOUT, currentT, next_red, next_green, next_blue);
			curColor = SetColor(0, true);
			next_blue = curColor & 0xFF;
			next_green = (curColor >> 8) & 0xFF;
			next_red = (curColor >> 16) & 0xFF;
			FadeFroup(currentColorStep, groupSize, FADEIN, currentT, next_red, next_green, next_blue);
		}

		if (currentT == 1)
		{
			if (groupStep == 1)
				groupStep = 0;
			else
				groupStep++;
		}

		IncrementTotalColorStep();

		show();
	}

	void LerpedColorGradient(uint8_t start_red, uint8_t start_green, uint8_t start_blue, uint8_t start_white, uint8_t end_red, uint8_t end_green, uint8_t end_blue, uint8_t end_white, float curStep)
	{
		red = (uint8_t)LinearInteroplation(start_red, end_red, curStep, 0.0, 1.0);
		green = (uint8_t)LinearInteroplation(start_green, end_green, curStep, 0.0, 1.0);
		blue = (uint8_t)LinearInteroplation(start_blue, end_blue, curStep, 0.0, 1.0);
		white = (uint8_t)LinearInteroplation(start_white, end_white, curStep, 0.0, 1.0);
	}

	void SetEntireStrip(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
	{
		for (int curPixel = 0; curPixel < NUM_LEDS; curPixel++)
			setPixelColor(curPixel, r, g, b, w);
		show();
	}

	//Linear Interpolation function used to get a color value between a start and end value
	//x1 = starting color value
	//x2 = ending color value
	//tCurrent = current step/time
	//tStart should always be 0 and tEnd should always be 1
	float LinearInteroplation(float x1, float x2, float tCurrent, float tStart, float tEnd)
	{
		//float temp = (x2 - x1)*tCurrent + x1;
		return  x1 + (x2 - x1) * ((tCurrent - tStart) / (tEnd - tStart));
	}

	void FadeFroup(uint8_t startLED, uint8_t groupSize, Direction selDirection, float lerpStep, uint8_t r, uint8_t g, uint8_t b)
	{
		for (int i = startLED; i < startLED + groupSize; i++)
		{
			if (selDirection == FADEIN)
			{
				LerpedColorGradient(r/4, g/4, b/4, 0, r, g, b, 0, lerpStep);
				//LerpedColorGradient(0, 0, 0, 0, r, g, b, 0, lerpStep);
			}
			else if (selDirection == FADEOUT)
			{
				LerpedColorGradient(r, g, b, 0, r/4, g/4, b/4, 0, lerpStep);
				//LerpedColorGradient(r, g, b, 0, 0, 0, 0, 0, lerpStep);
			}
			else
				break;

			setPixelColor(i, red, green, blue, white);
		}
	}

	uint32_t SetColor(uint8_t color, bool indexFlag)
	{
		if (indexFlag == false)
		{
			if (color >= 0 && color < 10)
				color = 0;
			else if (color >= 10 && color < 20)
				color = 1;
			else if (color >= 20 && color < 30)
				color = 2;
			else if (color >= 30 && color < 40)
				color = 3;
			else if (color >= 40 && color < 50)
				color = 4;
			else if (color >= 50 && color < 60)
				color = 5;
			else
				color = 6;
		}

		switch (color)
		{
		case 0: //Red
			red = 255;
			green = 0;
			blue = 0;
			white = 0;
			break;
		case 1: //Green
			red = 0;
			green = 255;
			blue = 0;
			white = 0;
			break;
		case 2: //Blue
			red = 0;
			green = 0;
			blue = 255;
			white = 0;
			break;
		case 3: //Yellow
			red = 255;
			green = 255;
			blue = 0;
			white = 0;
			break;
		case 4: //Purple
			red = 160;
			green = 32;
			blue = 240;
			white = 0;
			break;
		case 5: //Orange
			red = 255;
			green = 165;
			blue = 0;
			white = 0;
			break;
		default:
			red = 0;
			green = 0;
			blue = 0;
			white = 255;
		}

		return Color(red, green, blue, white);
	}

	void IncrementCurrentStep()
	{
		if (currentColorStep == 255)
			currentColorStep = 0;
		else
			currentColorStep++;
	}

	void IncrementTotalColorStep()
	{
		if (totalColorStep == 255)
			totalColorStep = 0;
		else
			totalColorStep++;
	}

	void FillLEDRange(unsigned int startLED, unsigned int endLED, uint8_t r, uint8_t g, uint8_t b, uint8_t w)
	{
		//Pevent overflow on trying to set an LED out of range
		if (endLED > NUM_LEDS)
			endLED = NUM_LEDS;

		for (int i = startLED; i <= endLED; i++)
		{
			setPixelColor(i, r, g, b, w);
		}
		show();
	}
};

int selectedAnimation;
unsigned int currentValue;
uint8_t redVal;
uint8_t greenVal;
uint8_t blueVal;
uint8_t whiteVal;
unsigned int speedVal;
uint8_t directionVal;
bool newAnimationSelected;
unsigned int speedValTemp;
char bluefruitBuffer[INPUT_BUFFER_SIZE];
int bufferOffset;

NeoPixelAnimations strip = NeoPixelAnimations(NUM_LEDS, PIN, STRIP_TYPE + NEO_KHZ800);
SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);
Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN, BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

void setup()
{

	Serial.begin(57600);
	Serial.println("Serial port is set up on ardiuno...");

  if(ENABLE_BLUETOOTH)
  {
    Serial.print(F("Initialising the Bluefruit LE module: "));
    if (!ble.begin(VERBOSE_MODE))
    {
      Serial.println("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?");
    }
    Serial.println(F("OK!"));
  
    ble.echo(false);
    ble.verbose(false);
  
    //Wait for bluetooth module to connect
    //while (!ble.isConnected()) {
    //  delay(500);
    //}
  
    if (ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION))
    {
      // Change Mode LED Activity
      Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
      ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
    }
    ble.setMode(BLUEFRUIT_MODE_DATA);
  }
	

	strip.begin();

	Serial.println("Starting default animation...");
	strip.StripStaticColor(0, 0, 0, 0); //Default to off

  //Initilize values
	selectedAnimation = 0;
	speedVal = 0;
	newAnimationSelected = false;
	redVal = 0;
	greenVal = 0;
	blueVal = 0;
	directionVal = 0;
	whiteVal = 0;
	bufferOffset = 0;
}
void loop() {

	if (Serial.available() > 0)
	{
		while (1) //Force an infinite loop while we read the entire command from serial so the show() command does not cause data loss since show() uses interupts 
		{
			char c = Serial.read();
			if (c == 'A')
				selectedAnimation = Serial.parseInt();
			if (c == 'R')
				redVal = Serial.parseInt();
			if (c == 'G')
				greenVal = Serial.parseInt();
			if (c == 'B')
				blueVal = Serial.parseInt();
			if (c == 'S')
				speedValTemp = Serial.parseInt();
			if (c == 'D')
				directionVal = Serial.parseInt();
			if (c == 'T')
			{
				speedVal = speedValTemp;
				newAnimationSelected = true;
				break;
			}
		}
	}

  if(ENABLE_BLUETOOTH)
  {
    while (ble.available())
    {
      int c = ble.read();
      //Serial.println((char)c);
      bluefruitBuffer[bufferOffset] = (char)c;
      bufferOffset++;
  
      if (c == 'T')
      {
        //Serial.println(bluefruitBuffer);
        parseBuffer();
        speedVal = speedValTemp;
        newAnimationSelected = true;
      }
    } 
  }

	if (newAnimationSelected == true)
	{
		switch (selectedAnimation)
		{
		case 0:
			strip.StripStaticColor(redVal, greenVal, blueVal, whiteVal); break;
		case 1:
			strip.StripFadeColor(); break;
		case 2:
			strip.RainbowCycle(); break;
		case 3:
			strip.RainbowChase(directionVal); break;
		case 4:
			strip.TheaterChase(redVal, greenVal, blueVal, whiteVal); break;
		case 5:
			strip.RandomColorPixel(); break;
		case 6:
			strip.AuroraGlow(); break;
		default:
			Serial.println("Invalid value recieved."); break;
		}

		selectedAnimation = NULL;

		newAnimationSelected = false;
	}

	strip.Update(speedVal);
}

void parseBuffer()
{
	char* tok = strchr(bluefruitBuffer, 'A');
	if (tok != NULL)
		selectedAnimation = atoi(tok + 1);

	tok = strchr(bluefruitBuffer, 'R');
	if (tok != NULL)
		redVal = atoi(tok + 1);

	tok = strchr(bluefruitBuffer, 'G');
	if (tok != NULL)
		greenVal = atoi(tok + 1);

	tok = strchr(bluefruitBuffer, 'B');
	if (tok != NULL)
		blueVal = atoi(tok + 1);

	tok = strchr(bluefruitBuffer, 'S');
	if (tok != NULL)
		speedValTemp = atoi(tok + 1);

	tok = strchr(bluefruitBuffer, 'D');
	if (tok != NULL)
		directionVal = atoi(tok + 1);

	//Reset buffer
	for (int i = 0; i < INPUT_BUFFER_SIZE; i++)
		bluefruitBuffer[i] = -1;

	bufferOffset = 0;
}
