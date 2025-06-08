// End Game

//Variaables
int x = 0;
int y = 0;

int prize_x = 3;
int prize_y = -2;


String key;
String name;

String readSerial(String pretext = ""){
  //To Read from User
  Serial.println(pretext);
  while (Serial.available() == 0) {}
  return Serial.readString();
}

void clearMonitor(){
  //clears monitor
 for(int i = 0; i<50; i++)
   Serial.println("");
}

void setup()
{
  Serial.begin(9600);
  clearMonitor();
  String instructions = "WELCOME TO VIRTUAL MAZE\nStart positions is (0,0) meaning x=0,y=0\nEnter 'd' to move RIGHT\nEnter 's' to move DOWN\nEnter 'a' to move LEFT\nEnter 'w' to move UP";

  Serial.println(instructions);
  name = readSerial("Enter your name:");
  Serial.println("Welcome to the Maze "+ name);
  Serial.println("***\n");
}

// YOU

void printLocation(){
  Serial.println("x= "+ String(x) + ", y= "+ String(y));
}

void move(String direction){
  if(direction == "right"){
    x = x + 1;
  }
  else if(direction == "left"){
    x = x - 1;
  }
  else if(direction == "up"){
    y = y + 1;
  }
  else if(direction == "down"){
    y = y - 1;
  }
  
  printLocation();
}

void loop()
{
  key = readSerial("> What Key Pressed? ");
  // Moves
  if(key == "d" or key == "D"){
    move("right");
  }
  else if(key == "s" or key == "S"){
    move("down");
  }
  else if(key == "a" or key == "A"){
    move("left");
  }
  else if(key == "w" or key == "W"){
    move("up");
  }
  else if(key == "l" or key == "L"){
    Serial.print("Current Location: ");
    printLocation();
  }
  else{
    Serial.println("> Move Not Allowed");
  }
  
  if (x == prize_x && y == prize_y)
  {
   	Serial.println(">>> You Got a prize"); 
  }
} 
