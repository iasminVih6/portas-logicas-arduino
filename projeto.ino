// Variáveis Globais

// AND
int pin_saidaAnd = 13;
int pin_A_And = 0;
int pin_B_And = 1;

// OR
int pin_saidaOr = 10;
int pin_A_Or = 2;
int pin_B_Or = 3;

// NOT
int pin_saidaNot = 8;
int pin_A_Not = 4;

// XOR
int pin_saidaXor = 12;
int pin_A_Xor = 5;
int pin_B_Xor = 6;

void setup()
{
  // AND
  pinMode(pin_saidaAnd, OUTPUT);
  pinMode(pin_A_And, INPUT);
  pinMode(pin_B_And, INPUT);

  // OR
  pinMode(pin_saidaOr, OUTPUT);
  pinMode(pin_A_Or, INPUT);
  pinMode(pin_B_Or, INPUT);

  // NOT
  pinMode(pin_saidaNot, OUTPUT);
  pinMode(pin_A_Not, INPUT);

  // XOR
  pinMode(pin_saidaXor, OUTPUT);
  pinMode(pin_A_Xor, INPUT);
  pinMode(pin_B_Xor, INPUT);
}
void loop()
{
  // AND
  bool S_and = portaAnd(digitalRead(pin_A_And), digitalRead(pin_B_And));
  digitalWrite(pin_saidaAnd, S_and);

  // OR
  bool S_or = portaOr(digitalRead(pin_A_Or), digitalRead(pin_B_Or));
  digitalWrite(pin_saidaOr, S_or);

  // NOT
  bool S_not = portaNot(digitalRead(pin_A_Not));
  digitalWrite(pin_saidaNot, S_not);

  // XOR
  bool S_xor = portaXor(digitalRead(pin_A_Xor), digitalRead(pin_B_Xor));
  digitalWrite(pin_saidaXor, S_xor);
}
// Funções das portas lógicas
// AND
bool portaAnd(bool A, bool B)
{
  return (A && B);
}
// OR
bool portaOr(bool A, bool B)
{
  return (A || B);
}
// NOT
bool portaNot(bool A)
{
  return !A;
}
// XOR
bool portaXor(bool A, bool B)
{
  bool S1 = portaNot(A);
  bool S2 = portaNot(B);
  bool S3 = portaAnd(S1, B);
  bool S4 = portaAnd(S2, A);
  return portaOr(S3, S4);
}
