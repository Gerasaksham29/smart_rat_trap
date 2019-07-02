#include <ESP8266WiFi.h>
#include<Servo.h>
Servo servo;
const char* ssid = "Adxy_336";
const char* password = "123467890";
 
int ledPin = 13; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, INPUT);
 servo.attach(12);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 servo.write(180);
}
 
void loop() {
  // Check if a client has connected
  //Serial.print(digitalRead(13));
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(10);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if (request.indexOf("/LED=ON") != -1)  {
    servo.write(90);
    delay(2000);
    servo.write(180);
  }

 
  // Match the request
 client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.print("<html> <head>    <style>    body{  margin:0; padding:0;  background-image:url('https://ik.imagekit.io/2xkh6z6bb/ab1_TVFNJPeRB.jpg'); background-size:100%; background-position:center; background-repeat:no-repeat;  font-family:sans-serif;}.icon{  width:40px; height:40px;}.loginbox input{margin-top:3%;float:left;position:fixed;height:auto;font-size:20px;padding:5px;border-radius:8px;background-color:rgba(255,69,0,0.6)}.flashCol{  border:1.5px solid yellow;  border-radius:12px; padding-top:5%; padding-bottom:5%;    text-align:center;  background-color:red;}.loginbox{  width:400px;  height:300px; background:rgba(50,50,50,.01);  color:#fff; top:40%;  left:50%; position:absolute;  transform:translate(-50%,-50%); box-sizing:border-box;  padding:70px 40px;  box-shadow:0 15 px 25px rgba(0,0,0,0.5);  border-radius:30px }   .abc{   width:100px;  height:100px;   border-radius:50%;  position:absolute;  top:-40px;  left:calc(50% - 50px); } .loginbox .inputBox {  position:relative; } .loginbox .inputBox input{   width:100%;   padding:2px 0;  font-size:16px;   color:#fff;   margin-bottom:3px;  border:none;  border-bottom:1px solid #fff;   outline:none;   background:transparent; } .loginbox .inputBox label{  position:absolute;  top:0;  left:0;   padding:10px 0;   font-size:16px;   color:#fff;   pointer-events:none;  transition:.5s;   } .loginbox .inputBox input:focus ~ label, .loginbox .inputBox input:valid ~ label {  top:-7px;   left:0;   color:#03a9f4;  font-size:12px;   } h1{   margin:0;   padding:10px 0 20px;  text-align:center;  font-size:26px;   color:#8B008B } h1:hover{   color:rgb(255,255,0); }   .SELECT {    width:30%;    margin-top: 20px;   margin-bottom:25px; } .loginbox p{    margin:0;   padding:0;    font-weight:bold; }   .loginbox input[type='text'],input[type='password'] {   border:none;    border-bottom:1px solid #fff;   background:transparent;   outline:none;   height:40px;    color:#fff;   font-size:16px; }   .loginbox input[type='submit'] {    border:none;    outline:none;   height:35px;    position:center;    left:45%;   background:#fb2525;   color:#fff;   font-size:18px;   border-radius:20px; }  .loginbox input[type='submit']:hover {   cursor:pointer;   background:#ffc107;   color:#000;    }  .loginbox a{    text-decoration:none;   font-size:12px;   line-height:20px;   color:darkgrey; }  .loginbox a:hover{  color:#ffc107; }    </style>  <script>    function choose(){  alert('Food Released');  }      function blinktext() {  setInterval(function() {  document.getElementById('ale').style.backgroundColor=(document.getElementById('ale').style.backgroundColor == 'red' ? '#00CED1' : 'red');  },300);  </script>  </head>   <title>SMART RAT TRAP</title>  <body onload='blinktext()'>     <div class='loginbox'>    <img src='https://ik.imagekit.io/2xkh6z6bb/ab2_eO4S3DWFm.png' class='abc'>      <h1>WELCOME TO THE SMARTEST RAT TRAP</h1>     <form>      ");
  if(digitalRead(13)){
  client.print(" <div  >       <div id='ale' style='border:1.5px solid yellow;border-radius:12px;padding-top:5%;padding-bottom:5%;text-align:center;background-color:red;'>                <p>Congratulations.....!!! </p>       <p>Rat has been trapped !!!</p>               </div>                <!--<input type='submit' name='submit' value='DONE'><br>-->               <pre> <a href='/LED=ON' ><input type='button' id='ch1' value='Release Food' onclick='choose()'></a>                            </pre>      <div>     </form>   </div>      </body></html>");
  }
 else{
  client.print("<div style='display:none' >       <div id='ale' style='border:1.5px solid yellow;border-radius:12px;padding-top:5%;padding-bottom:5%;text-align:center;background-color:red;'>                <p>Congratulations.....!!! </p>       <p>Rat has been trapped !!!</p>               </div>                <!--<input type='submit' name='submit' value='DONE'><br>-->               <pre> <a href='/LED=ON' ><input type='button' id='ch1' value='Release Food' onclick='choose()'></a>                              </pre>      <div>     </form>   </div>      </body></html>");
 }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  
  
 
  delay(10);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
