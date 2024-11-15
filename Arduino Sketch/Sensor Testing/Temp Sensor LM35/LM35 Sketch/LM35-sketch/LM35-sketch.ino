// Aqui vai ser basicamente a leitura de temperatura de um LM35, convertendo o valor de tensão para graus Celisius, extremamente simples


int pinoLM35 = A2;
float temperatura = 0;

float mediaTemperatura(int pinoSensor){ //essa função retornará uma média de 10 amostras da temperatura ambiente, para não haver tanta variação assim
  
  float temp = 0;
  
  for(int i = 0; i < 10; i++){

    temp += analogRead(pinoSensor) * ((5.0/1023.0) * 100.0);
    
    delay(100);
  }

  return temp / 10.0;

}

void setup() {
  Serial.begin(9600);
  Serial.println("A serial tá funcionando!");
  pinMode(pinoLM35, INPUT);
}

void loop() {
  
  temperatura = mediaTemperatura(pinoLM35);
  Serial.println(temperatura);
  
  delay(500);

}

// É importante citar que: como o sensor é analógico, a temperatura varia seguidamente
