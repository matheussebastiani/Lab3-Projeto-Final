
/*

      Definições Sensor MQ2

*/

int pinoSensorMQ2 = A0;           // pino do sensor MQ2
int valorMQ2ppm = 0;        

// Função que lê o pino do sensor de gás MQ2 e retorna o valor convertido para a escala ppm

int getAirQuality(int pino){
  delay(10);
  valorMQ2ppm = analogRead(pino);
  valorMQ2ppm = map(valorMQ2ppm, 0, 1023, 200, 10000); // sei que poderia deixar a função mais enxuta, mas gostaria de deixar ela bem legível

  return valorMQ2ppm;

}

/*

    Definições Sensor de Chuva

*/

int pinoSensorChuva = A1;
int valorChuva = 0;

int getValorChuva(int pino){ // Sei que essa função é desnecessária, mas acho interessante deixar o loop principal mais limpo, deixando o código mais modularizado e setorizado

  valorChuva = analogRead(pino);
  return valorChuva;

}

/*

    Definições Sensor LM35

*/

int pinoLM35 = A2;
float temperatura = 0;

float TemperaturaMedia(int pino){ // Esse sensor é um sensor analógico. como suas medições variam bastante, vou fazer uma média de vários valores lidos, para a temperatura não ficar variando tanto

  float temperatura = 0;

  int n = 10;
  
  while(n--){

    temperatura += analogRead(pino) * ((5.0/1023.0) * 100.0); // Converte valores de tensão para graus celsius

    delay(100);

  }

  return temperatura / 10.0; // Retorna uma média de 10 amostras

}


/*

    Definições LDR

*/

int pinoLDR = A3;
int valorLuminosidade = 0;

int getLuminosidade(int pino){ // também analógico (na verdade um resistor) mas mais facilmente filtrável
  
  valorLuminosidade = analogRead(pino);

  return valorLuminosidade;

}


/*

    Definições Sensor UV
    Lembrete: não esquecer de tratar as escalas UV baseados nos níveis de tensão do sensor
    A tabela tá no sketch do sensor

*/

int pinoUV = A4;
float tensaoSaida;
float valorSensorUV;

float getTensaoUV(int pino){

  valorSensorUV = analogRead(pino);
  tensaoSaida = valorSensorUV / (1024.0*5.0) * 1000;   // Convertendo o valor para mili Volts. A saída do sensor varia entre 0 e 1 V;
  return tensaoSaida;


}

float getValorUV(int pino){
  valorSensorUV = analogRead(pino);
  return valorSensorUV;
}

/*

    Definições Sensor de Poeira
    não vou continuar agora pq to com medinho

*/


int pinoSensorPoeira = 8;         // pino digital 8
unsigned long duracao = 0;        // medições de tempo serão necessárias para esse sensor
unsigned long tempo_inicio = 0;
unsigned long tempo_final = 0;
unsigned long tempo_amostragem_ms = 30000;
unsigned long duracao_pulso_low = 0;
float porcentagem = 0;
float concentracao = 0;

float getConcentracaoPoeira(int pino){

  while((millis() - tempo_inicio) < tempo_amostragem_ms){

    duracao = pulseIn(pino, LOW); //função pulseIn: mede o tempo que um pulso fica em low/high EM MICROSSEGUNDOS
    duracao_pulso_low += duracao;           //incrementa o acumulador para encontrarmos o tempo total em que o sinal ficou em nivel lógico baixo

  }

  porcentagem = (duracao_pulso_low) / (tempo_amostragem_ms * 10.0); // encontrando quantos % do tempo de amostragem o sinal ficou em low
  concentracao = 1.1 * pow(porcentagem, 3) - 3.8 * pow(porcentagem, 2) + 520 * porcentagem + 0.62;                     // essa foi a curva característica que eu encontrei para o sensor
  
  duracao_pulso_low = 0; // reseta as variáveis para a próxima medição
  tempo_inicio = millis();
  
  return concentracao;


}


void setup() {
  Serial.begin(9600);
  pinMode(pinoSensorMQ2, INPUT);
  pinMode(pinoSensorChuva, INPUT);
  pinMode(pinoLM35, INPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoUV, INPUT);
  pinMode(pinoSensorPoeira, INPUT);
  tempo_inicio = millis();

}

char comando;

void loop() {
  
  if(Serial.available() > 0){ // Primeiro, verifica se têm algum dado disponível na Serial

    comando = Serial.read();

  }

  if(comando == 'r'){

    Serial.println(getAirQuality(pinoSensorMQ2));

  }


}
