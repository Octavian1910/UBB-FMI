#ifndef LAB4_TEMPLATE_TESTS_H
#define LAB4_TEMPLATE_TESTS_H

class TestMedService {
public:
    /*
     * Rulează toate testele aplicației pentru a verifica funcționalitatea și acoperirea codului.
     */
    void runAll();

private:
    /**
     * Testează metodele clasei de domeniu Medicine (gettere, settere, ID).
     */
    void testDomain();

    /**
     * Testează funcționalitățile MyVector: constructor de copiere, operator assignment,
     * removeLast și comportamentul la resize.
     */
    void testMyVectorExtra();

    /**
     * Testează stocarea și recuperarea tuturor elementelor din service.
     */
    void testStoreAndGetAll();

    /**
     * Testează funcția de actualizare a unui medicament existent.
     */
    void testUpdate();

    /**
     * Testează ștergerea unui medicament din sistem.
     */
    void testRemove();

    /**
     * Testează căutarea unui medicament după ID.
     */
    void testFind();

    /**
     * Testează filtrarea medicamentelor după preț.
     */
    void testFilterPrice();

    /**
     * Testează filtrarea medicamentelor după substanța activă.
     */
    void testFilterSubstance();

    /**
     * Testează sortarea alfabetică după nume (crescător/descrescător).
     */
    void testSortByName();

    /**
     * Testează sortarea după producător.
     */
    void testSortByProducer();

    /**
     * Testează sortarea după substanța activă.
     */
    void testSortBySubstance();

    /**
     * Testează cazul în care criteriul de sortare este identic,
     * verificând dacă se aplică sortarea secundară după preț.
     */
    void testSortEqualKey();

    /**
     * Testează aruncarea excepțiilor în Repository (duplicate, elemente inexistente).
     */
    void testRepoExceptions();

    /**
     * Testează validarea datelor și aruncarea excepțiilor de validare.
     */
    void testValidatorExceptions();
};

#endif //LAB4_TEMPLATE_TESTS_H