Se va asigura constructorul cu cu un singur argument – dimensiunea matricei, adică numărul de linii și de coloane al matricei, constructorul implicit – dimensiunea este 10 și un constructor de copiere. Fiecare constructor va permite și alocarea de memorie pentru matrice. Se va defini și un destructor care va permite eliberarea memoriei alocată de constructorul aplicat.

Se va redefini operatorul >> ca funcție prieten (friend) pentru citirea unei matrice de la intrarea standard și se va redefini operatorul << ca funcție prieten (friend) pentru afișarea unei matrice la ieșirea standard.

Se vor prevedea funcții membri pentru:

<li>accesul la elementele vectorului;</li>

<li>supraîncărcarea operatorului ob1/= ob2 - done împărțirea unei matrice la o altă matrice dată ca argument;</li>

<li>supraîncărcarea operatorului ob1-- postfix și --ob1 prefix;</li>

<li>supraîncărcarea operatorului ob1<= ob2 care permite compararea a două matrice;</li>

<li>supraîncărcarea operatorilor x-ob1, ob1-x pentru a permite scăderea între x (număr întreg) și ob1(obiect a clasei respective);</li>

<li>supraîncărcarea operatorului de atribuire ob1= ob2.</li>


Funcția main() va conține exemple de aplicare corectă a operatorilor descriși relativ la clasa dată.

Se vor descrie aceiași operatori (care au fost descriși ca funcții membre) și ca funcții prietene într-un al program similar.
