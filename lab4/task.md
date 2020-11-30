Se va asigura constructorul cu cu un singur argument – dimensiunea matricei, adică numărul de linii și de coloane al matricei, constructorul implicit – dimensiunea este 10 și un constructor de copiere. Fiecare constructor va permite și alocarea de memorie pentru matrice. Se va defini și un destructor care va permite eliberarea memoriei alocată de constructorul aplicat.

Se va redefini operatorul >> ca funcție prieten (friend) pentru citirea unei matrice de la intrarea standard și se va redefini operatorul << ca funcție prieten (friend) pentru afișarea unei matrice la ieșirea standard. - DONE

Se vor prevedea funcții membri pentru:

<li>accesul la elementele vectorului; - DONE</li>

<li>supraîncărcarea operatorului ob1/= ob2 împărțirea unei matrice la o altă matrice dată ca argument; - DONE</li>

<li>supraîncărcarea operatorului ob1-- postfix și --ob1 prefix; - DONE</li>

<li>supraîncărcarea operatorului ob1<= ob2 care permite compararea a două matrice; - DONE</li>

<li>supraîncărcarea operatorilor x-ob1, ob1-x pentru a permite scăderea între x (număr întreg) și ob1(obiect a clasei respective); - DONE</li>

<li>supraîncărcarea operatorului de atribuire ob1= ob2. - DONE</li>


Funcția main() va conține exemple de aplicare corectă a operatorilor descriși relativ la clasa dată.

Se vor descrie aceiași operatori (care au fost descriși ca funcții membre) și ca funcții prietene într-un al program similar.

Pentru realizarea acestui laborator ca bază se va lua laboratorul nr. 3 la care se vor adăuga următoarele:

în baza clasei descrise în laboratorul 3 se va crea o clasă-șablon asupra căreia pot fi aplicați aceeași operatori;

înafara clasei se va descrie o funcție-șablon care permite lucrul cu aceste obiecte și/sau cu parametri de alte tipuri iar în main() vor fi exemple de apelare a acestei funcții;

în cadrul programului (sau în descrierea operatorilor sau membrilor clasei, sau în funcția-șablon) va fi integrat try-catch care va permite prelucrarea cel puțin a unei erori.

rewrite pow to return int (T type compatibility)