// End Game

//Class

class Coordinate
{
  public:
  
  int x;
  int y;
  
  Coordinate(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  
  void printLocation(String pretext = "")
  {
    Serial.print(pretext);
  	Serial.println("x= "+ String(this->x) + ", y= "+ String(this->y));
  }
};

//Variaables

//My loc = My Location 
Coordinate myLoc(0,0);

//.                x                y
Coordinate prize1(random(-3, 3), random(-3, 3));

//.                x                y
Coordinate prize2(random(-3, 3), random(-3, 3));


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
  
  // For cheat to get Location 
  prize1.printLocation("Prize 1 Location: ");
  prize2.printLocation("Prize 2 Location: ");
}

// YOU

void move(String direction){
  if(direction == "right"){
    myLoc.x = myLoc.x + 1;
  }
  else if(direction == "left"){
    myLoc.x = myLoc.x - 1;
  }
  else if(direction == "up"){
    myLoc.y = myLoc.y + 1;
  }
  else if(direction == "down"){
    myLoc.y = myLoc.y - 1;
  }
  
  myLoc.printLocation();
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
    myLoc.printLocation("My current location: ");
  }
  else{
    Serial.println("> Move Not Allowed");
  }
  
  if (myLoc.x == prize1.x && myLoc.y == prize1.y)
  {
   	Serial.println(">>> You Got prize1"); 
  }
  if(myLoc.x == prize2.x && myLoc.y == prize2.y)
  {
   	Serial.println(">>> You Got prize2"); 
  }
} 
