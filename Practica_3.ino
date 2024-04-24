/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Fundamentos de programación 
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 18 de abril
*/

#define switch_avance 2  
#define switch_retroceso 3
#define configINPUT(pin) pinMode(pin, INPUT)
#define pausa delay(500)

struct datos_producto
{
  String nombre_producto;
  byte stock;
};

byte producto_seleccionado = 0;

datos_producto producto_stock[4] = {
{"Tortrix", 40},
{"Doritos", 60},
{"Lays", 50},
{"Takis", 25}
};

void setup() {
  Serial.begin(9600);
  configINPUT(switch_avance);
  configINPUT(switch_retroceso);
  Serial.println("Bienvenido(a)");
}

void loop() {
  if (digitalRead(switch_avance) == HIGH) {
    producto_seleccionado = (producto_seleccionado + 1) % 4;
    Serial.println("El nombre del producto es: " + producto_stock[producto_seleccionado].nombre_producto);
    Serial.println("La cantidad del producto es: " + String(producto_stock[producto_seleccionado].stock));
    Serial.println("");              
    pausa;
  }

  if (digitalRead(switch_retroceso) == HIGH) {
    producto_seleccionado = (producto_seleccionado - 1 + 4) % 4;
    Serial.println("El nombre del producto es: " + producto_stock[producto_seleccionado].nombre_producto);
    Serial.println("La cantidad del producto es: " + String(producto_stock[producto_seleccionado].stock));
    Serial.println("");              
    pausa;
  }
}   
