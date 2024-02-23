#Assambly Emulator built with C++ for C.S. Course
Instructions of ussage below in spanish

###Project Developed by:
@CarlosMtz1281
@NicoTC-04


Usar codigo con la sintaxis encontrada en los siguientes casos de pruebas

Casos de Prueba

-----------------------------------

caso 1. MULTIPLICACION

Multiplica numeros en memorias 010 y 011 y almacena la respuesta en 020

ORG 000

000 LDA Inm 10
001 STA A 010
002 LDA Inm 3
003 STA A 011
004 LDA A 010
005 STA A 020
006 LDA A 011
007 SUB Inm 1
008 STA A 011
009 JMZ A 014
010 LDA A 020
011 ADD A 010
012 STA A 020
013 JMP A 006
014 HLT
-----------------------------------

caso 2. DIVISION

Divide numeros en memorias 010 entre el 011 y almacena el cociente en 005 y residuo en 006


ORG 000

000 LDA Inm 22
001 STA A 010
002 LDA Inm 5
003 STA A 011
004 CLA
005 STA A 005
006 LDA A 010
007 STA A 006
008 SUB A 011
009 JMN A 017
010 LDA A 005
011 ADD Inm 1
012 STA A 005
013 LDA A 006
014 SUB A 011
015 STA A 006
016 JMP A 008
017 HLT

------------------------------------------

caso 3. SUMATORIA DE numeros

Suma la cantidad de numeros N (Memoria 001) Y se almacena resultado en memoria 002 donde la memoria 003 almacena la direccion de los numeros que se sumaran (010,011,012,013)


ORG 000

000 LDA Inm 4
001 STA A 001

002 LDA Inm 5
003 STA A 010

004 LDA Inm 10
005 STA A 011

006 LDA Inm 20
007 STA A 012

008 LDA Inm 25
009 STA A 013

010 CLA
011 STA A 002
012 LDA Inm 010
013 STA A 003

014 LDA A 001
015 JMZ A 026
016 LDA A 002
017 ADD Ind 003
018 STA A 002
019 LDA A 003
020 ADD Inm 1
021 STA A 003
022 LDA A 001
023 SUB Inm 1
024 STA A 001
025 JMP A 014
026 HLT


