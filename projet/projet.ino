bool ledState = false;
void flushSerialInput();
void setup()
{
  // definition du mode de l'I/O
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(2, ledState);

  // def. de la vitesse du port serie
  Serial.begin(9600);

  // Ecriture sans retour chariot
  Serial.print("Projet 3");

  // Ecriture avec retour chariot
  Serial.println(" ecriture serie");
}

void loop()
{
  digitalWrite(2, ledState);
}
void flushSerialInput(){
  while(Serial.available()){Serial.read();}
}
void SerialEvent(){
    
    // attente du remplissage du buffer avant lecture
    delay(100);
    char str[5] = "";
    int i=0;
    //strlen(str)< (taille Max - caractere d'arret de chaine)
    while (Serial.available() && strlen(str) < 4)
    {
      char aChar ='\0';
      aChar=Serial.read();
      //si le caractere recu est imprimable
      if(isPrintable(aChar)){
        str[i++]=aChar;
      }
    }
    //vidange du buffer de lecture
    flushSerialInput();
    str[i]='\0';
    //si la chaine est "on" ou "1"
    if(strcmp(str,'on') || strcmp(str,"1")){
      ledState=true;
    }
    //sinon si la chaine est "off" ou "0"
    else if (strcmp(str,"off")|| strcmp(str,"0"))
    {
        ledState=false;
    }
}