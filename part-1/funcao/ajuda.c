int soma(int num1, int num2) {
  int result = num1 + num2;
  return result;
}

float divide(float num1, float num2) {
  float result;
  if (!num2) {
    return 0;
  }
  result = num1 / num2;
  return result;
}
