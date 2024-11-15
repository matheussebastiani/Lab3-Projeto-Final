/*
  Este Sketch terá a finalidade de testar o funcionamento do módulo contendo o sensor de gás MQ-2.
  Esse sensor detecta a concentração de gases liquefeitos de petróleo, como fumaça, álcool, propano, hidrogênio e CO, lendo valores de 200 a 10.000ppm
  Seu uso é interessante para monitorar a qualidade do ar. Ele é apenas utilizado para medir a densidade de um gás conhecido na atmosfera, mas não diferencia os gases
  UNIDADE DE MEDIDA PPM: Partes por milhão (ppm) indica a quantidade, em gramas, de soluto presente em 1000000 gramas da solução.
  Basicamente, essa unidade de medida indica quantas gramas da particula medida haveria dissolvida em uma solução de 1000000 gramas.

  O módulo utilizado pode ser verificado no seguinte link: https://www.usinainfo.com.br/blog/sensor-de-gas-arduino-mq-2-para-gases-inflamaveis-e-fumaca/

  Basicamente o módulo possui 4 pinos:
  * Dois pinos de alimentação (VCC e GND)
  * Um pino digital, que indica a presença do gás na atmosfera
  * Um pino analógico, que apresenta valores no intervalo de 0 a 5V, indicando a densidade dos gases conhecidos na atmosfera (ou em torno do sensor, melhor dizendo)

  O sketch em questão é bem parecido com os de exemplos, vou tentar converter um valor de tensão para a unidade de medida ppm, para enviá-lo à aplicação do Qt.

  Como o TinkerCad não possui o módulo, é um pouco mais difícil ter algo mais visual, vou tentar anexar algumas fotos da ligação elétrica para este software, mas não ficará tão bonito e visual quanto no TinkerCad.
  Vou usar apenas o pino Analógico na porta A0 e alimentar o módulo, beeeem simples, apenas para ler o valor

*/

int pinoSensor = A0;  // definiçaõ do pino do Arduino para leitura do sensor
int valorConvertido = 0;  //vou converter o valor analógico para ppm e printar na serial com essa variável aqui


void setup() {
  Serial.begin(9600);   // definição da porta serial para comunicação
  Serial.println("A serial tá funcionando\n");
}

void loop() {
  
  delay(10000);
  valorConvertido = analogRead(pinoSensor);
  valorConvertido = map(valorConvertido, 0, 1023, 200, 10000);  //O Arduino lê valores de 0 a 1023, a função map basicamente converte escalas matematicamente. 
                                                                // seus parâmetros são: valor lido, valor mínimo da escala que está o valor lido, valor máximo da escala, 
                                                                // valor mínimo da escala a ser convertida e valor máximo da escala a ser convertida
  Serial.println(valorConvertido);
  Serial.println("ppm");

}

// Fiz o teste aproximando um Isqueiro do sensor e liberando o gás do Isqueiro, foi possível verificar um drástico aumento na concentração de gases no entorno do sensor, na escala convertida (ppm)
// Após afastar o Isqueiro, o valor volta a se estabilizar depois de um certo tempo
// Primeiro Sensor OK! Tranquilo de usar.
