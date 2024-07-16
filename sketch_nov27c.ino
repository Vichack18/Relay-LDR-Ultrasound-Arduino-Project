
const int rele=8;
int fotores=A5;
int resultado=0;
const int eco=4;
const int trig=5;

int tiempopulso; // variables del ultrasonido //
int distfin;

void setup() {
  // put your setup code here, to run once:
 pinMode ( rele, OUTPUT);
 pinMode (fotores , INPUT);

 pinMode (eco , INPUT);
 pinMode (trig , OUTPUT);

 Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 resultado=analogRead (fotores); // nos va a mostrar entre 0 y 1023 la fotoresistencia //

 Serial.print ( " fotoresist \t "); // esto es igual que la palabra "ultra" del ultrasonido, para separar datos //
 // \t es una accion que nos permite en el monitor serial darle un tab o espacio a los datos //
 // mostrara asi:    fotoresist  800
//                 ultra 20   //

// Ahora necesitamos saber con precision la luz del ambiente, ya que 500 es un estimativo que pusimos //
// Necesitamos calibrarlo //
 Serial.println ( resultado );

 digitalWrite ( trig , HIGH);
 delayMicroseconds ( 5 );      // esto para ultrasonido //
 digitalWrite (trig , LOW);

tiempopulso = pulseIn ( eco , HIGH); // funciones ultrasonido //
distfin = 0.034 / 2 * tiempopulso;

Serial.print ("ultra");  // resultado del ultra sonido, se pone "ultra" como para separar ya que vamos a tener //
// dos resultados en numero, el del ultra sonido y el de la fotoresistencia, entonces nos quedara //
// 800 ultra 20 //

Serial.println ( distfin );

 if (resultado >= 800 && distfin <=10 ){ // cuanta mayor oscuridad, mayor va a ser el numero //
 // se le agrega el distfin <= 10 ya que este programa va hacer que el arduino cuando detecte oscuridad y a la vez //
 // detecte acercamiento ( menor a 10 ), prenda la lampara, es una conjuncion donde debe ser verdadero y verdadero //
 
      digitalWrite (rele, LOW); // algunas placas de rele se prenden con un LOW o con un HIGH ( analizar segun fabricante)
  // o verificar probando primero antes que nada, para no generar problemas de conexion despues //
      delay (500); // siempre tener un minimo de 500 de t al ser un dispositivo que trabaja con imanes, etc //
 }

 else {
      digitalWrite ( rele , HIGH);
      delay (500);
 }

}
