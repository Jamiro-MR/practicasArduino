//Gutierrez Bejarano Braulio Roberto 4-D

const char DIGITOS[] = {
  0b00111111, // 0 
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
  0b01110111, // A
  0b01111100, // b
  0b00111001, // C
};

int bebidaA = 7, bebidaAB = 8, bebidaAC = 9, oneCoin = 13, twoCoin = 14, fiveCoin = 15, tenCoin = 16;

int currentDisplay;
bool DA = false, DB = false, DC = false;
int money = 0;

void setup() {
  currentDisplay = 0;
  DDRD = 0b11111111;
  DDRB = 0b00011100;
  pinMode(bebidaA, INPUT_PULLUP);
  pinMode(bebidaB, INPUT_PULLUP);
  pinMode(bebidaC, INPUT_PULLUP);
  pinMode(oneCoin, INPUT_PULLUP);
  pinMode(oneCoin, INPUT_PULLUP);
  pinMode(fiveCoin, INPUT_PULLUP);
  pinMode(tenCoin, INPUT_PULLUP);
}

void loop() {
  addMoney();
  selectbebida();
  showMoney();
  multiplex();
}

void addMoney(){
  if(digitalRead(13)){
    money += 1;
  }else if(digitalRead(14)){
    money += 2;
  }else if(digitalRead(15)){
    money += 5;
  }else if(digitalRead(16)){
    money += 10;
  }
}

void selectbebida(){
  if(digitalRead(bebidaA)){
    if(!(money < 10)){
      money -= 10;
      digitalWrite(17, HIGH);
      DA = true;
    }
  }else if(digitalRead(bebidaB)){
    if(!(money < 10)){
      money -= 10;
      digitalWrite(17, HIGH);
      DB = true;
    }
  }else if(digitalRead(bebidaC)){
    if(!(money < 10)){
      money -= 10;
      digitalWrite(17, HIGH);
      DC = true;
    }
  }
}

void showMoney(){
  int select = 0;
  if(DA == true){
    select = 10;
  }else if(DB == true){
    select = 11;
  }else if(DC == true){
    select = 12;
  }
  
  switch(currentDisplay){
    case 0: PORTB = DIGITOS[money / 10]; break;
    case 1: PORTB = DIGITOS[money % 10]; break;
    case 3: PORTB = DIGITOS[select]; break;
  }
}

void multiplex() {
  PORTB = 0b00011100;
  switch(currentDisplay) {
    case 0: PORTB = 0b00011000; break;
    case 1: PORTB = 0b00010100; break;
    case 2: PORTB = 0b00001100; break;
  }

  currentDisplay++;
  if (currentDisplay > 2)
    currentDisplay = 0;
}
