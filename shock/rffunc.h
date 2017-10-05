const int outPin = D6;

void int_to_bin_digit(unsigned int in, int count, int* out)
{
  unsigned int mask = 1U << (count - 1);
  int i;
  for (i = 0; i < count; i++) {
    out[i] = (in & mask) ? 1 : 0;
    in <<= 1;
  }
}

void command(int arr[], int _size) {
  bool b = true;
  for (int i = 0; i < _size; i++) {
    digitalWrite(outPin, b); delayMicroseconds(arr[i]);
    b = !b;
  }
}

void startSequenzPt1() {
  int arr[] = {1472, 730, 725, 231, 233, 720, 233, 720, 233, 719, 233, 720};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void startSequenzPt2() {
  int arr[] = {725, 231, 723, 230, 249, 720, 722, 231, 233, 720, 233, 720, 723, 231, 233, 719, 237, 719, 723, 231, 722, 231, 722, 231, 233, 731, 233, 719, 723, 230, 723, 231, 236, 720};
  command(arr, (sizeof(arr) / sizeof(int)));
}
void endSequenz() {
  int arr[] = {723, 230, 723, 231, 722, 231, 722, 231, 233, 720, 232};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void _shock1() {
  int arr[] = {233, 719, 234, 719, 723, 231};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void _shock2() {
  int arr[] = {237, 719, 723, 231, 722, 231};
  command(arr, (sizeof(arr) / sizeof(int)));
}
void _vibrate1() {
  int arr[] = {233, 719, 722, 231, 233, 719};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void _vibrate2() {
  int arr[] = {725, 231, 233, 719, 722, 231};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void _sound1() {
  int arr[] = {723, 230, 233, 720, 233, 719};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void _sound2() {
  int arr[] = {725, 231, 722, 231, 233, 719};
  command(arr, (sizeof(arr) / sizeof(int)));
}

void executeTaskWithStrength(int i) {
  int digit[7];
  int_to_bin_digit(i, 7, digit);
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(outPin, 1); delayMicroseconds((digit[i] == 0) ? 230 : 730);
    digitalWrite(outPin, 0); delayMicroseconds((digit[i] == 0) ? 730 : 230);
  }
}

void intermezo(int i) {
  startSequenzPt2();
  executeTaskWithStrength(i);
}

void execute(int i, int type) {
  startSequenzPt1();
  switch (type) {
    case (0):
      _shock1();
      intermezo(i);
      _shock2();
      break;
    case (1):
      _vibrate1();
      intermezo(i);
      _vibrate2();
      break;
    case (2):
      _sound1();
      intermezo(0);
      _sound2();
      break;
    default:
      _shock1();
      intermezo(i);
      _shock2();
  }
  endSequenz();
  digitalWrite(outPin, 0);
  delayMicroseconds(7877);
}
/*
  void test() {
  digitalWrite(outPin, 1); delayMicroseconds(1470);
  digitalWrite(outPin, 0); delayMicroseconds(730);
  digitalWrite(outPin, 1); delayMicroseconds(725);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(718);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(725);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(244);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(718);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(236);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(721);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(730);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(237);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(718);
  digitalWrite(outPin, 1); delayMicroseconds(723);
  digitalWrite(outPin, 0); delayMicroseconds(242);
  digitalWrite(outPin, 1); delayMicroseconds(232);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(726);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(231);
  digitalWrite(outPin, 1); delayMicroseconds(722);
  digitalWrite(outPin, 0); delayMicroseconds(230);
  digitalWrite(outPin, 1); delayMicroseconds(233);
  digitalWrite(outPin, 0); delayMicroseconds(719);
  digitalWrite(outPin, 1); delayMicroseconds(232);

  digitalWrite(outPin, 0);
  }
*/
