# Kalkulator - równania matematyczne i zamiana na ONP
Program oblicza równania matematyczne (włączając w to nawiasy) wyświetlając przy tym postać równania w ONP oraz kolejno wykonywane działania (zapisywane dodatkowo w pliku .txt) a zapętlenie pozwala na obliczanie po sobie dowolnej ilości równań.
## Jak uruchomić
Program można odpalić w środowisku programistycznym obsługującym język C - przykładowo Code::Blocks.
* Pobrać i zainstalować Code::Blocksa (np. https://sourceforge.net/projects/codeblocks/files/Binaries/12.11/Windows/codeblocks-12.11mingw-setup.exe)
* Pobrać plik [main.c](https://github.com/LionGambino/Calculator/blob/main/main.c) i otworzyć go w Code::Blocksie
* Uruchomić klikając Build and Run
![image](https://user-images.githubusercontent.com/107425382/173459331-afdcc88a-4d01-4e63-8745-3224386a43c9.png)

## Screeny
### Przykład rozwiązania równania:

![image](https://user-images.githubusercontent.com/107425382/173455990-f192521e-d50d-4c60-aaa5-703a09b956c5.png)
## Ciekawe elementy techniczne
### Funkcje do obsługi stosu:
![image](https://user-images.githubusercontent.com/107425382/173455189-17558224-6954-4441-ad5b-7989eff0fe33.png)

### Struktura wiązana do przetrzymywania równania w ONP
![image](https://user-images.githubusercontent.com/107425382/173459568-40e89e86-9f8e-446e-b456-cbd7a1f1130a.png)
![image](https://user-images.githubusercontent.com/107425382/173459624-7163acd0-9667-4e4e-bed1-9597c7f2132c.png)
![image](https://user-images.githubusercontent.com/107425382/173459643-afc7f961-f8f1-497d-aa44-7e2a1026d5b8.png)
![image](https://user-images.githubusercontent.com/107425382/173459723-b2f2988c-1bc7-4546-ac66-d95aedeee712.png)

Struktura składa się z wartości "typ", w której przetrzymywany jest znak, a w przypadku liczby litera "l". Dla liczb mamy wartość "val", w której mamy w zmiennej typu float naszą liczbę. Na końcu znajduje sie wskaźnik "next" do kolejnej struktury.

## Repozytorium GitHub

https://github.com/LionGambino/Calculator
