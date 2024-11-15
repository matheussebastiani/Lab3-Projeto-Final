//Agora vamos testar a Luminosidade de um LDR
//Basicamente o LDR é um resistor variável em função da luminosidade. Então, vou colocar ele em série com um resistor de 10K 
//e medir a tensão sobre ele com um pino do Arduino. Vou testar quais limiares utilizarei.
// Agora é final de tarde. Medirei a luminosidade com a janela aberta, incidindo luz sobre ele, com a janela fechada e com a luz ligada
// não sei como converter para valores de lumens, então classificarei de acordo com minha interpretação.

int pinoLDR = A3;
int valorLuminosidade = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("A serial tá funcionando");
  pinMode(pinoLDR, INPUT);

}

void loop() {
  valorLuminosidade = analogRead(pinoLDR);
  Serial.println(valorLuminosidade);
  delay(500);

}

//Valor com luminosidade alta (luz ligada): 700 (com a lanterna do celular incidindo luz sobre ele: 420 a 440)
//Valor incidindo a luz solar de fim de tarde: Cerca de 620 a 650. Considerarei essa faixa como luminosidade média
//Valor com a luz apagada e janela fechada: casa dos 1000