
#include <TFTv2.h>
#include <SPI.h>
#include <Bridge.h>
#include <Console.h>
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
    Console.begin();

    //waits for console to open
    while(!Console);
    Console.println("Connected to the serial!");

    Console.println("1made it this far");

    Process p;            
    p.begin("curl");      
    Console.println("2made it this far");
    p.addParameter("api.openweathermap.org/data/2.5/weather?lat=35&lon=139&mode=xml&APPID=e520bd843707ba2c49a4b0d895407f7d"); 
   Console.println("3made it this far");
    p.run();
    
     char inData[1000] = "";
     short index = 0;
    Console.println("4made it this far");
    while (p.available() > 0) {
      char c = p.read();
      inData[index] = c;
      Console.print(inData[index]);
      index++;
    }
    inData[index] = '\0';

   Console.println("5made it this far");

    for( index = 0; index < sizeof(inData); index++ ) { 
    Console.print(inData[index]);
    }

    char el[5];
    //store first 9 characters prints <current>
    for( index = 0; index < 9; index++ ) { 
          el[index] = inData[index];
    }
    el[index] = '\0';
    Console.println("7made it this far");
     Tft.drawString(el,100,100,2,RED);
}

    void loop() {
    }

