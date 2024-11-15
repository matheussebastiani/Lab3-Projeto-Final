/*
                                    Explicando o código e o sensor
  PS: Antes de começar, vou avisar, esse é o segundo sketch que estou fazendo, não pretendo mexer na ligação do circuito para tentar integrar tudo mais tarde de maneira mais fácil.
  Agora, vou comentar sobre esse sensor
  O FC-37 é um sensor que mede a presença de água em sua superfície. Basicamente, ele possui o sensor, que é uma placa composta por várias trilhas de cobre separadas umas das outras.
  A água possui nela, sais dissolvidos, que conduzem energia elétrica. Quando a água faz com que as trilhas dessa placa se encostem, uma corrente é induzida.
  O sensor é conectado a um driver, que possui um AmpOp e envia valores digitais e analógicos para os pinos de saída. O SENSOR NÃO POSSUI POLARIDADE.
  Os valores analógicos serão valores de 0 a 1023. A lógica é a seguinte: quanto maior o valor lido, menor é a concentração de água,
  tendo em vista que a resistência do sensor é inversamente proporcional à quantidade de água despejada sobre ele
*/

int sensorChuva = A1;
int valorChuva = 0;

void setup() {
  pinMode(sensorChuva, INPUT);
  Serial.begin(9600);
  Serial.println("A serial tá funcionando");
}

void loop() {

  valorChuva = analogRead(sensorChuva);
  Serial.println(valorChuva);

  delay(500);

}

// Basicamente, estou lendo os valores do sensor e mandando para a serial. Vou testar os valores que o sensor manda dependendo da quantidade de água que eu coloco sobre ele.
// O sensor é bem sensível, apenas com uma gota curto-circuitando duas trilhas, o valor caiu para cerca de 930. Com duas gotas, 780, com 3 gotas, 690. Vou usar o valor 700 como referência