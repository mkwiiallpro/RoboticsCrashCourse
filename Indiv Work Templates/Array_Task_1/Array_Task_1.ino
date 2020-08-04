// Array Task 1

void setup() {
  Serial.begin(9600);

  // Creat an array of type int and size 10:
  int ten[10];
  // Using a while loop, fill the array with multiples of 3 between 3 and 30 (inclusive):
                // Remember the syntax?
                // while (condition) {
                //       code...
                // }
  int x=0;
  while(x<10){
    ten[x]= 3*x+3;
    x++;
  }


  // Rewrite the code above with a for loop:
                // Remember the syntax?
                // for (initialization; condition; update variable) {
                //       code...
                // }


  // Write a loop that will go through the array 
  //     and print any values that are a multiple of 9:
                // Hint: Use the % (modulus) operator.
  for(int i =0;i<10;i++){
    if(ten[i]%9 == 0){
      Serial.println(ten[i]);
    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
