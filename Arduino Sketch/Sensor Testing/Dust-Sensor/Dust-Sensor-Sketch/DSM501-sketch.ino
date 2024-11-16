/*
                                                                            O sensor de Poeira DSM501A
    *  Esse sensor possui a capacidade de detectar poeira e fumaça, sendo capaz de detectar partículas pequenas em um espaço de até trinta metros cúbicos.
    *  Ele é capaz também de detectar poeiras finas e partículas de até um micrômetro.
    *  Ele converte sua medição em sinais digitais de PWM.
    *  Para calcular sua medição, é necessário medir a soma do tempo em que os pulsos enviados pelo sensor permaneceram em nível lógico baixo em uma amostra de 30 segundos e converter esse valor para uma porcentagem.
    *  Esse sensor possui uma característica específica. Ele precisa permanecer pelo menos um minuto ligado até que ele se estabilize. 
       Por isso, vamos colocar um delay em nosso código logo após ligarmos o sensor, para seguirmos a recomendaçaõ do fabricante
    *  A unidade de medida é pcs/0.01cf. Ou seja, "pedaços" a cada 0.01 pés cúbicos. Ou seja, quantas peças medidas teriam em um volume de 0.01 pés cúbicos (o equivalente a 0,283 litros);
    Podemos dizer que essa unidade de media equivale à mesma quantidade de grãos dissolvidos em um volume de 0,283 litros, ou 283 ml.
    * A equação da curva característica do sensor é a seguinte: concentração =   1.1*pow(porcentagem_low,3)-3.8*pow(porcentagem_low,2)+520*porcentagem_low+0.62;
    Os pinos do sensor são: 
    1	Controle 1	Saída de controle 1
    2	Vout 2	saída de tensão 2
    3	VCC	Alimentação (5V)
    4	Vout 1	Saida de tensão 1
    5	GND	GND

  Vout2: Porta de saída normal. Essa porta detecta partículas que estão acima de 1 micrômetro.
  Vout1: A sensibilidade de Vout 1 é duas vezes e meia mais lento que Vout 2. Isso significa que o tamanho da partícula é 2.5 micrômetros. A saída também é ajustável.
  Controle 1: Esse pino ajusta a sensibilidade do Vout1.

  Para esse caso, vamos usar o pino 2 (Vout2) no pino digital 8 do Arduino
*/

int pinoSensPoeira = 8;
unsigned long duracao = 0;
unsigned long tempo_inicio = 0;
unsigned long tempo_final = 0;
unsigned long tempo_amostragem_ms = 30000; // tempo de amostragem dos sinais recebidos do sensor
unsigned long duracao_pulso_low = 0;
float porcentagem = 0;
float concentracao = 0;

int contador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoSensPoeira, INPUT);
  tempo_inicio = millis(); //timestamp de execução do Arduino em ms
  Serial.println("Aguardando 1 minuto para estabilização");
  delay(60000);
}

void loop() {
  
  duracao = pulseIn(pinoSensPoeira, LOW); //função pulseIn: mede o tempo que um pulso fica em low/high EM MICROSSEGUNDOS
  duracao_pulso_low += duracao;           //incrementa o acumulador para encontrarmos o tempo total em que o sinal ficou em nivel lógico baixo
  tempo_final = millis();
  if((millis() - tempo_inicio) > tempo_amostragem_ms){ // checa se os 30 segundos se passaram
      
    porcentagem = (duracao_pulso_low) / (tempo_amostragem_ms * 10.0); // encontrando quantos % do tempo de amostragem o sinal ficou em low
    concentracao = 1.1 * pow(porcentagem, 3) - 3.8 * pow(porcentagem, 2) + 520 * porcentagem + 0.62;                     // essa foi a curva característica que eu encontrei para o sensor
    Serial.print("Tempo que o sinal ficou em nível lógico baixo: ");
    Serial.println(duracao_pulso_low/1000); // valor em milissegundos
    Serial.print("Valor em porcentagem: ");
    Serial.println(porcentagem);
    Serial.print("Concentração de partículas: ");
    Serial.println(concentracao);
    Serial.print("\n\n");

    duracao_pulso_low = 0; // reseta as variáveis para a próxima medição
    tempo_inicio = millis();

  
  }

  //Serial.println(++contador);

}

// Esse sensor é bem estranho e tem bem pouca documentação sobre ele, mas acho que assim está funcionando. Espirrei um jato de desodorante perto dele e as partículas que ele estava medindo aumentaram
// consideravelmente de quantidade. Após um tempo, o valor se estabilizou novamente para o valor ambiente. Valor do meu quarto: 634.97 pcs/0.01cf
// Esse sensor é bem lento e geralmente sua primeira medição é bem ruidosa.
// Ele é lento pois precisa de 30 segundos para coletar seus dados, analisando as amostragens de tempo e suas medições podem variar um pouco
/*
  Vamos considerar uma faixa de valores para a quantidade de partículas lidas pelo sensor:
  Concentração de poeira < 1000 pcs/283ml -> Ar ambiente limpo
  Concentração de poeira > 1000 e < 10000 -> Ar ambiente bom
  Concentração de poeira > 10000 e < 20000 -> Concentração aceitável de partículas
  Concentração de poeira > 20000 e < 50000 -> Ar ambiente pesado
  Concentraçaõ de poeira > 50000           -> Ar ambiente prejudicial

*/




