/* led num */
int ledNum = 3;

/* pins for gnd */
int gnd[3] = {0, 1, 2};

/* pins for vs */
int vs1[3] = {3, 4, 5};
int vs2[3] = {6, 7, 8};
int vs3[3] = {9, 10, 11};
int vs[3][3] = {
  {vs1[0],vs1[1],vs1[2]},
  {vs2[0],vs2[1],vs2[2]},
  {vs3[0],vs3[1],vs3[2]}
};

/* blink per second */
int bps = 3;

/* flame per second */
int fps = 120;

void setup() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      pinMode(vs[i][j], OUTPUT);
    }
    pinMode(gnd[i], OUTPUT);
  }

  all();
  delay(1000);

  cls();
  delay(1000);
}

int state = 0;

void loop() {
  switch (state) {
    case 0:
      patternRand(10, 2);
      break;
    case 1:
      pattern1(3);
      break;
    case 2:
      pattern2(1);
      break;
    case 3:
      pattern3(0);
      break;
  }
}

void patternRand(int times, int next) {
  for (int i = 0; i < times; i++) {
    cls();
    int randX = random(ledNum);
    int randY = random(ledNum);
    int randZ = random(ledNum);
    digitalWrite(gnd[randZ], LOW);
    digitalWrite(vs[randX][randY], HIGH);
    delay(fps);
  }
  
  state = next;
}

void pattern1(int next) {
  all();

  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], HIGH);
  digitalWrite(gnd[2], HIGH);
  delay(fps);
  digitalWrite(gnd[0], HIGH);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[2], HIGH);
  delay(fps);
  digitalWrite(gnd[0], HIGH);
  digitalWrite(gnd[1], HIGH);
  digitalWrite(gnd[2], LOW);
  delay(fps);
  
  digitalWrite(gnd[0], HIGH);
  digitalWrite(gnd[1], HIGH);
  digitalWrite(gnd[2], LOW);
  delay(fps);
  digitalWrite(gnd[0], HIGH);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[2], HIGH);
  delay(fps);
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], HIGH);
  digitalWrite(gnd[2], HIGH);
  delay(fps);
  
  state = next;
}

void pattern2(int next) {
  cls();

  for(int i=2; i>=0; i--){
    if(i == 2){
      digitalWrite(gnd[i], LOW);
    }else{
      digitalWrite(gnd[i+1], HIGH);
      digitalWrite(gnd[i], LOW);
    }

    digitalWrite(vs[2][2], HIGH);
    delay(fps);

    digitalWrite(vs[2][2], LOW);
    digitalWrite(vs[2][1], HIGH);
    delay(fps);

    digitalWrite(vs[2][1], LOW);
    digitalWrite(vs[2][0], HIGH);
    delay(fps);

    digitalWrite(vs[2][0], LOW);
    digitalWrite(vs[1][0], HIGH);
    delay(fps);

    digitalWrite(vs[1][0], LOW);
    digitalWrite(vs[0][0], HIGH);
    delay(fps);

    digitalWrite(vs[0][0], LOW);
    digitalWrite(vs[0][1], HIGH);
    delay(fps);

    digitalWrite(vs[0][1], LOW);
    digitalWrite(vs[0][2], HIGH);
    delay(fps);


    digitalWrite(vs[0][2], LOW);
    digitalWrite(vs[1][2], HIGH);
    delay(fps);

    digitalWrite(vs[1][2], LOW);
  }
  
  state = next;
}

void pattern3(int next) {
  int t = 10;
  for (int i=0; i<100; i++) {
    cls();
    digitalWrite(gnd[0], LOW);
    digitalWrite(gnd[1], HIGH);
    digitalWrite(gnd[2], LOW);
    digitalWrite(vs[0][0], HIGH);
    digitalWrite(vs[0][1], HIGH);
    digitalWrite(vs[0][2], HIGH);
    digitalWrite(vs[1][0], HIGH);
    digitalWrite(vs[1][2], HIGH);
    digitalWrite(vs[2][0], HIGH);
    digitalWrite(vs[2][1], HIGH);
    digitalWrite(vs[2][2], HIGH);
    delay(fps/t);
    cls();
    digitalWrite(gnd[0], HIGH);
    digitalWrite(gnd[1], LOW);
    digitalWrite(gnd[2], HIGH);
    digitalWrite(vs[0][0], HIGH);
    digitalWrite(vs[0][2], HIGH);
    digitalWrite(vs[2][0], HIGH);
    digitalWrite(vs[2][2], HIGH);
    delay(fps/t);
  }
  
  all();
  delay(fps);
  
  state = next;
}

void all() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(vs[i][j], HIGH);
    }
    digitalWrite(gnd[i], LOW);
  }
}

void cls() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(vs[i][j], LOW);
    }
    digitalWrite(gnd[i], HIGH);
  }
}

