int const relay1 = 4; // Relay Pintu Masuk
int const relay2 = 5; // Relay Pintu Keluar
int const relay3 = 6; // Test
int const relay4 = 7;

int const tombol_atas = 8;
int const tombol_bawah = 9;
//#define tombol_atas 8
//#define tombol_bawah 9
int const led_build_in = 13;
boolean lb1 = LOW;
boolean lb2 = LOW;
boolean onPrint = false;

//int tombol = digitalRead(tombol_karcis);
int val = 0;


void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);   
  pinMode(tombol_atas, INPUT);
  pinMode(tombol_bawah, INPUT);
}

void loop() {
program();
pintu2();  
}

void kirimData(){
  int atas = digitalRead(tombol_atas);
  int bawah = digitalRead(tombol_bawah);
  boolean toggle = false;
  boolean pressed = false;
  boolean openState = false;
  int bounce = 0;
  
  if(atas == HIGH){
    openState = true;
    pressed = true;
    toggle = true;
  }

  if(bawah == HIGH && openState){    
    toggle = false; 
    bounce++;
  }
  
  if(onPrint){
    return; 
  }
  
  if (toggle == false && pressed && onPrint == false){
      toggle = true;
      vToggle();
      bounce = 0;
      pressed = false;
      relay(); 
  }
}

void relay(){
        onPrint = true;
        digitalWrite(relay1, HIGH);
        delay(2000);
        digitalWrite(relay1, LOW);
        onPrint = false;
   }
   
void barier(){
  onPrint = true;
  digitalWrite(relay2, HIGH);
  delay(2000);
  digitalWrite(relay2, LOW);
  onPrint = false;   
}
   
void vToggle(){
  onPrint = true;
  Serial.println("1");
  onPrint = false;
}

void nToggle() {
  Serial.println("2");
}

void coba() {
  if (digitalRead(tombol_bawah) == HIGH) {  
      if (digitalRead(tombol_atas) == LOW) {
        digitalWrite(relay1, LOW);
      } else {
        Serial.println("1");
        digitalWrite(relay1, HIGH);
      }
      } 
      }
void coba2() {
  if (digitalRead(tombol_atas) == HIGH) {
      if (digitalRead(tombol_bawah) == HIGH) {
        digitalWrite(relay1, LOW); 
      } 
  }
}

void program() {
      if (onPrint == false && digitalRead(tombol_atas) != HIGH && digitalRead(tombol_bawah) == HIGH){
      kirimData();  
  }
}

void pintu2() {
  char i = Serial.read();
  if (i == 'b') {
    digitalWrite(relay2, HIGH);
    delay(2500);
    digitalWrite(relay2, LOW);
  }
}

