boolean click = false;

void setup() {
  size(400, 400);//library -> processing
  background(100);
  rectMode(CENTER);
  textSize(20);
}

void draw() {
  if (mouseX >= 150 && mouseX <= 250 && mouseY >= 150 && mouseY <= 250) {
    if (!click) {
      fill(150);
      rect(200, 200, 100, 100);
      fill(100);
      stroke(100);
      rect(100, 100, 100, 100);
      println("Darken the Image");
    } else {
      println("running : click = true");
      fill(50, 100, 20);
      text("Hi", 100, 100);
      println("Saying Hi");
      rect(200, 200, 100, 100);
      println("delaying");
      println("click = false");
    }
  } else {
    click = false;
    fill(200);
    rect(200, 200, 100, 100);
    fill(100);
    stroke(100);
    rect(100, 100, 100, 100);
    println("Resetting");
  }
  fill(0);
  text("Click",175,210);
}

void mouseClicked() {
  println("mouse clicked");
  click = !click;
}
