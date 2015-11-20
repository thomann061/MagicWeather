
#include <TFTv2.h>
    #include <SPI.h>
        #include <Bridge.h>
            //#include <Console.h>
                #include <Process.h>
                    #include <HttpClient.h>


                        #define LEFT2RIGHT 0
                        #define DOWN2UP    1
                        #define RIGHT2LEFT 2
                        #define UP2DOWN    3 //orientation for the correct display


                        //Use Wifi to upload sketch
                        //If you want to upload through USB, you must change Console to Serial
                        //Make sure Monitor is closed before each sketch demonstration

                        void setup() {
                        TFT_BL_ON;      // turn on the background light
                        Tft.TFTinit();  // init TFT library
                        Tft.setDisplayDirect(UP2DOWN);

                        Bridge.begin(); //make contact with linux processor
                        Serial.begin(9600);

                        //Container Box for Days: Temp
                        Tft.fillScreen(0,190,0,100,GRAY1);

                        //Boarder around the Container Box
                        Tft.drawLine(0,0,190,0,WHITE);  
                        Tft.drawLine(0,100,190,100,WHITE);
                        Tft.drawLine(0,0,0,100,WHITE);
                        Tft.drawLine(190,0,190,100,WHITE);

                        //**********Header Box to hold the current city - if possible dynamic/updatable by zip code  *************** .fillScreen();
                        Tft.fillScreen(240,193,0,320,GRAY1);
                        //**********Boarder around the Header Box*********** .drawLine(x,y,X,Y);
                        Tft.drawLine(192,0,192,320,WHITE);  
                        Tft.drawLine(240,0,240,320,WHITE);
                        Tft.drawLine(240,0,192,0,WHITE);
                        Tft.drawLine(240,320,192,320,WHITE);



                        //MUCH BETTER SUN TAKEN FROM THE LIBRARY FILE but I might still need to make Rain/Cloudy/and whatever else
                        for(int r=0;r<60;r=r+2)                            //set r : 0--115
                        {
                        Tft.drawCircle(95,215,r,YELLOW);       //draw circle, center:(119, 160), color: random
                        }

                        //City, State text
                        Tft.drawString("Salt Lake City, UT",215,0,2,CYAN);       // draw string: "hello", (0, 180), size: 3, color: CYAN

                        //*******  Sun Shine Baby!
                        //********    .fillScreen(x, X, y, Y, Color)
                        //      Tft.fillScreen(65, 140, 185,260,YELLOW);
                        //     Tft.drawLine(65,185,65,260,WHITE);  
                        //      Tft.drawLine(140,185,140,260,WHITE);
                        //      Tft.drawLine(65,185,140,185,WHITE);
                        //      Tft.drawLine(65,260,140,260,WHITE);
                        //***************(125,50,200,200,125,275)
                        //      Tft.drawTriangle(105,175,155,225,105,275,RED);
                        //***** Boarder line**** I think it might look better as just two .drawLine
                        //     Tft.drawTriangle(105,173,156,225,105,276U,WHITE);
                        // POSSIBLE TO FILL RECTANGLE LIKE CIRCLE OR SQUARE FROM TFTv2 CODE?
                        ///###########################void TFT::drawTriangle( int poX1, int poY1, int poX2, int poY2, int poX3, int poY3, INT16U color)
                        //#################################{
                        //####################################drawLine(poX1, poY1, poX2, poY2,color);
                        //####################################drawLine(poX1, poY1, poX3, poY3,color);
                        //####################################drawLine(poX2, poY2, poX3, poY3,color);
                        //#################################}



                        //placer line to seperate the Days from Weather Temp #######Tft.drawLine(0,50,240,50,RED);

                        Tft.drawString("Mon:",189,0,1,WHITE);

                        Tft.drawString("Tue:",162,0,1,WHITE); 

                        Tft.drawString("Wed:",135,0,1,WHITE);

                        Tft.drawString("Thu:",108,0,1,WHITE);

                        Tft.drawString("Fri:",81, 0,1,WHITE);

                        Tft.drawString("Sat:",54, 0,1,WHITE);

                        Tft.drawString("Sun:",27, 0,1,WHITE);


                        for(int i = 1; i <= 7; i++)
                        {
                        for(int j = 0; j<7; j++)
                        {
                        //ascii for degrees is 167? source code goes to 127
                        Tft.drawString("1 F",j * 27 + 27,50,1,BLUE);
                        }                                      
                        }                                        



                        //void fillRectangle(INT16U poX, INT16U poY, 
                        //INT16U length, INT16U width, INT16U color);
                        //drawString((char*)string, poX, poY, size, fgcolor);

                        //void drawLine(INT16U x0,INT16U y0, INT16U x1,INT16U y1,INT16U color);
                        //.drawString("String", x, y,Font Size, Font Color)

                        }

                        void loop() {
                        }
