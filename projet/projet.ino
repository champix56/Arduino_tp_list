void setup()
{
    // definition du mode de l'I/O
    pinMode(2, OUTPUT);
}

void loop()
{
    digitalWrite(2, HIGH);
    delay(750);
    digitalWrite(2, LOW);
    delay(750);
}