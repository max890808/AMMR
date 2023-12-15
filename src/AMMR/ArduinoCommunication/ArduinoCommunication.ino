int left = 8;
int right = 9;
char data = '0';

void setup()
{
    Serial.begin(9600);
    pinMode (left, OUTPUT);
    pinMode (right, OUTPUT);
    pinMode (13, OUTPUT);
}

void loop()
{
    if(Serial.available())
    {
          data = Serial.read();
          Serial.println(data);
          if(data == '0'){
              digitalWrite(left, LOW);
              digitalWrite(13, LOW);
          }
          else if(data == '1'){
              digitalWrite(left, HIGH);
              digitalWrite(13, HIGH);
            }
          else if (data == '2')
              digitalWrite(right, LOW);
          else if (data == '3')
              digitalWrite(right, HIGH);
          else
              ;
    }
}
