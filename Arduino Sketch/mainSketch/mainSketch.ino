
/*

      Definições Sensor MQ2

*/

int pinoSensorMQ2 = A0;           // pino do sensor MQ2
int valorMQ2ppm = 0;        

// Função que lê o pino do sensor de gás MQ2 e retorna o valor convertido para a escala ppm

int getAirQuality(int pino){

  valorMQ2ppm = analogRead(pino);
  valorMQ2ppm = map(valorMQ2ppm, 0, 1023, 200, 10000); // sei que poderia deixar a função mais enxuta, mas gostaria de deixar ela bem legível

  return valorMQ2ppm;

}

/*

    Definições Sensor de Chuva

*/



void setup() {
  Serial.begin(9600);
  pinMode(pinoSensorMQ2, INPUT);

}

void loop() {
  
  if(Serial.available() > 0){ // Primeiro, verifica se têm algum dado disponível na Serial

    String comando = Serial.readStringUntil(";");   // Vou finalizar minhas mensagens com ;

  }

}
