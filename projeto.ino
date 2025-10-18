//Variáveis Globais
//função and/xor
int pin_saidaAnd = 13;
int pin_A_And=0;
int pin_B_And=1;
//or
int pin_saidaOr = 10;
int pin_A_Or = 2;
int pin_B_Or = 3;
//not
int pin_saidaNot = 8;
int pin_A_Not = 4;



void setup()
{
  pinMode(pin_saidaAnd, OUTPUT);
  pinMode(pin_A_And,INPUT);
  pinMode(pin_B_And,INPUT);
  //Or
  pinMode(pin_saidaOr, OUTPUT);
  pinMode(pin_A_Or,INPUT);
  pinMode(pin_B_Or,INPUT);
  //not
  pinMode(pin_saidaNot, OUTPUT);
  pinMode(pin_A_Not,INPUT);
 
  
}

void loop()
{
  bool S = portaXor(digitalRead(pin_A_And),digitalRead(pin_B_And));
  digitalWrite(pin_saidaAnd,S);

  
  bool S2 = portaOr(digitalRead(pin_A_Or),digitalRead(pin_B_Or));
  digitalWrite(pin_saidaOr,S2);
  
  bool S3 = portaNot(digitalRead(pin_A_Not));
  digitalWrite(pin_saidaNot,S3);
  
  
  
}
//E
bool portaAnd(bool A, bool B)
{
 	if(A==true && B==true)
      	return true;
  	else
      	return false;
}
//Ou
bool portaOr(bool A, bool B)
{
  if(A == true || B == true)
    return true;
  else
    return false;
}
//not

bool portaNot(bool A)
{
  if(A == true)
    return false;
  else 
    return true;
}

//shor

bool portaXor(bool A, bool B){
  bool S1 = portaNot(A);
  bool S2 = portaNot(B);
  bool S3 = portaAnd(S1, B);
  bool S4 = portaAnd(S2, A);
  return portaOr(S3, S4);
}