// CONFIGURACIÓN DE PINES

const int LED_ROJO = 13;
const int LED_AMARILLO = 12;
const int LED_VERDE = 11;
const int BOTON = 2;

// VARIABLES

int modo = 0;  

int estadoBoton;
int ultimoEstadoBoton = HIGH;

unsigned long tiempoAnterior = 0;
unsigned long intervalo = 0;

unsigned long debounceTiempo = 0;
const unsigned long debounceDelay = 200;

int estadoSemaforo = 0;
bool estadoParpadeo = false;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {

  // CONTROL DEL BOTÓN

  int lectura = digitalRead(BOTON);

  if (lectura == LOW && ultimoEstadoBoton == HIGH && (millis() - debounceTiempo) > debounceDelay) {
    modo++;
    if (modo > 4) modo = 0;   
    debounceTiempo = millis();
  }

  ultimoEstadoBoton = lectura;

  // ESTADOS PRINCIPAL

  switch (modo) {

    case 0: 
      semaforoAutomatico();
      break;

    case 1: 
      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_AMARILLO, LOW);
      digitalWrite(LED_VERDE, HIGH);
      break;

    case 2: 
      parpadeoGeneral(500);
      break;

    case 3: 
      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_VERDE, LOW);
      parpadeoAmarillo(500);
      break;

    case 4: 
      digitalWrite(LED_ROJO, LOW);
      digitalWrite(LED_AMARILLO, LOW);
      digitalWrite(LED_VERDE, LOW);
      break;
  }
}

// FUNCIONES

void parpadeoGeneral(unsigned long intervaloLocal) {
  if (millis() - tiempoAnterior >= intervaloLocal) {
    tiempoAnterior = millis();
    estadoParpadeo = !estadoParpadeo;

    digitalWrite(LED_ROJO, estadoParpadeo);
    digitalWrite(LED_AMARILLO, estadoParpadeo);
    digitalWrite(LED_VERDE, estadoParpadeo);
  }
}

void parpadeoAmarillo(unsigned long intervaloLocal) {
  if (millis() - tiempoAnterior >= intervaloLocal) {
    tiempoAnterior = millis();
    estadoParpadeo = !estadoParpadeo;
    digitalWrite(LED_AMARILLO, estadoParpadeo);
  }
}

void semaforoAutomatico() {

  if (millis() - tiempoAnterior >= intervalo) {

    tiempoAnterior = millis();

    switch (estadoSemaforo) {

      case 0: 
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_VERDE, HIGH);
        intervalo = 2000;
        estadoSemaforo = 1;
        break;

      case 1: 
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_AMARILLO, HIGH);
        digitalWrite(LED_VERDE, LOW);
        intervalo = 1000;
        estadoSemaforo = 2;
        break;

      case 2: 
        digitalWrite(LED_ROJO, HIGH);
        digitalWrite(LED_AMARILLO, LOW);
        digitalWrite(LED_VERDE, LOW);
        intervalo = 2000;
        estadoSemaforo = 3;
        break;

      case 3: 
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_AMARILLO, HIGH);
        digitalWrite(LED_VERDE, LOW);
        intervalo = 1000;
        estadoSemaforo = 0;
        break;
    }
  }
}