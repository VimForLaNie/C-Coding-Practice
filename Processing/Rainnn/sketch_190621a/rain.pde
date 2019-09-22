class rainDrop{
  float rainWidth = random(3,5);
  float rainLength = random(30,40);
  float xpos = random(width);
  float ypos = random(-100,-1000); 
  float fallspeed = random(4,10);
  
  void render(){
    stroke(255,0,0);
    fill(255,0,0);
    rect(xpos,ypos,rainWidth,rainLength);

  }
  void fall(){
    ypos = ypos + fallspeed;
    if(ypos > height + (rainLength / 2)){
      ypos = random(-100,-150);
    }
  }
}
