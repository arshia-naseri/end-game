// End Game

//Variaables
int x = 0;
int y = 0;

int prize;
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


void move(String direction){

}

void loop()
{
  key = readSerial("> What Key Pressed? ");
  Serial.println(key);
  // here
  if(key == "d")
  {
       //go right and print new coordinates 
    move("r");
  }
} 
