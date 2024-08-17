int UVOUT = A0; // Saida do sensor

void setup()
{
  analogReference(INTERNAL2V56);
  //analogReference(EXTERNAL);
  pinMode(UVOUT, INPUT); //Entrada da leitura do sensor no arduino
  
  Serial.begin(115200);  
}

void loop()
{
  int uvLevel = averageAnalogRead(UVOUT); 
 // int refLevel = averageAnalogRead(REF_3V3);
  Serial.println(uvLevel*2.56/1024);
  
  delay(1000);
}

//Função para tirar uma média de leitura do pino
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0; 

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
    runningValue /= numberOfReadings;
    return(runningValue);  
}
