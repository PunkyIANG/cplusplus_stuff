Se consideră ierarhia de clase din schemă. Clasa de bază conține 4 membri protected 2 dintre care (câmp1_moștenit, câmp2_moștenit) sunt moșteniți de clasele derivate xxx și yyy (xxx și yyy sunt denumiri de clase simbolice, ceea ce înseamnă că studentul va înlocui aceste valori după cum crede de cuviință). Fiecare clasă xxx și yyy vor conține și câte 2 membri private proprii (pe lângă cei 2 membri moșteniți de la clasa de bază). Clasa zzz conține câmpurile câmp1_moștenit, câmp2_moștenit moștenite de la clasa de bază, un câmp câmp_moștenit_x moștenit de la clasa xxx, un câmp câmp_moștenit_y moștenit de la clasa yyy și un câmp private propriu câmp_z. Opțional, fiecare clasă poate conține și alți membri public dacă studentul decide că este necesar. La ierarhia descrisă se adaogă și o clasă abstractă de la care derivă clasa de bază descrisă în schemă. Membrii public ai fiecărei clase din ierarhie sunt: un constructor fără parametri, un constructor cu parametri, funcție(ții) care permite citirea de la tastatură a valorilor membrilor private și protected și funcție(ții) care permite afișarea la ecran a valorilor membrilor private și protected.

În funcția main() este declarat un tablou dinamic de obiecte care va conține obiecte a tuturor claselor din ierarhie. Tot în funcția main() este descris un meniu (fiecare punct din meniu conține o funcție care execută fiecare din cerințele formulate mai jos):

<ol>
    <li>citirea de la tastatură a valorilor membrilor obiectelor diferitor clase din ierarhie în tabloul definit;</li>
    <li>afișarea obiectelor tabloului la ecran;</li>
    <li>sortarea obiectelor în ordine definită de student după un câmp comun tuturor claselor din ierarhie;</li>
    <li>afișarea la ecran a obiectelor pentru care se cunoaște că un câmp comun tuturor claselor din ierarhie satisface o condiție formulată de student;</li>
    <li>se modifică datele obiectului pe poziția k în tabloul de obiecte (k se citește de la tastatură);</li>
    <li>se șterge obiectul pentru care se cunoaște că  un câmp comun tuturor claselor din ierarhie satisface o condiție formulată de student.</li>
</ol>