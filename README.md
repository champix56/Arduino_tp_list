# Arduino_tp_list

# Projet 0

Découverte du code arduino minimum

## 0.1. Composants

- Aucun

## 0.2. code

~~~c
    void setup(){
        //code exécuter au départ de l'exécution du code
    }
    void loop(){
        //boucle d'exécution infinie 
    }
~~~

### 0.2.1. ***void setup ()***

>**fonction obligatoire** pour l'appel de tous les   >constructeurs d'instances diverses.
>
>cette fonction est exécutée une seul fois au démarrage de la puce

### 0.2.2 ***void loop()***

>**fonction obligatoire** exécuter en boucle lorsque la puce est allumée. Cette fonction commence à être exécutée qu’une fois le setup achevé

----------

# projet 1 : clignotement d'une LED

Découverte des sorties *Tout Ou Rien*.

## 5. Enoncé

Clignotement continue d'une diode électroluminescente
## 1.1. composants

- arduino uno
- 1x LED
- une résistance *(*facultatif)*

## 1.2. Code

~~~c

    void setup() {
        //définition du mode de l'I/O
        pinMode(2, OUTPUT);
    }

    void loop() {
        //écriture sur le port
        digitalWrite(2, HIGH);
        delay(750);
        digitalWrite(2, LOW);
        delay(750);
    }
~~~

### 1.2.1 ***pinMode(*IOPin*, *digitalValue*)***

Def. du type d'usage d'un port numérique. Cette fonction permet de fixer des résistances à VCC ou GND

- #### *IOPin*

  - Valeur ou nom de l'entrée
    >
    >- 1, 2, ..., 13 : pour les ports digitaux
    >- A0, A1, ..., A5 : pour les ports digitaux. attention certaines cartes possèdent 2 ports CAN en plus (A6 / A7)

- #### *digitalValue*

  - Def. des PULLUP / PULLDOWN res sur les entrées / sorties :
    >
    >- OUTPUT : PULLUP résistance interne sur VCC
    >- INPUT  : PULLDOWN résistance interne sur GND

### 1.2.2. **digitalWrite(*IOPin*, *digitalValue*)**

Ecriture état numérique HAUT ou BAS *simple et constant ou remplissage cyclique PWM* sur une sortie digitale (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)
  
- *digitalValue*
  - Valeur à écrire sur le port : {#digital-value}
    >
    >- HIGH / LOW : état fixe et constant
    >- 0, 25, ..., 254, 255 : état de remplissage de cycle PWM, remplissage continu (sur les ports compatibles uniquement indiqués par '~' )

## 1.3. Montage

projet1.fzz

![projet 1](./img/projet1.png)

----------

# Projet 2

Lecture numérique TOR sans gestion d'interruption, et écriture en fonction de l'état de l'entrée

## 2.1. composants

- arduino uno
- 1x push button
- 1x led
- 2x résistances

## 2.2. code

~~~c
    void setup() {
        //définition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
    }

    void loop() {
        //lecture de l'état de l'entrée
        bool isD3Pushed=digitalRead(3);
        if(isD3Pushed){
            digitalWrite(2, HIGH);
        }
        else {
            digitalWrite(2, LOW);
        }
    }
~~~

### 2.2.1. **digitalRead(*IOPin*)**

Lecture d'état numérique HAUT ou BAS simple sur une entrée numérique (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)

## 2.3. montage

projet.fzz
![projet 2](img/projet2.png)

----------
