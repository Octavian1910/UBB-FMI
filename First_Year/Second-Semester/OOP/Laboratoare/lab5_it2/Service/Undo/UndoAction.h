//
// Created by octav on 02.05.2026.
//

#ifndef LAB4_UNDOACTION_H
#define LAB4_UNDOACTION_H
#include "../../domain/Medicine.h"
#include "../../Repository/MedRepository.h"

class UndoAction
{
protected:
    /*
     * repo: medicine repository
     */
    MedRepository& repo;
public:
    /*
     * Creates undo action
     * :param repo: medicine repository
     */
    UndoAction(MedRepository& repo):repo{repo}{}

    /*
     * Executes undo operation
     */
    virtual void doUndo() = 0; //facem clasa abstrascta , fiecare operatie de undo e implementata diferit

    /*
     * Virtual destructor
     */
    virtual ~UndoAction() = default; // evitam memory leak
};


class UndoAdd : public UndoAction
{
private:
    /*
     * addedMedicine: added medicine
     */
    Medicine addedMedicine;

public:
    /*
     * Creates undo add action
     * :param repo: medicine repository
     * :param med: added medicine
     */
    UndoAdd(MedRepository& repo,const Medicine& med):UndoAction{repo},addedMedicine{med}{}

    /*
     * Undoes add operation
     */
    void doUndo() override
    {
        repo.remove(addedMedicine.get_ID());
    };
};

class UndoDelete : public UndoAction
{
private:
    /*
     * deletedMedicine: deleted medicine
     */
    Medicine deletedMedicine;
public:
    /*
     * Creates undo delete action
     * :param repo: medicine repository
     * :param med: deleted medicine
     */
    UndoDelete(MedRepository& repo,const Medicine& med):UndoAction{repo},deletedMedicine{med}{}

    /*
     * Undoes delete operation
     */
    void doUndo() override
    {
        repo.store(deletedMedicine);
    };
};

class UndoModify : public UndoAction
{
private:
    /*
     * oldMedicine: old medicine before modification
     */
    Medicine oldMedicine;
public:
    /*
     * Creates undo modify action
     * :param repo: medicine repository
     * :param med: old medicine
     */
    UndoModify(MedRepository& repo,const Medicine& med):UndoAction{repo},oldMedicine{med}{}

    /*
     * Undoes modify operation
     */
    void doUndo() override
    {
        repo.update(oldMedicine);
    };
};


#endif //LAB4_UNDOACTION_H