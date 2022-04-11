# MC504-Proj01
Proj01 - Aplicação Multithread

Esse projeto consiste na implementação de um solucionador de um caça-palavras 3D. 
Foi utilizado multithreading para que a busca por palavras fosse feita de forma mais eficiente. O modo como isso foi implementado se resume no uso de diferentes threads, cada uma verificando por palavras em uma certa direção. Por exemplo, existe uma thread que busca por palavras no eixo x, e outras nos eixos y e z. Além disso, existe a possibilidade de palavras estarem nos planos xy, xz e yz, logo existem threads que verificam por palavras nesses planos. 
 