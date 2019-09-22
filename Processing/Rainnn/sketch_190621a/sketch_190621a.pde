rainDrop[] rain;

void setup(){
  size(500,500);
  rectMode(CENTER);
  rain = new rainDrop[200];
  for(int i = 0; i < rain.length; i++){
    rain[i] = new rainDrop(); 
  }
}

void draw(){
  background(255);
  for(int i = 0; i < rain.length; i++){
    rain[i].render();
    rain[i].fall();
  }
}
