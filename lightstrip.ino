//
// ******** DEBUG ==== should auto config to adapt different mother board *********
//#define DATA_1 (PORTF |=  0X01)    // DATA 1    // for ATMEGA
//#define DATA_0 (PORTF &=  0XFE)    // DATA 0    // for ATMEGA
//#define STRIP_PINOUT DDRF=0xFF  // for ATMEGA
#define DATA_1 (PORTC |=  0X01)    // DATA 1    // for UNO
#define DATA_0 (PORTC &=  0XFE)    // DATA 0    // for UNO
#define STRIP_PINOUT (DDRC=0x00000001)    // for UNO


PROGMEM const unsigned long comet_1[][10]={
  {0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x000000,0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x111111,0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0x444444,0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000},
  {0xffffff,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000}
  
};



//set base color at beginning
 unsigned const long background_Landscape[10] = {0xff0000,0xdd0000,0x60FF60,0x50ff50,0x40ff40,0x30ff30,0x10ff10,0x00FF00,0x00FF00,0x00FF00};
 unsigned const long background_Clear[10] = {0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000};
 unsigned const long background_Rainbow[10] = {0xff0000,0x00ff00,0x0000ff,0xffff00,0xff00ff,0x00ffff,0x08ff08,0xff0808,0x0808ff,0xffffff};

 
 unsigned long strip_Array_0[10];
int frame_Counter = 0;

int photon_Pos = 0;
int photon_Exists = 0;
int show_Burst = 1;
int burst_Timer = 0;
uint32_t green;
uint32_t blue;
uint32_t red;
uint32_t val = 0x00000000;
int color_Channel = 0;


int ball_Exists = 0;
int ball_Pos = 9;
int ball_Up = 0;

int target_1;
int target_2;

const int pingPin = 8;
long cm;
long duration;


int pick_New_Color = 1;
int sensorValue; //value from botix
int y_1; 

int player_1_Pos; //red
int player_2_Pos; //green
int player_3_Pos; //blue


//////////////////////////////////////////

void setup() {                

   
  STRIP_PINOUT;        // set output pin - DEBUG: should auto detect which mother board for use
  randomSeed(analogRead(3));
  reset_strip();
  //noInterrupts();
 Serial.begin(9600);
 delay(2000);
 
 
 
 
}//end setup



// ***********************************************************************************************************
// *
// *                            Main Loop 
// *
// *
// ***********************************************************************************************************
void loop() 
{

// load the background first
//get_Background(2);

//get_Photon();
//get_Ball_Drop();
//get_User_Pos(1);

       for(int i=0;i<10;i++){ 
        val=0x0000000;      
         //pick three random numbers  
              red = 0;//random(1,50);
              blue = 0;//random(1,50);
              green = 255;//random(1,50);
          
              if(i==9){green=0;}
              //assemble into a 24 bit number
              Serial.println(i);
              Serial.println(green);
              val |= green << 16;
              val |= blue << 8;
              val |= red;
              // then stick it in our array
              strip_Array_0[i]=val;
             
              
        }//end 10 element loop

red=0;
blue=255;
green=0;
    val |= green << 16;
    val |= blue << 8;
    val |= red;
              // then stick it in our array
           //   strip_Array_0[6]=val;
              strip_Array_0[9]=val;
      
//NewColor.R = Color1.R - (Color1.R - Color2.R)/2;
//NewColor.G = Color1.G - (Color1.G - Color2.G)/2;
//NewColor.B = Color1.B - (Color1.B - Color2.B)/2;


///////////////////////////////////////////////////////send the final array to 
send_Strip_0();

//reset if at the end
if(frame_Counter >= 20){frame_Counter = 0;}

frame_Counter++;

delay(50); //20 frames per second
  
 }//end loop
 
 
 
/*******************************************************************************
 * Function Name  : get_Player_Pos
 * Description    : Set the appropriate analog in and calculate the pos
 *                  
 * Input          : which sensor
 *                  
 * Output         : position
 * Return         : y = position of player
 *******************************************************************************/

int get_User_Pos (int sensor){ 
  // only update 2 times a second
if(frame_Counter%10 == 0){
int y;
  
  switch (sensor) {
  case 1:
  sensorValue = analogRead(A5);
  Serial.println(sensorValue);
   break;
  }

  if(sensorValue <= 58){ y=0; }
  else if(sensorValue >= 59 && sensorValue <= 72){ y=1; }
  else if(sensorValue >= 73 && sensorValue <= 86){ y=2; }
  else if(sensorValue >= 87 && sensorValue <= 99){ y=3; }
  else if(sensorValue >= 100 && sensorValue <= 114){ y=4; }
  else if(sensorValue >= 115 && sensorValue <=128 ){ y=5; }
  else if(sensorValue >= 129 && sensorValue <= 142){ y=6; }
  else if(sensorValue >= 143 && sensorValue <= 156){ y=7; }
  else if(sensorValue >= 157 && sensorValue <= 170){ y=8; }
  else if(sensorValue >= 171 ){ y=9; }
  
  
 //duration is from the ping sensor
 /*
 if(duration < 4100){duration = 4100;}
 if(duration > 13400){duration = 13400;} 
//get the sensor mapped to one of the 10 positions
int y = map(duration, 4100, 13400, 0, 9);
*/

 y_1 = y;


   }// framecounter check

strip_Array_0[y_1] = 0xffffff;


}

void send_Strip_0(){
  
  //send the array to the strip 
  noInterrupts();
  for(int i=0;i<10;i++){

//send that to the strip. 1 block at a time
 send_strip(strip_Array_0[i]);
}
  interrupts();   


}


/*******************************************************************************
 * Function Name  : send_strip
 * Description    : Transmit 24 pulse to LED strip
 *                  
 * Input          : 24-bit data for the strip
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/
void send_strip(uint32_t data)
{
  int i;
  unsigned long j=0x800000;
  
 
  for (i=0;i<24;i++)
  {
    if (data & j)
    {
      DATA_1;
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");    
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      DATA_0;
    }
    else
    {
      DATA_1;
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");
      __asm__("nop\n\t");    
      DATA_0;
    }

    j>>=1;
  }


  
}

/*******************************************************************************
 * Function Name  : reset_strip
 * Description    : Send reset pulse to reset all color of the strip
 *                  
 * Input          : None
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/
void  reset_strip()
{
  DATA_0;
  delayMicroseconds(20);
}

void clear_Strip() {
  
  for(int i=0;i<10;i++){
    send_strip(0x000000);
  }
}


//////////////////////////////////////////////////////////////////////


/*******************************************************************************
 * Function Name  : victory_1
 * Description    : plays animation array
 *                  
 * Input          : array name, how many frames, frame rate (milli)
 *                  
 * Output         : None
 * Return         : None
 *******************************************************************************/

void victory_1(const unsigned long data[][10], int pattern_no, int frame_rate)
{
  int i=0;
  int j=0;
  uint32_t temp_data;

  for (i=0;i<pattern_no;i++)
  {
    noInterrupts();
    for (j=0;j<10;j++)
    {
      temp_data=pgm_read_dword_near(&data[i][j]);
      send_strip(temp_data);
    }
    interrupts();

    delay(frame_rate);

  }


}// victory1

void get_Background(int bkgnd){
    
//load the background colors
  
          for(int i=0;i<10;i++){
            switch(bkgnd){
              case 1:
               strip_Array_0[i] = background_Landscape[i];
                break;
              case 2:
               strip_Array_0[i] = background_Clear[i];
                break;
            }
        }

}//end get background

void get_Photon(){
   
  
if(photon_Exists){  
  
  
//move photon every half second
if(frame_Counter%10==0){
  if(photon_Pos > 1){photon_Pos -= 1;}
  else{photon_Exists = 0;}
  }//end photon animation and end collision


if(show_Burst){
  
  red  = 255;
  green  = 0;
  blue  =0;
  
      //assemble into a 24 bit number
  uint32_t val= 0x00000000;
  val |= green << 16;
  val |= blue << 8;
  val |= red;
  
  
if(frame_Counter%2==0){
      
    strip_Array_0[photon_Pos-1] = val;
    strip_Array_0[photon_Pos+1] = 0x000000;
  }
  else {
    
strip_Array_0[photon_Pos-1] = 0x000000;
strip_Array_0[photon_Pos+1] = val;

  }


/*  //fade out burst
  red  -=25;
  green  = 0;
  blue  =0;
  
      //assemble into a 24 bit number
              uint32_t val= 0x00000000;
              val |= green << 16;
              val |= blue << 8;
              val |= red

strip_Array_0[photon_Pos-1] = val;
strip_Array_0[photon_Pos+1] = val;
*/
burst_Timer++;
if(burst_Timer==9){show_Burst=0;burst_Timer=0;red=255;green=255;blue=255;}


}//end showburst

//write our position to the frame buffer
strip_Array_0[photon_Pos] = 0x0000ff;
  
} // end frame counter 


else { //create photon
photon_Pos = random(3,9);
strip_Array_0[photon_Pos] = 0x0000ff;
show_Burst = 1;
photon_Exists = 1;

} 
  
} //end get_Photon




void get_Ball_Drop(){
  
  
  
  red  = random(0,255);
  green = 0;
  blue  = 0;
  
      //assemble into a 24 bit number

  val |= green << 16;
  val |= blue << 8;
  val |= red;
  
 // val = 0x00ff0000;
  
  
 if(ball_Exists){
         //animate ball
         if(ball_Up){ball_Pos++;}else{ ball_Pos --;}
         strip_Array_0[ball_Pos]= background_Rainbow[burst_Timer];
         if(ball_Pos <= 0){ ball_Up = 1;burst_Timer++;}
         if(ball_Pos >= 9){ ball_Up = 0;}
 }
 else { //create the ball
         ball_Pos = 9;
         strip_Array_0[ball_Pos]= val;
         ball_Exists = 1;
        
 
 }// end ball_Exists

    if(burst_Timer >=9){burst_Timer = 0;}
  
} //end get_Ball_Drop


///////////////



  
/*


 
  
  

if(pick_New_Color == 1){
//set a target color position
target_0 = random(0,10);
//set color to that position
strip_Array_0[target_0] = 0x0000ff;
//set flag to not generate new color
pick_New_Color = 0;
}
else {
  strip_Array_0[target_0] = 0x0000ff;
}

// set the user position

 if(frame_Counter%10 == 0) {
 player_1_Pos = get_User_Pos(1);

 }



if (player_1_Pos == target_0){
  victory_1(comet_1,20,50);
  pick_New_Color = 1;
  
}// end if they match

strip_Array_0[player_1_Pos] = 0xffffff;

  
  
 if(frame_Counter%10 == 0) {
  //set background color
    for(int i=0;i<10;i++){ 
      
           //   uint32_t red = 0;
           //   uint32_t blue = 40;
           //   uint32_t green = 0;
              
              uint32_t red = random(1,100);
              uint32_t blue = random(1,100);
              uint32_t green = random(1,100);
              
              //assemble into a 24 bit number
              uint32_t val= 0x00000000;
              val |= green << 16;
              val |= blue << 8;
              val |= red;
              // then stick it in our array
              strip_Array_0[i]=val;
              
    }// end color loop
   
   }//end frame counter





// send a ping every other frame
if(frame_Counter%10 == 0){
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
 //inches = microsecondsToInches(duration);
 // cm = (duration / 29) / 2;

 Serial.println(duration);
 
} // end ping


  if(frame_Counter%20 == 0) {

       for(int i=0;i<10;i++){ 
               //pick three random numbers  
              uint32_t red = random(1,50);
              uint32_t blue = random(1,50);
              uint32_t green = random(1,50);
          
              
              //assemble into a 24 bit number
              uint32_t val= 0x00000000;
              val |= green << 16;
              val |= blue << 8;
              val |= red;
              // then stick it in our array
              color_Array[i]=val;
      
        }//end 10 element loop
  
  }// end frame getting random color
  */
  

