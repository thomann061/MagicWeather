#include <TFTv2.h>
#include <SPI.h>
#include <Bridge.h>
//#include <Console.h>
#include <Process.h>
#include <HttpClient.h>


#define LEFT2RIGHT 0
#define DOWN2UP    1
#define RIGHT2LEFT 2
#define UP2DOWN    3


//Use Wifi to upload sketch
//If you want to upload through USB, you must change Console to Serial
//Make sure Monitor is closed before each sketch demonstration

void setup() {
    TFT_BL_ON;      // turn on the background light
    Tft.TFTinit();  // init TFT library
    Tft.setDisplayDirect(UP2DOWN);
   
    Bridge.begin(); //make contact with linux processor
    Serial.begin(9600);

    //waits for console to open
    //while(!Serial);
    Serial.println("Connected to the console!");

    Serial.println("1made it this far");
/*
    Process p;            
    p.begin("curl");      
    Serial.println("2made it this far");
    p.addParameter("api.openweathermap.org/data/2.5/weather?lat=35&lon=139&mode=xml&APPID=e520bd843707ba2c49a4b0d895407f7d"); 
   Serial.println("3made it this far");
    p.run();
    
     char inData[1000] = "";
     short index = 0;
    Serial.println("4made it this far");
    while (p.available() > 0) {
      char c = p.read();
      inData[index] = c;
      Serial.print(inData[index]);
      index++;
    }
    inData[index] = '\0';

   Serial.println("5made it this far");

    for( index = 0; index < sizeof(inData); index++ ) { 
    Serial.print(inData[index]);
    }

    char el[5];
    //store first 9 characters prints <current>
    for( index = 0; index < 9; index++ ) { 
          el[index] = inData[index];
    }
    el[index] = '\0';
    Serial.println("7made it this far");
    */
    Tft.fillScreen(0,240,0,100,GRAY1);
    Tft.drawLine(0,0,240,0,WHITE);  //void drawLine(INT16U x0,INT16U y0, INT16U x1,INT16U y1,INT16U color);
    Tft.drawLine(0,100,240,100,WHITE);
    Tft.drawLine(0,0,0,100,WHITE);
    Tft.drawLine(240,0,240,100,WHITE);
    // Tft.drawString(el,100,100,2,RED);
     //Tft.fillRectangle(0, 0, 100,100,YELLOW); //void fillRectangle(INT16U poX, INT16U poY, 
                                                //INT16U length, INT16U width, INT16U color);
    Tft.drawString("Mon",230,0,2,WHITE);          //drawString((char*)string, poX, poY, size, fgcolor);
    Tft.drawString("Tue",195,0,2,WHITE); 
    Tft.drawString("Wed",161,0,2,WHITE);
    Tft.drawString("Thu",127,0,2,WHITE);
    Tft.drawString("Fri",92, 0,2,WHITE);
    Tft.drawString("Sat",58, 0,2,WHITE);
    Tft.drawString("Sun",24, 0,2,WHITE);

                                             //void fillScreen(INT16U XL,INT16U XR,INT16U YU,INT16U YD,INT16U color);
    
}

    void loop() {
    }
