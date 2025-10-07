#define scr_trig     8   // Pin digital para disparar el SCR
#define pot        A1    // Potenciómetro en A1 (antes estaba en A0)

volatile bool ZC = 0;    // Bandera de cruce por cero (debe ser volatile)
uint16_t alpha;          // Retardo en microsegundos

void setup(void) {
  pinMode(scr_trig, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);   // LED de prueba
  digitalWrite(scr_trig, LOW);

  // Interrupción externa INT0 en pin digital 2 (D2 en Arduino UNO)
  attachInterrupt(digitalPinToInterrupt(2), ZC_detect, FALLING);
}

void ZC_detect() {
  ZC = 1;   // Marca que ocurrió un cruce por cero
}

void loop() {
  if(ZC){
    // Retardo proporcional al potenciómetro
    delayMicroseconds(alpha);

    // Pulso de disparo al SCR
    digitalWrite(scr_trig, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);   // LED ON cuando dispara
    delay(1);                          // ancho de pulso ~1 ms
    digitalWrite(scr_trig, LOW);
    digitalWrite(LED_BUILTIN, LOW);    // LED OFF

    // Reset de la bandera de cruce
    ZC = 0;

    // Escala del potenciómetro (0–1023) → (0–10000 µs)
    alpha = analogRead(pot) * 10;
    if(alpha > 10000)
      alpha = 10000;
  }
}
