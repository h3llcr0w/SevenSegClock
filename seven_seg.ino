#define S2 A5
#define S1 A4
#define M2 A3
#define M1 A2
#define H2 A1
#define H1 A0
#define SET 9
#define INC 10
  byte digitArray[11][7] = { { 0,0,0,0,0,0,1 }, // = 0
                           { 1,0,0,1,1,1,1 }, // = 1
                           { 0,0,1,0,0,1,0 }, // = 2
                           { 0,0,0,0,1,1,0 }, // = 3
                           { 1,0,0,1,1,0,0 }, // = 4
                           { 0,1,0,0,1,0,0 }, // = 5
                           { 0,1,0,0,0,0,0 }, // = 6
                           { 0,0,0,1,1,1,1 }, // = 7
                           { 0,0,0,0,0,0,0 }, // = 8
                           { 0,0,0,1,1,0,0 }, // = 9
                           { 1,1,1,1,1,1,1 } // = off
                         };
long previousMillis = 0;                         
long previousMillis2 = 0;                         
long interval = 1000; 
long interval2 = 500;
int led=0;
int hh=00,mm=54,ss=00;
int set=0;
void setup()
{
  Serial.begin(9600);
  int i;
  for(i=2;i<9;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
}
void loop()
{
  if(digitalRead(SET)==HIGH)
    {
      set=(set+1)%4;
      delay(500);
    }
  if(set==0)
  {
  unsigned long currentMillis = millis();
  /*for(p=0;p<10;p++)
   { for(q=0;q<10;)
      {*/
      if(currentMillis - previousMillis2 > interval2) 
        {
          previousMillis2 = currentMillis;
          analogWrite(11,led);
          if(led==0)
          led=8;
          else
          led=0;
        }
        if(currentMillis - previousMillis > interval) 
        {
          previousMillis = currentMillis;
          ss++;
          if(ss/60!=0)
          {
            ss%=60;
            mm++;
          }
          if(mm/60!=0)
          {
            mm%=60;
            hh++;
          }
          if(hh%12==0)
          {
            hh%=12;
          }
        }
        
      }
   if(set==1)
   {   if(digitalRead(INC)==HIGH)
       {
           hh=(hh+1)%12;
          delay(200);
       }
   }
   if(set==2)
   {
      if(digitalRead(INC)==HIGH)
      {    
          mm=(mm+1)%60;
         delay(200);
      }
   }
   if(set==3)
   {
      if(digitalRead(INC)==HIGH)
      {  
          ss=(ss+1)%60;
          delay(200);
      }
   }
        dispnum(S2,ss%10);
        dispnum(S1,ss/10);
        dispnum(M2,mm%10);
        dispnum(M1,mm/10);
        dispnum(H2,hh%10);
        dispnum(H1,hh/10);
      
   
  
}

void dispnum(int i,int k)
{
  int j,l;
  for(j=A0;j<A6;j++)
    {  
      digitalWrite(j,LOW);
    }
  digitalWrite(i,HIGH);
  
  for(l=2;l<9;l++)
    digitalWrite(l,digitArray[k][l-2]);
    delay(2);
  
}
