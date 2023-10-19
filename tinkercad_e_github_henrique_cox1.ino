int ledPin = 8; // Pino conectado ao LED
int tempoAceso = 1000; // Tempo que o LED fica aceso em milissegundos (1 segundo)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); // Liga o LED
  delay(tempoAceso); // Aguarda 1 segundo
  digitalWrite(ledPin, LOW); // Desliga o LED
  delay(tempoAceso); // Aguarda 1 segundo novamente
}
