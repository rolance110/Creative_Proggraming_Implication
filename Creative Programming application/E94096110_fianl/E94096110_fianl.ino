#include <IRremote.h> 

#define LaserPIN A5
#define buzzerPin 4
// L298N 馬達驅動板
#define MotorR_I1     8  //定義 I1 接腳
#define MotorR_I2     9  //定義 I2 接腳
#define MotorL_I3    10  //定義 I3 接腳
#define MotorL_I4    11  //定義 I4 接腳
#define MotorR_ENA    5  //定義 ENA (PWM調速) 接腳
#define MotorL_ENB    6  //定義 ENB (PWM調速) 接腳
#define isObstaclePin  3
int isObstacle = LOW;

// IRremote
#define IR_Recv      2   // 定義紅外線接收接腳
IRrecv irrecv(IR_Recv);  // 宣告 IRrecv 物件來接收紅外線訊號　
decode_results results;  // 宣告解碼變數


#define IR_Advence  0x00FFA857  
#define IR_Back     0x00FF629D  
#define IR_Stop     0x00FF02FD  
#define IR_Left     0x00FF22DD  
#define IR_Right    0x00FFC23D  
#define IR_Xpp      0x00FF6897       
#define IR_Ypp      0x00FF9867
#define IR_Tpp      0x00FFB04F
#define IR_Hpp      0x00FF30CF

void LDo(){
  tone (buzzerPin,261,450);     
  delay(500);
}
void LRe(){
  tone (buzzerPin,293,450);     
  delay(500);
}
void LMi(){
  tone (buzzerPin,329,450);     
  delay(500);
}
void LFa(){
  tone (buzzerPin,349,450);     
  delay(500);
}
void LSo(){
  tone (buzzerPin,391,450);     
  delay(500);
}
void LLa(){
  tone (buzzerPin,440,450);     
  delay(500);
}
void LSi(){
  tone (buzzerPin,493,450);     
  delay(500);
}
void Do(){
  tone (buzzerPin,523,450);     
  delay(500);
}
void Re(){
  tone (buzzerPin,587,450);     
  delay(500);
}
void Mi(){
  tone (buzzerPin,659,450);     
  delay(500);
}
void Fa(){
  tone (buzzerPin,698,450);     
  delay(500);
}
void So(){
  tone (buzzerPin,783,450);     
  delay(500);
}
void HSo(){
  tone (buzzerPin,830,450);     
  delay(500);
}
void La(){
  tone (buzzerPin,880,450);     
  delay(500);
}
void Si(){
  tone (buzzerPin,987,450);     
  delay(500);
}
void HDo(){
  tone (buzzerPin,1046,450);     
  delay(500);
}
void HRe(){
  tone (buzzerPin,1174,450);     
  delay(500);
}
void HHRe(){
  tone (buzzerPin,1244,450);     
  delay(500);
}
void HMi(){
  tone (buzzerPin,1318,450);     
  delay(500);
}
void setup()
{
  Serial.begin(115200);
  pinMode(MotorR_I1,OUTPUT);
  pinMode(MotorR_I2,OUTPUT);
  pinMode(MotorL_I3,OUTPUT);
  pinMode(MotorL_I4,OUTPUT);
  pinMode(MotorR_ENA,OUTPUT);
  pinMode(MotorL_ENB,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LaserPIN,OUTPUT);
  pinMode(isObstaclePin, INPUT);
  irrecv.enableIRIn();  // 啟動紅外線解碼
  
  analogWrite(MotorR_ENA,200);    //設定馬達 (右) 轉速
  analogWrite(MotorL_ENB,200);    //設定馬達 (左) 轉速

  pinMode(isObstaclePin, INPUT); 
}

void advance(int a)    // 前進
{
    digitalWrite(MotorR_I1,HIGH); 
    digitalWrite(MotorR_I2,LOW);
    digitalWrite(MotorL_I3,HIGH); 
    digitalWrite(MotorL_I4,LOW);
    delay(a * 100);
}

void turnR(int e)    
{
    digitalWrite(MotorR_I1,HIGH);  
    digitalWrite(MotorR_I2,LOW);
    digitalWrite(MotorL_I3,LOW);  
    digitalWrite(MotorL_I4,HIGH);
    delay(e * 100);
} 

void turnL(int d)  
{
    digitalWrite(MotorR_I1,LOW);  
    digitalWrite(MotorR_I2,HIGH);
    digitalWrite(MotorL_I3,HIGH); 
    digitalWrite(MotorL_I4,LOW);
    delay(d * 100);
}  

void stopRL(int f)  //停止
{
    digitalWrite(MotorR_I1,HIGH);  
    digitalWrite(MotorR_I2,HIGH);
    digitalWrite(MotorL_I3,HIGH);  
    digitalWrite(MotorL_I4,HIGH);
    delay(f * 100);
}

void back(int g)    //後退
{
    digitalWrite(MotorR_I1,LOW);   
    digitalWrite(MotorR_I2,HIGH);
    digitalWrite(MotorL_I3,LOW);   
    digitalWrite(MotorL_I4,HIGH);
    delay(g * 100);     
}
void Xpp() //小星星
{
  digitalWrite(MotorR_I1,LOW);    //f
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,LOW);   
   digitalWrite(MotorL_I4,HIGH);  
   Do();
   Do();
   digitalWrite(MotorR_I1,LOW);    //l
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,HIGH); 
   digitalWrite(MotorL_I4,LOW);
   So();
   digitalWrite(MotorR_I1,LOW);   
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,LOW);   
   digitalWrite(MotorL_I4,HIGH);
   So();
   La();
   digitalWrite(MotorR_I1,LOW);  
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,HIGH); 
   digitalWrite(MotorL_I4,LOW);
   La();
   digitalWrite(MotorR_I1,LOW);   
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,LOW);   
   digitalWrite(MotorL_I4,HIGH);
   tone (buzzerPin,784,600);     
   delay(800);
   
   Fa();
   digitalWrite(MotorR_I1,LOW);  
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,HIGH); 
   digitalWrite(MotorL_I4,LOW);
   Fa();
   digitalWrite(MotorR_I1,LOW);   
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,LOW);   
   digitalWrite(MotorL_I4,HIGH);
   Mi();
   Mi();
   digitalWrite(MotorR_I1,LOW);  
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,HIGH); 
   digitalWrite(MotorL_I4,LOW);
   Re();
   digitalWrite(MotorR_I1,LOW);   
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,LOW);   
   digitalWrite(MotorL_I4,HIGH);
   Re();   
   Do();
   digitalWrite(MotorR_I1,HIGH);  
   digitalWrite(MotorR_I2,HIGH);
   digitalWrite(MotorL_I3,HIGH);  
   digitalWrite(MotorL_I4,HIGH);
}
void Ypp()
{
  digitalWrite(MotorR_I1,HIGH);   //f
  digitalWrite(MotorR_I2,LOW);
  digitalWrite(MotorL_I3,HIGH); 
  digitalWrite(MotorL_I4,LOW);
  tone (buzzerPin,293,300);     
  delay(350);
  tone (buzzerPin,391,300);     
  delay(350);
  tone (buzzerPin,391,300);     
  delay(350);
  tone (buzzerPin,493,300);
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,LOW);
  digitalWrite(MotorL_I3,LOW);  
  digitalWrite(MotorL_I4,HIGH);     
  delay(350);
  tone (buzzerPin,523,300);     
  delay(350);
  tone (buzzerPin,493,300);     
  delay(350);
  digitalWrite(MotorR_I1,LOW);   
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,LOW);   
  digitalWrite(MotorL_I4,HIGH);
  tone (buzzerPin,440,350);     
  delay(450);
  tone (buzzerPin,391,175);     
  delay(200);
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,LOW);
  digitalWrite(MotorL_I3,LOW);  
  digitalWrite(MotorL_I4,HIGH);
  tone (buzzerPin,440,175);     
  delay(200);
  tone (buzzerPin,493,300);     
  delay(350);
  tone (buzzerPin,493,300);     
  delay(350);
  tone (buzzerPin,493,300);     
  delay(350);
  digitalWrite(MotorR_I1,HIGH); 
  digitalWrite(MotorR_I2,LOW);
  digitalWrite(MotorL_I3,HIGH); 
  digitalWrite(MotorL_I4,LOW);
  tone (buzzerPin,493,300);     
  delay(350);
  tone (buzzerPin,440,175);     
  delay(200);
  tone (buzzerPin,493,175);     
  delay(200);
  tone (buzzerPin,440,300);     
  delay(350);
  digitalWrite(MotorR_I1,LOW);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH); 
  digitalWrite(MotorL_I4,LOW);
  tone (buzzerPin,391,300);     
  delay(350);
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH);  
  digitalWrite(MotorL_I4,HIGH);
}

void Tpp(){
  digitalWrite(MotorR_I1,LOW);   
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,LOW);   
  digitalWrite(MotorL_I4,HIGH);
  HMi();
  HHRe();
  HMi();
  HHRe();
  HMi();
  Si();
  HRe();
  HDo();
  tone (buzzerPin,880,600);     
  delay(650);
  delay(150);
  Do();
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH);  
  digitalWrite(MotorL_I4,HIGH);
  Mi();
  La();
  tone (buzzerPin,987,600);     
  delay(800);
  Mi();
  HSo();
  Si();
  tone (buzzerPin,1046,600);     
  delay(750);
  Mi();
  digitalWrite(MotorR_I1,LOW);   
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,LOW);   
  digitalWrite(MotorL_I4,HIGH);
  HMi();
  HHRe();
  HMi();
  HHRe();
  HMi();
  Si();
  HRe();
  HDo();
  tone (buzzerPin,880,600);     
  delay(750);
  Do();
  Mi();
  La();
  Si();
  Mi();
  HDo(); 
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH);  
  digitalWrite(MotorL_I4,HIGH);
  Si();
  tone (buzzerPin,880,600);     
  delay(600); 
}

void Hpp(){
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,LOW);
  digitalWrite(MotorL_I3,LOW);  
  digitalWrite(MotorL_I4,HIGH);
  Mi();
  Mi();
  Fa();
  So();
  So(); 
  Fa(); 
  Mi();
  digitalWrite(MotorR_I1,LOW);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH); 
  digitalWrite(MotorL_I4,LOW);
  Re(); 
  Do(); 
  Do(); 
  Re(); 
  Mi();
  Mi(); 
  Re(); 
  Re();
  digitalWrite(MotorR_I1,HIGH);  
  digitalWrite(MotorR_I2,HIGH);
  digitalWrite(MotorL_I3,HIGH);  
  digitalWrite(MotorL_I4,HIGH);
}

void loop() 
{
    isObstacle = digitalRead(isObstaclePin);
    
    if (isObstacle == LOW) {          //前方有障礙物
    tone (buzzerPin,1100,90);       
    delay(100);
                       
    for(int i=0;i<=2;i++){               
    digitalWrite(LaserPIN, HIGH);
    delay(100);
    digitalWrite(LaserPIN, LOW);
    delay(100);
        }
    }
    
    else{
      if(irrecv.decode(&results)){          
        switch(results.value)
        {
          case IR_Advence:
            advance(1);
            break;
            
          case IR_Back:
            back(1);
            break;
            
          case IR_Stop:
            stopRL(1);
            break;
            
          case IR_Left:
            turnL(1);
            break;
            
          case IR_Right:
            turnR(1);
            break;
            
          case IR_Xpp:
            Xpp();
            break;
            
          case IR_Ypp:
            Ypp();
            break;
            
          case IR_Tpp:
            Tpp();
            break;

          case IR_Hpp:
            Hpp();
            break;    
          default:
          Serial.print(" Unsupported");
        }    
        irrecv.resume(); // Receive the next value
      }
    }
}
