int xpos = 0;
int ypos = 350;
int size = 100;
int speed = 0;
int overlap = 0;

void setup() {
  size(400, 400);
  background(122,255,255);
  fill(238,131,37);
  rect(xpos,ypos,400,200);
  rectMode(CORNER);
  textSize(20);
}

void draw(){
  setup();
  overlap = size - (400-speed);
  speed += 5 ;
  fill(255);
  rect(xpos + speed,ypos - size,size,size);
  rect(xpos,ypos - size,overlap,size);
  if(speed >= (400)){
    speed = 0; 
  }
}
