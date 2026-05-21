#pragma once
#include "../../domain/Medicine.h"
#include "../../Repository/MedRepository.h"

class UndoAction
{
protected:
    /*
     * repo: repository reference
     */
    MedRepository& repo;

public:
    /*
     * Creates undo action
     * :param repo: repository reference
     */
    UndoAction(MedRepository& repo)
        : repo{repo} {}

    /*
     * Executes undo operation
     */
    virtual void doUndo() = 0;

    /*
     * Virtual destructor
     */
    virtual ~UndoAction() = default;
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
     * :param repo: repository reference
     * :param med: added medicine
     */
    UndoAdd(MedRepository& repo, const Medicine& med)
        : UndoAction{repo}, addedMedicine{med} {}

    /*
     * Undoes add operation
     */
    void doUndo() override
    {
        repo.remove(addedMedicine.get_ID());
    }
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
     * :param repo: repository reference
     * :param med: deleted medicine
     */
    UndoDelete(MedRepository& repo, const Medicine& med)
        : UndoAction{repo}, deletedMedicine{med} {}

    /*
     * Undoes delete operation
     */
    void doUndo() override
    {
        repo.store(deletedMedicine);
    }
};

class UndoModify : public UndoAction
{
private:
    /*
     * oldMedicine: medicine before modification
     */
    Medicine oldMedicine;

public:
    /*
     * Creates undo modify action
     * :param repo: repository reference
     * :param med: old medicine
     */
    UndoModify(MedRepository& repo, const Medicine& med)
        : UndoAction{repo}, oldMedicine{med} {}

    /*
     * Undoes modify operation
     */
    void doUndo() override
    {
        repo.update(oldMedicine);
    }
};